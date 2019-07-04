#include "GameSystems.h"
#include "Logic/Input/InputSystems.h"
#include "Logic/GameBoard/GameBoardSystems.h"
#include "Logic/GameState/GameStateSystems.h"
#include "Logic/View/ViewSystems.h"
#include "Logic/DestroySystem.h"

GameSystems::GameSystems()
{
    Add(MakeShared<InputSystems>());
    Add(MakeShared<GameBoardSystems>());
    Add(MakeShared<GameStateSystems>());
    Add(MakeShared<ViewSystems>());
    Add(MakeShared<DestroySystem>());
}
