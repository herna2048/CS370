cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for harfbuzz")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/Users/michaelhernandez/Desktop/CS370/HangmanSFML/build/_deps/harfbuzz-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/opt/homebrew/bin/cmake]====] [====[-DHARFBUZZ_DIR=/Users/michaelhernandez/Desktop/CS370/HangmanSFML/build/_deps/harfbuzz-src]====] [====[-P]====] [====[/Users/michaelhernandez/Desktop/CS370/HangmanSFML/build/_deps/sfml-src/tools/harfbuzz/PatchHarfBuzz.cmake]====]
)

endblock()
