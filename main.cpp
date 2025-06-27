#include <raylib.h>
#include <cmath>
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

    if (isColliding) {
      player.velocity = 0;
      player.position.y = ground.position.y - player.height;
      Rectangle groundi = ground.getRec();
      //player.SetY(groundi.y - player.height / 2);
      if (fabs(player.velocity) < 5.0f) {
        player.velocity = 0;
        player.onGround = true;
      } else {
        player.onGround = false;
      }
    } else {
      player.onGround = false;
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

// g++ main.cpp player.cpp ground.cpp -o game -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
