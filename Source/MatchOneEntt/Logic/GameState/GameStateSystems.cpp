#include "GameStateSystems.h"
#include "Systems/ScoreSystem.h"
#include "Systems/ScoreListenerSystem.h"

GameStateSystems::GameStateSystems()
{
    Add(std::make_shared<ScoreSystem>());
    Add(std::make_shared<ScoreListenerSystem>());
}
