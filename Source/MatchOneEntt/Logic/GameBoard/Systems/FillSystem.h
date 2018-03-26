#pragma once

#include "Interfaces/System.h"

class FillSystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
