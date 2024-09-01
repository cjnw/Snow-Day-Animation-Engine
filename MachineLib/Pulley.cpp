/**
 * @file Pulley.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Pulley.h"

/**
 * Draw this pulley
 * @param graphics context
 * @param x position
 * @param y position
 */
void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if (mChild)
    {
        Belt(graphics);
    }
    else if (!mSource.GetComponent())
    {
        Belt(graphics);
    }

    GetImage()->DrawPolygon(graphics,x,y);

}

/**
 * Set the image of this pulley
 * @param name
 */
void Pulley::SetImage(const std::wstring &name)
{
    GetImage()->SetImage(name);

}

/**
 * Set rotation of pulley
 * @param rotation
 */
void Pulley::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    GetImage()->SetRotation(rotation);



}

/**
 * Update this pulley
 */
void Pulley::Update(double)
{
    if (mParent)
    {
        SetRotation((mParent->GetRadius()/mRadius)*mParent->GetRotation());
    }
}

/**
 * Draw belt to pulley's child
 * @param graphics
 */
void Pulley::Belt(std::shared_ptr<wxGraphicsContext> graphics)
{
    if (!mSource.GetComponent())
    {

    }

    auto x2 = mChild->GetPosition().x;
    auto y2 = mChild->GetPosition().y;
    auto r2 = mChild->GetRadius()-3;

    auto x1 = GetPosition().x;
    auto y1 = GetPosition().y;
    auto r1 = GetRadius()-3;


    auto theta = atan2(y2-y1,x2-x1);

    auto mag = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    auto msin = (r2-r1)/ mag;
    auto phi = asin(msin);

    auto beta = theta + phi + (M_PI/2);

    /// Line 1
    wxPoint2DDouble  pt1 = wxPoint2DDouble(r1* cos(beta)+x1, r1 * sin(beta)+y1);
    wxPoint2DDouble pt2 = wxPoint2DDouble(r2* cos(beta)+x2, r2*sin(beta)+y2);

    graphics->SetPen(*wxBLACK_PEN);
    graphics->StrokeLine(pt1.m_x,pt1.m_y,pt2.m_x,pt2.m_y);

    auto beta2 = theta - phi - M_PI/2;

    /// Line 2
    wxPoint2DDouble pt1b = wxPoint2DDouble(r1* cos(beta2)+x1, r1 * sin(beta2)+y1);
    wxPoint2DDouble pt2b = wxPoint2DDouble(r2* cos(beta2)+x2, r2*sin(beta2)+y2);
    graphics->StrokeLine(pt1b.m_x,pt1b.m_y,pt2b.m_x,pt2b.m_y);

}





