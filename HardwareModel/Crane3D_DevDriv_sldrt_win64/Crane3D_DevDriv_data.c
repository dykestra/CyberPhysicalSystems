/*
 * Crane3D_DevDriv_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Crane3D_DevDriv".
 *
 * Model version              : 1.179
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Nov 30 11:37:48 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Crane3D_DevDriv.h"
#include "Crane3D_DevDriv_private.h"

/* Block parameters (auto storage) */
P_Crane3D_DevDriv_T Crane3D_DevDriv_P = {
  0.3,                                 /* Variable: Dx
                                        * Referenced by: '<S6>/Derivative Gain'
                                        */
  0.3,                                 /* Variable: Dy
                                        * Referenced by: '<S7>/Derivative Gain'
                                        */
  0.3,                                 /* Variable: Ix
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  0.3,                                 /* Variable: Iy
                                        * Referenced by: '<S7>/Integral Gain'
                                        */
  3.0,                                 /* Variable: Px
                                        * Referenced by: '<S6>/Proportional Gain'
                                        */
  3.0,                                 /* Variable: Py
                                        * Referenced by: '<S7>/Proportional Gain'
                                        */

  /*  Variable: waypoints
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0, 4.0, 6.0, 34.0, 43.0, 44.0, 44.0, 46.0, 0.0, 28.0, 32.0, 30.0,
    30.0, 21.0, 21.0, 36.0, 38.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0,
    35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0, 35.0 },
  -1.0,                                /* Mask Parameter: PIDController_LowerSaturationLimit
                                        * Referenced by: '<S6>/Saturate'
                                        */
  -1.0,                                /* Mask Parameter: PIDController2_LowerSaturationLimit
                                        * Referenced by: '<S7>/Saturate'
                                        */
  30.0,                                /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S7>/Filter Coefficient'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_UpperSaturationLimit
                                        * Referenced by: '<S6>/Saturate'
                                        */
  1.0,                                 /* Mask Parameter: PIDController2_UpperSaturationLimit
                                        * Referenced by: '<S7>/Saturate'
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S3>/Encoder'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S3>/Encoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Encoder 500PPR'
                                        */
  5.8157313559321858E-5,               /* Expression: Crane3D_ScaleCoeff( 1 )
                                        * Referenced by: '<S3>/X Scale'
                                        */
  5.8157313559321858E-5,               /* Expression: Crane3D_ScaleCoeff( 2 )
                                        * Referenced by: '<S3>/Y Scale'
                                        */
  0.001534,                            /* Expression: Crane3D_ScaleCoeff( 4 )
                                        * Referenced by: '<S3>/X Angle Scale'
                                        */
  0.001534,                            /* Expression: Crane3D_ScaleCoeff( 5 )
                                        * Referenced by: '<S3>/Y Angle Scale'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S6>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S6>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S7>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S7>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S3>/PWM'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S3>/PWM'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Saturation'
                                        */

  /*  Computed Parameter: LimitFlag_P1_Size
   * Referenced by: '<S3>/LimitFlag'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitFlag'
                                        */

  /*  Computed Parameter: LimitFlag_P2_Size
   * Referenced by: '<S3>/LimitFlag'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/LimitFlag'
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S3>/LimitFlagSource'
   */
  { 1.0, 1.0, 1.0 },

  /*  Expression: Crane3D_RangeBit
   * Referenced by: '<S3>/LimitSource'
   */
  { 134.0, 167.0, 388.0 },

  /*  Computed Parameter: SetLimit_P1_Size
   * Referenced by: '<S3>/SetLimit'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/SetLimit'
                                        */

  /*  Computed Parameter: SetLimit_P2_Size
   * Referenced by: '<S3>/SetLimit'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/SetLimit'
                                        */

  /*  Computed Parameter: LimitSwitch_P1_Size
   * Referenced by: '<S3>/LimitSwitch'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */

  /*  Computed Parameter: LimitSwitch_P2_Size
   * Referenced by: '<S3>/LimitSwitch'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S3>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S3>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  60.0,                                /* Expression: 60
                                        * Referenced by: '<S3>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S3>/ResetEncoder'
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S3>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */

  /*  Expression: [0 0 0 0 0]
   * Referenced by: '<S3>/ResetSource'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ResetSwitchFlag_P1_Size
   * Referenced by: '<S3>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P2_Size
   * Referenced by: '<S3>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */

  /*  Expression: [ 0 0 0 ]
   * Referenced by: '<S3>/ResetSwitchFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S3>/ThermFlag '
   */
  { 1.0, 1.0 },
  12288.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S3>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S3>/ThermFlag '
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S3>/ThermFlagSource'
   */
  { 1.0, 1.0, 1.0 }
};
