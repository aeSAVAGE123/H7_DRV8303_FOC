/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FOC_Model.h
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

#ifndef FOC_Model_h_
#define FOC_Model_h_
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

#include "FOC_Model_types.h"
#include "idq_Controller.h"
#include "FLUX_OB.h"
#include "SMO_LPF.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals and states (default storage) for system '<S1>/Curr_loop' */
typedef struct {
  DW_idq_Controller idq_Controller_g;  /* '<S2>/idq_Controller' */
  DW_FLUX_OB FLUX_OB_k;                /* '<S2>/FLUX_OB' */
  real32_T Merge;                      /* '<S2>/Merge' */
  real32_T Merge1;                     /* '<S2>/Merge1' */
  real32_T ZReset;                     /* '<S2>/Chart1' */
  real32_T UnitDelay_DSTATE;           /* '<S13>/Unit Delay' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S13>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S11>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_j;/* '<S11>/Discrete-Time Integrator1' */
  real32_T cnt;                        /* '<S2>/Chart1' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S11>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S11>/Discrete-Time Integrator1' */
  uint8_T is_active_c7_FOC_Model;      /* '<S2>/Chart1' */
  uint8_T is_c7_FOC_Model;             /* '<S2>/Chart1' */
} DW_Curr_loop;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_SMO_LPF LPF;                      /* '<S1>/LPF' */
  DW_Curr_loop Curr_loop_d;            /* '<S1>/Curr_loop' */
  real32_T RateTransition3;            /* '<S1>/Rate Transition3' */
  real32_T RestsSingal;                /* '<S2>/Chart1' */
  real32_T Integrator_DSTATE;          /* '<S230>/Integrator' */
  real32_T RateTransition3_Buffer0;    /* '<S1>/Rate Transition3' */
  real32_T Integrator_PREV_U;          /* '<S230>/Integrator' */
  uint32_T Speed_loop_PREV_T;          /* '<S1>/Speed_loop' */
  int8_T Integrator_PrevResetState;    /* '<S230>/Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S230>/Integrator' */
  boolean_T Speed_loop_RESET_ELAPS_T;  /* '<S1>/Speed_loop' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S10>/Constant1'
   *   '<S11>/Constant2'
   *   '<S13>/Constant2'
   *   '<S16>/Constant'
   *   '<S20>/Gain2'
   */
  real32_T pooled2;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S16>/PWM_HalfPeriod'
   *   '<S64>/Saturation'
   */
  real32_T pooled4;

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S16>/Gain'
   */
  real32_T Gain_Gain_j;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T Speed_ref;                  /* '<Root>/Speed_ref' */
  real_T MotorOnOff;                   /* '<Root>/MotorOnOff' */
  real32_T VDC;                        /* '<Root>/VDC' */
  real32_T Wm;                         /* '<Root>/Wm' */
  real32_T Theta;                      /* '<Root>/Theta' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Tcmp1;                      /* '<Root>/Tcmp1' */
  real32_T Tcmp2;                      /* '<Root>/Tcmp2' */
  real32_T Tcmp3;                      /* '<Root>/Tcmp3' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct FLU_OBS_tag {
  real32_T FLU;                        /* Referenced by: '<S20>/Constant1' */
} FLU_OBS_type;

typedef struct JIE_MEI_KANG_PARAMETE_tag {
  real32_T FLUX;                       /* Referenced by:
                                        * '<S20>/Constant'
                                        * '<S20>/Gain5'
                                        */
} JIE_MEI_KANG_PARAMETE_type;

typedef struct JIE_MEI_KANG_PARAMETER_tag {
  real32_T L;                          /* Referenced by:
                                        * '<S20>/Gain1'
                                        * '<S20>/Gain4'
                                        */
  real32_T Pn;                         /* Referenced by:
                                        * '<S8>/Gain'
                                        * '<S11>/Gain'
                                        * '<S13>/Gain'
                                        */
  real32_T Rs;                         /* Referenced by: '<S20>/Gain' */
} JIE_MEI_KANG_PARAMETER_type;

