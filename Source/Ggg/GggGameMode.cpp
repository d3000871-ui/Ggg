#include "GggGameMode.h"
#include "GggCharacter.h"
#include "GggPlayerState.h"

AGggGameMode::AGggGameMode()
{
    PlayerStateClass = AGggPlayerState::StaticClass();
    DefaultPawnClass = AGggCharacter::StaticClass();
}
