#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <variant>
#include <exception>
#include <wx/wx.h>
#include <wx/grid.h>
#include <nlohmann/json.hpp>


using json = nlohmann::json;

using namespace std;

enum {
  ID_ABOUT = 1001,
  ID_EXIT = 1002
};

class MonApp : public wxApp {
  public:
    virtual bool OnInit();
};


class MaFrame : public wxFrame {
  public:
    MaFrame(const wxString& title);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

  private:
    wxPanel* m_panel;
    wxButton* btn1;
    wxGrid* m_grid;
};

wxIMPLEMENT_APP(MonApp);

bool MonApp::OnInit() {
  SetAppName("CMonApilipilipili");
  MaFrame* frame = new MaFrame("C'est la fefe..fenetre !!");
  frame->Show(true);
  return true;
};

MaFrame::MaFrame(const wxString& title)
  : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
    try
    {
     // Create a menu bar and file menu
    wxMenuBar* MenuBar = new wxMenuBar();
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(ID_ABOUT, "About...", "Voir à propos");
    menuFile->AppendSeparator();
    menuFile->Append(ID_EXIT, "Exit", "Quitter l'application");
    // Add the file menu to the menu bar
    MenuBar->Append(menuFile, "Fichier");
    SetMenuBar(MenuBar);
 
    // Bind menu events
    Bind(wxEVT_MENU, &MaFrame::OnAbout, this, ID_ABOUT);
    Bind(wxEVT_MENU, &MaFrame::OnExit, this, ID_EXIT);
 
    // Create a panel within the frame
    m_panel = new wxPanel(this, wxID_ANY);
    m_panel->SetBackgroundColour(wxColour(255, 255, 255));
 
    // Use a box sizer to manage the layout
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
 
    // Create the grid inside the panel
    m_grid = new wxGrid(m_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    m_grid->CreateGrid(10, 5);
    m_grid->SetColLabelValue(0, "Col 1");
    m_grid->SetColLabelValue(1, "Col 2");
    m_grid->SetColLabelValue(2, "Col 3");
    m_grid->SetColLabelValue(3, "Col 4");
    m_grid->SetColLabelValue(4, "Col 5"); // Add label for the last column
 
    for (int row = 0; row < 10; row++) {
      for (int col = 0; col < 5; col++) {
        m_grid->SetCellValue(row, col, wxString::Format("R%dC%d", row + 1, col + 1));
      }
    }
    m_grid->EnableEditing(false);
 
    // Add the grid to the sizer
    sizer->Add(m_grid, 1, wxEXPAND | wxALL, 10);
 
    // Create a button inside the panel
    btn1 = new wxButton(m_panel, wxID_ANY, "Clique moi beau gosse", wxDefaultPosition, wxDefaultSize);
 
    // Add the button to the sizer
    sizer->Add(btn1, 0, wxALL | wxALIGN_CENTER, 10);
 
    // Set the sizer for the panel
    m_panel->SetSizer(sizer);
    }
    catch(const std::exception& e)
    {
      std::cerr << "Exception" << e.what() << '\n';
    }
  
};

void MaFrame::OnExit(wxCommandEvent& event) {
  Close(true);
}

void MaFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("Bienvenue sur la fefe..fenetre !!", "A propos", wxOK | wxICON_INFORMATION);
}