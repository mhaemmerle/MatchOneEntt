#pragma once

#include "UObject/Interface.h"
#include "ScoreListener.generated.h"

UINTERFACE()
class MATCHONEENTT_API UScoreListener : public UInterface
{
    GENERATED_BODY()
};

class MATCHONEENTT_API IScoreListener
{
    GENERATED_BODY()

public:
    virtual void OnScore(int32 Score) = 0;
};
