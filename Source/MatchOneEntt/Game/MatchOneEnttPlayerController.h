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

    UFUNCTION(BlueprintCallable)
        void SetAssetLibrary(UAssetLibrary* Assets);

    void OnClick();
    void OnPressedB();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

private:
    void CheckHit();

    TSharedPtr<entt::registry> Registry;
    TUniquePtr<GameSystems> Systems;
};
