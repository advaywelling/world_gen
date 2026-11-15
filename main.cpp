#include "raylib.h"
#include <cstdlib>

int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;
    int currFpsTarget = 60;

    InitWindow(screenWidth, screenHeight, "Window");
    SetTargetFPS(currFpsTarget);

    Vector2 deltaCircle { 0, (float)screenHeight / 3.0f };
    Vector2 frameCircle { 0, (float)screenHeight * (2.0f / 3.0f)};

    const float speed = 10.0f;
    const float circleRadius = 32.0f;

    while (!WindowShouldClose()) {
        
        float mouseWheel = GetMouseWheelMove();
        if (currFpsTarget >= 0) {
            currFpsTarget += (int)mouseWheel;
        } else {
            currFpsTarget = 0;
        }
        SetTargetFPS(currFpsTarget);

        deltaCircle.x += GetFrameTime() * 5.0f * speed;
        frameCircle.x += 0.5f * speed;

        if (deltaCircle.x > screenWidth) deltaCircle.x = 0;
        if (frameCircle.x > screenWidth) frameCircle.x = 0;

        if (IsKeyPressed(KEY_R)) {
            deltaCircle.x = 0;
            frameCircle.x = 0;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleV(deltaCircle, circleRadius, RED);
            DrawCircleV(frameCircle, circleRadius, BLUE);

            const char* fpsText = TextFormat("FPS: %i (Target: %i)", GetFPS(), currFpsTarget);
            DrawText(fpsText, 10, 10, 20, DARKGRAY);
            DrawText(TextFormat("Frame time: %02.02f ms", GetFrameTime()*1000.0f), 10, 30, 20, DARKGRAY);
            DrawText("Use the scroll wheel to change the fps limit, r to reset", 10, 50, 20, DARKGRAY);

            DrawText("FUNC: x += GetFrameTime()*speed", 10, 90, 20, RED);
            DrawText("FUNC: x += speed", 10, 240, 20, BLUE);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}