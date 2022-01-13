cmake_minimum_required (VERSION 3.15)

project ("InnoLab_Core")

# add_subdirectory ("SubdirName")

# add_executable (NAME "core.cpp" "libretro.h")
add_library (InnoLab_Core SHARED "core.cpp" "libretro.h")
# add_library (Skeletor SHARED "skeletor.c" "libretro.h")

# target_link_libraries(${PROJECT_NAME} libname)

install(TARGETS InnoLab_Core DESTINATION .) # C:/RetroArch-Win64/downloads/INNOCore
# install(FILES name.h DESTINATION path)
