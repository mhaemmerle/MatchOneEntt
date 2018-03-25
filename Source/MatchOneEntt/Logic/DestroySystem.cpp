#include "MatchOneEntt.h"
#include "DestroySystem.h"
#include "Components/DestroyedComponent.h"
#include "Components/FillEventComponent.h"
#include "Components/FallEventComponent.h"

void DestroySystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<DestroyedComponent>();

    for (auto Entity : View)
    {
        Registry.destroy(Entity);

        Registry.create<FillEventComponent>();
        Registry.create<FallEventComponent>();
    }
}
