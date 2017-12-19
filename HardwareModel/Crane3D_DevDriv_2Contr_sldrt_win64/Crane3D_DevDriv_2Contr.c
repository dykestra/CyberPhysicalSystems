/*
 * Crane3D_DevDriv_2Contr.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Crane3D_DevDriv_2Contr".
 *
 * Model version              : 1.255
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Tue Dec 19 13:33:17 2017
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Crane3D_DevDriv_2Contr.h"
#include "Crane3D_DevDriv_2Contr_private.h"
#include "Crane3D_DevDriv_2Contr_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Crane3D_DevDriv_2Contr_T Crane3D_DevDriv_2Contr_B;

/* Continuous states */
X_Crane3D_DevDriv_2Contr_T Crane3D_DevDriv_2Contr_X;

/* Block states (auto storage) */
DW_Crane3D_DevDriv_2Contr_T Crane3D_DevDriv_2Contr_DW;

/* Real-time model */
RT_MODEL_Crane3D_DevDriv_2Contr_T Crane3D_DevDriv_2Contr_M_;
RT_MODEL_Crane3D_DevDriv_2Contr_T *const Crane3D_DevDriv_2Contr_M =
  &Crane3D_DevDriv_2Contr_M_;

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
  Crane3D_DevDriv_2Contr_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Crane3D_DevDriv_2Contr_output();
  Crane3D_DevDriv_2Contr_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Crane3D_DevDriv_2Contr_output();
  Crane3D_DevDriv_2Contr_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Crane3D_DevDriv_2Contr_output();
  Crane3D_DevDriv_2Contr_derivatives();

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
  Crane3D_DevDriv_2Contr_output();
  Crane3D_DevDriv_2Contr_derivatives();

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
  Crane3D_DevDriv_2Contr_output();
  Crane3D_DevDriv_2Contr_derivatives();

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
void Crane3D_DevDriv_2Contr_output(void)
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
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    /* set solver stop time */
    if (!(Crane3D_DevDriv_2Contr_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Crane3D_DevDriv_2Contr_M->solverInfo,
                            ((Crane3D_DevDriv_2Contr_M->Timing.clockTickH0 + 1) *
        Crane3D_DevDriv_2Contr_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Crane3D_DevDriv_2Contr_M->solverInfo,
                            ((Crane3D_DevDriv_2Contr_M->Timing.clockTick0 + 1) *
        Crane3D_DevDriv_2Contr_M->Timing.stepSize0 +
        Crane3D_DevDriv_2Contr_M->Timing.clockTickH0 *
        Crane3D_DevDriv_2Contr_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    Crane3D_DevDriv_2Contr_M->Timing.t[0] = rtsiGetT
      (&Crane3D_DevDriv_2Contr_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  Crane3D_DevDriv_2Contr_B.Clock = Crane3D_DevDriv_2Contr_M->Timing.t[0];
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    /* Level2 S-Function Block: '<S3>/Encoder' (Crane3D_Encoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S3>/Encoder 500PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder500PPR[i] = Crane3D_DevDriv_2Contr_P.Encoder500PPR_Gain *
        Crane3D_DevDriv_2Contr_B.Encoder[i];
    }

    /* End of Gain: '<S3>/Encoder 500PPR' */

    /* Gain: '<S3>/X Scale' */
    Crane3D_DevDriv_2Contr_B.XScale = Crane3D_DevDriv_2Contr_P.XScale_Gain *
      rtb_Encoder500PPR[0];

    /* Gain: '<S3>/Y Scale' */
    Crane3D_DevDriv_2Contr_B.YScale = Crane3D_DevDriv_2Contr_P.YScale_Gain *
      rtb_Encoder500PPR[1];

    /* Gain: '<S3>/X Angle Scale' */
    Crane3D_DevDriv_2Contr_B.XAngleScale =
      Crane3D_DevDriv_2Contr_P.XAngleScale_Gain * rtb_Encoder500PPR[3];

    /* Gain: '<S3>/Y Angle Scale' */
    Crane3D_DevDriv_2Contr_B.YAngleScale =
      Crane3D_DevDriv_2Contr_P.YAngleScale_Gain * rtb_Encoder500PPR[4];

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
    Crane3D_DevDriv_2Contr_B.x_l = sin(Crane3D_DevDriv_2Contr_B.XAngleScale +
      1.5707963267948966) * 0.3 * sin(Crane3D_DevDriv_2Contr_B.YAngleScale) +
      Crane3D_DevDriv_2Contr_B.XScale;

    /* '<S2>:1:17' */
    Crane3D_DevDriv_2Contr_B.y_f = cos(Crane3D_DevDriv_2Contr_B.XAngleScale +
      1.5707963267948966) * 0.3 + Crane3D_DevDriv_2Contr_B.YScale;

    /* MATLAB Function: '<Root>/Select most convenient path' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* MATLAB Function 'Select most convenient path': '<S4>:1' */
    /* % Random default values - dont touch */
    /* '<S4>:1:9' */
    x = 0.252;

    /* '<S4>:1:10' */
    y = 0.365;

    /* '<S4>:1:11' */
    rtb_stop = 0.0;
    if (Crane3D_DevDriv_2Contr_DW.WP_Index <= 10.0) {
      /* '<S4>:1:12' */
      /* '<S4>:1:13' */
      x = Crane3D_DevDriv_2Contr_P.waypoints[(int32_T)
        Crane3D_DevDriv_2Contr_DW.WP_Index - 1] / 100.0;

      /* '<S4>:1:14' */
      y = Crane3D_DevDriv_2Contr_P.waypoints[(int32_T)
        Crane3D_DevDriv_2Contr_DW.WP_Index + 9] / 100.0;

      /*     %% Establish boundary conditions and controller class */
      /* '<S4>:1:17' */
      x_max = x + 0.02;

      /* '<S4>:1:18' */
      x_min = x - 0.02;

      /* '<S4>:1:19' */
      y_max = y + 0.02;

      /* '<S4>:1:20' */
      y_min = y - 0.02;
      if (Crane3D_DevDriv_2Contr_P.waypoints[(int32_T)
          Crane3D_DevDriv_2Contr_DW.WP_Index + 39] == 1.0) {
        /* '<S4>:1:22' */
        /* '<S4>:1:23' */
        x_max = x + 0.01;

        /* '<S4>:1:24' */
        x_min = x - 0.01;

        /* '<S4>:1:25' */
        y_max = y + 0.01;

        /* '<S4>:1:26' */
        y_min = y - 0.01;
      }

      /*     %% Crane arrived to point */
      if ((Crane3D_DevDriv_2Contr_B.x_l <= x_max) &&
          (Crane3D_DevDriv_2Contr_B.x_l >= x_min) &&
          (Crane3D_DevDriv_2Contr_B.y_f <= y_max) &&
          (Crane3D_DevDriv_2Contr_B.y_f >= y_min)) {
        /* '<S4>:1:31' */
        /* '<S4>:1:32' */
        Crane3D_DevDriv_2Contr_DW.WP_Index++;
        if (Crane3D_DevDriv_2Contr_DW.WP_Index > 10.0) {
          /* '<S4>:1:33' */
          /* '<S4>:1:34' */
          Crane3D_DevDriv_2Contr_DW.WP_Index--;

          /* '<S4>:1:35' */
          rtb_stop = 1.0;
        }
      }
    }

    Crane3D_DevDriv_2Contr_B.x = x;
    Crane3D_DevDriv_2Contr_B.y = y;

    /* End of MATLAB Function: '<Root>/Select most convenient path' */

    /* Stop: '<Root>/Stop Simulation' */
    if (rtb_stop != 0.0) {
      rtmSetStopRequested(Crane3D_DevDriv_2Contr_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */

    /* Sum: '<S6>/Sum' */
    rtb_stop = Crane3D_DevDriv_2Contr_B.x - Crane3D_DevDriv_2Contr_B.XScale;

    /* Gain: '<S7>/Proportional Gain' */
    Crane3D_DevDriv_2Contr_B.ProportionalGain = Crane3D_DevDriv_2Contr_P.PC1x *
      rtb_stop;

    /* Gain: '<S7>/Derivative Gain' */
    Crane3D_DevDriv_2Contr_B.DerivativeGain = Crane3D_DevDriv_2Contr_P.DC1x *
      rtb_stop;

    /* Sum: '<S6>/Sum3' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtb_Sum3 = Crane3D_DevDriv_2Contr_B.XAngleScale -
      Crane3D_DevDriv_2Contr_P.Constant_Value;

    /* Gain: '<S8>/Proportional Gain' */
    Crane3D_DevDriv_2Contr_B.ProportionalGain_j =
      Crane3D_DevDriv_2Contr_P.AnglePX * rtb_Sum3;

    /* Gain: '<S8>/Derivative Gain' */
    Crane3D_DevDriv_2Contr_B.DerivativeGain_f = Crane3D_DevDriv_2Contr_P.AngleDX
      * rtb_Sum3;
  }

  /* Gain: '<S7>/Filter Coefficient' incorporates:
   *  Integrator: '<S7>/Filter'
   *  Sum: '<S7>/SumD'
   */
  Crane3D_DevDriv_2Contr_B.FilterCoefficient =
    (Crane3D_DevDriv_2Contr_B.DerivativeGain -
     Crane3D_DevDriv_2Contr_X.Filter_CSTATE) *
    Crane3D_DevDriv_2Contr_P.PIDController_N;

  /* Gain: '<S8>/Filter Coefficient' incorporates:
   *  Integrator: '<S8>/Filter'
   *  Sum: '<S8>/SumD'
   */
  Crane3D_DevDriv_2Contr_B.FilterCoefficient_g =
    (Crane3D_DevDriv_2Contr_B.DerivativeGain_f -
     Crane3D_DevDriv_2Contr_X.Filter_CSTATE_p) *
    Crane3D_DevDriv_2Contr_P.PIDController1_N;

  /* Sum: '<S6>/Sum2' incorporates:
   *  Integrator: '<S7>/Integrator'
   *  Integrator: '<S8>/Integrator'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S8>/Sum'
   */
  x_max = ((Crane3D_DevDriv_2Contr_B.ProportionalGain +
            Crane3D_DevDriv_2Contr_X.Integrator_CSTATE) +
           Crane3D_DevDriv_2Contr_B.FilterCoefficient) +
    ((Crane3D_DevDriv_2Contr_B.ProportionalGain_j +
      Crane3D_DevDriv_2Contr_X.Integrator_CSTATE_b) +
     Crane3D_DevDriv_2Contr_B.FilterCoefficient_g);
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    /* Sum: '<S6>/Sum1' */
    rtb_yerror = Crane3D_DevDriv_2Contr_B.y - Crane3D_DevDriv_2Contr_B.YScale;

    /* Gain: '<S10>/Proportional Gain' */
    Crane3D_DevDriv_2Contr_B.ProportionalGain_o = Crane3D_DevDriv_2Contr_P.PC1y *
      rtb_yerror;

    /* Gain: '<S10>/Derivative Gain' */
    Crane3D_DevDriv_2Contr_B.DerivativeGain_c = Crane3D_DevDriv_2Contr_P.DC1y *
      rtb_yerror;

    /* Sum: '<S6>/Sum5' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    rtb_Sum5 = Crane3D_DevDriv_2Contr_B.YAngleScale -
      Crane3D_DevDriv_2Contr_P.Constant1_Value;

    /* Gain: '<S9>/Proportional Gain' */
    Crane3D_DevDriv_2Contr_B.ProportionalGain_f =
      Crane3D_DevDriv_2Contr_P.AnglePY * rtb_Sum5;

    /* Gain: '<S9>/Derivative Gain' */
    Crane3D_DevDriv_2Contr_B.DerivativeGain_m = Crane3D_DevDriv_2Contr_P.AngleDY
      * rtb_Sum5;
  }

  /* Gain: '<S10>/Filter Coefficient' incorporates:
   *  Integrator: '<S10>/Filter'
   *  Sum: '<S10>/SumD'
   */
  Crane3D_DevDriv_2Contr_B.FilterCoefficient_e =
    (Crane3D_DevDriv_2Contr_B.DerivativeGain_c -
     Crane3D_DevDriv_2Contr_X.Filter_CSTATE_p4) *
    Crane3D_DevDriv_2Contr_P.PIDController5_N;

  /* Gain: '<S9>/Filter Coefficient' incorporates:
   *  Integrator: '<S9>/Filter'
   *  Sum: '<S9>/SumD'
   */
  Crane3D_DevDriv_2Contr_B.FilterCoefficient_o =
    (Crane3D_DevDriv_2Contr_B.DerivativeGain_m -
     Crane3D_DevDriv_2Contr_X.Filter_CSTATE_n) *
    Crane3D_DevDriv_2Contr_P.PIDController2_N;

  /* Sum: '<S6>/Sum4' incorporates:
   *  Integrator: '<S10>/Integrator'
   *  Integrator: '<S9>/Integrator'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S9>/Sum'
   */
  x_min = ((Crane3D_DevDriv_2Contr_B.ProportionalGain_o +
            Crane3D_DevDriv_2Contr_X.Integrator_CSTATE_d) +
           Crane3D_DevDriv_2Contr_B.FilterCoefficient_e) +
    ((Crane3D_DevDriv_2Contr_B.ProportionalGain_f +
      Crane3D_DevDriv_2Contr_X.Integrator_CSTATE_a) +
     Crane3D_DevDriv_2Contr_B.FilterCoefficient_o);

  /* MATLAB Function: '<S1>/Enforce Soft Limits and Overflow' incorporates:
   *  Constant: '<Root>/X_range'
   *  Constant: '<Root>/Y_range '
   */
  x = Crane3D_DevDriv_2Contr_B.XScale;
  y = Crane3D_DevDriv_2Contr_B.YScale;

  /* MATLAB Function 'Controller/Enforce Soft Limits and Overflow': '<S5>:1' */
  /* '<S5>:1:3' */
  /* '<S5>:1:4' */
  /* '<S5>:1:5' */
  y_max = x_max;

  /* '<S5>:1:6' */
  y_min = x_min;

  /*  Deal with overflow - may not be the most appropriate place */
  if ((Crane3D_DevDriv_2Contr_B.XScale > 10.0) ||
      (Crane3D_DevDriv_2Contr_B.XScale < -10.0)) {
    /* '<S5>:1:9' */
    /* '<S5>:1:10' */
    x = 0.0;
  }

  if ((Crane3D_DevDriv_2Contr_B.YScale > 10.0) ||
      (Crane3D_DevDriv_2Contr_B.YScale < -10.0)) {
    /* '<S5>:1:12' */
    /* '<S5>:1:13' */
    y = 0.0;
  }

  /*  Put in place soft boundaries on the borders */
  if ((x > Crane3D_DevDriv_2Contr_P.xRange[1] - 0.08) && (!(x_max <= 0.0))) {
    /* '<S5>:1:17' */
    /* '<S5>:1:18' */
    y_max = 0.0;
  }

  if (x < Crane3D_DevDriv_2Contr_P.xRange[0] + 0.08) {
    /* '<S5>:1:21' */
    /* '<S5>:1:22' */
    if (x_max >= 0.0) {
      y_max = x_max;
    } else {
      y_max = 0.0;
    }
  }

  if ((y > Crane3D_DevDriv_2Contr_P.yRange[1] - 0.08) && (!(x_min <= 0.0))) {
    /* '<S5>:1:26' */
    /* '<S5>:1:27' */
    y_min = 0.0;
  }

  if (y < Crane3D_DevDriv_2Contr_P.yRange[0] + 0.08) {
    /* '<S5>:1:30' */
    /* '<S5>:1:31' */
    if (x_min >= 0.0) {
      y_min = x_min;
    } else {
      y_min = 0.0;
    }
  }

  /* End of MATLAB Function: '<S1>/Enforce Soft Limits and Overflow' */
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    /* Gain: '<S7>/Integral Gain' */
    Crane3D_DevDriv_2Contr_B.IntegralGain = Crane3D_DevDriv_2Contr_P.IC1x *
      rtb_stop;

    /* Gain: '<S8>/Integral Gain' */
    Crane3D_DevDriv_2Contr_B.IntegralGain_a = Crane3D_DevDriv_2Contr_P.AngleIX *
      rtb_Sum3;

    /* Gain: '<S9>/Integral Gain' */
    Crane3D_DevDriv_2Contr_B.IntegralGain_p = Crane3D_DevDriv_2Contr_P.AngleIY *
      rtb_Sum5;

    /* Gain: '<S10>/Integral Gain' */
    Crane3D_DevDriv_2Contr_B.IntegralGain_g = Crane3D_DevDriv_2Contr_P.IC1y *
      rtb_yerror;

    /* Level2 S-Function Block: '<S3>/PWM' (Crane3D_PWM) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (y_max > Crane3D_DevDriv_2Contr_P.Saturation_UpperSat) {
    Crane3D_DevDriv_2Contr_B.Saturation[0] =
      Crane3D_DevDriv_2Contr_P.Saturation_UpperSat;
  } else if (y_max < Crane3D_DevDriv_2Contr_P.Saturation_LowerSat) {
    Crane3D_DevDriv_2Contr_B.Saturation[0] =
      Crane3D_DevDriv_2Contr_P.Saturation_LowerSat;
  } else {
    Crane3D_DevDriv_2Contr_B.Saturation[0] = y_max;
  }

  if (y_min > Crane3D_DevDriv_2Contr_P.Saturation_UpperSat) {
    Crane3D_DevDriv_2Contr_B.Saturation[1] =
      Crane3D_DevDriv_2Contr_P.Saturation_UpperSat;
  } else if (y_min < Crane3D_DevDriv_2Contr_P.Saturation_LowerSat) {
    Crane3D_DevDriv_2Contr_B.Saturation[1] =
      Crane3D_DevDriv_2Contr_P.Saturation_LowerSat;
  } else {
    Crane3D_DevDriv_2Contr_B.Saturation[1] = y_min;
  }

  if (Crane3D_DevDriv_2Contr_P.Constant_Value_f >
      Crane3D_DevDriv_2Contr_P.Saturation_UpperSat) {
    Crane3D_DevDriv_2Contr_B.Saturation[2] =
      Crane3D_DevDriv_2Contr_P.Saturation_UpperSat;
  } else if (Crane3D_DevDriv_2Contr_P.Constant_Value_f <
             Crane3D_DevDriv_2Contr_P.Saturation_LowerSat) {
    Crane3D_DevDriv_2Contr_B.Saturation[2] =
      Crane3D_DevDriv_2Contr_P.Saturation_LowerSat;
  } else {
    Crane3D_DevDriv_2Contr_B.Saturation[2] =
      Crane3D_DevDriv_2Contr_P.Constant_Value_f;
  }

  /* End of Saturate: '<S3>/Saturation' */
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    /* Level2 S-Function Block: '<S3>/LimitFlag' (Crane3D_LimitFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[0] =
      Crane3D_DevDriv_2Contr_P.LimitFlagSource_Value[0];

    /* Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_2Contr_B.LimitSource[0] =
      Crane3D_DevDriv_2Contr_P.LimitSource_Value[0];

    /* Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[1] =
      Crane3D_DevDriv_2Contr_P.LimitFlagSource_Value[1];

    /* Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_2Contr_B.LimitSource[1] =
      Crane3D_DevDriv_2Contr_P.LimitSource_Value[1];

    /* Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[2] =
      Crane3D_DevDriv_2Contr_P.LimitFlagSource_Value[2];

    /* Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_2Contr_B.LimitSource[2] =
      Crane3D_DevDriv_2Contr_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S3>/SetLimit' (Crane3D_SetLimit) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/LimitSwitch' (Crane3D_Switch) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/PWMPrescalerSource' */
    Crane3D_DevDriv_2Contr_B.PWMPrescalerSource =
      Crane3D_DevDriv_2Contr_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S3>/ResetEncoder' (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ResetSource' */
    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_2Contr_B.ResetSource[i] =
        Crane3D_DevDriv_2Contr_P.ResetSource_Value[i];
    }

    /* End of Constant: '<S3>/ResetSource' */

    /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ResetSwitchFlagSource' */
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[0] =
      Crane3D_DevDriv_2Contr_P.ResetSwitchFlagSource_Value[0];
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[1] =
      Crane3D_DevDriv_2Contr_P.ResetSwitchFlagSource_Value[1];
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[2] =
      Crane3D_DevDriv_2Contr_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S3>/ThermFlag ' (Crane3D_ThermFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S3>/ThermFlagSource' */
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[0] =
      Crane3D_DevDriv_2Contr_P.ThermFlagSource_Value[0];
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[1] =
      Crane3D_DevDriv_2Contr_P.ThermFlagSource_Value[1];
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[2] =
      Crane3D_DevDriv_2Contr_P.ThermFlagSource_Value[2];
  }
}

/* Model update function */
void Crane3D_DevDriv_2Contr_update(void)
{
  if (rtmIsMajorTimeStep(Crane3D_DevDriv_2Contr_M)) {
    rt_ertODEUpdateContinuousStates(&Crane3D_DevDriv_2Contr_M->solverInfo);
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
  if (!(++Crane3D_DevDriv_2Contr_M->Timing.clockTick0)) {
    ++Crane3D_DevDriv_2Contr_M->Timing.clockTickH0;
  }

  Crane3D_DevDriv_2Contr_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Crane3D_DevDriv_2Contr_M->solverInfo);

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
    if (!(++Crane3D_DevDriv_2Contr_M->Timing.clockTick1)) {
      ++Crane3D_DevDriv_2Contr_M->Timing.clockTickH1;
    }

    Crane3D_DevDriv_2Contr_M->Timing.t[1] =
      Crane3D_DevDriv_2Contr_M->Timing.clockTick1 *
      Crane3D_DevDriv_2Contr_M->Timing.stepSize1 +
      Crane3D_DevDriv_2Contr_M->Timing.clockTickH1 *
      Crane3D_DevDriv_2Contr_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Crane3D_DevDriv_2Contr_derivatives(void)
{
  XDot_Crane3D_DevDriv_2Contr_T *_rtXdot;
  _rtXdot = ((XDot_Crane3D_DevDriv_2Contr_T *)
             Crane3D_DevDriv_2Contr_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = Crane3D_DevDriv_2Contr_B.IntegralGain;

  /* Derivatives for Integrator: '<S7>/Filter' */
  _rtXdot->Filter_CSTATE = Crane3D_DevDriv_2Contr_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = Crane3D_DevDriv_2Contr_B.IntegralGain_a;

  /* Derivatives for Integrator: '<S8>/Filter' */
  _rtXdot->Filter_CSTATE_p = Crane3D_DevDriv_2Contr_B.FilterCoefficient_g;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = Crane3D_DevDriv_2Contr_B.IntegralGain_g;

  /* Derivatives for Integrator: '<S10>/Filter' */
  _rtXdot->Filter_CSTATE_p4 = Crane3D_DevDriv_2Contr_B.FilterCoefficient_e;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = Crane3D_DevDriv_2Contr_B.IntegralGain_p;

  /* Derivatives for Integrator: '<S9>/Filter' */
  _rtXdot->Filter_CSTATE_n = Crane3D_DevDriv_2Contr_B.FilterCoefficient_o;
}

/* Model initialize function */
void Crane3D_DevDriv_2Contr_initialize(void)
{
  {
    int32_T i;

    /* Start for Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[0] =
      Crane3D_DevDriv_2Contr_P.LimitFlagSource_Value[0];

    /* Start for Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_2Contr_B.LimitSource[0] =
      Crane3D_DevDriv_2Contr_P.LimitSource_Value[0];

    /* Start for Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[1] =
      Crane3D_DevDriv_2Contr_P.LimitFlagSource_Value[1];

    /* Start for Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_2Contr_B.LimitSource[1] =
      Crane3D_DevDriv_2Contr_P.LimitSource_Value[1];

    /* Start for Constant: '<S3>/LimitFlagSource' */
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[2] =
      Crane3D_DevDriv_2Contr_P.LimitFlagSource_Value[2];

    /* Start for Constant: '<S3>/LimitSource' */
    Crane3D_DevDriv_2Contr_B.LimitSource[2] =
      Crane3D_DevDriv_2Contr_P.LimitSource_Value[2];

    /* Start for Constant: '<S3>/PWMPrescalerSource' */
    Crane3D_DevDriv_2Contr_B.PWMPrescalerSource =
      Crane3D_DevDriv_2Contr_P.PWMPrescalerSource_Value;

    /* Start for Constant: '<S3>/ResetSource' */
    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_2Contr_B.ResetSource[i] =
        Crane3D_DevDriv_2Contr_P.ResetSource_Value[i];
    }

    /* End of Start for Constant: '<S3>/ResetSource' */
    /* Start for Constant: '<S3>/ResetSwitchFlagSource' */
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[0] =
      Crane3D_DevDriv_2Contr_P.ResetSwitchFlagSource_Value[0];
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[1] =
      Crane3D_DevDriv_2Contr_P.ResetSwitchFlagSource_Value[1];
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[2] =
      Crane3D_DevDriv_2Contr_P.ResetSwitchFlagSource_Value[2];

    /* Start for Constant: '<S3>/ThermFlagSource' */
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[0] =
      Crane3D_DevDriv_2Contr_P.ThermFlagSource_Value[0];
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[1] =
      Crane3D_DevDriv_2Contr_P.ThermFlagSource_Value[1];
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[2] =
      Crane3D_DevDriv_2Contr_P.ThermFlagSource_Value[2];
  }

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  Crane3D_DevDriv_2Contr_X.Integrator_CSTATE =
    Crane3D_DevDriv_2Contr_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S7>/Filter' */
  Crane3D_DevDriv_2Contr_X.Filter_CSTATE = Crane3D_DevDriv_2Contr_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  Crane3D_DevDriv_2Contr_X.Integrator_CSTATE_b =
    Crane3D_DevDriv_2Contr_P.Integrator_IC_e;

  /* InitializeConditions for Integrator: '<S8>/Filter' */
  Crane3D_DevDriv_2Contr_X.Filter_CSTATE_p =
    Crane3D_DevDriv_2Contr_P.Filter_IC_k;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  Crane3D_DevDriv_2Contr_X.Integrator_CSTATE_d =
    Crane3D_DevDriv_2Contr_P.Integrator_IC_c;

  /* InitializeConditions for Integrator: '<S10>/Filter' */
  Crane3D_DevDriv_2Contr_X.Filter_CSTATE_p4 =
    Crane3D_DevDriv_2Contr_P.Filter_IC_a;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  Crane3D_DevDriv_2Contr_X.Integrator_CSTATE_a =
    Crane3D_DevDriv_2Contr_P.Integrator_IC_k;

  /* InitializeConditions for Integrator: '<S9>/Filter' */
  Crane3D_DevDriv_2Contr_X.Filter_CSTATE_n =
    Crane3D_DevDriv_2Contr_P.Filter_IC_d;

  /* SystemInitialize for MATLAB Function: '<Root>/Select most convenient path' */
  Crane3D_DevDriv_2Contr_DW.WP_Index = 1.0;
}

/* Model terminate function */
void Crane3D_DevDriv_2Contr_terminate(void)
{
  /* Level2 S-Function Block: '<S3>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S3>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[8];
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
  Crane3D_DevDriv_2Contr_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Crane3D_DevDriv_2Contr_update();
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
  Crane3D_DevDriv_2Contr_initialize();
}

void MdlTerminate(void)
{
  Crane3D_DevDriv_2Contr_terminate();
}

/* Registration function */
RT_MODEL_Crane3D_DevDriv_2Contr_T *Crane3D_DevDriv_2Contr(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Crane3D_DevDriv_2Contr_M, 0,
                sizeof(RT_MODEL_Crane3D_DevDriv_2Contr_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
                          &Crane3D_DevDriv_2Contr_M->Timing.simTimeStep);
    rtsiSetTPtr(&Crane3D_DevDriv_2Contr_M->solverInfo, &rtmGetTPtr
                (Crane3D_DevDriv_2Contr_M));
    rtsiSetStepSizePtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
                       &Crane3D_DevDriv_2Contr_M->Timing.stepSize0);
    rtsiSetdXPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
                 &Crane3D_DevDriv_2Contr_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Crane3D_DevDriv_2Contr_M->solverInfo, (real_T **)
                         &Crane3D_DevDriv_2Contr_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
      &Crane3D_DevDriv_2Contr_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
      &Crane3D_DevDriv_2Contr_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
      &Crane3D_DevDriv_2Contr_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
      &Crane3D_DevDriv_2Contr_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
                          (&rtmGetErrorStatus(Crane3D_DevDriv_2Contr_M)));
    rtsiSetRTModelPtr(&Crane3D_DevDriv_2Contr_M->solverInfo,
                      Crane3D_DevDriv_2Contr_M);
  }

  rtsiSetSimTimeStep(&Crane3D_DevDriv_2Contr_M->solverInfo, MAJOR_TIME_STEP);
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.y =
    Crane3D_DevDriv_2Contr_M->ModelData.odeY;
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.f[0] =
    Crane3D_DevDriv_2Contr_M->ModelData.odeF[0];
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.f[1] =
    Crane3D_DevDriv_2Contr_M->ModelData.odeF[1];
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.f[2] =
    Crane3D_DevDriv_2Contr_M->ModelData.odeF[2];
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.f[3] =
    Crane3D_DevDriv_2Contr_M->ModelData.odeF[3];
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.f[4] =
    Crane3D_DevDriv_2Contr_M->ModelData.odeF[4];
  Crane3D_DevDriv_2Contr_M->ModelData.intgData.f[5] =
    Crane3D_DevDriv_2Contr_M->ModelData.odeF[5];
  Crane3D_DevDriv_2Contr_M->ModelData.contStates = ((real_T *)
    &Crane3D_DevDriv_2Contr_X);
  rtsiSetSolverData(&Crane3D_DevDriv_2Contr_M->solverInfo, (void *)
                    &Crane3D_DevDriv_2Contr_M->ModelData.intgData);
  rtsiSetSolverName(&Crane3D_DevDriv_2Contr_M->solverInfo,"ode5");
  Crane3D_DevDriv_2Contr_M->solverInfoPtr =
    (&Crane3D_DevDriv_2Contr_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Crane3D_DevDriv_2Contr_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Crane3D_DevDriv_2Contr_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Crane3D_DevDriv_2Contr_M->Timing.sampleTimes =
      (&Crane3D_DevDriv_2Contr_M->Timing.sampleTimesArray[0]);
    Crane3D_DevDriv_2Contr_M->Timing.offsetTimes =
      (&Crane3D_DevDriv_2Contr_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Crane3D_DevDriv_2Contr_M->Timing.sampleTimes[0] = (0.0);
    Crane3D_DevDriv_2Contr_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Crane3D_DevDriv_2Contr_M->Timing.offsetTimes[0] = (0.0);
    Crane3D_DevDriv_2Contr_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Crane3D_DevDriv_2Contr_M, &Crane3D_DevDriv_2Contr_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = Crane3D_DevDriv_2Contr_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Crane3D_DevDriv_2Contr_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Crane3D_DevDriv_2Contr_M, 60.0);
  Crane3D_DevDriv_2Contr_M->Timing.stepSize0 = 0.01;
  Crane3D_DevDriv_2Contr_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  Crane3D_DevDriv_2Contr_M->Sizes.checksums[0] = (3662513070U);
  Crane3D_DevDriv_2Contr_M->Sizes.checksums[1] = (1748753832U);
  Crane3D_DevDriv_2Contr_M->Sizes.checksums[2] = (3263596883U);
  Crane3D_DevDriv_2Contr_M->Sizes.checksums[3] = (516135558U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Crane3D_DevDriv_2Contr_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Crane3D_DevDriv_2Contr_M->extModeInfo,
      &Crane3D_DevDriv_2Contr_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Crane3D_DevDriv_2Contr_M->extModeInfo,
                        Crane3D_DevDriv_2Contr_M->Sizes.checksums);
    rteiSetTPtr(Crane3D_DevDriv_2Contr_M->extModeInfo, rtmGetTPtr
                (Crane3D_DevDriv_2Contr_M));
  }

  Crane3D_DevDriv_2Contr_M->solverInfoPtr =
    (&Crane3D_DevDriv_2Contr_M->solverInfo);
  Crane3D_DevDriv_2Contr_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Crane3D_DevDriv_2Contr_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Crane3D_DevDriv_2Contr_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Crane3D_DevDriv_2Contr_M->ModelData.blockIO = ((void *)
    &Crane3D_DevDriv_2Contr_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_2Contr_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_2Contr_B.ResetEncoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Crane3D_DevDriv_2Contr_B.ResetSource[i] = 0.0;
    }

    Crane3D_DevDriv_2Contr_B.Clock = 0.0;
    Crane3D_DevDriv_2Contr_B.XScale = 0.0;
    Crane3D_DevDriv_2Contr_B.YScale = 0.0;
    Crane3D_DevDriv_2Contr_B.XAngleScale = 0.0;
    Crane3D_DevDriv_2Contr_B.YAngleScale = 0.0;
    Crane3D_DevDriv_2Contr_B.ProportionalGain = 0.0;
    Crane3D_DevDriv_2Contr_B.DerivativeGain = 0.0;
    Crane3D_DevDriv_2Contr_B.FilterCoefficient = 0.0;
    Crane3D_DevDriv_2Contr_B.ProportionalGain_j = 0.0;
    Crane3D_DevDriv_2Contr_B.DerivativeGain_f = 0.0;
    Crane3D_DevDriv_2Contr_B.FilterCoefficient_g = 0.0;
    Crane3D_DevDriv_2Contr_B.ProportionalGain_o = 0.0;
    Crane3D_DevDriv_2Contr_B.DerivativeGain_c = 0.0;
    Crane3D_DevDriv_2Contr_B.FilterCoefficient_e = 0.0;
    Crane3D_DevDriv_2Contr_B.ProportionalGain_f = 0.0;
    Crane3D_DevDriv_2Contr_B.DerivativeGain_m = 0.0;
    Crane3D_DevDriv_2Contr_B.FilterCoefficient_o = 0.0;
    Crane3D_DevDriv_2Contr_B.IntegralGain = 0.0;
    Crane3D_DevDriv_2Contr_B.IntegralGain_a = 0.0;
    Crane3D_DevDriv_2Contr_B.IntegralGain_p = 0.0;
    Crane3D_DevDriv_2Contr_B.IntegralGain_g = 0.0;
    Crane3D_DevDriv_2Contr_B.PWM[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.PWM[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.PWM[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.Saturation[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.Saturation[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.Saturation[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitFlag[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitFlag[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitFlag[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitFlagSource[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitSource[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitSource[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitSource[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.SetLimit[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.SetLimit[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.SetLimit[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitSwitch[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitSwitch[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.LimitSwitch[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.PWMPrescaler = 0.0;
    Crane3D_DevDriv_2Contr_B.PWMPrescalerSource = 0.0;
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlag[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlag[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlag[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.ThermFlag[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.ThermFlag[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.ThermFlag[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[0] = 0.0;
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[1] = 0.0;
    Crane3D_DevDriv_2Contr_B.ThermFlagSource[2] = 0.0;
    Crane3D_DevDriv_2Contr_B.x = 0.0;
    Crane3D_DevDriv_2Contr_B.y = 0.0;
    Crane3D_DevDriv_2Contr_B.x_l = 0.0;
    Crane3D_DevDriv_2Contr_B.y_f = 0.0;
  }

  /* parameters */
  Crane3D_DevDriv_2Contr_M->ModelData.defaultParam = ((real_T *)
    &Crane3D_DevDriv_2Contr_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Crane3D_DevDriv_2Contr_X;
    Crane3D_DevDriv_2Contr_M->ModelData.contStates = (x);
    (void) memset((void *)&Crane3D_DevDriv_2Contr_X, 0,
                  sizeof(X_Crane3D_DevDriv_2Contr_T));
  }

  /* states (dwork) */
  Crane3D_DevDriv_2Contr_M->ModelData.dwork = ((void *)
    &Crane3D_DevDriv_2Contr_DW);
  (void) memset((void *)&Crane3D_DevDriv_2Contr_DW, 0,
                sizeof(DW_Crane3D_DevDriv_2Contr_T));
  Crane3D_DevDriv_2Contr_DW.WP_Index = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Crane3D_DevDriv_2Contr_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.sfcnInfo;
    Crane3D_DevDriv_2Contr_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Crane3D_DevDriv_2Contr_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Crane3D_DevDriv_2Contr_M->Sizes.numSampTimes);
    Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Crane3D_DevDriv_2Contr_M)[0]);
    Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Crane3D_DevDriv_2Contr_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Crane3D_DevDriv_2Contr_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Crane3D_DevDriv_2Contr_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Crane3D_DevDriv_2Contr_M));
    rtssSetStepSizePtr(sfcnInfo, &Crane3D_DevDriv_2Contr_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Crane3D_DevDriv_2Contr_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Crane3D_DevDriv_2Contr_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Crane3D_DevDriv_2Contr_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &Crane3D_DevDriv_2Contr_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Crane3D_DevDriv_2Contr_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Crane3D_DevDriv_2Contr_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Crane3D_DevDriv_2Contr_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Crane3D_DevDriv_2Contr_M->solverInfoPtr);
  }

  Crane3D_DevDriv_2Contr_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)
                  &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    Crane3D_DevDriv_2Contr_M->childSfunctions =
      (&Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        Crane3D_DevDriv_2Contr_M->childSfunctions[i] =
          (&Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/Encoder (Crane3D_Encoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/Encoder");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/PWM (Crane3D_PWM) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_2Contr_B.Saturation;
          sfcnUPtrs[1] = &Crane3D_DevDriv_2Contr_B.Saturation[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_2Contr_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Crane3D_DevDriv_2Contr_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/PWM");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Crane3D_DevDriv_2Contr_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Crane3D_DevDriv_2Contr_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/LimitFlag (Crane3D_LimitFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_2Contr_B.LimitFlagSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_2Contr_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_2Contr_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/LimitFlag");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/SetLimit (Crane3D_SetLimit) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_2Contr_B.LimitSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_2Contr_B.LimitSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_2Contr_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/SetLimit");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/LimitSwitch (Crane3D_Switch) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/LimitSwitch");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/PWMPrescaler (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &Crane3D_DevDriv_2Contr_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Crane3D_DevDriv_2Contr_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/PWMPrescaler");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/ResetEncoder (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = Crane3D_DevDriv_2Contr_B.ResetSource;
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
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/ResetEncoder");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/ResetSwitchFlag  (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_2Contr_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/ResetSwitchFlag ");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: Crane3D_DevDriv_2Contr/<S3>/ThermFlag  (Crane3D_ThermFlag) */
    {
      SimStruct *rts = Crane3D_DevDriv_2Contr_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
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
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, Crane3D_DevDriv_2Contr_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.statesInfo2
                         [8]);
        ssSetPeriodicStatesInfo(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = Crane3D_DevDriv_2Contr_B.ThermFlagSource;
          sfcnUPtrs[1] = &Crane3D_DevDriv_2Contr_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &Crane3D_DevDriv_2Contr_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Crane3D_DevDriv_2Contr_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Crane3D_DevDriv_2Contr/Crane 3D/ThermFlag ");
      ssSetRTModel(rts,Crane3D_DevDriv_2Contr_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Crane3D_DevDriv_2Contr_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Crane3D_DevDriv_2Contr_P.ThermFlag_P2_Size);
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
  Crane3D_DevDriv_2Contr_M->Sizes.numContStates = (8);/* Number of continuous states */
  Crane3D_DevDriv_2Contr_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Crane3D_DevDriv_2Contr_M->Sizes.numY = (0);/* Number of model outputs */
  Crane3D_DevDriv_2Contr_M->Sizes.numU = (0);/* Number of model inputs */
  Crane3D_DevDriv_2Contr_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Crane3D_DevDriv_2Contr_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Crane3D_DevDriv_2Contr_M->Sizes.numBlocks = (82);/* Number of blocks */
  Crane3D_DevDriv_2Contr_M->Sizes.numBlockIO = (41);/* Number of block outputs */
  Crane3D_DevDriv_2Contr_M->Sizes.numBlockPrms = (160);/* Sum of parameter "widths" */
  return Crane3D_DevDriv_2Contr_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
