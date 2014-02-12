#include "cube.h"
#include "ClrServer.h"
#include <stdio.h>
#include <vcclr.h>

ClrServer::ClrServer()
{
	plugins = gcnew PluginList();

	System::String^ corePath = System::IO::Path::Combine(System::Environment::CurrentDirectory, "bin/plugins/Sauerbraten.Core.dll");
	LoadDll(corePath);

	auto toLoad = System::IO::Directory::GetFiles("bin/plugins", "*.dll", System::IO::SearchOption::AllDirectories);
	for (int i = 0; i < toLoad->Length; i++) {
		try {
			if (System::IO::Path::GetFileName(toLoad[0]) != "Sauerbraten.Core.dll")
				LoadDll(toLoad[i]);
		}
		catch (System::Exception^) {
			fatal("error loading a plugin.");
		}
	}
}


ClrServer::~ClrServer()
{
}

namespace server
{
	extern void SetMasterMode(int value, int cn);
}

void ClrServer::SetMasterMode(int value, int cn){
	server::SetMasterMode(value, cn);
}

void ClrServer::LoadDll(System::String^ path){
	auto assembly = System::Reflection::Assembly::LoadFile(path);

	auto types = assembly->GetExportedTypes();

	for (int i = 0; i < types->Length; i++) {
		if (IPlugin::typeid->IsAssignableFrom(types[0])) {
			auto plugin = dynamic_cast<IPlugin^>(System::Activator::CreateInstance(types[0]));

			printf("Loaded plugin: %s called '%s'\n", plugin->GetType()->FullName, plugin->Name);

			plugins->Add(plugin);
		}
	}
}

#define PLUGINS_RUN(X, ...) do {\
	int count = plugins->Count;  \
	for (int i = 0; i < count; i++)\
{ \
	if (!plugins[i]->X(__VA_ARGS__)) \
{ return false; } \
} \
	return true; \
} \
while (false)

bool ClrServer::OnInit()
{
	PLUGINS_RUN(OnInit);
}

bool ClrServer::OnConnecting(int clientNumber, const char * _hostname, const char * _name, const char * _password, bool isReserved)
{
	System::String^ hostname = gcnew System::String(_hostname);
	System::String^ name = gcnew System::String(_name);
	System::String^ password = gcnew System::String(_password);

	PLUGINS_RUN(OnConnecting, clientNumber, hostname, name, password, isReserved);
}
bool ClrServer::OnConnect(int clientNumber, bool spy)
{
	PLUGINS_RUN(OnConnect, clientNumber, spy);
}

bool ClrServer::OnDisconnect(int clientNumber, const char * _reason)
{
	System::String^ reason = gcnew System::String(_reason);

	PLUGINS_RUN(OnDisconnect, clientNumber, reason);
}
bool ClrServer::OnFailedConnect(const char * _hostname, const char * _reason)
{
	System::String^ hostname = gcnew System::String(_hostname);
	System::String^ reason = gcnew System::String(_reason);

	PLUGINS_RUN(OnFailedConnect, hostname, reason);
}

bool ClrServer::OnRenaming(int clientNumber)
{
	PLUGINS_RUN(OnRenaming, clientNumber);
}
bool ClrServer::OnAllowRename(int clientNumber, const char * _newName)
{
	System::String^ newName = gcnew System::String(_newName);

	PLUGINS_RUN(OnAllowRename, clientNumber, newName);
}
bool ClrServer::OnRename(int clientNumber, const char * _oldName, const char * _newName)
{
	System::String^ oldName = gcnew System::String(_oldName);
	System::String^ newName = gcnew System::String(_newName);

	PLUGINS_RUN(OnRename, clientNumber, oldName, newName);
}

bool ClrServer::OnTeamChange(int clientNumber, const char * _oldTeam, const char * _newTeam)
{
	System::String^ oldTeam = gcnew System::String(_oldTeam);
	System::String^ newTeam = gcnew System::String(_newTeam);

	PLUGINS_RUN(OnTeamChange, clientNumber, oldTeam, newTeam);
}
bool ClrServer::OnTeamChangeRequest(int clientNumber, const char * _oldTeam, const char * _newTeam)
{
	System::String^ oldTeam = gcnew System::String(_oldTeam);
	System::String^ newTeam = gcnew System::String(_newTeam);

	PLUGINS_RUN(OnTeamChangeRequest, clientNumber, oldTeam, newTeam);
}

bool ClrServer::OnText(int clientNumber, const char * _text)
{
	System::String^ text = gcnew System::String(_text);

	PLUGINS_RUN(OnText, clientNumber, text);
}
bool ClrServer::OnSayTeam(int clientNumber, const char * _text)
{
	System::String^ text = gcnew System::String(_text);

	PLUGINS_RUN(OnSayTeam, clientNumber, text);
}
bool ClrServer::OnServerCommand(int clientNumber, const char * _text)
{
	System::String^ text = gcnew System::String(_text);

	PLUGINS_RUN(OnServerCommand, clientNumber, text);
}

