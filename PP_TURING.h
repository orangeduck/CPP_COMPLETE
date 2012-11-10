#ifndef PP_TURING_H
#define PP_TURING_H

#include "PP.h"

/*!
 *  Turing machine in C preprocessor
 *  
 *    T - Binary Tape
 *    S - Current State
 *    Q - Initial State
 *    F - Final State
 *    H - Head position
 *
 *  Where, given an initial state A,
 *  a transition state B, a binary 
 *  reading R, a binary write W,
 *  and a head movement M.
 *
 *  The transition is in the form:
 *
 *    `T_A_R=(B, W, M)`
 *
 *  
 *  Where `M` is `R`, `L` or `T` for "terminate"
 *  The state of the TM is given then by the following.
 *  
 *  It can be run in the following way.
 *
 *    `cpp MAIN_TM.h -D T=(0,0,1,1,0,1) -D Q=s0 -D T_s0_0=(s0, 1, R) -D T_s0_1=(s0, 1, R)`
 *  
 *  This should output
 *
 *    `((1,1,1,1,1,1), s0, 6)`
 *
 */
 
#define PP_TM_IS_BLANK(X) PP_JOIN(PP_TM_IS_BLANK_, X)
#define PP_TM_IS_BLANK_  1
#define PP_TM_IS_BLANK_0 0
#define PP_TM_IS_BLANK_1 0

#define PP_TM_IS_RIGHT(X) PP_JOIN(PP_TM_IS_RIGHT_, X)
#define PP_TM_IS_RIGHT_R 1
#define PP_TM_IS_RIGHT_L 0

#define PP_TM_T(X) PP_FST(X)
#define PP_TM_Q(X) PP_SND(X)
#define PP_TM_H(X) PP_TRD(X)

#define PP_TM_READ($, X) PP_NTH($, PP_TM_T(X), PP_TM_H(X))
#define PP_TM_TRANS($, X) PP_TM_TRANS_F(PP_TM_Q(X), PP_TM_READ($, X))
#define PP_TM_TRANS_F(A, R) PP_JOIN2(T_, A, R)

#define PP_TM_TAPE_FST($, T, N) PP_TAKE($, T, N)
#define PP_TM_TAPE_SND($, T, N) PP_DROP($, T, PP_INC(N))
#define PP_TM_TAPE_SET($, T, N, X) PP_CONCAT( PP_TM_TAPE_FST($, T, N) , PP_CONS( X , PP_TM_TAPE_SND($, T, N) ) )

#define PP_TM_TAPE_U($, X) PP_TM_TAPE_SET($, PP_TM_T(X), PP_TM_H(X), PP_SND(PP_TM_TRANS($, X)))
#define PP_TM_STATE_U($, X) PP_FST(PP_TM_TRANS($, X))
#define PP_TM_HEAD_U($, X) PP_IF_ELSE( PP_TM_IS_RIGHT(PP_TRD(PP_TM_TRANS($, X))) , PP_INC(PP_TM_H(X)) , PP_DEC(PP_TM_H(X)) )

#define PP_TURING_RECR_C($, X) PP_NOT(PP_TM_IS_BLANK(PP_TM_READ($, X)))
#define PP_TURING_RECR_M($, X) [PP_TM_HEAD_U($, X)]
//#define PP_TURING_RECR_U($, X) ( PP_TM_TAPE_U($, X), PP_TM_STATE_U($, X), PP_TM_HEAD_U($, X) )
#define PP_TURING_RECR_U($, X) ( PP_TM_T(X), PP_TM_Q(X), PP_TM_HEAD_U($, X) )
#define PP_TURING_RECR_E($, X) X
#define PP_TURING_RECR($, T, Q, H) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_TURING_RECR_C, PP_TURING_RECR_M, PP_TURING_RECR_U, PP_TURING_RECR_E, (T, Q, H))

#define PP_TURING(T, Q) PP_TURING_RECR($0, T, Q, 0)
 


#endif