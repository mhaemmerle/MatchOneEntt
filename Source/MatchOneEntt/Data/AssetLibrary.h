#pragma once

#include "Game/Actors/GamePiece.h"

class AssetLibrary
{
public:
    void Add(FName, TSubclassOf<AGamePiece> Value);
    TSubclassOf<AGamePiece> Get(FName Key);

private:
    TMap<FName, TSubclassOf<AGamePiece>> Assets;
};
