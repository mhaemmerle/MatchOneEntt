#pragma once

#include "Extension/Feature.h"

class DestroySystem final : public Feature
{
public:
    virtual void Update(entt::registry& Registry) override;
};
