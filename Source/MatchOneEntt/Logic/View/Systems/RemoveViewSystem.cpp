#include "RemoveViewSystem.h"
#include "Components/ViewComponent.h"
#include "Components/DestroyedComponent.h"

void RemoveViewSystem::Initialize(entt::registry& Registry) {}

void RemoveViewSystem::Update(entt::registry& Registry)
{
    auto View = Registry.view<ViewComponent, DestroyedComponent>();

    for (auto Entity : View)
    {
        auto& ViewComp = View.get<ViewComponent>(Entity);
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
