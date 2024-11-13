/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SVPWM.c
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
#include "SVPWM.h"
#include <math.h>
#include "mw_cmsis.h"
#include "FOC_Model.h"
#include "FOC_Model_private.h"

/* Output and update for atomic system: '<S2>/SVPWM' */
void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus, real32_T
           rty_tABC[3])
{
  real32_T tmp[3];
  real32_T tmp_0[3];
  real32_T rtb_Min;
  real32_T rtb_Sum1_j;
  real32_T rtb_Sum_b;

  /* Gain: '<S79>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S79>/Gain1' */
  rtb_Sum1_j = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S79>/Sum' */
  rtb_Sum_b = rtb_Min + rtb_Sum1_j;

  /* Sum: '<S79>/Sum1' */
  rtb_Sum1_j = rtb_Min - rtb_Sum1_j;

  /* Gain: '<S80>/Gain' incorporates:
   *  MinMax: '<S80>/Min'
   *  MinMax: '<S80>/Min1'
   *  Sum: '<S80>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_b), rtb_Sum1_j) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_b), rtb_Sum1_j)) * -0.5F;

  /* Sum: '<S16>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_b;
  rty_tABC[2] = rtb_Min + rtb_Sum1_j;

  /* Gain: '<S16>/Gain' */
  mw_arm_scale_1_f32(&rtConstP.Gain_Gain_j, &rty_tABC[0], &tmp[0], 3U);

  /* Sum: '<S16>/Sum1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Gain: '<S16>/Gain'
   *  Product: '<S16>/Divide'
   */
  tmp[0] /= rtu_v_bus;
  tmp[1] /= rtu_v_bus;
  tmp[2] /= rtu_v_bus;
  mw_arm_bias_2_f32(&tmp[0], &rtConstP.pooled2, &tmp_0[0], 3U);

  /* Gain: '<S16>/PWM_HalfPeriod' incorporates:
   *  Sum: '<S16>/Sum1'
   */
  mw_arm_scale_1_f32(&rtConstP.pooled4, &tmp_0[0], &rty_tABC[0], 3U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
