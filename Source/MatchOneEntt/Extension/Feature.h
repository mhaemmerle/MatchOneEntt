#pragma once

#include "CoreMinimal.h"
#include "System.h"

class Feature : public System
{
public:
    auto Add(TSharedPtr<System> InSystem)->Feature*;
    template <typename T> inline auto Add()->Feature*;

    virtual void Initialize(entt::registry& Registry) override;
    virtual void Update(entt::registry& Registry) override;
    virtual void Teardown(entt::registry& Registry) override;

protected:
    TArray<TSharedPtr<System>> Systems;
};

template <typename T>
auto Feature::Add() -> Feature*
{
    return Add(MakeShared<T>());
}
