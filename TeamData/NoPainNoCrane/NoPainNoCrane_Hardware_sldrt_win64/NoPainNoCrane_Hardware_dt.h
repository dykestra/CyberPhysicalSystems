/*
 * NoPainNoCrane_Hardware_dt.h
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
  { (char_T *)(&NoPainNoCrane_Hardware_B.Encoder[0]), 0, 0, 89 }
  ,

  { (char_T *)(&NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE[0]), 0, 0, 6 },

  { (char_T *)(&NoPainNoCrane_Hardware_DW.ToWorkspace_PWORK.LoggedData), 11, 0,
    10 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  3U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&NoPainNoCrane_Hardware_P.PIDController_D), 0, 0, 147 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] NoPainNoCrane_Hardware_dt.h */
