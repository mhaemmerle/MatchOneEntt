#include "MatchOneEnttPlayerController.h"
#include "Components/UserInputComponent.h"
#include "Components/BurstModeComponent.h"
#include "Components/AssetLibraryComponent.h"
#include "Components/WorldComponent.h"
#include "Components/ViewContainerComponent.h"
#include "Components/ScoreListenerComponent.h"
#include "Game/Actors/GamePiece.h"
#include "Game/Actors/ViewContainer.h"
#include "Game/MatchOneEnttHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

AMatchOneEnttPlayerController::AMatchOneEnttPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;

    Registry = MakeShared<entt::registry>();
    Systems = MakeUnique<GameSystems>();
}

void AMatchOneEnttPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        InputComponent->BindAction("MouseLeftClicked", IE_Pressed, this, &AMatchOneEnttPlayerController::OnClick);
        InputComponent->BindAction("B", IE_Pressed, this, &AMatchOneEnttPlayerController::OnPressedB);
    }
}

void AMatchOneEnttPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto Entity = Registry->create();
    Registry->assign<ScoreListenerComponent>(Entity, Cast<AMatchOneEnttHUD>(GetHUD()));

    Systems->Initialize(Registry.ToSharedRef().Get());

    auto ViewContainer = GetWorld()->SpawnActor<AViewContainer>(AViewContainer::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);

    Registry->set<ViewContainerComponent>(ViewContainer);
    Registry->set<WorldComponent>(GetWorld());
}

void AMatchOneEnttPlayerController::EndPlay(EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    Systems->Teardown(Registry.ToSharedRef().Get());

    Registry->reset();
}

void AMatchOneEnttPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (IsInputKeyDown(EKeys::LeftMouseButton))
    {
        if (auto BurstMode = Registry->try_ctx<BurstModeComponent>())
        {
            CheckHit();
        }
    }

    Systems->Update(Registry.ToSharedRef().Get());
}

void AMatchOneEnttPlayerController::SetAssetLibrary(UAssetLibrary* AssetLibrary)
{
    Registry->set<AssetLibraryComponent>(AssetLibrary);
}

void AMatchOneEnttPlayerController::OnClick()
{
    CheckHit();
}

void AMatchOneEnttPlayerController::OnPressedB()
{
    if (auto BurstMode = Registry->try_ctx<BurstModeComponent>())
    {
        Registry->unset<BurstModeComponent>();
    }
    else
    {
        Registry->set<BurstModeComponent>();
    }
}

void AMatchOneEnttPlayerController::CheckHit()
{
    float LocationX;
    float LocationY;

    GetMousePosition(LocationX, LocationY);

    FVector2D MousePosition(LocationX, LocationY);
    FHitResult HitResult;
    const bool TraceComplex = false;

    if (GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, TraceComplex, HitResult) == true)
    {
        auto GamePiece = Cast<AGamePiece>(HitResult.GetActor());

        if (GamePiece != nullptr)
        {
            auto Location = GamePiece->GetActorLocation();

            auto Entity = Registry->create();
            Registry->assign<UserInputComponent>(Entity, int(Location.Y / 125.f), int(Location.Z / 125.f));
        }
    }
}
