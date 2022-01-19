# retroarch and libretro
## about retroarch
- [official website](https://www.retroarch.com/)
- [download retroarch for your platform](https://www.retroarch.com/?page=platforms)
- you find plenty of recources online on how to work with retroarch, just google it

- important things to know for developing your own cores for retroarch:
  - you load your own cores from mainMenu >> loadCore >> installOrRestoreACore  
    more on that under _**how to compile our core**_
  - you can rebind your keys to controlls under settings >> input  
    useful since thus far in the project the left pong-paddle is played with the left- and right arrowkeys, you can rebind them to sth like [w] and [s]
  - for debugging it is useful to log messages to a console, you can turn this on under settings >> logging -> logging verbosity on  
    if this does not work, you can instead start retroarch from the retroarch folder with  
    retroarch --menu --verbose

## libretro core development 
- [libretro github](https://github.com/libretro)
- [libretro.h](https://github.com/libretro/libretro-common/blob/master/include/libretro.h)
- [developing libretro cores](https://docs.libretro.com/development/cores/developing-cores/)  
  should give you a rough overview on important functions
- [skeletor](https://github.com/libretro/skeletor)  
  in our core we used the skeletor libretro.c file as a basis for our own core.cpp file

# our core
to add:
- our core and libretro functions
- implemented functions
- every decision made 
    
# how to compile our core
- cmake and terminal commands 
- windows/linux 
- .bat/.sh scripts 
