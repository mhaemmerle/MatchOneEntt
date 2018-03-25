#include "MatchOneEntt.h"
#include "FillSystem.h"
#include "Components/FillEventComponent.h"
#include "Components/GameBoardComponent.h"
#include "Logic/GameBoard/GameBoardLogic.h"

void FillSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<FillEventComponent>();

    if (View.size() > 0)
    {
        auto GameBoard = Registry.get<GameBoardComponent>();

        for (auto Entity : View)
        {
            for (int Column = 0; Column < GameBoard.Columns; Column++)
            {
                auto position = FIntVector(Column, GameBoard.Rows, 0);
                auto NextRowPos = GameBoardLogic::GetNextEmptyRow(Registry, position);

                while (NextRowPos != GameBoard.Rows)
                {
                    GameBoardLogic::CreateRandomPiece(Registry, Column, NextRowPos);
                    NextRowPos = GameBoardLogic::GetNextEmptyRow(Registry, position);
                }
            }

            Registry.destroy(Entity);
        }
    }
}
