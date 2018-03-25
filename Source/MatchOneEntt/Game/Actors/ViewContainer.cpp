#include "MatchOneEntt.h"
#include "ViewContainer.h"

AViewContainer::AViewContainer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = true;

    auto SceneComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("SceneComponent"));
    SceneComponent->SetMobility(EComponentMobility::Static);

    RootComponent = SceneComponent;
}
