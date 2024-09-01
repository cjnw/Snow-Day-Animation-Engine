/**
 * @file Pulley.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
#define CANADIANEXPERIENCE_MACHINELIB_PULLEY_H

#include "Component.h"
#include "MotionSink.h"
#include "MotionSource.h"

/**
 * Class to represent the pulley
 */
class Pulley : public Component
{
private:
    /// Pulley's radius
    double mRadius = 0.0;
    ///  Pulley's child
    std::shared_ptr<Pulley> mChild= nullptr;
    /// Pulley's parent
    std::shared_ptr<Pulley> mParent = nullptr;
    /// Pulley as source
    MotionSource mSource;
    /// Pulley as a sink
    MotionSink mSink;

public:
    /** Copy constructor disabled */
    Pulley(const Pulley &) = delete;
    /** Assignment operator disabled */
    void operator=(const Pulley &) = delete;

    /**
     * Constructor
     * @param name of pulley
     */
    Pulley(const std::wstring& name) : Component(name) {mSink.SetComponent(this); mSource.SetComponent(this);}

    void Draw(std::shared_ptr<wxGraphicsContext>, int, int)override;

    void Belt(std::shared_ptr<wxGraphicsContext>);

    /**
     * Get sink of pulley
     * @return
     */
    MotionSink* GetSink() {return &mSink;}

    /**
     * Get source of pulley
     * @return
     */
    MotionSource* GetSource() {return &mSource;}

    /**
     * Set pulley radius
     * @param radius
     */
    void SetRadius(double radius) {mRadius = radius;}

    /**
     * Get radius
     * @return
     */
    double GetRadius() {return mRadius;}

    /**
     * Set pulley's child
     * @param child
     */
    void SetChild(std::shared_ptr<Pulley> child) {mChild = child;}

    /**
     * Set pulley's parent
     * @param parent
     */
    void SetParent(std::shared_ptr<Pulley> parent) {mParent = parent;}

    void SetRotation(double)override;
    void SetImage(const std::wstring& name)override;
    void Update(double)override;
};

#endif //CANADIANEXPERIENCE_MACHINELIB_PULLEY_H
