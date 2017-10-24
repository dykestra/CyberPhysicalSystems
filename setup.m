clear variables
close all
clc
%% SimscapeCrane_MPC_start;
load('Params_Simscape.mat');
load('SSmodelParams.mat');
%% Load the dynamics matrices using a solution from last assignment
Ts=1/20;
T=10;
x0=[xRange(2)/2 0 yRange(2)/2 0 0 0 0 0]'; % starting offset

%% Refine frictiopn model
TxVisc = 49.1750;
TxCoulomb = 2.5;
TxBreak = 0;
xZero = 0;

yZero = 0;
TyBreak = 0;
TyVisc = 47.5650;
TyCoulomb = 1.8;

% TzVisc = 92.5; % considering the mass added
TzVisc = 342; %Z friciton without contant frictional force added by the
% mass
