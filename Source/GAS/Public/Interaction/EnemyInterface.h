// Fadehs GAS

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAS_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighLightActor() = 0; // Pure virtual function which must be implemented in the class which inherits this interface
	virtual void UnHighLightActor() = 0; // Pure virtual function which must be implemented in the class which inherits this interface
};
