#pragma once

#include "Interfaces/System.h"

class ScoreListenerSystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
