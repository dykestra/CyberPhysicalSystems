/*
 * Crane3D_DevDriv_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Crane3D_DevDriv".
 *
 * Model version              : 1.234
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Dec 18 17:45:09 2017
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
  0.2,                                 /* Variable: DC1x
                                        * Referenced by: '<S11>/Derivative Gain'
                                        */
  0.2,                                 /* Variable: DC1y
                                        * Referenced by: '<S16>/Derivative Gain'
                                        */
  0.3,                                 /* Variable: DC2x
                                        * Referenced by: '<S12>/Derivative Gain'
                                        */
  0.3,                                 /* Variable: DC2y
                                        * Referenced by: '<S17>/Derivative Gain'
                                        */
  0.4,                                 /* Variable: DC3x
                                        * Referenced by: '<S13>/Derivative Gain'
                                        */
  0.4,                                 /* Variable: DC3y
                                        * Referenced by: '<S15>/Derivative Gain'
                                        */
  0.5,                                 /* Variable: DC4x
                                        * Referenced by: '<S14>/Derivative Gain'
                                        */
  0.5,                                 /* Variable: DC4y
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  0.08,                                /* Variable: IC1x
                                        * Referenced by: '<S11>/Integral Gain'
                                        */
  0.08,                                /* Variable: IC1y
                                        * Referenced by: '<S16>/Integral Gain'
                                        */
  0.3,                                 /* Variable: IC2x
                                        * Referenced by: '<S12>/Integral Gain'
                                        */
  0.3,                                 /* Variable: IC2y
                                        * Referenced by: '<S17>/Integral Gain'
                                        */
  0.4,                                 /* Variable: IC3x
                                        * Referenced by: '<S13>/Integral Gain'
                                        */
  0.4,                                 /* Variable: IC3y
                                        * Referenced by: '<S15>/Integral Gain'
                                        */
  0.6,                                 /* Variable: IC4x
                                        * Referenced by: '<S14>/Integral Gain'
                                        */
  0.6,                                 /* Variable: IC4y
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  1.2,                                 /* Variable: PC1x
                                        * Referenced by: '<S11>/Proportional Gain'
                                        */
  1.2,                                 /* Variable: PC1y
                                        * Referenced by: '<S16>/Proportional Gain'
                                        */
  2.0,                                 /* Variable: PC2x
                                        * Referenced by: '<S12>/Proportional Gain'
                                        */
  2.0,                                 /* Variable: PC2y
                                        * Referenced by: '<S17>/Proportional Gain'
                                        */
  2.5,                                 /* Variable: PC3x
                                        * Referenced by: '<S13>/Proportional Gain'
                                        */
  2.5,                                 /* Variable: PC3y
                                        * Referenced by: '<S15>/Proportional Gain'
                                        */
  2.7,                                 /* Variable: PC4x
                                        * Referenced by: '<S14>/Proportional Gain'
                                        */
  2.7,                                 /* Variable: PC4y
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */

  /*  Variable: waypoints
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 6.0, 9.0, 12.0, 15.0, 16.0, 17.0, 19.0, 27.0, 35.0, 43.0, 44.0, 37.0,
    35.0, 34.0, 30.0, 26.0, 9.0, 8.0, 7.0, 0.0, 0.0, 3.0, 3.0, 6.0, 6.0, 7.0,
    7.0, 15.0, 7.0, 7.0, 8.0, 7.0, 9.0, 9.0, 13.0, 13.0, 30.0, 30.0, 31.0, 46.0,
    46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0, 46.0,
    46.0, 46.0, 46.0, 24.0, 24.0, 24.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0,
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 46.0, 46.0, 46.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Variable: xRange
   * Referenced by: '<Root>/X_range'
   */
  { 0.0, 0.52 },

  /*  Variable: yRange
   * Referenced by: '<Root>/Y_range '
   */
  { 0.0, 0.62 },
  30.0,                                /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S11>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S12>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S13>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController3_N
                                        * Referenced by: '<S14>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController5_N
                                        * Referenced by: '<S16>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController6_N
                                        * Referenced by: '<S17>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController4_N
                                        * Referenced by: '<S15>/Filter Coefficient'
                                        */
  30.0,                                /* Mask Parameter: PIDController7_N
                                        * Referenced by: '<S18>/Filter Coefficient'
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
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S11>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S12>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S13>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S13>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S14>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S14>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S16>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S16>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S17>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S17>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S15>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S15>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S18>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S18>/Filter'
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
