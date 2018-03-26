#include "ScoreSystem.h"
#include "Components/ScoreComponent.h"
#include "Components/UpdateScoreComponent.h"
#include "Components/ScoreUpdatedComponent.h"

void ScoreSystem::Initialize(entt::DefaultRegistry &Registry)
{
    Registry.attach<ScoreComponent>(Registry.create(), 0);
}

void ScoreSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<UpdateScoreComponent>();

    for (auto Entity : View)
    {
        auto ScoreEntity = Registry.attachee<ScoreComponent>();
        auto Score = Registry.get<ScoreComponent>();

        Registry.attach<ScoreComponent>(ScoreEntity, Score.Value + 1);

        Registry.destroy(Entity);

        Registry.create<ScoreUpdatedComponent>();
    }
}
