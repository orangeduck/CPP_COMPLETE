#ifndef BRAINFUCK_H
#define BRAINFUCK_H

/*!
 *  BRAINFUCK
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
#define IS_BLANK(X) JOIN(IS_BLANK_, X) 
#define IS_BLANK_  1
#define IS_BLANK_R 0
#define IS_BLANK_L 0
#define IS_BLANK_U 0
#define IS_BLANK_D 0
#define IS_BLANK_O 0
#define IS_BLANK_F 0
#define IS_BLANK_B 0

/* Check if output symbol */
#define IS_OUTPUT(X) JOIN(IS_OUTPUT_, X)
#define IS_OUTPUT_  0
#define IS_OUTPUT_R 0
#define IS_OUTPUT_L 0
#define IS_OUTPUT_U 0
#define IS_OUTPUT_D 0
#define IS_OUTPUT_O 1
#define IS_OUTPUT_F 0
#define IS_OUTPUT_B 0

/* Check if forward symbol */
#define IS_FORWARD(X) JOIN(IS_FORWARD_, X)
#define IS_FORWARD_  0
#define IS_FORWARD_R 0
#define IS_FORWARD_L 0
#define IS_FORWARD_U 0
#define IS_FORWARD_D 0
#define IS_FORWARD_O 0
#define IS_FORWARD_F 1
#define IS_FORWARD_B 0

/* Check if backward symbol */
#define IS_BACKWARD(X) JOIN(IS_BACKWARD_, X)
#define IS_BACKWARD_  0
#define IS_BACKWARD_R 0
#define IS_BACKWARD_L 0
#define IS_BACKWARD_U 0
#define IS_BACKWARD_D 0
#define IS_BACKWARD_O 0
#define IS_BACKWARD_F 0
#define IS_BACKWARD_B 1

/* Get individual parts */
#define BF_IP(X) FST(X)
#define BF_DP(X) SND(X)
#define BF_IA(X) TRD(X)
#define BF_DA(X) FTH(X)
#define BF_INSTR($, X) NTH($, BF_IA(X), BF_IP(X)) 
#define BF_DATA($, X)  NTH($, BF_DA(X), BF_DP(X)) 

/* Inc/Dec Data Item */
#define BF_DATA_FST($, X) TAKE($, BF_DA(X), BF_DP(X))
#define BF_DATA_SND($, X) DROP($, BF_DA(X), INC(BF_DP(X)))
#define BF_DATA_INCED($, X) ( INC(NTH($, BF_DA(X), BF_DP(X))) )
#define BF_DATA_DECED($, X) ( DEC(NTH($, BF_DA(X), BF_DP(X))) )

#define BF_DATA_INC($, X) CONCAT( BF_DATA_FST($, X) , CONCAT( BF_DATA_INCED($, X) , BF_DATA_SND($, X) ) )
#define BF_DATA_DEC($, X) CONCAT( BF_DATA_FST($, X) , CONCAT( BF_DATA_DECED($, X) , BF_DATA_SND($, X) ) )

/* Jump Forward/Back */

// TODO: Make count braces
#define BF_JUMP_FWD_E_TRD(S, I) IF_ELSE(IS_FOWARD(S), INC(I), IF_ELSE(IS_BACKWARD(S), DEC(I), I) )

#define BF_JUMP_FWD_C($, X) NOT(IS_BACKWARD(HEAD(FST(X))))
#define BF_JUMP_FWD_M($, X) 
#define BF_JUMP_FWD_U($, X) (TAIL(FST(X)), INC(SND(X)))
#define BF_JUMP_FWD_E($, X) INC(SND(X))
#define BF_JUMP_FWD($, X) JOIN(RECR_D, $)(INC($), BF_JUMP_FWD_C, BF_JUMP_FWD_M, BF_JUMP_FWD_U, BF_JUMP_FWD_E, (DROP($, BF_IA(X), BF_IP(X)), BF_IP(X) ) )

// TODO: Make count braces
#define BF_JUMP_BCK_C($, X) NOT( IS_FORWARD(NTH($, FST(X), SND(X))) )
#define BF_JUMP_BCK_M($, X) 
#define BF_JUMP_BCK_U($, X) ( FST(X), DEC(SND(X)) )
#define BF_JUMP_BCK_E($, X) INC(SND(X))
#define BF_JUMP_BCK($, X) JOIN(RECR_D, $)(INC($), BF_JUMP_BCK_C, BF_JUMP_BCK_M, BF_JUMP_BCK_U, BF_JUMP_BCK_E, (BF_IA(X), BF_IP(X)) )

#define BF_JUMP_F($, X) IF_ELSE(BOOL(BF_DATA($, X)), INC(BF_IP(X)), BF_JUMP_FWD($, X) )
#define BF_JUMP_B($, X) IF_ELSE(BOOL(BF_DATA($, X)), BF_JUMP_BCK($, X) , INC(BF_IP(X)) )

/* Brainfuck Symbol Update */
#define BF_UPDATE_SYM($, S, X) JOIN(BF_UPDATE_SYM_, S)($, X)
#define BF_UPDATE_SYM_R($, X) (INC(BF_IP(X)), INC(BF_DP(X)), BF_IA(X), BF_DA(X))
#define BF_UPDATE_SYM_L($, X) (INC(BF_IP(X)), DEC(BF_DP(X)), BF_IA(X), BF_DA(X))
#define BF_UPDATE_SYM_U($, X) (INC(BF_IP(X)), BF_DP(X), BF_IA(X), BF_DATA_INC($, X))
#define BF_UPDATE_SYM_D($, X) (INC(BF_IP(X)), BF_DP(X), BF_IA(X), BF_DATA_DEC($, X))
#define BF_UPDATE_SYM_O($, X) (INC(BF_IP(X)), BF_DP(X), BF_IA(X), BF_DA(X))
#define BF_UPDATE_SYM_F($, X) (BF_JUMP_F($, X),  BF_DP(X), BF_IA(X), BF_DA(X))
#define BF_UPDATE_SYM_B($, X) (BF_JUMP_B($, X),  BF_DP(X), BF_IA(X), BF_DA(X))
#define BF_UPDATE_SYM_($, X) X


#define BF_COND($, X) NOT(IS_BLANK(BF_INSTR($, X)))
#define BF_MACRO($, X) IF(IS_OUTPUT(BF_INSTR($, X)), CHAR(BF_DATA($, X)))
#define BF_UPDATE($, X) BF_UPDATE_SYM($, BF_INSTR($, X), X)
#define BF_FINALLY($, X) 
#define BF_RECR($, X) JOIN(RECR_D, $)(INC($), BF_COND, BF_MACRO, BF_UPDATE, BF_FINALLY, X)

#define BF_DATA_EMPTY() (0,0,0,0,0)

/* Perform Brainfuck with input I */
#define BRAINFUCK(I) BF_RECR($0, (0, 0, I, BF_DATA_EMPTY()))


#endif