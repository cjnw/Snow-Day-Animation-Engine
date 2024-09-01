/**
 * @file Shape.h
 * @author CJ Nwogu
 *
 * Class to represent shapes
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
#define CANADIANEXPERIENCE_MACHINELIB_SHAPE_H

#include "Component.h"
#include "MotionSink.h"

/**
 * Class to represent shapes
 */
class Shape : public Component
{
private:
    /// The motion sink for this component
    MotionSink mSink;


public:
    /**
     * Constructor
     * @param name
     */
    Shape(const std::wstring& name) : Component(name) {mSink.SetComponent(this);}

    /**
     * Get this shapes sink
     * @return
     */
    MotionSink *GetSink() {return &mSink;}

    void Draw(std::shared_ptr<wxGraphicsContext>, int, int)override;
    void SetImage(const std::wstring& name)override;
    void SetRotation(double)override;



};

#endif //CANADIANEXPERIENCE_MACHINELIB_SHAPE_H
