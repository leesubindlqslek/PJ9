// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SVMulti/BaseballPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseballPlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
SVMULTI_API UClass* Z_Construct_UClass_ABaseballPlayerController();
SVMULTI_API UClass* Z_Construct_UClass_ABaseballPlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_SVMulti();
// End Cross Module References

// Begin Class ABaseballPlayerController Function ClientOnGameLose
static const FName NAME_ABaseballPlayerController_ClientOnGameLose = FName(TEXT("ClientOnGameLose"));
void ABaseballPlayerController::ClientOnGameLose()
{
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientOnGameLose);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientOnGameLose", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientOnGameLose)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnGameLose_Implementation();
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientOnGameLose

// Begin Class ABaseballPlayerController Function ClientOnGameWin
static const FName NAME_ABaseballPlayerController_ClientOnGameWin = FName(TEXT("ClientOnGameWin"));
void ABaseballPlayerController::ClientOnGameWin()
{
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientOnGameWin);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientOnGameWin", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientOnGameWin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnGameWin_Implementation();
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientOnGameWin

// Begin Class ABaseballPlayerController Function ClientReceiveResult
struct BaseballPlayerController_eventClientReceiveResult_Parms
{
	FString InputNumber;
	int32 Strike;
	int32 Ball;
};
static const FName NAME_ABaseballPlayerController_ClientReceiveResult = FName(TEXT("ClientReceiveResult"));
void ABaseballPlayerController::ClientReceiveResult(const FString& InputNumber, int32 Strike, int32 Ball)
{
	BaseballPlayerController_eventClientReceiveResult_Parms Parms;
	Parms.InputNumber=InputNumber;
	Parms.Strike=Strike;
	Parms.Ball=Ball;
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientReceiveResult);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InputNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Strike;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Ball;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::NewProp_InputNumber = { "InputNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseballPlayerController_eventClientReceiveResult_Parms, InputNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputNumber_MetaData), NewProp_InputNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::NewProp_Strike = { "Strike", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseballPlayerController_eventClientReceiveResult_Parms, Strike), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::NewProp_Ball = { "Ball", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseballPlayerController_eventClientReceiveResult_Parms, Ball), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::NewProp_InputNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::NewProp_Strike,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::NewProp_Ball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientReceiveResult", nullptr, nullptr, Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::PropPointers), sizeof(BaseballPlayerController_eventClientReceiveResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::Function_MetaDataParams) };
static_assert(sizeof(BaseballPlayerController_eventClientReceiveResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientReceiveResult)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InputNumber);
	P_GET_PROPERTY(FIntProperty,Z_Param_Strike);
	P_GET_PROPERTY(FIntProperty,Z_Param_Ball);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientReceiveResult_Implementation(Z_Param_InputNumber,Z_Param_Strike,Z_Param_Ball);
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientReceiveResult

// Begin Class ABaseballPlayerController Function ClientResettingbuttons
static const FName NAME_ABaseballPlayerController_ClientResettingbuttons = FName(TEXT("ClientResettingbuttons"));
void ABaseballPlayerController::ClientResettingbuttons()
{
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientResettingbuttons);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientResettingbuttons", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientResettingbuttons)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientResettingbuttons_Implementation();
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientResettingbuttons

// Begin Class ABaseballPlayerController Function ClientSetMyTurn
static const FName NAME_ABaseballPlayerController_ClientSetMyTurn = FName(TEXT("ClientSetMyTurn"));
void ABaseballPlayerController::ClientSetMyTurn()
{
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientSetMyTurn);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n//\xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd\xc6\xae rpc . / \xef\xbf\xbd\xd5\xbf\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xb1\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb0\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n\xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd\xc6\xae rpc . / \xef\xbf\xbd\xd5\xbf\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xb1\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientSetMyTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientSetMyTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientSetMyTurn_Implementation();
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientSetMyTurn

// Begin Class ABaseballPlayerController Function ClientSetOtherTurn
static const FName NAME_ABaseballPlayerController_ClientSetOtherTurn = FName(TEXT("ClientSetOtherTurn"));
void ABaseballPlayerController::ClientSetOtherTurn()
{
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientSetOtherTurn);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientSetOtherTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientSetOtherTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientSetOtherTurn_Implementation();
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientSetOtherTurn

