/*
 * NoPainNoCrane_Hardware.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "NoPainNoCrane_Hardware".
 *
 * Model version              : 1.269
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Wed Jan 10 15:10:38 2018
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NoPainNoCrane_Hardware.h"
#include "NoPainNoCrane_Hardware_private.h"
#include "NoPainNoCrane_Hardware_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_NoPainNoCrane_Hardware_T NoPainNoCrane_Hardware_B;

/* Continuous states */
X_NoPainNoCrane_Hardware_T NoPainNoCrane_Hardware_X;

/* Block states (auto storage) */
DW_NoPainNoCrane_Hardware_T NoPainNoCrane_Hardware_DW;

/* Real-time model */
RT_MODEL_NoPainNoCrane_Hardware_T NoPainNoCrane_Hardware_M_;
RT_MODEL_NoPainNoCrane_Hardware_T *const NoPainNoCrane_Hardware_M =
  &NoPainNoCrane_Hardware_M_;

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
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  NoPainNoCrane_Hardware_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  NoPainNoCrane_Hardware_output();
  NoPainNoCrane_Hardware_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  NoPainNoCrane_Hardware_output();
  NoPainNoCrane_Hardware_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  NoPainNoCrane_Hardware_output();
  NoPainNoCrane_Hardware_derivatives();

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
  NoPainNoCrane_Hardware_output();
  NoPainNoCrane_Hardware_derivatives();

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
  NoPainNoCrane_Hardware_output();
  NoPainNoCrane_Hardware_derivatives();

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
void NoPainNoCrane_Hardware_output(void)
{
  real_T x;
  real_T y;
  real_T x_max;
  real_T x_min;
  real_T y_max;
  real_T y_min;
  real_T rtb_Encoder500PPR[5];
  real_T rtb_Sum3;
  real_T rtb_yerror;
  real_T rtb_Sum5;
  real_T rtb_stop;
  int32_T i;
  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    /* set solver stop time */
    if (!(NoPainNoCrane_Hardware_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&NoPainNoCrane_Hardware_M->solverInfo,
                            ((NoPainNoCrane_Hardware_M->Timing.clockTickH0 + 1) *
        NoPainNoCrane_Hardware_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&NoPainNoCrane_Hardware_M->solverInfo,
                            ((NoPainNoCrane_Hardware_M->Timing.clockTick0 + 1) *
        NoPainNoCrane_Hardware_M->Timing.stepSize0 +
        NoPainNoCrane_Hardware_M->Timing.clockTickH0 *
        NoPainNoCrane_Hardware_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(NoPainNoCrane_Hardware_M)) {
    NoPainNoCrane_Hardware_M->Timing.t[0] = rtsiGetT
      (&NoPainNoCrane_Hardware_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    /* Level2 S-Function Block: '<S3>/Encoder' (Crane3D_Encoder) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/Encoder 500PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder500PPR[i] = NoPainNoCrane_Hardware_P.Encoder500PPR_Gain *
        NoPainNoCrane_Hardware_B.Encoder[i];
    }

    /* End of Gain: '<S3>/Encoder 500PPR' */

    /* Gain: '<S3>/X Scale' */
    NoPainNoCrane_Hardware_B.XScale = NoPainNoCrane_Hardware_P.XScale_Gain *
      rtb_Encoder500PPR[0];

    /* Gain: '<S3>/Y Scale' */
    NoPainNoCrane_Hardware_B.YScale = NoPainNoCrane_Hardware_P.YScale_Gain *
      rtb_Encoder500PPR[1];

    /* Gain: '<S3>/X Angle Scale' */
    NoPainNoCrane_Hardware_B.XAngleScale =
      NoPainNoCrane_Hardware_P.XAngleScale_Gain * rtb_Encoder500PPR[3];

    /* Gain: '<S3>/Y Angle Scale' */
    NoPainNoCrane_Hardware_B.YAngleScale =
      NoPainNoCrane_Hardware_P.YAngleScale_Gain * rtb_Encoder500PPR[4];

    /* MATLAB Function: '<Root>/Convert Coordinates' */
    /* MATLAB Function 'Convert Coordinates': '<S2>:1' */
    /* % Assumptions */
    /* '<S2>:1:4' */
    /* % Obtain Measurements from sensors */
    /* '<S2>:1:12' */
    /* '<S2>:1:13' */
    /*  x = now_x + R * sin_a * sin_b; */
    /*  y = now_y + R * cos_a; */
    /* '<S2>:1:19' */
    NoPainNoCrane_Hardware_B.x_l = 0.3 * sin
      (NoPainNoCrane_Hardware_B.XAngleScale) + NoPainNoCrane_Hardware_B.XScale;

    /* '<S2>:1:20' */
    NoPainNoCrane_Hardware_B.y_f = 0.3 * sin
      (NoPainNoCrane_Hardware_B.YAngleScale) + NoPainNoCrane_Hardware_B.YScale;

    /* MATLAB Function: '<Root>/Select most convenient path' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* MATLAB Function 'Select most convenient path': '<S5>:1' */
    /* % Random default values - dont touch */
    /* '<S5>:1:9' */
    x = 0.252;

    /* '<S5>:1:10' */
    y = 0.365;

    /* '<S5>:1:11' */
    rtb_stop = 0.0;
    if (NoPainNoCrane_Hardware_DW.WP_Index <= 6.0) {
      /* '<S5>:1:12' */
      /* '<S5>:1:13' */
      x = NoPainNoCrane_Hardware_P.Constant_Value[(int32_T)
        NoPainNoCrane_Hardware_DW.WP_Index - 1] / 100.0;

      /* '<S5>:1:14' */
      y = NoPainNoCrane_Hardware_P.Constant_Value[(int32_T)
        NoPainNoCrane_Hardware_DW.WP_Index + 5] / 100.0;

      /*     %% Establish boundary conditions and controller class */
      /* '<S5>:1:17' */
      x_max = x + 0.02;

      /* '<S5>:1:18' */
      x_min = x - 0.02;

      /* '<S5>:1:19' */
      y_max = y + 0.02;

      /* '<S5>:1:20' */
      y_min = y - 0.02;
      if (NoPainNoCrane_Hardware_P.Constant_Value[(int32_T)
          NoPainNoCrane_Hardware_DW.WP_Index + 23] == 1.0) {
        /* '<S5>:1:22' */
        /* '<S5>:1:23' */
        x_max = x + 0.01;

        /* '<S5>:1:24' */
        x_min = x - 0.01;

        /* '<S5>:1:25' */
        y_max = y + 0.01;

        /* '<S5>:1:26' */
        y_min = y - 0.01;
      }

      /*     %% Crane arrived to point */
      if ((NoPainNoCrane_Hardware_B.x_l <= x_max) &&
          (NoPainNoCrane_Hardware_B.x_l >= x_min) &&
          (NoPainNoCrane_Hardware_B.y_f <= y_max) &&
          (NoPainNoCrane_Hardware_B.y_f >= y_min)) {
        /* '<S5>:1:31' */
        /* '<S5>:1:32' */
        NoPainNoCrane_Hardware_DW.WP_Index++;
        if (NoPainNoCrane_Hardware_DW.WP_Index > 6.0) {
          /* '<S5>:1:33' */
          /* '<S5>:1:34' */
          NoPainNoCrane_Hardware_DW.WP_Index--;

          /* '<S5>:1:35' */
          rtb_stop = 1.0;
        }
      }
    }

    NoPainNoCrane_Hardware_B.x = x;
    NoPainNoCrane_Hardware_B.y = y;

    /* End of MATLAB Function: '<Root>/Select most convenient path' */

    /* Stop: '<Root>/Stop Simulation' */
    if (rtb_stop != 0.0) {
      rtmSetStopRequested(NoPainNoCrane_Hardware_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */

    /* Gain: '<S3>/Z Scale' */
    NoPainNoCrane_Hardware_B.ZScale = NoPainNoCrane_Hardware_P.ZScale_Gain *
      rtb_Encoder500PPR[2];

    /* Gain: '<S4>/GainZ1' incorporates:
     *  Sum: '<S4>/Add1'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    NoPainNoCrane_Hardware_B.Derivatives[0] = (NoPainNoCrane_Hardware_B.XScale -
      NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[0]) *
      NoPainNoCrane_Hardware_P.GainZ1_Gain;
    NoPainNoCrane_Hardware_B.Derivatives[1] = (NoPainNoCrane_Hardware_B.YScale -
      NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[1]) *
      NoPainNoCrane_Hardware_P.GainZ1_Gain;
    NoPainNoCrane_Hardware_B.Derivatives[2] = (NoPainNoCrane_Hardware_B.ZScale -
      NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[2]) *
      NoPainNoCrane_Hardware_P.GainZ1_Gain;
    NoPainNoCrane_Hardware_B.Derivatives[3] =
      (NoPainNoCrane_Hardware_B.XAngleScale -
       NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[3]) *
      NoPainNoCrane_Hardware_P.GainZ1_Gain;
    NoPainNoCrane_Hardware_B.Derivatives[4] =
      (NoPainNoCrane_Hardware_B.YAngleScale -
       NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[4]) *
      NoPainNoCrane_Hardware_P.GainZ1_Gain;

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo WorkspaceInport1' */
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[0] =
      NoPainNoCrane_Hardware_B.XScale;
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[1] =
      NoPainNoCrane_Hardware_B.Derivatives[0];
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[2] =
      NoPainNoCrane_Hardware_B.YScale;
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[3] =
      NoPainNoCrane_Hardware_B.Derivatives[1];
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[4] =
      NoPainNoCrane_Hardware_B.XAngleScale;
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[5] =
      NoPainNoCrane_Hardware_B.Derivatives[3];
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[6] =
      NoPainNoCrane_Hardware_B.YAngleScale;
    NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[7] =
      NoPainNoCrane_Hardware_B.Derivatives[4];

    /* Sum: '<S7>/Sum' */
    rtb_stop = NoPainNoCrane_Hardware_B.x - NoPainNoCrane_Hardware_B.XScale;

    /* Gain: '<S8>/Proportional Gain' */
    NoPainNoCrane_Hardware_B.ProportionalGain =
      NoPainNoCrane_Hardware_P.PIDController_P * rtb_stop;

    /* Gain: '<S8>/Derivative Gain' */
    NoPainNoCrane_Hardware_B.DerivativeGain =
      NoPainNoCrane_Hardware_P.PIDController_D * rtb_stop;

    /* Sum: '<S7>/Sum3' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Sum3 = NoPainNoCrane_Hardware_B.XAngleScale -
      NoPainNoCrane_Hardware_P.Constant_Value_b;

    /* Gain: '<S9>/Proportional Gain' */
    NoPainNoCrane_Hardware_B.ProportionalGain_j =
      NoPainNoCrane_Hardware_P.PIDController1_P * rtb_Sum3;

    /* Gain: '<S9>/Derivative Gain' */
    NoPainNoCrane_Hardware_B.DerivativeGain_f =
      NoPainNoCrane_Hardware_P.PIDController1_D * rtb_Sum3;
  }

  /* Gain: '<S8>/Filter Coefficient' incorporates:
   *  Integrator: '<S8>/Filter'
   *  Sum: '<S8>/SumD'
   */
  NoPainNoCrane_Hardware_B.FilterCoefficient =
    (NoPainNoCrane_Hardware_B.DerivativeGain -
     NoPainNoCrane_Hardware_X.Filter_CSTATE) *
    NoPainNoCrane_Hardware_P.PIDController_N;

  /* Gain: '<S9>/Filter Coefficient' incorporates:
   *  Integrator: '<S9>/Filter'
   *  Sum: '<S9>/SumD'
   */
  NoPainNoCrane_Hardware_B.FilterCoefficient_g =
    (NoPainNoCrane_Hardware_B.DerivativeGain_f -
     NoPainNoCrane_Hardware_X.Filter_CSTATE_p) *
    NoPainNoCrane_Hardware_P.PIDController1_N;

  /* Sum: '<S7>/Sum2' incorporates:
   *  Integrator: '<S8>/Integrator'
   *  Integrator: '<S9>/Integrator'
   *  Sum: '<S8>/Sum'
   *  Sum: '<S9>/Sum'
   */
  x_max = ((NoPainNoCrane_Hardware_B.ProportionalGain +
            NoPainNoCrane_Hardware_X.Integrator_CSTATE) +
           NoPainNoCrane_Hardware_B.FilterCoefficient) +
    ((NoPainNoCrane_Hardware_B.ProportionalGain_j +
      NoPainNoCrane_Hardware_X.Integrator_CSTATE_b) +
     NoPainNoCrane_Hardware_B.FilterCoefficient_g);
  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    /* Sum: '<S7>/Sum1' */
    rtb_yerror = NoPainNoCrane_Hardware_B.y - NoPainNoCrane_Hardware_B.YScale;

    /* Gain: '<S11>/Proportional Gain' */
    NoPainNoCrane_Hardware_B.ProportionalGain_o =
      NoPainNoCrane_Hardware_P.PIDController5_P * rtb_yerror;

    /* Gain: '<S11>/Derivative Gain' */
    NoPainNoCrane_Hardware_B.DerivativeGain_c =
      NoPainNoCrane_Hardware_P.PIDController5_D * rtb_yerror;

    /* Sum: '<S7>/Sum5' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    rtb_Sum5 = NoPainNoCrane_Hardware_B.YAngleScale -
      NoPainNoCrane_Hardware_P.Constant1_Value;

    /* Gain: '<S10>/Proportional Gain' */
    NoPainNoCrane_Hardware_B.ProportionalGain_f =
      NoPainNoCrane_Hardware_P.PIDController2_P * rtb_Sum5;

    /* Gain: '<S10>/Derivative Gain' */
    NoPainNoCrane_Hardware_B.DerivativeGain_m =
      NoPainNoCrane_Hardware_P.PIDController2_D * rtb_Sum5;
  }

  /* Gain: '<S11>/Filter Coefficient' incorporates:
   *  Integrator: '<S11>/Filter'
   *  Sum: '<S11>/SumD'
   */
  NoPainNoCrane_Hardware_B.FilterCoefficient_e =
    (NoPainNoCrane_Hardware_B.DerivativeGain_c -
     NoPainNoCrane_Hardware_X.Filter_CSTATE_p4) *
    NoPainNoCrane_Hardware_P.PIDController5_N;

  /* Gain: '<S10>/Filter Coefficient' incorporates:
   *  Integrator: '<S10>/Filter'
   *  Sum: '<S10>/SumD'
   */
  NoPainNoCrane_Hardware_B.FilterCoefficient_o =
    (NoPainNoCrane_Hardware_B.DerivativeGain_m -
     NoPainNoCrane_Hardware_X.Filter_CSTATE_n) *
    NoPainNoCrane_Hardware_P.PIDController2_N;

  /* Sum: '<S7>/Sum4' incorporates:
   *  Integrator: '<S10>/Integrator'
   *  Integrator: '<S11>/Integrator'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S11>/Sum'
   */
  x_min = ((NoPainNoCrane_Hardware_B.ProportionalGain_o +
            NoPainNoCrane_Hardware_X.Integrator_CSTATE_d) +
           NoPainNoCrane_Hardware_B.FilterCoefficient_e) +
    ((NoPainNoCrane_Hardware_B.ProportionalGain_f +
      NoPainNoCrane_Hardware_X.Integrator_CSTATE_a) +
     NoPainNoCrane_Hardware_B.FilterCoefficient_o);

  /* MATLAB Function: '<S1>/Enforce Soft Limits and Overflow' incorporates:
   *  Constant: '<Root>/X_range'
   *  Constant: '<Root>/Y_range '
   */
  x = NoPainNoCrane_Hardware_B.XScale;
  y = NoPainNoCrane_Hardware_B.YScale;

  /* MATLAB Function 'Controller/Enforce Soft Limits and Overflow': '<S6>:1' */
  /* '<S6>:1:3' */
  /* '<S6>:1:4' */
  /* '<S6>:1:5' */
  y_max = x_max;

  /* '<S6>:1:6' */
  y_min = x_min;

  /*  Deal with overflow - may not be the most appropriate place */
  if ((NoPainNoCrane_Hardware_B.XScale > 10.0) ||
      (NoPainNoCrane_Hardware_B.XScale < -10.0)) {
    /* '<S6>:1:9' */
    /* '<S6>:1:10' */
    x = 0.0;
  }

  if ((NoPainNoCrane_Hardware_B.YScale > 10.0) ||
      (NoPainNoCrane_Hardware_B.YScale < -10.0)) {
    /* '<S6>:1:12' */
    /* '<S6>:1:13' */
    y = 0.0;
  }

  /*  Put in place soft boundaries on the borders */
  if ((x > NoPainNoCrane_Hardware_P.X_range_Value[1] - 0.08) && (!(x_max <= 0.0)))
  {
    /* '<S6>:1:17' */
    /* '<S6>:1:18' */
    y_max = 0.0;
  }

  if (x < NoPainNoCrane_Hardware_P.X_range_Value[0] + 0.08) {
    /* '<S6>:1:21' */
    /* '<S6>:1:22' */
    if (x_max >= 0.0) {
      y_max = x_max;
    } else {
      y_max = 0.0;
    }
  }

  if ((y > NoPainNoCrane_Hardware_P.Y_range_Value[1] - 0.08) && (!(x_min <= 0.0)))
  {
    /* '<S6>:1:26' */
    /* '<S6>:1:27' */
    y_min = 0.0;
  }

  if (y < NoPainNoCrane_Hardware_P.Y_range_Value[0] + 0.08) {
    /* '<S6>:1:30' */
    /* '<S6>:1:31' */
    if (x_min >= 0.0) {
      y_min = x_min;
    } else {
      y_min = 0.0;
    }
  }

  /* End of MATLAB Function: '<S1>/Enforce Soft Limits and Overflow' */
  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    /* Gain: '<S8>/Integral Gain' */
    NoPainNoCrane_Hardware_B.IntegralGain =
      NoPainNoCrane_Hardware_P.PIDController_I * rtb_stop;

    /* Gain: '<S9>/Integral Gain' */
    NoPainNoCrane_Hardware_B.IntegralGain_a =
      NoPainNoCrane_Hardware_P.PIDController1_I * rtb_Sum3;

    /* Gain: '<S10>/Integral Gain' */
    NoPainNoCrane_Hardware_B.IntegralGain_p =
      NoPainNoCrane_Hardware_P.PIDController2_I * rtb_Sum5;

    /* Gain: '<S11>/Integral Gain' */
    NoPainNoCrane_Hardware_B.IntegralGain_g =
      NoPainNoCrane_Hardware_P.PIDController5_I * rtb_yerror;

    /* Level2 S-Function Block: '<S3>/PWM' (Crane3D_PWM) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (y_max > NoPainNoCrane_Hardware_P.Saturation_UpperSat) {
    NoPainNoCrane_Hardware_B.Saturation[0] =
      NoPainNoCrane_Hardware_P.Saturation_UpperSat;
  } else if (y_max < NoPainNoCrane_Hardware_P.Saturation_LowerSat) {
    NoPainNoCrane_Hardware_B.Saturation[0] =
      NoPainNoCrane_Hardware_P.Saturation_LowerSat;
  } else {
    NoPainNoCrane_Hardware_B.Saturation[0] = y_max;
  }

  if (y_min > NoPainNoCrane_Hardware_P.Saturation_UpperSat) {
    NoPainNoCrane_Hardware_B.Saturation[1] =
      NoPainNoCrane_Hardware_P.Saturation_UpperSat;
  } else if (y_min < NoPainNoCrane_Hardware_P.Saturation_LowerSat) {
    NoPainNoCrane_Hardware_B.Saturation[1] =
      NoPainNoCrane_Hardware_P.Saturation_LowerSat;
  } else {
    NoPainNoCrane_Hardware_B.Saturation[1] = y_min;
  }

  if (NoPainNoCrane_Hardware_P.Constant_Value_f >
      NoPainNoCrane_Hardware_P.Saturation_UpperSat) {
    NoPainNoCrane_Hardware_B.Saturation[2] =
      NoPainNoCrane_Hardware_P.Saturation_UpperSat;
  } else if (NoPainNoCrane_Hardware_P.Constant_Value_f <
             NoPainNoCrane_Hardware_P.Saturation_LowerSat) {
    NoPainNoCrane_Hardware_B.Saturation[2] =
      NoPainNoCrane_Hardware_P.Saturation_LowerSat;
  } else {
    NoPainNoCrane_Hardware_B.Saturation[2] =
      NoPainNoCrane_Hardware_P.Constant_Value_f;
  }

  /* End of Saturate: '<S3>/Saturation' */
  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    /* Level2 S-Function Block: '<S3>/LimitFlag' (Crane3D_LimitFlag) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/LimitFlagSource' */
    NoPainNoCrane_Hardware_B.LimitFlagSource[0] =
      NoPainNoCrane_Hardware_P.LimitFlagSource_Value[0];

    /* Constant: '<S3>/LimitSource' */
    NoPainNoCrane_Hardware_B.LimitSource[0] =
      NoPainNoCrane_Hardware_P.LimitSource_Value[0];

    /* Constant: '<S3>/LimitFlagSource' */
    NoPainNoCrane_Hardware_B.LimitFlagSource[1] =
      NoPainNoCrane_Hardware_P.LimitFlagSource_Value[1];

    /* Constant: '<S3>/LimitSource' */
    NoPainNoCrane_Hardware_B.LimitSource[1] =
      NoPainNoCrane_Hardware_P.LimitSource_Value[1];

    /* Constant: '<S3>/LimitFlagSource' */
    NoPainNoCrane_Hardware_B.LimitFlagSource[2] =
      NoPainNoCrane_Hardware_P.LimitFlagSource_Value[2];

    /* Constant: '<S3>/LimitSource' */
    NoPainNoCrane_Hardware_B.LimitSource[2] =
      NoPainNoCrane_Hardware_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S3>/SetLimit' (Crane3D_SetLimit) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/LimitSwitch' (Crane3D_Switch) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/PWMPrescalerSource' */
    NoPainNoCrane_Hardware_B.PWMPrescalerSource =
      NoPainNoCrane_Hardware_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S3>/ResetEncoder' (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ResetSource' */
    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_B.ResetSource[i] =
        NoPainNoCrane_Hardware_P.ResetSource_Value[i];
    }

    /* End of Constant: '<S3>/ResetSource' */

    /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ResetSwitchFlagSource' */
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[0] =
      NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value[0];
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[1] =
      NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value[1];
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[2] =
      NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S3>/ThermFlag ' (Crane3D_ThermFlag) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ThermFlagSource' */
    NoPainNoCrane_Hardware_B.ThermFlagSource[0] =
      NoPainNoCrane_Hardware_P.ThermFlagSource_Value[0];
    NoPainNoCrane_Hardware_B.ThermFlagSource[1] =
      NoPainNoCrane_Hardware_P.ThermFlagSource_Value[1];
    NoPainNoCrane_Hardware_B.ThermFlagSource[2] =
      NoPainNoCrane_Hardware_P.ThermFlagSource_Value[2];
  }

  /* Clock: '<Root>/Clock' */
  NoPainNoCrane_Hardware_B.Clock = NoPainNoCrane_Hardware_M->Timing.t[0];
  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
  }
}

/* Model update function */
void NoPainNoCrane_Hardware_update(void)
{
  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    /* Update for UnitDelay: '<S4>/Unit Delay' */
    NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[0] =
      NoPainNoCrane_Hardware_B.XScale;
    NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[1] =
      NoPainNoCrane_Hardware_B.YScale;
    NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[2] =
      NoPainNoCrane_Hardware_B.ZScale;
    NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[3] =
      NoPainNoCrane_Hardware_B.XAngleScale;
    NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[4] =
      NoPainNoCrane_Hardware_B.YAngleScale;
  }

  if (rtmIsMajorTimeStep(NoPainNoCrane_Hardware_M)) {
    rt_ertODEUpdateContinuousStates(&NoPainNoCrane_Hardware_M->solverInfo);
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
  if (!(++NoPainNoCrane_Hardware_M->Timing.clockTick0)) {
    ++NoPainNoCrane_Hardware_M->Timing.clockTickH0;
  }

  NoPainNoCrane_Hardware_M->Timing.t[0] = rtsiGetSolverStopTime
    (&NoPainNoCrane_Hardware_M->solverInfo);

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
    if (!(++NoPainNoCrane_Hardware_M->Timing.clockTick1)) {
      ++NoPainNoCrane_Hardware_M->Timing.clockTickH1;
    }

    NoPainNoCrane_Hardware_M->Timing.t[1] =
      NoPainNoCrane_Hardware_M->Timing.clockTick1 *
      NoPainNoCrane_Hardware_M->Timing.stepSize1 +
      NoPainNoCrane_Hardware_M->Timing.clockTickH1 *
      NoPainNoCrane_Hardware_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void NoPainNoCrane_Hardware_derivatives(void)
{
  XDot_NoPainNoCrane_Hardware_T *_rtXdot;
  _rtXdot = ((XDot_NoPainNoCrane_Hardware_T *)
             NoPainNoCrane_Hardware_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = NoPainNoCrane_Hardware_B.IntegralGain;

  /* Derivatives for Integrator: '<S8>/Filter' */
  _rtXdot->Filter_CSTATE = NoPainNoCrane_Hardware_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = NoPainNoCrane_Hardware_B.IntegralGain_a;

  /* Derivatives for Integrator: '<S9>/Filter' */
  _rtXdot->Filter_CSTATE_p = NoPainNoCrane_Hardware_B.FilterCoefficient_g;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = NoPainNoCrane_Hardware_B.IntegralGain_g;

  /* Derivatives for Integrator: '<S11>/Filter' */
  _rtXdot->Filter_CSTATE_p4 = NoPainNoCrane_Hardware_B.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = NoPainNoCrane_Hardware_B.IntegralGain_p;

  /* Derivatives for Integrator: '<S10>/Filter' */
  _rtXdot->Filter_CSTATE_n = NoPainNoCrane_Hardware_B.FilterCoefficient_o;
}

/* Model initialize function */
void NoPainNoCrane_Hardware_initialize(void)
{
  {
    int32_T i;

    /* Start for Constant: '<S3>/LimitFlagSource' */
    NoPainNoCrane_Hardware_B.LimitFlagSource[0] =
      NoPainNoCrane_Hardware_P.LimitFlagSource_Value[0];

    /* Start for Constant: '<S3>/LimitSource' */
    NoPainNoCrane_Hardware_B.LimitSource[0] =
      NoPainNoCrane_Hardware_P.LimitSource_Value[0];

    /* Start for Constant: '<S3>/LimitFlagSource' */
    NoPainNoCrane_Hardware_B.LimitFlagSource[1] =
      NoPainNoCrane_Hardware_P.LimitFlagSource_Value[1];

    /* Start for Constant: '<S3>/LimitSource' */
    NoPainNoCrane_Hardware_B.LimitSource[1] =
      NoPainNoCrane_Hardware_P.LimitSource_Value[1];

    /* Start for Constant: '<S3>/LimitFlagSource' */
    NoPainNoCrane_Hardware_B.LimitFlagSource[2] =
      NoPainNoCrane_Hardware_P.LimitFlagSource_Value[2];

    /* Start for Constant: '<S3>/LimitSource' */
    NoPainNoCrane_Hardware_B.LimitSource[2] =
      NoPainNoCrane_Hardware_P.LimitSource_Value[2];

    /* Start for Constant: '<S3>/PWMPrescalerSource' */
    NoPainNoCrane_Hardware_B.PWMPrescalerSource =
      NoPainNoCrane_Hardware_P.PWMPrescalerSource_Value;

    /* Start for Constant: '<S3>/ResetSource' */
    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_B.ResetSource[i] =
        NoPainNoCrane_Hardware_P.ResetSource_Value[i];
    }

    /* End of Start for Constant: '<S3>/ResetSource' */
    /* Start for Constant: '<S3>/ResetSwitchFlagSource' */
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[0] =
      NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value[0];
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[1] =
      NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value[1];
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[2] =
      NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value[2];

    /* Start for Constant: '<S3>/ThermFlagSource' */
    NoPainNoCrane_Hardware_B.ThermFlagSource[0] =
      NoPainNoCrane_Hardware_P.ThermFlagSource_Value[0];
    NoPainNoCrane_Hardware_B.ThermFlagSource[1] =
      NoPainNoCrane_Hardware_P.ThermFlagSource_Value[1];
    NoPainNoCrane_Hardware_B.ThermFlagSource[2] =
      NoPainNoCrane_Hardware_P.ThermFlagSource_Value[2];
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[i] =
        NoPainNoCrane_Hardware_P.UnitDelay_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S4>/Unit Delay' */

    /* InitializeConditions for Integrator: '<S8>/Integrator' */
    NoPainNoCrane_Hardware_X.Integrator_CSTATE =
      NoPainNoCrane_Hardware_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S8>/Filter' */
    NoPainNoCrane_Hardware_X.Filter_CSTATE = NoPainNoCrane_Hardware_P.Filter_IC;

    /* InitializeConditions for Integrator: '<S9>/Integrator' */
    NoPainNoCrane_Hardware_X.Integrator_CSTATE_b =
      NoPainNoCrane_Hardware_P.Integrator_IC_e;

    /* InitializeConditions for Integrator: '<S9>/Filter' */
    NoPainNoCrane_Hardware_X.Filter_CSTATE_p =
      NoPainNoCrane_Hardware_P.Filter_IC_k;

    /* InitializeConditions for Integrator: '<S11>/Integrator' */
    NoPainNoCrane_Hardware_X.Integrator_CSTATE_d =
      NoPainNoCrane_Hardware_P.Integrator_IC_c;

    /* InitializeConditions for Integrator: '<S11>/Filter' */
    NoPainNoCrane_Hardware_X.Filter_CSTATE_p4 =
      NoPainNoCrane_Hardware_P.Filter_IC_a;

    /* InitializeConditions for Integrator: '<S10>/Integrator' */
    NoPainNoCrane_Hardware_X.Integrator_CSTATE_a =
      NoPainNoCrane_Hardware_P.Integrator_IC_k;

    /* InitializeConditions for Integrator: '<S10>/Filter' */
    NoPainNoCrane_Hardware_X.Filter_CSTATE_n =
      NoPainNoCrane_Hardware_P.Filter_IC_d;

    /* SystemInitialize for MATLAB Function: '<Root>/Select most convenient path' */
    NoPainNoCrane_Hardware_DW.WP_Index = 1.0;
  }
}

/* Model terminate function */
void NoPainNoCrane_Hardware_terminate(void)
{
  /* Level2 S-Function Block: '<S3>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[8];
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
  NoPainNoCrane_Hardware_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  NoPainNoCrane_Hardware_update();
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
  NoPainNoCrane_Hardware_initialize();
}

void MdlTerminate(void)
{
  NoPainNoCrane_Hardware_terminate();
}

/* Registration function */
RT_MODEL_NoPainNoCrane_Hardware_T *NoPainNoCrane_Hardware(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)NoPainNoCrane_Hardware_M, 0,
                sizeof(RT_MODEL_NoPainNoCrane_Hardware_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&NoPainNoCrane_Hardware_M->solverInfo,
                          &NoPainNoCrane_Hardware_M->Timing.simTimeStep);
    rtsiSetTPtr(&NoPainNoCrane_Hardware_M->solverInfo, &rtmGetTPtr
                (NoPainNoCrane_Hardware_M));
    rtsiSetStepSizePtr(&NoPainNoCrane_Hardware_M->solverInfo,
                       &NoPainNoCrane_Hardware_M->Timing.stepSize0);
    rtsiSetdXPtr(&NoPainNoCrane_Hardware_M->solverInfo,
                 &NoPainNoCrane_Hardware_M->ModelData.derivs);
    rtsiSetContStatesPtr(&NoPainNoCrane_Hardware_M->solverInfo, (real_T **)
                         &NoPainNoCrane_Hardware_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&NoPainNoCrane_Hardware_M->solverInfo,
      &NoPainNoCrane_Hardware_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&NoPainNoCrane_Hardware_M->solverInfo,
      &NoPainNoCrane_Hardware_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&NoPainNoCrane_Hardware_M->solverInfo,
      &NoPainNoCrane_Hardware_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&NoPainNoCrane_Hardware_M->solverInfo,
      &NoPainNoCrane_Hardware_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&NoPainNoCrane_Hardware_M->solverInfo,
                          (&rtmGetErrorStatus(NoPainNoCrane_Hardware_M)));
    rtsiSetRTModelPtr(&NoPainNoCrane_Hardware_M->solverInfo,
                      NoPainNoCrane_Hardware_M);
  }

  rtsiSetSimTimeStep(&NoPainNoCrane_Hardware_M->solverInfo, MAJOR_TIME_STEP);
  NoPainNoCrane_Hardware_M->ModelData.intgData.y =
    NoPainNoCrane_Hardware_M->ModelData.odeY;
  NoPainNoCrane_Hardware_M->ModelData.intgData.f[0] =
    NoPainNoCrane_Hardware_M->ModelData.odeF[0];
  NoPainNoCrane_Hardware_M->ModelData.intgData.f[1] =
    NoPainNoCrane_Hardware_M->ModelData.odeF[1];
  NoPainNoCrane_Hardware_M->ModelData.intgData.f[2] =
    NoPainNoCrane_Hardware_M->ModelData.odeF[2];
  NoPainNoCrane_Hardware_M->ModelData.intgData.f[3] =
    NoPainNoCrane_Hardware_M->ModelData.odeF[3];
  NoPainNoCrane_Hardware_M->ModelData.intgData.f[4] =
    NoPainNoCrane_Hardware_M->ModelData.odeF[4];
  NoPainNoCrane_Hardware_M->ModelData.intgData.f[5] =
    NoPainNoCrane_Hardware_M->ModelData.odeF[5];
  NoPainNoCrane_Hardware_M->ModelData.contStates = ((real_T *)
    &NoPainNoCrane_Hardware_X);
  rtsiSetSolverData(&NoPainNoCrane_Hardware_M->solverInfo, (void *)
                    &NoPainNoCrane_Hardware_M->ModelData.intgData);
  rtsiSetSolverName(&NoPainNoCrane_Hardware_M->solverInfo,"ode5");
  NoPainNoCrane_Hardware_M->solverInfoPtr =
    (&NoPainNoCrane_Hardware_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = NoPainNoCrane_Hardware_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    NoPainNoCrane_Hardware_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    NoPainNoCrane_Hardware_M->Timing.sampleTimes =
      (&NoPainNoCrane_Hardware_M->Timing.sampleTimesArray[0]);
    NoPainNoCrane_Hardware_M->Timing.offsetTimes =
      (&NoPainNoCrane_Hardware_M->Timing.offsetTimesArray[0]);

    /* task periods */
    NoPainNoCrane_Hardware_M->Timing.sampleTimes[0] = (0.0);
    NoPainNoCrane_Hardware_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    NoPainNoCrane_Hardware_M->Timing.offsetTimes[0] = (0.0);
    NoPainNoCrane_Hardware_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(NoPainNoCrane_Hardware_M, &NoPainNoCrane_Hardware_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = NoPainNoCrane_Hardware_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    NoPainNoCrane_Hardware_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(NoPainNoCrane_Hardware_M, 59.79);
  NoPainNoCrane_Hardware_M->Timing.stepSize0 = 0.01;
  NoPainNoCrane_Hardware_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  NoPainNoCrane_Hardware_M->Sizes.checksums[0] = (2744582875U);
  NoPainNoCrane_Hardware_M->Sizes.checksums[1] = (726568948U);
  NoPainNoCrane_Hardware_M->Sizes.checksums[2] = (401154565U);
  NoPainNoCrane_Hardware_M->Sizes.checksums[3] = (2310163723U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    NoPainNoCrane_Hardware_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(NoPainNoCrane_Hardware_M->extModeInfo,
      &NoPainNoCrane_Hardware_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(NoPainNoCrane_Hardware_M->extModeInfo,
                        NoPainNoCrane_Hardware_M->Sizes.checksums);
    rteiSetTPtr(NoPainNoCrane_Hardware_M->extModeInfo, rtmGetTPtr
                (NoPainNoCrane_Hardware_M));
  }

  NoPainNoCrane_Hardware_M->solverInfoPtr =
    (&NoPainNoCrane_Hardware_M->solverInfo);
  NoPainNoCrane_Hardware_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&NoPainNoCrane_Hardware_M->solverInfo, 0.01);
  rtsiSetSolverMode(&NoPainNoCrane_Hardware_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  NoPainNoCrane_Hardware_M->ModelData.blockIO = ((void *)
    &NoPainNoCrane_Hardware_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_B.Derivatives[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_B.ResetEncoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_B.ResetSource[i] = 0.0;
    }

    NoPainNoCrane_Hardware_B.XScale = 0.0;
    NoPainNoCrane_Hardware_B.YScale = 0.0;
    NoPainNoCrane_Hardware_B.XAngleScale = 0.0;
    NoPainNoCrane_Hardware_B.YAngleScale = 0.0;
    NoPainNoCrane_Hardware_B.ZScale = 0.0;
    NoPainNoCrane_Hardware_B.ProportionalGain = 0.0;
    NoPainNoCrane_Hardware_B.DerivativeGain = 0.0;
    NoPainNoCrane_Hardware_B.FilterCoefficient = 0.0;
    NoPainNoCrane_Hardware_B.ProportionalGain_j = 0.0;
    NoPainNoCrane_Hardware_B.DerivativeGain_f = 0.0;
    NoPainNoCrane_Hardware_B.FilterCoefficient_g = 0.0;
    NoPainNoCrane_Hardware_B.ProportionalGain_o = 0.0;
    NoPainNoCrane_Hardware_B.DerivativeGain_c = 0.0;
    NoPainNoCrane_Hardware_B.FilterCoefficient_e = 0.0;
    NoPainNoCrane_Hardware_B.ProportionalGain_f = 0.0;
    NoPainNoCrane_Hardware_B.DerivativeGain_m = 0.0;
    NoPainNoCrane_Hardware_B.FilterCoefficient_o = 0.0;
    NoPainNoCrane_Hardware_B.IntegralGain = 0.0;
    NoPainNoCrane_Hardware_B.IntegralGain_a = 0.0;
    NoPainNoCrane_Hardware_B.IntegralGain_p = 0.0;
    NoPainNoCrane_Hardware_B.IntegralGain_g = 0.0;
    NoPainNoCrane_Hardware_B.PWM[0] = 0.0;
    NoPainNoCrane_Hardware_B.PWM[1] = 0.0;
    NoPainNoCrane_Hardware_B.PWM[2] = 0.0;
    NoPainNoCrane_Hardware_B.Saturation[0] = 0.0;
    NoPainNoCrane_Hardware_B.Saturation[1] = 0.0;
    NoPainNoCrane_Hardware_B.Saturation[2] = 0.0;
    NoPainNoCrane_Hardware_B.LimitFlag[0] = 0.0;
    NoPainNoCrane_Hardware_B.LimitFlag[1] = 0.0;
    NoPainNoCrane_Hardware_B.LimitFlag[2] = 0.0;
    NoPainNoCrane_Hardware_B.LimitFlagSource[0] = 0.0;
    NoPainNoCrane_Hardware_B.LimitFlagSource[1] = 0.0;
    NoPainNoCrane_Hardware_B.LimitFlagSource[2] = 0.0;
    NoPainNoCrane_Hardware_B.LimitSource[0] = 0.0;
    NoPainNoCrane_Hardware_B.LimitSource[1] = 0.0;
    NoPainNoCrane_Hardware_B.LimitSource[2] = 0.0;
    NoPainNoCrane_Hardware_B.SetLimit[0] = 0.0;
    NoPainNoCrane_Hardware_B.SetLimit[1] = 0.0;
    NoPainNoCrane_Hardware_B.SetLimit[2] = 0.0;
    NoPainNoCrane_Hardware_B.LimitSwitch[0] = 0.0;
    NoPainNoCrane_Hardware_B.LimitSwitch[1] = 0.0;
    NoPainNoCrane_Hardware_B.LimitSwitch[2] = 0.0;
    NoPainNoCrane_Hardware_B.PWMPrescaler = 0.0;
    NoPainNoCrane_Hardware_B.PWMPrescalerSource = 0.0;
    NoPainNoCrane_Hardware_B.ResetSwitchFlag[0] = 0.0;
    NoPainNoCrane_Hardware_B.ResetSwitchFlag[1] = 0.0;
    NoPainNoCrane_Hardware_B.ResetSwitchFlag[2] = 0.0;
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[0] = 0.0;
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[1] = 0.0;
    NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[2] = 0.0;
    NoPainNoCrane_Hardware_B.ThermFlag[0] = 0.0;
    NoPainNoCrane_Hardware_B.ThermFlag[1] = 0.0;
    NoPainNoCrane_Hardware_B.ThermFlag[2] = 0.0;
    NoPainNoCrane_Hardware_B.ThermFlagSource[0] = 0.0;
    NoPainNoCrane_Hardware_B.ThermFlagSource[1] = 0.0;
    NoPainNoCrane_Hardware_B.ThermFlagSource[2] = 0.0;
    NoPainNoCrane_Hardware_B.Clock = 0.0;
    NoPainNoCrane_Hardware_B.x = 0.0;
    NoPainNoCrane_Hardware_B.y = 0.0;
    NoPainNoCrane_Hardware_B.x_l = 0.0;
    NoPainNoCrane_Hardware_B.y_f = 0.0;
  }

  /* parameters */
  NoPainNoCrane_Hardware_M->ModelData.defaultParam = ((real_T *)
    &NoPainNoCrane_Hardware_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &NoPainNoCrane_Hardware_X;
    NoPainNoCrane_Hardware_M->ModelData.contStates = (x);
    (void) memset((void *)&NoPainNoCrane_Hardware_X, 0,
                  sizeof(X_NoPainNoCrane_Hardware_T));
  }

  /* states (dwork) */
  NoPainNoCrane_Hardware_M->ModelData.dwork = ((void *)
    &NoPainNoCrane_Hardware_DW);
  (void) memset((void *)&NoPainNoCrane_Hardware_DW, 0,
                sizeof(DW_NoPainNoCrane_Hardware_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  NoPainNoCrane_Hardware_DW.WP_Index = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    NoPainNoCrane_Hardware_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &NoPainNoCrane_Hardware_M->NonInlinedSFcns.sfcnInfo;
    NoPainNoCrane_Hardware_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(NoPainNoCrane_Hardware_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &NoPainNoCrane_Hardware_M->Sizes.numSampTimes);
    NoPainNoCrane_Hardware_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (NoPainNoCrane_Hardware_M)[0]);
    NoPainNoCrane_Hardware_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (NoPainNoCrane_Hardware_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   NoPainNoCrane_Hardware_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(NoPainNoCrane_Hardware_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(NoPainNoCrane_Hardware_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (NoPainNoCrane_Hardware_M));
    rtssSetStepSizePtr(sfcnInfo, &NoPainNoCrane_Hardware_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (NoPainNoCrane_Hardware_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &NoPainNoCrane_Hardware_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &NoPainNoCrane_Hardware_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &NoPainNoCrane_Hardware_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &NoPainNoCrane_Hardware_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &NoPainNoCrane_Hardware_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &NoPainNoCrane_Hardware_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &NoPainNoCrane_Hardware_M->solverInfoPtr);
  }

  NoPainNoCrane_Hardware_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)
                  &NoPainNoCrane_Hardware_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    NoPainNoCrane_Hardware_M->childSfunctions =
      (&NoPainNoCrane_Hardware_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        NoPainNoCrane_Hardware_M->childSfunctions[i] =
          (&NoPainNoCrane_Hardware_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/Encoder (Crane3D_Encoder) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/Encoder");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/PWM (Crane3D_PWM) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = NoPainNoCrane_Hardware_B.Saturation;
          sfcnUPtrs[1] = &NoPainNoCrane_Hardware_B.Saturation[1];
          sfcnUPtrs[2] = &NoPainNoCrane_Hardware_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) NoPainNoCrane_Hardware_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/PWM");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)NoPainNoCrane_Hardware_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)NoPainNoCrane_Hardware_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/LimitFlag (Crane3D_LimitFlag) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = NoPainNoCrane_Hardware_B.LimitFlagSource;
          sfcnUPtrs[1] = &NoPainNoCrane_Hardware_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &NoPainNoCrane_Hardware_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/LimitFlag");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/SetLimit (Crane3D_SetLimit) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = NoPainNoCrane_Hardware_B.LimitSource;
          sfcnUPtrs[1] = &NoPainNoCrane_Hardware_B.LimitSource[1];
          sfcnUPtrs[2] = &NoPainNoCrane_Hardware_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/SetLimit");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/LimitSwitch (Crane3D_Switch) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/LimitSwitch");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/PWMPrescaler (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &NoPainNoCrane_Hardware_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &NoPainNoCrane_Hardware_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/PWMPrescaler");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/ResetEncoder (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = NoPainNoCrane_Hardware_B.ResetSource;
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
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/ResetEncoder");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/ResetSwitchFlag  (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = NoPainNoCrane_Hardware_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &NoPainNoCrane_Hardware_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/ResetSwitchFlag ");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: NoPainNoCrane_Hardware/<S3>/ThermFlag  (Crane3D_ThermFlag) */
    {
      SimStruct *rts = NoPainNoCrane_Hardware_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, NoPainNoCrane_Hardware_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &NoPainNoCrane_Hardware_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &NoPainNoCrane_Hardware_M->NonInlinedSFcns.statesInfo2
                         [8]);
        ssSetPeriodicStatesInfo(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = NoPainNoCrane_Hardware_B.ThermFlagSource;
          sfcnUPtrs[1] = &NoPainNoCrane_Hardware_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &NoPainNoCrane_Hardware_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            NoPainNoCrane_Hardware_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "NoPainNoCrane_Hardware/Crane 3D/ThermFlag ");
      ssSetRTModel(rts,NoPainNoCrane_Hardware_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &NoPainNoCrane_Hardware_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       NoPainNoCrane_Hardware_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       NoPainNoCrane_Hardware_P.ThermFlag_P2_Size);
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
  NoPainNoCrane_Hardware_M->Sizes.numContStates = (8);/* Number of continuous states */
  NoPainNoCrane_Hardware_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  NoPainNoCrane_Hardware_M->Sizes.numY = (0);/* Number of model outputs */
  NoPainNoCrane_Hardware_M->Sizes.numU = (0);/* Number of model inputs */
  NoPainNoCrane_Hardware_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  NoPainNoCrane_Hardware_M->Sizes.numSampTimes = (2);/* Number of sample times */
  NoPainNoCrane_Hardware_M->Sizes.numBlocks = (88);/* Number of blocks */
  NoPainNoCrane_Hardware_M->Sizes.numBlockIO = (44);/* Number of block outputs */
  NoPainNoCrane_Hardware_M->Sizes.numBlockPrms = (147);/* Sum of parameter "widths" */
  return NoPainNoCrane_Hardware_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
