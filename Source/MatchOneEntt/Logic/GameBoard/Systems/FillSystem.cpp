#include "FillSystem.h"
#include "Components/DestroyedComponent.h"
#include "Components/GameBoardComponent.h"
#include "Components/GameBoardElementComponent.h"
#include "Logic/GameBoard/GameBoardLogic.h"

void FillSystem::Initialize(entt::registry& Registry)
{
    auto Collector = entt::collector.group<DestroyedComponent>().where<GameBoardElementComponent>();
    Observer = MakeUnique<entt::observer>(Registry, Collector);
}

void FillSystem::Update(entt::registry& Registry)
{
    if (Observer->size() == 0)
    {
        return;
    }

    for (const auto Entity : *Observer)
    {
        auto GameBoard = Registry.ctx<GameBoardComponent>();

        for (int Column = 0; Column < GameBoard.Columns; Column++)
        {
            auto Position = FIntVector(Column, GameBoard.Rows, 0);
            auto NextRowPos = GameBoardLogic::GetNextEmptyRow(Registry, Position);

            while (NextRowPos != GameBoard.Rows)
            {
                GameBoardLogic::CreateRandomPiece(Registry, Column, NextRowPos);
                NextRowPos = GameBoardLogic::GetNextEmptyRow(Registry, Position);
            }
        }
    }

    Observer->clear();
}

void FillSystem::Teardown(entt::registry& Registry)
{
    Observer->clear();
    Observer->disconnect();
}
