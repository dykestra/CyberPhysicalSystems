/*
 * Crane3D_DevDriv_private.h
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

#ifndef RTW_HEADER_Crane3D_DevDriv_private_h_
#define RTW_HEADER_Crane3D_DevDriv_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Crane3D_DevDriv.h"

extern void Crane3D_Encoder(SimStruct *rts);
extern void Crane3D_PWM(SimStruct *rts);
extern void Crane3D_LimitFlag(SimStruct *rts);
extern void Crane3D_SetLimit(SimStruct *rts);
extern void Crane3D_Switch(SimStruct *rts);
extern void Crane3D_PWMPrescaler(SimStruct *rts);
extern void Crane3D_ResetEncoder(SimStruct *rts);
extern void Crane3D_ResetSwitchFlag(SimStruct *rts);
extern void Crane3D_ThermFlag(SimStruct *rts);
extern void Crane3D_DevDriv_GainDesch(real_T rtu_C1, real_T rtu_C2, real_T
  rtu_C3, real_T rtu_C4, real_T rtu_Class, B_GainDesch_Crane3D_DevDriv_T *localB);
extern void Crane3D_DevDriv_GainSch(real_T rtu_Input, real_T rtu_Class,
  B_GainSch_Crane3D_DevDriv_T *localB);

/* private model entry point functions */
extern void Crane3D_DevDriv_derivatives(void);

#endif                                 /* RTW_HEADER_Crane3D_DevDriv_private_h_ */
