#include "player.hpp"
#include <raylib.h>


Player::Player() {
  // Setting the values
  position.x = 100;
  position.y = 100;
  width = 50;
  height = 50;
  speed = 5;
  accel = 50.0f;
  decel = 20.0f;
  maxspeed = 300.0f;
}

void Player::Draw() {
  DrawRectangle(position.x, position.y, width, height, BLUE);
}

void Player::Update(float dt) {
  if (IsKeyDown(KEY_LEFT)) position.x -= speed;
  if (IsKeyDown(KEY_RIGHT)) position.x += speed;
  if (IsKeyDown(KEY_UP)) position.y -= speed;
  if (IsKeyDown(KEY_DOWN)) position.y += speed;
}

Rectangle Player::GetRec() {
  return Rectangle{position.x, position.y, width, height};
}
