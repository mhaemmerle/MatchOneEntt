#include "Feature.h"

auto Feature::Add(std::shared_ptr<System> System) -> Feature*
{
    Systems.push_back(System);

    return this;
}

void Feature::Initialize(entt::registry& Registry)
{
    for (const auto& System : Systems)
    {
        System->Initialize(Registry);
    }
}

void Feature::Update(entt::registry& Registry)
{
    for (const auto& System : Systems)
    {
        System->Update(Registry);
    }
}

void Feature::Teardown(entt::registry& Registry)
{
    for (const auto& System : Systems)
    {
        System->Teardown(Registry);
    }
}
