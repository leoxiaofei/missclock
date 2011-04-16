#ifndef SARES_H
#define SARES_H

class wxSound;

class MissRes {
	class MissResImpl;
	static MissRes* ms_instance;

public:
	static MissRes* Instance();
	static void Release();

	void SetStrArchive ( const wxString& strArchive );
	const wxString& GetStrArchive() const;

	bool GetReswxSound (const wxString& strSoundName , wxSound& sound );

private:
	MissRes();
	~MissRes();
	std::tr1::shared_ptr<MissResImpl> m_pImpl;
};

#endif // SARES_H
