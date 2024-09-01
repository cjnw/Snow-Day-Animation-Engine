/**
 * @file Machine2Factory.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Machine2Factory.h"
#include "Shape.h"
#include "Blower.h"
#include "Motor.h"
#include "Pulley.h"

using namespace std;

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
Machine2Factory::Machine2Factory(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}


std::shared_ptr<Machine> Machine2Factory::Create(std::wstring imagesDir)
{
    // The machine itself
    auto machine = std::make_shared<Machine>(2);
    machine->SetMachineSystem(mMachineSystem);

    const int BaseWidth = 325;  // Width of the base
    const int BaseHeight = 40;  // Height of the base

    const int MotorX = 20;	// Motor X location
    const int Post1X = -70;	// Post X location
    const int Post2X = 80;	// Second post X location

    int Post1Height = 120;
    int Post2Height = 200;

    //
    // The blower
    //
    auto blower = make_shared<Blower>(L"BlowerR");

    blower->SetImage(mImagesDir + L"/blowerR.png");
    blower->SetInitialPos(wxPoint(Post1X,-38-430/2));

    machine->SetComponent(blower);
    blower->SetMachine(machine);
    blower->GetImage()->SetRotation(.15);

    //
    // Post 1
    //
    //
    auto post1 = CreatePost(Post1X, -40, 20, Post1Height, wxColour(10,10,10), L"1");
    machine->SetComponent(post1);

    //
    // Post 2
    //
    auto post2 = CreatePost(Post2X, -40, 20, Post2Height, wxColor(10, 10, 10), L"2");
    machine->SetComponent(post2);

    //
    // Post 3
    //
    auto post3 = CreatePost(Post1X, -90, 20, Post2Height, wxColor(10, 10, 10), L"2");
    machine->SetComponent(post3);


    //
    // The base
    //
    auto base = std::make_shared<Shape>(L"Base");
    auto basePoly = std::make_shared<cse335::Polygon>();

    base->SetPolygon(basePoly);

    base->GetImage()->Rectangle(int(-BaseWidth/2), 0, BaseWidth, BaseHeight);
    base->SetImage(mImagesDir + L"/base.png");

    machine->SetComponent(base);
    base->SetMachine(machine);

    //
    // The motor
    //
    auto motor =  std::make_shared<Motor>(L"Motor");
    auto motorShaft = std::make_shared<cse335::Polygon>();
    auto motorBody = std::make_shared<cse335::Polygon>();

    motor->SetBody(motorBody);
    motor->SetPolygon(motorShaft);

    motor->SetInitialPos(wxPoint(MotorX, -38));

    motor->GetBody()->Rectangle(MotorX,motor->GetPosition().y,80,80);
    motor->SetBodyImage(mImagesDir + L"/motor2.png");


    motor->GetImage()->CenteredSquare(25);
    motor->SetImage(mImagesDir + L"/shaft.png");

    motor->SetSpeed(1.0);
    motor->SetInitialPos(wxPoint(MotorX,motor->GetPosition().y));

    machine->SetComponent(motor);
    motor->SetMachine(machine);

    //
    // Pulley 1
    //
    auto pulley = make_shared<Pulley>(L"Pulley");
    auto pulleyPoly = make_shared<cse335::Polygon>();

    pulley->SetPolygon(pulleyPoly);
    pulley->SetRadius(50);

    pulley->GetImage()->CenteredSquare(50);
    pulley->SetImage(mImagesDir + L"/pulley.png");
    pulley->SetInitialPos(wxPoint(Post1X, -38 - 90 / 2));
    pulley->GetImage()->SetPhase(0.1);

    machine->SetComponent(pulley);
    pulley->SetMachine(machine);

    motor->GetSource()->AddSink(pulley->GetSink());
    pulley->GetSink()->SetSource(motor->GetSource());


    //
    // pulley 2
    //
    auto pulley2 = make_shared<Pulley>(L"Pulley2");
    auto pulleyPoly2 = make_shared<cse335::Polygon>();

    pulley2->SetPolygon(pulleyPoly2);
    pulley2->SetRadius(45);

    pulley2->GetImage()->CenteredSquare(pulley2->GetRadius());
    pulley2->SetImage(mImagesDir + L"/pulley.png");
    pulley2->SetInitialPos(wxPoint(Post2X, -38 - 210 / 2));
    pulley2->GetImage()->SetPhase(0.2);

    machine->SetComponent(pulley2);
    pulley2->SetMachine(machine);

    pulley->SetChild(pulley2);
    pulley2->SetParent(pulley);


    //
    // pulley 3
    //
    auto pulley3 = make_shared<Pulley>(L"Pulley3");
    auto pulleyPoly3 = make_shared<cse335::Polygon>();

    pulley3->SetPolygon(pulleyPoly3);
    pulley3->SetRadius(40);

    pulley3->GetImage()->CenteredSquare(pulley3->GetRadius());
    pulley3->SetImage(mImagesDir + L"/pulley.png");
    pulley3->SetInitialPos(wxPoint(Post1X, -38 - 245 / 2));
    pulley3->GetImage()->SetPhase(0.1);

    machine->SetComponent(pulley3);
    pulley3->SetMachine(machine);

    pulley2->SetChild(pulley3);
    pulley3->SetParent(pulley2);


    //
    // pulley 4
    //
    auto pulley4 = make_shared<Pulley>(L"Pulley4");
    auto pulleyPoly4 = make_shared<cse335::Polygon>();

    pulley4->SetPolygon(pulleyPoly4);
    pulley4->SetRadius(35);

    pulley4->GetImage()->CenteredSquare(pulley4->GetRadius());
    pulley4->SetImage(mImagesDir + L"/pulley.png");
    pulley4->SetInitialPos(wxPoint(Post2X, -38 - 350 / 2));
    pulley4->GetImage()->SetPhase(0.1);

    machine->SetComponent(pulley4);
    pulley4->SetMachine(machine);

    pulley3->SetChild(pulley4);
    pulley4->SetParent(pulley3);


    //
    // pulley 5
    //
    auto pulley5 = make_shared<Pulley>(L"Pulley5");
    auto pulleyPoly5 = make_shared<cse335::Polygon>();

    pulley5->SetPolygon(pulleyPoly5);
    pulley5->SetRadius(30);

    pulley5->GetImage()->CenteredSquare(pulley5->GetRadius());
    pulley5->SetImage(mImagesDir + L"/pulley.png");
    pulley5->SetInitialPos(wxPoint(Post1X, -38 - 430 / 2));
    pulley5->GetImage()->SetPhase(0.1);

    machine->SetComponent(pulley5);
    pulley5->SetMachine(machine);

    pulley4->SetChild(pulley5);
    pulley5->SetParent(pulley4);

    pulley5->GetSource()->AddSink(blower->GetSink());

    //
    //  banner
    //
    //auto banner = make_shared<Shape>()

    return machine;
}


std::shared_ptr<Shape> Machine2Factory::CreatePost(int x, int y, int wid, int hit, wxColour color, std::wstring num)
{
    auto post = std::make_shared<Shape>(L"Post" + num);
    auto postPoly = make_shared<cse335::Polygon>();

    post->SetPolygon(postPoly);
    post->GetImage()->Rectangle(-wid/2, 0, wid, hit);
    post->GetImage()->SetColor(color);
    post->SetInitialPos(wxPoint(x,y));

    return post;
}
