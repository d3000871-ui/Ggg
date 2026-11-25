#include "GggCharacter.h"\n#include "GggCombatComponent.h"\n#include "GggInventoryComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"

AGggCharacter::AGggCharacter()
{
    PrimaryActorTick.bCanEverTick = true;\n    bReplicates = true;\n    CombatComponent = CreateDefaultSubobject<UGggCombatComponent>(TEXT("CombatComponent"));\n    InventoryComponent = CreateDefaultSubobject<UGggInventoryComponent>(TEXT("InventoryComponent"));
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
    GetCharacterMovement()->JumpZVelocity = 600.0f;
    GetCharacterMovement()->AirControl = 0.2f;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 350.0f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
}

void AGggCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AGggCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AGggCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AGggCharacter::Turn);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AGggCharacter::LookUp);
    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ACharacter::StopJumping);\n    PlayerInputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &AGggCharacter::Attack);
}

void AGggCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
        AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value);
    }
}

void AGggCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
        AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Value);
    }
}

void AGggCharacter::Attack()\n{\n    if (CombatComponent) CombatComponent->PerformAttack();\n}\n\nvoid AGggCharacter::Turn(float Value) { AddControllerYawInput(Value); }
void AGggCharacter::LookUp(float Value) { AddControllerPitchInput(Value); }
