#pragma once

#include <wx/wx.h>

class AppMain : public wxApp {
public:
	virtual bool OnInit();
};

class MainFrame : public wxFrame {
public:
	MainFrame();

private:
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnFile(wxCommandEvent& event);
};

enum {
	ID_FILEBAR_TEST = 1
};