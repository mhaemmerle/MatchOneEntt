#include "ProcessInputSystem.h"
#include "Components/UserInputComponent.h"
#include "Components/DestroyedComponent.h"
#include "Components/PositionComponent.h"
#include "Components/InteractiveComponent.h"
#include "Data/Comparator.h"

void ProcessInputSystem::Initialize(entt::registry& Registry) {}

void ProcessInputSystem::Update(entt::registry& Registry)
{
    auto View = Registry.view<UserInputComponent>();

    for (auto Entity : View)
    {
        auto UserInput = View.get(Entity);
        auto InputPosition = FIntVector(UserInput.X, UserInput.Y, 0);

        auto PositionView = Registry.view<PositionComponent, InteractiveComponent>();

        for (auto PositionEntity : PositionView)
        {
            auto Position = PositionView.get<PositionComponent>(PositionEntity);

            if (Position.Value == InputPosition)
            {
                if (Registry.has<DestroyedComponent>(PositionEntity) == false)
                {
                    Registry.assign<DestroyedComponent>(PositionEntity);
                }
            }
        }

        Registry.destroy(Entity);
    }
}
