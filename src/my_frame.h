#pragma once

#include <wx/wx.h>

#include "my_app.h"
#include "scaffold/game.h"
#include "scaffold/board.h"
#include <vector>

class MyFrame : public wxFrame, public Board
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size, int width = 10, int height = 10);

    Game *game;

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

    wxDECLARE_EVENT_TABLE();

    enum
    {
        ID_Play = wxID_HIGHEST + 1,
        ID_Next,
        ID_NewGame,
    };
};
