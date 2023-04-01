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
  Sub,
  Addi,
  Subi
};

struct Instruction{
  InstructionType type = InstructionType::Load;
  int rs1 = 0;
  int rs2 = 0;
  int rd = 0;
  int imm = 0;

  Instruction() = default;


};

