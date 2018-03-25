#pragma once

#include "Logic/GameSystems.h"
#include "Data/AssetLibrary.h"
#include "GameFramework/PlayerController.h"
#include "MatchOneEnttPlayerController.generated.h"

UCLASS()
class MATCHONEENTT_API AMatchOneEnttPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AMatchOneEnttPlayerController();

    virtual void SetupInputComponent() override;
    virtual void Tick(float DeltaSeconds) override;

    void OnClick();
    void OnPressedB();

protected:
    virtual void BeginPlay() override;
    virtual void BeginDestroy() override;
    virtual void FinishDestroy() override;

private:
    void CheckHit();

    AssetLibrary* Assets;
    std::unique_ptr<GameSystems> Systems;
};
