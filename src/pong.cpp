#include "pong.h"

Ball::Ball(float tempX, float tempY, float tempDiameter) {
    x = tempX;
    y = tempY;
    diameter = tempDiameter;
    radius = diameter/2;
    speedX = 0;
    speedY = 0;
    color = 225;
}

void Ball::move() {
    y = y + speedY;
    x = x + speedX;
}

void Ball::display(uint8_t* frame_buf, int screen_width, int screen_height) {
    for (int h = floor(y - radius); h <= ceil(y + radius); h++) {
        for (int w = floor(x - radius); w <= ceil(x + radius); w++) {
            if ((w >= 0 && w < screen_width && h >= 0 && h < screen_height)) {
                float x_dist_to_center = x - w;
                float y_dist_to_center = y - h;
                float distance = sqrt(pow(x_dist_to_center, 2) + pow(y_dist_to_center, 2));
                if (distance  < radius) {
                    int curr_pixel = h * screen_width * 4 + w * 4;
                    //fprintf(stderr, "%d\t", curr_pixel);
                    frame_buf[curr_pixel] = 220;//blue
                    frame_buf[++curr_pixel] = 220;//green
                    frame_buf[++curr_pixel] = 220;//red
                }
                else if(distance < radius + 0.3){
                    int curr_pixel = h * screen_width * 4 + w * 4;
                    //fprintf(stderr, "%d\t", curr_pixel);
                    frame_buf[curr_pixel] = 150;//blue
                    frame_buf[++curr_pixel] = 150;//green
                    frame_buf[++curr_pixel] = 150;//red
                }
            }
        }
    }
    //paint cirle with diameter into frame_buf
}

//functions to help with collision detection
float Ball::left() {
    return x - diameter / 2;
}
float Ball::right() {
    return x + diameter / 2;
}
float Ball::top() {
    return y - diameter / 2;
}
float Ball::bottom() {
    return y + diameter / 2;
}

Paddle::Paddle(float tempX, float tempY, float tempW, float tempH){
    x = tempX;
    y = tempY;
    w = tempW;
    h = tempH;
    speedY = 0;
    speedX = 0;
    //c=(255);
}

void Paddle::move(){
    y += speedY;
    x += speedX;
}

void Paddle::display(uint8_t* frame_buf, int screen_width, int screen_height) {
    for (int height = y - h/2; height <= y + h/2; height++) {
        for (int width = x - w/2; width <= x + w/2; width++) {
            if ((width >= 0 && width < screen_width && height >= 0 && height < screen_height)) {
                int curr_pixel = height * screen_width * 4 + width * 4;
                frame_buf[curr_pixel] = 200;//blue
                frame_buf[++curr_pixel] = 200;//green
                frame_buf[++curr_pixel] = 200;
            }
        }
    }
    //paint cirle with diameter into frame_buf
}

//functions to help with collision detection
float Paddle::left() {
    return x - w / 2;
}
float Paddle::right() {
    return x + w / 2;
}
float Paddle::top() {
    return y - h / 2;
}
float Paddle::bottom() {
    return y + h / 2;
}