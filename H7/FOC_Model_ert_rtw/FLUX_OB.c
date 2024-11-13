/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FLUX_OB.c
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
#include "FLUX_OB.h"
#include "mw_cmsis.h"
#include <math.h>
#include "FOC_Model_private.h"
#include "FOC_Model.h"
#include "rt_nonfinite.h"
#include <float.h>

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Output and update for atomic system: '<S2>/FLUX_OB' */
void FLUX_OB(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_ualpha,
             real32_T rtu_ubeta, real32_T *rty_theta, real32_T *rty_We,
             DW_FLUX_OB *localDW)
{
  real32_T rtb_MatrixConcatenate[2];
  real32_T rtb_MatrixConcatenate1[2];
  real32_T rtb_MatrixConcatenate2[2];
  real32_T rtb_MatrixConcatenate3[2];
  real32_T rtb_Sum5[2];
  real32_T tmp[2];
  real32_T rtb_IntegralGain_b;
  real32_T rtb_Product_h1;

  /* SignalConversion generated from: '<S20>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[0] = rtu_ialpha;

  /* SignalConversion generated from: '<S20>/Matrix Concatenate2' */
  rtb_MatrixConcatenate2[1] = rtu_ibeta;

  /* Gain: '<S20>/Gain1' incorporates:
   *  Concatenate: '<S20>/Matrix Concatenate2'
   */
  rtb_Product_h1 = -JIE_MEI_KANG_PARAMETER.L;
  mw_arm_scale_1_f32(&rtb_Product_h1, &rtb_MatrixConcatenate2[0], &tmp[0], 2U);

  /* Sum: '<S20>/Sum1' incorporates:
   *  Delay: '<S20>/Delay'
   *  Gain: '<S20>/Gain1'
   *  Gain: '<S20>/Gain5'
   */
  mw_arm_add_f32(&tmp[0], &localDW->Delay_DSTATE[0], &rtb_MatrixConcatenate2[0],
                 2U);

  /* Math: '<S20>/Square' */
  *rty_theta = rtb_MatrixConcatenate2[0] * rtb_MatrixConcatenate2[0];

  /* Product: '<S20>/Product' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Gain: '<S20>/Gain2'
   *  Math: '<S20>/Square1'
   *  Math: '<S20>/Square2'
   *  Sum: '<S20>/Sum2'
   *  Sum: '<S20>/Sum3'
   */
  rtb_Product_h1 = (JIE_MEI_KANG_PARAMETE.FLUX * JIE_MEI_KANG_PARAMETE.FLUX -
                    (rtb_MatrixConcatenate2[1] * rtb_MatrixConcatenate2[1] +
                     *rty_theta)) * (0.5F * FLU_OBS.FLU);

  /* SignalConversion generated from: '<S20>/Matrix Concatenate1' */
  rtb_MatrixConcatenate1[0] = rtu_ualpha;

  /* SignalConversion generated from: '<S20>/Matrix Concatenate1' */
  rtb_MatrixConcatenate1[1] = rtu_ubeta;

  /* SignalConversion generated from: '<S20>/Matrix Concatenate' */
  rtb_MatrixConcatenate[0] = rtu_ialpha;

  /* SignalConversion generated from: '<S20>/Matrix Concatenate' */
  rtb_MatrixConcatenate[1] = rtu_ibeta;

  /* Product: '<S20>/Product1' incorporates:
   *  Gain: '<S20>/Gain5'
   */
  mw_arm_scale_2_f32(&rtb_MatrixConcatenate2[0], &rtb_Product_h1, &tmp[0], 2U);

  /* Gain: '<S20>/Gain' incorporates:
   *  Concatenate: '<S20>/Matrix Concatenate'
   */
  rtb_Product_h1 = -JIE_MEI_KANG_PARAMETER.Rs;
  mw_arm_scale_1_f32(&rtb_Product_h1, &rtb_MatrixConcatenate[0],
                     &rtb_MatrixConcatenate3[0], 2U);

  /* Sum: '<S20>/Sum' incorporates:
   *  Concatenate: '<S20>/Matrix Concatenate1'
   *  Gain: '<S20>/Gain'
   */
  mw_arm_add_f32(&rtb_MatrixConcatenate3[0], &rtb_MatrixConcatenate1[0],
                 &rtb_MatrixConcatenate[0], 2U);

  /* Sum: '<S20>/Sum4' incorporates:
   *  Product: '<S20>/Product1'
   *  Sum: '<S20>/Sum'
   */
  mw_arm_add_f32(&tmp[0], &rtb_MatrixConcatenate[0], &rtb_MatrixConcatenate3[0],
                 2U);

  /* Gain: '<S20>/Gain3' incorporates:
   *  Sum: '<S20>/Sum4'
   */
  mw_arm_scale_1_f32((real32_T *)&(Tp_loop.T), &rtb_MatrixConcatenate3[0], &tmp
                     [0], 2U);

  /* Sum: '<S20>/Sum5' incorporates:
   *  Delay: '<S20>/Delay1'
   *  Gain: '<S20>/Gain3'
   */
  mw_arm_add_f32(&tmp[0], &localDW->Delay1_DSTATE[0], &rtb_Sum5[0], 2U);

  /* SignalConversion generated from: '<S20>/Matrix Concatenate3' */
  rtb_MatrixConcatenate3[0] = rtu_ualpha;

  /* SignalConversion generated from: '<S20>/Matrix Concatenate3' */
  rtb_MatrixConcatenate3[1] = rtu_ubeta;

  /* Gain: '<S20>/Gain5' */
  rtb_Product_h1 = 1.0F / JIE_MEI_KANG_PARAMETE.FLUX;

  /* Gain: '<S20>/Gain4' incorporates:
   *  Concatenate: '<S20>/Matrix Concatenate3'
   */
  mw_arm_scale_1_f32((real32_T *)&(JIE_MEI_KANG_PARAMETER.L),
                     &rtb_MatrixConcatenate3[0], &tmp[0], 2U);

  /* Sum: '<S20>/Sum6' incorporates:
   *  Gain: '<S20>/Gain4'
   *  Sum: '<S20>/Sum5'
   */
  mw_arm_sub_f32(&rtb_Sum5[0], &tmp[0], &rtb_MatrixConcatenate3[0], 2U);

  /* Gain: '<S20>/Gain5' incorporates:
   *  Sum: '<S20>/Sum6'
   */
  mw_arm_scale_1_f32(&rtb_Product_h1, &rtb_MatrixConcatenate3[0],
                     &rtb_MatrixConcatenate2[0], 2U);

  /* Trigonometry: '<S76>/ReplicaOfSource' incorporates:
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   */
  *rty_theta = sinf(localDW->DiscreteTimeIntegrator_DSTATE);

  /* Product: '<S19>/Product' */
  *rty_theta *= rtb_MatrixConcatenate2[0];

  /* Sum: '<S19>/Sum' incorporates:
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   *  Product: '<S19>/Product1'
   *  Trigonometry: '<S75>/ReplicaOfSource'
   */
  *rty_theta = cosf(localDW->DiscreteTimeIntegrator_DSTATE) *
    rtb_MatrixConcatenate2[1] - *rty_theta;

  /* Sum: '<S66>/Sum' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator'
   *  Gain: '<S62>/Proportional Gain'
   */
  *rty_We = 2121.0F * *rty_theta + localDW->Integrator_DSTATE;

  /* Saturate: '<S64>/Saturation' */
  if (*rty_We > 10000.0F) {
    rtb_Product_h1 = 10000.0F;
  } else if (*rty_We < -10000.0F) {
    rtb_Product_h1 = -10000.0F;
  } else {
    rtb_Product_h1 = *rty_We;
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Gain: '<S8>/Gain1' incorporates:
   *  Gain: '<S8>/Gain'
   */
  *rty_We = 1.0F / JIE_MEI_KANG_PARAMETER.Pn * rtb_Product_h1 * 9.54929638F;

  /* Gain: '<S54>/Integral Gain' */
  rtb_IntegralGain_b = 250000.0F * *rty_theta;

  /* Math: '<S8>/Mod' incorporates:
   *  Constant: '<S8>/Constant1'
   *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
   */
  *rty_theta = rt_modf_snf(localDW->DiscreteTimeIntegrator_DSTATE, 6.28318548F);

  /* Update for Delay: '<S20>/Delay' incorporates:
   *  Sum: '<S20>/Sum5'
   */
  localDW->Delay_DSTATE[0] = rtb_Sum5[0];

  /* Update for Delay: '<S20>/Delay1' incorporates:
   *  Sum: '<S20>/Sum5'
   */
  localDW->Delay1_DSTATE[0] = rtb_Sum5[0];

  /* Update for Delay: '<S20>/Delay' incorporates:
   *  Sum: '<S20>/Sum5'
   */
  localDW->Delay_DSTATE[1] = rtb_Sum5[1];

  /* Update for Delay: '<S20>/Delay1' incorporates:
   *  Sum: '<S20>/Sum5'
   */
  localDW->Delay1_DSTATE[1] = rtb_Sum5[1];

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE += 0.0001F * rtb_Product_h1;

  /* Update for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_DSTATE += 0.0001F * rtb_IntegralGain_b;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
