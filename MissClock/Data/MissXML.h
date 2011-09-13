#ifndef MISSXML_H
#define MISSXML_H

class MissSkin;
class MissRemindSkin;

class MissXML
{
    public:
        static bool SaveSkin(const shared_ptr<MissSkin>& pSkin);
        static void LoadSkin(const shared_ptr<MissSkin>& pSkin, const wxString& SkinName);

        static bool SaveRemindSkin(const shared_ptr<MissRemindSkin>& pRemindSkin);
        static void LoadRemindSkin(const shared_ptr<MissRemindSkin>& pRemindSkin, const wxString& SkinName);

};

#endif // MISSXML_H
