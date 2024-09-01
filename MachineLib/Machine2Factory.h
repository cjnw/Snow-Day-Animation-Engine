/**
 * @file Machine2Factory.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H

#include "MachineSystem.h"

class Machine;
class Shape;


/**
 * Factory for machine 2
 */
class Machine2Factory
{
private:
    /// Path to the resources directory
    std::wstring mResourcesDir;
    /// Path to images directory
    std::wstring mImagesDir;

    /// Machine system for factory
    MachineSystem* mMachineSystem = nullptr;


public:
    Machine2Factory(std::wstring resourcesDir);

    /**
     * Create machine 2
     * @param imagesDir
     * @return
     */
    std::shared_ptr<Machine> Create(std::wstring imagesDir);

    /**
     * Create a post
     * @param x
     * @param y
     * @param wid
     * @param hit
     * @param color
     * @param num
     * @return
     */
    std::shared_ptr<Shape> CreatePost(int x, int y, int wid, int hit, wxColour color, std::wstring num);

    /**
     * Set machine system
     * @param machineSystem
     */
    void SetMachineSystem(MachineSystem* machineSystem) {mMachineSystem = machineSystem;}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINE2FACTORY_H
