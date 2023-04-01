/**
 * @file CPU.h
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include <vector>
#include <array>
#include "Instruction.h"
#include "Cache.h"
#include "NBCache.h"


template<class _CacheType>
class CPU{

private:
  int pc_ = 0; // step = 1
  std::array<int,32> registers_; // 32 registers
  const _CacheType cache_;

public:




public:

  void run(std::vector<Instruction> instructions);


};


