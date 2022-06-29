// Fill out your copyright notice in the Description page of Project Settings.


#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "EhonOperation.h"
#include "DataStorePlace.h"
#include "Misc/LocalTimestampDirectoryVisitor.h"

const FString AEhonOperation::ExtensionOfImageFile = ".bmp";
const FString AEhonOperation::ExtensionOfSoundFile = ".bmp";
const FString AEhonOperation::ImageDir = "images";
const FString AEhonOperation::SoundDir = "sounds";

// Sets default values
AEhonOperation::AEhonOperation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEhonOperation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEhonOperation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Load book data files
bool AEhonOperation::LoadBookDataFiles()
{
	// ページ番号の初期化
	this->curretPageIndex = 0;

    FString imageDir = DataStorePlace::URL + "/"  + AEhonOperation::ImageDir + "/";
    FString soundDir = DataStorePlace::URL + "/" + AEhonOperation::SoundDir + "/";

    // 特定ディレクトリにある画像ファイルパス一覧を取得する
    this->imageUrlList = this->getAllFilesInDirectory(imageDir, 10);

    for (int index = 0; index < this->imageUrlList.Num(); index++) 
    {
        GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, this->imageUrlList[index]);
    }


	return true;
}

// Start book from entry
bool AEhonOperation::StartBookFromEntry()
{
	return true;
}

// Move to next of book
bool AEhonOperation::MoveToNextOfBook()
{
	return true;
}

// End Book
bool AEhonOperation::EndBook()
{
	return true;
}

// ファイル一覧取得
TArray<FString> AEhonOperation::getAllFilesInDirectory(const FString directory, const int numOfDataSet)
{

    //GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, directory);

    TArray<FString> files;

    files.Add(directory + FString(TEXT("000.bmp")));
    files.Add(directory + FString(TEXT("001.bmp")));
    files.Add(directory + FString(TEXT("002.bmp")));
    files.Add(directory + FString(TEXT("003.bmp")));
    files.Add(directory + FString(TEXT("004.bmp")));
    files.Add(directory + FString(TEXT("005.bmp")));
    files.Add(directory + FString(TEXT("006.bmp")));
    files.Add(directory + FString(TEXT("007.bmp")));
    files.Add(directory + FString(TEXT("008.bmp")));
    files.Add(directory + FString(TEXT("009.bmp")));


    /*for (int index = 0; index < numOfDataSet; index++)
    {
        std::ostringstream sout;
        sout << std::setfill('0') << std::setw(3) << index;
        std::string s = sout.str();
        FString temp(s.c_str());
        files.Add(directory + temp + FString(TEXT(".bmp")));
    }*/

    return files;
}

//// ファイル一覧取得
//TArray<FString> AEhonOperation::getAllFilesInDirectory(const FString directory, const bool fullPath, const bool withoutExtention, const FString onlyFilesStartingWith, const FString onlyFilesWithExtension)
//{
//
//    //GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, directory);
//
//    // Get all files in directory
//    TArray<FString> directoriesToSkip;
//    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
//    FLocalTimestampDirectoryVisitor Visitor(PlatformFile, directoriesToSkip, directoriesToSkip, false);
//    PlatformFile.IterateDirectory(*directory, Visitor);
//    TArray<FString> files;
//
//    int n = Visitor.FileTimes.Num();
//    FString dbMessage = FString::FromInt(n);
//    GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, dbMessage);
//
//    for (TMap<FString, FDateTime>::TIterator TimestampIt(Visitor.FileTimes); TimestampIt; ++TimestampIt)
//    {
//        const FString filePath = TimestampIt.Key();
//        const FString fileName = FPaths::GetCleanFilename(filePath);
//        bool shouldAddFile = true;
//
//        // Check if filename starts with required characters
//        if (!onlyFilesStartingWith.IsEmpty())
//        {
//            const FString left = fileName.Left(onlyFilesStartingWith.Len());
//
//            if (!(fileName.Left(onlyFilesStartingWith.Len()).Equals(onlyFilesStartingWith)))
//                shouldAddFile = false;
//        }
//
//        // Check if file extension is required characters
//        if (!onlyFilesWithExtension.IsEmpty())
//        {
//            if (!(FPaths::GetExtension(fileName, false).Equals(onlyFilesWithExtension, ESearchCase::IgnoreCase)))
//                shouldAddFile = false;
//        }
//
//
//        // Add full path to results
//        if (shouldAddFile)
//        {
//            if (withoutExtention)
//                files.Add(fullPath ? filePath : FPaths::GetBaseFilename(filePath));
//            else
//                files.Add(fullPath ? filePath : FPaths::GetCleanFilename(filePath));
//        }
//    }
//
//    return files;
//}

