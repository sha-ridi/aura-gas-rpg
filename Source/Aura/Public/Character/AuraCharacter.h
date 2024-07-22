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
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:
	UPROPERTY(VisibleAnywhere, Category = "Player Camera")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Player Camera")
	USpringArmComponent* SpringArm;	

	virtual void InitAbilityActorInfo() override;

};
