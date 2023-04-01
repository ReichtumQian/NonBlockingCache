/**
 * @file Instruction.h
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */

#pragma once

#include <vector>
#include <string>

enum class InstructionType{
  Load,
  Store,
  Jump,
  Beq,
  Bne,
  Add,
  Sub
};

struct Instruction{
  int address;  // address of the instruction, step is 1
  InstructionType type;
  int rs1 = 0;
  int rs2 = 0;
  int rd = 0;
  int mem_addr = 0;

  Instruction(std::string inst){

  }

};

