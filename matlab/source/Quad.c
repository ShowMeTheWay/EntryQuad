/*
 * File: Quad.c
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

#include "Quad.h"
#include "Quad_private.h"

/* Block states (auto storage) */
D_Work_Quad Quad_DWork;

/* Model step function */
void Quad_step(void)
{
  /* Logic: '<S1>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Quad_DWork.bitsForTID0.UnitDelay_DSTATE =
    !Quad_DWork.bitsForTID0.UnitDelay_DSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  EnableDisablePin((uint16_T)Quad_DWork.bitsForTID0.UnitDelay_DSTATE);
}

/* Model initialize function */
void Quad_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&Quad_DWork, 0,
                sizeof(D_Work_Quad));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
