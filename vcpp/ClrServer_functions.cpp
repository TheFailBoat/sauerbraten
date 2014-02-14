#ifndef __IN_SERVER_CPP__
#include "../fpsgame/server.cpp"
#include <vector>
#include <set>
namespace server {
#endif
	clientinfo* get_ci(int cn) {
		clientinfo* ci = getinfo(cn);
		if (!ci) throw gcnew System::Exception("invalid cn");
		return ci;
	}

	void SetMasterMode(int value, int cn)
	{
		if (value == mastermode)
			return;

		int prev_mastermode = mastermode;

		mastermode = value;
		allowedips.shrink(0);

		if (mastermode >= MM_PRIVATE)
		{
			loopv(clients) allowedips.add(getclientip(clients[i]->clientnum));
		}

		ClrServer::instance->OnSetMasterMode(cn, mastermodename(prev_mastermode), mastermodename(mastermode));

		sendf(-1, 1, "rii", N_MASTERMODE, mastermode);
	}

	void SendMessage(const char * text) {
		sendservmsg(text);
	}
	void SendTeamMessage(const char * team, const char * text) {
		loopv(clients)
			if (!strcmp(clients[i]->team, team))
				clients[i]->sendprivtext(text);
	}
	void SendPrivateMessage(int cn, const char * text) {
		get_ci(cn)->sendprivtext(text);
	}

	int GetClientNumber(const char * name)
	{
		loopv(clients)
			if (!strcmp(clients[i]->name, name))
				return clients[i]->clientnum;

		throw gcnew System::Exception("username not found");
	}

	std::vector<int> GetPlayers()
	{
		std::vector<int> result;
		loopv(clients)
			if (clients[i]->state.aitype == AI_NONE)
				result.push_back(clients[i]->clientnum);
		return result;
	}
	std::vector<int> GetPlayers(const char * team)
	{
		std::vector<int> result;
		loopv(clients)
			if (clients[i]->state.state != CS_SPECTATOR && clients[i]->state.aitype == AI_NONE && !strcmp(clients[i]->team, team))
				result.push_back(clients[i]->clientnum);
		return result;
	}
	std::vector<const char *> GetTeams()
	{
		std::set<std::string> teams;
		loopv(clients)
		{
			teams.insert(std::string(clients[i]->team));
		}

		std::vector<const char *> result;
		for (auto i = teams.begin(); i != teams.end(); i++) {
			result.push_back((*i).c_str());
		}
		return result;
	}

	IGameState^ GetGameState(gamestate *s)
	{
		GameState^ gs = gcnew GameState();

		gs->X = s->o.x;
		gs->Y = s->o.y;
		gs->Z = s->o.z;

		gs->Health = s->health;
		gs->MaxHealth = s->maxhealth;
		gs->Armour = s->armour;

		gs->GunSelect = s->gunselect;
		gs->GunWait = s->gunwait;

		gs->State = s->state;
		gs->EditState = s->editstate;

		gs->LastDeath = s->lastdeath;
		gs->LastSpawn = s->lastspawn;
		gs->LastShot = s->lastshot;

		gs->Frags = s->frags;
		gs->Flags = s->flags;
		gs->Deaths = s->deaths;
		gs->Teamkills = s->teamkills;
		gs->ShotDamage = s->shotdamage;
		gs->Damage = s->damage;
		gs->Tokens = s->tokens;
		gs->Suicides = s->suicides;
		gs->Hits = s->hits;
		gs->Misses = s->misses;
		gs->Shots = s->shots;

		gs->TimePlayed = s->timeplayed;
		
		return gs;
	}

	IClientInfo^ GetClientInfo(int cn)
	{
		clientinfo* ci = get_ci(cn);
		ClientInfo^ info = gcnew ClientInfo();

		info->ClientNumber = ci->clientnum;

		info->Name = gcnew System::String(ci->name);
		info->Team = gcnew System::String(ci->team);

		info->PlayerModel = ci->playermodel;

		info->Privilege = ci->privilege;
		info->Connected = ci->connected;
		info->Local = ci->local;

		info->State = GetGameState(&ci->state);

		info->Ping = ci->ping;

		return info;
	}
	IClientInfo^ GetClientInfo(const char * name)
	{
		return GetClientInfo(GetClientNumber(name));
	}

#ifndef __IN_SERVER_CPP__
}
#endif