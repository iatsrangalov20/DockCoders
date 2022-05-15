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

int main()
{
    // window measurements

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    // create window

    InitWindow(screenWidth, screenHeight, "Game");

    GameScreen currentScreen = MENU;

    // Important variables

    string pos[5];
    int framesCounter = 0;
    bool darkMode = false;
    int randRow = 0, randCol = 0;
    string player1Cards[7], player2Cards[7];
    bool initialCardsValueP1[6], initialCardsValueP2[6];
    bool cardsValue;

    // Card deck

    string cardsName[6][8]{
        { "1and", "1and", "1and", "1and", "1and", "1and", "1and", "1and" },
        { "0and", "0and", "0and", "0and", "0and", "0and", "0and", "0and" },
        { "1or", "1or", "1or", "1or", "1or", "1or", "1or", "1or" },
        { "0or", "0or", "0or", "0or", "0or", "0or", "0or", "0or" },
        { "1xor", "1xor", "1xor", "1xor", "1xor", "1xor", "1xor", "1xor" },
        { "0xor", "0xor", "0xor", "0xor", "0xor", "0xor", "0xor", "0xor" }
    };

    SetTargetFPS(60);

    int choice[6];

    // randomise initial binaries

    for (int i = 0; i < 6; i++)
    {
        choice[i] = rand() % 2;

        if (choice[i] == 0)
        {
            initialCardsValueP1[i] = 0;
            initialCardsValueP2[i] = 1;
        }
        else
        {
            initialCardsValueP1[i] = 1;
            initialCardsValueP2[i] = 0;
        }
    }

    // randomise first player's cards

    for (int i = 0; i < 5; i++)
    {
        randRow = rand() % 6;
        randCol = rand() % 8;

        if (cardsName[randRow][randCol] != "empty")
        {
            player1Cards[i] = cardsName[randRow][randCol];
            cardsName[randRow][randCol] = "empty";
        }
        else
        {
            while (true)
            {
                randRow = rand() % 6;
                randCol = rand() % 8;

                if (cardsName[randRow][randCol] != "empty")
                {
                    player1Cards[i] = cardsName[randRow][randCol];
                    cardsName[randRow][randCol] = "empty";
                    break;
                }
            }
        }

    }

    // Randomise second player's cards

    for (int i = 0; i < 5; i++)
    {
        randRow = rand() % 6;
        randCol = rand() % 8;

        if (cardsName[randRow][randCol] != "empty")
        {
            player2Cards[i] = cardsName[randRow][randCol];
            cardsName[randRow][randCol] = "empty";
        }

        else
        {
            while (true)
            {
                randRow = rand() % 6;
                randCol = rand() % 8;

                if (cardsName[randRow][randCol] != "empty")
                {
                    player2Cards[i] = cardsName[randRow][randCol];
                    cardsName[randRow][randCol] = "empty";
                    break;
                }
            }
        }

    }

    if (randRow % 2 == 0)
    {
        cardsValue = 1;
    }
    else
    {
        cardsValue = 0;
    }

    // Switch screens 

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
                darkMode = true; // dark mode 
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
        case EXIT:
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


        // check which screen is the user on

        switch (currentScreen)
        {
        case MENU:
        {
            if (darkMode)
            {
                ClearBackground(BLACK);

                DrawRectangle(60, 80, 860, 440, LIGHTGRAY);
                DrawRectangle(980, 80, 860, 440, LIGHTGRAY);
                DrawRectangle(60, 550, 860, 440, LIGHTGRAY);
                DrawRectangle(980, 550, 860, 440, LIGHTGRAY);

                DrawText("PLAY", 340, 160, 120, MAROON);
                DrawText("[P]", 420, 340, 120, MAROON);
                DrawText("OPTIONS", 1150, 160, 120, MAROON);
                DrawText("[O]", 1350, 340, 120, MAROON);
                DrawText("RULES", 290, 620, 120, MAROON);
                DrawText("[R]", 420, 800, 120, MAROON);
                DrawText("EXIT", 1280, 620, 120, MAROON);
                DrawText("[E]", 1350, 800, 120, MAROON);
            }
            else
            {
                DrawRectangle(60, 80, 860, 440, LIGHTGRAY);
                DrawRectangle(980, 80, 860, 440, LIGHTGRAY);
                DrawRectangle(60, 550, 860, 440, LIGHTGRAY);
                DrawRectangle(980, 550, 860, 440, LIGHTGRAY);

                DrawText("PLAY", 340, 160, 120, MAROON);
                DrawText("[P]", 420, 340, 120, MAROON);
                DrawText("OPTIONS", 1150, 160, 120, MAROON);
                DrawText("[O]", 1350, 340, 120, MAROON);
                DrawText("RULES", 290, 620, 120, MAROON);
                DrawText("[R]", 420, 800, 120, MAROON);
                DrawText("EXIT", 1280, 620, 120, MAROON);
                DrawText("[E]", 1350, 800, 120, MAROON);
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
            

            srand(time(NULL)); // every time get different random number 

            int x = 525, y = 325, sizeX = 100, sizeY = 140;

            if (pos[0] == "1and")
            {
                Image card = LoadImage("texture/1and.png");
                ImageResize(&card, sizeX, sizeY);
                Texture2D img_card = LoadTextureFromImage(card);
                DrawTexture(img_card, x, y, WHITE);
            }
            if (pos[0] == "0and")
            {
                Image card = LoadImage("texture/0and.png");
                ImageResize(&card, sizeX, sizeY);
                ImageFlipVertical(&card);
                Texture2D img_card = LoadTextureFromImage(card);
                DrawTexture(img_card, x, y, WHITE);
            }
            if (pos[0] == "1or")
            {
                Image card = LoadImage("texture/1or.png");
                ImageResize(&card, sizeX, sizeY);
                ImageFlipVertical(&card);
                Texture2D img_card = LoadTextureFromImage(card);
                DrawTexture(img_card, x, y, WHITE);
            }
            if (pos[0] == "0or")
            {
                Image card = LoadImage("texture/0or.png");
                ImageResize(&card, sizeX, sizeY);
                ImageFlipVertical(&card);
                Texture2D img_card = LoadTextureFromImage(card);
                DrawTexture(img_card, x, y, WHITE);
            }
            if (pos[0] == "1xor")
            {
                Image card = LoadImage("texture/1xor.png");
                ImageResize(&card, sizeX, sizeY);
                ImageFlipVertical(&card);
                Texture2D img_card = LoadTextureFromImage(card);
                DrawTexture(img_card, x, y, WHITE);
            }
            if (pos[0] == "0xor")
            {
                Image card = LoadImage("texture/0xor.png");
                ImageResize(&card, sizeX, sizeY);
                ImageFlipVertical(&card);
                Texture2D img_card = LoadTextureFromImage(card);
                DrawTexture(img_card, x, y, WHITE);
            }


            //Initial binaries randomise


            x = 400;
            y = 450;

            for (int i = 0; i < 6; i++)
            {
                // visualise initial binaries 

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
                // visualise player one's deck

                if (player1Cards[i] == "1and")
                {
                    Image card = LoadImage("texture/1and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player1Cards[i] == "0and")
                {
                    Image card = LoadImage("texture/0and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player1Cards[i] == "1or")
                {
                    Image card = LoadImage("texture/1or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player1Cards[i] == "0or")
                {
                    Image card = LoadImage("texture/0or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player1Cards[i] == "1xor")
                {
                    Image card = LoadImage("texture/1xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player1Cards[i] == "0xor")
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




            for (int i = 0; i < 5; i++)
            {

                // visulise playe two's deck

                if (player2Cards[i] == "1and")
                {
                    Image card = LoadImage("texture/1and.png"); // load image in memory
                    ImageResize(&card, 60, 100); // resize image 
                    ImageFlipVertical(&card); // flip image 
                    Texture2D img_card = LoadTextureFromImage(card); // create texture for image 
                    DrawTexture(img_card, x, y, WHITE); // visualise texture
                }
                if (player2Cards[i] == "0and")
                {
                    Image card = LoadImage("texture/0and.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player2Cards[i] == "1or")
                {
                    Image card = LoadImage("texture/1or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player2Cards[i] == "0or")
                {
                    Image card = LoadImage("texture/0or.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player2Cards[i] == "1xor")
                {
                    Image card = LoadImage("texture/1xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }
                if (player2Cards[i] == "0xor")
                {
                    Image card = LoadImage("texture/0xor.png");
                    ImageResize(&card, 60, 100);
                    ImageFlipVertical(&card);
                    Texture2D img_card = LoadTextureFromImage(card);
                    DrawTexture(img_card, x, y, WHITE);
                }

                x += 75;
            }

            // plays first card

            if (IsKeyPressed(KEY_A))
            {
                pos[0] = player1Cards[0];
            }

        }
        break;

        case OPTIONS:
        {
            // options design dark mode 

            if (darkMode == true)
            {
                ClearBackground(BLACK);

                DrawFPS(30, 60);

                DrawText("OPTIONS", 720, 120, 110, DARKBLUE);

                DrawText("Choose FPS", 120, 300, 70, BROWN);

                DrawRectangle(250, 450, 100, 100, SKYBLUE);
                DrawRectangle(700, 450, 100, 100, SKYBLUE);
                DrawRectangle(1160, 450, 100, 100, SKYBLUE);
                DrawRectangle(1600, 450, 100, 100, SKYBLUE);

                DrawText("60", 265, 570, 60, BLUE);
                DrawText("[6]", 265, 650, 60, DARKGREEN);
                DrawText("120", 708, 570, 60, BLUE);
                DrawText("[12]", 708, 650, 60, DARKGREEN);
                DrawText("180", 1168, 570, 60, BLUE);
                DrawText("[18]", 1168, 650, 60, DARKGREEN);
                DrawText("240", 1600, 570, 60, BLUE);
                DrawText("[24]", 1600, 650, 60, DARKGREEN);

                DrawText("Dark Mode [D]", 120, 850, 70, BROWN);
                DrawRectangle(700, 830, 100, 100, BLUE);
            }
            else
            {
                DrawFPS(30, 60);

                DrawText("OPTIONS", 720, 120, 110, DARKBLUE);

                DrawText("Choose FPS", 120, 300, 70, DARKBROWN);

                DrawRectangle(250, 450, 100, 100, SKYBLUE);
                DrawRectangle(700, 450, 100, 100, SKYBLUE);
                DrawRectangle(1160, 450, 100, 100, SKYBLUE);
                DrawRectangle(1600, 450, 100, 100, SKYBLUE);

                DrawText("60", 265, 570, 60, DARKBLUE);
                DrawText("[6]", 265, 650, 60, DARKGREEN);
                DrawText("120", 708, 570, 60, DARKBLUE);
                DrawText("[12]", 708, 650, 60, DARKGREEN);
                DrawText("180", 1168, 570, 60, DARKBLUE);
                DrawText("[18]", 1168, 650, 60, DARKGREEN);
                DrawText("240", 1600, 570, 60, DARKBLUE);
                DrawText("[24]", 1600, 650, 60, DARKGREEN);

                DrawText("Dark Mode [D]", 120, 850, 70, DARKBROWN);
                DrawRectangle(700, 830, 100, 100, BLUE);
            }

            if (GetFPS() > 58 && GetFPS() < 62)
            {
                DrawRectangle(250, 450, 100, 100, DARKGREEN);
            }
            if (GetFPS() > 120 && GetFPS() < 130)
            {
                DrawRectangle(700, 450, 100, 100, DARKGREEN);
            }
            if (GetFPS() > 160 && GetFPS() < 185)
            {
                DrawRectangle(1160, 450, 100, 100, DARKGREEN);
            }
            if (GetFPS() > 240 && GetFPS() < 290)
            {
                DrawRectangle(1600, 450, 100, 100, DARKGREEN);
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
            // dark mode 

            if (darkMode)
            {
                ClearBackground(BLACK);
                DrawText("Exit after 2 seconds", 500, 500, 90, WHITE);
            }
            else
            {
                DrawText("Exit after 2 seconds", 500, 500, 90, DARKBLUE);
            }

            // exit 


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