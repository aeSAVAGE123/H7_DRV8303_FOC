/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FOC_Model.c
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

#include "FOC_Model.h"
#include "rtwtypes.h"
#include "FOC_Model_private.h"
#include <math.h>
#include "SVPWM.h"
#include "FLUX_OB.h"
#include "idq_Controller.h"
#include "SMO_LPF.h"

/* Named constants for Chart: '<S2>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define IN_ThetaAlign                  ((uint8_T)5U)

/* Exported data definition */

/* Definition for custom storage class: Struct */
FLU_OBS_type FLU_OBS = {
  /* FLU */
  1.0E+6F
};

JIE_MEI_KANG_PARAMETE_type JIE_MEI_KANG_PARAMETE = {
  /* FLUX */
  0.0055F
};

JIE_MEI_KANG_PARAMETER_type JIE_MEI_KANG_PARAMETER = {
  /* L */
  0.00062F,

  /* Pn */
  4.0F,

  /* Rs */
  0.89F
};

MID_parameter_type MID_parameter;
Tp_loop_type Tp_loop = {
  /* T */
  0.0001F
};

curr_kpki_type curr_kpki = {
  /* curr_d_ki */
  100.0F,

  /* curr_d_kp */
  0.1F
};

spd_kpki_type spd_kpki = {
  /* spd_ki */
  0.001F,

  /* spd_kp */
  0.0005F
};

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for atomic system: '<S2>/Clark' */
void Clark(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic)
{
  /* Sum: '<S7>/Add1' incorporates:
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Sum: '<S7>/Add'
   */
  MID_parameter.ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) *
    0.333333343F;

  /* Gain: '<S7>/Gain2' incorporates:
   *  Sum: '<S7>/Add2'
   */
  MID_parameter.ibeta = (rtu_ib - rtu_ic) * 0.577350259F;
}

/* Output and update for atomic system: '<S2>/In_park' */
void In_park(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta_sin, real32_T
             rtu_theta_cos)
{
  /* Sum: '<S14>/Add' incorporates:
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   */
  MID_parameter.ualpha = rtu_ud * rtu_theta_cos - rtu_uq * rtu_theta_sin;

  /* Sum: '<S14>/Add1' incorporates:
   *  Product: '<S14>/Product2'
   *  Product: '<S14>/Product3'
   */
  MID_parameter.ubeta = rtu_ud * rtu_theta_sin + rtu_uq * rtu_theta_cos;
}

/* Output and update for atomic system: '<S2>/Park' */
void Park(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T rtu_theta_sin,
          real32_T rtu_theta_cos, real32_T *rty_id, real32_T *rty_iq)
{
  /* Sum: '<S15>/Add' incorporates:
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   */
  *rty_id = rtu_ialpha * rtu_theta_cos + rtu_ibeta * rtu_theta_sin;

  /* Sum: '<S15>/Add1' incorporates:
   *  Product: '<S15>/Product2'
   *  Product: '<S15>/Product3'
   */
  *rty_iq = rtu_ibeta * rtu_theta_cos - rtu_ialpha * rtu_theta_sin;
}

/* System initialize for atomic system: '<S1>/Curr_loop' */
void Curr_loop_Init(real32_T *rty_RestsSingal, DW_Curr_loop *localDW)
{
  /* SystemInitialize for Chart: '<S2>/Chart1' */
  *rty_RestsSingal = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S2>/If Action Subsystem2' */
  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S2>/If Action Subsystem2' */
}

