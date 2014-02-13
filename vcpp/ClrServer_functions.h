#pragma once

#include <vector>
#include <set>

namespace server
{
	void SetMasterMode(int value, int cn);

	void SendMessage(const char * text);
	void SendTeamMessage(const char * team, const char * text);
	void SendPrivateMessage(int cn, const char * text);

	int GetClientNumber(const char * name);

	std::vector<int> GetPlayers();
	std::vector<int> GetPlayers(const char * team);
	std::vector<const char *> GetTeams();

	IClientInfo^ GetClientInfo(int cn);
	IClientInfo^ GetClientInfo(const char * name);
}