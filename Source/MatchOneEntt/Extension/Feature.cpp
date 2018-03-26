#include "MatchOneEntt.h"
#include "Feature.h"

auto Feature::Add(std::shared_ptr<System> System) -> Feature*
{
    Systems.push_back(System);

    return this;
}

void Feature::Initialize(entt::DefaultRegistry &Registry)
{
    for (const auto &System : Systems)
    {
        System->Initialize(Registry);
    }
}

void Feature::Update(entt::DefaultRegistry &Registry)
{
    for (const auto &System : Systems)
    {
        System->Update(Registry);
    }
}
