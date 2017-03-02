/*
 * File: Quad.h
 *
 * Code generated for Simulink model 'Quad'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Sun Feb 26 22:33:20 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quad_h_
#define RTW_HEADER_Quad_h_
#ifndef Quad_COMMON_INCLUDES_
# define Quad_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* Quad_COMMON_INCLUDES_ */

#include "Quad_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    uint_T UnitDelay_DSTATE:1;         /* '<S1>/Unit Delay' */
  } bitsForTID0;
} D_Work_Quad;

/* Block states (auto storage) */
extern D_Work_Quad Quad_DWork;

/* Model entry point functions */
extern void Quad_initialize(void);
extern void Quad_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Quad'
 * '<S1>'   : 'Quad/EnableDisableLed'
 */

/*-
 * Requirements for '<Root>': Quad
 */
#endif                                 /* RTW_HEADER_Quad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
