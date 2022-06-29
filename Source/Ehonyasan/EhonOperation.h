// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include <map>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EhonOperation.generated.h"

UCLASS()
class EHONYASAN_API AEhonOperation : public AActor
{
	GENERATED_BODY()

private:
	// �摜�f�[�^�t�@�C���g���q
	static const FString ExtensionOfImageFile;

	// �����f�[�^�t�@�C���g���q
	static const FString ExtensionOfSoundFile;

	// �摜�f�[�^�f�B���N�g��
	static const FString ImageDir;

	// �����f�[�^�f�B���N�g��
	static const FString SoundDir;

	// �摜�t�@�C���p�X���i�[����A���C
	TArray<FString> imageUrlList;

	// �����t�@�C���p�X���i�[����A���C
	TArray<FString> soundUrlList;

	// ���ݗL���y�[�W�̃C���f�b�N�X
	int curretPageIndex = 0;

public:	
	// Sets default values for this actor's properties
	AEhonOperation();

	// �Ώۃu�b�N�f�[�^�f�B���N�g��
	FString DirOfBookData = "";

	// Load book data files
	UFUNCTION(BlueprintCallable)
	bool LoadBookDataFiles();

	// Start book from entry
	UFUNCTION(BlueprintCallable)
	bool StartBookFromEntry();

	// Move to next of book
	UFUNCTION(BlueprintCallable)
	bool MoveToNextOfBook();

	// End Book
	UFUNCTION(BlueprintCallable)
	bool EndBook();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//static TArray<FString> getAllFilesInDirectory(const FString directory, const bool fullPath, const bool withoutExtention, const FString onlyFilesStartingWith, const FString onlyFilesWithExtension);

	static TArray<FString> getAllFilesInDirectory(const FString directory, const int numOfDataSet);

private:

};
