/**
 * @file MotionSource.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H

#include "Component.h"

class MotionSink;

/**
 * Our class to represent sources of motion
 */
class MotionSource
{
private:
    /// This source's component
    Component* mComponent;
    /// This source's sink
    MotionSink* mSink;


public:
    MotionSource() {}
    /// Copy constructor (disabled)
    MotionSource(const MotionSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const MotionSource &) = delete;

    void AddSink(MotionSink* sink);

    /**
     * Get sink for this source
     * @return
     */
    MotionSink* GetSink() {return mSink;}

    void SetRotation(double);

    /**
     * Set component for this source
     * @param component
     */
    void SetComponent(Component* component) {mComponent = component;}

    /**
     * Get component for this source
     * @return
     */
    Component* GetComponent() {return mComponent;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTIONSOURCE_H
