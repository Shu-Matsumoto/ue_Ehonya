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
	// 画像データファイル拡張子
	static const FString ExtensionOfImageFile;

	// 音声データファイル拡張子
	static const FString ExtensionOfSoundFile;

	// 画像データディレクトリ
	static const FString ImageDir;

	// 音声データディレクトリ
	static const FString SoundDir;

	// 画像ファイルパスを格納するアレイ
	TArray<FString> imageUrlList;

	// 音声ファイルパスを格納するアレイ
	TArray<FString> soundUrlList;

	// 現在有効ページのインデックス
	int curretPageIndex = 0;

public:	
	// Sets default values for this actor's properties
	AEhonOperation();

	// 対象ブックデータディレクトリ
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
