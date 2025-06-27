#pragma once
#include <raylib.h>

class Player {
 public:
  Player();
  void Draw();
  void Update(float dt);
  void SetY(float y) { position.y = y; } 
  Rectangle GetRec();
  float jumpforce;
  float velocity;
  Vector2 position;
  float width;
  float height;
  float gravity;
  float speed;
  bool onGround;
};
