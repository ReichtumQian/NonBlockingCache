/**
 * @file Memory.h
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include <vector>
#include <array>
#include "Config.h"


class Memory{

private:
  std::array<int, MEMORY_SIZE> data_;

public:
  Memory() = default;

  int read(int address) const;

  void write(int address, int value);


};


