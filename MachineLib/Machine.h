/**
 * @file Machine.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE_H

#include "Component.h"

class MachineSystem;

/**
 * Class to represent our machine
 */
class Machine
{
private:
    /// Start frame
    int mStartFrame = 0;
    /// elapsed time
    double mElapsed = 0;
    /// current frame
    int mCurrentFrame = 0;
    /// Machine number
    int mMachineNum = 0;

    /// Machine System
    MachineSystem* mMachineSystem = nullptr;

    /// Components of our machine
    std::vector<std::shared_ptr<Component>> mComponents;
public:
    /**
     * Constructor
     * @param machineNum
     */
    Machine(int machineNum) : mMachineNum(machineNum) {};

    /**
     * Set component to our machine
     * @param component to be set
     */
    void SetComponent(std::shared_ptr<Component> component) {mComponents.push_back(component);}

    /**
     * Reset machine
     */
    void Reset() {};

    /**
     * Set time on machine
     * @param time in seconds
     */
    void SetTime(double time) {mElapsed = time;}

    /**
     * Get elapsed time on machine
     * @return
     */
    double GetTime() {return mElapsed;}

    /**
     * Update this machine
     * @param elapsed time
     */
    void Update(double elapsed);


    void Draw(std::shared_ptr<wxGraphicsContext>);

    /**
     * Advance frame on machine
     * @param frame
     */
    void Advance(double frame);

    /**
     * Set the machine system
     * @param machineSystem
     */
    void SetMachineSystem(MachineSystem* machineSystem) {mMachineSystem = machineSystem;}

    /**
     * Get the machine system
     * @return
     */
    MachineSystem* GetMachineSystem() {return mMachineSystem;}


};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE_H
