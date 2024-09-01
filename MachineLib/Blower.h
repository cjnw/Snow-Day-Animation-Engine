/**
 * @file Blower.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_BLOWER_H
#define CANADIANEXPERIENCE_MACHINELIB_BLOWER_H

#include <random>
#include "MotionSink.h"
#include "Polygon.h"
#include "Snow.h"

/// Width of the snow blower in pixels
const int SnowBlowerWidth = 120;

/// Height of the snow blower in pixels
const int SnowBlowerHeight = 174;

/// Y offset to the center of the snow blower in pixels
const int SnowBlowerCenterOffset = 60;

/**
 * Class to represent our snowblower
 */
class Blower : public Component
{
private:
    /// Random number generator
    std::mt19937 mRandom;

    /// Blower as a sink
    MotionSink mSink;

    /// Snow list
    std::list<std::shared_ptr<Snow>> mSnowFlakes;

    /// Time step
    double mDelta=0.0;


    /// Angle of blower oscilation
    double mOscilation=0;

public:
    /** Copy constructor disabled */
    Blower(const Blower &) = delete;
    /** Assignment operator disabled */
    void operator=(const Blower &) = delete;

    /**
     * Constructor
     * @param name
     */
    Blower(const std::wstring& name) : Component(name)
    {
        std::random_device rd;
        mRandom.seed(rd());
        mSink.SetComponent(this);

        auto blowerPoly = std::make_shared<cse335::Polygon>();
        this->SetPolygon(blowerPoly);
        GetImage()->Rectangle(-SnowBlowerWidth / 2, SnowBlowerCenterOffset, SnowBlowerWidth, SnowBlowerHeight);
    }

    /**
     * Get this blower's sink
     * @return
     */
    MotionSink* GetSink() {return &mSink;}

    void Draw(std::shared_ptr<wxGraphicsContext>, int, int)override;
    void SetImage(const std::wstring&)override;
    void SetRotation(double rotation)override;
    double Random(double fmValue, double toValue);

    /**
     * Append  snow to our collection
     * @param flake
     */
    void AddSnow(std::shared_ptr<Snow> flake) {mSnowFlakes.push_back(flake);};

    void MakeSnow();

    void Advance(double delta)override;
    void Update(double)override;

};

#endif //CANADIANEXPERIENCE_MACHINELIB_BLOWER_H
