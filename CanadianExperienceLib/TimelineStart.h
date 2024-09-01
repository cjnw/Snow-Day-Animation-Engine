/**
 * @file TimelineStart.h
 * @author CJ Nwogu
 *
 * Class to represent start frame dialog box
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINESTART_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINESTART_H
class Timeline;

/**
 * Start frame dialog box
 */
class TimelineStart final : public wxDialog
{
private:

    void OnOK(wxCommandEvent& event);

    /// The pointer to the Timeline
    Timeline *mTimeline;

    /// Machine Start frame
    int mStartFrame = 0;

public:
    TimelineStart(wxWindow* parent, Timeline *timeline);



};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_TIMELINESTART_H
