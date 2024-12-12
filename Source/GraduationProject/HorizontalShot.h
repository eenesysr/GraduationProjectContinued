// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HorizontalShot.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRADUATIONPROJECT_API UHorizontalShot : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHorizontalShot();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool isStarting = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool isActivee = true;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector NewLocation ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector CurrentLocation ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector TargetLocation ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector OriginalLocation ;
	
private:

	UPROPERTY(EditAnywhere)
	float Vx =50;

	float h= 40;
	float g = 10;
};
