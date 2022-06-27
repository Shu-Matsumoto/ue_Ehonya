// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Operation.generated.h"

UCLASS()
class EHONYASAN_API AOperation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOperation();

	// HTTP通信をするメソッド
	UFUNCTION(BlueprintCallable)
	void MyTestMethod();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
