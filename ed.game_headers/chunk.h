#pragma once

#include <boost\multi_array.hpp>

struct chunk
{
  typedef boost::multi_array<short, 3> container;

  container blocks;
};