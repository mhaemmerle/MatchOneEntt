#include "MatchOneEntt.h"
#include "GameBoardSystems.h"
#include "Systems/GameBoardSystem.h"
#include "Systems/FallSystem.h"
#include "Systems/FillSystem.h"

GameBoardSystems::GameBoardSystems()
{
    Add(std::make_shared<GameBoardSystem>());
    Add(std::make_shared<FallSystem>());
    Add(std::make_shared<FillSystem>());
}
