# InnoLab-Raspberry-Pi-Arcade-Game

compiling under windows in visual studio code
    start in src directory
    configure cmake:
        cmake -S . -B ../out/build/windows/
    build program (MSBuild has to be added to the path beforehand):
        MSBuild.exe ../out/build/windows/InnoLab_Core.sln
    install(copy) core to zB. retroarch core folder
        cmake --install ../out/build/windows/ --config Debug --prefix "C:/RetroArch-Win64/downloads/INNOCore"

compiling under linux
    start in src directory
    configure cmake:
        cmake -S . -B ../out/build/linux/
    build program:
        cd ../out/build/linux
        make
    install(copy) core to zB. retroarch core folder
        cmake --install . --config Debug --prefix "/mnt/c/RetroArch-Win64/downloads/INNOCore"

