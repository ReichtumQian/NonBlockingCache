/**
 * @file NBCache.cpp
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "NBCache.h"


void NBCache::load(int addr, int* target, LoadStatus* status, bool denpendency){
  if(data_.find(addr) != data_.end()){
    *target = data_[addr];
    status->setStatus(LoadStatus::Status::Completed);
    return ;
  }
  if(denpendency){
    while(status->getTime() < READ_MEMORY_TIME){
      status->addTime();
      ++STALL_TIME;
      ++EXECUTE_TIME;
    }
    *target = memory_->read(addr);
    status->setStatus(LoadStatus::Status::Completed);
  }
  else{
    status->setStatus(LoadStatus::Status::Waiting);
  }
}



