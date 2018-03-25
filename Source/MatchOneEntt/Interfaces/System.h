#pragma once

#include "entt.hpp"

class ISystem
{
protected:
    ISystem() {};
    ISystem(const ISystem&) = default;
    ISystem& operator=(const ISystem&) = default;

public:
    virtual ~ISystem() = default;
};

class IInitializeSystem
{
protected:
    IInitializeSystem() {};

public:
    virtual ~IInitializeSystem() = default;

    virtual void Initialize(entt::DefaultRegistry &Registry) = 0;
};

class IUpdateSystem
{
protected:
    IUpdateSystem() {};

public:
    virtual ~IUpdateSystem() = default;

    virtual void Update(entt::DefaultRegistry &Registry) = 0;
};
