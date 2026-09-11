cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

message(VERBOSE "Executing patch step for vorbis")

block(SCOPE_FOR VARIABLES)

execute_process(
  WORKING_DIRECTORY "/Users/michaelhernandez/Desktop/CS370/HangmanSFML/build/_deps/vorbis-src"
  COMMAND_ERROR_IS_FATAL LAST
  COMMAND  [====[/opt/homebrew/bin/cmake]====] [====[-DVORBIS_DIR=/Users/michaelhernandez/Desktop/CS370/HangmanSFML/build/_deps/vorbis-src]====] [====[-P]====] [====[/Users/michaelhernandez/Desktop/CS370/HangmanSFML/build/_deps/sfml-src/tools/vorbis/PatchVorbis.cmake]====]
)

endblock()
