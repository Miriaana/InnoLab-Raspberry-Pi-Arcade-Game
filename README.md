# InnoLab-Raspberry-Pi-Arcade-Game

# build commands
### windows in vscode:
- configure cmake:  
``cmake -S . -B out/build/windows/``
- build program (MSBuild has to be added to the PATH beforehand):  
    ``MSBuild.exe out/build/windows/InnoLab_Core.sln``
- install(copy) core to zB. retroarch core folder  
``cmake --install out/build/windows/ --config Debug --prefix "C:/RetroArch-Win64/downloads/INNOCore"``
- open retroarch over commandline  
``C:\RetroArch-Win64\retroarch --menu -v``

### ubuntu:
``
$ cmake -S . -B out/build/linux/
$ make -C out/build/linux/
$ cmake --install out/build/linux/ --config Debug --prefix "/home/miriam/.config/retroarch/downloads/"
$ (cd ../../../.config/retroarch && exec retroarch --menu -v)
``


