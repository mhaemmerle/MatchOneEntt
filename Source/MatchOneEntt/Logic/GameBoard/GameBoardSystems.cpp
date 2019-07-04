#include "GameBoardSystems.h"
#include "Systems/GameBoardSystem.h"
#include "Systems/FallSystem.h"
#include "Systems/FillSystem.h"

GameBoardSystems::GameBoardSystems()
{
    Add(MakeShared<GameBoardSystem>());
    Add(MakeShared<FallSystem>());
    Add(MakeShared<FillSystem>());
}
