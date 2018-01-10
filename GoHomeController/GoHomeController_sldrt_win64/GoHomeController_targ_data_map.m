  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (GoHomeController_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_P.DetectRisePositive_vinit
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 90;
      section.data(90)  = dumData; %prealloc
      
	  ;% GoHomeController_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GoHomeController_P.Constant_Value
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GoHomeController_P.Constant1_Value_j
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GoHomeController_P.Constant_Value_b
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GoHomeController_P.TransferFcn3_A
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GoHomeController_P.TransferFcn3_C
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 6;
	
	  ;% GoHomeController_P.TransferFcn1_A
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 8;
	
	  ;% GoHomeController_P.TransferFcn1_C
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 10;
	
	  ;% GoHomeController_P.Constant_Value_a
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 12;
	
	  ;% GoHomeController_P.Constant1_Value_c
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 13;
	
	  ;% GoHomeController_P.Constant2_Value
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 14;
	
	  ;% GoHomeController_P.Constant3_Value
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 15;
	
	  ;% GoHomeController_P.YRef_Value
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 16;
	
	  ;% GoHomeController_P.Y_DotRef_Value
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 17;
	
	  ;% GoHomeController_P.XRef_Value
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 18;
	
	  ;% GoHomeController_P.X_DotRef_Value
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 19;
	
	  ;% GoHomeController_P.AlphaRef_Value
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 20;
	
	  ;% GoHomeController_P.Alpha_DotRef_Value
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 21;
	
	  ;% GoHomeController_P.BetaRef_Value
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 22;
	
	  ;% GoHomeController_P.Beta_DotRef_Value
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 23;
	
	  ;% GoHomeController_P.Encoder_P1_Size
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 24;
	
	  ;% GoHomeController_P.Encoder_P1
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 26;
	
	  ;% GoHomeController_P.Encoder_P2_Size
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 27;
	
	  ;% GoHomeController_P.Encoder_P2
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 29;
	
	  ;% GoHomeController_P.Encoder500PPR_Gain
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 30;
	
	  ;% GoHomeController_P.YScale_Gain
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 31;
	
	  ;% GoHomeController_P.UnitDelay_InitialCondition
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 32;
	
	  ;% GoHomeController_P.XScale_Gain
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 37;
	
	  ;% GoHomeController_P.ZScale_Gain
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 38;
	
	  ;% GoHomeController_P.XAngleScale_Gain
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 39;
	
	  ;% GoHomeController_P.YAngleScale_Gain
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 40;
	
	  ;% GoHomeController_P.GainZ1_Gain
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 41;
	
	  ;% GoHomeController_P.DerivativeFilter_NumCoef
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 42;
	
	  ;% GoHomeController_P.DerivativeFilter_DenCoef
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 59;
	
	  ;% GoHomeController_P.DerivativeFilter_InitialStates
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 76;
	
	  ;% GoHomeController_P.Gain1_Gain
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 77;
	
	  ;% GoHomeController_P.Bias_Bias
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 78;
	
	  ;% GoHomeController_P.Gain_Gain
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 79;
	
	  ;% GoHomeController_P.DiscreteTimeIntegrator_gainval
	  section.data(39).logicalSrcIdx = 39;
	  section.data(39).dtTransOffset = 80;
	
	  ;% GoHomeController_P.DiscreteTimeIntegrator_IC
	  section.data(40).logicalSrcIdx = 40;
	  section.data(40).dtTransOffset = 81;
	
	  ;% GoHomeController_P.Gain1_Gain_j
	  section.data(41).logicalSrcIdx = 41;
	  section.data(41).dtTransOffset = 82;
	
	  ;% GoHomeController_P.Gain_Gain_g
	  section.data(42).logicalSrcIdx = 42;
	  section.data(42).dtTransOffset = 83;
	
	  ;% GoHomeController_P.Saturation_UpperSat
	  section.data(43).logicalSrcIdx = 43;
	  section.data(43).dtTransOffset = 103;
	
	  ;% GoHomeController_P.Saturation_LowerSat
	  section.data(44).logicalSrcIdx = 44;
	  section.data(44).dtTransOffset = 104;
	
	  ;% GoHomeController_P.LimitSwitch_P1_Size
	  section.data(45).logicalSrcIdx = 45;
	  section.data(45).dtTransOffset = 105;
	
	  ;% GoHomeController_P.LimitSwitch_P1
	  section.data(46).logicalSrcIdx = 46;
	  section.data(46).dtTransOffset = 107;
	
	  ;% GoHomeController_P.LimitSwitch_P2_Size
	  section.data(47).logicalSrcIdx = 47;
	  section.data(47).dtTransOffset = 108;
	
	  ;% GoHomeController_P.LimitSwitch_P2
	  section.data(48).logicalSrcIdx = 48;
	  section.data(48).dtTransOffset = 110;
	
	  ;% GoHomeController_P.LimitSwitchGain_Gain
	  section.data(49).logicalSrcIdx = 49;
	  section.data(49).dtTransOffset = 111;
	
	  ;% GoHomeController_P.PWM_P1_Size
	  section.data(50).logicalSrcIdx = 50;
	  section.data(50).dtTransOffset = 112;
	
	  ;% GoHomeController_P.PWM_P1
	  section.data(51).logicalSrcIdx = 51;
	  section.data(51).dtTransOffset = 114;
	
	  ;% GoHomeController_P.PWM_P2_Size
	  section.data(52).logicalSrcIdx = 52;
	  section.data(52).dtTransOffset = 115;
	
	  ;% GoHomeController_P.PWM_P2
	  section.data(53).logicalSrcIdx = 53;
	  section.data(53).dtTransOffset = 117;
	
	  ;% GoHomeController_P.Saturation_UpperSat_h
	  section.data(54).logicalSrcIdx = 54;
	  section.data(54).dtTransOffset = 118;
	
	  ;% GoHomeController_P.Saturation_LowerSat_d
	  section.data(55).logicalSrcIdx = 55;
	  section.data(55).dtTransOffset = 119;
	
	  ;% GoHomeController_P.ResetEncoder_P1_Size
	  section.data(56).logicalSrcIdx = 56;
	  section.data(56).dtTransOffset = 120;
	
	  ;% GoHomeController_P.ResetEncoder_P1
	  section.data(57).logicalSrcIdx = 57;
	  section.data(57).dtTransOffset = 122;
	
	  ;% GoHomeController_P.ResetEncoder_P2_Size
	  section.data(58).logicalSrcIdx = 58;
	  section.data(58).dtTransOffset = 123;
	
	  ;% GoHomeController_P.ResetEncoder_P2
	  section.data(59).logicalSrcIdx = 59;
	  section.data(59).dtTransOffset = 125;
	
	  ;% GoHomeController_P.LimitFlag_P1_Size
	  section.data(60).logicalSrcIdx = 60;
	  section.data(60).dtTransOffset = 126;
	
	  ;% GoHomeController_P.LimitFlag_P1
	  section.data(61).logicalSrcIdx = 61;
	  section.data(61).dtTransOffset = 128;
	
	  ;% GoHomeController_P.LimitFlag_P2_Size
	  section.data(62).logicalSrcIdx = 62;
	  section.data(62).dtTransOffset = 129;
	
	  ;% GoHomeController_P.LimitFlag_P2
	  section.data(63).logicalSrcIdx = 63;
	  section.data(63).dtTransOffset = 131;
	
	  ;% GoHomeController_P.LimitFlagSource_Value
	  section.data(64).logicalSrcIdx = 64;
	  section.data(64).dtTransOffset = 132;
	
	  ;% GoHomeController_P.LimitSource_Value
	  section.data(65).logicalSrcIdx = 65;
	  section.data(65).dtTransOffset = 135;
	
	  ;% GoHomeController_P.SetLimit_P1_Size
	  section.data(66).logicalSrcIdx = 66;
	  section.data(66).dtTransOffset = 138;
	
	  ;% GoHomeController_P.SetLimit_P1
	  section.data(67).logicalSrcIdx = 67;
	  section.data(67).dtTransOffset = 140;
	
	  ;% GoHomeController_P.SetLimit_P2_Size
	  section.data(68).logicalSrcIdx = 68;
	  section.data(68).dtTransOffset = 141;
	
	  ;% GoHomeController_P.SetLimit_P2
	  section.data(69).logicalSrcIdx = 69;
	  section.data(69).dtTransOffset = 143;
	
	  ;% GoHomeController_P.PWMPrescaler_P1_Size
	  section.data(70).logicalSrcIdx = 70;
	  section.data(70).dtTransOffset = 144;
	
	  ;% GoHomeController_P.PWMPrescaler_P1
	  section.data(71).logicalSrcIdx = 71;
	  section.data(71).dtTransOffset = 146;
	
	  ;% GoHomeController_P.PWMPrescaler_P2_Size
	  section.data(72).logicalSrcIdx = 72;
	  section.data(72).dtTransOffset = 147;
	
	  ;% GoHomeController_P.PWMPrescaler_P2
	  section.data(73).logicalSrcIdx = 73;
	  section.data(73).dtTransOffset = 149;
	
	  ;% GoHomeController_P.PWMPrescalerSource_Value
	  section.data(74).logicalSrcIdx = 74;
	  section.data(74).dtTransOffset = 150;
	
	  ;% GoHomeController_P.ResetSwitchFlag_P1_Size
	  section.data(75).logicalSrcIdx = 75;
	  section.data(75).dtTransOffset = 151;
	
	  ;% GoHomeController_P.ResetSwitchFlag_P1
	  section.data(76).logicalSrcIdx = 76;
	  section.data(76).dtTransOffset = 153;
	
	  ;% GoHomeController_P.ResetSwitchFlag_P2_Size
	  section.data(77).logicalSrcIdx = 77;
	  section.data(77).dtTransOffset = 154;
	
	  ;% GoHomeController_P.ResetSwitchFlag_P2
	  section.data(78).logicalSrcIdx = 78;
	  section.data(78).dtTransOffset = 156;
	
	  ;% GoHomeController_P.ResetSwitchFlagSource_Value
	  section.data(79).logicalSrcIdx = 79;
	  section.data(79).dtTransOffset = 157;
	
	  ;% GoHomeController_P.ThermFlag_P1_Size
	  section.data(80).logicalSrcIdx = 80;
	  section.data(80).dtTransOffset = 160;
	
	  ;% GoHomeController_P.ThermFlag_P1
	  section.data(81).logicalSrcIdx = 81;
	  section.data(81).dtTransOffset = 162;
	
	  ;% GoHomeController_P.ThermFlag_P2_Size
	  section.data(82).logicalSrcIdx = 82;
	  section.data(82).dtTransOffset = 163;
	
	  ;% GoHomeController_P.ThermFlag_P2
	  section.data(83).logicalSrcIdx = 83;
	  section.data(83).dtTransOffset = 165;
	
	  ;% GoHomeController_P.ThermFlagSource_Value
	  section.data(84).logicalSrcIdx = 84;
	  section.data(84).dtTransOffset = 166;
	
	  ;% GoHomeController_P.UnitDelay_InitialCondition_n
	  section.data(85).logicalSrcIdx = 85;
	  section.data(85).dtTransOffset = 169;
	
	  ;% GoHomeController_P.Switch_Threshold
	  section.data(86).logicalSrcIdx = 86;
	  section.data(86).dtTransOffset = 170;
	
	  ;% GoHomeController_P.PulseGenerator_Amp
	  section.data(87).logicalSrcIdx = 87;
	  section.data(87).dtTransOffset = 171;
	
	  ;% GoHomeController_P.PulseGenerator_Period
	  section.data(88).logicalSrcIdx = 88;
	  section.data(88).dtTransOffset = 172;
	
	  ;% GoHomeController_P.PulseGenerator_Duty
	  section.data(89).logicalSrcIdx = 89;
	  section.data(89).dtTransOffset = 173;
	
	  ;% GoHomeController_P.PulseGenerator_PhaseDelay
	  section.data(90).logicalSrcIdx = 90;
	  section.data(90).dtTransOffset = 174;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 4;
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
    ;% Auto data (GoHomeController_B)
    ;%
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% GoHomeController_B.dx2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GoHomeController_B.TransferFcn1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GoHomeController_B.vel
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GoHomeController_B.Constant1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% GoHomeController_B.Constant2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% GoHomeController_B.Constant3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% GoHomeController_B.YReference
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% GoHomeController_B.Y_dotReference
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% GoHomeController_B.XReference
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 9;
	
	  ;% GoHomeController_B.X_dotReference
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% GoHomeController_B.AlphaReference
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 11;
	
	  ;% GoHomeController_B.Alpha_dotReference
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 12;
	
	  ;% GoHomeController_B.BetaReference
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 13;
	
	  ;% GoHomeController_B.Beta_dotReference
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 14;
	
	  ;% GoHomeController_B.Reference
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 15;
	
	  ;% GoHomeController_B.Encoder
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% GoHomeController_B.YScale
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% GoHomeController_B.XScale
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% GoHomeController_B.ZScale
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% GoHomeController_B.XAngleScale
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 31;
	
	  ;% GoHomeController_B.YAngleScale
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 32;
	
	  ;% GoHomeController_B.Error
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 33;
	
	  ;% GoHomeController_B.LimitSwitch
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 41;
	
	  ;% GoHomeController_B.PWM
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 44;
	
	  ;% GoHomeController_B.Saturation
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 47;
	
	  ;% GoHomeController_B.ResetEncoder
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 50;
	
	  ;% GoHomeController_B.LimitFlag
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 55;
	
	  ;% GoHomeController_B.LimitFlagSource
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 58;
	
	  ;% GoHomeController_B.LimitSource
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 61;
	
	  ;% GoHomeController_B.SetLimit
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 64;
	
	  ;% GoHomeController_B.PWMPrescaler
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 67;
	
	  ;% GoHomeController_B.PWMPrescalerSource
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 68;
	
	  ;% GoHomeController_B.ResetSwitchFlag
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 69;
	
	  ;% GoHomeController_B.ResetSwitchFlagSource
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 72;
	
	  ;% GoHomeController_B.ThermFlag
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 75;
	
	  ;% GoHomeController_B.ThermFlagSource
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 78;
	
	  ;% GoHomeController_B.DataTypeConversion
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 81;
	
	  ;% GoHomeController_B.Sum
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 82;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_B.Compare
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_B.sf_YOverflowProtection1.y
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_B.sf_XOverflowProtection.y
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    nTotSects     = 4;
    sectIdxOffset = 4;
    
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
    ;% Auto data (GoHomeController_DW)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% GoHomeController_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GoHomeController_DW.DerivativeFilter_states
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% GoHomeController_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 85;
	
	  ;% GoHomeController_DW.UnitDelay_DSTATE_d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 87;
	
	  ;% GoHomeController_DW.DerivativeFilter_tmp
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 88;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Cranehardware_at_outport_3_PWORK.AQHandles
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Reference_at_outport_0_PWORK.AQHandles
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Sum_at_outport_0_PWORK.AQHandles
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Crane3D_at_outport_0_PWORK.AQHandles
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Crane3D_at_outport_1_PWORK.AQHandles
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Crane3D_at_outport_2_PWORK.AQHandles
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Crane3D_at_outport_3_PWORK.AQHandles
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GoHomeController_DW.HiddenToAsyncQueue_InsertedFor_Crane3D_at_outport_4_PWORK.AQHandles
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GoHomeController_DW.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 899873547;
  targMap.checksum1 = 365729218;
  targMap.checksum2 = 2302677284;
  targMap.checksum3 = 703345186;

