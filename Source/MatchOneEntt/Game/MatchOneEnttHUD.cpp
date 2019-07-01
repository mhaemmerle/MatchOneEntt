#include "MatchOneEnttHUD.h"

void AMatchOneEnttHUD::BeginPlay()
{
    Super::BeginPlay();
}

void AMatchOneEnttHUD::DrawHUD()
{
    Super::DrawHUD();

    DrawText(FString::FromInt(Score), FColor::White, 10.0f, 10.0f);
}

void AMatchOneEnttHUD::OnScore(int32 InScore)
{
    Score = InScore;
}
