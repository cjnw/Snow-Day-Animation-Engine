/**
 * @file Blower.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Blower.h"
#include "Machine.h"
#include "MachineSystem.h"

/// The spread of the snow blower oscillations
const double SnowBlowerOscillationSpread = 1.0;

/// Average amount of snow created per rotation
const double SnowPerRotation = 1000;

/// Variance in how much snow is created
const double SnowVariancePerSecond = 100;

/// Range of the random angle snow will be thrown in
const double SnowAngleVariance = 0.1;

/// Angle range for the end of the snow machine in radians.
const double SnowMachineAngleRange = 0.25;

/// Offset to end of snow blower from middle in pixels
const double SnowBlowerOffset = 100;

/// Random variance in the snowblower offset
const double SnowBlowerOffsetVariance = 5;

/// Minimum snow particle velocity
const double SnowMinimumVelocity = 90;

/// Maximum snow particle velocity
const double SnowMaximumVelocity = 110;

// Compute how much snow to generate for this amount of rotation.
//auto num = (int)(rotation * (SnowPerRotation + Random(-SnowVariancePerSecond, SnowVariancePerSecond)));

/**
 * Draw this blower
 * @param graphics graphics context
 * @param x x-position
 * @param y y-position
 */
void Blower::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if (GetImage()->GetRotation() != 0)
    {
        for (auto flake : mSnowFlakes)
        {
            double prob = Random(0.0,1.0);

            if (prob <= 0.01)
            {
                flake->Draw(graphics,x);
            }
            else
            {
                flake->Draw(graphics,x);
            }
        }
    }
    GetImage()->DrawPolygon(graphics,x,y);

}

/**
 * Set this image
 * @param name
 */
void Blower::SetImage(const std::wstring &name)
{
    GetImage()->SetImage(name);
}

/**
 * Set rotation on blower
 * @param rotation
 */
void Blower::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    MakeSnow();

}

/**
 * Add snow
 */
void Blower::MakeSnow()
{
    // Compute how much snow to generate for this amount of rotation.
    auto num = (int)((mSink.GetSource()->GetComponent()->GetRotation()) * (Random(-SnowVariancePerSecond, SnowVariancePerSecond)));
    num = num*0.01;
    for (int i=0; i < num; i++)
    {
        // GetRotation gets the rotation of the snow machine.
        // This code computes a vector to the emitting end of the
        // snow machine. The random value means that position is over
        // the entire end of the machine, not just a single point.

        double angle = 0.0;

        if (GetName() == L"Blower")
        {
            angle = -.15 * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
        }
        else
        {
            angle = .15 * 2 * M_PI + Random(-SnowMachineAngleRange, SnowMachineAngleRange);
        }

        auto dx = sin(angle);
        auto dy = -cos(angle);


        auto angle1 = angle + Random(-SnowAngleVariance, SnowAngleVariance);
        auto dx1 = sin(angle1);
        auto dy1 = -cos(angle1);

        double offset = SnowBlowerOffset + Random(-SnowBlowerOffsetVariance, SnowBlowerOffsetVariance);
        double velocity = Random(SnowMinimumVelocity, SnowMaximumVelocity);


        wxPoint2DDouble snowPosition((float)(GetPosition().x+dx * offset), (float)(GetPosition().y+dy * offset));
        wxPoint2DDouble snowVelocity((float)(dx1 * velocity), (float)(dy1 * velocity));
        auto flake = std::make_shared<Snow>(snowVelocity, snowPosition, mDelta);

        double prob = Random(0.0,1.0);

        if (prob <= 0.01)
        {
            flake->SetColor(true);
        }

        mSnowFlakes.push_back(flake);
    }
}


/**
 * Generate a uniform distribution random number from fmValue to toValue
 * @param fmValue Minimum value to generate
 * @param toValue Maximum value to generate
 * @return Random number
 */
double Blower::Random(double fmValue, double toValue)
{
    std::uniform_real_distribution<> distribution(fmValue, toValue);
    return distribution(mRandom);
}

/**
 * Advance the frame on our blower
 * @param delta
 */
void Blower::Advance(double delta)
{
    MakeSnow();
    Component::Advance(delta);
    auto it = mSnowFlakes.begin();
    while (it != mSnowFlakes.end())
    {
        auto flake = *it;
        if ((flake->GetP().m_y > 200) || (flake->GetP().m_x < -900))
        {
            it = mSnowFlakes.erase(it); // erase returns the iterator to the next valid element
        }
        else
        {
            flake->Update(delta);
            ++it; // move to the next element
        }
    }

    mDelta = delta;
}

/**
 * Update blower
 * @param elapsed
 */
void Blower::Update(double elapsed)
{

}
