#include "MissGlobal.h"

namespace MissGlobal
{
const wxString s_strSWeek[7] = {wxT("日"),wxT("一"),wxT("二"),wxT("三"),wxT("四"),wxT("五"),wxT("六")};

const wxString s_strSDateFormat[] = {
                            wxT("yyyy年MM月dd日"),
                            wxT("yyyy-MM-dd"),
                            wxT("yyyy/MM/dd")};

const wxString s_strCDateFormat[] = {
                            wxT("%Y年%m月%d日"),
                            wxT("%Y-%m-%d"),
                            wxT("%Y/%m/%d")};

const wxString s_strSTimeFormat[] = {
                            wxT("HH:mm:ss"),
                            wxT("H:mm:ss"),
                            wxT("HH:mm")
                            wxT("II:mm:ss P")};

const wxString s_strCTimeFormat[] = {
                            wxT("%H:%M:%S"),
                            wxT("%#H:%M:%S"),
                            wxT("%H:%M:"),
                            wxT("%I:%M:%S %p")};

wxString TaskData::GetTDateDesc() const
{
    wxString strRet;
    switch(nDateType)
    {
    case 0:
        strRet = strTaskDate;
        break;
    case 1:
        strRet = nEvery == 1 ? wxT("每天") : wxString::Format(wxT("每%d天"),nEvery);
        break;
    case 2:
        {
            int exist(0), every(nEvery);
            for (int loop = 0; loop != 7 && every != 0; ++loop, every /= 10)
            {
                exist = every % 10;
                if ( exist )
                {
                    strRet += strRet.IsEmpty()?wxT("每星期"):wxT("、");
                    strRet += s_strSWeek[loop];
                }
            }
        }
        break;
    case 3:
        strRet = wxString::Format(wxT("每月%d天"),nEvery);
        break;
    case 4:
        {
            wxDateTime dtTmp;
            dtTmp.ParseDate(strTaskDate);
            ///wxDateTime::GetMonth()的范围0~11
            strRet = wxString::Format(wxT("每年%d月%d日"), dtTmp.GetMonth()+1, dtTmp.GetDay());
        }
        break;
    }
    return strRet;
}

wxString TaskData::GetTTimeDesc() const
{
    wxString strRet;
    switch(nTimeType)
    {
    case 0:
        strRet = strTaskTime;
        break;
    case 1:
        strRet = wxT("启动时");
        break;
    case 2:
        strRet = wxT("退出时");
        break;
    case 3:
        strRet = wxT("不提醒");
        break;
    }

    return strRet;
}

wxString TaskData::GetTContentDesc() const
{
    wxString strRet;
    switch(nTaskType)
    {
    case 0:
        strRet = strTaskContent;
        break;
    case 1:
        strRet = wxT("运行:") + strTaskContent;
        break;
    }
    return strRet;
}

}

DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCUI_EVENT);
DEFINE_LOCAL_EVENT_TYPE(wxEVT_MCDATA_EVENT);
