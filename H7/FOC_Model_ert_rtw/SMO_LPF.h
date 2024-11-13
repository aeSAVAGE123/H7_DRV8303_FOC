/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SMO_LPF.h
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

#ifndef SMO_LPF_h_
#define SMO_LPF_h_
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<S1>/LPF' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S4>/Delay' */
} DW_SMO_LPF;

extern real32_T SMO_LPF(real32_T rtu_obs_we, DW_SMO_LPF *localDW);

#endif                                 /* SMO_LPF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
