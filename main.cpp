/**
 * @file main.cpp
 * @author YiXiao Qian 
 * 
 * @copyright Copyright (c) 2023 YiXiao Qian
 * 
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include "Instruction.h"
#include "src/CPU.h"

static constexpr int LINE_SIZE = 100;

Instruction constructInstruction(std::string inst){
  Instruction result;
  std::stringstream lineStream(inst);
  std::string word;
  lineStream >> word;
  if(word == "ld"){
    result.type = InstructionType::Load;
    lineStream >> word;
    result.rd = std::stoi(word);
    lineStream >> word;
    result.imm = std::stoi(word);
  }
  else if(word == "sd"){
    result.type = InstructionType::Store;
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.imm = std::stoi(word);
  }
  else if(word == "beq"){
    result.type = InstructionType::Beq;
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.rs2 = std::stoi(word);
  }
  else if(word == "bne"){
    result.type = InstructionType::Bne;
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.rs2 = std::stoi(word);
  }
  else if(word == "add"){
    result.type = InstructionType::Add;
    lineStream >> word;
    result.rd = std::stoi(word);
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.rs2 = std::stoi(word);
  }
  else if(word == "sub"){
    result.type = InstructionType::Sub;
    lineStream >> word;
    result.rd = std::stoi(word);
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.rs2 = std::stoi(word);
  }
  else if(word == "addi"){
    result.type = InstructionType::Addi;
    lineStream >> word;
    result.rd = std::stoi(word);
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.imm = std::stoi(word);
  }
  else if(word == "subi"){
    result.type = InstructionType::Subi;
    lineStream >> word;
    result.rd = std::stoi(word);
    lineStream >> word;
    result.rs1 = std::stoi(word);
    lineStream >> word;
    result.imm = std::stoi(word);
  }
  else if(word == "j"){
    result.type = InstructionType::Jump;
    lineStream >> word;
    result.imm = std::stoi(word);
  }
  else{
    std::cerr << "Invalid instruction" << std::endl;
  }
  return result;
}



int main(){
  // init instruction
  std::ifstream file("instruction");
  std::string line;
  while(std::getline(file, line)){
  }
  return 0;
}



