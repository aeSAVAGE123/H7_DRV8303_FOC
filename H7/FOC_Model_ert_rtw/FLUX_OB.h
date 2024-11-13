/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FLUX_OB.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue Nov 12 14:52:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef FLUX_OB_h_
#define FLUX_OB_h_
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

#include "rtGetNaN.h"

/* Block signals and states (default storage) for system '<S2>/FLUX_OB' */
typedef struct {
  real32_T Delay_DSTATE[2];            /* '<S20>/Delay' */
  real32_T Delay1_DSTATE[2];           /* '<S20>/Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S19>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE;          /* '<S57>/Integrator' */
} DW_FLUX_OB;

extern void FLUX_OB(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_ualpha,
                    real32_T rtu_ubeta, real32_T *rty_theta, real32_T *rty_We,
                    DW_FLUX_OB *localDW);

#endif                                 /* FLUX_OB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
