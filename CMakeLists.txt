cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(DJGPP_DIR "/home/darko/Programs/djgpp/")
set(CMAKE_C_COMPILER "${DJGPP_DIR}/bin/i586-pc-msdosdjgpp-g++")
set(DJGPP_INCLUDE "${DJGPP_DIR}//i586-pc-msdosdjgpp/sys-include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main
  src/app.c
  src/display.c
  src/draw.c
  src/main.c
  )
target_include_directories(main PUBLIC ${DJGPP_INCLUDE})
