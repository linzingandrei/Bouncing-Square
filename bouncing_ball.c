#include "../include/raylib.h"

Color GetRandomColor()
{
    return (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
}

int main(void)
{
    InitWindow(1250, 850, "Raylib Window");

    Vector2 ballPosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    Vector2 ballSpeed = { 5.0f, 4.0f };
    int ballRadius = 100;

    Color squareColor = BLUE;
    bool pause = 0;
    int framesCounter = 0;

    bool hitHorizontal = false;
    bool hitVertical = false;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE)) pause = !pause;
	hitHorizontal = false;
	hitVertical = false;

        if (!pause)
        {
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;


	    if (ballPosition.x <= 0 || ballPosition.x + ballRadius >= GetScreenWidth()) {
	    	ballSpeed.x *= -1;
		hitHorizontal = true;
	    }

            if (ballPosition.y <= 0 || ballPosition.y + ballRadius >= GetScreenHeight()) {
            	ballSpeed.y *= -1;
	    	hitVertical = true;
	    }
	}
        else framesCounter++;
	if (hitHorizontal || hitVertical)
        {
            squareColor = GetRandomColor();
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

	    DrawRectangleV(ballPosition, (Vector2){ ballRadius, ballRadius }, squareColor);
            DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

            if (pause && ((framesCounter/30)%2)) DrawText("PAUSED", 550, 350, 30, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
