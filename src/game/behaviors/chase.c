#include "chase.h"
#include "player.h"

static uint8 updateChase(Updateable* who, World* world)
{
    int16 diff;
    int16 threshold = 5;
    Chase* c = who->behavior;

    who->position.y += c->vertSpeed;

    if (spriteTop(world->player) > spriteBottom(who))
    {
        diff = spriteCenter(world->player).x - spriteCenter(who).x;

        if (diff > threshold)
            who->position.x += c->horizSpeed;
        else if (diff < -threshold)
            who->position.x -= c->horizSpeed;
    }

    if (c->vertSpeed > 0)
    {
        //
        // heading downscreen
        //
        if (spriteTop(who) > SCREEN_HEIGHT)
            return UPDATE_REMOVE;
    }
    else
    {
        //
        // heading upscreen
        //
        if (spriteBottom(who) < 0)
            return UPDATE_REMOVE;
    }

    return UPDATE_KEEP;
}

Chase* createChase(int8 vertSpeed, int8 horizSpeed)
{
    Chase* c = new(Chase);
    c->destroy = nullDestroy;
    c->update = updateChase;
    c->vertSpeed = vertSpeed;
    c->horizSpeed = horizSpeed;

    return c;
}