// Begin Class ABaseballPlayerController Function ClientShowMessage
struct BaseballPlayerController_eventClientShowMessage_Parms
{
	FString Message;
};
static const FName NAME_ABaseballPlayerController_ClientShowMessage = FName(TEXT("ClientShowMessage"));
void ABaseballPlayerController::ClientShowMessage(const FString& Message)
{
	BaseballPlayerController_eventClientShowMessage_Parms Parms;
	Parms.Message=Message;
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientShowMessage);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseballPlayerController_eventClientShowMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientShowMessage", nullptr, nullptr, Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::PropPointers), sizeof(BaseballPlayerController_eventClientShowMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::Function_MetaDataParams) };
static_assert(sizeof(BaseballPlayerController_eventClientShowMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientShowMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientShowMessage_Implementation(Z_Param_Message);
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientShowMessage

// Begin Class ABaseballPlayerController Function ClientUpdateTurnTime
struct BaseballPlayerController_eventClientUpdateTurnTime_Parms
{
	float RemainingTime;
};
static const FName NAME_ABaseballPlayerController_ClientUpdateTurnTime = FName(TEXT("ClientUpdateTurnTime"));
void ABaseballPlayerController::ClientUpdateTurnTime(float RemainingTime)
{
	BaseballPlayerController_eventClientUpdateTurnTime_Parms Parms;
	Parms.RemainingTime=RemainingTime;
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ClientUpdateTurnTime);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RemainingTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::NewProp_RemainingTime = { "RemainingTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseballPlayerController_eventClientUpdateTurnTime_Parms, RemainingTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::NewProp_RemainingTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ClientUpdateTurnTime", nullptr, nullptr, Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::PropPointers), sizeof(BaseballPlayerController_eventClientUpdateTurnTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(BaseballPlayerController_eventClientUpdateTurnTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execClientUpdateTurnTime)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_RemainingTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientUpdateTurnTime_Implementation(Z_Param_RemainingTime);
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ClientUpdateTurnTime

// Begin Class ABaseballPlayerController Function ServerRequestRestart
static const FName NAME_ABaseballPlayerController_ServerRequestRestart = FName(TEXT("ServerRequestRestart"));
void ABaseballPlayerController::ServerRequestRestart()
{
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ServerRequestRestart);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ServerRequestRestart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execServerRequestRestart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestRestart_Implementation();
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ServerRequestRestart

// Begin Class ABaseballPlayerController Function ServerSendReadyValue
struct BaseballPlayerController_eventServerSendReadyValue_Parms
{
	bool IsReady;
};
static const FName NAME_ABaseballPlayerController_ServerSendReadyValue = FName(TEXT("ServerSendReadyValue"));
void ABaseballPlayerController::ServerSendReadyValue(bool IsReady)
{
	BaseballPlayerController_eventServerSendReadyValue_Parms Parms;
	Parms.IsReady=IsReady ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ServerSendReadyValue);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_IsReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady_SetBit(void* Obj)
{
	((BaseballPlayerController_eventServerSendReadyValue_Parms*)Obj)->IsReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady = { "IsReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BaseballPlayerController_eventServerSendReadyValue_Parms), &Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ServerSendReadyValue", nullptr, nullptr, Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::PropPointers), sizeof(BaseballPlayerController_eventServerSendReadyValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00280CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(BaseballPlayerController_eventServerSendReadyValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execServerSendReadyValue)
{
	P_GET_UBOOL(Z_Param_IsReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSendReadyValue_Implementation(Z_Param_IsReady);
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ServerSendReadyValue

// Begin Class ABaseballPlayerController Function ServerSubmitGuess
struct BaseballPlayerController_eventServerSubmitGuess_Parms
{
	FString InputNumber;
};
static const FName NAME_ABaseballPlayerController_ServerSubmitGuess = FName(TEXT("ServerSubmitGuess"));
void ABaseballPlayerController::ServerSubmitGuess(const FString& InputNumber)
{
	BaseballPlayerController_eventServerSubmitGuess_Parms Parms;
	Parms.InputNumber=InputNumber;
	UFunction* Func = FindFunctionChecked(NAME_ABaseballPlayerController_ServerSubmitGuess);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd rpc\n" },
#endif
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd rpc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InputNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::NewProp_InputNumber = { "InputNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BaseballPlayerController_eventServerSubmitGuess_Parms, InputNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputNumber_MetaData), NewProp_InputNumber_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::NewProp_InputNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballPlayerController, nullptr, "ServerSubmitGuess", nullptr, nullptr, Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::PropPointers), sizeof(BaseballPlayerController_eventServerSubmitGuess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::Function_MetaDataParams) };
static_assert(sizeof(BaseballPlayerController_eventServerSubmitGuess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballPlayerController::execServerSubmitGuess)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InputNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSubmitGuess_Implementation(Z_Param_InputNumber);
	P_NATIVE_END;
}
// End Class ABaseballPlayerController Function ServerSubmitGuess

// Begin Class ABaseballPlayerController
void ABaseballPlayerController::StaticRegisterNativesABaseballPlayerController()
{
	UClass* Class = ABaseballPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnGameLose", &ABaseballPlayerController::execClientOnGameLose },
		{ "ClientOnGameWin", &ABaseballPlayerController::execClientOnGameWin },
		{ "ClientReceiveResult", &ABaseballPlayerController::execClientReceiveResult },
		{ "ClientResettingbuttons", &ABaseballPlayerController::execClientResettingbuttons },
		{ "ClientSetMyTurn", &ABaseballPlayerController::execClientSetMyTurn },
		{ "ClientSetOtherTurn", &ABaseballPlayerController::execClientSetOtherTurn },
		{ "ClientShowMessage", &ABaseballPlayerController::execClientShowMessage },
		{ "ClientUpdateTurnTime", &ABaseballPlayerController::execClientUpdateTurnTime },
		{ "ServerRequestRestart", &ABaseballPlayerController::execServerRequestRestart },
		{ "ServerSendReadyValue", &ABaseballPlayerController::execServerSendReadyValue },
		{ "ServerSubmitGuess", &ABaseballPlayerController::execServerSubmitGuess },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseballPlayerController);
UClass* Z_Construct_UClass_ABaseballPlayerController_NoRegister()
{
	return ABaseballPlayerController::StaticClass();
}
struct Z_Construct_UClass_ABaseballPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "BaseballPlayerController.h" },
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xd1\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc4\xab\xef\xbf\xbd\xd7\xb0\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd HUD\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd. \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe2\xbf\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xd1\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc4\xab\xef\xbf\xbd\xd7\xb0\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd HUD\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd. \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe2\xbf\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetInstance_MetaData[] = {
		{ "Category", "HUD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BaseballPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDWidgetInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameLose, "ClientOnGameLose" }, // 3380947198
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientOnGameWin, "ClientOnGameWin" }, // 1566939931
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientReceiveResult, "ClientReceiveResult" }, // 2950494736
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientResettingbuttons, "ClientResettingbuttons" }, // 1533748220
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientSetMyTurn, "ClientSetMyTurn" }, // 3235284698
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientSetOtherTurn, "ClientSetOtherTurn" }, // 1976929311
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientShowMessage, "ClientShowMessage" }, // 1102703470
		{ &Z_Construct_UFunction_ABaseballPlayerController_ClientUpdateTurnTime, "ClientUpdateTurnTime" }, // 1911696713
		{ &Z_Construct_UFunction_ABaseballPlayerController_ServerRequestRestart, "ServerRequestRestart" }, // 1762444233
		{ &Z_Construct_UFunction_ABaseballPlayerController_ServerSendReadyValue, "ServerSendReadyValue" }, // 1667933257
		{ &Z_Construct_UFunction_ABaseballPlayerController_ServerSubmitGuess, "ServerSubmitGuess" }, // 3667336950
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseballPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABaseballPlayerController_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseballPlayerController, HUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetClass_MetaData), NewProp_HUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseballPlayerController_Statics::NewProp_HUDWidgetInstance = { "HUDWidgetInstance", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseballPlayerController, HUDWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetInstance_MetaData), NewProp_HUDWidgetInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseballPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseballPlayerController_Statics::NewProp_HUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseballPlayerController_Statics::NewProp_HUDWidgetInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABaseballPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_SVMulti,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseballPlayerController_Statics::ClassParams = {
	&ABaseballPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABaseballPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseballPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseballPlayerController()
{
	if (!Z_Registration_Info_UClass_ABaseballPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseballPlayerController.OuterSingleton, Z_Construct_UClass_ABaseballPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseballPlayerController.OuterSingleton;
}
template<> SVMULTI_API UClass* StaticClass<ABaseballPlayerController>()
{
	return ABaseballPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseballPlayerController);
ABaseballPlayerController::~ABaseballPlayerController() {}
// End Class ABaseballPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseballPlayerController, ABaseballPlayerController::StaticClass, TEXT("ABaseballPlayerController"), &Z_Registration_Info_UClass_ABaseballPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseballPlayerController), 3235706921U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_1323311788(TEXT("/Script/SVMulti"),
	Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
