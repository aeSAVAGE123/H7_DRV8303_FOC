/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SMO_LPF.c
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

#include "rtwtypes.h"
#include "SMO_LPF.h"
#include "FOC_Model_private.h"

/* Output and update for atomic system: '<S1>/LPF' */
real32_T SMO_LPF(real32_T rtu_obs_we, DW_SMO_LPF *localDW)
{
  real32_T rty_we_0;

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Delay: '<S4>/Delay'
   *  Product: '<S4>/Product'
   *  Sum: '<S4>/Sum'
   */
  rty_we_0 = (rtu_obs_we - localDW->Delay_DSTATE) * 0.003F +
    localDW->Delay_DSTATE;

  /* Update for Delay: '<S4>/Delay' */
  localDW->Delay_DSTATE = rty_we_0;
  return rty_we_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
