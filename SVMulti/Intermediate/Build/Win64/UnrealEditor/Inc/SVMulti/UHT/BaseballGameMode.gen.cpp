// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SVMulti/BaseballGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseballGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameMode();
SVMULTI_API UClass* Z_Construct_UClass_ABaseballGameMode();
SVMULTI_API UClass* Z_Construct_UClass_ABaseballGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SVMulti();
// End Cross Module References

// Begin Class ABaseballGameMode
void ABaseballGameMode::StaticRegisterNativesABaseballGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABaseballGameMode);
UClass* Z_Construct_UClass_ABaseballGameMode_NoRegister()
{
	return ABaseballGameMode::StaticClass();
}
struct Z_Construct_UClass_ABaseballGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BaseballGameMode.h" },
		{ "ModuleRelativePath", "BaseballGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnTimeLimit_MetaData[] = {
		{ "ModuleRelativePath", "BaseballGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnTimeLimit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABaseballGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABaseballGameMode_Statics::NewProp_TurnTimeLimit = { "TurnTimeLimit", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABaseballGameMode, TurnTimeLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnTimeLimit_MetaData), NewProp_TurnTimeLimit_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABaseballGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABaseballGameMode_Statics::NewProp_TurnTimeLimit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABaseballGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_SVMulti,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABaseballGameMode_Statics::ClassParams = {
	&ABaseballGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABaseballGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABaseballGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ABaseballGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABaseballGameMode()
{
	if (!Z_Registration_Info_UClass_ABaseballGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABaseballGameMode.OuterSingleton, Z_Construct_UClass_ABaseballGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABaseballGameMode.OuterSingleton;
}
template<> SVMULTI_API UClass* StaticClass<ABaseballGameMode>()
{
	return ABaseballGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseballGameMode);
ABaseballGameMode::~ABaseballGameMode() {}
// End Class ABaseballGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABaseballGameMode, ABaseballGameMode::StaticClass, TEXT("ABaseballGameMode"), &Z_Registration_Info_UClass_ABaseballGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABaseballGameMode), 1080601075U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameMode_h_2188827461(TEXT("/Script/SVMulti"),
	Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
