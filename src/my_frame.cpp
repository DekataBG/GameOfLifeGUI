#include "my_frame.h"
#include "my_cell.h"
#include "scaffold/board.h"

#include <vector>

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size, int width, int height)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    fieldWidth = width;
    fieldHeight = height;
    Board *board;

    wxGridSizer *gridSizer = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);

    for (size_t i = 0; i < fieldWidth; i++)
    {
        for (size_t j = 0; j < fieldHeight; j++)
        {
            MyCell *button = new MyCell(this, 10000 + (j * fieldWidth + i), i, j);
            button->SetBackgroundColour(wxColour(192, 192, 192));
            button->Bind(wxEVT_BUTTON, &MyFrame::OnCellClick, this);
            cells.push_back(button);
            gridSizer->Add(button, 1, wxEXPAND | wxALL);
        }
    }

    board = new Board(cells, fieldWidth, fieldHeight);
    game = new Game(*board);

    // Create buttons sizer
    wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    // Create "Play" button
    wxButton *playButton = new wxButton(this, ID_Play, "Play");
    playButton->SetMinSize(wxSize(80, 40));
    playButton->Bind(wxEVT_BUTTON, &MyFrame::OnPlay, this);
    buttonSizer->Add(playButton);

    // Create "Next" button
    wxButton *nextButton = new wxButton(this, ID_Next, "Next");
    nextButton->SetMinSize(wxSize(80, 40));
    nextButton->Bind(wxEVT_BUTTON, &MyFrame::OnNext, this);
    buttonSizer->Add(nextButton);

    // Create "Reset" button
    wxButton *resetButton = new wxButton(this, ID_NewGame, "Reset");
    resetButton->SetMinSize(wxSize(80, 40));
    resetButton->Bind(wxEVT_BUTTON, &MyFrame::OnNewGame, this);
    buttonSizer->Add(resetButton);

    // Create main sizer to hold grid and button sizer
    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(gridSizer, 1, wxEXPAND | wxALL);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER | wxBOTTOM, 10);

    this->SetSizer(mainSizer);
    // grid->Layout();
}

void MyFrame::OnPlay(wxCommandEvent &event)
{
    for (size_t i = 0; i < fieldWidth; i++)
    {
        for (size_t j = 0; j < fieldHeight; j++)
        {
            static_cast<MyCell *>(cells[j * fieldWidth + i])->Enable(false);
        }
    }
}

void MyFrame::OnNext(wxCommandEvent &event)
{
    game->manageBoard();
}

void MyFrame::OnNewGame(wxCommandEvent &event)
{
    for (size_t i = 0; i < fieldWidth; i++)
    {
        for (size_t j = 0; j < fieldHeight; j++)
        {
            MyCell *cell = static_cast<MyCell *>(cells[j * fieldWidth + i]);
            cell->Enable(true);
            cell->setSelected(false); // Set gray color
        }
    }
}

void MyFrame::OnCellClick(wxCommandEvent &event)
{
    // int x = (event.GetId() - 10000) % fieldWidth;
    // int y = (event.GetId() - 10000) / fieldWidth;

    // MyCell *cell = static_cast<MyCell *>(cells[x * fieldWidth + y]);
    MyCell *cell = static_cast<MyCell *>(event.GetEventObject());

    cell->setSelected(!cell->getSelected());
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    wxEND_EVENT_TABLE()
        wxIMPLEMENT_APP(MyApp);
