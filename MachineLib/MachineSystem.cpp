/**
 * @file MachineSystem.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Machine.h"
#include "MachineSystem.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"

/**
* Draw the machine at the currently specified location
* @param graphics Graphics object to render to
*/
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    // This will put the machine where it is supposed to be drawn
    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);
    mMachine->Draw(graphics);

//    // Just get something on the screen, this draws a simple crosshair
//    graphics->SetPen(*wxRED_PEN);
//    graphics->StrokeLine(-20, 0, 20, 0);
//    graphics->StrokeLine(0, -20, 0, 20);



    graphics->PopState();
}

/**
 * Set the machine number, creating the appropriate machine
 * @param machine Machine number
 */
void MachineSystem::SetMachineNumber(int machine)
{
    if(machine == 1)
    {
        Machine1Factory mac1Fac(mResourcesDir);
        mac1Fac.SetMachineSystem(this);
        auto machine = mac1Fac.Create(mResourcesDir);
        mMachine = machine;
        SetMachine(mMachine);
    }
    else
    {
        Machine2Factory mac2Fac(mResourcesDir);
        mac2Fac.SetMachineSystem(this);
        auto machine = mac2Fac.Create(mResourcesDir);
        mMachine = machine;
        SetMachine(mMachine);
    }
    mMachine->SetMachineSystem(this);
}

/**
 * Constructor
 * @param resources
 */
MachineSystem::MachineSystem(std::wstring resources)
{
    mResourcesDir = resources;
    SetMachineNumber(1);
    SetMachineNumber(2);
}

/**
 * Set this system's machine
 * @param machine
 */
void MachineSystem::SetMachine(std::shared_ptr<Machine> machine)
{
    mMachine =  machine;
    mMachine->SetMachineSystem(this);
}


void MachineSystem::SetMachineFrame(int frame)
{
    mMachineTime = frame / mFrameRate;
    mMachine->SetTime(mMachineTime);

    if (frame < mCurrentFrame)
    {
        // Reset();
        mCurrentFrame = frame;
    }

    while (mCurrentFrame < frame) {
        // Advance one frame
        mCurrentFrame++;
        Advance( 1.0 / mFrameRate);
    }
}
