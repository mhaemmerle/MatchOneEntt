#pragma once

#include "Extension/System.h"

class AddViewSystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
