#pragma once

#include "Interfaces/ScoreListener.h"
#include "GameFramework/HUD.h"
#include "MatchOneEnttHUD.generated.h"

UCLASS()
class MATCHONEENTT_API AMatchOneEnttHUD : public AHUD, public IScoreListener
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void DrawHUD() override;

private:
    void OnScore(int32 InScore, uint32_t Entity) override;

    int Score;
};
