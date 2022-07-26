#pragma once
#include "PlacableActor.h"
class Life : public PlacableActor
{
public:
    Life(int x, int y) :
        PlacableActor(x, y) 
    {

    }

    virtual ActorType GetType() override { return ActorType::Life; }
    virtual void Draw() override;
};

