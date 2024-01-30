// Fadehs GAS

#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true; //enable replication so that all clients can be updated by the server
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext); //check if AuraContext is valid (which is a pointer)

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()); //get the local player subsystem
	check(Subsystem); //check if Subsystem is valid (which is a pointer)
	Subsystem->AddMappingContext(AuraContext, 0); //add the AuraContext to the subsystem

	bShowMouseCursor = true; //show the mouse cursor
	DefaultMouseCursor = EMouseCursor::Crosshairs; //set the default mouse cursor to crosshairs

	FInputModeGameAndUI InputModeData; //create a new input mode
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); //set the lock mouse to viewport behavior to DoNotLock
	InputModeData.SetHideCursorDuringCapture(false); //set the hide cursor during capture to false
	SetInputMode(InputModeData); //set the input mode to the input mode data
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move); //bind the MoveAction to the Move function
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>(); //get the vector2d from the input action value
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); //get the forward vector that corresponds to the yaw rotation vector
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit; //create a new hit result to store the hit result under the cursor
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit); //get the hit result under the cursor

	if(!CursorHit.bBlockingHit) return; //if the hit result is not blocking, return

	LastActor = ThisActor; //set the last actor to the current actor
	ThisActor =	Cast<IEnemyInterface>(CursorHit.GetActor()); //cast the hit actor to the enemy interface and execute the OnCursorOver function

	if(LastActor == nullptr) //if the current actor is not the last actor and the last actor is not null
	{
		if(ThisActor != nullptr) //if the current actor is not null
		{
			ThisActor->HighLightActor(); //execute the OnCursorOver function
		}
		else //if the current actor is null
		{
			//Both Actor are null, do nothing
		}
	}
	else
	{
		if(ThisActor == nullptr) //if the current actor is null
		{
			LastActor->UnHighLightActor(); //execute the Unhighlight function
		}
		else
		{
			if(ThisActor != LastActor)
			{
				LastActor->UnHighLightActor(); //execute the Unhighlight function on LastActor
				ThisActor->HighLightActor(); //execute the Highlight function on ThisActor
			}
			else
			{
				//Both Actor are the same, do nothing
			}
		}
	}
	
}
