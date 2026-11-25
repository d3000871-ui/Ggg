#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GggCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class AGggCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AGggCharacter();

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    TObjectPtr<USpringArmComponent> CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    TObjectPtr<UCameraComponent> FollowCamera;
};
