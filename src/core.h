//info and variables you need shared across core and game, 
//but which are generally core-specific or need libreto.h

//#include "libretro.h"
#ifndef CORE_H
#define CORE_H

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <cmath> //#include <math.h>
#include <thread>
#include <cstring>//for memset

#if defined(_WIN32) && !defined(_XBOX)
#include <windows.h>
#endif

#include "libretro.h"
#include "game.h"

#define VIDEO_WIDTH 384 //256
#define VIDEO_HEIGHT 384 //384
#define VIDEO_PIXELS VIDEO_WIDTH * VIDEO_HEIGHT

#endif //CORE_H