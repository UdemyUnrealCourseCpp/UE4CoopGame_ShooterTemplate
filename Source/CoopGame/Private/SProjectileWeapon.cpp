// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


void ASProjectileWeapon::Fire()
{
	AActor* ActorOwner = GetOwner();

	if (ActorOwner && ProjectileActor)
	{
		FVector EyeLocation;
		FRotator EyeRotation;

		ActorOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocket);

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ActorSpawnParams.Instigator = Cast<APawn>(ActorOwner);

		GetWorld()->SpawnActor<AActor>(ProjectileActor, MuzzleLocation, EyeRotation, ActorSpawnParams);

		if (MuzzleParticle)
		{
			UGameplayStatics::SpawnEmitterAttached(MuzzleParticle, MeshComp, MuzzleSocket);
		}
	}
}
