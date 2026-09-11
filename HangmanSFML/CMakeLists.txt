cmake_minimum_required(VERSION 3.20)

project(HangmanSFML VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# SFML's official CMake template is the recommended cross-platform setup.
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SFML)

set(APP_SOURCES
    src/main.cpp
    src/Button.cpp
    src/Game.cpp
    src/Hangman.cpp
    src/UI.cpp
    src/WordDatabase.cpp
)

add_executable(HangmanSFML ${APP_SOURCES})

target_link_libraries(HangmanSFML PRIVATE
    SFML::Graphics
)

# Put the runtime asset directory beside the executable.
add_custom_command(TARGET HangmanSFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:HangmanSFML>/assets/fonts"
)

# A font is downloaded at configure time if the project does not already contain one.
# Open Sans is distributed under the SIL Open Font License.
set(FONT_PATH "${CMAKE_SOURCE_DIR}/assets/fonts/OpenSans-Regular.ttf")
if(NOT EXISTS "${FONT_PATH}")
    message(STATUS "Downloading Open Sans font...")
    file(DOWNLOAD
        "https://raw.githubusercontent.com/google/fonts/main/ofl/opensans/OpenSans%5Bwght%5D.ttf"
        "${FONT_PATH}"
        STATUS FONT_DOWNLOAD_STATUS
        SHOW_PROGRESS
    )
    list(GET FONT_DOWNLOAD_STATUS 0 FONT_STATUS_CODE)
    if(NOT FONT_STATUS_CODE EQUAL 0)
        message(WARNING
            "Could not download the font. Place OpenSans-Regular.ttf or another "
            "OpenType/TrueType font in assets/fonts/ and update UI.cpp if needed."
        )
    endif()
endif()

add_custom_command(TARGET HangmanSFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:HangmanSFML>/assets"
)
