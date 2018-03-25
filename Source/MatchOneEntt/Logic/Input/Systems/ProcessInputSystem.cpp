#include "MatchOneEntt.h"
#include "ProcessInputSystem.h"
#include "Components/UserInputComponent.h"
#include "Components/DestroyedComponent.h"
#include "Components/PositionComponent.h"
#include "Components/InteractiveComponent.h"
#include "Components/UpdateScoreComponent.h"
#include "Data/Comparator.h"

void ProcessInputSystem::Initialize(entt::DefaultRegistry &Registry)
{
    Registry.prepare<PositionComponent, InteractiveComponent>();
}

void ProcessInputSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.view<UserInputComponent>();

    for (auto Entity : View)
    {
        auto UserInput = Registry.get<UserInputComponent>(Entity);
        auto InputPosition = FIntVector(UserInput.X, UserInput.Y, 0);

        auto PositionView = Registry.persistent<PositionComponent, InteractiveComponent>();

        for (auto PositionEntity : PositionView)
        {
            auto Position = PositionView.get<PositionComponent>(PositionEntity);

            if (Position.Value == InputPosition)
            {
                if (Registry.has<DestroyedComponent>(PositionEntity) == false)
                {
                    Registry.assign<DestroyedComponent>(PositionEntity);
                    Registry.create<UpdateScoreComponent>();
                }
            }
        }

        Registry.destroy(Entity);
    }
}
