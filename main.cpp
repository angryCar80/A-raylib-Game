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

    bool isColliding = CheckCollisionRecs(player.GetRec(), ground.getRec());

    if (isColliding){
      player.velocity *= -0.5f;
      player.position.y = ground.position.y - player.height;
    }

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(0, 0);
    // Drawing the player
    player.Draw();
    player.Update(dt);
    ground.Draw();
    EndDrawing();
  }
}
