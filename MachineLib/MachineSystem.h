/**
 * @file MachineSystem.h
 * @author CJ Nwogu
 *
 * Class to represent our machine system
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
#define CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H

#include <wx/gdicmn.h>
#include <wx/graphics.h>
#include <memory>
#include "IMachineSystem.h"
#include "Machine.h"

class Polygon;

/**
 * Class to represent our machine system
 */
class MachineSystem : public IMachineSystem
{
private:
    /// System framerate
    double mFrameRate = 30;
    /// System location
    wxPoint mLocation = wxPoint(0,0);
    /// Current  frame
    double mCurrentFrame = 0.0;
    /// Flag
    int mFlag = 0;
    /// Machine number
    int mNumber = 0;
    /// Machine time
    double mMachineTime = 0.0;
    /// Machine object
    std::shared_ptr<Machine> mMachine = nullptr;
    /// Resources path
    std::wstring mResourcesDir;
    /// Snow Frame
    double mSnowFrame;

public:
    MachineSystem(std::wstring resources);
    /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    void SetLocation(wxPoint location) override{mLocation = location;};

    /**
     * Get the location of hte machine
     * @return Location x,y in pixels as a point
     */
    wxPoint GetLocation() override{return mLocation;};

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    void SetMachineFrame(int frame) override;

    /**
     * Set the expected frame rate in frames per second
     * @param rate Frame rate in frames per second
     */
    void SetFrameRate(double rate) override{mFrameRate = rate;};

    void SetMachineNumber(int machine) override;

    /**
     * Get the current machine number
     * @return Machine number integer
     */
    int GetMachineNumber() override{return mNumber;};

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    double GetMachineTime() override{return mMachineTime;};

    /**
     * Set the flag from the control panel
     * @param flag Flag to set
     */
    void SetFlag(int flag) override{mFlag = flag;};

    void SetMachine(std::shared_ptr<Machine>);

    /**
     * Get resources  path
     * @return resources path
     */
     std::wstring GetResources() {return mResourcesDir;}

     /**
      * Advance frame to system
      * @param frame
      */
     void Advance(double frame) {mMachine->Advance(frame);}

};

#endif //CANADIANEXPERIENCE_MACHINELIB_MACHINESYSTEM_H
