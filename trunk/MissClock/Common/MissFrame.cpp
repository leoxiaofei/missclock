#include "MissFrame.h"
#include <wx/dcclient.h>
#include <wx/effects.h>

#include "windows.h"


MissFrame::MissFrame( wxWindow* parent )
    :
    MissFrameBase( parent )
    //m_bmBackGround(wxT("mm_mid.png"),wxBITMAP_TYPE_PNG)
{
    //SetWindowStyleFlag(wxFRAME_TOOL_WINDOW | wxFRAME_NO_TASKBAR | wxNO_BORDER);

}

MissFrame::~MissFrame()
{
}

/*
void MissFrame::OnPaint( wxPaintEvent& event )
{
// TODO: Implement OnPaint
    wxPaintDC dc(this);
    //dc.DrawLine(0,0,100,100);
}
*/

void MissFrame::OnEraseBackground(wxEraseEvent& event)
{
    event.Skip();
    /*
    wxDC* pDC = event.GetDC();
    wxSize sz = GetClientSize ();
    pDC->SetBrush(*wxRED_BRUSH);
    pDC->DrawRectangle(wxPoint(0,0),sz);
    */
}

void MissFrame::OnPTitleOnPaint(wxPaintEvent& event)
{
    event.Skip();
    /*
    wxPaintDC dc(m_pTitle);
    //dc.SetBrush(wxBrush(wxBitmap(wxT("C:\\Users\\leoxiaofei\\Desktop\\catbg.png"),wxBITMAP_TYPE_PNG)));
    wxSize sz = m_pTitle->GetClientSize ();
    dc.DrawRectangle(wxPoint(0,0),sz);
    */
}

void MissFrame::OnPTitleLeftDown(wxMouseEvent& event)
{
    ::PostMessage(static_cast<HWND>(GetHandle()), WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(event.GetX(), event.GetY()));
}

