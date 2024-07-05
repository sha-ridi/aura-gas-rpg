// copyright sha-ridi


#include "Character/AuraCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "UI/HUD/AuraHUD.h"
#include "Player/AuraPlayerController.h"

AAuraCharacter::AAuraCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->SetRelativeRotation(FRotator(-43.f, 0.f, 0.f));
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritRoll = false;
    SpringArm->bInheritYaw = false;
    SpringArm->TargetArmLength = 700;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 20;
    SpringArm->CameraLagMaxDistance = 100;

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    
    //init ability actor info for the server
    InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    //init ability actor info for the client
    InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
    AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
    check (AuraPlayerState);

    AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);

    AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
    AttributeSet = AuraPlayerState->GetAttributeSet();

    AAuraPlayerController* AuraPlayerController = GetController<AAuraPlayerController>();
    
    if (AuraPlayerController)
    {
        AAuraHUD* AuraHUD = AuraPlayerController->GetHUD<AAuraHUD>();
        if (AuraHUD)
        {
            AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
        }
    }
}

