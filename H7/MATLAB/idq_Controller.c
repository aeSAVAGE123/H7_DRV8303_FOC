/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: idq_Controller.c
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
#include "idq_Controller.h"
#include <math.h>
#include "FOC_Model_private.h"
#include "FOC_Model.h"

/* Output and update for atomic system: '<S2>/idq_Controller' */
void idq_Controller(real32_T rtu_id_fdbk, real32_T rtu_iq_fdbk, real32_T
                    rtu_iq_ref, real32_T *rty_ud_ref, real32_T *rty_uq_ref,
                    DW_idq_Controller *localDW)
{
  real32_T rtb_IProdOut;
  real32_T rtb_Integrator_e;
  real32_T rtb_Sum_i;
  real32_T rtb_Sum_n;
  int16_T rtb_IProdOut_p;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3_g;

  /* Sum: '<S130>/Sum' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant3'
   *  DiscreteIntegrator: '<S121>/Integrator'
   *  Product: '<S126>/PProd Out'
   *  Sum: '<S18>/Sum1'
   */
  rtb_Sum_n = (0.0F - rtu_id_fdbk) * curr_kpki.curr_d_kp + (real32_T)
    localDW->Integrator_DSTATE_f * 0.0001F;

  /* DeadZone: '<S113>/DeadZone' */
  if (rtb_Sum_n > 12.4707661F) {
    rtb_Integrator_e = rtb_Sum_n - 12.4707661F;
  } else if (rtb_Sum_n >= -12.4707661F) {
    rtb_Integrator_e = 0.0F;
  } else {
    rtb_Integrator_e = rtb_Sum_n - -12.4707661F;
  }

  /* End of DeadZone: '<S113>/DeadZone' */

  /* Product: '<S118>/IProd Out' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant4'
   *  Sum: '<S18>/Sum1'
   */
  rtb_IProdOut_p = (int16_T)floorf((0.0F - rtu_id_fdbk) * curr_kpki.curr_d_ki);

  /* Switch: '<S111>/Switch1' incorporates:
   *  Constant: '<S111>/Constant'
   *  Constant: '<S111>/Constant2'
   *  RelationalOperator: '<S111>/fix for DT propagation issue'
   */
  if (rtb_Integrator_e > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S111>/Switch2' incorporates:
   *  Constant: '<S111>/Clamping_zero'
   *  Constant: '<S111>/Constant3'
   *  Constant: '<S111>/Constant4'
   *  RelationalOperator: '<S111>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_p > 0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S111>/AND3' incorporates:
   *  RelationalOperator: '<S111>/Equal1'
   *  RelationalOperator: '<S111>/Relational Operator'
   *  Switch: '<S111>/Switch1'
   *  Switch: '<S111>/Switch2'
   */
  rtb_AND3_g = ((rtb_Integrator_e != 0.0F) && (tmp == tmp_0));

  /* Sum: '<S18>/Sum7' */
  rtb_Integrator_e = rtu_iq_ref - rtu_iq_fdbk;

  /* Product: '<S172>/IProd Out' incorporates:
   *  Constant: '<S18>/Constant4'
   */
  rtb_IProdOut = rtb_Integrator_e * curr_kpki.curr_d_ki;

  /* Sum: '<S184>/Sum' incorporates:
   *  Constant: '<S18>/Constant3'
   *  DiscreteIntegrator: '<S175>/Integrator'
   *  Product: '<S180>/PProd Out'
   */
  rtb_Sum_i = rtb_Integrator_e * curr_kpki.curr_d_kp +
    localDW->Integrator_DSTATE;

  /* DeadZone: '<S167>/DeadZone' incorporates:
   *  Saturate: '<S182>/Saturation'
   */
  if (rtb_Sum_i > 12.4707661F) {
    rtb_Integrator_e = rtb_Sum_i - 12.4707661F;
    *rty_uq_ref = 12.4707661F;
  } else {
    if (rtb_Sum_i >= -12.4707661F) {
      rtb_Integrator_e = 0.0F;
    } else {
      rtb_Integrator_e = rtb_Sum_i - -12.4707661F;
    }

    if (rtb_Sum_i < -12.4707661F) {
      *rty_uq_ref = -12.4707661F;
    } else {
      *rty_uq_ref = rtb_Sum_i;
    }
  }

  /* End of DeadZone: '<S167>/DeadZone' */

  /* Saturate: '<S128>/Saturation' */
  if (rtb_Sum_n > 12.4707661F) {
    *rty_ud_ref = 12.4707661F;
  } else if (rtb_Sum_n < -12.4707661F) {
    *rty_ud_ref = -12.4707661F;
  } else {
    *rty_ud_ref = rtb_Sum_n;
  }

  /* End of Saturate: '<S128>/Saturation' */

  /* Switch: '<S111>/Switch' incorporates:
   *  Constant: '<S111>/Constant1'
   */
  if (rtb_AND3_g) {
    rtb_IProdOut_p = 0;
  }

  /* Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
   *  Switch: '<S111>/Switch'
   */
  localDW->Integrator_DSTATE_f += rtb_IProdOut_p;

  /* Switch: '<S165>/Switch1' incorporates:
   *  Constant: '<S165>/Clamping_zero'
   *  Constant: '<S165>/Constant'
   *  Constant: '<S165>/Constant2'
   *  RelationalOperator: '<S165>/fix for DT propagation issue'
   */
  if (rtb_Integrator_e > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S165>/Switch2' incorporates:
   *  Constant: '<S165>/Clamping_zero'
   *  Constant: '<S165>/Constant3'
   *  Constant: '<S165>/Constant4'
   *  RelationalOperator: '<S165>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S165>/Switch' incorporates:
   *  Constant: '<S165>/Clamping_zero'
   *  Constant: '<S165>/Constant1'
   *  Logic: '<S165>/AND3'
   *  RelationalOperator: '<S165>/Equal1'
   *  RelationalOperator: '<S165>/Relational Operator'
   *  Switch: '<S165>/Switch1'
   *  Switch: '<S165>/Switch2'
   */
  if ((rtb_Integrator_e != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S175>/Integrator' incorporates:
   *  Switch: '<S165>/Switch'
   */
  localDW->Integrator_DSTATE += 0.0001F * rtb_IProdOut;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
