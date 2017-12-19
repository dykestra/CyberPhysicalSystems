/*
 * Crane3D_DevDriv.h
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

#ifndef RTW_HEADER_Crane3D_DevDriv_h_
#define RTW_HEADER_Crane3D_DevDriv_h_
#include <string.h>
#include <stddef.h>
#include <math.h>
#ifndef Crane3D_DevDriv_COMMON_INCLUDES_
# define Crane3D_DevDriv_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* Crane3D_DevDriv_COMMON_INCLUDES_ */

#include "Crane3D_DevDriv_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Crane3D_DevDriv_rtModel        RT_MODEL_Crane3D_DevDriv_T

/* Block signals for system '<S6>/GainDesch' */
typedef struct {
  real_T Out;                          /* '<S6>/GainDesch' */
} B_GainDesch_Crane3D_DevDriv_T;

/* Block signals for system '<S6>/GainSch' */
typedef struct {
  real_T C1;                           /* '<S6>/GainSch' */
  real_T C2;                           /* '<S6>/GainSch' */
  real_T C3;                           /* '<S6>/GainSch' */
  real_T C4;                           /* '<S6>/GainSch' */
} B_GainSch_Crane3D_DevDriv_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Encoder[5];                   /* '<S3>/Encoder' */
  real_T XScale;                       /* '<S3>/X Scale' */
  real_T YScale;                       /* '<S3>/Y Scale' */
  real_T XAngleScale;                  /* '<S3>/X Angle Scale' */
  real_T YAngleScale;                  /* '<S3>/Y Angle Scale' */
  real_T ProportionalGain;             /* '<S11>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S11>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S11>/Filter Coefficient' */
  real_T ProportionalGain_j;           /* '<S12>/Proportional Gain' */
  real_T DerivativeGain_j;             /* '<S12>/Derivative Gain' */
  real_T FilterCoefficient_c;          /* '<S12>/Filter Coefficient' */
  real_T ProportionalGain_h;           /* '<S13>/Proportional Gain' */
  real_T DerivativeGain_jh;            /* '<S13>/Derivative Gain' */
  real_T FilterCoefficient_b;          /* '<S13>/Filter Coefficient' */
  real_T ProportionalGain_f;           /* '<S14>/Proportional Gain' */
  real_T DerivativeGain_k;             /* '<S14>/Derivative Gain' */
  real_T FilterCoefficient_j;          /* '<S14>/Filter Coefficient' */
  real_T ProportionalGain_o;           /* '<S16>/Proportional Gain' */
  real_T DerivativeGain_c;             /* '<S16>/Derivative Gain' */
  real_T FilterCoefficient_e;          /* '<S16>/Filter Coefficient' */
  real_T ProportionalGain_c;           /* '<S17>/Proportional Gain' */
  real_T DerivativeGain_p;             /* '<S17>/Derivative Gain' */
  real_T FilterCoefficient_d;          /* '<S17>/Filter Coefficient' */
  real_T ProportionalGain_g;           /* '<S15>/Proportional Gain' */
  real_T DerivativeGain_m;             /* '<S15>/Derivative Gain' */
  real_T FilterCoefficient_j0;         /* '<S15>/Filter Coefficient' */
  real_T ProportionalGain_p;           /* '<S18>/Proportional Gain' */
  real_T DerivativeGain_cw;            /* '<S18>/Derivative Gain' */
  real_T FilterCoefficient_jx;         /* '<S18>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S11>/Integral Gain' */
  real_T IntegralGain_l;               /* '<S12>/Integral Gain' */
  real_T IntegralGain_o;               /* '<S13>/Integral Gain' */
  real_T IntegralGain_lr;              /* '<S14>/Integral Gain' */
  real_T IntegralGain_n;               /* '<S15>/Integral Gain' */
  real_T IntegralGain_g;               /* '<S16>/Integral Gain' */
  real_T IntegralGain_m;               /* '<S17>/Integral Gain' */
  real_T IntegralGain_e;               /* '<S18>/Integral Gain' */
  real_T PWM[3];                       /* '<S3>/PWM' */
  real_T Saturation[3];                /* '<S3>/Saturation' */
  real_T LimitFlag[3];                 /* '<S3>/LimitFlag' */
  real_T LimitFlagSource[3];           /* '<S3>/LimitFlagSource' */
  real_T LimitSource[3];               /* '<S3>/LimitSource' */
  real_T SetLimit[3];                  /* '<S3>/SetLimit' */
  real_T LimitSwitch[3];               /* '<S3>/LimitSwitch' */
  real_T PWMPrescaler;                 /* '<S3>/PWMPrescaler' */
  real_T PWMPrescalerSource;           /* '<S3>/PWMPrescalerSource' */
  real_T ResetEncoder[5];              /* '<S3>/ResetEncoder' */
  real_T ResetSource[5];               /* '<S3>/ResetSource' */
  real_T ResetSwitchFlag[3];           /* '<S3>/ResetSwitchFlag ' */
  real_T ResetSwitchFlagSource[3];     /* '<S3>/ResetSwitchFlagSource' */
  real_T ThermFlag[3];                 /* '<S3>/ThermFlag ' */
  real_T ThermFlagSource[3];           /* '<S3>/ThermFlagSource' */
  real_T x;                            /* '<Root>/Select most convenient path' */
  real_T y;                            /* '<Root>/Select most convenient path' */
  real_T Class;                        /* '<Root>/Select most convenient path' */
  real_T x_l;                          /* '<Root>/Convert Coordinates' */
  real_T y_f;                          /* '<Root>/Convert Coordinates' */
  B_GainSch_Crane3D_DevDriv_T sf_GainSch1;/* '<S6>/GainSch1' */
  B_GainSch_Crane3D_DevDriv_T sf_GainSch;/* '<S6>/GainSch' */
  B_GainDesch_Crane3D_DevDriv_T sf_GainDesch1;/* '<S6>/GainDesch1' */
  B_GainDesch_Crane3D_DevDriv_T sf_GainDesch;/* '<S6>/GainDesch' */
} B_Crane3D_DevDriv_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T WP_Index;                     /* '<Root>/Select most convenient path' */
  struct {
    void *LoggedData;
  } ToWorkspace4_PWORK;                /* '<Root>/To Workspace4' */

  struct {
    void *LoggedData;
  } XDes_PWORK;                        /* '<Root>/XDes' */

  struct {
    void *LoggedData;
  } XTraj_PWORK;                       /* '<Root>/XTraj' */

  struct {
    void *LoggedData;
  } YDes_PWORK;                        /* '<Root>/YDes' */

  struct {
    void *LoggedData;
  } YTraj_PWORK;                       /* '<Root>/YTraj' */

  struct {
    void *LoggedData;
  } anglex_PWORK;                      /* '<Root>/anglex' */

  struct {
    void *LoggedData;
  } angley_PWORK;                      /* '<Root>/angley' */

  struct {
    void *LoggedData;
  } xpos_PWORK;                        /* '<Root>/xpos' */

  struct {
    void *LoggedData;
  } ypos_PWORK;                        /* '<Root>/ypos' */
} DW_Crane3D_DevDriv_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
  real_T Filter_CSTATE;                /* '<S11>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S12>/Integrator' */
  real_T Filter_CSTATE_g;              /* '<S12>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S13>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S13>/Filter' */
  real_T Integrator_CSTATE_l;          /* '<S14>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S14>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S16>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S16>/Filter' */
  real_T Integrator_CSTATE_a;          /* '<S17>/Integrator' */
  real_T Filter_CSTATE_m;              /* '<S17>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S15>/Integrator' */
  real_T Filter_CSTATE_ie;             /* '<S15>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S18>/Integrator' */
  real_T Filter_CSTATE_pq;             /* '<S18>/Filter' */
} X_Crane3D_DevDriv_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
  real_T Filter_CSTATE;                /* '<S11>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S12>/Integrator' */
  real_T Filter_CSTATE_g;              /* '<S12>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S13>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S13>/Filter' */
  real_T Integrator_CSTATE_l;          /* '<S14>/Integrator' */
  real_T Filter_CSTATE_d;              /* '<S14>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S16>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S16>/Filter' */
  real_T Integrator_CSTATE_a;          /* '<S17>/Integrator' */
  real_T Filter_CSTATE_m;              /* '<S17>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S15>/Integrator' */
  real_T Filter_CSTATE_ie;             /* '<S15>/Filter' */
  real_T Integrator_CSTATE_c;          /* '<S18>/Integrator' */
  real_T Filter_CSTATE_pq;             /* '<S18>/Filter' */
} XDot_Crane3D_DevDriv_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S11>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S11>/Filter' */
  boolean_T Integrator_CSTATE_n;       /* '<S12>/Integrator' */
  boolean_T Filter_CSTATE_g;           /* '<S12>/Filter' */
  boolean_T Integrator_CSTATE_e;       /* '<S13>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S13>/Filter' */
  boolean_T Integrator_CSTATE_l;       /* '<S14>/Integrator' */
  boolean_T Filter_CSTATE_d;           /* '<S14>/Filter' */
  boolean_T Integrator_CSTATE_d;       /* '<S16>/Integrator' */
  boolean_T Filter_CSTATE_p;           /* '<S16>/Filter' */
  boolean_T Integrator_CSTATE_a;       /* '<S17>/Integrator' */
  boolean_T Filter_CSTATE_m;           /* '<S17>/Filter' */
  boolean_T Integrator_CSTATE_i;       /* '<S15>/Integrator' */
  boolean_T Filter_CSTATE_ie;          /* '<S15>/Filter' */
  boolean_T Integrator_CSTATE_c;       /* '<S18>/Integrator' */
  boolean_T Filter_CSTATE_pq;          /* '<S18>/Filter' */
} XDis_Crane3D_DevDriv_T;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Crane3D_DevDriv_B
#define BlockIO                        B_Crane3D_DevDriv_T
#define rtX                            Crane3D_DevDriv_X
#define ContinuousStates               X_Crane3D_DevDriv_T
#define rtXdot                         Crane3D_DevDriv_XDot
#define StateDerivatives               XDot_Crane3D_DevDriv_T
#define tXdis                          Crane3D_DevDriv_XDis
#define StateDisabled                  XDis_Crane3D_DevDriv_T
#define rtP                            Crane3D_DevDriv_P
#define Parameters                     P_Crane3D_DevDriv_T
#define rtDWork                        Crane3D_DevDriv_DW
#define D_Work                         DW_Crane3D_DevDriv_T

