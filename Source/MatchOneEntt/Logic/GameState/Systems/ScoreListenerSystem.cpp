#include "ScoreListenerSystem.h"
#include "Components/ScoreComponent.h"
#include "Components/ScoreListenerComponent.h"

void ScoreListenerSystem::Initialize(entt::registry& Registry)
{
    Observer = MakeUnique<entt::observer>(Registry, entt::collector.replace<ScoreComponent>());
}

void ScoreListenerSystem::Update(entt::registry& Registry)
{
    auto ListenerView = Registry.view<ScoreListenerComponent>();

    for (auto Entity : *Observer)
    {
        auto& Score = Registry.get<ScoreComponent>(Entity);

        for (auto ListenerEntity : ListenerView)
        {
            auto& ScoreListener = ListenerView.get(ListenerEntity);
            ScoreListener.Value->OnScore(Score.Value);
        }
    }

    Observer->clear();
}

void ScoreListenerSystem::Teardown(entt::registry& Registry)
{
    Observer->clear();
    Observer->disconnect();
}
