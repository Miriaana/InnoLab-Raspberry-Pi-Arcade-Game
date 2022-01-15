#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <cmath>

class Ball {
public:
    float x;
    float y;
    float speedX;
    float speedY;
    float diameter;
    float radius;
    uint8_t color;

    Ball(float tempX, float tempY, float tempDiameter);

    void move();

    void display(uint8_t* frame_buf, int screen_width, int screen_height);

    //functions to help with collision detection
    float left();
    float right();
    float top();
    float bottom();
};

class Paddle{
public:
  float x;
  float y;
  float w;
  float h;
  float speedY;
  float speedX;
  //color c;
  
  Paddle(float tempX, float tempY, float tempW, float tempH);

  void move();

  void display(uint8_t* frame_buf, int screen_width, int screen_height);

    //functions to help with collision detection
    float left();
    float right();
    float top();
    float bottom();
};

