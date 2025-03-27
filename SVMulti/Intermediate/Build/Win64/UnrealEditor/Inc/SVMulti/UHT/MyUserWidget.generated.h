// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyUserWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SVMULTI_MyUserWidget_generated_h
#error "MyUserWidget.generated.h already included, missing '#pragma once' in MyUserWidget.h"
#endif
#define SVMULTI_MyUserWidget_generated_h

#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRestartButtonClicked); \
	DECLARE_FUNCTION(execOnGuessButtonClicked); \
	DECLARE_FUNCTION(execOnResetButtonClicked); \
	DECLARE_FUNCTION(execOnBackspceButtonClicked); \
	DECLARE_FUNCTION(execOnNumberButtonClicked9); \
	DECLARE_FUNCTION(execOnNumberButtonClicked8); \
	DECLARE_FUNCTION(execOnNumberButtonClicked7); \
	DECLARE_FUNCTION(execOnNumberButtonClicked6); \
	DECLARE_FUNCTION(execOnNumberButtonClicked5); \
	DECLARE_FUNCTION(execOnNumberButtonClicked4); \
	DECLARE_FUNCTION(execOnNumberButtonClicked3); \
	DECLARE_FUNCTION(execOnNumberButtonClicked2); \
	DECLARE_FUNCTION(execOnNumberButtonClicked1);


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyUserWidget(); \
	friend struct Z_Construct_UClass_UMyUserWidget_Statics; \
public: \
	DECLARE_CLASS(UMyUserWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SVMulti"), NO_API) \
	DECLARE_SERIALIZER(UMyUserWidget)


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyUserWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMyUserWidget(UMyUserWidget&&); \
	UMyUserWidget(const UMyUserWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyUserWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyUserWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyUserWidget) \
	NO_API virtual ~UMyUserWidget();


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_9_PROLOG
#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_INCLASS_NO_PURE_DECLS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SVMULTI_API UClass* StaticClass<class UMyUserWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_MyUserWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
