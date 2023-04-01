/**
 * @file Cache.h
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include <map>
#include "LoadStatus.h"
#include "Memory.h"

class Cache{
protected:
  std::map<int, int> data_;  // addr -> value
  Memory* memory_;

public:

  virtual void load(int addr, int* target, LoadStatus* status, bool denpendency = false);

  void store(int addr, int value);


};
