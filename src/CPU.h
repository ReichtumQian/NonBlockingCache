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


template<class _CacheType>
void CPU<_CacheType>::run(std::vector<Instruction> instructions){
  pc_ = 0;
  for(;pc_ < instructions.size(); ++pc_){
    const auto& inst = instructions.at(pc_);
    InstructionType type = inst.type;
    int rs1 = inst.rs1;
    int rs2 = inst.rs2;
    int rd = inst.rd;
    int imm = inst.imm;

    switch(type){
      case InstructionType::Add:
        std::cout << "Instruction: Add " << rd << " " << rs1 << " " << rs2 << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        registers_[rd] = registers_[rs1] + registers_[rs2];
        break;
      case InstructionType::Sub:
        std::cout << "Instruction: Sub " << rd << " " << rs1 << " " << rs2 << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        registers_[rd] = registers_[rs1] - registers_[rs2];
        break;
      case InstructionType::Jump:
        std::cout << "Instruction: Jump " << imm << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        pc_ = imm;
        break;
      case InstructionType::Beq:
        std::cout << "Instruction: Beq " << rs1 << " " << rs2 << " " << imm << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        if(registers_[rs1] == registers_[rs2]){
          pc_ = imm;
        }
        break;
      case InstructionType::Bne:
        std::cout << "Instruction: Bne " << rs1 << " " << rs2 << " " << imm << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        if(registers_[rs1] != registers_[rs2]){
          pc_ = imm;
        }
        break;
      case InstructionType::Load:
        std::cout << "Instruction: Load " << rd << " " << imm << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        cache_.load(imm, &registers_.at(rd), &status_.at(rd), false);
        break;
      case InstructionType::Store:
        std::cout << "Instruction: Store " << rd << " " << imm << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        cache_.store(imm, registers_.at(rd));
        break;
    }
  }
}



template class CPU<Cache>;
template class CPU<NBCache>;


