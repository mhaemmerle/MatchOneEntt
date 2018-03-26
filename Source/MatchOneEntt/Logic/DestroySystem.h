#pragma once

#include "Interfaces/System.h"

class DestroySystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
