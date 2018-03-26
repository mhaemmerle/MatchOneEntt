#pragma once

#include "Extension/System.h"

class ScoreListenerSystem : public System
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
