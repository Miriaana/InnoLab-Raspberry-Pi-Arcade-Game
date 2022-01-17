#include "game.h"

bool key_up = false;
bool key_down = false;
bool key_left = false;
bool key_right = false;

Ball ball(VIDEO_WIDTH/2, VIDEO_HEIGHT/2, 20);//pong
Paddle paddleLeft(10, VIDEO_HEIGHT/2, 20,100);
Paddle paddleRight(VIDEO_WIDTH-10, VIDEO_HEIGHT/2, 20,100);
int scoreLeft = 0;
int scoreRight = 0;

void game_init(){
    printf("in game_init\n");
    ball.speedX = 5; // Giving the ball speed in x-axis //pong
    srand (time(NULL));
    ball.speedY = rand()%7-3; // Giving the ball speed in y-axis between -3 and 3
}

void game_deinit(){
    printf("in game_deinit\n");
}

void game_reset(){
    printf("in game_reset\n");
}

void score_display(uint8_t* frame_buf){
    if(scoreLeft == 0 && scoreRight == 0)
        return;
    
    int score_size = 6;
    int space_between = 2;
    int space_up = 2;
    int space_side = 2;
    int xPos;
    int points;

    //draw seperator
    for (int y = 0; y < 10; y++) {
        int curr_pixel = y * VIDEO_WIDTH * 4 + VIDEO_WIDTH * 2;// -> VIDEO_WIDTH * 4 / 2
        frame_buf[curr_pixel] = 150;//blue
        frame_buf[++curr_pixel] = 150;//green
        frame_buf[++curr_pixel] = 150;//red
    }

    //draw left score
    points = scoreLeft;
    xPos = VIDEO_WIDTH/2 - space_side - score_size;

    while(points>0){
        //draw 1 point
        for (int y = space_up; y < space_up + score_size; y++) {
            for (int x = xPos; x < xPos + score_size; x++) {
                if (x >= 0 && x < VIDEO_WIDTH && y >= 0 && y < VIDEO_HEIGHT){//just in case, but shouldn't be necessary
                    int curr_pixel = y * VIDEO_WIDTH * 4 + x * 4;
                    frame_buf[curr_pixel] = 155;//blue
                    frame_buf[++curr_pixel] = 220;//green
                    frame_buf[++curr_pixel] = 235;//red
                }
            }
        }
        xPos = xPos - space_between - score_size;
        points--;
    }

    //draw right score
    points = scoreRight;
    xPos = VIDEO_WIDTH/2 + space_side;

    while(points>0){
        //draw 1 point
        for (int y = space_up; y < space_up + score_size; y++) {
            for (int x = xPos; x < xPos + score_size; x++) {
                if (x >= 0 && x < VIDEO_WIDTH && y >= 0 && y < VIDEO_HEIGHT){//just in case, but shouldn't be necessary
                    int curr_pixel = y * VIDEO_WIDTH * 4 + x * 4;
                    frame_buf[curr_pixel] = 155;//blue
                    frame_buf[++curr_pixel] = 220;//green
                    frame_buf[++curr_pixel] = 235;//red
                }
            }
        }
        xPos = xPos + space_between + score_size;
        points--;
    }
}

void game_draw(uint8_t* frame_buf){
    for (int j = 0; j < VIDEO_PIXELS * 4; j++) {//wipe display
            frame_buf[j] = 50;
    }
    paddleLeft.display(frame_buf, VIDEO_WIDTH, VIDEO_HEIGHT);
    paddleRight.display(frame_buf, VIDEO_WIDTH, VIDEO_HEIGHT);
    ball.display(frame_buf, VIDEO_WIDTH, VIDEO_HEIGHT);
    score_display(frame_buf);
}

void game_run(){
    
    ball.move();
    paddleRight.move();
    paddleLeft.move();

    //ball collision detection
    if (ball.right() > VIDEO_WIDTH) {
        scoreLeft++;
        ball.x = VIDEO_WIDTH/2;
        ball.y = VIDEO_HEIGHT/2;
        ball.speedX = -ball.speedX;
        ball.speedY = rand()%7-3; // Giving the ball speed in y-axis between -3 and 3
    }
    if (ball.left() < 0) {
        scoreRight++;
        ball.x = VIDEO_WIDTH/2;
        ball.y = VIDEO_HEIGHT/2;
        ball.speedX = -ball.speedX;
        ball.speedY = rand()%7-3;
    }
    if (ball.bottom() > VIDEO_HEIGHT) {
        ball.speedY = -ball.speedY;
    }
    if (ball.top() < 0) {
        ball.speedY = -ball.speedY;
    }

    //paddles collision detection
    if (paddleLeft.bottom() > VIDEO_HEIGHT) {
        paddleLeft.y = VIDEO_HEIGHT-paddleLeft.h/2;
    }
    if (paddleLeft.top() < 0) {
        paddleLeft.y = paddleLeft.h/2;
    }
    if (paddleRight.bottom() > VIDEO_HEIGHT) {
        paddleRight.y = VIDEO_HEIGHT-paddleRight.h/2;
    }
    if (paddleRight.top() < 0) {
        paddleRight.y = paddleRight.h/2;
    }

    if (key_up) {
        paddleRight.speedY=-10;
    } else if (key_down) {
        paddleRight.speedY=10;
    } else{
        paddleRight.speedY=0;
    }
    if (key_left) {
        paddleLeft.speedY=-10;
    } else if (key_right) {
        paddleLeft.speedY=10;
    } else{
        paddleLeft.speedY=0;
    }
    // If the ball gets behind the paddle 
    // AND if the ball is int he area of the paddle (between paddle top and bottom)
    // AND the ball hasn't already bounced of
    // bounce the ball to other direction
    //left paddle
    if ( ball.left() < paddleLeft.right() && ball.y > paddleLeft.top() && ball.y < paddleLeft.bottom() && ball.speedX < 0){
        ball.speedX = -ball.speedX;
    }
    //right paddle
    if ( ball.right() > paddleRight.left() && ball.y > paddleRight.top() && ball.y < paddleRight.bottom() && ball.speedX > 0) {
        ball.speedX = -ball.speedX;
    }
}

