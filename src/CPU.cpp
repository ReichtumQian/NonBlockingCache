/**
 * @file CPU.cpp
 * @author YiXiao Qian
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "CPU.h"
#include "NBCache.h"

template<class _CacheType>
void CPU<_CacheType>::run(const std::vector<Instruction>& instructions){
  pc_ = 0;
  for(;pc_ < instructions.size(); ++pc_){
    const auto& inst = instructions.at(pc_);
    InstructionType type = inst.type;
    int rs1 = inst.rs1;
    int rs2 = inst.rs2;
    int rd = inst.rd;
    int imm = inst.imm;
    for(size_t i = 0; i < 32; i++){
      status_.at(i).changeStatus();
    }

    switch(type){
      case InstructionType::Addi:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: addi x" << rd << ", x" << rs1 << ", " << imm << std::endl;
        registers_[rd] = readReg(rs1) + imm;
        break;
      case InstructionType::Subi:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: subi x" << rd << ", x" << rs1 << ", " << imm << std::endl;
        registers_[rd] = readReg(rs1) - imm;
        break;
      case InstructionType::Add:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: add x" << rd << ", x" << rs1 << ", x" << rs2 << std::endl;
        registers_[rd] = readReg(rs1) + readReg(rs2);
        break;
      case InstructionType::Sub:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: sub x" << rd << ", x" << rs1 << ", x" << rs2 << std::endl;
        registers_[rd] = readReg(rs1) - readReg(rs2);
        break;
      case InstructionType::Jump:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: j " << imm << std::endl;
        pc_ = imm - 1;
        break;
      case InstructionType::Beq:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: beq x" << rs1 << ", x" << rs2 << ", " << imm << std::endl;
        if(readReg(rs1) == readReg(rs2)){
          pc_ = imm - 1;
        }
        break;
      case InstructionType::Bne:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: bne x" << rs1 << ", x" << rs2 << ", " << imm << std::endl;
        if(readReg(rs1) != readReg(rs2)){
          pc_ = imm - 1;
        }
        break;
      case InstructionType::Load:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: ld x" << rd << ", " << imm << std::endl;
        cache_.load(imm, &registers_.at(rd), &status_.at(rd));
        break;
      case InstructionType::Store:
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        std::cout << "Instruction: sd x" << rd << ", " << imm << std::endl;
        cache_.store(imm, registers_.at(rd));
        break;
    }
    ++EXECUTE_TIME;
  }
}

template<>
int CPU<Cache>::readReg(int reg_id){
  return registers_.at(reg_id);
}

template<>
int CPU<NBCache>::readReg(int reg_id){
  if(reg_id == 0) return 0;
  cache_.load(reg_id, &registers_.at(reg_id), &status_.at(reg_id), true);
  return registers_.at(reg_id);
}

template class CPU<Cache>;
template class CPU<NBCache>;