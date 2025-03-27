// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SVMulti/MySvCPPLib.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySvCPPLib() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
SVMULTI_API UClass* Z_Construct_UClass_UMySvCPPLib();
SVMULTI_API UClass* Z_Construct_UClass_UMySvCPPLib_NoRegister();
UPackage* Z_Construct_UPackage__Script_SVMulti();
// End Cross Module References

// Begin Class UMySvCPPLib Function GetMyFirstCPP
struct Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics
{
	struct MySvCPPLib_eventGetMyFirstCPP_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MySvCPPLib" },
		{ "ModuleRelativePath", "MySvCPPLib.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MySvCPPLib_eventGetMyFirstCPP_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySvCPPLib, nullptr, "GetMyFirstCPP", nullptr, nullptr, Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::MySvCPPLib_eventGetMyFirstCPP_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::MySvCPPLib_eventGetMyFirstCPP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMySvCPPLib::execGetMyFirstCPP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UMySvCPPLib::GetMyFirstCPP();
	P_NATIVE_END;
}
// End Class UMySvCPPLib Function GetMyFirstCPP

// Begin Class UMySvCPPLib
void UMySvCPPLib::StaticRegisterNativesUMySvCPPLib()
{
	UClass* Class = UMySvCPPLib::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetMyFirstCPP", &UMySvCPPLib::execGetMyFirstCPP },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMySvCPPLib);
UClass* Z_Construct_UClass_UMySvCPPLib_NoRegister()
{
	return UMySvCPPLib::StaticClass();
}
struct Z_Construct_UClass_UMySvCPPLib_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MySvCPPLib.h" },
		{ "ModuleRelativePath", "MySvCPPLib.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMySvCPPLib_GetMyFirstCPP, "GetMyFirstCPP" }, // 3910814215
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMySvCPPLib>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMySvCPPLib_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_SVMulti,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMySvCPPLib_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMySvCPPLib_Statics::ClassParams = {
	&UMySvCPPLib::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMySvCPPLib_Statics::Class_MetaDataParams), Z_Construct_UClass_UMySvCPPLib_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMySvCPPLib()
{
	if (!Z_Registration_Info_UClass_UMySvCPPLib.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMySvCPPLib.OuterSingleton, Z_Construct_UClass_UMySvCPPLib_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMySvCPPLib.OuterSingleton;
}
template<> SVMULTI_API UClass* StaticClass<UMySvCPPLib>()
{
	return UMySvCPPLib::StaticClass();
}
UMySvCPPLib::UMySvCPPLib(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMySvCPPLib);
UMySvCPPLib::~UMySvCPPLib() {}
// End Class UMySvCPPLib

// Begin Registration
struct Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMySvCPPLib, UMySvCPPLib::StaticClass, TEXT("UMySvCPPLib"), &Z_Registration_Info_UClass_UMySvCPPLib, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMySvCPPLib), 2318649628U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_1506999675(TEXT("/Script/SVMulti"),
	Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
