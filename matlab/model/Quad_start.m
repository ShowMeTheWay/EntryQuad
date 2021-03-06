clc;clear all; close all;

%% Config path

addpath(genpath('..\..\matlab'));

%% controller output
SET_functionValue = mpt.Signal;
SET_functionValue.RTWInfo.StorageClass = 'Custom';
SET_functionValue.RTWInfo.Alias = '';
SET_functionValue.RTWInfo.CustomStorageClass = 'GetSet';
SET_functionValue.RTWInfo.CustomAttributes.HeaderFile = 'adaptation.h';
SET_functionValue.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
SET_functionValue.RTWInfo.CustomAttributes.SetFunction = 'ControllerSendCommand';
SET_functionValue.Description = '';
SET_functionValue.DataType = 'uint8';
SET_functionValue.Min = -Inf;
SET_functionValue.Max = Inf;
SET_functionValue.DocUnits = '';
SET_functionValue.Dimensions = 4;
SET_functionValue.DimensionsMode = 'auto';
SET_functionValue.Complexity = 'auto';
SET_functionValue.SampleTime = -1;
SET_functionValue.SamplingMode = 'auto';
SET_functionValue.InitialValue = '';

%% controller input
GET_functionValue = mpt.Signal;
GET_functionValue.RTWInfo.StorageClass = 'Custom';
GET_functionValue.RTWInfo.Alias = '';
GET_functionValue.RTWInfo.CustomStorageClass = 'GetSet';
GET_functionValue.RTWInfo.CustomAttributes.HeaderFile = 'adaptation.h';
GET_functionValue.RTWInfo.CustomAttributes.GetFunction = 'ControllerReceiveFeedback';
GET_functionValue.RTWInfo.CustomAttributes.SetFunction = 'Set_vNotUsed';
GET_functionValue.Description = '';
GET_functionValue.DataType = 'uint8';
GET_functionValue.Min = -Inf;
GET_functionValue.Max = Inf;
GET_functionValue.DocUnits = '';
GET_functionValue.Dimensions = 12;
GET_functionValue.DimensionsMode = 'auto';
GET_functionValue.Complexity = 'auto';
GET_functionValue.SampleTime = -1;
GET_functionValue.SamplingMode = 'auto';
GET_functionValue.InitialValue = '';

%% set PWM
SET_PWMValue = mpt.Signal;
SET_PWMValue.RTWInfo.StorageClass = 'Custom';
SET_PWMValue.RTWInfo.Alias = '';
SET_PWMValue.RTWInfo.CustomStorageClass = 'GetSet';
SET_PWMValue.RTWInfo.CustomAttributes.HeaderFile = 'adaptation.h';
SET_PWMValue.RTWInfo.CustomAttributes.GetFunction = 'Get_vNotUsed';
SET_PWMValue.RTWInfo.CustomAttributes.SetFunction = 'user_pwm_setvalue';
SET_PWMValue.Description = '';
SET_PWMValue.DataType = 'uint16';
SET_PWMValue.Min = -Inf;
SET_PWMValue.Max = Inf;
SET_PWMValue.DocUnits = '';
SET_PWMValue.Dimensions = -1;
SET_PWMValue.DimensionsMode = 'auto';
SET_PWMValue.Complexity = 'auto';
SET_PWMValue.SampleTime = -1;
SET_PWMValue.SamplingMode = 'auto';
SET_PWMValue.InitialValue = '';

%% input for PWM
GET_PWMValue = mpt.Parameter;
GET_PWMValue.DataType = 'uint16';
GET_PWMValue.DocUnits='';
GET_PWMValue.Value=[1 2 3 4 5 6 7 8 9];