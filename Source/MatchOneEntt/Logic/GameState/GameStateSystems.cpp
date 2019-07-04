#include "GameStateSystems.h"
#include "Systems/ScoreSystem.h"
#include "Systems/ScoreListenerSystem.h"

GameStateSystems::GameStateSystems()
{
    Add(MakeShared<ScoreSystem>());
    Add(MakeShared<ScoreListenerSystem>());
}
