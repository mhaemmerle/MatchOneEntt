#pragma once

#include "CoreMinimal.h"
#include "Extension/System.h"
#include "EnttWrapper.h"

class ScoreListenerSystem : public System
{
public:
    virtual void Initialize(entt::registry& Registry) override;
    virtual void Update(entt::registry& Registry) override;
    virtual void Teardown(entt::registry& Registry) override;

protected:
    TUniquePtr<entt::observer> Observer;
};
