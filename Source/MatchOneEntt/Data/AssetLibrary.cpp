#include "MatchOneEntt.h"
#include "AssetLibrary.h"

void AssetLibrary::Add(FName Key, TSubclassOf<AGamePiece> Value)
{
    Assets.Add(Key, Value);
}

TSubclassOf<AGamePiece> AssetLibrary::Get(FName Key)
{
    return Assets.FindRef(Key);
}
