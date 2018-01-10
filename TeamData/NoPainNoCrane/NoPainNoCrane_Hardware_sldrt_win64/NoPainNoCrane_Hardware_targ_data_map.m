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
    ;% Auto data (NoPainNoCrane_Hardware_P)
    ;%
      section.nData     = 82;
      section.data(82)  = dumData; %prealloc
      
	  ;% NoPainNoCrane_Hardware_P.PIDController_D
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController1_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController5_D
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController2_D
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController_I
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController1_I
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController2_I
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController5_I
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController_N
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController1_N
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController5_N
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController2_N
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController_P
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController1_P
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController5_P
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% NoPainNoCrane_Hardware_P.PIDController2_P
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% NoPainNoCrane_Hardware_P.Encoder_P1_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% NoPainNoCrane_Hardware_P.Encoder_P1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 18;
	
	  ;% NoPainNoCrane_Hardware_P.Encoder_P2_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 19;
	
	  ;% NoPainNoCrane_Hardware_P.Encoder_P2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 21;
	
	  ;% NoPainNoCrane_Hardware_P.Encoder500PPR_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 22;
	
	  ;% NoPainNoCrane_Hardware_P.XScale_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 23;
	
	  ;% NoPainNoCrane_Hardware_P.YScale_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 24;
	
	  ;% NoPainNoCrane_Hardware_P.XAngleScale_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 25;
	
	  ;% NoPainNoCrane_Hardware_P.YAngleScale_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 26;
	
	  ;% NoPainNoCrane_Hardware_P.Constant_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 27;
	
	  ;% NoPainNoCrane_Hardware_P.UnitDelay_InitialCondition
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 57;
	
	  ;% NoPainNoCrane_Hardware_P.ZScale_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 62;
	
	  ;% NoPainNoCrane_Hardware_P.GainZ1_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 63;
	
	  ;% NoPainNoCrane_Hardware_P.Integrator_IC
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 64;
	
	  ;% NoPainNoCrane_Hardware_P.Filter_IC
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 65;
	
	  ;% NoPainNoCrane_Hardware_P.Constant_Value_b
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 66;
	
	  ;% NoPainNoCrane_Hardware_P.Integrator_IC_e
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 67;
	
	  ;% NoPainNoCrane_Hardware_P.Filter_IC_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 68;
	
	  ;% NoPainNoCrane_Hardware_P.Integrator_IC_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 69;
	
	  ;% NoPainNoCrane_Hardware_P.Filter_IC_a
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 70;
	
	  ;% NoPainNoCrane_Hardware_P.Constant1_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 71;
	
	  ;% NoPainNoCrane_Hardware_P.Integrator_IC_k
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 72;
	
	  ;% NoPainNoCrane_Hardware_P.Filter_IC_d
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 73;
	
	  ;% NoPainNoCrane_Hardware_P.X_range_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 74;
	
	  ;% NoPainNoCrane_Hardware_P.Y_range_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 76;
	
	  ;% NoPainNoCrane_Hardware_P.Constant_Value_f
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 78;
	
	  ;% NoPainNoCrane_Hardware_P.PWM_P1_Size
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 79;
	
	  ;% NoPainNoCrane_Hardware_P.PWM_P1
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 81;
	
	  ;% NoPainNoCrane_Hardware_P.PWM_P2_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 82;
	
	  ;% NoPainNoCrane_Hardware_P.PWM_P2
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 84;
	
	  ;% NoPainNoCrane_Hardware_P.Saturation_UpperSat
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 85;
	
	  ;% NoPainNoCrane_Hardware_P.Saturation_LowerSat
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 86;
	
	  ;% NoPainNoCrane_Hardware_P.LimitFlag_P1_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 87;
	
	  ;% NoPainNoCrane_Hardware_P.LimitFlag_P1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 89;
	
	  ;% NoPainNoCrane_Hardware_P.LimitFlag_P2_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 90;
	
	  ;% NoPainNoCrane_Hardware_P.LimitFlag_P2
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 92;
	
	  ;% NoPainNoCrane_Hardware_P.LimitFlagSource_Value
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 93;
	
	  ;% NoPainNoCrane_Hardware_P.LimitSource_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 96;
	
	  ;% NoPainNoCrane_Hardware_P.SetLimit_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 99;
	
	  ;% NoPainNoCrane_Hardware_P.SetLimit_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 101;
	
	  ;% NoPainNoCrane_Hardware_P.SetLimit_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 102;
	
	  ;% NoPainNoCrane_Hardware_P.SetLimit_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 104;
	
	  ;% NoPainNoCrane_Hardware_P.LimitSwitch_P1_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 105;
	
	  ;% NoPainNoCrane_Hardware_P.LimitSwitch_P1
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 107;
	
	  ;% NoPainNoCrane_Hardware_P.LimitSwitch_P2_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 108;
	
	  ;% NoPainNoCrane_Hardware_P.LimitSwitch_P2
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 110;
	
	  ;% NoPainNoCrane_Hardware_P.PWMPrescaler_P1_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 111;
	
	  ;% NoPainNoCrane_Hardware_P.PWMPrescaler_P1
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 113;
	
	  ;% NoPainNoCrane_Hardware_P.PWMPrescaler_P2_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 114;
	
	  ;% NoPainNoCrane_Hardware_P.PWMPrescaler_P2
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 116;
	
	  ;% NoPainNoCrane_Hardware_P.PWMPrescalerSource_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 117;
	
	  ;% NoPainNoCrane_Hardware_P.ResetEncoder_P1_Size
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 118;
	
	  ;% NoPainNoCrane_Hardware_P.ResetEncoder_P1
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 120;
	
	  ;% NoPainNoCrane_Hardware_P.ResetEncoder_P2_Size
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 121;
	
	  ;% NoPainNoCrane_Hardware_P.ResetEncoder_P2
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 123;
	
	  ;% NoPainNoCrane_Hardware_P.ResetSource_Value
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 124;
	
	  ;% NoPainNoCrane_Hardware_P.ResetSwitchFlag_P1_Size
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 129;
	
	  ;% NoPainNoCrane_Hardware_P.ResetSwitchFlag_P1
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 131;
	
	  ;% NoPainNoCrane_Hardware_P.ResetSwitchFlag_P2_Size
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 132;
	
	  ;% NoPainNoCrane_Hardware_P.ResetSwitchFlag_P2
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 134;
	
	  ;% NoPainNoCrane_Hardware_P.ResetSwitchFlagSource_Value
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 135;
	
	  ;% NoPainNoCrane_Hardware_P.ThermFlag_P1_Size
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 138;
	
	  ;% NoPainNoCrane_Hardware_P.ThermFlag_P1
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 140;
	
	  ;% NoPainNoCrane_Hardware_P.ThermFlag_P2_Size
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 141;
	
	  ;% NoPainNoCrane_Hardware_P.ThermFlag_P2
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 143;
	
	  ;% NoPainNoCrane_Hardware_P.ThermFlagSource_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 144;
	
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
    ;% Auto data (NoPainNoCrane_Hardware_B)
    ;%
      section.nData     = 44;
      section.data(44)  = dumData; %prealloc
      
	  ;% NoPainNoCrane_Hardware_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% NoPainNoCrane_Hardware_B.XScale
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% NoPainNoCrane_Hardware_B.YScale
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% NoPainNoCrane_Hardware_B.XAngleScale
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% NoPainNoCrane_Hardware_B.YAngleScale
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% NoPainNoCrane_Hardware_B.ZScale
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% NoPainNoCrane_Hardware_B.Derivatives
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% NoPainNoCrane_Hardware_B.TmpSignalConversionAtToWorkspaceInport1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
	  ;% NoPainNoCrane_Hardware_B.ProportionalGain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 23;
	
	  ;% NoPainNoCrane_Hardware_B.DerivativeGain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 24;
	
	  ;% NoPainNoCrane_Hardware_B.FilterCoefficient
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 25;
	
	  ;% NoPainNoCrane_Hardware_B.ProportionalGain_j
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 26;
	
	  ;% NoPainNoCrane_Hardware_B.DerivativeGain_f
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 27;
	
	  ;% NoPainNoCrane_Hardware_B.FilterCoefficient_g
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 28;
	
	  ;% NoPainNoCrane_Hardware_B.ProportionalGain_o
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 29;
	
	  ;% NoPainNoCrane_Hardware_B.DerivativeGain_c
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 30;
	
	  ;% NoPainNoCrane_Hardware_B.FilterCoefficient_e
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 31;
	
	  ;% NoPainNoCrane_Hardware_B.ProportionalGain_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 32;
	
	  ;% NoPainNoCrane_Hardware_B.DerivativeGain_m
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 33;
	
	  ;% NoPainNoCrane_Hardware_B.FilterCoefficient_o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 34;
	
	  ;% NoPainNoCrane_Hardware_B.IntegralGain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 35;
	
	  ;% NoPainNoCrane_Hardware_B.IntegralGain_a
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 36;
	
	  ;% NoPainNoCrane_Hardware_B.IntegralGain_p
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 37;
	
	  ;% NoPainNoCrane_Hardware_B.IntegralGain_g
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 38;
	
	  ;% NoPainNoCrane_Hardware_B.PWM
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 39;
	
	  ;% NoPainNoCrane_Hardware_B.Saturation
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 42;
	
	  ;% NoPainNoCrane_Hardware_B.LimitFlag
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 45;
	
	  ;% NoPainNoCrane_Hardware_B.LimitFlagSource
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 48;
	
	  ;% NoPainNoCrane_Hardware_B.LimitSource
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 51;
	
	  ;% NoPainNoCrane_Hardware_B.SetLimit
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 54;
	
	  ;% NoPainNoCrane_Hardware_B.LimitSwitch
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 57;
	
	  ;% NoPainNoCrane_Hardware_B.PWMPrescaler
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 60;
	
	  ;% NoPainNoCrane_Hardware_B.PWMPrescalerSource
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 61;
	
	  ;% NoPainNoCrane_Hardware_B.ResetEncoder
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 62;
	
	  ;% NoPainNoCrane_Hardware_B.ResetSource
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 67;
	
	  ;% NoPainNoCrane_Hardware_B.ResetSwitchFlag
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 72;
	
	  ;% NoPainNoCrane_Hardware_B.ResetSwitchFlagSource
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 75;
	
	  ;% NoPainNoCrane_Hardware_B.ThermFlag
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 78;
	
	  ;% NoPainNoCrane_Hardware_B.ThermFlagSource
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 81;
	
	  ;% NoPainNoCrane_Hardware_B.Clock
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 84;
	
	  ;% NoPainNoCrane_Hardware_B.x
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 85;
	
	  ;% NoPainNoCrane_Hardware_B.y
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 86;
	
	  ;% NoPainNoCrane_Hardware_B.x_l
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 87;
	
	  ;% NoPainNoCrane_Hardware_B.y_f
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 88;
	
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
    ;% Auto data (NoPainNoCrane_Hardware_DW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% NoPainNoCrane_Hardware_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% NoPainNoCrane_Hardware_DW.WP_Index
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% NoPainNoCrane_Hardware_DW.ToWorkspace_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% NoPainNoCrane_Hardware_DW.XDes_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% NoPainNoCrane_Hardware_DW.XTraj_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% NoPainNoCrane_Hardware_DW.YDes_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% NoPainNoCrane_Hardware_DW.YTraj_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% NoPainNoCrane_Hardware_DW.anglex_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% NoPainNoCrane_Hardware_DW.angley_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% NoPainNoCrane_Hardware_DW.xpos_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% NoPainNoCrane_Hardware_DW.ypos_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% NoPainNoCrane_Hardware_DW.ToWorkspace4_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
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


  targMap.checksum0 = 2744582875;
  targMap.checksum1 = 726568948;
  targMap.checksum2 = 401154565;
  targMap.checksum3 = 2310163723;

