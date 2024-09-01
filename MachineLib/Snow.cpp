/**
 * @file Snow.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Snow.h"

/// Gravity in pixels per second per second
const float Gravity = 15;

/**
 * Constructor
 * @param v velocity
 * @param p position
 * @param delta time step
 */
Snow::Snow(wxPoint2DDouble v, wxPoint2DDouble p, double delta)
{
    mV = v;
    mP = p;

}

/**
 * Update location of snow object
 * @param delta
 */
void Snow::Update(double delta)
{
    mV = wxPoint2DDouble(mV.m_x, mV.m_y + Gravity * delta);
    mP = wxPoint2DDouble(mP.m_x + mV.m_x * delta, mP.m_y + mV.m_y * delta);
}

/**
 * Draw snow object
 * @param graphics
 * @param x
 */
void Snow::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x)
{
    if (mYellow)
    {
        wxBrush brush(*wxYELLOW);
        graphics->SetBrush(brush);
        graphics->SetPen(*wxYELLOW);
        graphics->DrawRectangle((int)mP.m_x + x + 50, (int)mP.m_y, 2, 2);
    }
    else
    {
        wxBrush brush(*wxWHITE);
        graphics->SetBrush(brush);
        graphics->SetPen(*wxWHITE);
        graphics->DrawRectangle((int)mP.m_x + x + 50, (int)mP.m_y, 2, 2);
    }

}

