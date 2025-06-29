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
  if (IsKeyDown(KEY_SPACE) && onGround) {
    velocity = -jumpforce;
  }
  if (IsKeyDown(KEY_D)) dir += 1;
  if (IsKeyDown(KEY_A)) dir -= 1;

  if (dir != 0) {
    position.x += dir * accel * dt;
    position.x = std::clamp(position.x, -maxspeed, maxspeed);
  } else {
    if (position.x > 0) {
      position.x = std::max(0.0f, position.x - decel * dt);
    } else if (position.x < 0) {
      position.x = std::min(0.0f, position.x + decel * dt);
    }
  }
  position.x = dir * speed;
}

Rectangle Player::GetRec() {
  return Rectangle{position.x, position.y, width, height};
}
