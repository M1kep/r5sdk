//=====================================================================================//
//
// Purpose: Implementation of the pylon server backend.
//
// $NoKeywords: $
//=====================================================================================//

#include <core/stdafx.h>
#include <tier0/cvar.h>
#include <engine/host_state.h>
#include <engine/sys_utils.h>
#include <engine/net_chan.h>
#include <squirrel/sqinit.h>
#include <networksystem/r5net.h>
#include <networksystem/pylon.h>

//-----------------------------------------------------------------------------
// Purpose: Send keep alive request to Pylon Master Server.
// NOTE: When Pylon update reaches indev remove this and implement properly.
//-----------------------------------------------------------------------------
void KeepAliveToPylon()
{
	if (g_pHostState->m_bActiveGame && sv_pylonvisibility->GetBool()) // Check for active game.
	{
		std::string m_szHostToken = std::string();
		std::string m_szHostRequestMessage = std::string();
		DevMsg(eDLL_T::SERVER, "Sending PostServerHost request\n");
		bool result = g_pR5net->PostServerHost(m_szHostRequestMessage, m_szHostToken,
			ServerListing{
				g_pCVar->FindVar("hostname")->GetString(),
				std::string(g_pHostState->m_levelName),
				"",
				g_pCVar->FindVar("hostport")->GetString(),
				g_pCVar->FindVar("mp_gamemode")->GetString(),
				false,
				std::to_string(*g_nServerRemoteChecksum),
				std::string(),
				g_szNetKey.c_str()
			}
		);
	}
}