#ifndef MISSREMINDSKIN_H
#define MISSREMINDSKIN_H

class MissRemindSkin
{
    class MissRemindSkinImpl;

public:
    enum PatternPos
    {
        PP_TOP_LEFT,    PP_TOP_MID,    PP_TOP_RIGHT,
        PP_MID_LEFT,    PP_MID_RIGHT,  PP_MID_MID,
        PP_BOTTOM_LEFT, PP_BOTTOM_MID, PP_BOTTOM_RIGHT
    };

    enum FillPos
    {
        PP_TOP_OTHER, PP_BOTTOM_OTHER, PP_LEFT_OTHER, PP_RIGHT_OTHER
    };

    struct PatternInfo
    {
        PatternPos ePos;
        wxString   strBitmap;
    };

    struct FillInfo
    {
        int        nSize;        ///水平位置时，代表高度；垂直位置时，代表宽度；
        FillPos    ePos;
        int        nType;        ///1、颜色填充 2、图案填充
        wxString   strBrush;
    };

    struct OutTextInfo
    {
        int      nBottomHeight;
        int      nTextWidth;
        wxPoint  ptPos;
        wxFont   fontText;
        wxColour colorText;
        wxString strBitmap;
    };

    struct CloseBtnInfo
    {
        wxPoint  ptPos;
        wxFont   fontBtn;
        wxColour colorBtn;
        wxString strBtnText;
    };

    public:
        MissRemindSkin();
        virtual ~MissRemindSkin();

    public:
        void DrawSkin(wxDC &dc);
        void DrawText(wxDC &dc, unsigned int nStrLength);

        unsigned int GetRemindStringLength();
        void TakeOrderWithNewline(const std::vector<wxString>& vecIn);
        void LoadTempData();
        void ClearTempData();
        bool PtInCloseBtn(const wxPoint& pt);

    public:
        const wxString& GetSkinPath() const;
        int GetOverallWidth()  const;
        int GetOverallHeight() const;
        int GetMinHeight()     const;
        int GetMaxHeight()     const;
        const CloseBtnInfo& GetCloseBtnInfo()          const;
        const OutTextInfo&  GetOutTextInfo()           const;
        const PatternInfo&  GetPatternInfo(int nIndex) const;
        const FillInfo&     GetFillInfo(int nIndex)    const;
        int  GetPatternSize() const;
        int  GetFillSize()    const;

        void SetSkinPath(const wxString& strSkinPath);
        void SetOverallWidth(int nOverallWidth);
        void SetMinHeight(int nMinHeight);
        void SetMaxHeight(int nMaxHeight);
        void SetBGColor(const wxColor& cBG);
        void SetBtnInfo(const CloseBtnInfo& cButtonInfo);
        void SetTextInfo(const OutTextInfo& oTextInfo);
        void AddPattern(const PatternInfo& info);
        void AddFill(const FillInfo& info);
        void ClearPattern();
        void ClearFill();

    protected:

        void DrawFill       (wxDC & dc);
        void DrawPattern    (wxDC & dc);
        void DrawRemindText (wxDC & dc);
        void DrawButton     (wxDC & dc);


        const wxBitmap* GetPatternByPos(const PatternPos &pos);
        const wxBrush * GetFillByPos(const FillPos& pos);
    private:
        shared_ptr<MissRemindSkinImpl> m_pImpl;
};

#endif // MISSREMINDSKIN_H
