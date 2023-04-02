/**
 * @file NBCache.cpp
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "NBCache.h"


void NBCache::load(int addr, int* target, LoadStatus* status, int status_id, bool dependency){
  // cache hit
  if(data_.find(addr) != data_.end()){
    *target = data_[addr];
    status->setStatus(LoadStatus::Status::Completed);
    return ;
  }
  // cache miss
  status[status_id].setStatus(LoadStatus::Status::Waiting);
  // if there is data dependency, stall
  if(dependency){
    while(status[status_id].getTime() <= READ_MEMORY_TIME){
      for(int i = 1; i < NUM_REGISTER; ++i){
        status[i].changeStatus();
      }
      ++STALL_TIME;
      ++EXECUTE_TIME;
    }
    *target = memory_->read(addr);
    status[status_id].setStatus(LoadStatus::Status::Completed);
  }
  // if there is no data dependency, not stall
  else{
    status[status_id].setStatus(LoadStatus::Status::Waiting);
  }
}



