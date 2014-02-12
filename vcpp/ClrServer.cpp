#include "cube.h"
#include "ClrServer.h"
#include <stdio.h>

ClrServer::ClrServer()
{
	plugins = gcnew PluginList();
}


ClrServer::~ClrServer()
{
}

void ClrServer::LoadDll(const char* path){
	auto assembly = System::AppDomain::CurrentDomain->Load(gcnew System::String(path));

	auto types = assembly->GetExportedTypes();

	for (int i = 0; i < types->Length; i++) {
		if (types[0]->IsAssignableFrom(IPlugin::typeid)) {
			auto plugin = dynamic_cast<IPlugin^>(System::Activator::CreateInstance(types[0]));

			plugins->Add(plugin);
		}
	}
}

bool ClrServer::OnInit()
{
	printf("Init!\n");
	return true;
}

bool ClrServer::OnConnecting(int clientNumber, const char * hostname, const char * name, const char * password, bool isReserved)
{
	printf("cid %i connecting\n", clientNumber);
	return true;
}
bool ClrServer::OnConnect(int clientNumber, bool spy)
{
	printf("cid %i connected\n", clientNumber);
	return true;
}
bool ClrServer::OnDisconnect(int clientNumber, const char * reason)
{
	printf("cid %i disconnecting\n", clientNumber);
	return true;
}
bool ClrServer::OnFailedConnect(const char * hostname, const char * reason)
{
	printf("host %s failed to connect\n", hostname);
	return true;
}

bool ClrServer::OnRenaming(int clientNumber)
{
	printf("on renaming %i\n", clientNumber);
	return true;
}
bool ClrServer::OnAllowRename(int clientNumber, const char * newName)
{
	printf("allowing rename to '%s' by %i\n", newName, clientNumber);
	return true;
}
bool ClrServer::OnRename(int clientNumber, const char * oldName, const char * newName)
{
	printf("rename to '%s from '%s' by %i\n", newName, oldName, clientNumber);
	return true;
}

bool ClrServer::OnTeamChange(int clientNumber, const char * oldTeam, const char * newTeam)
{
	printf("moved %i from '%s' to '%s'\n", clientNumber, oldTeam, newTeam);
	return true;
}
bool ClrServer::OnTeamChangeRequest(int clientNumber, const char * oldTeam, const char * newTeam)
{
	printf("request move %i from '%s' to '%s'\n", clientNumber, oldTeam, newTeam);
	return true;
}
