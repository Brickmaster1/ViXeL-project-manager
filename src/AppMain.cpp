#include "AppMain.h"

#include "wx/wx.h"

#include <cstddef>

bool AppMain::OnInit() {
    MainFrame* mainFrame = new MainFrame();
    mainFrame->Show(true);
    return true;
}


MainFrame::MainFrame() :
    wxFrame(NULL, wxID_ANY, "Test wxWidgets App")
{
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(ID_FILEBAR_TEST, "&Hello...\tCtrl-H",
                     "Example hover tooltip");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT);

    wxMenu* aboutMenu = new wxMenu;
    aboutMenu->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(aboutMenu, "&Help");

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
     
    Bind(wxEVT_MENU, &MainFrame::OnFile, this, ID_FILEBAR_TEST);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("A simple program to test out using wxWidgets",
                 "About Test", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnFile(wxCommandEvent& event) {
    wxLogMessage("Hello world from wxWidgets!");
}

wxIMPLEMENT_APP(AppMain);