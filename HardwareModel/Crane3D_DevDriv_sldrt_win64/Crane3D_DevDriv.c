/*
 * Crane3D_DevDriv.c
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
#include "Crane3D_DevDriv_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Crane3D_DevDriv_T Crane3D_DevDriv_B;

/* Continuous states */
X_Crane3D_DevDriv_T Crane3D_DevDriv_X;

/* Block states (auto storage) */
DW_Crane3D_DevDriv_T Crane3D_DevDriv_DW;

/* Real-time model */
RT_MODEL_Crane3D_DevDriv_T Crane3D_DevDriv_M_;
RT_MODEL_Crane3D_DevDriv_T *const Crane3D_DevDriv_M = &Crane3D_DevDriv_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Crane3D_DevDriv_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Crane3D_DevDriv_output();
  Crane3D_DevDriv_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Crane3D_DevDriv_output();
  Crane3D_DevDriv_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Crane3D_DevDriv_output();
  Crane3D_DevDriv_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  Crane3D_DevDriv_output();
  Crane3D_DevDriv_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  Crane3D_DevDriv_output();
  Crane3D_DevDriv_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Crane3D_DevDriv_output(void)
{
  real_T y;
  real_T rtb_Encoder500PPR[5];
  real_T rtb_yerror;
  int32_T i;
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_M)) {
    /* set solver stop time */
    if (!(Crane3D_DevDriv_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Crane3D_DevDriv_M->solverInfo,
                            ((Crane3D_DevDriv_M->Timing.clockTickH0 + 1) *
        Crane3D_DevDriv_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Crane3D_DevDriv_M->solverInfo,
                            ((Crane3D_DevDriv_M->Timing.clockTick0 + 1) *
        Crane3D_DevDriv_M->Timing.stepSize0 +
        Crane3D_DevDriv_M->Timing.clockTickH0 *
        Crane3D_DevDriv_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Crane3D_DevDriv_M)) {
    Crane3D_DevDriv_M->Timing.t[0] = rtsiGetT(&Crane3D_DevDriv_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  Crane3D_DevDriv_B.Clock = Crane3D_DevDriv_M->Timing.t[0];
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_M)) {
    /* Level2 S-Function Block: '<S3>/Encoder' (Crane3D_Encoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/Encoder 500PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder500PPR[i] = Crane3D_DevDriv_P.Encoder500PPR_Gain *
        Crane3D_DevDriv_B.Encoder[i];
    }

    /* End of Gain: '<S3>/Encoder 500PPR' */

    /* Gain: '<S3>/X Scale' */
    Crane3D_DevDriv_B.XScale = Crane3D_DevDriv_P.XScale_Gain *
      rtb_Encoder500PPR[0];

    /* Gain: '<S3>/Y Scale' */
    Crane3D_DevDriv_B.YScale = Crane3D_DevDriv_P.YScale_Gain *
      rtb_Encoder500PPR[1];

    /* Gain: '<S3>/X Angle Scale' */
    Crane3D_DevDriv_B.XAngleScale = Crane3D_DevDriv_P.XAngleScale_Gain *
      rtb_Encoder500PPR[3];

    /* Gain: '<S3>/Y Angle Scale' */
    Crane3D_DevDriv_B.YAngleScale = Crane3D_DevDriv_P.YAngleScale_Gain *
      rtb_Encoder500PPR[4];

    /* MATLAB Function: '<Root>/Convert Coordinates' */
    /* MATLAB Function 'Convert Coordinates': '<S2>:1' */
    /* % Assumptions */
    /* '<S2>:1:4' */
    /* % Obtain Measurements from sensors */
    /* '<S2>:1:9' */
    /* '<S2>:1:12' */
    /* '<S2>:1:13' */
    /* '<S2>:1:14' */
    /* '<S2>:1:16' */
    Crane3D_DevDriv_B.x_l = sin(Crane3D_DevDriv_B.XAngleScale +
      1.5707963267948966) * 0.3 * sin(Crane3D_DevDriv_B.YAngleScale) +
      Crane3D_DevDriv_B.XScale;

    /* '<S2>:1:17' */
    Crane3D_DevDriv_B.y_f = cos(Crane3D_DevDriv_B.XAngleScale +
      1.5707963267948966) * 0.3 + Crane3D_DevDriv_B.YScale;

    /* MATLAB Function: '<Root>/Select most convenient path' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* MATLAB Function 'Select most convenient path': '<S4>:1' */
    /* % Random default values - dont touch */
    /* '<S4>:1:9' */
    rtb_yerror = 0.252;

    /* '<S4>:1:10' */
    y = 0.365;
    if (Crane3D_DevDriv_DW.WP_Index <= 9.0) {
      /* '<S4>:1:11' */
      /* '<S4>:1:12' */
      rtb_yerror = Crane3D_DevDriv_P.waypoints[(int32_T)
        Crane3D_DevDriv_DW.WP_Index - 1] / 100.0;

      /* '<S4>:1:13' */
      y = Crane3D_DevDriv_P.waypoints[(int32_T)Crane3D_DevDriv_DW.WP_Index + 8] /
        100.0;

      /* '<S4>:1:14' */
      /* '<S4>:1:15' */
      /* '<S4>:1:16' */
      /* '<S4>:1:17' */
      /*     %% Crane arrived to point */
      if ((Crane3D_DevDriv_B.x_l <= rtb_yerror + 0.015) &&
          (Crane3D_DevDriv_B.x_l >= rtb_yerror - 0.015) &&
          (Crane3D_DevDriv_B.y_f <= y + 0.015) && (Crane3D_DevDriv_B.y_f >= y -
           0.015)) {
        /* '<S4>:1:20' */
        /* '<S4>:1:21' */
        Crane3D_DevDriv_DW.WP_Index++;
        if (Crane3D_DevDriv_DW.WP_Index > 9.0) {
          /* '<S4>:1:22' */
          /* '<S4>:1:23' */
          Crane3D_DevDriv_DW.WP_Index--;
        }
      }
    }

    Crane3D_DevDriv_B.x = rtb_yerror;
    Crane3D_DevDriv_B.y = y;

    /* End of MATLAB Function: '<Root>/Select most convenient path' */

    /* Sum: '<S5>/Sum' */
    rtb_yerror = Crane3D_DevDriv_B.x - Crane3D_DevDriv_B.x_l;

    /* Gain: '<S6>/Derivative Gain' */
    Crane3D_DevDriv_B.DerivativeGain = Crane3D_DevDriv_P.Dx * rtb_yerror;

    /* Gain: '<S6>/Integral Gain' */
    Crane3D_DevDriv_B.IntegralGain = Crane3D_DevDriv_P.Ix * rtb_yerror;

    /* Gain: '<S6>/Proportional Gain' */
    Crane3D_DevDriv_B.ProportionalGain = Crane3D_DevDriv_P.Px * rtb_yerror;

    /* Sum: '<S5>/Sum1' */
    rtb_yerror = Crane3D_DevDriv_B.y - Crane3D_DevDriv_B.y_f;

    /* Gain: '<S7>/Derivative Gain' */
    Crane3D_DevDriv_B.DerivativeGain_o = Crane3D_DevDriv_P.Dy * rtb_yerror;
  }

  /* Gain: '<S6>/Filter Coefficient' incorporates:
   *  Integrator: '<S6>/Filter'
   *  Sum: '<S6>/SumD'
   */
  Crane3D_DevDriv_B.FilterCoefficient = (Crane3D_DevDriv_B.DerivativeGain -
    Crane3D_DevDriv_X.Filter_CSTATE) * Crane3D_DevDriv_P.PIDController_N;

  /* Gain: '<S7>/Filter Coefficient' incorporates:
   *  Integrator: '<S7>/Filter'
   *  Sum: '<S7>/SumD'
   */
  Crane3D_DevDriv_B.FilterCoefficient_m = (Crane3D_DevDriv_B.DerivativeGain_o -
    Crane3D_DevDriv_X.Filter_CSTATE_g) * Crane3D_DevDriv_P.PIDController2_N;
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_M)) {
    /* Gain: '<S7>/Integral Gain' */
    Crane3D_DevDriv_B.IntegralGain_b = Crane3D_DevDriv_P.Iy * rtb_yerror;

    /* Gain: '<S7>/Proportional Gain' */
    Crane3D_DevDriv_B.ProportionalGain_e = Crane3D_DevDriv_P.Py * rtb_yerror;

    /* Level2 S-Function Block: '<S3>/PWM' (Crane3D_PWM) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Integrator: '<S6>/Integrator'
   */
  rtb_yerror = (Crane3D_DevDriv_B.ProportionalGain +
                Crane3D_DevDriv_X.Integrator_CSTATE) +
    Crane3D_DevDriv_B.FilterCoefficient;

  /* Saturate: '<S6>/Saturate' */
  if (rtb_yerror > Crane3D_DevDriv_P.PIDController_UpperSaturationLimit) {
    rtb_yerror = Crane3D_DevDriv_P.PIDController_UpperSaturationLimit;
  } else {
    if (rtb_yerror < Crane3D_DevDriv_P.PIDController_LowerSaturationLimit) {
      rtb_yerror = Crane3D_DevDriv_P.PIDController_LowerSaturationLimit;
    }
  }

  /* End of Saturate: '<S6>/Saturate' */

  /* Saturate: '<S3>/Saturation' */
  if (rtb_yerror > Crane3D_DevDriv_P.Saturation_UpperSat) {
    Crane3D_DevDriv_B.Saturation[0] = Crane3D_DevDriv_P.Saturation_UpperSat;
  } else if (rtb_yerror < Crane3D_DevDriv_P.Saturation_LowerSat) {
    Crane3D_DevDriv_B.Saturation[0] = Crane3D_DevDriv_P.Saturation_LowerSat;
  } else {
    Crane3D_DevDriv_B.Saturation[0] = rtb_yerror;
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  rtb_yerror = (Crane3D_DevDriv_B.ProportionalGain_e +
                Crane3D_DevDriv_X.Integrator_CSTATE_b) +
    Crane3D_DevDriv_B.FilterCoefficient_m;

  /* Saturate: '<S7>/Saturate' */
  if (rtb_yerror > Crane3D_DevDriv_P.PIDController2_UpperSaturationLimit) {
    rtb_yerror = Crane3D_DevDriv_P.PIDController2_UpperSaturationLimit;
  } else {
    if (rtb_yerror < Crane3D_DevDriv_P.PIDController2_LowerSaturationLimit) {
      rtb_yerror = Crane3D_DevDriv_P.PIDController2_LowerSaturationLimit;
    }
  }

  /* End of Saturate: '<S7>/Saturate' */

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (rtb_yerror > Crane3D_DevDriv_P.Saturation_UpperSat) {
    Crane3D_DevDriv_B.Saturation[1] = Crane3D_DevDriv_P.Saturation_UpperSat;
  } else if (rtb_yerror < Crane3D_DevDriv_P.Saturation_LowerSat) {
    Crane3D_DevDriv_B.Saturation[1] = Crane3D_DevDriv_P.Saturation_LowerSat;
  } else {
    Crane3D_DevDriv_B.Saturation[1] = rtb_yerror;
  }

  if (Crane3D_DevDriv_P.Constant_Value > Crane3D_DevDriv_P.Saturation_UpperSat)
  {
    Crane3D_DevDriv_B.Saturation[2] = Crane3D_DevDriv_P.Saturation_UpperSat;
  } else if (Crane3D_DevDriv_P.Constant_Value <
             Crane3D_DevDriv_P.Saturation_LowerSat) {
    Crane3D_DevDriv_B.Saturation[2] = Crane3D_DevDriv_P.Saturation_LowerSat;
  } else {
    Crane3D_DevDriv_B.Saturation[2] = Crane3D_DevDriv_P.Constant_Value;
  }

  if (rtmIsMajorTimeStep(Crane3D_DevDriv_M)) {
    /* Level2 S-Function Block: '<S3>/LimitFlag' (Crane3D_LimitFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_B.LimitFlagSource[0] =
      Crane3D_DevDriv_P.LimitFlagSource_Value[0];

    /* Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_B.LimitSource[0] = Crane3D_DevDriv_P.LimitSource_Value[0];

    /* Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_B.LimitFlagSource[1] =
      Crane3D_DevDriv_P.LimitFlagSource_Value[1];

    /* Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_B.LimitSource[1] = Crane3D_DevDriv_P.LimitSource_Value[1];

    /* Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_B.LimitFlagSource[2] =
      Crane3D_DevDriv_P.LimitFlagSource_Value[2];

    /* Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_B.LimitSource[2] = Crane3D_DevDriv_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S3>/SetLimit' (Crane3D_SetLimit) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/LimitSwitch' (Crane3D_Switch) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/PWMPrescalerSource' */
    Crane3D_DevDriv_B.PWMPrescalerSource =
      Crane3D_DevDriv_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S3>/ResetEncoder' (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ResetSource' */
    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_B.ResetSource[i] = Crane3D_DevDriv_P.ResetSource_Value[i];
    }

    /* End of Constant: '<S3>/ResetSource' */

    /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ResetSwitchFlagSource' */
    Crane3D_DevDriv_B.ResetSwitchFlagSource[0] =
      Crane3D_DevDriv_P.ResetSwitchFlagSource_Value[0];
    Crane3D_DevDriv_B.ResetSwitchFlagSource[1] =
      Crane3D_DevDriv_P.ResetSwitchFlagSource_Value[1];
    Crane3D_DevDriv_B.ResetSwitchFlagSource[2] =
      Crane3D_DevDriv_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S3>/ThermFlag ' (Crane3D_ThermFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ThermFlagSource' */
    Crane3D_DevDriv_B.ThermFlagSource[0] =
      Crane3D_DevDriv_P.ThermFlagSource_Value[0];
    Crane3D_DevDriv_B.ThermFlagSource[1] =
      Crane3D_DevDriv_P.ThermFlagSource_Value[1];
    Crane3D_DevDriv_B.ThermFlagSource[2] =
      Crane3D_DevDriv_P.ThermFlagSource_Value[2];
  }
}

/* Model update function */
void Crane3D_DevDriv_update(void)
{
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_M)) {
    rt_ertODEUpdateContinuousStates(&Crane3D_DevDriv_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Crane3D_DevDriv_M->Timing.clockTick0)) {
    ++Crane3D_DevDriv_M->Timing.clockTickH0;
  }

  Crane3D_DevDriv_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Crane3D_DevDriv_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Crane3D_DevDriv_M->Timing.clockTick1)) {
      ++Crane3D_DevDriv_M->Timing.clockTickH1;
    }

    Crane3D_DevDriv_M->Timing.t[1] = Crane3D_DevDriv_M->Timing.clockTick1 *
      Crane3D_DevDriv_M->Timing.stepSize1 +
      Crane3D_DevDriv_M->Timing.clockTickH1 *
      Crane3D_DevDriv_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Crane3D_DevDriv_derivatives(void)
{
  XDot_Crane3D_DevDriv_T *_rtXdot;
  _rtXdot = ((XDot_Crane3D_DevDriv_T *) Crane3D_DevDriv_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S6>/Filter' */
  _rtXdot->Filter_CSTATE = Crane3D_DevDriv_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = Crane3D_DevDriv_B.IntegralGain;

  /* Derivatives for Integrator: '<S7>/Filter' */
  _rtXdot->Filter_CSTATE_g = Crane3D_DevDriv_B.FilterCoefficient_m;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = Crane3D_DevDriv_B.IntegralGain_b;
}

/* Model initialize function */
void Crane3D_DevDriv_initialize(void)
{
  {
    int32_T i;

    /* Start for Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_B.LimitFlagSource[0] =
      Crane3D_DevDriv_P.LimitFlagSource_Value[0];

    /* Start for Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_B.LimitSource[0] = Crane3D_DevDriv_P.LimitSource_Value[0];

    /* Start for Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_B.LimitFlagSource[1] =
      Crane3D_DevDriv_P.LimitFlagSource_Value[1];

    /* Start for Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_B.LimitSource[1] = Crane3D_DevDriv_P.LimitSource_Value[1];

    /* Start for Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_B.LimitFlagSource[2] =
      Crane3D_DevDriv_P.LimitFlagSource_Value[2];

    /* Start for Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_B.LimitSource[2] = Crane3D_DevDriv_P.LimitSource_Value[2];

    /* Start for Constant: '<S3>/PWMPrescalerSource' */
    Crane3D_DevDriv_B.PWMPrescalerSource =
      Crane3D_DevDriv_P.PWMPrescalerSource_Value;

    /* Start for Constant: '<S3>/ResetSource' */
    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_B.ResetSource[i] = Crane3D_DevDriv_P.ResetSource_Value[i];
    }

    /* End of Start for Constant: '<S3>/ResetSource' */
    /* Start for Constant: '<S3>/ResetSwitchFlagSource' */
    Crane3D_DevDriv_B.ResetSwitchFlagSource[0] =
      Crane3D_DevDriv_P.ResetSwitchFlagSource_Value[0];
    Crane3D_DevDriv_B.ResetSwitchFlagSource[1] =
      Crane3D_DevDriv_P.ResetSwitchFlagSource_Value[1];
    Crane3D_DevDriv_B.ResetSwitchFlagSource[2] =
      Crane3D_DevDriv_P.ResetSwitchFlagSource_Value[2];

    /* Start for Constant: '<S3>/ThermFlagSource' */
    Crane3D_DevDriv_B.ThermFlagSource[0] =
      Crane3D_DevDriv_P.ThermFlagSource_Value[0];
    Crane3D_DevDriv_B.ThermFlagSource[1] =
      Crane3D_DevDriv_P.ThermFlagSource_Value[1];
    Crane3D_DevDriv_B.ThermFlagSource[2] =
      Crane3D_DevDriv_P.ThermFlagSource_Value[2];
  }

  /* InitializeConditions for Integrator: '<S6>/Filter' */
  Crane3D_DevDriv_X.Filter_CSTATE = Crane3D_DevDriv_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Crane3D_DevDriv_X.Integrator_CSTATE = Crane3D_DevDriv_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S7>/Filter' */
  Crane3D_DevDriv_X.Filter_CSTATE_g = Crane3D_DevDriv_P.Filter_IC_k;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  Crane3D_DevDriv_X.Integrator_CSTATE_b = Crane3D_DevDriv_P.Integrator_IC_j;

  /* SystemInitialize for MATLAB Function: '<Root>/Select most convenient path' */
  Crane3D_DevDriv_DW.WP_Index = 1.0;
}

