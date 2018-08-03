// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

UCLASS()
class COOPGAME_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* BarrelMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class URadialForceComponent* RadialForceComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class USHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	float ExplosionImpulse;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UParticleSystem* ExplosionParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UMaterialInterface* ExplosionMaterial;

	UFUNCTION()
	void OnHealthChanged(USHealthComponent* HealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	bool bExploded;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
