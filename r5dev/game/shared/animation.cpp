//=============================================================================//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//
#include "core/stdafx.h"
#include "public/studio.h"
#include "game/shared/animation.h"

//-----------------------------------------------------------------------------
//	
//-----------------------------------------------------------------------------
int CStudioHdr::LookupSequence(CStudioHdr* pStudio, const char* pszName)
{
	if (!pStudio->m_pMdlCacheVTable)
		return -1; // animations are unavailable for missing dynamic props! (mdl/error.rmdl).

	return v_CStudioHdr__LookupSequence(pStudio, pszName);
}

void Animation_Attach()
{
	DetourAttach((LPVOID*)&v_CStudioHdr__LookupSequence, &CStudioHdr::LookupSequence);
}

void Animation_Detach()
{
	DetourDetach((LPVOID*)&v_CStudioHdr__LookupSequence, &CStudioHdr::LookupSequence);
}
