#include "my_app.h"
#include "my_frame.h"

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Game of Life", wxPoint(50, 50), wxSize(1000, 1000), 20, 20);
    frame->Show(true);

    return true;
}