#include "ScoreSystem.h"
#include "Components/ScoreComponent.h"
#include "Data/ScoreEntityId.h"
#include "Components/DestroyedComponent.h"
#include "Components/GameBoardElementComponent.h"

void ScoreSystem::Initialize(entt::registry& Registry)
{
    auto Entity = Registry.create();
    Registry.assign<ScoreComponent>(Entity, 0);

    Registry.set<ScoreEntityId>(ScoreEntityId{ Entity });

    auto Collector = entt::collector.group<DestroyedComponent>().where<GameBoardElementComponent>();
    Observer = MakeUnique<entt::observer>(Registry, Collector);
}

void ScoreSystem::Update(entt::registry& Registry)
{
    if (Observer->size() == 0)
    {
        return;
    }

    auto& Score = Registry.get<ScoreComponent>(Registry.ctx<ScoreEntityId>().Value);

    for (const auto Entity : *Observer)
    {
        auto View = Registry.view<ScoreComponent>();

        for (const auto ScoreEntity : View)
        {
            Registry.replace<ScoreComponent>(ScoreEntity, Score.Value + 1);
        }
    }

    Observer->clear();
}

void ScoreSystem::Teardown(entt::registry& Registry)
{
    Observer->clear();
    Observer->disconnect();
}
