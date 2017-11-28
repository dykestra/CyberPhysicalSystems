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
      
	  ;% Crane3D_DevDriv_P.waypoints
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_P.PIDController_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 108;
	
	  ;% Crane3D_DevDriv_P.PIDController2_D
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 109;
	
	  ;% Crane3D_DevDriv_P.PIDController_I
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 110;
	
	  ;% Crane3D_DevDriv_P.PIDController2_I
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 111;
	
	  ;% Crane3D_DevDriv_P.PIDController_LowerSaturationLimit
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 112;
	
	  ;% Crane3D_DevDriv_P.PIDController2_LowerSaturationLimit
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 113;
	
	  ;% Crane3D_DevDriv_P.PIDController_N
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 114;
	
	  ;% Crane3D_DevDriv_P.PIDController2_N
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 115;
	
	  ;% Crane3D_DevDriv_P.PIDController_P
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 116;
	
	  ;% Crane3D_DevDriv_P.PIDController2_P
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 117;
	
	  ;% Crane3D_DevDriv_P.PIDController_UpperSaturationLimit
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 118;
	
	  ;% Crane3D_DevDriv_P.PIDController2_UpperSaturationLimit
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 119;
	
	  ;% Crane3D_DevDriv_P.Encoder_P1_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 120;
	
	  ;% Crane3D_DevDriv_P.Encoder_P1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 122;
	
	  ;% Crane3D_DevDriv_P.Encoder_P2_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 123;
	
	  ;% Crane3D_DevDriv_P.Encoder_P2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 125;
	
	  ;% Crane3D_DevDriv_P.Encoder500PPR_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 126;
	
	  ;% Crane3D_DevDriv_P.XScale_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 127;
	
	  ;% Crane3D_DevDriv_P.YScale_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 128;
	
	  ;% Crane3D_DevDriv_P.XAngleScale_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 129;
	
	  ;% Crane3D_DevDriv_P.YAngleScale_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 130;
	
	  ;% Crane3D_DevDriv_P.Filter_IC
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 131;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 132;
	
	  ;% Crane3D_DevDriv_P.Filter_IC_k
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 133;
	
	  ;% Crane3D_DevDriv_P.Integrator_IC_j
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 134;
	
	  ;% Crane3D_DevDriv_P.Constant_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 135;
	
	  ;% Crane3D_DevDriv_P.PWM_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 136;
	
	  ;% Crane3D_DevDriv_P.PWM_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 138;
	
	  ;% Crane3D_DevDriv_P.PWM_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 139;
	
	  ;% Crane3D_DevDriv_P.PWM_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 141;
	
	  ;% Crane3D_DevDriv_P.Saturation_UpperSat
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 142;
	
	  ;% Crane3D_DevDriv_P.Saturation_LowerSat
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 143;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P1_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 144;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 146;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P2_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 147;
	
	  ;% Crane3D_DevDriv_P.LimitFlag_P2
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 149;
	
	  ;% Crane3D_DevDriv_P.LimitFlagSource_Value
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 150;
	
	  ;% Crane3D_DevDriv_P.LimitSource_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 153;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P1_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 156;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 158;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P2_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 159;
	
	  ;% Crane3D_DevDriv_P.SetLimit_P2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 161;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P1_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 162;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 164;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P2_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 165;
	
	  ;% Crane3D_DevDriv_P.LimitSwitch_P2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 167;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P1_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 168;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 170;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P2_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 171;
	
	  ;% Crane3D_DevDriv_P.PWMPrescaler_P2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 173;
	
	  ;% Crane3D_DevDriv_P.PWMPrescalerSource_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 174;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P1_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 175;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P1
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 177;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P2_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 178;
	
	  ;% Crane3D_DevDriv_P.ResetEncoder_P2
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 180;
	
	  ;% Crane3D_DevDriv_P.ResetSource_Value
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 181;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P1_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 186;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P1
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 188;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P2_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 189;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlag_P2
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 191;
	
	  ;% Crane3D_DevDriv_P.ResetSwitchFlagSource_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 192;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P1_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 195;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P1
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 197;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P2_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 198;
	
	  ;% Crane3D_DevDriv_P.ThermFlag_P2
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 200;
	
	  ;% Crane3D_DevDriv_P.ThermFlagSource_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 201;
	
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
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_B.Encoder
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_B.XScale
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% Crane3D_DevDriv_B.YScale
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Crane3D_DevDriv_B.XAngleScale
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Crane3D_DevDriv_B.YAngleScale
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 10;
	
	  ;% Crane3D_DevDriv_B.IntegralGain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% Crane3D_DevDriv_B.DerivativeGain_o
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% Crane3D_DevDriv_B.FilterCoefficient_m
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 14;
	
	  ;% Crane3D_DevDriv_B.IntegralGain_b
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% Crane3D_DevDriv_B.ProportionalGain_e
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 16;
	
	  ;% Crane3D_DevDriv_B.PWM
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 17;
	
	  ;% Crane3D_DevDriv_B.Saturation
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 20;
	
	  ;% Crane3D_DevDriv_B.LimitFlag
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% Crane3D_DevDriv_B.LimitFlagSource
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% Crane3D_DevDriv_B.LimitSource
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% Crane3D_DevDriv_B.SetLimit
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 32;
	
	  ;% Crane3D_DevDriv_B.LimitSwitch
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 35;
	
	  ;% Crane3D_DevDriv_B.PWMPrescaler
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 38;
	
	  ;% Crane3D_DevDriv_B.PWMPrescalerSource
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 39;
	
	  ;% Crane3D_DevDriv_B.ResetEncoder
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 40;
	
	  ;% Crane3D_DevDriv_B.ResetSource
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 45;
	
	  ;% Crane3D_DevDriv_B.ResetSwitchFlag
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 50;
	
	  ;% Crane3D_DevDriv_B.ResetSwitchFlagSource
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 53;
	
	  ;% Crane3D_DevDriv_B.ThermFlag
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 56;
	
	  ;% Crane3D_DevDriv_B.ThermFlagSource
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 59;
	
	  ;% Crane3D_DevDriv_B.Clock
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 62;
	
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
    nTotSects     = 1;
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
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Crane3D_DevDriv_DW.anglex_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane3D_DevDriv_DW.angley_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane3D_DevDriv_DW.xpos_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane3D_DevDriv_DW.ypos_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Crane3D_DevDriv_DW.ToWorkspace4_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
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


  targMap.checksum0 = 1187067322;
  targMap.checksum1 = 4289955774;
  targMap.checksum2 = 3746908893;
  targMap.checksum3 = 235789616;

