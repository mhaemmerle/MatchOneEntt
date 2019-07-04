#include "ViewSystems.h"
#include "Systems/RemoveViewSystem.h"
#include "Systems/AddViewSystem.h"
#include "Systems/SetViewPositionSystem.h"
#include "Systems/AnimatePositionSystem.h"

ViewSystems::ViewSystems()
{
    Add(MakeShared<RemoveViewSystem>());
    Add(MakeShared<AddViewSystem>());
    Add(MakeShared<SetViewPositionSystem>());
    Add(MakeShared<AnimatePositionSystem>());
}
