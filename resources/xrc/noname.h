///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* MenuBar;
		wxMenu* FileMenu;
		wxMenu* EditMenu;
		wxMenu* MachineMenu;
		wxMenu* PlayMenu;
		wxMenu* HelpMenu;
		wxToolBar* ToolBar;
		wxToolBarToolBase* EditMove;
		wxToolBarToolBase* EditRotate;
		wxToolBarToolBase* EditSetKeyframe;
		wxToolBarToolBase* EditDeleteKeyframe;
		wxStatusBar* StatusBar;

	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Canadian Experience"), const wxPoint& pos = wxPoint( 100,100 ), const wxSize& size = wxSize( 1200,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDialog
///////////////////////////////////////////////////////////////////////////////
class AboutDialog : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText1;
		wxButton* wxID_OK;

	public:

		AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About Canadian Experience"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~AboutDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class TimelineDlg
///////////////////////////////////////////////////////////////////////////////
class TimelineDlg : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* TimelineDlgNumFrames;
		wxStaticText* m_staticText3;
		wxTextCtrl* TimelineDlgFrameRate;
		wxStdDialogButtonSizer* ;
		wxButton* OK;
		wxButton* Cancel;

	public:

		TimelineDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Timeline Parameters"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~TimelineDlg();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxMenuBar* MenuBar;
		wxMenu* FileMenu;
		wxMenu* EditMenu;
		wxMenu* PlayMenu;
		wxMenu* HelpMenu;
		wxToolBar* ToolBar;
		wxToolBarToolBase* EditMove;
		wxToolBarToolBase* EditRotate;
		wxToolBarToolBase* EditSetKeyframe;
		wxToolBarToolBase* EditDeleteKeyframe;
		wxStatusBar* StatusBar;

	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Canadian Experience"), const wxPoint& pos = wxPoint( 100,100 ), const wxSize& size = wxSize( 1200,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDialog
///////////////////////////////////////////////////////////////////////////////
class AboutDialog : public wxDialog
{
	private:

	protected:
		wxStaticBitmap* m_bitmap1;
		wxStaticText* m_staticText1;
		wxButton* wxID_OK;

	public:

		AboutDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About Canadian Experience"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~AboutDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class TimelineDlg
///////////////////////////////////////////////////////////////////////////////
class TimelineDlg : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* TimelineDlgNumFrames;
		wxStaticText* m_staticText3;
		wxTextCtrl* TimelineDlgFrameRate;
		wxStdDialogButtonSizer* ;
		wxButton* OK;
		wxButton* Cancel;

	public:

		TimelineDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Timeline Parameters"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~TimelineDlg();

};

