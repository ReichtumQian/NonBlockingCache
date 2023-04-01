/**
 * @file Memory.cpp
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "Memory.h"

int Memory::read(int address) const{
  return data_.at(address);
}

void Memory::write(int address, int value){
  data_.at(address) = value;
}


