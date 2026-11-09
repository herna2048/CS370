# Hangman — C++ / SFML

A polished single-player Hangman game created with C++ and SFML.

## Features

- Four categories:
  - Animals
  - Food
  - U.S. States
  - Countries
- Random word selection
- Keyboard letter input
- Correct and incorrect letter tracking
- Exactly six allowed mistakes
- Six-part Hangman drawing:
  1. Head
  2. Torso
  3. Left arm
  4. Right arm
  5. Left leg
  6. Right leg
- Win and loss screens
- Play Again and Category Menu buttons
- Hover-responsive UI
- Modular C++ architecture
- CMake build system

## Requirements

- C++17 compiler
- CMake 3.20+
- Git
- Internet access during the first CMake configuration so CMake can fetch SFML 3.1.0
- A TrueType/OpenType font

The project follows SFML's current CMake-oriented setup. SFML's documentation recommends its CMake project template for cross-platform projects.

## Build

From the project root:

```bash
cmake -B build
cmake --build build
```

Run the resulting `HangmanSFML` executable.

On macOS/Linux it will normally be under:

```text
build/HangmanSFML
```

On Visual Studio/Windows, the executable location depends on the generator/configuration.

## Font

CMake attempts to download Open Sans into:

```text
assets/fonts/OpenSans-Regular.ttf
```

If that download is unavailable, place a `.ttf` font there manually.

The application also checks several common system font paths as fallbacks.

## Controls

- Mouse: select category and press buttons
- Keyboard A-Z: guess a letter
- Escape: return to category selection during a game; close the application from the category screen

## File layout

The project keeps declarations in `include/` and implementations in `src/`.
Source files explicitly include project headers with paths such as
`#include "../include/Button.h"`, so the project does not depend on an IDE
automatically adding the header folder to its include search path.

## Architecture

```text
main.cpp
   |
   +-- UI
   |    +-- Button
   |    +-- Hangman
   |
   +-- Game
   |    |
   |    +-- WordDatabase
   |
   +-- Screen state
```

### Game

Owns the rules and state:

- secret word
- displayed word
- correct letters
- incorrect letters
- mistakes
- win/loss state

### WordDatabase

Owns category data and random word selection.

### Hangman

Owns the visual six-stage Hangman drawing.

### Button

Provides reusable clickable/hoverable UI controls.

### UI

Owns screen presentation and routes user input to the game.

## AI-directed development

This project was intentionally structured so the implementation can be developed through AI prompting and iterative testing, consistent with a Vibe Coding assignment.

When a compiler or runtime issue occurs, the recommended workflow is:

1. Run/build the project.
2. Capture the exact error or incorrect behavior.
3. Re-prompt the AI with that evidence.
4. Have the AI revise the relevant source.
5. Rebuild and retest.

Avoid manually fixing source-code defects if the course rubric expects the AI to direct the implementation.

## Notes

The game contains 55 animal terms, 50 food terms, all 50 U.S. states, and 50 country terms.

Some multi-word terms are stored without spaces (for example `NEWYORK`) so the player only guesses letters.
