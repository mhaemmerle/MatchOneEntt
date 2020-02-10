#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Game/Actors/GamePiece.h"
#include "AssetLibrary.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MATCHONEENTT_API UAssetLibrary : public UObject
{
    GENERATED_BODY()

public:
    UAssetLibrary(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
        TMap<FName, TSubclassOf<AGamePiece>> GamePieces;
};
