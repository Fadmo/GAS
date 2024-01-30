// Fadehs GAS

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract) //abstract class (cannot be instantiated)
class GAS_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase(); //constructor

protected:
	virtual void BeginPlay() override;

	//2.2 example
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon; //TObjectPtr is a smart pointer that can be null it is recommended to use it instead of a raw pointer and has the benefit of being garbage collected
};
