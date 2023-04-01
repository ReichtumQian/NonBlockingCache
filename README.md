
本程序意在用软件简单模拟 Non-Blocking Cache 的工作原理，并与一般 Cache 的效率进行比较。

## 指令格式

本程序输入的指令存放于 `instruction` 文件中，每行为一条指令，支持以下几种类型：

- Load 指令，格式为 `ld n imm`，其中 `n` 为寄存器编号，`imm` 为内存地址。
- Store 指令，格式为 `sd n imm`，其中 `n` 为寄存器编号，`imm` 为内存地址。
- Jump 指令
- Beq 指令
- Bne 指令
- Add 指令
- Sub 指令
- Addi 指令
- Subi 指令

