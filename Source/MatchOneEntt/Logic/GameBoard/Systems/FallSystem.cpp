#include "FallSystem.h"
#include "Components/FallEventComponent.h"
#include "Components/GameBoardComponent.h"
#include "Components/PositionComponent.h"
#include "Components/MovableComponent.h"
#include "Components/PositionUpdatedComponent.h"
#include "Logic/GameBoard/GameBoardLogic.h"
#include "Data/Comparator.h"

void FallSystem::Initialize(entt::DefaultRegistry &Registry)
{
    Registry.prepare<PositionComponent, MovableComponent>();
}

void FallSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<FallEventComponent>();

    if (View.size() > 0)
    {
        auto GameBoard = Registry.get<GameBoardComponent>();

        for (auto Entity : View)
        {
            for (int Column = 0; Column < GameBoard.Columns; Column++)
            {
                for (int Row = 1; Row < GameBoard.Rows; Row++)
                {
                    auto CurrentPosition = FIntVector(Column, Row, 0);
                    auto PositionView = Registry.persistent<PositionComponent, MovableComponent>();

                    for (auto PositionEntity : PositionView)
                    {
                        auto Position = PositionView.get<PositionComponent>(PositionEntity);

                        if (Position.Value == CurrentPosition)
                        {
                            auto NextRowPosition = GameBoardLogic::GetNextEmptyRow(Registry, CurrentPosition);

                            if (NextRowPosition != Position.Value.Y)
                            {
                                Registry.replace<PositionComponent>(PositionEntity, FIntVector(CurrentPosition.X, NextRowPosition, 0));
                                Registry.accommodate<PositionUpdatedComponent>(PositionEntity);
                            }
                        }
                    }
                }
            }

            Registry.destroy(Entity);
        }
    }
}
