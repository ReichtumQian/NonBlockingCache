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

void Cache::load(int addr, int* target, LoadStatus* status, int status_id, bool denpendency){
  if(data_.find(addr) != data_.end()){
    *target = data_[addr];
    status->setStatus(LoadStatus::Status::Completed);
    return ;
  }
  status[status_id].setStatus(LoadStatus::Status::Waiting);
  while(status[status_id].getTime() < READ_MEMORY_TIME){
    for(int i = 1; i < NUM_REGISTER; ++i){
      status[i].changeStatus();
    }
    ++STALL_TIME;
    ++EXECUTE_TIME;
  }
  *target = memory_->read(addr);
  status[status_id].setStatus(LoadStatus::Status::Completed);
}

void Cache::store(int addr, int value){
  memory_->write(addr, value);
  if(data_.find(addr) != data_.end()){
    data_[addr] = value;
  }
}


