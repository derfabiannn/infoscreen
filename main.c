#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "raylib.h"

#define MAX_IMAGES 100

int main(void)
{
    InitWindow(0, 0, "Infoscreen");
    ToggleFullscreen();
    SetTargetFPS(60);

    Texture2D images[MAX_IMAGES];
    int imageCount = 0;

    DIR *d = opendir("images");
    if (d)
    {
        struct dirent *dir;
        while ((dir = readdir(d)) != NULL && imageCount < MAX_IMAGES)
        {
            if (strstr(dir->d_name, ".png") || strstr(dir->d_name, ".jpg"))
            {
                char path[256];
                snprintf(path, sizeof(path), "images/%s", dir->d_name);
                images[imageCount] = LoadTexture(path);
                imageCount++;
            }
        }
        closedir(d);
    }

    int currentIndex = 0;
    float timer = 0.0f;
    float displayDuration = 10.0f;

    while (!WindowShouldClose())
    {
        timer += GetFrameTime();
        if (timer >= displayDuration)
        {
            timer = 0.0f;
            currentIndex = (currentIndex + 1) % imageCount;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (imageCount > 0)
        {
            DrawTexturePro(images[currentIndex],
                           (Rectangle){0, 0, images[currentIndex].width, images[currentIndex].height},
                           (Rectangle){0, 0, GetScreenWidth(), GetScreenHeight()},
                           (Vector2){0, 0}, 0.0f, WHITE);
        }
        else
        {
            DrawText("Keine Bilder gefunden!", 50, 50, 20, RED);
        }

        EndDrawing();
    }

    for (int i = 0; i < imageCount; i++)
    {
        UnloadTexture(images[i]);
    }
    CloseWindow();

    return EXIT_SUCCESS;
}
