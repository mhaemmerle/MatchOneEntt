#pragma once

#include "PaperSpriteActor.h"
#include "GamePiece.generated.h"

UCLASS()
class MATCHONEENTT_API AGamePiece : public APaperSpriteActor
{
    GENERATED_BODY()

public:
    AGamePiece(const FObjectInitializer& ObjectInitializer);
};
