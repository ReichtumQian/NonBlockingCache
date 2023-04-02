/**
 * @file NBCache.h
 * @author YiXiao Qian
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include "Cache.h"

class NBCache : public Cache{
private:
  using Base = Cache;

public:
  void load(int addr, int* target, LoadStatus* status, int status_id, bool denpendency = false) override;

  using Base::store;
};
