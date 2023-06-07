#include <vector>

#include "my_frame.h"
#include "my_cell.h"

#include "scaffold/game.h"

MyFrame::MyFrame(const wxString &title, const wxSize &size, int rows, int cols)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size), Board({}, rows, cols)
{
    wxGridSizer *gridSizer = CreateGridSizer();

    wxBoxSizer *buttonSizer = CreateButtonSizer();

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(gridSizer, 1, wxEXPAND | wxALL);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxBOTTOM, 10);

    this->SetSizer(mainSizer);
}

wxButton *MyFrame::CreatePlayButton()
{
    wxButton *playButton = new wxButton(this, ID_Play, "Play");
    playButton->SetMinSize(wxSize(80, 40));
    playButton->Bind(wxEVT_BUTTON, &MyFrame::OnPlay, this);

    return playButton;
}

wxButton *MyFrame::CreateResetButton()
{
    wxButton *resetButton = new wxButton(this, ID_NewGame, "Reset");
    resetButton->SetMinSize(wxSize(80, 40));
    resetButton->Bind(wxEVT_BUTTON, &MyFrame::OnNewGame, this);

    return resetButton;
}

wxButton *MyFrame::CreateNextButton()
{
    wxButton *nextButton = new wxButton(this, ID_Next, "Next");
    nextButton->SetMinSize(wxSize(80, 40));
    nextButton->Bind(wxEVT_BUTTON, &MyFrame::OnNext, this);

    return nextButton;
}

wxGridSizer *MyFrame::CreateGridSizer()
{
    wxGridSizer *gridSizer = new wxGridSizer(getRows(), getCols(), 0, 0);

    for (size_t i = 0; i < getRows(); i++)
    {
        for (size_t j = 0; j < getCols(); j++)
        {
            MyCell *button = new MyCell(this, i, j);
            button->SetBackgroundColour(wxColour(192, 192, 192));
            button->Bind(wxEVT_BUTTON, &MyFrame::OnCellClick, this);

            pushCell(button);

            gridSizer->Add(button, 1, wxEXPAND | wxALL);
        }
    }

    return gridSizer;
}

wxBoxSizer *MyFrame::CreateButtonSizer()
{
    wxButton *playButton = CreatePlayButton();
    wxButton *nextButton = CreateNextButton();
    wxButton *resetButton = CreateResetButton();

    wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);
    buttonSizer->Add(playButton);
    buttonSizer->Add(nextButton);
    buttonSizer->Add(resetButton);

    return buttonSizer;
}

void MyFrame::OnPlay(wxCommandEvent &event)
{
    wxButton *playBtn = static_cast<wxButton *>(FindWindowById(ID_Play));
    playBtn->Enable(false);

    for (size_t i = 0; i < getRows(); i++)
    {
        for (size_t j = 0; j < getCols(); j++)
        {
            MyCell *cell = static_cast<MyCell *>(getCell(i, j));

            cell->Enable(false);
        }
    }
}

void MyFrame::OnNext(wxCommandEvent &event)
{
    Game *game = Game::getInstance(*this);
    game->manageBoard();
}

void MyFrame::OnNewGame(wxCommandEvent &event)
{
    wxButton *playBtn = static_cast<wxButton *>(FindWindowById(ID_Play));
    playBtn->Enable(true);

    for (size_t i = 0; i < getRows(); i++)
    {
        for (size_t j = 0; j < getCols(); j++)
        {
            MyCell *cell = static_cast<MyCell *>(getCell(i, j));

            cell->Enable(true);
            unselectCell(cell); // Set gray color
        }
    }
}

void MyFrame::OnCellClick(wxCommandEvent &event)
{
    MyCell *cell = static_cast<MyCell *>(event.GetEventObject());

    cell->setSelected(!cell->getSelected());
}

wxIMPLEMENT_APP(MyApp);
