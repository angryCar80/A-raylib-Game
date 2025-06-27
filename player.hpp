#pragma once
#include <raylib.h>

class Player {
 public:
  Player();
  void Draw();
  void Update(float dt);

 private:
  float width;
  float height;
  float velocity;
  float gravity;
  float speed;
  Vector2 position;
};
