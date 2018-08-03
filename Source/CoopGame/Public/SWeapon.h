// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

UCLASS()
class COOPGAME_API ASWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USkeletalMeshComponent* MeshComp;

	virtual void Fire();

	void PlayFireEffects(FVector TracerEndPoint);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UDamageType> DamageType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName MuzzleSocket;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName TraceBeamSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseDamage;

	float LastFireTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RateOffFire;

	float TimeBetweenShots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UParticleSystem* MuzzleParticle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* DefaultImpactParticle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* FleshImpactParticle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* TracerParticle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UCameraShake>FireCamShake;

	FTimerHandle TimerHandle_Fire;

public:	
	void StartFire();
	void EndFire();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
