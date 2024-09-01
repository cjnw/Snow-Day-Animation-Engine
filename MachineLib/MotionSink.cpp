/**
 * @file MotionSink.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "MotionSink.h"
#include "Component.h"

/**
 * Set rotation on this sink
 * @param motion
 */
void MotionSink::SetRotation(double motion)
{
    mComponent->SetRotation(motion);
}

/**
 * Set component for this sink
 * @param component
 */
void MotionSink::SetComponent(Component *component)
{
    mComponent = component;
}

