#include "InputSystems.h"
#include "Systems/ProcessInputSystem.h"

InputSystems::InputSystems()
{
    Add(MakeShared<ProcessInputSystem>());
}
