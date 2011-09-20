#ifndef MISSXML_H
#define MISSXML_H

class MissSkin;
class MissRemindSkin;

class MissXML
{
    public:
        static bool SaveSkin(const MissSkin* pSkin);
        static void LoadSkin(MissSkin* pSkin, const wxString& SkinName);

        static bool SaveRemindSkin(const MissRemindSkin* pRemindSkin);
        static void LoadRemindSkin(MissRemindSkin* pRemindSkin, const wxString& SkinName);

};

#endif // MISSXML_H
