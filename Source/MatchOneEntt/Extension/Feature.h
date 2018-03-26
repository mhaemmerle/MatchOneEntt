#pragma once

#include "Feature.h"
#include "System.h"

class Feature : public System
{
public:
    auto Add(std::shared_ptr<System> system)->Feature*;
    template <typename T> inline auto Add()->Feature*;

    virtual void Initialize(entt::DefaultRegistry &Registry) override;
    virtual void Update(entt::DefaultRegistry &Registry) override;

protected:
    std::vector<std::shared_ptr<System>> Systems;
};

template <typename T>
auto Feature::Add() -> Feature*
{
    return Add(std::shared_ptr<T>(new T()));
}
