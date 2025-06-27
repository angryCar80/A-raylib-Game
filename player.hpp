#pragma once
#include <raylib.h>

class Player {
 public:
  Player();
  void Draw();
  void Update(float dt);
  Rectangle GetRec();
  float velocity;
  Vector2 position;
  float width;
  float height;
  float gravity;
  float speed;
};
