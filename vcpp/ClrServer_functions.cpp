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

	IClientInfo^ GetClientInfo(int cn)
	{
		return nullptr;
	}
	IClientInfo^ GetClientInfo(const char * name)
	{
		return nullptr;
	}

#ifndef __IN_SERVER_CPP__
}
#endif