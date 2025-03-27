// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BaseballPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SVMULTI_BaseballPlayerController_generated_h
#error "BaseballPlayerController.generated.h already included, missing '#pragma once' in BaseballPlayerController.h"
#endif
#define SVMULTI_BaseballPlayerController_generated_h

#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientResettingbuttons_Implementation(); \
	virtual void ServerRequestRestart_Implementation(); \
	virtual void ClientOnGameLose_Implementation(); \
	virtual void ClientOnGameWin_Implementation(); \
	virtual void ClientUpdateTurnTime_Implementation(float RemainingTime); \
	virtual void ClientShowMessage_Implementation(const FString& Message); \
	virtual void ClientReceiveResult_Implementation(const FString& InputNumber, int32 Strike, int32 Ball); \
	virtual void ServerSubmitGuess_Implementation(const FString& InputNumber); \
	virtual void ClientSetOtherTurn_Implementation(); \
	virtual void ClientSetMyTurn_Implementation(); \
	virtual void ServerSendReadyValue_Implementation(bool IsReady); \
	DECLARE_FUNCTION(execClientResettingbuttons); \
	DECLARE_FUNCTION(execServerRequestRestart); \
	DECLARE_FUNCTION(execClientOnGameLose); \
	DECLARE_FUNCTION(execClientOnGameWin); \
	DECLARE_FUNCTION(execClientUpdateTurnTime); \
	DECLARE_FUNCTION(execClientShowMessage); \
	DECLARE_FUNCTION(execClientReceiveResult); \
	DECLARE_FUNCTION(execServerSubmitGuess); \
	DECLARE_FUNCTION(execClientSetOtherTurn); \
	DECLARE_FUNCTION(execClientSetMyTurn); \
	DECLARE_FUNCTION(execServerSendReadyValue);


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_CALLBACK_WRAPPERS
#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseballPlayerController(); \
	friend struct Z_Construct_UClass_ABaseballPlayerController_Statics; \
public: \
	DECLARE_CLASS(ABaseballPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SVMulti"), NO_API) \
	DECLARE_SERIALIZER(ABaseballPlayerController)


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ABaseballPlayerController(ABaseballPlayerController&&); \
	ABaseballPlayerController(const ABaseballPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseballPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseballPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseballPlayerController) \
	NO_API virtual ~ABaseballPlayerController();


#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_8_PROLOG
#define FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_CALLBACK_WRAPPERS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_INCLASS_NO_PURE_DECLS \
	FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SVMULTI_API UClass* StaticClass<class ABaseballPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Sparta_Project_Multiplayer_SVMulti_Source_SVMulti_BaseballPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
