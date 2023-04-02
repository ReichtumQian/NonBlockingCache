/**
 * @file NBCache.cpp
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "NBCache.h"


void NBCache::load(int addr, int* target, LoadStatus* status, bool dependency){
  // cache hit
  if(data_.find(addr) != data_.end()){
    *target = data_[addr];
    status->setStatus(LoadStatus::Status::Completed);
    return ;
  }
  // cache miss
  // if there is data dependency, stall
  if(dependency){
    while(status->getTime() <= READ_MEMORY_TIME){
      status->addTime();
      ++STALL_TIME;
      ++EXECUTE_TIME;
    }
    *target = memory_->read(addr);
    status->setStatus(LoadStatus::Status::Completed);
  }
  // if there is no data dependency, not stall
  else{
    status->setStatus(LoadStatus::Status::Waiting);
  }
}



