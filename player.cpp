#include "player.hpp"

#include <raylib.h>

Player::Player() {
  // Setting the values
  position.x = 100;
  position.y = 100;
  width = 50;
  height = 50;
  speed = 100;
  gravity = 980;
  velocity = 0;
  jumpforce = 450.0f;
}

void Player::Draw() {
  DrawRectangle(position.x, position.y, width, height, BLUE);
}

void Player::Update(float dt) {
  velocity += gravity * dt;
  position.y += velocity * dt;
  if (IsKeyDown(KEY_SPACE) && onGround) {
    velocity = -jumpforce;
  }
}

Rectangle Player::GetRec() {
  return Rectangle{position.x, position.y, width, height};
}
