#pragma once

#include "Interfaces/System.h"

class DestroySystem : public ISystem, public IUpdateSystem
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
