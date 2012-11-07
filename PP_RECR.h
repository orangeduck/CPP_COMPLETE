#ifndef PP_RECR_H
#define PP_RECR_H

#include "PP_CORE.h"
#include "PP_COND.h"

#define $0 0
#define $1 1

/*!
 * Recursion Example
 * =================
 *
 * #define PP_RCOND($, X) PP_BOOL(X)
 * #define PP_RMACRO($, X) X
 * #define PP_RUPDATE($, X) PP_SUB($, X, 2)
 * #define PP_RFINALLY($, X) DONE
 *
 * #define PP_RTEST($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), PP_RCOND, PP_RMACRO, PP_RUPDATE, PP_RFINALLY, X)
 *
 * PP_RTEST($, 4) => 4 2 
 * 
 */
 
#define PP_RECR_D0($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D1($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D2($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D3($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D4($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D5($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D6($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D7($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D8($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D9($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D10($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D11($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D12($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D13($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D14($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D15($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D16($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D17($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D18($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D19($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D20($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D21($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D22($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D23($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D24($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D25($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D26($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D27($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D28($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D29($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D30($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D31($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)
#define PP_RECR_D32($, C, M, U, E, X)  PP_JOIN(PP_RECR_A, $)(PP_INC($), C, M, U, E, X)

#define PP_RECR_A0($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A1($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A2($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A3($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A4($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A5($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A6($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A7($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A8($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A9($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A10($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A11($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A12($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A13($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A14($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A15($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A16($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A17($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A18($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A19($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A20($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A21($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A22($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A23($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A24($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A25($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A26($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A27($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A28($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A29($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A30($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A31($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )
#define PP_RECR_A32($, C, M, U, E, X)  PP_IF_ELSE( C($, X), M($, X) PP_JOIN(PP_RECR_D, $)(PP_INC($), C, M, U, E, U($, X)), E($, X) )



#endif