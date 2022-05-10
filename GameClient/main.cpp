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
            if (darkMode)
            {
                ClearBackground(BLACK);

                DrawText("PLAY [P]", 720, 200, 120, WHITE);
                DrawText("OPTIONS [O]", 600, 400, 120, WHITE);
                DrawText("RULES [R]", 680, 600, 120, WHITE);
                DrawText("EXIT [E]", 720, 800, 120, WHITE);
            }
            else
            {
                DrawText("PLAY [P]", 720, 200, 120, DARKGRAY);
                DrawText("OPTIONS [O]", 600, 400, 120, DARKGRAY);
                DrawText("RULES [R]", 680, 600, 120, DARKGRAY);
                DrawText("EXIT [E]", 720, 800, 120, DARKGRAY);
            }
        }
        break;

        case PLAY:
        {
            if (darkMode)
            {
                ClearBackground(BLACK);
            }

            Image start_card = LoadImage("texture/starter_card.png");
            ImageResize(&start_card, 150, 190);

            Image deck = LoadImage("texture/deck.png");
            ImageResize(&deck, 200, 270);
            Texture2D deck_tex = LoadTextureFromImage(deck);
            DrawTexture(deck_tex, 1650, 100, WHITE);

            srand(time(NULL));

            //Initial binaries randomise
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

            //Deck
            string cards[6][8]{
                { "1and", "1and", "1and", "1and", "1and", "1and", "1and", "1and" },
                { "0and", "0and", "0and", "0and", "0and", "0and", "0and", "0and" },
                { "1or", "1or", "1or", "1or", "1or", "1or", "1or", "1or" },
                { "0or", "0or", "0or", "0or", "0or", "0or", "0or", "0or" },
                { "1xor", "1xor", "1xor", "1xor", "1xor", "1xor", "1xor", "1xor" },
                { "0xor", "0xor", "0xor", "0xor", "0xor", "0xor", "0xor", "0xor" }
            };

            //First - 5 random cards (choose 1 to put or discard); next time - pull 1 (-||-)

            //First 5 random cards
            int randRow = 0, randCol = 0;
            string playerCards[7];

            randomiseCards = false;

            if (!randomiseCards)
            {
                for (int i = 0; i < 5; i++)
                {
                    randRow = rand() % 6;
                    randCol = rand() % 8;

                    if (cards[randRow][randCol] != "empty")
                    {
                        playerCards[i] = cards[randRow][randCol];
                        cards[randRow][randCol] = "empty";
                    }
                }

                randomiseCards = true;
            }
            
            if (darkMode)
            {
                DrawText("Player 1's deck", 15, 50, 20, WHITE);
            }
            else
            {
                DrawText("Player 1's deck", 15, 50, 20, BLACK);
            }

            x = 15;
            y = 80;

            for (int i = 0; i < 5; i++)
            {
                if (playerCards[i] == "1and")
                {
                    Image card = LoadImage("texture/1and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "0and")
                {
                    Image card = LoadImage("texture/0and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "1or")
                {
                    Image card = LoadImage("texture/1or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "0or")
                {
                    Image card = LoadImage("texture/0or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "1xor")
                {
                    Image card = LoadImage("texture/1xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "0xor")
                {
                    Image card = LoadImage("texture/0xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }

                x += 75;
            }

            if (darkMode)
            {
                DrawText("Player 2's deck", 15, 210, 20, WHITE);
            }
            else
            {
                DrawText("Player 2's deck", 15, 210, 20, BLACK);
            }

            x = 15;
            y = 240;

            randomiseCards = false;

            if (!randomiseCards)
            {
                for (int i = 0; i < 5; i++)
                {
                    randRow = rand() % 6;
                    randCol = rand() % 8;

                    if (cards[randRow][randCol] != "empty")
                    {
                        playerCards[i] = cards[randRow][randCol];
                        cards[randRow][randCol] = "empty";
                    }
                }

                randomiseCards = true;
            }

            for (int i = 0; i < 5; i++)
            {
                if (playerCards[i] == "1and")
                {
                    Image card = LoadImage("texture/1and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "0and")
                {
                    Image card = LoadImage("texture/0and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "1or")
                {
                    Image card = LoadImage("texture/1or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "0or")
                {
                    Image card = LoadImage("texture/0or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "1xor")
                {
                    Image card = LoadImage("texture/1xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (playerCards[i] == "0xor")
                {
                    Image card = LoadImage("texture/0xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }

                x += 75;
            }
        }
        break;

        case OPTIONS:
        {
            if (darkMode)
            {
                ClearBackground(BLACK);

                DrawFPS(30, 60);

                DrawText("OPTIONS", 720, 120, 110, BLUE);

                DrawText("Choose FPS", 120, 300, 70, GOLD);

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
            }
            else
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
            }

            if (darkMode)
            {
                DrawRectangle(700, 830, 100, 100, GREEN);
            }

        }
        break;

        case RULES:
        {
            if (darkMode)
            {
                ClearBackground(BLACK);
            }

            DrawRectangle(100, 100, 800, 800, BLUE);
            DrawText("Here you will see the rules in the future", 400, 400, 80, GRAY);

        }
        break;

        case EXIT:
        {
            if (darkMode)
            {
                ClearBackground(BLACK);
                DrawText("Exit after 2 seconds", 500, 200, 90, WHITE);
            }
            else
            {
                DrawText("Exit after 2 seconds", 500, 200, 90, BLUE);
            }
            

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