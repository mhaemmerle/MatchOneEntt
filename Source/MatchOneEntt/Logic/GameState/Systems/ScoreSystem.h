#pragma once

#include "Extension/System.h"
#include "EnttWrapper.h"

class ScoreSystem : public System
{
public:
    virtual void Initialize(entt::registry& Registry) override;
    virtual void Update(entt::registry& Registry) override;
    virtual void Teardown(entt::registry& Registry) override;

protected:
    TUniquePtr<entt::observer> Observer;
};
