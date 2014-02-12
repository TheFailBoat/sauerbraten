#pragma once

typedef Sauerbraten::Interfaces::IServer IServer;
typedef Sauerbraten::Interfaces::IPlugin IPlugin;
typedef System::Collections::Generic::IReadOnlyList<IPlugin^> IPluginReadOnlyList;
typedef System::Collections::Generic::List<IPlugin^> PluginList;

public ref class ClrServer : public IServer
{
public:
	ClrServer();
	~ClrServer();

	static ClrServer^ instance;

public:
	virtual property IPluginReadOnlyList^ Plugins
	{
		IPluginReadOnlyList^ get()
		{
			return plugins;
		};
	};


	virtual void SetMasterMode(int value) { return SetMasterMode(value, -1); }
	virtual void SetMasterMode(int value, int cn);
	
public:
	bool OnInit();

	bool OnConnecting(int clientNumber, const char * hostname, const char * name, const char * password, bool isReserved);
	bool OnConnect(int clientNumber, bool spy);
	bool OnDisconnect(int clientNumber, const char * reason);
	bool OnFailedConnect(const char * hostname, const char * reason);

	bool OnRenaming(int clientNumber);
	bool OnAllowRename(int clientNumber, const char * newName);
	bool OnRename(int clientNumber, const char * oldName, const char * newName);

	bool OnTeamChange(int clientNumber, const char * oldTeam, const char * newTeam);
	bool OnTeamChangeRequest(int clientNumber, const char * oldTeam, const char * newTeam);

	bool OnText(int clientNumber, const char * text);
	bool OnSayTeam(int clientNumber, const char * text);
	bool OnServerCommand(int clientNumber, const char * text);

	bool OnMapVote(int clientNumber, const char * map, const char * mode);
	bool OnMapVotePassed(const char * map, const char * mode);

	bool OnSetMasterMode(int clientNumber, const char * oldMode, const char * newMode);
	bool OnSetMasterModeRequest(int a, const char * oldMode, const char * newMode);
	bool OnSpectator(int clientNumber);
	// bool OnPrivilege(int clientNumber, int oldLevel, int newLevel);
	bool OnSetMaster(int clientNumber, const char * password, bool force);
	bool OnClearBansRequest();
	bool OnKickRequest(int kickerClientNumber, const char * kickerName, int banTime, int victimClientNumber, const char * victimName);

	bool OnAuthRequest(int clientNumber, const char * username, const char * domain);
	bool OnAuthResponse(int clientNumber, int id, const char * val);

	bool OnModMap(int clientNumber, const char * map, int crc);

	bool OnTeamkill(int actorClientNumber, int targetClientNumber);
	bool OnFrag(int actorClientNumber, int targetClientNumber);
	bool OnShot(int clientNumber, int weapon, int hits);
	bool OnSuicide(int clientNumber);
	bool OnSpawn(int clientNumber);
	bool OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon);
	bool OnTakeFlag(int clientNumber, const char * team);
	bool OnDropFlag(int clientNumber, const char * team);
	bool OnScoreFlag(int clientNumber, const char * team, int score);
	bool OnReturnFlag(int clientNumber, const char * team);
	bool OnFlagReset(const char * team);
	bool OnScoreUpdate(const char * team, int score);


private:
	void LoadDll(const char* path);

	PluginList^ plugins;
};