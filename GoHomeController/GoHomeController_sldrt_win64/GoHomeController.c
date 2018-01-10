/*
 * GoHomeController.c
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
#include "GoHomeController_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_GoHomeController_T GoHomeController_B;

/* Continuous states */
X_GoHomeController_T GoHomeController_X;

/* Block states (auto storage) */
DW_GoHomeController_T GoHomeController_DW;

/* Real-time model */
RT_MODEL_GoHomeController_T GoHomeController_M_;
RT_MODEL_GoHomeController_T *const GoHomeController_M = &GoHomeController_M_;

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
  GoHomeController_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  GoHomeController_output();
  GoHomeController_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  GoHomeController_output();
  GoHomeController_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  GoHomeController_output();
  GoHomeController_derivatives();

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
  GoHomeController_output();
  GoHomeController_derivatives();

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
  GoHomeController_output();
  GoHomeController_derivatives();

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

/*
 * Output and update for atomic system:
 *    '<S2>/X Overflow Protection'
 *    '<S2>/Y Overflow Protection1'
 */
void GoHomeController_XOverflowProtection(real_T rtu_u,
  B_XOverflowProtection_GoHomeController_T *localB)
{
  /* MATLAB Function 'Crane (hardware)/X Overflow Protection': '<S10>:1' */
  /* '<S10>:1:3' */
  localB->y = rtu_u;
  if (rtu_u > 2.0) {
    /* '<S10>:1:4' */
    /* '<S10>:1:5' */
    localB->y = 0.0;
  }
}

