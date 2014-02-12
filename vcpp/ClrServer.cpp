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

namespace server
{
	extern void SetMasterMode(int value, int cn);
}

void ClrServer::SetMasterMode(int value, int cn){
	server::SetMasterMode(value, cn);
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

bool ClrServer::OnText(int clientNumber, const char * text)
{
	printf("text from %i '%s'\n", clientNumber, text);
	return true;
}
bool ClrServer::OnSayTeam(int clientNumber, const char * text)
{
	printf("team text from %i '%s'\n", clientNumber, text);
	return true;
}
bool ClrServer::OnServerCommand(int clientNumber, const char * text)
{
	printf("server command from %i '%s'\n", clientNumber, text);
	return true;
}

bool ClrServer::OnMapVote(int clientNumber, const char * map, const char * mode)
{
	printf("client %i votes for %s on %s\n", clientNumber, mode, map);
	return true;
}
bool ClrServer::OnMapVotePassed(const char * map, const char * mode)
{
	printf("%s on %s wins on vote\n", mode, map);
	return true;
}

bool ClrServer::OnSetMasterMode(int clientNumber, const char * oldMode, const char * newMode)
{
	printf("setmastermode\n");
	return true;
}
bool ClrServer::OnSetMasterModeRequest(int a, const char * oldMode, const char * newMode)
{
	printf("setmastermoderequest\n");
	return true;
}
bool ClrServer::OnSpectator(int clientNumber)
{
	printf("spectator\n");
	return true;
}
// bool OnPrivilege(int clientNumber, int oldLevel, int newLevel);
bool ClrServer::OnSetMaster(int clientNumber, const char * password, bool force)
{
	printf("setmaster\n");
	return true;
}
bool ClrServer::OnClearBansRequest()
{
	printf("clearbans\n");
	return true;
}
bool ClrServer::OnKickRequest(int kickerClientNumber, const char * kickerName, int banTime, int victimClientNumber, const char * victimName)
{
	printf("kickrequest\n");
	return true;
}

bool ClrServer::OnAuthRequest(int clientNumber, const char * username, const char * domain)
{
	printf("authreq\n");
	return true;
}
bool ClrServer::OnAuthResponse(int clientNumber, int id, const char * val)
{
	printf("authres\n");
	return true;
}

bool ClrServer::OnModMap(int clientNumber, const char * map, int crc)
{
	printf("modmap\n");
	return true;
}

bool ClrServer::OnTeamkill(int actorClientNumber, int targetClientNumber)
{
	printf("tk\n");
	return true;
}
bool ClrServer::OnFrag(int actorClientNumber, int targetClientNumber)
{
	printf("frag\n");
	return true;
}
bool ClrServer::OnShot(int clientNumber, int weapon, int hits)
{
	printf("shot\n");
	return true;
}
bool ClrServer::OnSuicide(int clientNumber)
{
	printf("suicide\n");
	return true;
}
bool ClrServer::OnSpawn(int clientNumber)
{
	printf("spawn\n");
	return true;
}
bool ClrServer::OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon)
{
	printf("damage\n");
	return true;
}
bool ClrServer::OnTakeFlag(int clientNumber, const char * team)
{
	printf("take flag\n");
	return true;
}
bool ClrServer::OnDropFlag(int clientNumber, const char * team)
{
	printf("drop flag\n");
	return true;
}
bool ClrServer::OnScoreFlag(int clientNumber, const char * team, int score)
{
	printf("score flag\n");
	return true;
}
bool ClrServer::OnReturnFlag(int clientNumber, const char * team)
{
	printf("return flag\n");
	return true;
}
bool ClrServer::OnFlagReset(const char * team)
{
	printf("flag reset\n");
	return true;
}
bool ClrServer::OnScoreUpdate(const char * team, int score)
{
	printf("score update\n");
	return true;
}