#ifndef PP_BRAINFUCK_H
#define PP_BRAINFUCK_H

#include "PP.h"

/*!
 *  PP_BRAINFUCK
 *  ============
 *
 *  About
 *  -----
 *
 *  Brainfuck in c preprocessor
 *  
 *
 *  Input
 *  -----
 *
 *  To ensure valid preprocessor symbols
 *  instructions are mapped to the following
 *  characters, with input disabled.
 *
 *  + `>` => `R`
 *  + `<` => `L`
 *  + `+` => `U`
 *  + `-` => `D`
 *  + `.` => `O`
 *  + `[` => `F`
 *  + `]` => `B`
 *
 *
 *  Structure
 *  ---------
 *
 *  IP - Brainfuck instr index
 *  DP - Brainfuck data  index
 *  IA - Brainfuck instr array
 *  DA - Brainfuck data  array
 *
 *  X - (IP, DP, IA, DA)
 *
 */

/* Check if blank symbol */
#define PP_IS_BLANK(X) PP_JOIN(PP_IS_BLANK_, X) 
#define PP_IS_BLANK_  1
#define PP_IS_BLANK_R 0
#define PP_IS_BLANK_L 0
#define PP_IS_BLANK_U 0
#define PP_IS_BLANK_D 0
#define PP_IS_BLANK_O 0
#define PP_IS_BLANK_F 0
#define PP_IS_BLANK_B 0

/* Check if output symbol */
#define PP_IS_OUTPUT(X) PP_JOIN(PP_IS_OUTPUT_, X)
#define PP_IS_OUTPUT_  0
#define PP_IS_OUTPUT_R 0
#define PP_IS_OUTPUT_L 0
#define PP_IS_OUTPUT_U 0
#define PP_IS_OUTPUT_D 0
#define PP_IS_OUTPUT_O 1
#define PP_IS_OUTPUT_F 0
#define PP_IS_OUTPUT_B 0

/* Check if forward symbol */
#define PP_IS_FORWARD(X) PP_JOIN(PP_IS_FORWARD_, X)
#define PP_IS_FORWARD_  0
#define PP_IS_FORWARD_R 0
#define PP_IS_FORWARD_L 0
#define PP_IS_FORWARD_U 0
#define PP_IS_FORWARD_D 0
#define PP_IS_FORWARD_O 0
#define PP_IS_FORWARD_F 1
#define PP_IS_FORWARD_B 0

/* Check if backward symbol */
#define PP_IS_BACKWARD(X) PP_JOIN(PP_IS_BACKWARD_, X)
#define PP_IS_BACKWARD_  0
#define PP_IS_BACKWARD_R 0
#define PP_IS_BACKWARD_L 0
#define PP_IS_BACKWARD_U 0
#define PP_IS_BACKWARD_D 0
#define PP_IS_BACKWARD_O 0
#define PP_IS_BACKWARD_F 0
#define PP_IS_BACKWARD_B 1

/* Get individual parts */
#define PP_BF_IP(X) PP_FST(X)
#define PP_BF_DP(X) PP_SND(X)
#define PP_BF_IA(X) PP_TRD(X)
#define PP_BF_DA(X) PP_FTH(X)
#define PP_BF_INSTR($, X) PP_NTH($, PP_BF_IA(X), PP_BF_IP(X)) 
#define PP_BF_DATA($, X)  PP_NTH($, PP_BF_DA(X), PP_BF_DP(X)) 

/* Inc/Dec Data Item */
#define PP_BF_DATA_FST($, X) PP_TAKE($, PP_BF_DA(X), PP_BF_DP(X))
#define PP_BF_DATA_SND($, X) PP_DROP($, PP_BF_DA(X), PP_INC(PP_BF_DP(X)))
#define PP_BF_DATA_INCED($, X) ( PP_INC(PP_NTH($, PP_BF_DA(X), PP_BF_DP(X))) )
#define PP_BF_DATA_DECED($, X) ( PP_DEC(PP_NTH($, PP_BF_DA(X), PP_BF_DP(X))) )

#define PP_BF_DATA_INC($, X) PP_CONCAT( PP_BF_DATA_FST($, X) , PP_CONCAT( PP_BF_DATA_INCED($, X) , PP_BF_DATA_SND($, X) ) )
#define PP_BF_DATA_DEC($, X) PP_CONCAT( PP_BF_DATA_FST($, X) , PP_CONCAT( PP_BF_DATA_DECED($, X) , PP_BF_DATA_SND($, X) ) )

/* Jump Forward/Back */

