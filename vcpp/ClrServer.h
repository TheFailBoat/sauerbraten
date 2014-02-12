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

private:
	void LoadDll(const char* path);

	PluginList^ plugins;
};