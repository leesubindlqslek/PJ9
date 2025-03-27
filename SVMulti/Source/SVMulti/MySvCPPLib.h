
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
	static FString GetMyFirstCPP(); //블프에 나올 이름 적는 공간 
};
