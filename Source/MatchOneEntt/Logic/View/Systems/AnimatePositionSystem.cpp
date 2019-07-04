#include "AnimatePositionSystem.h"
#include "Components/PositionComponent.h"
#include "Components/ViewComponent.h"
#include "Components/GameBoardComponent.h"

void AnimatePositionSystem::Initialize(entt::registry& Registry)
{
    auto Collector = entt::collector.replace<PositionComponent>().where<ViewComponent>();
    Observer = MakeUnique<entt::observer>(Registry, Collector);
}

void AnimatePositionSystem::Update(entt::registry& Registry)
{
    if (Observer->size() == 0)
    {
        return;
    }

    auto& GameBoard = Registry.ctx<GameBoardComponent>();

    for (const auto Entity : *Observer)
    {
        auto& Position = Registry.get<PositionComponent>(Entity);
        auto& View = Registry.get<ViewComponent>(Entity);

        auto IsTopRow = Position.Value.Y == GameBoard.Rows - 1;

        auto X = 0.0f;
        auto Y = Position.Value.X * 125.0f;
        auto Z = Position.Value.Y * 125.0f;

        if (IsTopRow)
        {
            View.Value->SetActorLocation(FVector(X, Y, Z + 1));
        }

        View.Value->SetActorLocation(FVector(X, Y, Z));
    }

    Observer->clear();
}

void AnimatePositionSystem::Teardown(entt::registry& Registry)
{
    Observer->clear();
    Observer->disconnect();
}
