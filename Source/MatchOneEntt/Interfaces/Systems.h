#pragma once

#include "Systems.h"
#include "System.h"

class Systems : public ISystem, public IInitializeSystem, public IUpdateSystem
{
public:
    Systems() = default;

    auto Add(std::shared_ptr<ISystem> system)->Systems*;
    template <typename T> inline auto Add()->Systems*;

    virtual void Initialize(entt::DefaultRegistry &Registry) override;
    virtual void Update(entt::DefaultRegistry &Registry) override;

private:
    std::vector<std::shared_ptr<IInitializeSystem>> InitializeSystems;
    std::vector<std::shared_ptr<IUpdateSystem>> UpdateSystems;
};

template <typename T>
auto Systems::Add() -> Systems*
{
    return Add(std::shared_ptr<T>(new T()));
}
