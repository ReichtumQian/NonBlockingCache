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
  int time = 0;

public:

  void changeStatus(int step = 1){
    time += step;
  }

  bool checkStatus() const{
    return time >= READ_MEMORY_TIME;
  }


};


