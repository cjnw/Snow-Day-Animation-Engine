/**
 * @file MachineDrawable.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H


#include "Drawable.h"
#include "../../MachineLib/MachineSystem.h"

/**
 * Class to represent our adapter
 */
class MachineDrawable : public Drawable
{
private:
    /// The interface
    std::shared_ptr<IMachineSystem> mMachine;

    /// Starting frame
    int mStartFrame = 10;

    /// The machine's timeline
    Timeline* mTimeline;

public:
    MachineDrawable(const std::wstring& name, const std::wstring&);

    /// Default constructor (disabled)
    MachineDrawable() = default;

    /// Copy constructor (disabled)
    MachineDrawable(const MachineDrawable &) = delete;

    /// Assignment operator
    void operator=(const MachineDrawable &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext>)override;

    bool HitTest(wxPoint)override;

    /**
     * Set actor for the machine drawable
     * @param actor
     */
    void SetActor(Actor *actor) override {Drawable::SetActor(actor);};

    /**
     * Set the starting frame
     * @param frame
     */
    void SetStart(int frame) {mStartFrame = frame;}

    void SetTimeline(Timeline*)override;

    void SetMachineNumber(int);

    /**
     * Get the machine number for this drawable
     * @return
     */
    int GetMachineNumber() {return mMachine->GetMachineNumber();}

    int MachDialog(wxWindow* window)override;



};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLE_H
