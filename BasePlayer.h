// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "BasePlayer.generated.h"


UCLASS()
class COINCOLLECTOR_API ABasePlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//connects a mesh to this actor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	//arm for the camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	//camera connected to the spring arm
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	//variable for movement force
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce;

	//variables for keybinds
	void MoveUp(float Value);
	void MoveRight(float Value);

	//variable for jump force
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse;

	//jump event this is implemented in the actors blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void Jump();




};
