#include "MatchOneEntt.h"
#include "MatchOneEnttGameMode.h"
#include "Game/MatchOneEnttPlayerController.h"
#include "Game/MatchOneEnttHUD.h"

AMatchOneEnttGameMode::AMatchOneEnttGameMode()
{
    PlayerControllerClass = AMatchOneEnttPlayerController::StaticClass();
    HUDClass = AMatchOneEnttHUD::StaticClass();
}