// TODO: Make count braces
#define PP_BF_JUMP_FWD_E_TRD(S, I) PP_IF_ELSE(PP_IS_FOWARD(S), PP_INC(I), PP_IF_ELSE(PP_IS_BACKWARD(S), PP_DEC(I), I) )

#define PP_BF_JUMP_FWD_C($, X) PP_NOT(PP_IS_BACKWARD(PP_HEAD(PP_FST(X))))
#define PP_BF_JUMP_FWD_M($, X) 
#define PP_BF_JUMP_FWD_U($, X) (PP_TAIL(PP_FST(X)), PP_INC(PP_SND(X)))
#define PP_BF_JUMP_FWD_E($, X) PP_INC(PP_SND(X))
#define PP_BF_JUMP_FWD($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_BF_JUMP_FWD_C, PP_BF_JUMP_FWD_M, PP_BF_JUMP_FWD_U, PP_BF_JUMP_FWD_E, (PP_DROP($, PP_BF_IA(X), PP_BF_IP(X)), PP_BF_IP(X) ) )

// TODO: Make count braces
#define PP_BF_JUMP_BCK_C($, X) PP_NOT( PP_IS_FORWARD(PP_NTH($, PP_FST(X), PP_SND(X))) )
#define PP_BF_JUMP_BCK_M($, X) 
#define PP_BF_JUMP_BCK_U($, X) ( PP_FST(X), PP_DEC(PP_SND(X)) )
#define PP_BF_JUMP_BCK_E($, X) PP_INC(PP_SND(X))
#define PP_BF_JUMP_BCK($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_BF_JUMP_BCK_C, PP_BF_JUMP_BCK_M, PP_BF_JUMP_BCK_U, PP_BF_JUMP_BCK_E, (PP_BF_IA(X), PP_BF_IP(X)) )

#define PP_BF_JUMP_F($, X) PP_IF_ELSE(PP_BOOL(PP_BF_DATA($, X)), PP_INC(PP_BF_IP(X)), PP_BF_JUMP_FWD($, X) )
#define PP_BF_JUMP_B($, X) PP_IF_ELSE(PP_BOOL(PP_BF_DATA($, X)), PP_BF_JUMP_BCK($, X) , PP_INC(PP_BF_IP(X)) )

/* Brainfuck Symbol Update */
#define PP_BF_UPDATE_SYM($, S, X) PP_JOIN(PP_BF_UPDATE_SYM_, S)($, X)
#define PP_BF_UPDATE_SYM_R($, X) (PP_INC(PP_BF_IP(X)), PP_INC(PP_BF_DP(X)), PP_BF_IA(X), PP_BF_DA(X))
#define PP_BF_UPDATE_SYM_L($, X) (PP_INC(PP_BF_IP(X)), PP_DEC(PP_BF_DP(X)), PP_BF_IA(X), PP_BF_DA(X))
#define PP_BF_UPDATE_SYM_U($, X) (PP_INC(PP_BF_IP(X)), PP_BF_DP(X), PP_BF_IA(X), PP_BF_DATA_INC($, X))
#define PP_BF_UPDATE_SYM_D($, X) (PP_INC(PP_BF_IP(X)), PP_BF_DP(X), PP_BF_IA(X), PP_BF_DATA_DEC($, X))
#define PP_BF_UPDATE_SYM_O($, X) (PP_INC(PP_BF_IP(X)), PP_BF_DP(X), PP_BF_IA(X), PP_BF_DA(X))
#define PP_BF_UPDATE_SYM_F($, X) (PP_BF_JUMP_F($, X),  PP_BF_DP(X), PP_BF_IA(X), PP_BF_DA(X))
#define PP_BF_UPDATE_SYM_B($, X) (PP_BF_JUMP_B($, X),  PP_BF_DP(X), PP_BF_IA(X), PP_BF_DA(X))
#define PP_BF_UPDATE_SYM_($, X) X


#define PP_BF_COND($, X) PP_NOT(PP_IS_BLANK(PP_BF_INSTR($, X)))
#define PP_BF_MACRO($, X) PP_IF(PP_IS_OUTPUT(PP_BF_INSTR($, X)), PP_CHAR(PP_BF_DATA($, X)))
#define PP_BF_UPDATE($, X) PP_BF_UPDATE_SYM($, PP_BF_INSTR($, X), X)
#define PP_BF_FINALLY($, X) 
#define PP_BF_RECR($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_BF_COND, PP_BF_MACRO, PP_BF_UPDATE, PP_BF_FINALLY, X)

#define PP_BF_DATA_EMPTY() (0,0,0,0,0)

/* Perform Brainfuck with input I */
#define PP_BRAINFUCK(I) PP_BF_RECR($0, (0, 0, I, PP_BF_DATA_EMPTY()))


#endif