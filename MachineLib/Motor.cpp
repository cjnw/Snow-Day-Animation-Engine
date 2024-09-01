/**
 * @file Motor.cpp
 * @author CJ Nwogu
 */
#include "pch.h"
#include "Motor.h"

/**
 * Draw this motor
 * @param graphics context
 * @param x position
 * @param y position
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    mBody->DrawPolygon(graphics,GetPosition().x,GetPosition().y+38);
    GetImage()->DrawPolygon(graphics,GetPosition().x+60,GetPosition().y-38);

}

/**
 * Set this motor's shaft's image
 * @param name filename
 */
void Motor::SetImage(const std::wstring &name)
{
    GetImage()->SetImage(name);
}

/**
 * Set image of the motor body
 * @param name filename
 */
void Motor::SetBodyImage(const std::wstring &name)
{
    mBody->SetImage(name);
}

/**
 * Set time for motor
 * @param time
 */
void Motor::SetTime(double time)
{
    SetRotation(time*mSpeed);
    GetImage()->SetRotation(GetRotation());
    mSource.SetRotation(GetRotation());

}
