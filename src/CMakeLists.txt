cmake_minimum_required (VERSION 3.8)

# add_executable (NAME "core.cpp" "libretro.h")
add_library (Pong SHARED "core.cpp" "libretro.h" "pong.h" "pong.cpp")
# add_library (Skeletor SHARED "skeletor.c" "libretro.h")

# target_link_libraries(${PROJECT_NAME} libname)

install(TARGETS Pong DESTINATION .) # C:/RetroArch-Win64/downloads/INNOCore
# install(FILES name.h DESTINATION path)
# TODO: Add tests and install targets if needed.
