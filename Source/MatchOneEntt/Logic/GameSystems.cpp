#include "MatchOneEntt.h"
#include "GameSystems.h"
#include "Logic/Input/InputSystems.h"
#include "Logic/GameBoard/GameBoardSystems.h"
#include "Logic/GameState/GameStateSystems.h"
#include "Logic/View/ViewSystems.h"
#include "Logic/DestroySystem.h"

GameSystems::GameSystems()
{
    Add(std::make_shared<InputSystems>());
    Add(std::make_shared<GameBoardSystems>());
    Add(std::make_shared<GameStateSystems>());
    Add(std::make_shared<ViewSystems>());
    Add(std::make_shared<DestroySystem>());
}
