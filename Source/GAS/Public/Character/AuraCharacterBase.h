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

};
