#pragma once

#include "Extension/System.h"

class GameBoardSystem : public System
{
public:
    virtual void Initialize(entt::registry& Registry) override;
    virtual void Update(entt::registry& Registry) override;
};
