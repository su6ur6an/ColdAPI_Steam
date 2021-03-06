#pragma once
#include "../public SDK/ISteamMatchmaking008.h"
#include "../Bridge.h"


class SteamMatchmakingIn008 : public ISteamMatchmaking008
{
public:
	int GetFavoriteGameCount()
	{
		return NULL;
	}

	bool GetFavoriteGame(int iGame, AppId_t* pnAppID, uint32* pnIP, uint16* pnConnPort, uint16* pnQueryPort, uint32* punFlags, uint32* pRTime32LastPlayedOnServer)
	{
		return false;
	}

	int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer)
	{
		return NULL;
	}

	bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags)
	{
		return false;
	}

	SteamAPICall_t RequestLobbyList()
	{
		return NULL;
	}
	void AddRequestLobbyListStringFilter(const char* pchKeyToMatch, const char* pchValueToMatch, ELobbyComparison eComparisonType)
	{
		return;
	}
	void AddRequestLobbyListNumericalFilter(const char* pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
	{
		return;
	}
	void AddRequestLobbyListNearValueFilter(const char* pchKeyToMatch, int nValueToBeCloseTo)
	{
		return;
	}
	void AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable)
	{
		return;
	}
	void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter)
	{
		return;
	}
	void AddRequestLobbyListResultCountFilter(int cMaxResults)
	{
		return;
	}

	CSteamID GetLobbyByIndex(int iLobby)
	{
		CSteamID idata = CSteamID(1111111, 0x40000, k_EUniversePublic, k_EAccountTypeChat);
		return idata;
	}

	SteamAPICall_t CreateLobby(ELobbyType eLobbyType, int)
	{
		LobbyCreated_t* Response = nullptr;
		CSteamID ID = CSteamID(1337132, 0x40000, k_EUniversePublic, k_EAccountTypeChat);		// Init a CSteamID structure

		auto RequestID = SteamCallback::RegisterCall(true);

		Response = static_cast<LobbyCreated_t*>(malloc(sizeof(LobbyCreated_t)));		// alloc memory to set a new fake Lobby response
		Response->m_eResult = k_EResultOK;
		Response->m_ulSteamIDLobby = ID.ConvertToUint64();

		SteamCallback::CreateNewRequest(Response, sizeof(*Response), Response->k_iCallback, RequestID);
		JoinLobby(ID);

		return RequestID;
	}

	SteamAPICall_t JoinLobby(CSteamID steamIDLobby)
	{
		LobbyEnter_t* Response = nullptr;

		auto RequestID = SteamCallback::RegisterCall(true);
		Response = static_cast<LobbyEnter_t*>(malloc(sizeof(LobbyEnter_t)));
		Response->m_bLocked = false;
		Response->m_EChatRoomEnterResponse = k_EChatRoomEnterResponseSuccess;
		Response->m_rgfChatPermissions = (EChatPermission)0xFFFFFFFF;
		Response->m_ulSteamIDLobby = steamIDLobby.ConvertToUint64();

		SteamCallback::CreateNewRequest(Response, sizeof(*Response), Response->k_iCallback, RequestID);

		return RequestID;
	}

	void LeaveLobby(CSteamID steamIDLobby)
	{
		auto RequestID = SteamCallback::RegisterCall(true);

		LobbyChatUpdate_t* retvals = (LobbyChatUpdate_t*)malloc(sizeof(LobbyChatUpdate_t));
		retvals->m_rgfChatMemberStateChange = EChatMemberStateChange::k_EChatMemberStateChangeLeft;
		retvals->m_ulSteamIDLobby = steamIDLobby;
		retvals->m_ulSteamIDMakingChange = Steam_Config::UserID;
		retvals->m_ulSteamIDUserChanged = Steam_Config::UserID;
		SteamCallback::CreateNewRequest(retvals, sizeof(*retvals), retvals->k_iCallback, RequestID);
	}

	bool InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee)
	{
		return false;
	}

	int GetNumLobbyMembers(CSteamID steamIDLobby)
	{
		return 1;
	}
	CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember)
	{
		return CSteamID((uint64)Steam_Config::UserID);
	}

	const char* GetLobbyData(CSteamID steamIDLobby, const char* pchKey)
	{
		return "";
	}
	bool SetLobbyData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue)
	{
		return false;
	}

	int GetLobbyDataCount(CSteamID steamIDLobby)
	{
		return NULL;
	}

	bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char* pchKey, int cchKeyBufferSize, char* pchValue, int cchValueBufferSize)
	{
		return false;
	}

	bool DeleteLobbyData(CSteamID steamIDLobby, const char* pchKey)
	{
		return false;
	}

	const char* GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char* pchKey)
	{
		return "";
	}
	void SetLobbyMemberData(CSteamID steamIDLobby, const char* pchKey, const char* pchValue)
	{
		return;
	}

	bool SendLobbyChatMsg(CSteamID steamIDLobby, const void* pvMsgBody, int cubMsgBody)
	{
		return false;
	}
	int GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID* pSteamIDUser, void* pvData, int cubData, EChatEntryType* peChatEntryType)
	{
		return NULL;
	}

	bool RequestLobbyData(CSteamID steamIDLobby)
	{
		return false;
	}

	void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer)
	{
		return;
	}
	bool GetLobbyGameServer(CSteamID steamIDLobby, uint32* punGameServerIP, uint16* punGameServerPort, CSteamID* psteamIDGameServer)
	{
		return false;
	}

	bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers)
	{
		return false;
	}
	int GetLobbyMemberLimit(CSteamID steamIDLobby)
	{
		return 1;
	}

	bool SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType)
	{
		return false;
	}

	bool SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable)
	{
		return false;
	}

	CSteamID GetLobbyOwner(CSteamID steamIDLobby)
	{
		return CSteamID((uint64)Steam_Config::UserID);
	}

	bool SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner)
	{
		return false;
	}
};
