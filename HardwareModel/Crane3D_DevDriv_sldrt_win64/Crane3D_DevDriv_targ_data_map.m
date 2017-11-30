  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Crane3D_DevDriv_P)
    ;%
      section.nData     = 67;
      section.data(67)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_P.Dx
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_P.Dy
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_P.Ix
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane3D_DevDriv_P.Iy
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Crane3D_DevDriv_P.Px
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Crane3D_DevDriv_P.Py
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Crane3D_DevDriv_P.waypoints
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Crane3D_DevDriv_P.PIDController_LowerSaturationLimit
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 42;
	
	  ;% Crane3D_DevDriv_P.PIDController2_LowerSaturationLimit
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 43;
	
	  ;% Crane3D_DevDriv_P.PIDController_N
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 44;
	
	  ;% Crane3D_DevDriv_P.PIDController2_N
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 45;
	
	  ;% Crane3D_DevDriv_P.PIDController_UpperSaturationLimit
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 46;
	
	  ;% Crane3D_DevDriv_P.PIDController2_UpperSaturationLimit
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 47;
	
	  ;% Crane3D_DevDriv_P.Encoder_P1_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 48;
	
	  ;% Crane3D_DevDriv_P.Encoder_P1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 50;
	
	  ;% Crane3D_DevDriv_P.Encoder_P2_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 51;
	
	  ;% Crane3D_DevDriv_P.Encoder_P2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 53;
	
	  ;% Crane3D_DevDriv_P.Encoder500PPR_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 54;
	
	  ;% Crane3D_DevDriv_P.XScale_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 55;
	
	  ;% Crane3D_DevDriv_P.YScale_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 56;
	
	  ;% Crane3D_DevDriv_P.XAngleScale_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 57;
	
	  ;% Crane3D_DevDriv_P.YAngleScale_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 58;
	
	  ;% Crane3D_DevDriv_P.Filter_IC
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 59;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 60;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_k
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 61;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_j
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 62;
	
	  ;% Crane3D_DevDriv_P.Constant_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 63;
	
	  ;% Crane3D_DevDriv_P.PWM_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 64;
	
	  ;% Crane3D_DevDriv_P.PWM_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 66;
	
	  ;% Crane3D_DevDriv_P.PWM_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 67;
	
	  ;% Crane3D_DevDriv_P.PWM_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 69;
	
	  ;% Crane3D_DevDriv_P.Saturation_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 70;
	
	  ;% Crane3D_DevDriv_P.Saturation_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 71;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P1_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 72;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 74;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P2_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 75;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P2
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 77;
	
	  ;% Crane3D_DevDriv_P.LimitFlagSource_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 78;
	
	  ;% Crane3D_DevDriv_P.LimitSource_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 81;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P1_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 84;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 86;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P2_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 87;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 89;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P1_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 90;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 92;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P2_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 93;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 95;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P1_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 96;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 98;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P2_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 99;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 101;
	
	  ;% Crane3D_DevDriv_P.PWMPrescalerSource_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 102;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P1_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 103;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P1
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 105;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P2_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 106;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P2
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 108;
	
	  ;% Crane3D_DevDriv_P.ResetSource_Value
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 109;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P1_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 114;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P1
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 116;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P2_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 117;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P2
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 119;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlagSource_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 120;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P1_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 123;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P1
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 125;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P2_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 126;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P2
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 128;
	
	  ;% Crane3D_DevDriv_P.ThermFlagSource_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 129;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Crane3D_DevDriv_B)
    ;%
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_B.Encoder
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_B.XScale
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Crane3D_DevDriv_B.YScale
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Crane3D_DevDriv_B.XAngleScale
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Crane3D_DevDriv_B.YAngleScale
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Crane3D_DevDriv_B.IntegralGain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_o
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_m
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_b
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_e
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% Crane3D_DevDriv_B.PWM
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Crane3D_DevDriv_B.Saturation
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Crane3D_DevDriv_B.LimitFlag
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% Crane3D_DevDriv_B.LimitFlagSource
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 27;
	
	  ;% Crane3D_DevDriv_B.LimitSource
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% Crane3D_DevDriv_B.SetLimit
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 33;
	
	  ;% Crane3D_DevDriv_B.LimitSwitch
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 36;
	
	  ;% Crane3D_DevDriv_B.PWMPrescaler
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 39;
	
	  ;% Crane3D_DevDriv_B.PWMPrescalerSource
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 40;
	
	  ;% Crane3D_DevDriv_B.ResetEncoder
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 41;
	
	  ;% Crane3D_DevDriv_B.ResetSource
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 46;
	
	  ;% Crane3D_DevDriv_B.ResetSwitchFlag
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 51;
	
	  ;% Crane3D_DevDriv_B.ResetSwitchFlagSource
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 54;
	
	  ;% Crane3D_DevDriv_B.ThermFlag
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 57;
	
	  ;% Crane3D_DevDriv_B.ThermFlagSource
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 60;
	
	  ;% Crane3D_DevDriv_B.x
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 63;
	
	  ;% Crane3D_DevDriv_B.y
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 64;
	
	  ;% Crane3D_DevDriv_B.x_l
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 65;
	
	  ;% Crane3D_DevDriv_B.y_f
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Crane3D_DevDriv_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_DW.WP_Index
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_DW.ToWorkspace4_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_DW.XDes_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_DW.XTraj_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane3D_DevDriv_DW.YDes_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Crane3D_DevDriv_DW.YTraj_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Crane3D_DevDriv_DW.anglex_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Crane3D_DevDriv_DW.angley_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Crane3D_DevDriv_DW.xpos_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Crane3D_DevDriv_DW.ypos_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 683255587;
  targMap.checksum1 = 516352514;
  targMap.checksum2 = 2244256495;
  targMap.checksum3 = 3693446197;

