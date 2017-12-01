/*
 * Crane3D_DevDriv_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Crane3D_DevDriv".
 *
 * Model version              : 1.232
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Fri Dec 01 15:43:34 2017
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
  { (char_T *)(&Crane3D_DevDriv_B.Clock), 0, 0, 92 },

  { (char_T *)(&Crane3D_DevDriv_B.sf_GainSch1.C1), 0, 0, 4 },

  { (char_T *)(&Crane3D_DevDriv_B.sf_GainSch.C1), 0, 0, 4 },

  { (char_T *)(&Crane3D_DevDriv_B.sf_GainDesch1.Out), 0, 0, 1 },

  { (char_T *)(&Crane3D_DevDriv_B.sf_GainDesch.Out), 0, 0, 1 }
  ,

  { (char_T *)(&Crane3D_DevDriv_DW.WP_Index), 0, 0, 1 },

  { (char_T *)(&Crane3D_DevDriv_DW.ToWorkspace4_PWORK.LoggedData), 11, 0, 9 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Crane3D_DevDriv_P.DC1x), 0, 0, 165 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] Crane3D_DevDriv_dt.h */
