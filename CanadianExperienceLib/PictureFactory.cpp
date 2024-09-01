/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 * @author CJ Nwogu
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "BallFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawableFactory.h"
#include "MachineDrawable.h"

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();


    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
        std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    auto machine = std::make_shared<Actor>(L"Machine");
    machine->SetClickable(true);
    machine->SetPosition(wxPoint(350, 300));

    auto machineD = std::make_shared<MachineDrawable>(L"Machine", resourcesDir);
    machineD->SetStart(150);
    machineD->SetMachineNumber(1);
    machine->AddDrawable(machineD);
    machine->SetRoot(machineD);
    picture->AddActor(machine);

    auto machine2 = std::make_shared<Actor>(L"Machine");
    machine2->SetClickable(true);
    machine2->SetPosition(wxPoint(600, 300));

    auto machineD2 = std::make_shared<MachineDrawable>(L"Machine", resourcesDir);
    machineD2->SetMachineNumber(2);
    machineD2->SetStart(450);
    machine2->AddDrawable(machineD2);
    machine2->SetRoot(machineD2);
    picture->AddActor(machine2);


    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 620));
    picture->AddActor(sparty);

    // Create and  add Ball
    BallFactory ballFactory;
    auto  ball = ballFactory.Create(imagesDir);

    ball->SetPosition(wxPoint(700, 630));
    picture->AddActor(ball);


    return picture;
}


