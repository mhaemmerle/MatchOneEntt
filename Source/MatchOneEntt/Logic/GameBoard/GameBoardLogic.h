#pragma once

#include "entt.hpp"
#include "Components/GameBoardComponent.h"
#include "Components/PositionComponent.h"
#include "Components/AssetComponent.h"
#include "Components/GameBoardElementComponent.h"
#include "Components/InteractiveComponent.h"
#include "Components/MovableComponent.h"
#include "Components/PositionUpdatedComponent.h"
#include "Components/AddViewComponent.h"
#include "Data/Comparator.h"

class GameBoardLogic
{
public:
    static int GetNextEmptyRow(entt::DefaultRegistry &Registry, FIntVector Position)
    {
        Position.Y -= 1;

        while (Position.Y >= 0 && GameBoardPositionEmpty(Registry, Position))
        {
            Position.Y -= 1;
        }

        return Position.Y + 1;
    }

    static uint32_t CreateRandomPiece(entt::DefaultRegistry &Registry, int X, int Y)
    {
        auto Entity = Registry.create();
        Registry.assign<GameBoardElementComponent>(Entity);
        Registry.assign<InteractiveComponent>(Entity);
        Registry.assign<MovableComponent>(Entity);

        std::vector<FName> pieces = {
            FName(TEXT("Piece0")),
            FName(TEXT("Piece1")),
            FName(TEXT("Piece2")),
            FName(TEXT("Piece3")),
            FName(TEXT("Piece4")),
            FName(TEXT("Piece5"))
        };

        int randomIndex = rand() % pieces.size();

        Registry.assign<PositionComponent>(Entity, FIntVector(X, Y, 0));
        Registry.assign<AssetComponent>(Entity, pieces[randomIndex]);
        Registry.assign<PositionUpdatedComponent>(Entity);
        Registry.assign<AddViewComponent>(Entity);

        return Entity;
    }

    static uint32_t CreateBlocker(entt::DefaultRegistry &Registry, int X, int Y)
    {
        auto Entity = Registry.create();
        Registry.assign<GameBoardElementComponent>(Entity);
        Registry.assign<PositionComponent>(Entity, FIntVector(X, Y, 0));
        Registry.assign<AssetComponent>(Entity, FName(TEXT("Blocker")));
        Registry.assign<PositionUpdatedComponent>(Entity);
        Registry.assign<AddViewComponent>(Entity);

        return Entity;
    }

    static bool GameBoardPositionEmpty(entt::DefaultRegistry &Registry, FIntVector Position)
    {
        auto View = Registry.view<PositionComponent>();

        for (auto Entity : View)
        {
            if (Registry.get<PositionComponent>(Entity).Value == Position)
            {
                return false;
            }
        }

        return true;
    }
};
