#pragma once

#include <unordered_map>
#include <boost\multi_array.hpp>

struct chunk
{
  int x, z;

  typedef boost::multi_array<short, 3> block;
  typedef std::unordered_map<int, block> pilar;

  pilar data;

  block &AccessBlock(int y);
};