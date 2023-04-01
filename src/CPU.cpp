/**
 * @file CPU.cpp
 * @author YiXiao Qian
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#include "CPU.h"

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
        registers_[rd] = readReg(rs1) + readReg(rs2);
        break;
      case InstructionType::Sub:
        std::cout << "Instruction: Sub " << rd << " " << rs1 << " " << rs2 << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        registers_[rd] = readReg(rs1) - readReg(rs2);
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
        if(readReg(rs1) == readReg(rs2)){
          pc_ = imm;
        }
        break;
      case InstructionType::Bne:
        std::cout << "Instruction: Bne " << rs1 << " " << rs2 << " " << imm << std::endl;
        std::cout << "TIME: " << EXECUTE_TIME << std::endl;
        ++EXECUTE_TIME;
        if(readReg(rs1) != readReg(rs2)){
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