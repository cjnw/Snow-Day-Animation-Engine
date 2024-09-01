/**
 * @file Motor.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
#define CANADIANEXPERIENCE_MACHINELIB_MOTOR_H

#include <memory>
#include "Polygon.h"
#include "Component.h"
#include "MotionSource.h"

/**
 * Class to represent our motor
 */
class Motor : public Component
{
private:
    /// Image to support rotor
    std::shared_ptr<cse335::Polygon> mBody=nullptr;
    /// Rotor speed
    double mSpeed=1;
    /// Rotation source for this component
    MotionSource mSource;
public:
    /**
     * Constructor
     * @param name
     */
    Motor(const std::wstring& name) : Component(name) {mSource.SetComponent(this);}
    void Draw(std::shared_ptr<wxGraphicsContext>, int, int)override;
    void SetImage(const std::wstring&)override;

    /**
     * Set the motor's body not shaft
     * @param body
     */
    void SetBody(std::shared_ptr<cse335::Polygon> body) {mBody = body;}

    /**
     * Get body of motor
     * @return
     */
    std::shared_ptr<cse335::Polygon> GetBody() {return mBody;}


    void SetBodyImage(const std::wstring &);

    /**
     * Set speed of motor
     * @param speed
     */
    void SetSpeed(double speed) {mSpeed = speed;}
    void SetTime(double time)override;

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    MotionSource *GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MOTOR_H
