
本程序意在用软件简单模拟 Non-Blocking Cache 的工作原理，并与一般 Cache 的效率进行比较。

## 编译运行程序

要运行本程序需要安装 `g++, cmake` 工具，安装后在项目根目录下执行以下命令：

```bash
bash configure.sh
bash compile.sh
./bin/main
```

## 指令格式

本程序输入的指令存放于 `instruction` 文件中，每行为一条指令，支持以下几种类型：

- Add 指令，格式为 `add a b c`，其中 `a,b,c` 为寄存器编号。
- Sub 指令，格式为 `sub a b c`，其中 `a,b,c` 为寄存器编号。
- Addi 指令，格式为 `addi a b imm`，其中 `a,b` 为寄存器编号，`imm` 为立即数。
- Subi 指令，格式为 `subi a b imm`，其中 `a,b` 为寄存器编号，`imm` 为立即数。
- Load 指令，格式为 `ld n imm`，其中 `n` 为寄存器编号，`imm` 为内存地址。
- Store 指令，格式为 `sd n imm`，其中 `n` 为寄存器编号，`imm` 为内存地址。
- Jump 指令，格式为 `j imm`，其中 `imm` 为跳转地址。
- Beq 指令，格式为 `beq n m imm`，其中 `n,m` 为寄存器编号，`imm` 为跳转地址。
- Bne 指令，格式为 `bne n m imm`，其中 `n,m` 为寄存器编号，`imm` 为跳转地址。

