#include "MissRemindSkin.h"

class MissRemindSkin::MissRemindSkinImpl
{
public:
    int m_nOverallWidth;
    int m_nMinHeight;
    int m_nMaxHeight;
};

MissRemindSkin::MissRemindSkin():
m_pImpl(new MissRemindSkinImpl)
{
    //ctor
}

MissRemindSkin::~MissRemindSkin()
{
    //dtor
}

void MissRemindSkin::DrawSkin(wxDC& dc)
{
}
