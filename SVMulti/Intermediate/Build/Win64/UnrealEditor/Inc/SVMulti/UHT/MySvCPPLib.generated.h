// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MySvCPPLib.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SVMULTI_MySvCPPLib_generated_h
#error "MySvCPPLib.generated.h already included, missing '#pragma once' in MySvCPPLib.h"
#endif
#define SVMULTI_MySvCPPLib_generated_h

#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetMyFirstCPP);


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMySvCPPLib(); \
	friend struct Z_Construct_UClass_UMySvCPPLib_Statics; \
public: \
	DECLARE_CLASS(UMySvCPPLib, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SVMulti"), NO_API) \
	DECLARE_SERIALIZER(UMySvCPPLib)


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMySvCPPLib(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMySvCPPLib(UMySvCPPLib&&); \
	UMySvCPPLib(const UMySvCPPLib&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMySvCPPLib); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMySvCPPLib); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMySvCPPLib) \
	NO_API virtual ~UMySvCPPLib();


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_9_PROLOG
#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_INCLASS_NO_PURE_DECLS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SVMULTI_API UClass* StaticClass<class UMySvCPPLib>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MySvCPPLib_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
