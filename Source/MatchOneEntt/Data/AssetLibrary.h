#pragma once

#include "Game/Actors/GamePiece.h"
#include <unordered_map>

class AssetLibrary
{
public:
    void Add(const std::string &Key, TSubclassOf<AGamePiece> Value);
    TSubclassOf<AGamePiece> Get(const std::string &Key);

private:
    std::unordered_map<std::string, TSubclassOf<AGamePiece>> Assets;
};