/* Model output function */
void GoHomeController_output(void)
{
  int32_T j;
  int32_T memOffset;
  int32_T denIdx;
  real_T rtb_Encoder500PPR[5];
  real_T rtb_Inputs[2];
  real_T rtb_PulseGenerator;
  boolean_T rtb_And2;
  real_T Derivatives[5];
  int32_T i;
  real_T tmp[10];
  real_T tmp_0[2];
  real_T rtb_LimitSwitchGain_idx_0;
  real_T rtb_LimitSwitchGain_idx_1;
  real_T tmp_1;
  if (rtmIsMajorTimeStep(GoHomeController_M)) {
    /* set solver stop time */
    if (!(GoHomeController_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&GoHomeController_M->solverInfo,
                            ((GoHomeController_M->Timing.clockTickH0 + 1) *
        GoHomeController_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&GoHomeController_M->solverInfo,
                            ((GoHomeController_M->Timing.clockTick0 + 1) *
        GoHomeController_M->Timing.stepSize0 +
        GoHomeController_M->Timing.clockTickH0 *
        GoHomeController_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(GoHomeController_M)) {
    GoHomeController_M->Timing.t[0] = rtsiGetT(&GoHomeController_M->solverInfo);
  }

  /* TransferFcn: '<S2>/Transfer Fcn3' */
  GoHomeController_B.dx2 = 0.0;
  GoHomeController_B.dx2 += GoHomeController_P.TransferFcn3_C[0] *
    GoHomeController_X.TransferFcn3_CSTATE[0];
  GoHomeController_B.dx2 += GoHomeController_P.TransferFcn3_C[1] *
    GoHomeController_X.TransferFcn3_CSTATE[1];

  /* TransferFcn: '<S2>/Transfer Fcn1' */
  GoHomeController_B.TransferFcn1 = 0.0;
  GoHomeController_B.TransferFcn1 += GoHomeController_P.TransferFcn1_C[0] *
    GoHomeController_X.TransferFcn1_CSTATE[0];
  GoHomeController_B.TransferFcn1 += GoHomeController_P.TransferFcn1_C[1] *
    GoHomeController_X.TransferFcn1_CSTATE[1];
  if (rtmIsMajorTimeStep(GoHomeController_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtHiddenToAsyncQueue_InsertedFor_Crane (hardware)_at_outport_3Inport1' */
    GoHomeController_B.vel[0] = GoHomeController_B.dx2;
    GoHomeController_B.vel[1] = GoHomeController_B.TransferFcn1;

    /* ToAsyncQueueBlock: '<Root>/HiddenToAsyncQueue_InsertedFor_Crane (hardware)_at_outport_3' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.vel[0];
        int32_T size = 2*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2153572236U, time, pData, size);
      }
    }

    /* Constant: '<Root>/Constant1' */
    GoHomeController_B.Constant1 = GoHomeController_P.Constant1_Value_c;

    /* Constant: '<Root>/Constant2' */
    GoHomeController_B.Constant2 = GoHomeController_P.Constant2_Value;

    /* Constant: '<Root>/Constant3' */
    GoHomeController_B.Constant3 = GoHomeController_P.Constant3_Value;

    /* Constant: '<S3>/Y Ref' */
    GoHomeController_B.YReference = GoHomeController_P.YRef_Value;

    /* Constant: '<S3>/Y_Dot Ref' */
    GoHomeController_B.Y_dotReference = GoHomeController_P.Y_DotRef_Value;

    /* Constant: '<S3>/X Ref' */
    GoHomeController_B.XReference = GoHomeController_P.XRef_Value;

    /* Constant: '<S3>/X_Dot Ref' */
    GoHomeController_B.X_dotReference = GoHomeController_P.X_DotRef_Value;

    /* Constant: '<S3>/Alpha Ref' */
    GoHomeController_B.AlphaReference = GoHomeController_P.AlphaRef_Value;

    /* Constant: '<S3>/Alpha_Dot Ref' */
    GoHomeController_B.Alpha_dotReference =
      GoHomeController_P.Alpha_DotRef_Value;

    /* Constant: '<S3>/Beta Ref' */
    GoHomeController_B.BetaReference = GoHomeController_P.BetaRef_Value;

    /* Constant: '<S3>/Beta_Dot Ref' */
    GoHomeController_B.Beta_dotReference = GoHomeController_P.Beta_DotRef_Value;

    /* SignalConversion: '<S1>/TmpSignal ConversionAtHiddenToAsyncQueue_InsertedFor_Reference_at_outport_0Inport1' */
    GoHomeController_B.Reference[0] = GoHomeController_B.YReference;
    GoHomeController_B.Reference[1] = GoHomeController_B.Y_dotReference;
    GoHomeController_B.Reference[2] = GoHomeController_B.XReference;
    GoHomeController_B.Reference[3] = GoHomeController_B.X_dotReference;
    GoHomeController_B.Reference[4] = GoHomeController_B.AlphaReference;
    GoHomeController_B.Reference[5] = GoHomeController_B.Alpha_dotReference;
    GoHomeController_B.Reference[6] = GoHomeController_B.BetaReference;
    GoHomeController_B.Reference[7] = GoHomeController_B.Beta_dotReference;

    /* ToAsyncQueueBlock: '<S1>/HiddenToAsyncQueue_InsertedFor_Reference_at_outport_0' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.Reference[0];
        int32_T size = 8*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(616536649U, time, pData, size);
      }
    }

    /* Level2 S-Function Block: '<S7>/Encoder' (Crane3D_Encoder) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S7>/Encoder 500PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder500PPR[i] = GoHomeController_P.Encoder500PPR_Gain *
        GoHomeController_B.Encoder[i];
    }

    /* End of Gain: '<S7>/Encoder 500PPR' */

    /* Gain: '<S7>/Y Scale' */
    GoHomeController_B.YScale = GoHomeController_P.YScale_Gain *
      rtb_Encoder500PPR[1];

    /* MATLAB Function: '<S2>/Y Overflow Protection1' */
    GoHomeController_XOverflowProtection(GoHomeController_B.YScale,
      &GoHomeController_B.sf_YOverflowProtection1);

    /* Gain: '<S7>/X Scale' */
    GoHomeController_B.XScale = GoHomeController_P.XScale_Gain *
      rtb_Encoder500PPR[0];

    /* MATLAB Function: '<S2>/X Overflow Protection' */
    GoHomeController_XOverflowProtection(GoHomeController_B.XScale,
      &GoHomeController_B.sf_XOverflowProtection);

    /* Gain: '<S7>/Z Scale' */
    GoHomeController_B.ZScale = GoHomeController_P.ZScale_Gain *
      rtb_Encoder500PPR[2];

    /* Gain: '<S7>/X Angle Scale' */
    GoHomeController_B.XAngleScale = GoHomeController_P.XAngleScale_Gain *
      rtb_Encoder500PPR[3];

    /* Gain: '<S7>/Y Angle Scale' */
    GoHomeController_B.YAngleScale = GoHomeController_P.YAngleScale_Gain *
      rtb_Encoder500PPR[4];

    /* Sum: '<S8>/Add1' incorporates:
     *  UnitDelay: '<S8>/Unit Delay'
     */
    rtb_Encoder500PPR[0] = GoHomeController_B.sf_XOverflowProtection.y -
      GoHomeController_DW.UnitDelay_DSTATE[0];
    rtb_Encoder500PPR[1] = GoHomeController_B.sf_YOverflowProtection1.y -
      GoHomeController_DW.UnitDelay_DSTATE[1];
    rtb_Encoder500PPR[2] = GoHomeController_B.ZScale -
      GoHomeController_DW.UnitDelay_DSTATE[2];
    rtb_Encoder500PPR[3] = GoHomeController_B.XAngleScale -
      GoHomeController_DW.UnitDelay_DSTATE[3];
    rtb_Encoder500PPR[4] = GoHomeController_B.YAngleScale -
      GoHomeController_DW.UnitDelay_DSTATE[4];
    for (i = 0; i < 5; i++) {
      /* Gain: '<S8>/GainZ1' */
      Derivatives[i] = GoHomeController_P.GainZ1_Gain * rtb_Encoder500PPR[i];

      /* DiscreteFilter: '<S8>/Derivative Filter' */
      memOffset = i << 4;
      rtb_PulseGenerator = Derivatives[i];
      denIdx = 1;
      for (j = 0; j < 16; j++) {
        rtb_PulseGenerator -=
          GoHomeController_DW.DerivativeFilter_states[memOffset + j] *
          GoHomeController_P.DerivativeFilter_DenCoef[denIdx];
        denIdx++;
      }

      rtb_PulseGenerator /= GoHomeController_P.DerivativeFilter_DenCoef[0];
      GoHomeController_DW.DerivativeFilter_tmp[i] = rtb_PulseGenerator;
      rtb_PulseGenerator = GoHomeController_P.DerivativeFilter_NumCoef[0] *
        GoHomeController_DW.DerivativeFilter_tmp[i];
      denIdx = 1;
      for (j = 0; j < 16; j++) {
        rtb_PulseGenerator +=
          GoHomeController_DW.DerivativeFilter_states[memOffset + j] *
          GoHomeController_P.DerivativeFilter_NumCoef[denIdx];
        denIdx++;
      }

      rtb_Encoder500PPR[i] = rtb_PulseGenerator;

      /* End of DiscreteFilter: '<S8>/Derivative Filter' */
    }

    /* Sum: '<S1>/Sum' incorporates:
     *  Bias: '<S5>/Bias'
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     */
    GoHomeController_B.Error[0] = GoHomeController_B.Reference[0] -
      GoHomeController_B.sf_YOverflowProtection1.y;
    GoHomeController_B.Error[1] = GoHomeController_B.Reference[1] -
      rtb_Encoder500PPR[1];
    GoHomeController_B.Error[2] = GoHomeController_B.Reference[2] -
      GoHomeController_B.sf_XOverflowProtection.y;
    GoHomeController_B.Error[3] = GoHomeController_B.Reference[3] -
      rtb_Encoder500PPR[0];
    GoHomeController_B.Error[4] = GoHomeController_B.Reference[4] -
      (GoHomeController_P.Gain1_Gain * GoHomeController_B.YAngleScale +
       GoHomeController_P.Bias_Bias);
    GoHomeController_B.Error[5] = GoHomeController_B.Reference[5] -
      GoHomeController_P.Gain_Gain * rtb_Encoder500PPR[4];
    GoHomeController_B.Error[6] = GoHomeController_B.Reference[6] -
      GoHomeController_B.XAngleScale;
    GoHomeController_B.Error[7] = GoHomeController_B.Reference[7] -
      rtb_Encoder500PPR[3];

    /* ToAsyncQueueBlock: '<S1>/HiddenToAsyncQueue_InsertedFor_Sum_at_outport_0' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.Error[0];
        int32_T size = 8*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3089872103U, time, pData, size);
      }
    }

    /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
     *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
     *  Gain: '<S1>/Gain1'
     */
    memcpy(&tmp[0], &GoHomeController_B.Error[0], sizeof(real_T) << 3U);
    tmp[8] = GoHomeController_P.Gain1_Gain_j *
      GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[0];
    tmp[9] = GoHomeController_P.Gain1_Gain_j *
      GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[1];
    for (i = 0; i < 2; i++) {
      /* Gain: '<S1>/Gain' incorporates:
       *  Saturate: '<S1>/Saturation'
       *  SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'
       */
      tmp_0[i] = 0.0;
      for (memOffset = 0; memOffset < 10; memOffset++) {
        tmp_0[i] += GoHomeController_P.Gain_Gain_g[(memOffset << 1) + i] *
          tmp[memOffset];
      }

      /* Saturate: '<S1>/Saturation' incorporates:
       *  Gain: '<S1>/Gain'
       */
      if (tmp_0[i] > GoHomeController_P.Saturation_UpperSat) {
        rtb_Inputs[i] = GoHomeController_P.Saturation_UpperSat;
      } else if (tmp_0[i] < GoHomeController_P.Saturation_LowerSat) {
        rtb_Inputs[i] = GoHomeController_P.Saturation_LowerSat;
      } else {
        rtb_Inputs[i] = tmp_0[i];
      }
    }

    /* ToAsyncQueueBlock: '<S2>/HiddenToAsyncQueue_InsertedFor_Crane 3D_at_outport_0' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.XScale;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(263637489U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock: '<S2>/HiddenToAsyncQueue_InsertedFor_Crane 3D_at_outport_1' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.YScale;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(265930569U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock: '<S2>/HiddenToAsyncQueue_InsertedFor_Crane 3D_at_outport_2' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.ZScale;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2426454092U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock: '<S2>/HiddenToAsyncQueue_InsertedFor_Crane 3D_at_outport_3' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.XAngleScale;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(781847990U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock: '<S2>/HiddenToAsyncQueue_InsertedFor_Crane 3D_at_outport_4' */
    if (rtmIsMajorTimeStep(GoHomeController_M)) {
      {
        double time = GoHomeController_M->Timing.t[1];
        void *pData = (void *)&GoHomeController_B.YAngleScale;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4287571790U, time, pData, size);
      }
    }

    /* Level2 S-Function Block: '<S7>/LimitSwitch' (Crane3D_Switch) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S7>/LimitSwitchGain' */
    rtb_LimitSwitchGain_idx_0 = GoHomeController_P.LimitSwitchGain_Gain *
      GoHomeController_B.LimitSwitch[0];
    rtb_LimitSwitchGain_idx_1 = GoHomeController_P.LimitSwitchGain_Gain *
      GoHomeController_B.LimitSwitch[1];

    /* Level2 S-Function Block: '<S7>/PWM' (Crane3D_PWM) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant'
     */
    if (rtb_LimitSwitchGain_idx_0 != 0.0) {
      rtb_PulseGenerator = rtb_Inputs[1];
    } else {
      rtb_PulseGenerator = GoHomeController_P.Constant_Value_b;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Saturate: '<S7>/Saturation' */
    if (rtb_PulseGenerator > GoHomeController_P.Saturation_UpperSat_h) {
      GoHomeController_B.Saturation[0] =
        GoHomeController_P.Saturation_UpperSat_h;
    } else if (rtb_PulseGenerator < GoHomeController_P.Saturation_LowerSat_d) {
      GoHomeController_B.Saturation[0] =
        GoHomeController_P.Saturation_LowerSat_d;
    } else {
      GoHomeController_B.Saturation[0] = rtb_PulseGenerator;
    }

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    if (rtb_LimitSwitchGain_idx_1 != 0.0) {
      rtb_PulseGenerator = rtb_Inputs[0];
    } else {
      rtb_PulseGenerator = GoHomeController_P.Constant1_Value_j;
    }

    /* End of Switch: '<S6>/Switch1' */

    /* Saturate: '<S7>/Saturation' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if (rtb_PulseGenerator > GoHomeController_P.Saturation_UpperSat_h) {
      GoHomeController_B.Saturation[1] =
        GoHomeController_P.Saturation_UpperSat_h;
    } else if (rtb_PulseGenerator < GoHomeController_P.Saturation_LowerSat_d) {
      GoHomeController_B.Saturation[1] =
        GoHomeController_P.Saturation_LowerSat_d;
    } else {
      GoHomeController_B.Saturation[1] = rtb_PulseGenerator;
    }

    if (GoHomeController_P.Constant_Value_a >
        GoHomeController_P.Saturation_UpperSat_h) {
      GoHomeController_B.Saturation[2] =
        GoHomeController_P.Saturation_UpperSat_h;
    } else if (GoHomeController_P.Constant_Value_a <
               GoHomeController_P.Saturation_LowerSat_d) {
      GoHomeController_B.Saturation[2] =
        GoHomeController_P.Saturation_LowerSat_d;
    } else {
      GoHomeController_B.Saturation[2] = GoHomeController_P.Constant_Value_a;
    }

    /* Level2 S-Function Block: '<S7>/ResetEncoder' (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S7>/LimitFlag' (Crane3D_LimitFlag) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S7>/LimitFlagSource' */
    GoHomeController_B.LimitFlagSource[0] =
      GoHomeController_P.LimitFlagSource_Value[0];

    /* Constant: '<S7>/LimitSource' */
    GoHomeController_B.LimitSource[0] = GoHomeController_P.LimitSource_Value[0];

    /* Constant: '<S7>/LimitFlagSource' */
    GoHomeController_B.LimitFlagSource[1] =
      GoHomeController_P.LimitFlagSource_Value[1];

    /* Constant: '<S7>/LimitSource' */
    GoHomeController_B.LimitSource[1] = GoHomeController_P.LimitSource_Value[1];

    /* Constant: '<S7>/LimitFlagSource' */
    GoHomeController_B.LimitFlagSource[2] =
      GoHomeController_P.LimitFlagSource_Value[2];

    /* Constant: '<S7>/LimitSource' */
    GoHomeController_B.LimitSource[2] = GoHomeController_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S7>/SetLimit' (Crane3D_SetLimit) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S7>/PWMPrescaler' (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S7>/PWMPrescalerSource' */
    GoHomeController_B.PWMPrescalerSource =
      GoHomeController_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S7>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S7>/ResetSwitchFlagSource' */
    GoHomeController_B.ResetSwitchFlagSource[0] =
      GoHomeController_P.ResetSwitchFlagSource_Value[0];
    GoHomeController_B.ResetSwitchFlagSource[1] =
      GoHomeController_P.ResetSwitchFlagSource_Value[1];
    GoHomeController_B.ResetSwitchFlagSource[2] =
      GoHomeController_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S7>/ThermFlag ' (Crane3D_ThermFlag) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S7>/ThermFlagSource' */
    GoHomeController_B.ThermFlagSource[0] =
      GoHomeController_P.ThermFlagSource_Value[0];
    GoHomeController_B.ThermFlagSource[1] =
      GoHomeController_P.ThermFlagSource_Value[1];
    GoHomeController_B.ThermFlagSource[2] =
      GoHomeController_P.ThermFlagSource_Value[2];

    /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
    rtb_PulseGenerator = (GoHomeController_DW.clockTickCounter <
                          GoHomeController_P.PulseGenerator_Duty) &&
      (GoHomeController_DW.clockTickCounter >= 0) ?
      GoHomeController_P.PulseGenerator_Amp : 0.0;
    if (GoHomeController_DW.clockTickCounter >=
        GoHomeController_P.PulseGenerator_Period - 1.0) {
      GoHomeController_DW.clockTickCounter = 0;
    } else {
      GoHomeController_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    if (GoHomeController_DW.UnitDelay_DSTATE_d >
        GoHomeController_P.Switch_Threshold) {
      tmp_1 = GoHomeController_P.Constant_Value;
    } else {
      tmp_1 = GoHomeController_P.Constant1_Value;
    }

    /* End of Switch: '<S4>/Switch' */

    /* Stop: '<S4>/Stop Simulation' incorporates:
     *  Logic: '<S4>/And2'
     *  Logic: '<S4>/Not 3'
     */
    if ((tmp_1 != 0.0) && (!(rtb_PulseGenerator != 0.0))) {
      rtmSetStopRequested(GoHomeController_M, 1);
    }

    /* End of Stop: '<S4>/Stop Simulation' */

    /* Logic: '<S4>/And1' incorporates:
     *  Logic: '<S4>/And'
     *  Logic: '<S4>/Not 1'
     *  Logic: '<S4>/Not 2'
     */
    rtb_And2 = ((!(rtb_LimitSwitchGain_idx_0 != 0.0)) &&
                (!(rtb_LimitSwitchGain_idx_1 != 0.0)) && (rtb_PulseGenerator !=
      0.0));

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    GoHomeController_B.DataTypeConversion = rtb_And2;

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    GoHomeController_B.Compare = ((int32_T)rtb_And2 > (int32_T)
      GoHomeController_P.Constant_Value_m);

    /* Sum: '<S4>/Sum' incorporates:
     *  RelationalOperator: '<S12>/FixPt Relational Operator'
     *  UnitDelay: '<S12>/Delay Input1'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    GoHomeController_B.Sum = (real_T)((int32_T)GoHomeController_B.Compare >
      (int32_T)GoHomeController_DW.DelayInput1_DSTATE) +
      GoHomeController_DW.UnitDelay_DSTATE_d;
  }
}

/* Model update function */
void GoHomeController_update(void)
{
  int32_T j;
  int32_T k;
  int32_T memOffset;
  if (rtmIsMajorTimeStep(GoHomeController_M)) {
    /* Update for UnitDelay: '<S8>/Unit Delay' */
    GoHomeController_DW.UnitDelay_DSTATE[0] =
      GoHomeController_B.sf_XOverflowProtection.y;
    GoHomeController_DW.UnitDelay_DSTATE[1] =
      GoHomeController_B.sf_YOverflowProtection1.y;
    GoHomeController_DW.UnitDelay_DSTATE[2] = GoHomeController_B.ZScale;
    GoHomeController_DW.UnitDelay_DSTATE[3] = GoHomeController_B.XAngleScale;
    GoHomeController_DW.UnitDelay_DSTATE[4] = GoHomeController_B.YAngleScale;

    /* Update for DiscreteFilter: '<S8>/Derivative Filter' */
    for (k = 0; k < 5; k++) {
      memOffset = k << 4;
      for (j = 0; j < 15; j++) {
        GoHomeController_DW.DerivativeFilter_states[(memOffset - j) + 15] =
          GoHomeController_DW.DerivativeFilter_states[(memOffset - j) + 14];
      }

      GoHomeController_DW.DerivativeFilter_states[memOffset] =
        GoHomeController_DW.DerivativeFilter_tmp[k];
    }

    /* End of Update for DiscreteFilter: '<S8>/Derivative Filter' */

    /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[0] +=
      GoHomeController_P.DiscreteTimeIntegrator_gainval *
      GoHomeController_B.Error[0];
    GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[1] +=
      GoHomeController_P.DiscreteTimeIntegrator_gainval *
      GoHomeController_B.Error[2];

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    GoHomeController_DW.UnitDelay_DSTATE_d = GoHomeController_B.Sum;

    /* Update for UnitDelay: '<S12>/Delay Input1' */
    GoHomeController_DW.DelayInput1_DSTATE = GoHomeController_B.Compare;
  }

  if (rtmIsMajorTimeStep(GoHomeController_M)) {
    rt_ertODEUpdateContinuousStates(&GoHomeController_M->solverInfo);
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
  if (!(++GoHomeController_M->Timing.clockTick0)) {
    ++GoHomeController_M->Timing.clockTickH0;
  }

  GoHomeController_M->Timing.t[0] = rtsiGetSolverStopTime
    (&GoHomeController_M->solverInfo);

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
    if (!(++GoHomeController_M->Timing.clockTick1)) {
      ++GoHomeController_M->Timing.clockTickH1;
    }

    GoHomeController_M->Timing.t[1] = GoHomeController_M->Timing.clockTick1 *
      GoHomeController_M->Timing.stepSize1 +
      GoHomeController_M->Timing.clockTickH1 *
      GoHomeController_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void GoHomeController_derivatives(void)
{
  XDot_GoHomeController_T *_rtXdot;
  _rtXdot = ((XDot_GoHomeController_T *) GoHomeController_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += GoHomeController_P.TransferFcn3_A[0] *
    GoHomeController_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += GoHomeController_P.TransferFcn3_A[1] *
    GoHomeController_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += GoHomeController_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += GoHomeController_B.XScale;

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += GoHomeController_P.TransferFcn1_A[0] *
    GoHomeController_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += GoHomeController_P.TransferFcn1_A[1] *
    GoHomeController_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += GoHomeController_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] +=
    GoHomeController_B.sf_YOverflowProtection1.y;
}

/* Model initialize function */
void GoHomeController_initialize(void)
{
  /* Start for Constant: '<S7>/LimitFlagSource' */
  GoHomeController_B.LimitFlagSource[0] =
    GoHomeController_P.LimitFlagSource_Value[0];

  /* Start for Constant: '<S7>/LimitSource' */
  GoHomeController_B.LimitSource[0] = GoHomeController_P.LimitSource_Value[0];

  /* Start for Constant: '<S7>/LimitFlagSource' */
  GoHomeController_B.LimitFlagSource[1] =
    GoHomeController_P.LimitFlagSource_Value[1];

  /* Start for Constant: '<S7>/LimitSource' */
  GoHomeController_B.LimitSource[1] = GoHomeController_P.LimitSource_Value[1];

  /* Start for Constant: '<S7>/LimitFlagSource' */
  GoHomeController_B.LimitFlagSource[2] =
    GoHomeController_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S7>/LimitSource' */
  GoHomeController_B.LimitSource[2] = GoHomeController_P.LimitSource_Value[2];

  /* Start for Constant: '<S7>/PWMPrescalerSource' */
  GoHomeController_B.PWMPrescalerSource =
    GoHomeController_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S7>/ResetSwitchFlagSource' */
  GoHomeController_B.ResetSwitchFlagSource[0] =
    GoHomeController_P.ResetSwitchFlagSource_Value[0];
  GoHomeController_B.ResetSwitchFlagSource[1] =
    GoHomeController_P.ResetSwitchFlagSource_Value[1];
  GoHomeController_B.ResetSwitchFlagSource[2] =
    GoHomeController_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S7>/ThermFlagSource' */
  GoHomeController_B.ThermFlagSource[0] =
    GoHomeController_P.ThermFlagSource_Value[0];
  GoHomeController_B.ThermFlagSource[1] =
    GoHomeController_P.ThermFlagSource_Value[1];
  GoHomeController_B.ThermFlagSource[2] =
    GoHomeController_P.ThermFlagSource_Value[2];

  /* Start for DiscretePulseGenerator: '<S4>/Pulse Generator' */
  GoHomeController_DW.clockTickCounter = 0;

  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn3' */
    GoHomeController_X.TransferFcn3_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn1' */
    GoHomeController_X.TransferFcn1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn3' */
    GoHomeController_X.TransferFcn3_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn1' */
    GoHomeController_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    for (i = 0; i < 5; i++) {
      GoHomeController_DW.UnitDelay_DSTATE[i] =
        GoHomeController_P.UnitDelay_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S8>/Unit Delay' */

    /* InitializeConditions for DiscreteFilter: '<S8>/Derivative Filter' */
    for (i = 0; i < 80; i++) {
      GoHomeController_DW.DerivativeFilter_states[i] =
        GoHomeController_P.DerivativeFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFilter: '<S8>/Derivative Filter' */

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[0] =
      GoHomeController_P.DiscreteTimeIntegrator_IC;
    GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[1] =
      GoHomeController_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
    GoHomeController_DW.UnitDelay_DSTATE_d =
      GoHomeController_P.UnitDelay_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S12>/Delay Input1' */
    GoHomeController_DW.DelayInput1_DSTATE =
      GoHomeController_P.DetectRisePositive_vinit;
  }
}

/* Model terminate function */
void GoHomeController_terminate(void)
{
  /* Level2 S-Function Block: '<S7>/Encoder' (Crane3D_Encoder) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/LimitSwitch' (Crane3D_Switch) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/PWM' (Crane3D_PWM) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/ResetEncoder' (Crane3D_ResetEncoder) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/LimitFlag' (Crane3D_LimitFlag) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/SetLimit' (Crane3D_SetLimit) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/PWMPrescaler' (Crane3D_PWMPrescaler) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/ResetSwitchFlag ' (Crane3D_ResetSwitchFlag) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/ThermFlag ' (Crane3D_ThermFlag) */
  {
    SimStruct *rts = GoHomeController_M->childSfunctions[8];
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
  GoHomeController_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  GoHomeController_update();
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
  GoHomeController_initialize();
}

void MdlTerminate(void)
{
  GoHomeController_terminate();
}

/* Registration function */
RT_MODEL_GoHomeController_T *GoHomeController(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)GoHomeController_M, 0,
                sizeof(RT_MODEL_GoHomeController_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&GoHomeController_M->solverInfo,
                          &GoHomeController_M->Timing.simTimeStep);
    rtsiSetTPtr(&GoHomeController_M->solverInfo, &rtmGetTPtr(GoHomeController_M));
    rtsiSetStepSizePtr(&GoHomeController_M->solverInfo,
                       &GoHomeController_M->Timing.stepSize0);
    rtsiSetdXPtr(&GoHomeController_M->solverInfo,
                 &GoHomeController_M->ModelData.derivs);
    rtsiSetContStatesPtr(&GoHomeController_M->solverInfo, (real_T **)
                         &GoHomeController_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&GoHomeController_M->solverInfo,
      &GoHomeController_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&GoHomeController_M->solverInfo,
      &GoHomeController_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&GoHomeController_M->solverInfo,
      &GoHomeController_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&GoHomeController_M->solverInfo,
      &GoHomeController_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&GoHomeController_M->solverInfo, (&rtmGetErrorStatus
      (GoHomeController_M)));
    rtsiSetRTModelPtr(&GoHomeController_M->solverInfo, GoHomeController_M);
  }

  rtsiSetSimTimeStep(&GoHomeController_M->solverInfo, MAJOR_TIME_STEP);
  GoHomeController_M->ModelData.intgData.y = GoHomeController_M->ModelData.odeY;
  GoHomeController_M->ModelData.intgData.f[0] =
    GoHomeController_M->ModelData.odeF[0];
  GoHomeController_M->ModelData.intgData.f[1] =
    GoHomeController_M->ModelData.odeF[1];
  GoHomeController_M->ModelData.intgData.f[2] =
    GoHomeController_M->ModelData.odeF[2];
  GoHomeController_M->ModelData.intgData.f[3] =
    GoHomeController_M->ModelData.odeF[3];
  GoHomeController_M->ModelData.intgData.f[4] =
    GoHomeController_M->ModelData.odeF[4];
  GoHomeController_M->ModelData.intgData.f[5] =
    GoHomeController_M->ModelData.odeF[5];
  GoHomeController_M->ModelData.contStates = ((real_T *) &GoHomeController_X);
  rtsiSetSolverData(&GoHomeController_M->solverInfo, (void *)
                    &GoHomeController_M->ModelData.intgData);
  rtsiSetSolverName(&GoHomeController_M->solverInfo,"ode5");
  GoHomeController_M->solverInfoPtr = (&GoHomeController_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = GoHomeController_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    GoHomeController_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GoHomeController_M->Timing.sampleTimes =
      (&GoHomeController_M->Timing.sampleTimesArray[0]);
    GoHomeController_M->Timing.offsetTimes =
      (&GoHomeController_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GoHomeController_M->Timing.sampleTimes[0] = (0.0);
    GoHomeController_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    GoHomeController_M->Timing.offsetTimes[0] = (0.0);
    GoHomeController_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(GoHomeController_M, &GoHomeController_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GoHomeController_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    GoHomeController_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GoHomeController_M, 100.0);
  GoHomeController_M->Timing.stepSize0 = 0.01;
  GoHomeController_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  GoHomeController_M->Sizes.checksums[0] = (899873547U);
  GoHomeController_M->Sizes.checksums[1] = (365729218U);
  GoHomeController_M->Sizes.checksums[2] = (2302677284U);
  GoHomeController_M->Sizes.checksums[3] = (703345186U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    GoHomeController_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GoHomeController_M->extModeInfo,
      &GoHomeController_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GoHomeController_M->extModeInfo,
                        GoHomeController_M->Sizes.checksums);
    rteiSetTPtr(GoHomeController_M->extModeInfo, rtmGetTPtr(GoHomeController_M));
  }

  GoHomeController_M->solverInfoPtr = (&GoHomeController_M->solverInfo);
  GoHomeController_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&GoHomeController_M->solverInfo, 0.01);
  rtsiSetSolverMode(&GoHomeController_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  GoHomeController_M->ModelData.blockIO = ((void *) &GoHomeController_B);
  (void) memset(((void *) &GoHomeController_B), 0,
                sizeof(B_GoHomeController_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      GoHomeController_B.Reference[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      GoHomeController_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      GoHomeController_B.Error[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      GoHomeController_B.ResetEncoder[i] = 0.0;
    }

    GoHomeController_B.dx2 = 0.0;
    GoHomeController_B.TransferFcn1 = 0.0;
    GoHomeController_B.vel[0] = 0.0;
    GoHomeController_B.vel[1] = 0.0;
    GoHomeController_B.Constant1 = 0.0;
    GoHomeController_B.Constant2 = 0.0;
    GoHomeController_B.Constant3 = 0.0;
    GoHomeController_B.YReference = 0.0;
    GoHomeController_B.Y_dotReference = 0.0;
    GoHomeController_B.XReference = 0.0;
    GoHomeController_B.X_dotReference = 0.0;
    GoHomeController_B.AlphaReference = 0.0;
    GoHomeController_B.Alpha_dotReference = 0.0;
    GoHomeController_B.BetaReference = 0.0;
    GoHomeController_B.Beta_dotReference = 0.0;
    GoHomeController_B.YScale = 0.0;
    GoHomeController_B.XScale = 0.0;
    GoHomeController_B.ZScale = 0.0;
    GoHomeController_B.XAngleScale = 0.0;
    GoHomeController_B.YAngleScale = 0.0;
    GoHomeController_B.LimitSwitch[0] = 0.0;
    GoHomeController_B.LimitSwitch[1] = 0.0;
    GoHomeController_B.LimitSwitch[2] = 0.0;
    GoHomeController_B.PWM[0] = 0.0;
    GoHomeController_B.PWM[1] = 0.0;
    GoHomeController_B.PWM[2] = 0.0;
    GoHomeController_B.Saturation[0] = 0.0;
    GoHomeController_B.Saturation[1] = 0.0;
    GoHomeController_B.Saturation[2] = 0.0;
    GoHomeController_B.LimitFlag[0] = 0.0;
    GoHomeController_B.LimitFlag[1] = 0.0;
    GoHomeController_B.LimitFlag[2] = 0.0;
    GoHomeController_B.LimitFlagSource[0] = 0.0;
    GoHomeController_B.LimitFlagSource[1] = 0.0;
    GoHomeController_B.LimitFlagSource[2] = 0.0;
    GoHomeController_B.LimitSource[0] = 0.0;
    GoHomeController_B.LimitSource[1] = 0.0;
    GoHomeController_B.LimitSource[2] = 0.0;
    GoHomeController_B.SetLimit[0] = 0.0;
    GoHomeController_B.SetLimit[1] = 0.0;
    GoHomeController_B.SetLimit[2] = 0.0;
    GoHomeController_B.PWMPrescaler = 0.0;
    GoHomeController_B.PWMPrescalerSource = 0.0;
    GoHomeController_B.ResetSwitchFlag[0] = 0.0;
    GoHomeController_B.ResetSwitchFlag[1] = 0.0;
    GoHomeController_B.ResetSwitchFlag[2] = 0.0;
    GoHomeController_B.ResetSwitchFlagSource[0] = 0.0;
    GoHomeController_B.ResetSwitchFlagSource[1] = 0.0;
    GoHomeController_B.ResetSwitchFlagSource[2] = 0.0;
    GoHomeController_B.ThermFlag[0] = 0.0;
    GoHomeController_B.ThermFlag[1] = 0.0;
    GoHomeController_B.ThermFlag[2] = 0.0;
    GoHomeController_B.ThermFlagSource[0] = 0.0;
    GoHomeController_B.ThermFlagSource[1] = 0.0;
    GoHomeController_B.ThermFlagSource[2] = 0.0;
    GoHomeController_B.DataTypeConversion = 0.0;
    GoHomeController_B.Sum = 0.0;
    GoHomeController_B.sf_YOverflowProtection1.y = 0.0;
    GoHomeController_B.sf_XOverflowProtection.y = 0.0;
  }

  /* parameters */
  GoHomeController_M->ModelData.defaultParam = ((real_T *)&GoHomeController_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &GoHomeController_X;
    GoHomeController_M->ModelData.contStates = (x);
    (void) memset((void *)&GoHomeController_X, 0,
                  sizeof(X_GoHomeController_T));
  }

  /* states (dwork) */
  GoHomeController_M->ModelData.dwork = ((void *) &GoHomeController_DW);
  (void) memset((void *)&GoHomeController_DW, 0,
                sizeof(DW_GoHomeController_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      GoHomeController_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 80; i++) {
      GoHomeController_DW.DerivativeFilter_states[i] = 0.0;
    }
  }

  GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[0] = 0.0;
  GoHomeController_DW.DiscreteTimeIntegrator_DSTATE[1] = 0.0;
  GoHomeController_DW.UnitDelay_DSTATE_d = 0.0;

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      GoHomeController_DW.DerivativeFilter_tmp[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GoHomeController_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &GoHomeController_M->NonInlinedSFcns.sfcnInfo;
    GoHomeController_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(GoHomeController_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &GoHomeController_M->Sizes.numSampTimes);
    GoHomeController_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (GoHomeController_M)[0]);
    GoHomeController_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (GoHomeController_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,GoHomeController_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(GoHomeController_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(GoHomeController_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (GoHomeController_M));
    rtssSetStepSizePtr(sfcnInfo, &GoHomeController_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(GoHomeController_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &GoHomeController_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &GoHomeController_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &GoHomeController_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &GoHomeController_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &GoHomeController_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &GoHomeController_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &GoHomeController_M->solverInfoPtr);
  }

  GoHomeController_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&GoHomeController_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    GoHomeController_M->childSfunctions =
      (&GoHomeController_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        GoHomeController_M->childSfunctions[i] =
          (&GoHomeController_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: GoHomeController/<S7>/Encoder (Crane3D_Encoder) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) GoHomeController_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/Encoder");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/LimitSwitch (Crane3D_Switch) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            GoHomeController_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/LimitSwitch");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/PWM (Crane3D_PWM) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = GoHomeController_B.Saturation;
          sfcnUPtrs[1] = &GoHomeController_B.Saturation[1];
          sfcnUPtrs[2] = &GoHomeController_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) GoHomeController_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/PWM");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/ResetEncoder (Crane3D_ResetEncoder) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &GoHomeController_B.DataTypeConversion;
          sfcnUPtrs[1] = &GoHomeController_B.DataTypeConversion;
          sfcnUPtrs[2] = &GoHomeController_B.Constant3;
          sfcnUPtrs[3] = &GoHomeController_B.Constant2;
          sfcnUPtrs[4] = &GoHomeController_B.Constant1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            GoHomeController_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/ResetEncoder");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/LimitFlag (Crane3D_LimitFlag) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = GoHomeController_B.LimitFlagSource;
          sfcnUPtrs[1] = &GoHomeController_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &GoHomeController_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) GoHomeController_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/LimitFlag");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/SetLimit (Crane3D_SetLimit) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = GoHomeController_B.LimitSource;
          sfcnUPtrs[1] = &GoHomeController_B.LimitSource[1];
          sfcnUPtrs[2] = &GoHomeController_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) GoHomeController_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/SetLimit");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/PWMPrescaler (Crane3D_PWMPrescaler) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &GoHomeController_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &GoHomeController_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/PWMPrescaler");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/ResetSwitchFlag  (Crane3D_ResetSwitchFlag) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = GoHomeController_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &GoHomeController_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &GoHomeController_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            GoHomeController_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts,
                "GoHomeController/Crane (hardware)/Crane 3D/ResetSwitchFlag ");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       GoHomeController_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       GoHomeController_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: GoHomeController/<S7>/ThermFlag  (Crane3D_ThermFlag) */
    {
      SimStruct *rts = GoHomeController_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = GoHomeController_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = GoHomeController_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = GoHomeController_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &GoHomeController_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, GoHomeController_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &GoHomeController_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &GoHomeController_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &GoHomeController_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &GoHomeController_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &GoHomeController_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = GoHomeController_B.ThermFlagSource;
          sfcnUPtrs[1] = &GoHomeController_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &GoHomeController_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &GoHomeController_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) GoHomeController_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "GoHomeController/Crane (hardware)/Crane 3D/ThermFlag ");
      ssSetRTModel(rts,GoHomeController_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &GoHomeController_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)GoHomeController_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)GoHomeController_P.ThermFlag_P2_Size);
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
  GoHomeController_M->Sizes.numContStates = (4);/* Number of continuous states */
  GoHomeController_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  GoHomeController_M->Sizes.numY = (0);/* Number of model outputs */
  GoHomeController_M->Sizes.numU = (0);/* Number of model inputs */
  GoHomeController_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GoHomeController_M->Sizes.numSampTimes = (2);/* Number of sample times */
  GoHomeController_M->Sizes.numBlocks = (88);/* Number of blocks */
  GoHomeController_M->Sizes.numBlockIO = (42);/* Number of block outputs */
  GoHomeController_M->Sizes.numBlockPrms = (177);/* Sum of parameter "widths" */
  return GoHomeController_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
