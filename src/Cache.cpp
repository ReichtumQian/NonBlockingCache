/**
 * @file Cache.cpp
 * @author YiXiao Qian
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "Cache.h"
#include "Config.h"
#include "LoadStatus.h"

void Cache::load(int addr, int* target, LoadStatus* status, bool denpendency){
  if(data_.find(addr) != data_.end()){
    *target = data_[addr];
    status->setStatus(LoadStatus::Status::Completed);
    return ;
  }
  while(status->getTime() < READ_MEMORY_TIME){
    status->addTime();
    ++STALL_TIME;
    ++EXECUTE_TIME;
  }
  *target = memory_->read(addr);
  status->setStatus(LoadStatus::Status::Completed);
}

void Cache::store(int addr, int value){
  memory_->write(addr, value);
  if(data_.find(addr) != data_.end()){
    data_[addr] = value;
  }
}


