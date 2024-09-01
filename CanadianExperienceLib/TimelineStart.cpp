/**
 * @file TimelineStart.cpp
 * @author CJ Nwogu
 */

#include "pch.h"
#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>
#include "TimelineStart.h"
#include "Timeline.h"

/**
 * Constructor
 * @param parent window
 * @param timeline
 */
TimelineStart::TimelineStart(wxWindow *parent, Timeline *timeline) : mTimeline(timeline)
{
    wxXmlResource::Get()->LoadDialog(this, parent, L"StartFrameDlg");

    mStartFrame = timeline->GetNumFrames();

    Bind(wxEVT_BUTTON, &TimelineStart::OnOK, this, wxID_OK);

    auto numFramesCtrl = XRCCTRL(*this, "StartingFrameDlgFrame", wxTextCtrl);
    wxIntegerValidator<int> numFramesValidator(&mStartFrame);
    numFramesValidator.SetRange(1, 10000);
    numFramesCtrl->SetValidator(numFramesValidator);

}

/**
 * Validate input upon "OK"
 * @param event
 */
void TimelineStart::OnOK(wxCommandEvent &event)
{
    if ( Validate() && TransferDataFromWindow() )
    {
        // Success! Set values in the class
        mTimeline->SetStartFrame(mStartFrame);

        EndModal(wxID_OK);
    }
}
