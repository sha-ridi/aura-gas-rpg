// copyright sha-ridi

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	
protected:
	UPROPERTY(VisibleAnywhere, Category = "Player Camera")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Player Camera")
	USpringArmComponent* SpringArm;	
};
