/**
 * @file CPU.h
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include <array>
#include <iostream>
#include <vector>
#include "Cache.h"
#include "Config.h"
#include "Instruction.h"
#include "NBCache.h"
#include "LoadStatus.h"


template<class _CacheType>
class CPU{

private:
  int pc_ = 0; // step = 1
  std::array<int,32> registers_; // 32 registers
  std::array<LoadStatus,32> status_;
  _CacheType cache_;

public:

  CPU(): registers_(), status_(), cache_() {
    for(size_t i = 0; i < 32; i++){
      registers_[i] = 0;
    }
  }


public:

  void run(std::vector<Instruction> instructions);

  int readReg(int reg_id){
    if(status_.at(reg_id).checkStatus()){
      return registers_.at(reg_id);
    }
    for(auto& statu : status_){
      statu.changeStatus(1);
      ++EXECUTE_TIME;
    }
    return readReg(reg_id);
  }

};

