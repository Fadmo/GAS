// Fadehs GAS


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100.f; // How often the server will update the state of this actor to the clients, normally half a second or so is fine.
}
