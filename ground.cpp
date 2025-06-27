#include "ground.hpp"
#include <raylib.h>

Ground::Ground(){
  width = 800;
  height = 800;
  position.x = 0;
  position.y = 600;
}

void Ground::Draw(){
  DrawRectangle(position.x, position.y, width, height, WHITE);
}

Rectangle Ground::getRec(){
  return Rectangle {position.x, position.y, width, height};
}
