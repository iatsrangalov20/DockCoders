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

    InitWindow(screenWidth, screenHeight, "Game");

    GameScreen currentScreen = MENU;

    int framesCounter = 0;
    bool darkMode = false;
    bool randomiseCards = false;

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
            if (IsKeyPressed(KEY_SIX))
            {
                SetTargetFPS(60);
            }
            if (IsKeyPressed(KEY_ONE) && IsKeyPressed(KEY_TWO))
            {
                SetTargetFPS(120);
            }
            if (IsKeyPressed(KEY_ONE) && IsKeyPressed(KEY_EIGHT))
            {
                SetTargetFPS(180);
            }
            if (IsKeyPressed(KEY_TWO) && IsKeyPressed(KEY_FOUR))
            {
                SetTargetFPS(240);
            }
            if (IsKeyPressed(KEY_D))
            {
                darkMode = true;
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
            Image start_card = LoadImage("texture/starter_card.png");
            ImageResize(&start_card, 150, 190);

            Image deck = LoadImage("texture/deck.png");
            ImageResize(&deck, 200, 270);
            Texture2D deck_tex = LoadTextureFromImage(deck);
            DrawTexture(deck_tex, 1650, 100, WHITE);

            srand(time(NULL));

            int choice[6];

            if (!randomiseCards)
            {
                for (int i = 0; i < 6; i++)
                {
                    choice[i] = rand() % 2;
                }

                randomiseCards = true;
            }

            int x = 400, y = 450;

            for (int i = 0; i < 6; i++)
            {
                switch (choice[i])
                {
                case 0:
                {
                    Texture2D img_tex = LoadTextureFromImage(start_card);
                    DrawTexture(img_tex, x, y, WHITE);
                    break;
                }
                case 1:
                {
                    ImageFlipVertical(&start_card);
                    Texture2D img_tex = LoadTextureFromImage(start_card);
                    DrawTexture(img_tex, x, y, WHITE);
                    break;
                }
                }

                x += 200;
            }


        }
        break;

        case OPTIONS:
        {
            DrawFPS(30, 60);

            DrawText("OPTIONS", 720, 120, 110, BROWN);

            DrawText("Choose FPS", 120, 300, 70, RED);

            DrawRectangle(250, 450, 100, 100, BLUE);
            DrawRectangle(700, 450, 100, 100, BLUE);
            DrawRectangle(1160, 450, 100, 100, BLUE);
            DrawRectangle(1600, 450, 100, 100, BLUE);

            DrawText("60", 260, 570, 70, BLUE);
            DrawText("[6]", 260, 650, 70, GOLD);
            DrawText("120", 700, 570, 70, BLUE);
            DrawText("[12]", 700, 650, 70, GOLD);
            DrawText("180", 1160, 570, 70, BLUE);
            DrawText("[18]", 1160, 650, 70, GOLD);
            DrawText("240", 1590, 570, 70, BLUE);
            DrawText("[24]", 1590, 650, 70, GOLD);

            DrawText("Dark Mode [D]", 120, 850, 70, GREEN);
            DrawRectangle(700, 830, 100, 100, LIGHTGRAY);

            if (darkMode == true)
            {
                DrawRectangle(700, 830, 100, 100, GREEN);
            }

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