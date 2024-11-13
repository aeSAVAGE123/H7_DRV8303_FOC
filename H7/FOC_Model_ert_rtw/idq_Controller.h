/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: idq_Controller.h
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

#ifndef idq_Controller_h_
#define idq_Controller_h_
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<S2>/idq_Controller' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S175>/Integrator' */
  int16_T Integrator_DSTATE_f;         /* '<S121>/Integrator' */
} DW_idq_Controller;

extern void idq_Controller(real32_T rtu_id_fdbk, real32_T rtu_iq_fdbk, real32_T
  rtu_iq_ref, real32_T *rty_ud_ref, real32_T *rty_uq_ref, DW_idq_Controller
  *localDW);

#endif                                 /* idq_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
