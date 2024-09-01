///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	MenuBar = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* wxID_OPEN;
	wxID_OPEN = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Open Animation &File...\tCtrl-F") ) , wxT("Open Animation File"), wxITEM_NORMAL );
	FileMenu->Append( wxID_OPEN );

	wxMenuItem* wxID_SAVEAS;
	wxID_SAVEAS = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save Animation &As...\tCtrl-S") ) , wxT("Save animation as"), wxITEM_NORMAL );
	FileMenu->Append( wxID_SAVEAS );

	FileMenu->AppendSeparator();

	wxMenuItem* wxID_EXIT;
	wxID_EXIT = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("E&xit\tAlt-X") ) , wxT("Exit the Application"), wxITEM_NORMAL );
	FileMenu->Append( wxID_EXIT );

	MenuBar->Append( FileMenu, wxT("&File") );

	EditMenu = new wxMenu();
	wxMenuItem* EditMove;
	EditMove = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Move") ) , wxEmptyString, wxITEM_CHECK );
	EditMenu->Append( EditMove );

	wxMenuItem* EditRotate;
	EditRotate = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Rotate") ) , wxEmptyString, wxITEM_CHECK );
	EditMenu->Append( EditRotate );

	EditMenu->AppendSeparator();

	wxMenuItem* EditSetKeyframe;
	EditSetKeyframe = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Set Keyframe") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( EditSetKeyframe );

	wxMenuItem* EditDeleteKeyframe;
	EditDeleteKeyframe = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Delete Keyframe") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( EditDeleteKeyframe );

	EditMenu->AppendSeparator();

	wxMenuItem* EditTimelineProperties;
	EditTimelineProperties = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("Timeline Propoerties...") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( EditTimelineProperties );

	MenuBar->Append( EditMenu, wxT("&Edit") );

	MachineMenu = new wxMenu();
	wxMenuItem* MachineChange;
	MachineChange = new wxMenuItem( MachineMenu, wxID_ANY, wxString( wxT("&Change") ) , wxEmptyString, wxITEM_NORMAL );
	MachineMenu->Append( MachineChange );

	MenuBar->Append( MachineMenu, wxT("&Machine") );

	PlayMenu = new wxMenu();
	wxMenuItem* PlayPlay;
	PlayPlay = new wxMenuItem( PlayMenu, wxID_ANY, wxString( wxT("&Play") ) , wxT("Play the animation"), wxITEM_NORMAL );
	PlayMenu->Append( PlayPlay );

	wxMenuItem* PlayPlayFromBeginning;
	PlayPlayFromBeginning = new wxMenuItem( PlayMenu, wxID_ANY, wxString( wxT("Play from &Beginning") ) , wxT("Play from the beginning"), wxITEM_NORMAL );
	PlayMenu->Append( PlayPlayFromBeginning );

	wxMenuItem* PlayStop;
	PlayStop = new wxMenuItem( PlayMenu, wxID_ANY, wxString( wxT("&Stop") ) , wxT("Stop playing"), wxITEM_NORMAL );
	PlayMenu->Append( PlayStop );

	MenuBar->Append( PlayMenu, wxT("&Play") );

	HelpMenu = new wxMenu();
	wxMenuItem* wxID_ABOUT;
	wxID_ABOUT = new wxMenuItem( HelpMenu, wxID_ANY, wxString( wxT("&About\tF1") ) , wxEmptyString, wxITEM_NORMAL );
	HelpMenu->Append( wxID_ABOUT );

	MenuBar->Append( HelpMenu, wxT("&Help") );

	this->SetMenuBar( MenuBar );

	ToolBar = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	ToolBar->SetToolBitmapSize( wxSize( 32,32 ) );
	EditMove = ToolBar->AddTool( wxID_ANY, wxT("Move"), wxBitmap( wxT("move32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxT("Move Actor Parts"), wxEmptyString, NULL );

	EditRotate = ToolBar->AddTool( wxID_ANY, wxT("Rotate"), wxBitmap( wxT("rotate32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxT("Rotate Actor Parts"), wxEmptyString, NULL );

	ToolBar->AddSeparator();

	EditSetKeyframe = ToolBar->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("record32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	EditDeleteKeyframe = ToolBar->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("delete32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	ToolBar->Realize();

	StatusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}

MainFrame::~MainFrame()
{
}

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ;
	= new wxBoxSizer( wxVERTICAL );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("about-image.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	->Add( m_bitmap1, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("The Canadian Experience"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText1->Wrap( -1 );
	->Add( m_staticText1, 0, wxALL|wxEXPAND, 5 );

	wxID_OK = new wxButton( this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );

	wxID_OK->SetBitmap( wxBitmap( wxT("Load From File;"), wxBITMAP_TYPE_ANY ) );
	->Add( wxID_OK, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	this->SetSizer(  );
	this->Layout();
	->Fit( this );

	this->Centre( wxBOTH );
}

AboutDialog::~AboutDialog()
{
}

TimelineDlg::TimelineDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ;
	= new wxBoxSizer( wxVERTICAL );

	wxGridSizer* ;
	= new wxGridSizer( 2, 2, 0, 0 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Number of frames:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	TimelineDlgNumFrames = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	->Add( TimelineDlgNumFrames, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Frame Rate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	TimelineDlgFrameRate = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	->Add( TimelineDlgFrameRate, 0, wxALL|wxEXPAND, 5 );


	->Add( , 1, wxEXPAND, 5 );

	= new wxStdDialogButtonSizer();
	OK = new wxButton( this, wxID_OK );
	->AddButton( OK );
	Cancel = new wxButton( this, wxID_CANCEL );
	->AddButton( Cancel );
	->Realize();

	->Add( , 1, wxEXPAND, 5 );


	this->SetSizer(  );
	this->Layout();
	->Fit( this );

	this->Centre( wxBOTH );
}

TimelineDlg::~TimelineDlg()
{
}

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	MenuBar = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* wxID_OPEN;
	wxID_OPEN = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Open Animation &File...\tCtrl-F") ) , wxT("Open Animation File"), wxITEM_NORMAL );
	FileMenu->Append( wxID_OPEN );

	wxMenuItem* wxID_SAVEAS;
	wxID_SAVEAS = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("Save Animation &As...\tCtrl-S") ) , wxT("Save animation as"), wxITEM_NORMAL );
	FileMenu->Append( wxID_SAVEAS );

	FileMenu->AppendSeparator();

	wxMenuItem* wxID_EXIT;
	wxID_EXIT = new wxMenuItem( FileMenu, wxID_ANY, wxString( wxT("E&xit\tAlt-X") ) , wxT("Exit the Application"), wxITEM_NORMAL );
	FileMenu->Append( wxID_EXIT );

	MenuBar->Append( FileMenu, wxT("&File") );

	EditMenu = new wxMenu();
	wxMenuItem* EditMove;
	EditMove = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Move") ) , wxEmptyString, wxITEM_CHECK );
	EditMenu->Append( EditMove );

	wxMenuItem* EditRotate;
	EditRotate = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Rotate") ) , wxEmptyString, wxITEM_CHECK );
	EditMenu->Append( EditRotate );

	EditMenu->AppendSeparator();

	wxMenuItem* EditSetKeyframe;
	EditSetKeyframe = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Set Keyframe") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( EditSetKeyframe );

	wxMenuItem* EditDeleteKeyframe;
	EditDeleteKeyframe = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("&Delete Keyframe") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( EditDeleteKeyframe );

	EditMenu->AppendSeparator();

	wxMenuItem* EditTimelineProperties;
	EditTimelineProperties = new wxMenuItem( EditMenu, wxID_ANY, wxString( wxT("Timeline Propoerties...") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( EditTimelineProperties );

	MenuBar->Append( EditMenu, wxT("&Edit") );

	PlayMenu = new wxMenu();
	wxMenuItem* PlayPlay;
	PlayPlay = new wxMenuItem( PlayMenu, wxID_ANY, wxString( wxT("&Play") ) , wxT("Play the animation"), wxITEM_NORMAL );
	PlayMenu->Append( PlayPlay );

	wxMenuItem* PlayPlayFromBeginning;
	PlayPlayFromBeginning = new wxMenuItem( PlayMenu, wxID_ANY, wxString( wxT("Play from &Beginning") ) , wxT("Play from the beginning"), wxITEM_NORMAL );
	PlayMenu->Append( PlayPlayFromBeginning );

	wxMenuItem* PlayStop;
	PlayStop = new wxMenuItem( PlayMenu, wxID_ANY, wxString( wxT("&Stop") ) , wxT("Stop playing"), wxITEM_NORMAL );
	PlayMenu->Append( PlayStop );

	MenuBar->Append( PlayMenu, wxT("&Play") );

	HelpMenu = new wxMenu();
	wxMenuItem* wxID_ABOUT;
	wxID_ABOUT = new wxMenuItem( HelpMenu, wxID_ANY, wxString( wxT("&About\tF1") ) , wxEmptyString, wxITEM_NORMAL );
	HelpMenu->Append( wxID_ABOUT );

	MenuBar->Append( HelpMenu, wxT("&Help") );

	this->SetMenuBar( MenuBar );

	ToolBar = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	ToolBar->SetToolBitmapSize( wxSize( 32,32 ) );
	EditMove = ToolBar->AddTool( wxID_ANY, wxT("Move"), wxBitmap( wxT("move32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxT("Move Actor Parts"), wxEmptyString, NULL );

	EditRotate = ToolBar->AddTool( wxID_ANY, wxT("Rotate"), wxBitmap( wxT("rotate32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_CHECK, wxT("Rotate Actor Parts"), wxEmptyString, NULL );

	ToolBar->AddSeparator();

	EditSetKeyframe = ToolBar->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("record32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	EditDeleteKeyframe = ToolBar->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("delete32.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	ToolBar->Realize();

	StatusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}

MainFrame::~MainFrame()
{
}

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ;
	= new wxBoxSizer( wxVERTICAL );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("about-image.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	->Add( m_bitmap1, 0, wxALL, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("The Canadian Experience"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText1->Wrap( -1 );
	->Add( m_staticText1, 0, wxALL|wxEXPAND, 5 );

	wxID_OK = new wxButton( this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );

	wxID_OK->SetBitmap( wxBitmap( wxT("Load From File;"), wxBITMAP_TYPE_ANY ) );
	->Add( wxID_OK, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	this->SetSizer(  );
	this->Layout();
	->Fit( this );

	this->Centre( wxBOTH );
}

AboutDialog::~AboutDialog()
{
}

TimelineDlg::TimelineDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* ;
	= new wxBoxSizer( wxVERTICAL );

	wxGridSizer* ;
	= new wxGridSizer( 2, 2, 0, 0 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Number of frames:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	TimelineDlgNumFrames = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	->Add( TimelineDlgNumFrames, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Frame Rate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	TimelineDlgFrameRate = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	->Add( TimelineDlgFrameRate, 0, wxALL|wxEXPAND, 5 );


	->Add( , 1, wxEXPAND, 5 );

	= new wxStdDialogButtonSizer();
	OK = new wxButton( this, wxID_OK );
	->AddButton( OK );
	Cancel = new wxButton( this, wxID_CANCEL );
	->AddButton( Cancel );
	->Realize();

	->Add( , 1, wxEXPAND, 5 );


	this->SetSizer(  );
	this->Layout();
	->Fit( this );

	this->Centre( wxBOTH );
}

TimelineDlg::~TimelineDlg()
{
}
