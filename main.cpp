#include <raylib.h>

#include "ground.hpp"
#include "player.hpp"

int main() {
  const int width = 800;
  const int height = 800;
  InitWindow(width, height, "I don't Know what to name it");
  SetTargetFPS(60);

  Player player;
  Ground ground;
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    if (CheckCollisionRecs(player.GetRec(), ground.getRec())) {
      player.position.y = ground.position.y - player.height;

      player.velocity = 0;
      player.onGround = true;
    } else {
      player.onGround = false;
    }

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    DrawText(TextFormat("onGround %d   velY %.1f   SPACE %d",
                    player.onGround,
                    player.position.y,
                    IsKeyPressed(KEY_SPACE)),
         10, 30, 20, YELLOW);
    // Drawing the player
    player.Draw();
    player.Update(dt);
    ground.Draw();
    EndDrawing();
  }
}
