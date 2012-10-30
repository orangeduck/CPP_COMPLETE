#ifndef PP_BRAINFUCK_H
#define PP_BRAINFUCK_H

/*
  PP_BRAINFUCK - brainfuck in c preprocessor
  
  
*/

#define PP_BF_INSTR(C) PP_JOIN(PP_BF_SYM_, C)

#define PP_BF_INSTR_R 1
#define PP_BF_INSTR_L 2
#define PP_BF_INSTR_P 3
#define PP_BF_INSTR_M 4
#define PP_BF_INSTR_O 5
#define PP_BF_INSTR_F 6
#define PP_BF_INSTR_B 7
#define PP_BF_INSTR_$ 8

#define PP_BF_INSTR_1 R
#define PP_BF_INSTR_2 L
#define PP_BF_INSTR_3 P
#define PP_BF_INSTR_4 M
#define PP_BF_INSTR_5 O
#define PP_BF_INSTR_6 F
#define PP_BF_INSTR_7 B
#define PP_BF_INSTR_8 $




#endif