#include "GggGameMode.h"
#include "GggCharacter.h"

AGggGameMode::AGggGameMode()
{
    DefaultPawnClass = AGggCharacter::StaticClass();
}
