#ifndef MISSSKIN_H
#define MISSSKIN_H

struct MissElement
{
    wxString      m_Name;
    std::string   m_Content;
    wxFont        m_Font;
    wxColour      m_Colour;
    double        m_Alignment;
    int           m_X;
    int           m_Y;
    bool          m_Show;
};

class MissSkin
{
    class MissSkinImpl;

public:
    MissSkin();
    virtual ~MissSkin();

public:
    void DrawSkin(wxDC & dc, const tm* tmNow);

    void SetSkinPath(const wxString& strPath);
    void SetBGPicPath(const wxString& strPicPath);
    void SetLocale(const wxString& strLocale);
    void AddElement(const MissElement& element);
    void DelElement(unsigned int nIndex);
    void ClearElement();
    void LoadBGPic();

    const wxString &GetSkinPath() const;
    const wxString &GetBGPicPath() const;
    const wxString &GetLocale() const;
    int GetElementSize() const;
    MissElement &GetElement(int nIndex) const;
    const wxBitmap &GetBGBitmap() const;

protected:

private:
    shared_ptr<MissSkinImpl> m_pImpl;

};

#endif // MISSSKIN_H
