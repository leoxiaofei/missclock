#include "../StdAfx.h"
#include "MissRes.h"
#include <wx/filesys.h>
#include <wx/sound.h>

class MissRes::MissResImpl
{
public:
	MissResImpl() :
		m_strArchive ( wxFileSystem::FileNameToURL ( wxString ( wxT ( "resource.dll" ) ) ) + wxT("#zip:") )
	{};
	wxFileSystem m_fileSystem;
	wxString m_strArchive;
};

MissRes* MissRes::ms_instance = 0;

MissRes::MissRes() :
	m_pImpl ( new MissResImpl )
{
}

MissRes::~MissRes()
{
}

MissRes* MissRes::Instance()
{
	if ( ms_instance == 0 )
	{
		ms_instance = new MissRes();
	}
	return ms_instance;
}

void MissRes::Release()
{
	if ( ms_instance )
	{
		delete ms_instance;
	}
	ms_instance = 0;
}

void MissRes::SetStrArchive ( const wxString& strArchive )
{
	m_pImpl->m_strArchive = wxFileSystem::FileNameToURL ( strArchive ) + wxT ( "#zip:" );
}

const wxString& MissRes::GetStrArchive() const
{
	return m_pImpl->m_strArchive;
}

bool MissRes::GetReswxSound(const wxString& strSoundName, wxSound& sound)
{
	wxFSFile *file = m_pImpl->m_fileSystem.OpenFile ( m_pImpl->m_strArchive + strSoundName );
	if ( file )
	{
		wxInputStream* stream = file->GetStream();
		wxByte* byDate = new wxByte[ stream->GetSize() ];
		stream->Read ( byDate,stream->GetSize() );
		sound.Create( stream->GetSize(),byDate );
		delete file ;
		delete [] byDate;
		return true;
	}
	return false;
}
