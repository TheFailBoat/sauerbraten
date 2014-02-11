#pragma once

typedef Sauerbraten::Interfaces::IServer IServer;
typedef Sauerbraten::Interfaces::IPlugin IPlugin;
typedef System::Collections::Generic::IReadOnlyList<IPlugin^> IPluginReadOnlyList;
typedef System::Collections::Generic::List<IPlugin^> PluginList;

public ref class ClrServer : public IServer, public IPlugin
{
public:
	ClrServer();
	~ClrServer();

public:
	virtual property IPluginReadOnlyList^ Plugins
	{
		IPluginReadOnlyList^ get()
		{
			return plugins;
		};
	};

public:
	virtual bool OnInit();

	virtual bool OnConnecting(int clientNumber, System::String^ hostname, System::String^ name, System::String^ password, bool isReserved);
	virtual bool OnConnect(int clientNumber, bool spy);
	virtual bool OnDisconnect(int clientNumber, System::String^ reason);
	virtual bool OnFailedConnect(System::String^ hostname, System::String^ reason);

private:
	void LoadDll(const char* path);

	PluginList^ plugins;
};

extern ClrServer^* clrServer;