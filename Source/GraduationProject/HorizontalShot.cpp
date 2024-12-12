// Fill out your copyright notice in the Description page of Project Settings.


#include "HorizontalShot.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UHorizontalShot::UHorizontalShot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHorizontalShot::BeginPlay()
{
	Super::BeginPlay();

	float t = FMath::Sqrt((2 * h) / g);
	float Distance = Vx * t;

 	OriginalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UHorizontalShot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if(isStarting)
	{
		float t = FMath::Sqrt((2 * h) / g);
		float Distance = Vx * t;
		CurrentLocation = GetOwner()->GetActorLocation();
		if(isActivee)
		{
			TargetLocation = CurrentLocation + FVector(Distance, 0, -40);
			float Speed = (Vx / t) ;
			NewLocation =  FMath::VInterpTo(CurrentLocation,TargetLocation,DeltaTime,Speed);
			GetOwner()->SetActorLocation(NewLocation);
			FString Result = FString::Printf(TEXT("Havada Kalma Süresi: %.2f saniye\nYatayda Alınan Mesafe: %.2f metre"), t, Distance);
				if (GEngine)
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Result);
				}
			isActivee = false;
		}
		

	}

}