/* Parameters (auto storage) */
struct P_Crane3D_DevDriv_T_ {
  real_T DC1x;                         /* Variable: DC1x
                                        * Referenced by: '<S11>/Derivative Gain'
                                        */
  real_T DC1y;                         /* Variable: DC1y
                                        * Referenced by: '<S16>/Derivative Gain'
                                        */
  real_T DC2x;                         /* Variable: DC2x
                                        * Referenced by: '<S12>/Derivative Gain'
                                        */
  real_T DC2y;                         /* Variable: DC2y
                                        * Referenced by: '<S17>/Derivative Gain'
                                        */
  real_T DC3x;                         /* Variable: DC3x
                                        * Referenced by: '<S13>/Derivative Gain'
                                        */
  real_T DC3y;                         /* Variable: DC3y
                                        * Referenced by: '<S15>/Derivative Gain'
                                        */
  real_T DC4x;                         /* Variable: DC4x
                                        * Referenced by: '<S14>/Derivative Gain'
                                        */
  real_T DC4y;                         /* Variable: DC4y
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  real_T IC1x;                         /* Variable: IC1x
                                        * Referenced by: '<S11>/Integral Gain'
                                        */
  real_T IC1y;                         /* Variable: IC1y
                                        * Referenced by: '<S16>/Integral Gain'
                                        */
  real_T IC2x;                         /* Variable: IC2x
                                        * Referenced by: '<S12>/Integral Gain'
                                        */
  real_T IC2y;                         /* Variable: IC2y
                                        * Referenced by: '<S17>/Integral Gain'
                                        */
  real_T IC3x;                         /* Variable: IC3x
                                        * Referenced by: '<S13>/Integral Gain'
                                        */
  real_T IC3y;                         /* Variable: IC3y
                                        * Referenced by: '<S15>/Integral Gain'
                                        */
  real_T IC4x;                         /* Variable: IC4x
                                        * Referenced by: '<S14>/Integral Gain'
                                        */
  real_T IC4y;                         /* Variable: IC4y
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  real_T PC1x;                         /* Variable: PC1x
                                        * Referenced by: '<S11>/Proportional Gain'
                                        */
  real_T PC1y;                         /* Variable: PC1y
                                        * Referenced by: '<S16>/Proportional Gain'
                                        */
  real_T PC2x;                         /* Variable: PC2x
                                        * Referenced by: '<S12>/Proportional Gain'
                                        */
  real_T PC2y;                         /* Variable: PC2y
                                        * Referenced by: '<S17>/Proportional Gain'
                                        */
  real_T PC3x;                         /* Variable: PC3x
                                        * Referenced by: '<S13>/Proportional Gain'
                                        */
  real_T PC3y;                         /* Variable: PC3y
                                        * Referenced by: '<S15>/Proportional Gain'
                                        */
  real_T PC4x;                         /* Variable: PC4x
                                        * Referenced by: '<S14>/Proportional Gain'
                                        */
  real_T PC4y;                         /* Variable: PC4y
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  real_T waypoints[100];               /* Variable: waypoints
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T xRange[2];                    /* Variable: xRange
                                        * Referenced by: '<Root>/X_range'
                                        */
  real_T yRange[2];                    /* Variable: yRange
                                        * Referenced by: '<Root>/Y_range '
                                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S11>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S12>/Filter Coefficient'
                                        */
  real_T PIDController2_N;             /* Mask Parameter: PIDController2_N
                                        * Referenced by: '<S13>/Filter Coefficient'
                                        */
  real_T PIDController3_N;             /* Mask Parameter: PIDController3_N
                                        * Referenced by: '<S14>/Filter Coefficient'
                                        */
  real_T PIDController5_N;             /* Mask Parameter: PIDController5_N
                                        * Referenced by: '<S16>/Filter Coefficient'
                                        */
  real_T PIDController6_N;             /* Mask Parameter: PIDController6_N
                                        * Referenced by: '<S17>/Filter Coefficient'
                                        */
  real_T PIDController4_N;             /* Mask Parameter: PIDController4_N
                                        * Referenced by: '<S15>/Filter Coefficient'
                                        */
  real_T PIDController7_N;             /* Mask Parameter: PIDController7_N
                                        * Referenced by: '<S18>/Filter Coefficient'
                                        */
  real_T Encoder_P1_Size[2];           /* Computed Parameter: Encoder_P1_Size
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder_P1;                   /* Expression: BaseAddress
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder_P2_Size[2];           /* Computed Parameter: Encoder_P2_Size
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder_P2;                   /* Expression: T0
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder500PPR_Gain;           /* Expression: 1
                                        * Referenced by: '<S3>/Encoder 500PPR'
                                        */
  real_T XScale_Gain;                  /* Expression: Crane3D_ScaleCoeff( 1 )
                                        * Referenced by: '<S3>/X Scale'
                                        */
  real_T YScale_Gain;                  /* Expression: Crane3D_ScaleCoeff( 2 )
                                        * Referenced by: '<S3>/Y Scale'
                                        */
  real_T XAngleScale_Gain;             /* Expression: Crane3D_ScaleCoeff( 4 )
                                        * Referenced by: '<S3>/X Angle Scale'
                                        */
  real_T YAngleScale_Gain;             /* Expression: Crane3D_ScaleCoeff( 5 )
                                        * Referenced by: '<S3>/Y Angle Scale'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S11>/Filter'
                                        */
  real_T Integrator_IC_a;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Filter_IC_j;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S12>/Filter'
                                        */
  real_T Integrator_IC_f;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Filter_IC_m;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S13>/Filter'
                                        */
  real_T Integrator_IC_h;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T Filter_IC_o;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S14>/Filter'
                                        */
  real_T Integrator_IC_c;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S16>/Integrator'
                                        */
  real_T Filter_IC_a;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S16>/Filter'
                                        */
  real_T Integrator_IC_fc;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S17>/Integrator'
                                        */
  real_T Filter_IC_c;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S17>/Filter'
                                        */
  real_T Integrator_IC_cx;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Filter_IC_or;                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S15>/Filter'
                                        */
  real_T Integrator_IC_a2;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Filter_IC_ms;                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S18>/Filter'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T PWM_P1_Size[2];               /* Computed Parameter: PWM_P1_Size
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T PWM_P1;                       /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T PWM_P2_Size[2];               /* Computed Parameter: PWM_P2_Size
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T PWM_P2;                       /* Expression: T0
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T LimitFlag_P1_Size[2];         /* Computed Parameter: LimitFlag_P1_Size
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlag_P2_Size[2];         /* Computed Parameter: LimitFlag_P2_Size
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S3>/LimitFlag'
                                        */
  real_T LimitFlagSource_Value[3];     /* Expression: [1 1 1]
                                        * Referenced by: '<S3>/LimitFlagSource'
                                        */
  real_T LimitSource_Value[3];         /* Expression: Crane3D_RangeBit
                                        * Referenced by: '<S3>/LimitSource'
                                        */
  real_T SetLimit_P1_Size[2];          /* Computed Parameter: SetLimit_P1_Size
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T SetLimit_P1;                  /* Expression: BaseAddress
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T SetLimit_P2_Size[2];          /* Computed Parameter: SetLimit_P2_Size
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T SetLimit_P2;                  /* Expression: T0
                                        * Referenced by: '<S3>/SetLimit'
                                        */
  real_T LimitSwitch_P1_Size[2];       /* Computed Parameter: LimitSwitch_P1_Size
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T LimitSwitch_P1;               /* Expression: BaseAddress
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2_Size[2];       /* Computed Parameter: LimitSwitch_P2_Size
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2;               /* Expression: T0
                                        * Referenced by: '<S3>/LimitSwitch'
                                        */
  real_T PWMPrescaler_P1_Size[2];      /* Computed Parameter: PWMPrescaler_P1_Size
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2_Size[2];      /* Computed Parameter: PWMPrescaler_P2_Size
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2;              /* Expression: T0
                                        * Referenced by: '<S3>/PWMPrescaler'
                                        */
  real_T PWMPrescalerSource_Value;     /* Expression: 60
                                        * Referenced by: '<S3>/PWMPrescalerSource'
                                        */
  real_T ResetEncoder_P1_Size[2];      /* Computed Parameter: ResetEncoder_P1_Size
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetEncoder_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2_Size[2];      /* Computed Parameter: ResetEncoder_P2_Size
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2;              /* Expression: T0
                                        * Referenced by: '<S3>/ResetEncoder'
                                        */
  real_T ResetSource_Value[5];         /* Expression: [0 0 0 0 0]
                                        * Referenced by: '<S3>/ResetSource'
                                        */
  real_T ResetSwitchFlag_P1_Size[2];   /* Computed Parameter: ResetSwitchFlag_P1_Size
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P1;           /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2_Size[2];   /* Computed Parameter: ResetSwitchFlag_P2_Size
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2;           /* Expression: T0
                                        * Referenced by: '<S3>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlagSource_Value[3];/* Expression: [ 0 0 0 ]
                                         * Referenced by: '<S3>/ResetSwitchFlagSource'
                                         */
  real_T ThermFlag_P1_Size[2];         /* Computed Parameter: ThermFlag_P1_Size
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlag_P2_Size[2];         /* Computed Parameter: ThermFlag_P2_Size
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S3>/ThermFlag '
                                        */
  real_T ThermFlagSource_Value[3];     /* Expression: [1 1 1]
                                        * Referenced by: '<S3>/ThermFlagSource'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Crane3D_DevDriv_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[9];
    SimStruct *childSFunctionPtrs[9];
    struct _ssBlkInfo2 blkInfo2[9];
    struct _ssSFcnModelMethods2 methods2[9];
    struct _ssSFcnModelMethods3 methods3[9];
    struct _ssStatesInfo2 statesInfo2[9];
    ssPeriodicStatesInfo periodicStatesInfo[9];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[5];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn8;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[16];
    real_T odeF[6][16];
    ODE5_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Crane3D_DevDriv_T Crane3D_DevDriv_P;

/* Block signals (auto storage) */
extern B_Crane3D_DevDriv_T Crane3D_DevDriv_B;

/* Continuous states (auto storage) */
extern X_Crane3D_DevDriv_T Crane3D_DevDriv_X;

/* Block states (auto storage) */
extern DW_Crane3D_DevDriv_T Crane3D_DevDriv_DW;

/* Model entry point functions */
extern void Crane3D_DevDriv_initialize(void);
extern void Crane3D_DevDriv_output(void);
extern void Crane3D_DevDriv_update(void);
extern void Crane3D_DevDriv_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Crane3D_DevDriv_rtModel *Crane3D_DevDriv(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Crane3D_DevDriv_T *const Crane3D_DevDriv_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Crane3D_DevDriv'
 * '<S1>'   : 'Crane3D_DevDriv/Controller'
 * '<S2>'   : 'Crane3D_DevDriv/Convert Coordinates'
 * '<S3>'   : 'Crane3D_DevDriv/Crane 3D'
 * '<S4>'   : 'Crane3D_DevDriv/Select most convenient path'
 * '<S5>'   : 'Crane3D_DevDriv/Controller/Enforce Soft Limits and Overflow'
 * '<S6>'   : 'Crane3D_DevDriv/Controller/PID Controler'
 * '<S7>'   : 'Crane3D_DevDriv/Controller/PID Controler/GainDesch'
 * '<S8>'   : 'Crane3D_DevDriv/Controller/PID Controler/GainDesch1'
 * '<S9>'   : 'Crane3D_DevDriv/Controller/PID Controler/GainSch'
 * '<S10>'  : 'Crane3D_DevDriv/Controller/PID Controler/GainSch1'
 * '<S11>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller'
 * '<S12>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller1'
 * '<S13>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller2'
 * '<S14>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller3'
 * '<S15>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller4'
 * '<S16>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller5'
 * '<S17>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller6'
 * '<S18>'  : 'Crane3D_DevDriv/Controller/PID Controler/PID Controller7'
 */
#endif                                 /* RTW_HEADER_Crane3D_DevDriv_h_ */
