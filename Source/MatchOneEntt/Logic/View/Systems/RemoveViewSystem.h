#pragma once

#include "Interfaces/System.h"

class RemoveViewSystem : public System
{
public:
    virtual void Initialize(entt::DefaultRegistry &Registry) override;
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
