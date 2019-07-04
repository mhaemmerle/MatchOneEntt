#pragma once

#include "entt.hpp"
#include "Components/GameBoardComponent.h"
#include "Components/PositionComponent.h"
#include "Components/AssetComponent.h"
#include "Components/GameBoardElementComponent.h"
#include "Components/InteractiveComponent.h"
#include "Components/MovableComponent.h"
#include "Components/AddViewComponent.h"
#include "Components/DestroyedComponent.h"
#include "Data/Comparator.h"

class GameBoardLogic
{
public:
    static int GetNextEmptyRow(entt::registry& Registry, FIntVector Position)
    {
        Position.Y -= 1;

        while (Position.Y >= 0 && GameBoardPositionEmpty(Registry, Position))
        {
            Position.Y -= 1;
        }

        return Position.Y + 1;
    }

    static entt::entity CreateRandomPiece(entt::registry& Registry, int X, int Y)
    {
        auto Entity = Registry.create();
        Registry.assign<GameBoardElementComponent>(Entity);
        Registry.assign<InteractiveComponent>(Entity);
        Registry.assign<MovableComponent>(Entity);

        TArray<FName> Pieces = {
            FName(TEXT("Piece0")),
            FName(TEXT("Piece1")),
            FName(TEXT("Piece2")),
            FName(TEXT("Piece3")),
            FName(TEXT("Piece4")),
            FName(TEXT("Piece5"))
        };

        int RandomIndex = rand() % Pieces.Num();

        Registry.assign<PositionComponent>(Entity, FIntVector(X, Y, 0));
        Registry.assign<AssetComponent>(Entity, Pieces[RandomIndex]);
        Registry.assign<AddViewComponent>(Entity);

        return Entity;
    }

    static entt::entity CreateBlocker(entt::registry& Registry, int X, int Y)
    {
        auto Entity = Registry.create();
        Registry.assign<GameBoardElementComponent>(Entity);
        Registry.assign<PositionComponent>(Entity, FIntVector(X, Y, 0));
        Registry.assign<AssetComponent>(Entity, FName(TEXT("Blocker")));
        Registry.assign<AddViewComponent>(Entity);

        return Entity;
    }

private:
    static bool GameBoardPositionEmpty(entt::registry& Registry, FIntVector Position)
    {
        auto Group = Registry.group<>(entt::get<PositionComponent, GameBoardElementComponent>, entt::exclude<DestroyedComponent>);

        for (auto Entity : Group)
        {
            if (Group.get<PositionComponent>(Entity).Value == Position)
            {
                return false;
            }
        }

        return true;
    }
};
