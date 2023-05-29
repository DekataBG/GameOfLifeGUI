#pragma once

#include <wx/wx.h>

#include "my_app.h"
#include "scaffold/board.h"

class MyFrame : public wxFrame, public Board
{
public:
    MyFrame(const wxString &title, const wxSize &size, int rows = 20, int cols = 20);

private:
    wxButton *CreatePlayButton();
    wxButton *CreateNextButton();
    wxButton *CreateResetButton();

    wxGridSizer *CreateGridSizer();
    wxBoxSizer *CreateButtonSizer();

    void OnPlay(wxCommandEvent &event);
    void OnNext(wxCommandEvent &event);
    void OnNewGame(wxCommandEvent &event);
    void OnCellClick(wxCommandEvent &event);

    enum
    {
        ID_Play = wxID_HIGHEST + 1,
        ID_Next,
        ID_NewGame,
    };
};
