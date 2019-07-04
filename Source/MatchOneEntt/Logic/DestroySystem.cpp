#include "DestroySystem.h"
#include "Components/DestroyedComponent.h"

void DestroySystem::Update(entt::registry& Registry)
{
    auto View = Registry.view<DestroyedComponent>();

    for (auto Entity : View)
    {
        Registry.destroy(Entity);
    }
}
