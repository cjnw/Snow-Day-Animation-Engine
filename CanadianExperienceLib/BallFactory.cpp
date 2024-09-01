/**
 * @file BallFactory.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "BallFactory.h"
#include "ImageDrawable.h"
#include "Actor.h"

/**
 * Create our ball actor
 * @param imagesDir
 * @return
 */
std::shared_ptr <Actor> BallFactory::Create(std::wstring imagesDir)
{
    std::shared_ptr<Actor> actor = std::make_shared<Actor>(L"BasketBall");

    auto basketball = std::make_shared<ImageDrawable>(L"ball",imagesDir + L"/basketball1.png");
    basketball->SetCenter(wxPoint(400, 144));
    basketball->SetPosition(wxPoint(0, -200));
    actor->SetRoot(basketball);

    actor->AddDrawable(basketball);

    return actor;
}

