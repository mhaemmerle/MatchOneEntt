#pragma once

#include "CoreMinimal.h"
#include "Extension/System.h"

class GameBoardSystem final : public System
{
public:
    virtual void Initialize(entt::registry& Registry) override;
    virtual void Update(entt::registry& Registry) override;
};
