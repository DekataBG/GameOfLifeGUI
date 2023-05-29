#include "my_app.h"
#include "my_frame.h"

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("The Game of Life", wxSize(1000, 1000), 20, 20);
    frame->Show(true);

    return true;
}