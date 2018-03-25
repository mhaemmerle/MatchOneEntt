#include "MatchOneEntt.h"
#include "InputSystems.h"
#include "Systems/ProcessInputSystem.h"

InputSystems::InputSystems()
{
    Add(std::make_shared<ProcessInputSystem>());
}
