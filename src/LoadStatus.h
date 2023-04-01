/**
 * @file LoadStatus.h
 * @author YiXiao Qian
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include "Config.h"


class LoadStatus{

public:
  enum class Status{
    Completed,
    Waiting
  };

private:
  Status status_;
  int time_ = 0;

public:

  LoadStatus(): status_(Status::Completed), time_(0) {}

  void changeStatus(int step = 1){
    time_ += step;
    if(time_ >= READ_MEMORY_TIME){
      status_ = Status::Completed;
    }
  }

  bool checkStatus() const{
    return status_ == Status::Completed;
  }


};


