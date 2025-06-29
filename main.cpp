#include "ground.hpp"
#include "player.hpp"


Player player;
Ground ground;
int main() {
  const int width = 800;
  const int height = 800;
  InitWindow(width, height, "I don't Know what to name it");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    if (CheckCollisionRecs(player.GetRec(), ground.getRec())) {
      player.position.y = (ground.position.y-35) - player.height;
    }
    player.Update(dt);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    // Drawing the player
    player.Draw();

    ground.Draw();
    EndDrawing();
  }
}
