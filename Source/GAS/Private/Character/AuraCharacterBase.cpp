// Fadehs GAS

#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	// 2.2 Example
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), TEXT("WeaponHandSocket")); //GetMesh() is a function from ACharacter
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision); //disable collision
}


void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}
