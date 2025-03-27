
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MySvCPPLib.generated.h"


UCLASS()
class SVMULTI_API UMySvCPPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
	
public:
	UFUNCTION(BlueprintCallable, Category = "MySvCPPLib")
	static FString GetMyFirstCPP(); //������ ���� �̸� ���� ���� 
};
