#include "FallSystem.h"
#include "Components/DestroyedComponent.h"
#include "Components/GameBoardElementComponent.h"
#include "Components/GameBoardComponent.h"
#include "Components/PositionComponent.h"
#include "Components/MovableComponent.h"
#include "Components/PositionUpdatedComponent.h"
#include "Logic/GameBoard/GameBoardLogic.h"
#include "Data/Comparator.h"

void FallSystem::Initialize(entt::registry& Registry)
{
    auto Collector = entt::collector.group<DestroyedComponent>().where<GameBoardElementComponent>();
    Observer = MakeUnique<entt::observer>(Registry, Collector);
}

void FallSystem::Update(entt::registry& Registry)
{
    if (Observer->size() == 0)
    {
        return;
    }

    for (const auto Entity : *Observer)
    {
        auto& GameBoard = Registry.ctx<GameBoardComponent>();

        for (int Column = 0; Column < GameBoard.Columns; Column++)
        {
            for (int Row = 1; Row < GameBoard.Rows; Row++)
            {
                auto CurrentPosition = FIntVector(Column, Row, 0);
                auto PositionView = Registry.view<PositionComponent, MovableComponent>();

                for (auto PositionEntity : PositionView)
                {
                    auto& Position = PositionView.get<PositionComponent>(PositionEntity);

                    if (Position.Value == CurrentPosition)
                    {
                        auto NextRowPosition = GameBoardLogic::GetNextEmptyRow(Registry, CurrentPosition);

                        if (NextRowPosition != Position.Value.Y)
                        {
                            Registry.replace<PositionComponent>(PositionEntity, FIntVector(CurrentPosition.X, NextRowPosition, 0));
                            Registry.assign_or_replace<PositionUpdatedComponent>(PositionEntity);

                            break;
                        }
                    }
                }
            }
        }
    }

    Observer->clear();
}

void FallSystem::Teardown(entt::registry& Registry)
{
    Observer->clear();
    Observer->disconnect();
}
