#pragma once

#include "CoreMinimal.h"
#include "entt.hpp"

class System
{
protected:
    System() {};
    System(const System&) = default;
    System& operator=(const System&) = default;

public:
    virtual ~System() = default;

    virtual void Initialize(entt::registry& Registry);
    virtual void Update(entt::registry& Registry);
    virtual void Teardown(entt::registry& Registry);
};
