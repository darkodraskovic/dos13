cmake_minimum_required(VERSION 3.8)
project (boilerplate C)

set(DJGPP_DIR "/home/darko/Programs/djgpp/")
set(CMAKE_C_COMPILER "${DJGPP_DIR}/bin/i586-pc-msdosdjgpp-g++")
set(DJGPP_INCLUDE "${DJGPP_DIR}//i586-pc-msdosdjgpp/sys-include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(MODE_13 src/mode_13h)
add_library(mode_13h
  ${MODE_13}/app.c
  ${MODE_13}/bitmap.c
  ${MODE_13}/display.c
  ${MODE_13}/primitive.c
  )
target_include_directories(mode_13h PUBLIC ${DJGPP_INCLUDE})

file(GLOB_RECURSE ASM_FILES "src/asm/*.o")
add_executable(main.exe
  ${ASM_FILES}
  src/main.c
  )
target_include_directories(main.exe PUBLIC src)
target_link_libraries(main.exe PRIVATE mode_13h)

