/**
 * @file Machine.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Machine.h"
#include "MachineSystem.h"


/**
 * Draw this machine
 * @param graphics graphics context
 */
void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics,component->GetPosition().x,component->GetPosition().y);
        component->Update(mElapsed);
    }
}


void Machine::Advance(double frame)
{
    for (auto component : mComponents)
    {
        component->Advance(frame);
    }
}


void Machine::Update(double elapsed)
{
    for(auto component : mComponents)
    {
        component->Update(elapsed);
    }
}
