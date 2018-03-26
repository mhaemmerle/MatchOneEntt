#pragma once

#include "Interfaces/System.h"

class AddViewSystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
