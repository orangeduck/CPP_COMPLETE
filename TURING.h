#ifndef TURING_H
#define TURING_H

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
 
#define TM_IS_BLANK(X) JOIN(TM_IS_BLANK_, X)
#define TM_IS_BLANK_  1
#define TM_IS_BLANK_0 0
#define TM_IS_BLANK_1 0

#define TM_IS_RIGHT(X) JOIN(TM_IS_RIGHT_, X)
#define TM_IS_RIGHT_R 1
#define TM_IS_RIGHT_L 0

#define TM_T(X) FST(X)
#define TM_Q(X) SND(X)
#define TM_H(X) TRD(X)

#define TM_READ($, X) NTH($, TM_T(X), TM_H(X))
#define TM_TRANS($, X) TM_TRANS_F(TM_Q(X), TM_READ($, X))
#define TM_TRANS_F(A, R) JOIN2(T_, A, R)

#define TM_TAPE_FST($, T, N) TAKE($, T, N)
#define TM_TAPE_SND($, T, N) DROP($, T, INC(N))
#define TM_TAPE_SET($, T, N, X) CONCAT( TM_TAPE_FST($, T, N) , CONS( X , TM_TAPE_SND($, T, N) ) )

#define TM_TAPE_U($, X) TM_TAPE_SET($, TM_T(X), TM_H(X), SND(TM_TRANS($, X)))
#define TM_STATE_U($, X) FST(TM_TRANS($, X))
#define TM_HEAD_U($, X) IF_ELSE( TM_IS_RIGHT(TRD(TM_TRANS($, X))) , INC(TM_H(X)) , DEC(TM_H(X)) )

#define TURING_RECR_C($, X) NOT(TM_IS_BLANK(TM_READ($, X)))
#define TURING_RECR_M($, X) [TM_HEAD_U($, X)]
//#define TURING_RECR_U($, X) ( TM_TAPE_U($, X), TM_STATE_U($, X), TM_HEAD_U($, X) )
#define TURING_RECR_U($, X) ( TM_T(X), TM_Q(X), TM_HEAD_U($, X) )
#define TURING_RECR_E($, X) X
#define TURING_RECR($, T, Q, H) JOIN(RECR_D, $)(INC($), TURING_RECR_C, TURING_RECR_M, TURING_RECR_U, TURING_RECR_E, (T, Q, H))

#define TURING(T, Q) TURING_RECR($0, T, Q, 0)
 


#endif