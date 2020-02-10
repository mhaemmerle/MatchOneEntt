#pragma once

#include "Extension/System.h"

class AddViewSystem final : public System
{
public:
    virtual void Update(entt::registry& Registry) override;
};