/* Output and update for atomic system: '<S1>/Curr_loop' */
void Curr_loop(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic, real_T
               rtu_MotorOnOff, real32_T rtu_iq_ref, real32_T rtu_VDC, real32_T
               rtyyy_Tcmp1Tcmp2Tcmp3[3], real32_T *rty_RestsSingal, DW_Curr_loop
               *localDW)
{
  real32_T rtb_Add_h;
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation_h;

  /* Chart: '<S2>/Chart1' */
  if (localDW->temporalCounter_i1 < 16383) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c7_FOC_Model == 0) {
    localDW->is_active_c7_FOC_Model = 1U;
    localDW->is_c7_FOC_Model = IN_IDLE;
  } else {
    switch (localDW->is_c7_FOC_Model) {
     case IN_AlignStage:
      if (localDW->temporalCounter_i1 >= 1000) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c7_FOC_Model = IN_OpenStage;
        localDW->ZReset = 0.0F;
        localDW->cnt = 0.0F;
      } else if (rtu_MotorOnOff == 0.0) {
        localDW->is_c7_FOC_Model = IN_IDLE;
      } else {
        MID_parameter.state = 2.0F;
        *rty_RestsSingal = 0.0F;
      }
      break;

     case IN_IDLE:
      if (rtu_MotorOnOff == 1.0) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c7_FOC_Model = IN_AlignStage;
      } else {
        MID_parameter.state = 1.0F;
        *rty_RestsSingal = 0.0F;
      }
      break;

     case IN_OpenStage:
      if (rtu_MotorOnOff == 0.0) {
        localDW->is_c7_FOC_Model = IN_IDLE;
      } else if (localDW->temporalCounter_i1 >= 10000) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c7_FOC_Model = IN_ThetaAlign;
      } else {
        if (localDW->cnt == 1.0F) {
          localDW->ZReset = 1.0F;
        }

        localDW->cnt = 1.0F;
        MID_parameter.state = 3.0F;
        *rty_RestsSingal = 0.0F;
      }
      break;

     case IN_RunStage:
      if (rtu_MotorOnOff == 0.0) {
        localDW->is_c7_FOC_Model = IN_IDLE;
      } else {
        MID_parameter.state = 4.0F;
        *rty_RestsSingal = 0.0F;
      }
      break;

     default:
      /* case IN_ThetaAlign: */
      if (localDW->temporalCounter_i1 >= 5000) {
        localDW->is_c7_FOC_Model = IN_RunStage;
      } else {
        MID_parameter.state = 4.0F;
        *rty_RestsSingal = 0.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* SwitchCase: '<S2>/Switch Case1' */
  switch ((int32_T)MID_parameter.state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  SignalConversion generated from: '<S9>/theta_fd'
     */
    localDW->Merge = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  SignalConversion generated from: '<S9>/iq_ref'
     */
    localDW->Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  Constant: '<S10>/Constant'
     *  SignalConversion generated from: '<S10>/theta_fd'
     */
    localDW->Merge = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S10>/Constant1'
     *  SignalConversion generated from: '<S10>/iq_ref'
     */
    localDW->Merge1 = 0.5F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    if ((localDW->ZReset > 0.0F) && (localDW->DiscreteTimeIntegrator_PrevRese <=
         0)) {
      localDW->DiscreteTimeIntegrator_DSTATE = 0.0F;
    }

    rtb_DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

    /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
    if ((localDW->ZReset > 0.0F) && (localDW->DiscreteTimeIntegrator1_PrevRes <=
         0)) {
      localDW->DiscreteTimeIntegrator1_DSTAT_j = 0.0F;
    }

    /* Merge: '<S2>/Merge' incorporates:
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
     *  SignalConversion generated from: '<S11>/theta_fd'
     */
    localDW->Merge = localDW->DiscreteTimeIntegrator1_DSTAT_j;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S11>/Constant2'
     *  SignalConversion generated from: '<S11>/iq_ref'
     */
    localDW->Merge1 = 0.5F;

    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S2>/Constant'
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
     *  Gain: '<S11>/Gain'
     *  Gain: '<S11>/Gain1'
     */
    localDW->DiscreteTimeIntegrator_DSTATE += JIE_MEI_KANG_PARAMETER.Pn *
      31.4159279F * 0.0001F;
    if (localDW->ZReset > 0.0F) {
      localDW->DiscreteTimeIntegrator_PrevRese = 1;
      localDW->DiscreteTimeIntegrator1_PrevRes = 1;
    } else if (localDW->ZReset < 0.0F) {
      localDW->DiscreteTimeIntegrator_PrevRese = -1;
      localDW->DiscreteTimeIntegrator1_PrevRes = -1;
    } else if (localDW->ZReset == 0.0F) {
      localDW->DiscreteTimeIntegrator_PrevRese = 0;
      localDW->DiscreteTimeIntegrator1_PrevRes = 0;
    } else {
      localDW->DiscreteTimeIntegrator_PrevRese = 2;
      localDW->DiscreteTimeIntegrator1_PrevRes = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
    localDW->DiscreteTimeIntegrator1_DSTAT_j += 0.0001F *
      rtb_DiscreteTimeIntegrator;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* If: '<S13>/If' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/Constant4'
     *  Constant: '<S77>/Constant'
     *  Merge: '<S2>/Merge1'
     *  Product: '<S13>/Product1'
     *  SignalConversion generated from: '<S77>/Out1'
     *  Sum: '<S13>/Add'
     *  Sum: '<S13>/Add4'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    if (localDW->UnitDelay_DSTATE + 0.01F >= 1.0F) {
      /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem' incorporates:
       *  ActionPort: '<S77>/Action Port'
       */
      rtb_DiscreteTimeIntegrator = 1.0F;

      /* End of Outputs for SubSystem: '<S13>/If Action Subsystem' */
    } else {
      rtb_DiscreteTimeIntegrator = localDW->UnitDelay_DSTATE + 0.01F;
    }

    localDW->Merge1 = 0.5F - rtb_DiscreteTimeIntegrator * 0.2F;

    /* End of If: '<S13>/If' */

    /* Merge: '<S2>/Merge' incorporates:
     *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator1'
     */
    localDW->Merge = localDW->DiscreteTimeIntegrator1_DSTATE;

    /* Update for UnitDelay: '<S13>/Unit Delay' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Sum: '<S13>/Add'
     */
    localDW->UnitDelay_DSTATE += 0.01F;

    /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S13>/Gain'
     *  Gain: '<S13>/Gain1'
     */
    localDW->DiscreteTimeIntegrator1_DSTATE += JIE_MEI_KANG_PARAMETER.Pn *
      31.4159279F * 0.0001F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* Merge: '<S2>/Merge' incorporates:
     *  SignalConversion generated from: '<S12>/theta_Close'
     *  UnitDelay: '<S2>/Unit Delay1'
     */
    localDW->Merge = MID_parameter.THETA;

    /* Merge: '<S2>/Merge1' incorporates:
     *  SignalConversion generated from: '<S12>/iq_CloseRef'
     */
    localDW->Merge1 = rtu_iq_ref;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case1' */

  /* Math: '<S2>/Mod1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_DiscreteTimeIntegrator = rt_modf_snf(localDW->Merge, 6.28318548F);

  /* Trigonometry: '<S82>/ReplicaOfSource' */
  rtb_Add_h = sinf(rtb_DiscreteTimeIntegrator);

  /* Trigonometry: '<S81>/ReplicaOfSource' */
  rtb_DiscreteTimeIntegrator = cosf(rtb_DiscreteTimeIntegrator);

  /* Outputs for Atomic SubSystem: '<S2>/In_park' */
  /* Constant: '<S2>/Constant5' incorporates:
   *  Constant: '<S2>/Constant2'
   *  DataTypeConversion: '<S81>/DTC_output_1'
   *  DataTypeConversion: '<S82>/DTC_output_1'
   */
  In_park(0.0F, 1.0F, rtb_Add_h, rtb_DiscreteTimeIntegrator);

  /* End of Outputs for SubSystem: '<S2>/In_park' */

  /* Outputs for Atomic SubSystem: '<S2>/SVPWM' */
  SVPWM(MID_parameter.ualpha, MID_parameter.ubeta, rtu_VDC,
        rtyyy_Tcmp1Tcmp2Tcmp3);

  /* End of Outputs for SubSystem: '<S2>/SVPWM' */

  /* Outputs for Atomic SubSystem: '<S2>/Clark' */
  Clark(rtu_ia, rtu_ib, rtu_ic);

  /* End of Outputs for SubSystem: '<S2>/Clark' */

  /* Outputs for Atomic SubSystem: '<S2>/FLUX_OB' */
  /* SignalConversion generated from: '<S2>/FLUX_OB' */
  FLUX_OB(MID_parameter.ialpha, MID_parameter.ibeta, MID_parameter.ualpha,
          MID_parameter.ubeta, &(MID_parameter.THETA), &(MID_parameter.wm),
          &localDW->FLUX_OB_k);

  /* End of Outputs for SubSystem: '<S2>/FLUX_OB' */

  /* Outputs for Atomic SubSystem: '<S2>/Park' */
  /* DataTypeConversion: '<S82>/DTC_output_1' incorporates:
   *  DataTypeConversion: '<S81>/DTC_output_1'
   */
  Park(MID_parameter.ialpha, MID_parameter.ibeta, rtb_Add_h,
       rtb_DiscreteTimeIntegrator, &rtb_Add_h, &rtb_DiscreteTimeIntegrator);

  /* End of Outputs for SubSystem: '<S2>/Park' */

  /* Outputs for Atomic SubSystem: '<S2>/idq_Controller' */
  idq_Controller(rtb_Add_h, rtb_DiscreteTimeIntegrator, localDW->Merge1,
                 &rtb_Saturation_h, &rtb_Saturation, &localDW->idq_Controller_g);

  /* End of Outputs for SubSystem: '<S2>/idq_Controller' */
}

/* Model step function */
void FOC_Model_step(void)
{
  real32_T rtb_PWM_HalfPeriod[3];
  real32_T Integrator;
  real32_T rtb_DeadZone;
  real32_T rtb_Sum1;
  uint32_T Speed_loop_ELAPS_T;
  int8_T tmp_0;
  int8_T tmp_1;
  boolean_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/FOC_Model' */
  /* RateTransition: '<S1>/Rate Transition3' incorporates:
   *  RateTransition: '<S1>/Rate Transition'
   */
  tmp = (rtM->Timing.TaskCounters.TID[1] == 0);
  if (tmp) {
    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* Outputs for Atomic SubSystem: '<S1>/Curr_loop' */
  /* Inport: '<Root>/ia' incorporates:
   *  Inport: '<Root>/MotorOnOff'
   *  Inport: '<Root>/VDC'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   */
  Curr_loop(rtU.ia, rtU.ib, rtU.ic, rtU.MotorOnOff, rtDW.RateTransition3,
            rtU.VDC, rtb_PWM_HalfPeriod, &rtDW.RestsSingal, &rtDW.Curr_loop_d);

  /* End of Outputs for SubSystem: '<S1>/Curr_loop' */

  /* Outputs for Atomic SubSystem: '<S1>/LPF' */
  /* ManualSwitch: '<S1>/Manual Switch' */
  rtb_Sum1 = SMO_LPF(MID_parameter.wm, &rtDW.LPF);

  /* End of Outputs for SubSystem: '<S1>/LPF' */

  /* RateTransition: '<S1>/Rate Transition' */
  if (tmp) {
    /* S-Function (fcgen): '<S3>/ReplicaOfSource' incorporates:
     *  SubSystem: '<S1>/Speed_loop'
     */
    if (rtDW.Speed_loop_RESET_ELAPS_T) {
      Speed_loop_ELAPS_T = 0U;
    } else {
      Speed_loop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.Speed_loop_PREV_T;
    }

    rtDW.Speed_loop_PREV_T = rtM->Timing.clockTick1;
    rtDW.Speed_loop_RESET_ELAPS_T = false;

    /* Sum: '<S5>/Sum2' incorporates:
     *  Inport: '<Root>/Speed_ref'
     */
    rtb_Sum1 = rtU.Speed_ref - rtb_Sum1;

    /* DiscreteIntegrator: '<S230>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S230>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE;
    } else if ((rtDW.RestsSingal > 0.0F) && (rtDW.Integrator_PrevResetState <= 0))
    {
      /* DiscreteIntegrator: '<S230>/Integrator' */
      Integrator = 0.0F;
    } else {
      /* DiscreteIntegrator: '<S230>/Integrator' */
      Integrator = 0.001F * (real32_T)Speed_loop_ELAPS_T
        * rtDW.Integrator_PREV_U + rtDW.Integrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S230>/Integrator' */

    /* Sum: '<S239>/Sum' incorporates:
     *  Gain: '<S235>/Proportional Gain'
     */
    rtb_DeadZone = spd_kpki.spd_kp * rtb_Sum1 + Integrator;

    /* Saturate: '<S237>/Saturation' incorporates:
     *  DeadZone: '<S222>/DeadZone'
     */
    if (rtb_DeadZone > 3.0F) {
      /* Update for RateTransition: '<S1>/Rate Transition3' incorporates:
       *  Saturate: '<S237>/Saturation'
       */
      rtDW.RateTransition3_Buffer0 = 3.0F;
      rtb_DeadZone -= 3.0F;
    } else {
      if (rtb_DeadZone < -3.0F) {
        /* Update for RateTransition: '<S1>/Rate Transition3' incorporates:
         *  Saturate: '<S237>/Saturation'
         */
        rtDW.RateTransition3_Buffer0 = -3.0F;
      } else {
        /* Update for RateTransition: '<S1>/Rate Transition3' incorporates:
         *  Saturate: '<S237>/Saturation'
         */
        rtDW.RateTransition3_Buffer0 = rtb_DeadZone;
      }

      if (rtb_DeadZone >= -3.0F) {
        rtb_DeadZone = 0.0F;
      } else {
        rtb_DeadZone -= -3.0F;
      }
    }

    /* End of Saturate: '<S237>/Saturation' */

    /* Gain: '<S227>/Integral Gain' */
    rtb_Sum1 *= spd_kpki.spd_ki;

    /* Update for DiscreteIntegrator: '<S230>/Integrator' incorporates:
     *  RateTransition: '<S1>/Rate Transition2'
     */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE = Integrator;
    if (rtDW.RestsSingal > 0.0F) {
      rtDW.Integrator_PrevResetState = 1;
    } else if (rtDW.RestsSingal < 0.0F) {
      rtDW.Integrator_PrevResetState = -1;
    } else if (rtDW.RestsSingal == 0.0F) {
      rtDW.Integrator_PrevResetState = 0;
    } else {
      rtDW.Integrator_PrevResetState = 2;
    }

    /* Switch: '<S220>/Switch2' incorporates:
     *  Constant: '<S220>/Clamping_zero'
     *  Constant: '<S220>/Constant3'
     *  Constant: '<S220>/Constant4'
     *  RelationalOperator: '<S220>/fix for DT propagation issue1'
     */
    if (rtb_Sum1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    /* Switch: '<S220>/Switch1' incorporates:
     *  Constant: '<S220>/Clamping_zero'
     *  Constant: '<S220>/Constant'
     *  Constant: '<S220>/Constant2'
     *  RelationalOperator: '<S220>/fix for DT propagation issue'
     */
    if (rtb_DeadZone > 0.0F) {
      tmp_1 = 1;
    } else {
      tmp_1 = -1;
    }

    /* Switch: '<S220>/Switch' incorporates:
     *  Constant: '<S220>/Clamping_zero'
     *  Logic: '<S220>/AND3'
     *  RelationalOperator: '<S220>/Equal1'
     *  RelationalOperator: '<S220>/Relational Operator'
     *  Switch: '<S220>/Switch1'
     *  Switch: '<S220>/Switch2'
     */
    if ((rtb_DeadZone != 0.0F) && (tmp_1 == tmp_0)) {
      /* Update for DiscreteIntegrator: '<S230>/Integrator' incorporates:
       *  Constant: '<S220>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S230>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_Sum1;
    }

    /* End of Switch: '<S220>/Switch' */
    /* End of Outputs for S-Function (fcgen): '<S3>/ReplicaOfSource' */
  }

  /* End of Outputs for SubSystem: '<Root>/FOC_Model' */

  /* Outport: '<Root>/Tcmp1' */
  rtY.Tcmp1 = rtb_PWM_HalfPeriod[0];

  /* Outport: '<Root>/Tcmp2' */
  rtY.Tcmp2 = rtb_PWM_HalfPeriod[1];

  /* Outport: '<Root>/Tcmp3' */
  rtY.Tcmp3 = rtb_PWM_HalfPeriod[2];
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void FOC_Model_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/FOC_Model' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/Curr_loop' */
  Curr_loop_Init(&rtDW.RestsSingal, &rtDW.Curr_loop_d);

  /* End of SystemInitialize for SubSystem: '<S1>/Curr_loop' */

  /* SystemInitialize for S-Function (fcgen): '<S3>/ReplicaOfSource' incorporates:
   *  SubSystem: '<S1>/Speed_loop'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S230>/Integrator' */
  rtDW.Integrator_PrevResetState = 2;

  /* End of SystemInitialize for S-Function (fcgen): '<S3>/ReplicaOfSource' */
  /* End of SystemInitialize for SubSystem: '<Root>/FOC_Model' */

  /* Enable for Atomic SubSystem: '<Root>/FOC_Model' */
  /* Enable for S-Function (fcgen): '<S3>/ReplicaOfSource' incorporates:
   *  SubSystem: '<S1>/Speed_loop'
   */
  rtDW.Speed_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S230>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for S-Function (fcgen): '<S3>/ReplicaOfSource' */
  /* End of Enable for SubSystem: '<Root>/FOC_Model' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
