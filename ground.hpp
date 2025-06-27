#pragma once
#include <raylib.h>

class Ground {
 public:
  Ground();
  void Draw();
  void Update();
  Rectangle getRec();
  float width;
  float height;
  Vector2 position;
};
