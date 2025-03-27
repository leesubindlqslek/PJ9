// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SVMulti/BaseballGameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseballGameState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameState();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
SVMULTI_API UClass* Z_Construct_UClass_ABaseballGameState();
SVMULTI_API UClass* Z_Construct_UClass_ABaseballGameState_NoRegister();
UPackage* Z_Construct_UPackage__Script_SVMulti();
// End Cross Module References

// Begin Class ABaseballGameState Function OnRep_CurrentTurnPlayer
struct Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb8\xef\xbf\xbd OnRep_CurrentTurnPlayer\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc8\xa3\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc8\xb4\xef\xbf\xbd.\n" },
#endif
		{ "ModuleRelativePath", "BaseballGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xb8\xef\xbf\xbd OnRep_CurrentTurnPlayer\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc8\xa3\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc8\xb4\xef\xbf\xbd." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseballGameState, nullptr, "OnRep_CurrentTurnPlayer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABaseballGameState::execOnRep_CurrentTurnPlayer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_CurrentTurnPlayer();
	P_NATIVE_END;
}
// End Class ABaseballGameState Function OnRep_CurrentTurnPlayer

// Begin Class ABaseballGameState
void ABaseballGameState::StaticRegisterNativesABaseballGameState()
{
	UClass* Class = ABaseballGameState::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnRep_CurrentTurnPlayer", &ABaseballGameState::execOnRep_CurrentTurnPlayer },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseballGameState);
UClass* Z_Construct_UClass_ABaseballGameState_NoRegister()
{
	return ABaseballGameState::StaticClass();
}
struct Z_Construct_UClass_ABaseballGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BaseballGameState.h" },
		{ "ModuleRelativePath", "BaseballGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTurnPlayer_MetaData[] = {
		{ "ModuleRelativePath", "BaseballGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTurnTimeRemaining_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd (UI \xc7\xa5\xef\xbf\xbd\xc3\xbf\xef\xbf\xbd)\n//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb5\xc7\xb8\xef\xbf\xbd \xef\xbf\xbd\xda\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcb\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "BaseballGameState.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xb0\xef\xbf\xbd (UI \xc7\xa5\xef\xbf\xbd\xc3\xbf\xef\xbf\xbd)\n\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xb5\xc7\xb8\xef\xbf\xbd \xef\xbf\xbd\xda\xb5\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcb\xb7\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTurnPlayer;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTurnTimeRemaining;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABaseballGameState_OnRep_CurrentTurnPlayer, "OnRep_CurrentTurnPlayer" }, // 834980011
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseballGameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABaseballGameState_Statics::NewProp_CurrentTurnPlayer = { "CurrentTurnPlayer", "OnRep_CurrentTurnPlayer", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseballGameState, CurrentTurnPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTurnPlayer_MetaData), NewProp_CurrentTurnPlayer_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABaseballGameState_Statics::NewProp_CurrentTurnTimeRemaining = { "CurrentTurnTimeRemaining", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseballGameState, CurrentTurnTimeRemaining), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTurnTimeRemaining_MetaData), NewProp_CurrentTurnTimeRemaining_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseballGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseballGameState_Statics::NewProp_CurrentTurnPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseballGameState_Statics::NewProp_CurrentTurnTimeRemaining,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABaseballGameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameState,
	(UObject* (*)())Z_Construct_UPackage__Script_SVMulti,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseballGameState_Statics::ClassParams = {
	&ABaseballGameState::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABaseballGameState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameState_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseballGameState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseballGameState()
{
	if (!Z_Registration_Info_UClass_ABaseballGameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseballGameState.OuterSingleton, Z_Construct_UClass_ABaseballGameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseballGameState.OuterSingleton;
}
template<> SVMULTI_API UClass* StaticClass<ABaseballGameState>()
{
	return ABaseballGameState::StaticClass();
}
void ABaseballGameState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_CurrentTurnPlayer(TEXT("CurrentTurnPlayer"));
	static const FName Name_CurrentTurnTimeRemaining(TEXT("CurrentTurnTimeRemaining"));
	const bool bIsValid = true
		&& Name_CurrentTurnPlayer == ClassReps[(int32)ENetFields_Private::CurrentTurnPlayer].Property->GetFName()
		&& Name_CurrentTurnTimeRemaining == ClassReps[(int32)ENetFields_Private::CurrentTurnTimeRemaining].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ABaseballGameState"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseballGameState);
ABaseballGameState::~ABaseballGameState() {}
// End Class ABaseballGameState

// Begin Registration
struct Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseballGameState, ABaseballGameState::StaticClass, TEXT("ABaseballGameState"), &Z_Registration_Info_UClass_ABaseballGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseballGameState), 1982554180U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameState_h_729435742(TEXT("/Script/SVMulti"),
	Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
