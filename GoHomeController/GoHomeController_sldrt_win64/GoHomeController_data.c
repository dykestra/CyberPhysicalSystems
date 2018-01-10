/*
 * GoHomeController_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GoHomeController".
 *
 * Model version              : 1.326
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Wed Jan 10 17:52:06 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GoHomeController.h"
#include "GoHomeController_private.h"

/* Block parameters (auto storage) */
P_GoHomeController_T GoHomeController_P = {
  0,                                   /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S12>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */

  /*  Computed Parameter: TransferFcn3_A
   * Referenced by: '<S2>/Transfer Fcn3'
   */
  { -38.888888888888893, -555.55555555555554 },

  /*  Computed Parameter: TransferFcn3_C
   * Referenced by: '<S2>/Transfer Fcn3'
   */
  { 555.55555555555554, 0.0 },

  /*  Computed Parameter: TransferFcn1_A
   * Referenced by: '<S2>/Transfer Fcn1'
   */
  { -38.888888888888893, -555.55555555555554 },

  /*  Computed Parameter: TransferFcn1_C
   * Referenced by: '<S2>/Transfer Fcn1'
   */
  { 555.55555555555554, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Y Ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Y_Dot Ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/X Ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/X_Dot Ref'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<S3>/Alpha Ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Alpha_Dot Ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Beta Ref'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Beta_Dot Ref'
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S7>/Encoder'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S7>/Encoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Encoder 500PPR'
                                        */
  5.8157313559321858E-5,               /* Expression: Crane3D_ScaleCoeff( 2 )
                                        * Referenced by: '<S7>/Y Scale'
                                        */

  /*  Expression: [0 0 0 0 0]
   * Referenced by: '<S8>/Unit Delay'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 },
  5.8157313559321858E-5,               /* Expression: Crane3D_ScaleCoeff( 1 )
                                        * Referenced by: '<S7>/X Scale'
                                        */
  2.2150329724344985E-5,               /* Expression: Crane3D_ScaleCoeff( 3 )
                                        * Referenced by: '<S7>/Z Scale'
                                        */
  0.001534,                            /* Expression: Crane3D_ScaleCoeff( 4 )
                                        * Referenced by: '<S7>/X Angle Scale'
                                        */
  0.001534,                            /* Expression: Crane3D_ScaleCoeff( 5 )
                                        * Referenced by: '<S7>/Y Angle Scale'
                                        */
  100.0,                               /* Expression: 1/Ts
                                        * Referenced by: '<S8>/GainZ1'
                                        */

  /*  Expression: filtNum
   * Referenced by: '<S8>/Derivative Filter'
   */
  { 9.6014904266071957E-6, 0.00015362384682571513, 0.0011521788511928634,
    0.00537683463890003, 0.017474712576425095, 0.041939310183420231,
    0.076888735336270428, 0.10984105048038632, 0.12357118179043461,
    0.10984105048038632, 0.076888735336270428, 0.041939310183420231,
    0.017474712576425095, 0.00537683463890003, 0.0011521788511928634,
    0.00015362384682571513, 9.6014904266071957E-6 },

  /*  Expression: filtDen
   * Referenced by: '<S8>/Derivative Filter'
   */
  { 1.0, -2.5774735647030704, 5.1684527974686638, -6.8368951784546423,
    7.3843862547692289, -6.2236116990371233, 4.3710352131168282,
    -2.5031815542344531, 1.1967707878575957, -0.46926551656005727,
    0.15133769826200552, -0.039232653653556784, 0.0080405540703447614,
    -0.0012494168480357635, 0.00013907249955162466, -9.8530363842468951E-6,
    3.3508123367672324E-7 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Derivative Filter'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S5>/Gain1'
                                        */
  1.5707963267948966,                  /* Expression: pi/2
                                        * Referenced by: '<S5>/Bias'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S5>/Gain'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */

  /*  Expression: K
   * Referenced by: '<S1>/Gain'
   */
  { 0.865125, 0.0, 0.0, 0.0, 0.0, 0.87025, 0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0,
    -8.0, 0.0, 0.0, -0.1562, 0.0, 0.0, -0.158 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Saturation'
                                        */

  /*  Computed Parameter: LimitSwitch_P1_Size
   * Referenced by: '<S7>/LimitSwitch'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/LimitSwitch'
                                        */

  /*  Computed Parameter: LimitSwitch_P2_Size
   * Referenced by: '<S7>/LimitSwitch'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/LimitSwitch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/LimitSwitchGain'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S7>/PWM'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S7>/PWM'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Saturation'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S7>/ResetEncoder'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S7>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/ResetEncoder'
                                        */

  /*  Computed Parameter: LimitFlag_P1_Size
   * Referenced by: '<S7>/LimitFlag'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/LimitFlag'
                                        */

  /*  Computed Parameter: LimitFlag_P2_Size
   * Referenced by: '<S7>/LimitFlag'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/LimitFlag'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S7>/LimitFlagSource'
   */
  { 1.0, 1.0, 1.0 },

  /*  Expression: Crane3D_RangeBit
   * Referenced by: '<S7>/LimitSource'
   */
  { 134.0, 167.0, 388.0 },

  /*  Computed Parameter: SetLimit_P1_Size
   * Referenced by: '<S7>/SetLimit'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/SetLimit'
                                        */

  /*  Computed Parameter: SetLimit_P2_Size
   * Referenced by: '<S7>/SetLimit'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/SetLimit'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S7>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S7>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/PWMPrescaler'
                                        */
  60.0,                                /* Expression: 60
                                        * Referenced by: '<S7>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P1_Size
   * Referenced by: '<S7>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/ResetSwitchFlag '
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P2_Size
   * Referenced by: '<S7>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/ResetSwitchFlag '
                                        */

  /*  Expression: [ 0 0 0 ]
   * Referenced by: '<S7>/ResetSwitchFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S7>/ThermFlag '
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S7>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S7>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S7>/ThermFlag '
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S7>/ThermFlagSource'
   */
  { 1.0, 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S4>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  200.0,                               /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  100.0,                               /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  0                                    /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S13>/Constant'
                                        */
};
