#include "player.hpp"

#include <raylib.h>

#include <algorithm>

Player::Player() {
  // Setting the values
  position.x = 100;
  position.y = 100;
  width = 50;
  height = 50;
  speed = 5;
  gravity = 980;
  velocity = 0;
  jumpforce = 450.0f;
  accel = 50.0f;
  decel = 20.0f;
  maxspeed = 300.0f;
}

void Player::Draw() {
  DrawRectangle(position.x, position.y, width, height, BLUE);
}

void Player::Update(float dt) {
  velocity += gravity * dt;
  position.y += velocity * dt;
}

void Player::Move(float dt) {
  if (IsKeyDown(KEY_SPACE)) {
    velocity = -jumpforce;
  }
  if(IsKeyDown(KEY_RIGHT)) position.x += 2; 
  if (IsKeyDown(KEY_LEFT)) position.x += 2;
}
Rectangle Player::GetRec() {
  return Rectangle{position.x, position.y, width, height};
}
