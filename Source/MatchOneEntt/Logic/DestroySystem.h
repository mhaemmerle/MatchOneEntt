#pragma once

#include "Extension/Feature.h"

class DestroySystem : public Feature
{
public:
    virtual void Update(entt::DefaultRegistry &Registry) override;
};
