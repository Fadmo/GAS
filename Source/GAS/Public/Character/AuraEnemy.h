// Fadehs GAS

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface // This class inherits from AAuraCharacterBase and IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	virtual void HighLightActor() override; 
	virtual void UnHighLightActor() override;
};
