#include "raylib.h"
#include <string>

int main(){
    //init size of window and title
    int width {1280};
    int height {720};
    std::string title = "Axe Game";
    // Window
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);

    //circle coordinates
    int circleX {200};
    int circleY {360};
    int circleRadius {25};
    //circle bounds
    int circleLeft {circleX - circleRadius};
    int circleRight {circleX + circleRadius};
    int circleTop {circleY - circleRadius};
    int circleBottom {circleY + circleRadius};

    //circle speed
    int circleSpeed {10};
    // collision
    bool collision =
        (circleLeft <= circleRight) &&
        (circleRight >= circleLeft) &&
        (circleTop <= circleBottom) &&
        (circleBottom >= circleTop);

    //axe coordinates
    int axeX {640};
    int axeY {360};
    int axeLength {50};


    //axe bounds
    int axeLeft {axeX};
    int axeRight {axeX + axeLength};
    int axeTop {axeY};
    int axeBottom {axeY + axeLength};




    int direction {10};
    // Main Loop
    while(!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(WHITE);
            if(collision){
                DrawText("Game Over", 550, 360, 50, RED);
                DrawText("Press Space to Restart", 500, 400, 20, RED);
                if(IsKeyDown(KEY_SPACE)){
                    collision = false;
                    circleX = 200;
                    axeY = 360;
                    direction = 10;
                }
            }
            else{
                 //game logic begins here
            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX, axeY, 50, 50, RED);
            //update bounds

            axeLeft = axeX;
            axeRight = axeX + axeLength;
            axeTop = axeY;
            axeBottom = axeY + axeLength;
            circleLeft = circleX - circleRadius;
            circleRight = circleX + circleRadius;
            circleTop = circleY - circleRadius;
            circleBottom = circleY + circleRadius;

            //axe movement
            axeY += direction;
            if (axeY >= height-50 || axeY <= 0){
                direction = -direction;
            }



            //collision detection
            collision =
                (circleLeft <= axeRight) &&
                (circleRight >= axeLeft) &&
                (circleTop <= axeBottom) &&
                (circleBottom >= axeTop);
            if(IsKeyDown(KEY_D)&&circleX<width-50){
                circleX += circleSpeed;
            }
            if(IsKeyDown(KEY_A)&&circleX>50){
                circleX -= circleSpeed;
            }
            }


            //game logic ends here
        EndDrawing();
    }
}