#include "MatchOneEntt.h"
#include "AssetLibrary.h"

void AssetLibrary::Add(const std::string &Key, TSubclassOf<AGamePiece> Value)
{
    Assets[Key] = Value;
}

TSubclassOf<AGamePiece> AssetLibrary::Get(const std::string &Key)
{
    auto It = Assets.find(Key);
    return It != Assets.end() ? It->second : nullptr;
}
