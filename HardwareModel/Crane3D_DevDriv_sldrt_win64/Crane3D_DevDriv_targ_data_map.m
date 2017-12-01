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
      section.nData     = 89;
      section.data(89)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_P.DC1x
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_P.DC1y
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_P.DC2x
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane3D_DevDriv_P.DC2y
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Crane3D_DevDriv_P.IC1x
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Crane3D_DevDriv_P.IC1y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Crane3D_DevDriv_P.IC2x
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Crane3D_DevDriv_P.IC2y
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Crane3D_DevDriv_P.PC1x
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Crane3D_DevDriv_P.PC1y
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Crane3D_DevDriv_P.PC2x
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Crane3D_DevDriv_P.PC2y
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Crane3D_DevDriv_P.waypoints
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Crane3D_DevDriv_P.xRange
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 57;
	
	  ;% Crane3D_DevDriv_P.yRange
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 59;
	
	  ;% Crane3D_DevDriv_P.PIDController_N
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 61;
	
	  ;% Crane3D_DevDriv_P.PIDController1_N
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 62;
	
	  ;% Crane3D_DevDriv_P.PIDController2_N
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 63;
	
	  ;% Crane3D_DevDriv_P.PIDController3_N
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 64;
	
	  ;% Crane3D_DevDriv_P.PIDController5_N
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 65;
	
	  ;% Crane3D_DevDriv_P.PIDController6_N
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 66;
	
	  ;% Crane3D_DevDriv_P.PIDController4_N
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 67;
	
	  ;% Crane3D_DevDriv_P.PIDController7_N
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 68;
	
	  ;% Crane3D_DevDriv_P.Encoder_P1_Size
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 69;
	
	  ;% Crane3D_DevDriv_P.Encoder_P1
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 71;
	
	  ;% Crane3D_DevDriv_P.Encoder_P2_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 72;
	
	  ;% Crane3D_DevDriv_P.Encoder_P2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 74;
	
	  ;% Crane3D_DevDriv_P.Encoder500PPR_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 75;
	
	  ;% Crane3D_DevDriv_P.XScale_Gain
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 76;
	
	  ;% Crane3D_DevDriv_P.YScale_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 77;
	
	  ;% Crane3D_DevDriv_P.XAngleScale_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 78;
	
	  ;% Crane3D_DevDriv_P.YAngleScale_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 79;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 80;
	
	  ;% Crane3D_DevDriv_P.Filter_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 81;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_a
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 82;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_j
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 83;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_f
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 84;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_m
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 85;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_h
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 86;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_o
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 87;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_c
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 88;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_a
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 89;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_fc
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 90;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_c
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 91;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_cx
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 92;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_or
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 93;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_a2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 94;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_ms
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 95;
	
	  ;% Crane3D_DevDriv_P.Constant_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 96;
	
	  ;% Crane3D_DevDriv_P.PWM_P1_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 97;
	
	  ;% Crane3D_DevDriv_P.PWM_P1
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 99;
	
	  ;% Crane3D_DevDriv_P.PWM_P2_Size
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 100;
	
	  ;% Crane3D_DevDriv_P.PWM_P2
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 102;
	
	  ;% Crane3D_DevDriv_P.Saturation_UpperSat
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 103;
	
	  ;% Crane3D_DevDriv_P.Saturation_LowerSat
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 104;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P1_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 105;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 107;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P2_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 108;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 110;
	
	  ;% Crane3D_DevDriv_P.LimitFlagSource_Value
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 111;
	
	  ;% Crane3D_DevDriv_P.LimitSource_Value
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 114;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P1_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 117;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P1
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 119;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P2_Size
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 120;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P2
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 122;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P1_Size
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 123;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P1
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 125;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P2_Size
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 126;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P2
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 128;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P1_Size
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 129;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 131;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P2_Size
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 132;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P2
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 134;
	
	  ;% Crane3D_DevDriv_P.PWMPrescalerSource_Value
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 135;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P1_Size
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 136;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P1
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 138;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P2_Size
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 139;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P2
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 141;
	
	  ;% Crane3D_DevDriv_P.ResetSource_Value
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 142;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P1_Size
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 147;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P1
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 149;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P2_Size
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 150;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P2
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 152;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlagSource_Value
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 153;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P1_Size
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 156;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P1
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 158;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P2_Size
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 159;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P2
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 161;
	
	  ;% Crane3D_DevDriv_P.ThermFlagSource_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 162;
	
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
    nTotSects     = 5;
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
      section.nData     = 58;
      section.data(58)  = dumData; %prealloc
      
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
	
	  ;% Crane3D_DevDriv_B.ProportionalGain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_j
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_j
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_c
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_h
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_jh
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_b
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 19;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_k
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 20;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_j
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 21;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_o
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 22;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_c
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 24;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_c
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 25;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_p
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 26;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_d
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 27;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_g
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 28;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 29;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_j0
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 30;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_p
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_cw
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 32;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_jx
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 33;
	
	  ;% Crane3D_DevDriv_B.IntegralGain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 34;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_l
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 35;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_o
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 36;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_lr
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 37;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_n
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 38;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_g
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 39;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_m
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 40;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_e
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 41;
	
	  ;% Crane3D_DevDriv_B.PWM
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 42;
	
	  ;% Crane3D_DevDriv_B.Saturation
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 45;
	
	  ;% Crane3D_DevDriv_B.LimitFlag
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 48;
	
	  ;% Crane3D_DevDriv_B.LimitFlagSource
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 51;
	
	  ;% Crane3D_DevDriv_B.LimitSource
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 54;
	
	  ;% Crane3D_DevDriv_B.SetLimit
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 57;
	
	  ;% Crane3D_DevDriv_B.LimitSwitch
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 60;
	
	  ;% Crane3D_DevDriv_B.PWMPrescaler
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 63;
	
	  ;% Crane3D_DevDriv_B.PWMPrescalerSource
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 64;
	
	  ;% Crane3D_DevDriv_B.ResetEncoder
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 65;
	
	  ;% Crane3D_DevDriv_B.ResetSource
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 70;
	
	  ;% Crane3D_DevDriv_B.ResetSwitchFlag
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 75;
	
	  ;% Crane3D_DevDriv_B.ResetSwitchFlagSource
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 78;
	
	  ;% Crane3D_DevDriv_B.ThermFlag
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 81;
	
	  ;% Crane3D_DevDriv_B.ThermFlagSource
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 84;
	
	  ;% Crane3D_DevDriv_B.x
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 87;
	
	  ;% Crane3D_DevDriv_B.y
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 88;
	
	  ;% Crane3D_DevDriv_B.Class
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 89;
	
	  ;% Crane3D_DevDriv_B.x_l
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 90;
	
	  ;% Crane3D_DevDriv_B.y_f
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 91;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_B.sf_GainSch1.C1
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_B.sf_GainSch1.C2
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_B.sf_GainSch1.C3
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane3D_DevDriv_B.sf_GainSch1.C4
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_B.sf_GainSch.C1
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_B.sf_GainSch.C2
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_B.sf_GainSch.C3
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane3D_DevDriv_B.sf_GainSch.C4
	  section.data(4).logicalSrcIdx = 65;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_B.sf_GainDesch1.Out
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_B.sf_GainDesch.Out
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    sectIdxOffset = 5;
    
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


  targMap.checksum0 = 3412237169;
  targMap.checksum1 = 210214119;
  targMap.checksum2 = 1411798281;
  targMap.checksum3 = 3613856210;

