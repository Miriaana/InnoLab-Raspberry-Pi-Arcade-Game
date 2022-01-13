#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#include <cmath>

class Ball {
    float x;
    float y;
    float speedX;
    float speedY;
    float diameter;
    uint8_t color;

    Ball(float tempX, float tempY, float tempDiameter) {
        x = tempX;
        y = tempY;
        diameter = tempDiameter;
        speedX = 0;
        speedY = 0;
        color = 225;
    }

    void move() {
        y = y + speedY;
        x = x + speedX;
    }

    void display(uint8_t* frame_buf) {
        //paint cirle with diameter into frame_buf
    }

    //functions to help with collision detection
    float left() {
        return x - diameter / 2;
    }
    float right() {
        return x + diameter / 2;
    }
    float top() {
        return y - diameter / 2;
    }
    float bottom() {
        return y + diameter / 2;
    }
};