/**
 * @file MachineDrawableFactory.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "MachineDrawableFactory.h"
#include "MachineDrawable.h"
#include "Actor.h"

/**
 * Create machine drawable
 * @param resourcesDir
 * @return
 */
std::shared_ptr <Actor> MachineDrawableFactory::Create(std::wstring resourcesDir)
{
    std::shared_ptr<Actor> actor = std::make_shared<Actor>(L"Machine");

    auto machine = std::make_shared<MachineDrawable>(L"machine",resourcesDir);
    machine->SetPosition(wxPoint(0, -200));
    actor->SetRoot(machine);

    actor->AddDrawable(machine);

    return actor;
}
