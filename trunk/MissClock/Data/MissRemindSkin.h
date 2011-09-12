#ifndef MISSREMINDSKIN_H
#define MISSREMINDSKIN_H


class MissRemindSkin
{
    class MissRemindSkinImpl;
    public:
        MissRemindSkin();
        virtual ~MissRemindSkin();

    public:
        void DrawSkin(wxDC & dc);

    protected:
    private:
        shared_ptr<MissRemindSkinImpl> m_pImpl;
};

#endif // MISSREMINDSKIN_H
