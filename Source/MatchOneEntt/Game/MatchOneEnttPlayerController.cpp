#include "MatchOneEntt.h"
#include "MatchOneEnttPlayerController.h"
#include "Components/UserInputComponent.h"
#include "Components/BurstModeComponent.h"
#include "Components/AssetLibraryComponent.h"
#include "Components/WorldComponent.h"
#include "Components/ViewContainerComponent.h"
#include "Game/Actors/GamePiece.h"
#include "Game/Actors/ViewContainer.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

AMatchOneEnttPlayerController::AMatchOneEnttPlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;

    static ConstructorHelpers::FClassFinder<AGamePiece> BlockerBPClass(TEXT("/Game/GamePieces/GamePiece_Blocker"));
    static ConstructorHelpers::FClassFinder<AGamePiece> GamePiece0BPClass(TEXT("/Game/GamePieces/GamePiece_0"));
    static ConstructorHelpers::FClassFinder<AGamePiece> GamePiece1BPClass(TEXT("/Game/GamePieces/GamePiece_1"));
    static ConstructorHelpers::FClassFinder<AGamePiece> GamePiece2BPClass(TEXT("/Game/GamePieces/GamePiece_2"));
    static ConstructorHelpers::FClassFinder<AGamePiece> GamePiece3BPClass(TEXT("/Game/GamePieces/GamePiece_3"));
    static ConstructorHelpers::FClassFinder<AGamePiece> GamePiece4BPClass(TEXT("/Game/GamePieces/GamePiece_4"));
    static ConstructorHelpers::FClassFinder<AGamePiece> GamePiece5BPClass(TEXT("/Game/GamePieces/GamePiece_5"));

    Assets = new AssetLibrary();
    Assets->Add(FName(TEXT("Blocker")), BlockerBPClass.Class);
    Assets->Add(FName(TEXT("Piece0")), GamePiece0BPClass.Class);
    Assets->Add(FName(TEXT("Piece1")), GamePiece1BPClass.Class);
    Assets->Add(FName(TEXT("Piece2")), GamePiece2BPClass.Class);
    Assets->Add(FName(TEXT("Piece3")), GamePiece3BPClass.Class);
    Assets->Add(FName(TEXT("Piece4")), GamePiece4BPClass.Class);
    Assets->Add(FName(TEXT("Piece5")), GamePiece5BPClass.Class);

    entt::ServiceLocator<entt::DefaultRegistry>::set();

    Systems = std::make_unique<GameSystems>();
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

    entt::DefaultRegistry &Registry = entt::ServiceLocator<entt::DefaultRegistry>::ref();

    Systems->Initialize(Registry);

    auto ViewContainer = GetWorld()->SpawnActor<AViewContainer>(AViewContainer::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);

    Registry.attach<AssetLibraryComponent>(Registry.create(), Assets);
    Registry.attach<ViewContainerComponent>(Registry.create(), ViewContainer);
    Registry.attach<WorldComponent>(Registry.create(), GetWorld());
}

void AMatchOneEnttPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    entt::DefaultRegistry &Registry = entt::ServiceLocator<entt::DefaultRegistry>::ref();

    if (IsInputKeyDown(EKeys::LeftMouseButton))
    {
        if (Registry.has<BurstModeComponent>())
        {
            CheckHit();
        }
    }

    Systems->Update(Registry);
}

void AMatchOneEnttPlayerController::BeginDestroy()
{
    Super::BeginDestroy();

    entt::ServiceLocator<entt::DefaultRegistry>::reset();
}

void AMatchOneEnttPlayerController::OnClick()
{
    CheckHit();
}

void AMatchOneEnttPlayerController::OnPressedB()
{
    entt::DefaultRegistry &Registry = entt::ServiceLocator<entt::DefaultRegistry>::ref();

    if (Registry.has<BurstModeComponent>())
    {
        Registry.remove<BurstModeComponent>();
    }
    else
    {
        Registry.attach<BurstModeComponent>(Registry.create());
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

            entt::DefaultRegistry &Registry = entt::ServiceLocator<entt::DefaultRegistry>::ref();
            Registry.create(UserInputComponent{ int(Location.Y / 125.0f), int(Location.Z / 125.0f) });
        }
    }
}
