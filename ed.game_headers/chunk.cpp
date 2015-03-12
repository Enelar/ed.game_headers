#include "chunk.h"

chunk::block &chunk::AccessBlock(int y)
{
  auto y_index = y / 16; // 256 max height / 16
  if (y_index < 0 || y_index > 15)
    throw "pilar out of bounds";

  auto it = data.find(y_index);
  if (it == data.end())
  {
    data.insert({y_index, block()});
    it = data.find(y_index);
  }
  return it->second;
}