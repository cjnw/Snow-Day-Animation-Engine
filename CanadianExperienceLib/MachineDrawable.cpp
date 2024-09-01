/**
 * @file MachineDrawable.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include "MachineDrawable.h"
#include "Timeline.h"
#include "../../MachineLib/IMachineSystem.h"
#include "../../MachineLib/MachineSystemFactory.h"
#include "../../MachineLib/MachineDialog.h"

/**
 * Draw the machine drawable
 * @param graphics
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double scale = 1;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);

    int currentFrame = mTimeline->GetCurrentFrame();

    mMachine->SetMachineFrame(0);

    if (currentFrame >= mStartFrame){
        mMachine->SetMachineFrame(currentFrame - mStartFrame);
    }

    wxPoint position = wxPoint(mPlacedPosition.x, mPlacedPosition.y);
    mMachine->SetLocation(position);
    mMachine->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Constructor
 * @param name
 * @param resourcesDir
 */
MachineDrawable::MachineDrawable(const std::wstring& name, const std::wstring& resourcesDir) : Drawable(name)
{
    MachineSystemFactory factory(resourcesDir);
    std::shared_ptr<IMachineSystem> machine = factory.CreateMachineSystem();
    mMachine =  machine;


}

/**
 * Set the timeline for this machine drawable
 * @param timeline
 */
void MachineDrawable::SetTimeline(Timeline *timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}


/**
 * Set this machine's number
 * @param number
 */
void MachineDrawable::SetMachineNumber(int number)
{
    mMachine->SetMachineNumber(number);
}

/**
 * Bring up dialog box for setting machine (Must select machine with mouse first)
 * @param window
 * @return
 */
int MachineDrawable::MachDialog(wxWindow *window)
{
    MachineDialog dlg(window, mMachine);
    if (dlg.ShowModal() == wxID_OK){

        return 1;
    }
    return 0;
}

/**
 * See if drawable was clicked on
 * @param pos clicked point
 * @return
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    double x = pos.x;
    double y = pos.y;

    // Translate(-mPlacedPosition)
    x -= mPlacedPosition.x;
    y -= mPlacedPosition.y;

    double sn = sin(mPlacedR);
    double cs = cos(mPlacedR);

    // Rotate(mPlacedR)
    double x1 = cs * x - sn * y;
    double y1 = sn * x + cs * y;

    // Translate(mCenter)
    x = x1 + GetPosition().x;
    y = y1 + GetPosition().y;


//    wxGraphicsMatrix mat;
//    mat.Translate(mCenter.x, mCenter.y);
//    mat.Rotate(mPlacedR);
//    mat.Translate(-mPlacedPosition.x, -mPlacedPosition.y);
//
//    wxDouble x = pos.x;
//    wxDouble y = pos.y;
//    mat.TransformPoint(&x, &y);

    double wid = 400;
    double hit = 500;

    // Test to see if x, y are in the image
    if (x < 0 || y < 0 || x >= wid || y >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image

    return true;
}
