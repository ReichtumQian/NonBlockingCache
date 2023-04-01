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

class Cache{
private:
  std::map<int, int> data_;  // addr -> value

public:

  int load(int addr, LoadStatus* status);

  void store(int addr, int value);


};
