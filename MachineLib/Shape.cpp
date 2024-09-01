/**
 * @file Shape.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "Shape.h"

/**
 * Draw this shape
 * @param graphics context
 * @param x position
 * @param y position
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    GetImage()->DrawPolygon(graphics,x,y);
}

/**
 * Set image of this shape
 * @param name filename
 */
void Shape::SetImage(const std::wstring &name)
{
    GetImage()->SetImage(name);

}

/**
 * Set rotation of shape
 * @param rotation
 */
void Shape::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    GetImage()->SetRotation(rotation);
}







