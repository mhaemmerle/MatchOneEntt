#include "MatchOneEntt.h"
#include "Systems.h"

auto Systems::Add(std::shared_ptr<System> System) -> Systems*
{
    mSystems.push_back(System);

    return this;
}

void Systems::Initialize(entt::DefaultRegistry &Registry)
{
    for (const auto &System : mSystems)
    {
        System->Initialize(Registry);
    }
}

void Systems::Update(entt::DefaultRegistry &Registry)
{
    for (const auto &System : mSystems)
    {
        System->Update(Registry);
    }
}
