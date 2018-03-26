#pragma once

#include "Interfaces/System.h"

class AnimatePositionSystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
