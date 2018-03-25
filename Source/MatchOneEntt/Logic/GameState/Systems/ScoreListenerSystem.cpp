#include "MatchOneEntt.h"
#include "ScoreListenerSystem.h"
#include "Components/ScoreUpdatedComponent.h"
#include "Components/ScoreComponent.h"
#include "Components/ScoreListenerComponent.h"

void ScoreListenerSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<ScoreUpdatedComponent>();
    auto ListenerView = Registry.view<ScoreListenerComponent>();

    for (auto Entity : View)
    {
        auto Score = Registry.get<ScoreComponent>();

        for (auto ListenerEntity : ListenerView)
        {
            auto ScoreListener = Registry.get<ScoreListenerComponent>(ListenerEntity);
            ScoreListener.Value->OnScore(Score.Value, Registry.attachee<ScoreComponent>());
        }

        Registry.destroy(Entity);
    }
}
