#include "chunk.h"

chunk::block &chunk::AccessBlock(int y)
{
  const int items_per_block = 16;
  auto y_index = y / items_per_block; // 256 max height / 16
  if (y_index < 0 || y_index > items_per_block - 1)
    throw "pilar out of bounds";

  auto it = data.find(y_index);
  if (it == data.end())
  {
    data.insert({y_index, block(boost::extents[items_per_block][items_per_block][items_per_block])});
    it = data.find(y_index);
  }
  return it->second;
}