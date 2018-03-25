#pragma once

#include "Interfaces/System.h"

class RemoveViewSystem : public ISystem, public IInitializeSystem, public IUpdateSystem
{
public:
    virtual void Initialize(entt::DefaultRegistry &Registry) override;
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
