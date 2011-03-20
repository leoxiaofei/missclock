#ifndef MISSXML_H
#define MISSXML_H

class MissSkin;

class MissXML
{
    public:
        static bool SaveSkin(const shared_ptr<MissSkin>& pSkin);
        static void LoadSkin(const shared_ptr<MissSkin>& pSkin, const wxString& SkinName);
};

#endif // MISSXML_H
