/*
 * GoHomeController_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&GoHomeController_B.dx2), 0, 0, 83 },

  { (char_T *)(&GoHomeController_B.Compare), 8, 0, 1 },

  { (char_T *)(&GoHomeController_B.sf_YOverflowProtection1.y), 0, 0, 1 },

  { (char_T *)(&GoHomeController_B.sf_XOverflowProtection.y), 0, 0, 1 }
  ,

  { (char_T *)(&GoHomeController_DW.UnitDelay_DSTATE[0]), 0, 0, 93 },

  { (char_T *)
    (&GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Cranehardware_at_outport_3_PWORK.AQHandles),
    11, 0, 8 },

  { (char_T *)(&GoHomeController_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&GoHomeController_DW.DelayInput1_DSTATE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&GoHomeController_P.DetectRisePositive_vinit), 8, 0, 1 },

  { (char_T *)(&GoHomeController_P.Constant1_Value), 0, 0, 175 },

  { (char_T *)(&GoHomeController_P.Constant_Value_m), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] GoHomeController_dt.h */
