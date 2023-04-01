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
#include "Config.h"
#include "Instruction.h"
#include "NBCache.h"
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
  std::vector<Instruction> instructions;
  std::string line;
  while(std::getline(file, line)){
    instructions.push_back(constructInstruction(line));
  }
  // test normal cache
  STALL_TIME = 0;
  EXECUTE_TIME = 0;
  CPU<Cache> cpu1;
  cpu1.run(instructions);
  std::cout << "Total stall time: " << STALL_TIME << std::endl;
  std::cout << "Total execute time: " << EXECUTE_TIME << std::endl;
  // test non-blocking cache
  STALL_TIME = 0;
  EXECUTE_TIME = 0;
  CPU<NBCache> cpu2;
  cpu2.run(instructions);
  std::cout << "Total stall time: " << STALL_TIME << std::endl;
  std::cout << "Total execute time: " << EXECUTE_TIME << std::endl;

  return 0;
}