bool ClrServer::OnMapVote(int clientNumber, const char * _map, const char * _mode)
{
	System::String^ map = gcnew System::String(_map);
	System::String^ mode = gcnew System::String(_mode);

	PLUGINS_RUN(OnMapVote, clientNumber, map, mode);
}
bool ClrServer::OnMapVotePassed(const char * _map, const char * _mode)
{
	System::String^ map = gcnew System::String(_map);
	System::String^ mode = gcnew System::String(_mode);

	PLUGINS_RUN(OnMapVotePassed, map, mode);
}

bool ClrServer::OnSetMasterMode(int clientNumber, const char * _oldMode, const char * _newMode)
{
	System::String^ oldMode = gcnew System::String(_oldMode);
	System::String^ newMode = gcnew System::String(_newMode);

	PLUGINS_RUN(OnSetMasterMode, clientNumber, oldMode, newMode);
}
bool ClrServer::OnSetMasterModeRequest(int clientNumber, const char * _oldMode, const char * _newMode)
{
	System::String^ oldMode = gcnew System::String(_oldMode);
	System::String^ newMode = gcnew System::String(_newMode);

	PLUGINS_RUN(OnSetMasterModeRequest, clientNumber, oldMode, newMode);
}
bool ClrServer::OnSpectator(int clientNumber)
{
	PLUGINS_RUN(OnSpectator, clientNumber);
}
// bool OnPrivilege(int clientNumber, int oldLevel, int newLevel);
bool ClrServer::OnSetMaster(int clientNumber, const char * _password, bool force)
{
	System::String^ password = gcnew System::String(_password);

	PLUGINS_RUN(OnSetMaster, clientNumber, password, force);
}
bool ClrServer::OnClearBansRequest()
{
	PLUGINS_RUN(OnClearBansRequest);
}
bool ClrServer::OnKickRequest(int kickerClientNumber, const char * _kickerName, int banTime, int victimClientNumber, const char * _victimName)
{
	System::String^ kickerName = gcnew System::String(_kickerName);
	System::String^ victimName = gcnew System::String(_victimName);

	PLUGINS_RUN(OnKickRequest, kickerClientNumber, kickerName, banTime, victimClientNumber, victimName);
}

bool ClrServer::OnAuthRequest(int clientNumber, const char * _username, const char * _domain)
{
	System::String^ username = gcnew System::String(_username);
	System::String^ domain = gcnew System::String(_domain);

	PLUGINS_RUN(OnAuthRequest, clientNumber, username, domain);
}
bool ClrServer::OnAuthResponse(int clientNumber, int id, const char * _val)
{
	System::String^ val = gcnew System::String(_val);

	PLUGINS_RUN(OnAuthResponse, clientNumber, id, val);
}

bool ClrServer::OnModMap(int clientNumber, const char * _map, int crc)
{
	System::String^ map = gcnew System::String(_map);

	PLUGINS_RUN(OnModMap, clientNumber, map, crc);
}

bool ClrServer::OnTeamkill(int actorClientNumber, int targetClientNumber)
{
	PLUGINS_RUN(OnTeamkill, actorClientNumber, targetClientNumber);
}
bool ClrServer::OnFrag(int actorClientNumber, int targetClientNumber)
{
	PLUGINS_RUN(OnFrag, actorClientNumber, targetClientNumber);
}
bool ClrServer::OnShot(int clientNumber, int weapon, int hits)
{
	PLUGINS_RUN(OnShot, clientNumber, weapon, hits);
}
bool ClrServer::OnSuicide(int clientNumber)
{
	PLUGINS_RUN(OnSuicide, clientNumber);
}
bool ClrServer::OnSpawn(int clientNumber)
{
	PLUGINS_RUN(OnSpawn, clientNumber);
}
bool ClrServer::OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon)
{
	PLUGINS_RUN(OnDamage, actorClientNumber, targetClientNumber, damage, weapon);
}
bool ClrServer::OnTakeFlag(int clientNumber, const char * _team)
{
	System::String^ team = gcnew System::String(_team);

	PLUGINS_RUN(OnTakeFlag, clientNumber, team);
}
bool ClrServer::OnDropFlag(int clientNumber, const char * _team)
{
	System::String^ team = gcnew System::String(_team);

	PLUGINS_RUN(OnDropFlag, clientNumber, team);
}
bool ClrServer::OnScoreFlag(int clientNumber, const char * _team, int score)
{
	System::String^ team = gcnew System::String(_team);

	PLUGINS_RUN(OnScoreFlag, clientNumber, team, score);
}
bool ClrServer::OnReturnFlag(int clientNumber, const char * _team)
{
	System::String^ team = gcnew System::String(_team);

	PLUGINS_RUN(OnReturnFlag, clientNumber, team);
}
bool ClrServer::OnFlagReset(const char * _team)
{
	System::String^ team = gcnew System::String(_team);

	PLUGINS_RUN(OnFlagReset, team);
}
bool ClrServer::OnScoreUpdate(const char * _team, int score)
{
	System::String^ team = gcnew System::String(_team);

	PLUGINS_RUN(OnScoreUpdate, team, score);
}