#include "raylib.h"
#include <iostream>

using namespace std;

typedef enum GameScreen {
    MENU = 0,
    PLAY,
    OPTIONS,
    RULES,
    EXIT
} GameScreen;

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Main Menu");

    GameScreen currentScreen = MENU;

    int framesCounter = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        switch (currentScreen)
        {
            case MENU:
            {
                if (IsKeyPressed(KEY_P))
                {
                    currentScreen = PLAY;
                }
                if (IsKeyPressed(KEY_O))
                {
                    currentScreen = OPTIONS;
                }
                if (IsKeyPressed(KEY_R))
                {
                    currentScreen = RULES;
                }
                if (IsKeyPressed(KEY_E))
                {
                    currentScreen = EXIT;
                }
            }
                break;

            case PLAY:
            {
                if (IsKeyPressed(KEY_M))
                {
                    currentScreen = MENU;
                }
            }
                break;
            
            case OPTIONS:
            {
                if (IsKeyPressed(KEY_M))
                {
                    currentScreen = MENU;
                }
            }
                break;

            case RULES:
            {
                if (IsKeyPressed(KEY_M))
                {
                    currentScreen = MENU;
                }
            }
                break;

            default:
                break;
        }



        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch (currentScreen)
            {
                case MENU:
                {
                    DrawText("PLAY [P]", 720, 200, 120, DARKGRAY);
                    DrawText("OPTIONS [O]", 600, 400, 120, DARKGRAY);
                    DrawText("RULES [R]", 680, 600, 120, DARKGRAY);
                    DrawText("EXIT [E]", 720, 800, 120, DARKGRAY);
                }
                    break;

                case PLAY:
                {
                    DrawRectangle(100, 100, 800, 800, GREEN);
                    DrawText("Here you will play in the future", 400, 400, 80, RED);

                }
                    break;

                case OPTIONS:
                {
                    DrawRectangle(100, 100, 800, 800, PURPLE);
                    DrawText("Here you will see the options in the future", 400, 400, 80, BROWN);

                }
                    break;

                case RULES:
                {
                    DrawRectangle(100, 100, 800, 800, BLUE);
                    DrawText("Here you will see the rules in the future", 400, 400, 80, GRAY);

                }
                    break;

                case EXIT:
                {
                    DrawText("Exit after 2 seconds", 500, 200, 90, BLUE);

                    framesCounter++;

                    if (framesCounter > 120)
                    {
                        CloseWindow();
                    }
                }

                default:
                    break;
            }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}