/* Model terminate function */
void Crane3D_DevDriv_terminate(void)
{
  /* Level2 S-Function Block: '<S3>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Crane3D_DevDriv_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Crane3D_DevDriv_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Crane3D_DevDriv_initialize();
}

void MdlTerminate(void)
{
  Crane3D_DevDriv_terminate();
}

/* Registration function */
RT_MODEL_Crane3D_DevDriv_T *Crane3D_DevDriv(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Crane3D_DevDriv_M, 0,
                sizeof(RT_MODEL_Crane3D_DevDriv_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Crane3D_DevDriv_M->solverInfo,
                          &Crane3D_DevDriv_M->Timing.simTimeStep);
    rtsiSetTPtr(&Crane3D_DevDriv_M->solverInfo, &rtmGetTPtr(Crane3D_DevDriv_M));
    rtsiSetStepSizePtr(&Crane3D_DevDriv_M->solverInfo,
                       &Crane3D_DevDriv_M->Timing.stepSize0);
    rtsiSetdXPtr(&Crane3D_DevDriv_M->solverInfo,
                 &Crane3D_DevDriv_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Crane3D_DevDriv_M->solverInfo, (real_T **)
                         &Crane3D_DevDriv_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Crane3D_DevDriv_M->solverInfo,
      &Crane3D_DevDriv_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Crane3D_DevDriv_M->solverInfo,
      &Crane3D_DevDriv_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Crane3D_DevDriv_M->solverInfo,
      &Crane3D_DevDriv_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Crane3D_DevDriv_M->solverInfo,
      &Crane3D_DevDriv_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Crane3D_DevDriv_M->solverInfo, (&rtmGetErrorStatus
      (Crane3D_DevDriv_M)));
    rtsiSetRTModelPtr(&Crane3D_DevDriv_M->solverInfo, Crane3D_DevDriv_M);
  }

  rtsiSetSimTimeStep(&Crane3D_DevDriv_M->solverInfo, MAJOR_TIME_STEP);
  Crane3D_DevDriv_M->ModelData.intgData.y = Crane3D_DevDriv_M->ModelData.odeY;
  Crane3D_DevDriv_M->ModelData.intgData.f[0] = Crane3D_DevDriv_M->
    ModelData.odeF[0];
  Crane3D_DevDriv_M->ModelData.intgData.f[1] = Crane3D_DevDriv_M->
    ModelData.odeF[1];
  Crane3D_DevDriv_M->ModelData.intgData.f[2] = Crane3D_DevDriv_M->
    ModelData.odeF[2];
  Crane3D_DevDriv_M->ModelData.intgData.f[3] = Crane3D_DevDriv_M->
    ModelData.odeF[3];
  Crane3D_DevDriv_M->ModelData.intgData.f[4] = Crane3D_DevDriv_M->
    ModelData.odeF[4];
  Crane3D_DevDriv_M->ModelData.intgData.f[5] = Crane3D_DevDriv_M->
    ModelData.odeF[5];
  Crane3D_DevDriv_M->ModelData.contStates = ((real_T *) &Crane3D_DevDriv_X);
  rtsiSetSolverData(&Crane3D_DevDriv_M->solverInfo, (void *)
                    &Crane3D_DevDriv_M->ModelData.intgData);
  rtsiSetSolverName(&Crane3D_DevDriv_M->solverInfo,"ode5");
  Crane3D_DevDriv_M->solverInfoPtr = (&Crane3D_DevDriv_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Crane3D_DevDriv_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Crane3D_DevDriv_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Crane3D_DevDriv_M->Timing.sampleTimes =
      (&Crane3D_DevDriv_M->Timing.sampleTimesArray[0]);
    Crane3D_DevDriv_M->Timing.offsetTimes =
      (&Crane3D_DevDriv_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Crane3D_DevDriv_M->Timing.sampleTimes[0] = (0.0);
    Crane3D_DevDriv_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Crane3D_DevDriv_M->Timing.offsetTimes[0] = (0.0);
    Crane3D_DevDriv_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Crane3D_DevDriv_M, &Crane3D_DevDriv_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Crane3D_DevDriv_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Crane3D_DevDriv_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Crane3D_DevDriv_M, 120.0);
  Crane3D_DevDriv_M->Timing.stepSize0 = 0.01;
  Crane3D_DevDriv_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  Crane3D_DevDriv_M->Sizes.checksums[0] = (683255587U);
  Crane3D_DevDriv_M->Sizes.checksums[1] = (516352514U);
  Crane3D_DevDriv_M->Sizes.checksums[2] = (2244256495U);
  Crane3D_DevDriv_M->Sizes.checksums[3] = (3693446197U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Crane3D_DevDriv_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Crane3D_DevDriv_M->extModeInfo,
      &Crane3D_DevDriv_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Crane3D_DevDriv_M->extModeInfo,
                        Crane3D_DevDriv_M->Sizes.checksums);
    rteiSetTPtr(Crane3D_DevDriv_M->extModeInfo, rtmGetTPtr(Crane3D_DevDriv_M));
  }

  Crane3D_DevDriv_M->solverInfoPtr = (&Crane3D_DevDriv_M->solverInfo);
  Crane3D_DevDriv_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Crane3D_DevDriv_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Crane3D_DevDriv_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Crane3D_DevDriv_M->ModelData.blockIO = ((void *) &Crane3D_DevDriv_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_B.ResetEncoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_B.ResetSource[i] = 0.0;
    }

    Crane3D_DevDriv_B.Clock = 0.0;
    Crane3D_DevDriv_B.XScale = 0.0;
    Crane3D_DevDriv_B.YScale = 0.0;
    Crane3D_DevDriv_B.XAngleScale = 0.0;
    Crane3D_DevDriv_B.YAngleScale = 0.0;
    Crane3D_DevDriv_B.DerivativeGain = 0.0;
    Crane3D_DevDriv_B.FilterCoefficient = 0.0;
    Crane3D_DevDriv_B.IntegralGain = 0.0;
    Crane3D_DevDriv_B.ProportionalGain = 0.0;
    Crane3D_DevDriv_B.DerivativeGain_o = 0.0;
    Crane3D_DevDriv_B.FilterCoefficient_m = 0.0;
    Crane3D_DevDriv_B.IntegralGain_b = 0.0;
    Crane3D_DevDriv_B.ProportionalGain_e = 0.0;
    Crane3D_DevDriv_B.PWM[0] = 0.0;
    Crane3D_DevDriv_B.PWM[1] = 0.0;
    Crane3D_DevDriv_B.PWM[2] = 0.0;
    Crane3D_DevDriv_B.Saturation[0] = 0.0;
    Crane3D_DevDriv_B.Saturation[1] = 0.0;
    Crane3D_DevDriv_B.Saturation[2] = 0.0;
    Crane3D_DevDriv_B.LimitFlag[0] = 0.0;
    Crane3D_DevDriv_B.LimitFlag[1] = 0.0;
    Crane3D_DevDriv_B.LimitFlag[2] = 0.0;
    Crane3D_DevDriv_B.LimitFlagSource[0] = 0.0;
    Crane3D_DevDriv_B.LimitFlagSource[1] = 0.0;
    Crane3D_DevDriv_B.LimitFlagSource[2] = 0.0;
    Crane3D_DevDriv_B.LimitSource[0] = 0.0;
    Crane3D_DevDriv_B.LimitSource[1] = 0.0;
    Crane3D_DevDriv_B.LimitSource[2] = 0.0;
    Crane3D_DevDriv_B.SetLimit[0] = 0.0;
    Crane3D_DevDriv_B.SetLimit[1] = 0.0;
    Crane3D_DevDriv_B.SetLimit[2] = 0.0;
    Crane3D_DevDriv_B.LimitSwitch[0] = 0.0;
    Crane3D_DevDriv_B.LimitSwitch[1] = 0.0;
    Crane3D_DevDriv_B.LimitSwitch[2] = 0.0;
    Crane3D_DevDriv_B.PWMPrescaler = 0.0;
    Crane3D_DevDriv_B.PWMPrescalerSource = 0.0;
    Crane3D_DevDriv_B.ResetSwitchFlag[0] = 0.0;
    Crane3D_DevDriv_B.ResetSwitchFlag[1] = 0.0;
    Crane3D_DevDriv_B.ResetSwitchFlag[2] = 0.0;
    Crane3D_DevDriv_B.ResetSwitchFlagSource[0] = 0.0;
    Crane3D_DevDriv_B.ResetSwitchFlagSource[1] = 0.0;
    Crane3D_DevDriv_B.ResetSwitchFlagSource[2] = 0.0;
    Crane3D_DevDriv_B.ThermFlag[0] = 0.0;
    Crane3D_DevDriv_B.ThermFlag[1] = 0.0;
    Crane3D_DevDriv_B.ThermFlag[2] = 0.0;
    Crane3D_DevDriv_B.ThermFlagSource[0] = 0.0;
    Crane3D_DevDriv_B.ThermFlagSource[1] = 0.0;
    Crane3D_DevDriv_B.ThermFlagSource[2] = 0.0;
    Crane3D_DevDriv_B.x = 0.0;
    Crane3D_DevDriv_B.y = 0.0;
    Crane3D_DevDriv_B.x_l = 0.0;
    Crane3D_DevDriv_B.y_f = 0.0;
  }

  /* parameters */
  Crane3D_DevDriv_M->ModelData.defaultParam = ((real_T *)&Crane3D_DevDriv_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Crane3D_DevDriv_X;
    Crane3D_DevDriv_M->ModelData.contStates = (x);
    (void) memset((void *)&Crane3D_DevDriv_X, 0,
                  sizeof(X_Crane3D_DevDriv_T));
  }

  /* states (dwork) */
  Crane3D_DevDriv_M->ModelData.dwork = ((void *) &Crane3D_DevDriv_DW);
  (void) memset((void *)&Crane3D_DevDriv_DW, 0,
                sizeof(DW_Crane3D_DevDriv_T));
  Crane3D_DevDriv_DW.WP_Index = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Crane3D_DevDriv_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Crane3D_DevDriv_M->NonInlinedSFcns.sfcnInfo;
    Crane3D_DevDriv_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Crane3D_DevDriv_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Crane3D_DevDriv_M->Sizes.numSampTimes);
    Crane3D_DevDriv_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Crane3D_DevDriv_M)[0]);
    Crane3D_DevDriv_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Crane3D_DevDriv_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Crane3D_DevDriv_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Crane3D_DevDriv_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Crane3D_DevDriv_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Crane3D_DevDriv_M));
    rtssSetStepSizePtr(sfcnInfo, &Crane3D_DevDriv_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Crane3D_DevDriv_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Crane3D_DevDriv_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Crane3D_DevDriv_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &Crane3D_DevDriv_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Crane3D_DevDriv_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Crane3D_DevDriv_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Crane3D_DevDriv_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Crane3D_DevDriv_M->solverInfoPtr);
  }

  Crane3D_DevDriv_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&Crane3D_DevDriv_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    Crane3D_DevDriv_M->childSfunctions =
      (&Crane3D_DevDriv_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        Crane3D_DevDriv_M->childSfunctions[i] =
          (&Crane3D_DevDriv_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/Encoder (Crane3D_Encoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Crane3D_DevDriv_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/Encoder");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.Encoder_P2_Size);
      }

      /* registration */
      Crane3D_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/PWM (Crane3D_PWM) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_B.Saturation;
          sfcnUPtrs[1] = &Crane3D_DevDriv_B.Saturation[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Crane3D_DevDriv_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/PWM");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.PWM_P2_Size);
      }

      /* registration */
      Crane3D_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/LimitFlag (Crane3D_LimitFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_B.LimitFlagSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Crane3D_DevDriv_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/LimitFlag");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.LimitFlag_P2_Size);
      }

      /* registration */
      Crane3D_LimitFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/SetLimit (Crane3D_SetLimit) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_B.LimitSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_B.LimitSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Crane3D_DevDriv_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/SetLimit");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.SetLimit_P2_Size);
      }

      /* registration */
      Crane3D_SetLimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/LimitSwitch (Crane3D_Switch) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/LimitSwitch");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.LimitSwitch_P2_Size);
      }

      /* registration */
      Crane3D_Switch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/PWMPrescaler (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &Crane3D_DevDriv_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Crane3D_DevDriv_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/PWMPrescaler");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      Crane3D_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/ResetEncoder (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = Crane3D_DevDriv_B.ResetSource;
            for (i1=0; i1 < 5; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/ResetEncoder");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.ResetEncoder_P2_Size);
      }

      /* registration */
      Crane3D_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/ResetSwitchFlag  (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/ResetSwitchFlag ");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_P.ResetSwitchFlag_P2_Size);
      }

      /* registration */
      Crane3D_ResetSwitchFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Crane3D_DevDriv/<S3>/ThermFlag  (Crane3D_ThermFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Crane3D_DevDriv_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_B.ThermFlagSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Crane3D_DevDriv_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Crane3D_DevDriv/Crane 3D/ThermFlag ");
      ssSetRTModel(rts,Crane3D_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_P.ThermFlag_P2_Size);
      }

      /* registration */
      Crane3D_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  Crane3D_DevDriv_M->Sizes.numContStates = (4);/* Number of continuous states */
  Crane3D_DevDriv_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Crane3D_DevDriv_M->Sizes.numY = (0); /* Number of model outputs */
  Crane3D_DevDriv_M->Sizes.numU = (0); /* Number of model inputs */
  Crane3D_DevDriv_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Crane3D_DevDriv_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Crane3D_DevDriv_M->Sizes.numBlocks = (57);/* Number of blocks */
  Crane3D_DevDriv_M->Sizes.numBlockIO = (33);/* Number of block outputs */
  Crane3D_DevDriv_M->Sizes.numBlockPrms = (132);/* Sum of parameter "widths" */
  return Crane3D_DevDriv_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
