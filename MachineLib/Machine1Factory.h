/**
 * @file Machine1Factory.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE1FACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE1FACTORY_H

class Machine;
class Shape;
/**
 * Factory for machine 1
 */
class Machine1Factory
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;
    /// Path to images directory
    std::wstring mImagesDir;

    /// Machine system for factory
    MachineSystem* mMachineSystem = nullptr;


public:
    Machine1Factory(std::wstring resourcesDir);

    std::shared_ptr<Machine> Create(std::wstring imagesDir);

    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColour color, std::wstring num);


    /**
     * Set the machine system
     * @param machineSystem
     */
    void SetMachineSystem(MachineSystem* machineSystem) {mMachineSystem = machineSystem;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE1FACTORY_H