typedef struct MID_parameter_tag {
  real32_T THETA;                      /* '<S2>/FLUX_OB' */
  real32_T wm;                         /* '<S2>/FLUX_OB' */
  real32_T state;                      /* '<S2>/Chart1' */
  real32_T ualpha;                     /* '<S14>/Add' */
  real32_T ubeta;                      /* '<S14>/Add1' */
  real32_T ialpha;                     /* '<S7>/Add1' */
  real32_T ibeta;                      /* '<S7>/Gain2' */
} MID_parameter_type;

typedef struct Tp_loop_tag {
  real32_T T;                          /* Referenced by: '<S20>/Gain3' */
} Tp_loop_type;

typedef struct curr_kpki_tag {
  real32_T curr_d_ki;                  /* Referenced by: '<S18>/Constant4' */
  real32_T curr_d_kp;                  /* Referenced by: '<S18>/Constant3' */
} curr_kpki_type;

typedef struct spd_kpki_tag {
  real32_T spd_ki;                   /* Referenced by: '<S227>/Integral Gain' */
  real32_T spd_kp;               /* Referenced by: '<S235>/Proportional Gain' */
} spd_kpki_type;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern FLU_OBS_type FLU_OBS;
extern JIE_MEI_KANG_PARAMETE_type JIE_MEI_KANG_PARAMETE;
extern JIE_MEI_KANG_PARAMETER_type JIE_MEI_KANG_PARAMETER;
extern MID_parameter_type MID_parameter;
extern Tp_loop_type Tp_loop;
extern curr_kpki_type curr_kpki;
extern spd_kpki_type spd_kpki;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S19>/Scope' : Unused code path elimination
 * Block '<S19>/Scope2' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S20>/Scope' : Unused code path elimination
 * Block '<S20>/Scope2' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S16>/Scope' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope13' : Unused code path elimination
 * Block '<S2>/Scope14' : Unused code path elimination
 * Block '<S2>/Scope15' : Unused code path elimination
 * Block '<S2>/Scope3' : Unused code path elimination
 * Block '<S2>/id' : Unused code path elimination
 * Block '<S18>/Scope' : Unused code path elimination
 * Block '<S2>/iq' : Unused code path elimination
 * Block '<S75>/DTC_input_1' : Eliminate redundant data type conversion
 * Block '<S75>/DTC_output_1' : Eliminate redundant data type conversion
 * Block '<S76>/DTC_input_1' : Eliminate redundant data type conversion
 * Block '<S76>/DTC_output_1' : Eliminate redundant data type conversion
 * Block '<S2>/Manual Switch2' : Eliminated due to constant selection input
 * Block '<S81>/DTC_input_1' : Eliminate redundant data type conversion
 * Block '<S82>/DTC_input_1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Copy_of_jiemeikang/FOC_Model')    - opens subsystem Copy_of_jiemeikang/FOC_Model
 * hilite_system('Copy_of_jiemeikang/FOC_Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Copy_of_jiemeikang'
 * '<S1>'   : 'Copy_of_jiemeikang/FOC_Model'
 * '<S2>'   : 'Copy_of_jiemeikang/FOC_Model/Curr_loop'
 * '<S3>'   : 'Copy_of_jiemeikang/FOC_Model/Function-Call Generator'
 * '<S4>'   : 'Copy_of_jiemeikang/FOC_Model/LPF'
 * '<S5>'   : 'Copy_of_jiemeikang/FOC_Model/Speed_loop'
 * '<S6>'   : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/Chart1'
 * '<S7>'   : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/Clark'
 * '<S8>'   : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB'
 * '<S9>'   : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem'
 * '<S10>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem1'
 * '<S11>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem2'
 * '<S12>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem3'
 * '<S13>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem4'
 * '<S14>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/In_park'
 * '<S15>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/Park'
 * '<S16>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/SVPWM'
 * '<S17>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/Subsystem'
 * '<S18>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller'
 * '<S19>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL'
 * '<S20>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/Subsystem3'
 * '<S21>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller'
 * '<S22>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Subsystem'
 * '<S23>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Anti-windup'
 * '<S24>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/D Gain'
 * '<S25>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/External Derivative'
 * '<S26>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Filter'
 * '<S27>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Filter ICs'
 * '<S28>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/I Gain'
 * '<S29>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Ideal P Gain'
 * '<S30>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S31>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Integrator'
 * '<S32>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Integrator ICs'
 * '<S33>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/N Copy'
 * '<S34>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/N Gain'
 * '<S35>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/P Copy'
 * '<S36>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Parallel P Gain'
 * '<S37>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Reset Signal'
 * '<S38>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Saturation'
 * '<S39>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Saturation Fdbk'
 * '<S40>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Sum'
 * '<S41>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Sum Fdbk'
 * '<S42>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tracking Mode'
 * '<S43>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tracking Mode Sum'
 * '<S44>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tsamp - Integral'
 * '<S45>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tsamp - Ngain'
 * '<S46>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/postSat Signal'
 * '<S47>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/preInt Signal'
 * '<S48>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/preSat Signal'
 * '<S49>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S50>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/D Gain/Disabled'
 * '<S51>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/External Derivative/Disabled'
 * '<S52>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Filter/Disabled'
 * '<S53>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Filter ICs/Disabled'
 * '<S54>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S55>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S56>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S57>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Integrator/Discrete'
 * '<S58>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S59>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S60>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/N Gain/Disabled'
 * '<S61>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/P Copy/Disabled'
 * '<S62>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S63>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Reset Signal/Disabled'
 * '<S64>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Saturation/Enabled'
 * '<S65>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S66>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Sum/Sum_PI'
 * '<S67>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S68>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S69>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S70>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S71>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S72>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S73>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S74>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S75>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Subsystem/Cos'
 * '<S76>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/FLUX_OB/PLL/Subsystem/Sin'
 * '<S77>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem'
 * '<S78>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/If Action Subsystem4/If Action Subsystem1'
 * '<S79>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/SVPWM/InvClark'
 * '<S80>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/SVPWM/ei_t'
 * '<S81>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/Subsystem/Cos'
 * '<S82>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/Subsystem/Sin'
 * '<S83>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1'
 * '<S84>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2'
 * '<S85>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup'
 * '<S86>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/D Gain'
 * '<S87>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/External Derivative'
 * '<S88>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter'
 * '<S89>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter ICs'
 * '<S90>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/I Gain'
 * '<S91>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain'
 * '<S92>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S93>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator'
 * '<S94>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator ICs'
 * '<S95>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Copy'
 * '<S96>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Gain'
 * '<S97>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/P Copy'
 * '<S98>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Parallel P Gain'
 * '<S99>'  : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Reset Signal'
 * '<S100>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation'
 * '<S101>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation Fdbk'
 * '<S102>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum'
 * '<S103>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum Fdbk'
 * '<S104>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode'
 * '<S105>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode Sum'
 * '<S106>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Integral'
 * '<S107>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Ngain'
 * '<S108>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/postSat Signal'
 * '<S109>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preInt Signal'
 * '<S110>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preSat Signal'
 * '<S111>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S112>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S113>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S114>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/D Gain/Disabled'
 * '<S115>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/External Derivative/Disabled'
 * '<S116>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter/Disabled'
 * '<S117>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Filter ICs/Disabled'
 * '<S118>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/I Gain/External Parameters'
 * '<S119>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S120>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S121>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator/Discrete'
 * '<S122>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S123>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S124>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/N Gain/Disabled'
 * '<S125>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/P Copy/Disabled'
 * '<S126>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Parallel P Gain/External Parameters'
 * '<S127>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Reset Signal/Disabled'
 * '<S128>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation/Enabled'
 * '<S129>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S130>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum/Sum_PI'
 * '<S131>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S132>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S133>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S134>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S135>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S136>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S137>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preInt Signal/Internal PreInt'
 * '<S138>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller1/preSat Signal/Forward_Path'
 * '<S139>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup'
 * '<S140>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/D Gain'
 * '<S141>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/External Derivative'
 * '<S142>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter'
 * '<S143>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter ICs'
 * '<S144>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/I Gain'
 * '<S145>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain'
 * '<S146>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain Fdbk'
 * '<S147>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator'
 * '<S148>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator ICs'
 * '<S149>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Copy'
 * '<S150>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Gain'
 * '<S151>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/P Copy'
 * '<S152>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Parallel P Gain'
 * '<S153>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Reset Signal'
 * '<S154>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation'
 * '<S155>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation Fdbk'
 * '<S156>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum'
 * '<S157>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum Fdbk'
 * '<S158>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode'
 * '<S159>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode Sum'
 * '<S160>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Integral'
 * '<S161>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Ngain'
 * '<S162>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/postSat Signal'
 * '<S163>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preInt Signal'
 * '<S164>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preSat Signal'
 * '<S165>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S166>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S167>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S168>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/D Gain/Disabled'
 * '<S169>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/External Derivative/Disabled'
 * '<S170>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter/Disabled'
 * '<S171>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Filter ICs/Disabled'
 * '<S172>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/I Gain/External Parameters'
 * '<S173>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain/Passthrough'
 * '<S174>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S175>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator/Discrete'
 * '<S176>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Integrator ICs/Internal IC'
 * '<S177>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S178>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/N Gain/Disabled'
 * '<S179>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/P Copy/Disabled'
 * '<S180>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Parallel P Gain/External Parameters'
 * '<S181>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Reset Signal/Disabled'
 * '<S182>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation/Enabled'
 * '<S183>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Saturation Fdbk/Disabled'
 * '<S184>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum/Sum_PI'
 * '<S185>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Sum Fdbk/Disabled'
 * '<S186>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode/Disabled'
 * '<S187>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S188>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S189>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S190>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/postSat Signal/Forward_Path'
 * '<S191>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preInt Signal/Internal PreInt'
 * '<S192>' : 'Copy_of_jiemeikang/FOC_Model/Curr_loop/idq_Controller/PID Controller2/preSat Signal/Forward_Path'
 * '<S193>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3'
 * '<S194>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Anti-windup'
 * '<S195>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/D Gain'
 * '<S196>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/External Derivative'
 * '<S197>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Filter'
 * '<S198>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Filter ICs'
 * '<S199>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/I Gain'
 * '<S200>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain'
 * '<S201>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S202>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Integrator'
 * '<S203>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Integrator ICs'
 * '<S204>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/N Copy'
 * '<S205>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/N Gain'
 * '<S206>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/P Copy'
 * '<S207>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain'
 * '<S208>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Reset Signal'
 * '<S209>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Saturation'
 * '<S210>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk'
 * '<S211>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Sum'
 * '<S212>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk'
 * '<S213>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tracking Mode'
 * '<S214>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S215>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral'
 * '<S216>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S217>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/postSat Signal'
 * '<S218>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/preInt Signal'
 * '<S219>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/preSat Signal'
 * '<S220>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S221>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S222>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S223>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/D Gain/Disabled'
 * '<S224>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/External Derivative/Disabled'
 * '<S225>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Filter/Disabled'
 * '<S226>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S227>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/I Gain/Internal Parameters'
 * '<S228>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S229>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S230>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Integrator/Discrete'
 * '<S231>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S232>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S233>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/N Gain/Disabled'
 * '<S234>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/P Copy/Disabled'
 * '<S235>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S236>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S237>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Saturation/Enabled'
 * '<S238>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S239>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S240>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S241>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S242>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S243>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S244>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S245>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S246>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/preInt Signal/Internal PreInt'
 * '<S247>' : 'Copy_of_jiemeikang/FOC_Model/Speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
