/**
 * @file MotionSource.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "MotionSource.h"
#include "MotionSink.h"

/**
 * Set the rotation on the source's sink
 * @param rotation
 */
void MotionSource::SetRotation(double rotation)
{
    mSink->SetRotation(rotation);
}

/**
 * Add the sink for this source
 * @param sink
 */
void MotionSource::AddSink(MotionSink *sink)
{
    mSink = sink;
    mSink->SetSource(this);
}
