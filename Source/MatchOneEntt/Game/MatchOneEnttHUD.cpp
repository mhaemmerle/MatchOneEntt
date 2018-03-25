#include "MatchOneEntt.h"
#include "MatchOneEnttHUD.h"
#include "entt.hpp"
#include "Components/ScoreListenerComponent.h"

void AMatchOneEnttHUD::BeginPlay()
{
    Super::BeginPlay();

    entt::DefaultRegistry &Registry = entt::ServiceLocator<entt::DefaultRegistry>::ref();
    Registry.create(ScoreListenerComponent{ this });
}

void AMatchOneEnttHUD::DrawHUD()
{
    Super::DrawHUD();

    DrawText(FString::FromInt(Score), FColor::White, 10.0f, 10.0f);
}

void AMatchOneEnttHUD::OnScore(int32 InScore, uint32_t Entity)
{
    Score = InScore;
}
