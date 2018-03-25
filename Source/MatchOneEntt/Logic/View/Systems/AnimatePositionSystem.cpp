#include "MatchOneEntt.h"
#include "AnimatePositionSystem.h"
#include "Components/PositionUpdatedComponent.h"
#include "Components/PositionComponent.h"
#include "Components/ViewComponent.h"
#include "Components/GameBoardComponent.h"

void AnimatePositionSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<PositionUpdatedComponent, ViewComponent>();

    if (View.size() > 0)
    {
        auto GameBoard = Registry.get<GameBoardComponent>();

        for (auto Entity : View)
        {
            auto &Position = Registry.get<PositionComponent>(Entity);
            auto &ViewComp = Registry.get<ViewComponent>(Entity);

            auto IsTopRow = Position.Value.Y == GameBoard.Rows - 1;

            auto X = 0.0f;
            auto Y = Position.Value.X * 125.0f;
            auto Z = Position.Value.Y * 125.0f;

            if (IsTopRow)
            {
                ViewComp.Value->SetActorLocation(FVector(X, Y, Z + 1));
            }

            ViewComp.Value->SetActorLocation(FVector(X, Y, Z));

            Registry.remove<PositionUpdatedComponent>(Entity);
        }
    }
}
