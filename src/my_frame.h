#pragma once

#include <wx/wx.h>

#include "my_app.h"
#include "scaffold/game.h"
#include <vector>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size, int width = 10, int height = 10);

    int fieldWidth;
    int fieldHeight;

    std::vector<ICell *> cells; //
    Game *game;                 //

private:
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
