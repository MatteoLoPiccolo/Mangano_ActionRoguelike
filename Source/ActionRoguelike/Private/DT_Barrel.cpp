// Fill out your copyright notice in the Description page of Project Settings.


#include "DT_Barrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ADT_Barrel::ADT_Barrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetSimulatePhysics(true);

	RootComponent = MeshComp;

	RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForce->SetupAttachment(MeshComp);

	RadialForce->ImpulseStrength = 2000.f;
	RadialForce->bImpulseVelChange = true;
	RadialForce->Radius = 600.f;
	RadialForce->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

// Called when the game starts or when spawned
void ADT_Barrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADT_Barrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

