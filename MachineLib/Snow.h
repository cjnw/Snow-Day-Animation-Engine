/**
 * @file Snow.h
 * @author CJ Nwogu
 *
 * Class to represent snow
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SNOW_H
#define CANADIANEXPERIENCE_MACHINELIB_SNOW_H

#include "Component.h"

/**
 * Class to represent snow
 */
class Snow
{
private:
    /// Snow velocity
    wxPoint2DDouble mV;

    /// Snow position
    wxPoint2DDouble mP;

    /// Color
    bool mYellow = false;
public:
    Snow(wxPoint2DDouble v, wxPoint2DDouble p, double );

    /**
     * Get velocity of snow
     * @return
     */
    wxPoint2DDouble GetV() {return mV;}

    /**
     * Get position of snow
     * @return
     */
    wxPoint2DDouble GetP() {return mP;}


    void Update(double delta);

    /**
     * Set this snow flake's color
     * @param color
     */
    void SetColor(bool color) {mYellow = color;}

    void Draw(std::shared_ptr<wxGraphicsContext>, int);

};

#endif //CANADIANEXPERIENCE_MACHINELIB_SNOW_H
