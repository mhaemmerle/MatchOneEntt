#include "MatchOneEntt.h"
#include "Systems.h"

auto Systems::Add(std::shared_ptr<ISystem> System) -> Systems*
{
    if (std::dynamic_pointer_cast<IInitializeSystem>(System) != nullptr)
    {
        InitializeSystems.push_back(std::dynamic_pointer_cast<IInitializeSystem>(System));
    }

    if (std::dynamic_pointer_cast<IUpdateSystem>(System) != nullptr)
    {
        UpdateSystems.push_back(std::dynamic_pointer_cast<IUpdateSystem>(System));
    }

    return this;
}

void Systems::Initialize(entt::DefaultRegistry &Registry)
{
    for (const auto &System : InitializeSystems)
    {
        System->Initialize(Registry);
    }
}

void Systems::Update(entt::DefaultRegistry &Registry)
{
    for (const auto &System : UpdateSystems)
    {
        System->Update(Registry);
    }
}
