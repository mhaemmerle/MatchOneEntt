#pragma once

#include "Interfaces/System.h"

class AnimatePositionSystem : public ISystem, public IUpdateSystem
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
