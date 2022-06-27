// Fill out your copyright notice in the Description page of Project Settings.


#include "Operation.h"

// Sets default values
AOperation::AOperation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOperation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOperation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOperation::MyTestMethod()
{
	// UE4クライアントにデバッグメッセージを表示
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, "CPPCPPCPPCPPCPPCPPCPPCPPCPPCPPCPPCPP");
}

