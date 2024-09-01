/**
 * @file Component.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
#define CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H

#include <wx/gdicmn.h>
#include "Polygon.h"

class Machine;

/**
 * Class to represent the components in our machine
 */
class Component
{
private:
    ///Current frame
    int mCurrentFrame = 0;
    /// Component position
    wxPoint mPosition = wxPoint(0,0);
    /// Image of component
    std::shared_ptr<cse335::Polygon> mImage;
    /// Angle of rotation
    double mRotation = 0.0;
    /// This component's machine
    std::shared_ptr<Machine> mMachine;
    /// Component name
    std::wstring mName;

public:
    ~Component(){};
    /** Default constructor disabled */
    Component() = delete;
    /** Copy constructor disabled */
    Component(const Component &) = delete;
    /** Assignment operator disabled */
    void operator=(const Component &) = delete;

    /**
     * Constructor
     * @param name component name
     */
    Component(const std::wstring& name) : mName(name){}



    /**
     * Set current machine frame
     * @param currentFrame
     */
    void SetCurrentFrame(int currentFrame) {mCurrentFrame = currentFrame;}

    /**
     * Reset component
     */
    void Reset(){};

    /**
     * Set initial position of component
     * @param pos
     */
    void SetInitialPos(wxPoint pos) {mPosition = pos;};

    /**
     * Get position of component
     * @return
     */
    wxPoint GetPosition() {return mPosition;}

    /**
     * Set machine that owns component
     * @param machine
     */
    void SetMachine(std::shared_ptr<Machine> machine) {mMachine = machine;}

    /**
     * Get this machine
     * @return
     */
    std::shared_ptr<Machine> GetMachine() {return mMachine;}

    /**
     * Get the image of the component
     * @return
     */
    std::shared_ptr<cse335::Polygon> GetImage(){return mImage;}

    /**
     * Set the image of a component
     * @param polygon
     */
    void SetPolygon(std::shared_ptr<cse335::Polygon> polygon) {mImage = polygon;}

    /**
     * Get this component's name
     * @return
     */
    std::wstring GetName() {return mName;}

    /**
     * Set this component's rotation
     * @param motion angle of rotation
     */
    virtual void SetRotation(double motion){mRotation = motion;}

    /**
     * Get rotation of component
     * @return
     */
    double GetRotation() {return mRotation;}

    /**
     * Set time on component
     * @param time
     */
    virtual void SetTime(double time){};

    /**
     * Advance frame on component
     * @param frame
     */
    virtual void Advance(double frame) {};


    /**
     * Update this component
     * @param elapsed
     */
    virtual void Update(double elapsed);

    /**
     * Set image of component
     * @param name filename
     */
    virtual void SetImage(const std::wstring& name)=0;

    /**
     * Draw this component
     * @param graphics graphics context
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int, int)=0;


};

#endif //CANADIANEXPERIENCE_MACHINELIB_COMPONENT_H
