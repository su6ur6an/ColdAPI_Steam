#pragma once
#include "../Bridge.h"
#include "../public SDK/ISteamUser012.h"

class SteamUserIn012 : public ISteamUser012
{
public:
	HSteamUser GetHSteamUser()
	{
		return NULL;
	}

	bool BLoggedOn()
	{
		return Steam_Config::OnlineMod;
	}

	CSteamID GetSteamID()
	{
		return CSteamID(Steam_Config::UserID);
	}

	int InitiateGameConnection(void* pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure)
	{
		return cbMaxAuthBlob;
	}

	void TerminateGameConnection(uint32 unIPServer, uint16 usPortServer)
	{
		return;
	}

	void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo = "")
	{
		return;
	}

	bool GetUserDataFolder(char* pchBuffer, int cubBuffer)
	{
		const char* mydir = ColdAPI_Storage::GetStorageDirectory();

		std::memcpy(pchBuffer, mydir, cubBuffer);
		return true;
	}

	void StartVoiceRecording()
	{
		return;
	}

	void StopVoiceRecording()
	{
		return;
	}

	EVoiceResult GetCompressedVoice(void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten)
	{
		return k_EVoiceResultNoData;
	}

	EVoiceResult DecompressVoice(void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten)
	{
		return k_EVoiceResultNoData;
	}

	HAuthTicket GetAuthSessionTicket(void* pTicket, int cbMaxTicket, uint32* pcbTicket)
	{
		return NULL;
	}

	EBeginAuthSessionResult BeginAuthSession(const void* pAuthTicket, int cbAuthTicket, CSteamID steamID)
	{
		return k_EBeginAuthSessionResultOK;
	}

	void EndAuthSession(CSteamID steamID)
	{
		return;
	}

	void CancelAuthTicket(HAuthTicket hAuthTicket)
	{
		return;
	}

	EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID)
	{
		return k_EUserHasLicenseResultHasLicense;
	}
};