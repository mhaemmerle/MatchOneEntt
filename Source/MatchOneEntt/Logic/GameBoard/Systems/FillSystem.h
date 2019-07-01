#pragma once

#include "Extension/System.h"

class FillSystem : public System
{
public:
    virtual void Update(entt::registry& Registry) override;
};
