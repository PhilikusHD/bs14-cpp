#include "include/raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

struct Dino
{
    Rectangle rect;
    Vector2 velocity;
    bool  isJumping;
};

struct Obstacle
{
    Rectangle rect;
    float speed;
};

void InitDino(Dino& dino)
{
    dino.rect = {100, screenWidth - 50 - 40, 40, 40};
    dino.velocity = {0, 0};
    dino.isJumping = false;
}

void InitObstacle(Obstacle& obstacle, float speed) 
{
    obstacle.rect = {screenWidth, screenHeight - 50 - 40, 40, 40};
    obstacle.speed = speed;
}

bool CheckCollision(const Dino& dino, const Obstacle& obstacle)
{
    return CheckCollisionRecs(dino.rect, obstacle.rect);
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Dino Game");

    Dino dino;
    Obstacle obstacle;

    InitDino(dino);
    InitObstacle(obstacle, 200);


    bool gameOver = false;
    int score = 0;
    const float gravity = 1000.0f;
    const float jumpVelocity = -450.0f;

    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if(!gameOver)
        {
            if(IsKeyPressed(KEY_SPACE) && !dino.isJumping)
            {
                dino.isJumping = true;
                dino.velocity.y = jumpVelocity;
            }

            dino.velocity.y += gravity * deltaTime;
            dino.rect.y += dino.velocity.y * deltaTime;

            // Prevent falling through the floor
            if(dino.rect.y > screenHeight - 50 - dino.rect.height)
            {
                dino.rect.y = screenHeight - 50 - dino.rect.height;
                dino.isJumping = false;
                dino.velocity.y = 0;
            }
            obstacle.rect.x -= obstacle.speed * deltaTime;

            if(obstacle.rect.x < -obstacle.rect.width)
            {
                obstacle.rect.x = screenWidth;
                score++;
            }

            if(CheckCollision(dino, obstacle))
            {
                gameOver = true;
            }

        }
        else 
        {
            // Restart game
            if (IsKeyPressed(KEY_R)) 
            {
                gameOver = false;
                score = 0;
                InitDino(dino);
                InitObstacle(obstacle, 200);
            }
        }

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Ground
        DrawRectangle(0, screenHeight - 50, screenWidth, 50, DARKGRAY);

        // Dino
        DrawRectangleRec(dino.rect, GREEN);

        // Obstacle
        DrawRectangleRec(obstacle.rect, RED);

        // Score and instructions
        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

        if (gameOver) 
        {
            DrawText("GAME OVER! Press R to Restart", screenWidth / 2 - 160, screenHeight / 2 - 20, 20, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
