// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DT_GameplayInterface.h"
#include "DT_ItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROGUELIKE_API ADT_ItemChest : public AActor, public IDT_GameplayInterface
{
	GENERATED_BODY()

public:
	void Interact_Implementation(APawn* InstigatorPawn) override;

	UPROPERTY(EditAnywhere)
		float TargetPitch;
	
protected:

	// Sets default values for this actor's properties
	ADT_ItemChest();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
