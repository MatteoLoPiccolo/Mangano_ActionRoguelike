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

	RadialForce->Radius = 750.f;
	RadialForce->ImpulseStrength = 2500.f;
	RadialForce->bImpulseVelChange = true;
	RadialForce->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

void ADT_Barrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	MeshComp->OnComponentHit.AddDynamic(this, &ADT_Barrel::OnActorHit);
}

void ADT_Barrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForce->FireImpulse();
}
