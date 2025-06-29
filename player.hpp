#pragma once
#include <raylib.h>
#include <raymath.h>
#include <iostream>

class Player {
 public:
  //Setting Functions
  Player();
  void Draw();
  void Update(float dt);
  void SetY(float y) { position.y = y; }
  void Move(float dt);
  Rectangle GetRec();
  // Setting Values
  Vector2 position;
  float width;
  float height;
  float speed;

 private:
  // Setting Movement Values
  int dir;
  float accel;
  float decel;
  float maxspeed;
};
