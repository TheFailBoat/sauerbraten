#pragma once

namespace server
{
	void SetMasterMode(int value, int cn);

	void SendMessage(const char * text);
	void SendTeamMessage(const char * team, const char * text);
	void SendPrivateMessage(int cn, const char * text);

}