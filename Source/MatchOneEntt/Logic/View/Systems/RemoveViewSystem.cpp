#include "MatchOneEntt.h"
#include "RemoveViewSystem.h"
#include "Components/ViewComponent.h"
#include "Components/DestroyedComponent.h"

void RemoveViewSystem::Initialize(entt::DefaultRegistry &Registry)
{
    Registry.prepare<ViewComponent, DestroyedComponent>();
}

void RemoveViewSystem::Update(entt::DefaultRegistry &Registry)
{
    auto View = Registry.persistent<ViewComponent, DestroyedComponent>();

    //    return HasView(entity);

    for (auto Entity : View)
    {
        auto &ViewComp = Registry.get<ViewComponent>(Entity);
        ViewComp.Value->Destroy();

        //var gameObject = viewComponent.gameObject;
        //var spriteRenderer = gameObject.GetComponent<SpriteRenderer>();
        //var color = spriteRenderer.color;
        //color.a = 0f;
        //spriteRenderer.material.DOColor(color, 0.2f);
        //gameObject.transform
        //    .DOScale(Vector3.one * 1.5f, 0.2f)
        //    .OnComplete(() = > {
        //    gameObject.Unlink();
        //    Object.Destroy(gameObject);
        //});

        Registry.remove<ViewComponent>(Entity);
    }
}
