/**
 * @file MotionSink.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTIONSINK_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTIONSINK_H

#include "MotionSource.h"

class Component;

/**
 * Class to represent our motion sinks
 */
class MotionSink
{
private:
    /// This sink's component
    Component* mComponent= nullptr;
    /// This sink's source
    MotionSource* mSource;


public:
    MotionSink(){}

    void SetRotation(double motion);
    void SetComponent(Component* component);

    /**
     * Set source for this sink
     * @param source
     */
    void SetSource(MotionSource* source) {mSource = source;};

    /**
     * Get source for this sink
     * @return
     */
    MotionSource* GetSource() {return mSource;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTIONSINK_H
