#include "MatchOneEntt.h"
#include "ViewSystems.h"
#include "Systems/RemoveViewSystem.h"
#include "Systems/AddViewSystem.h"
#include "Systems/SetViewPositionSystem.h"
#include "Systems/AnimatePositionSystem.h"

ViewSystems::ViewSystems()
{
    Add(std::make_shared<RemoveViewSystem>());
    Add(std::make_shared<AddViewSystem>());
    Add(std::make_shared<SetViewPositionSystem>());
    Add(std::make_shared<AnimatePositionSystem>());
}
