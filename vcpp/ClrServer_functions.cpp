#ifndef __IN_SERVER_CPP__
#include "../fpsgame/server.cpp"
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
		{
			return;
		}

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
		loopv(clients) if (!strcmp(clients[i]->team, team)) clients[i]->sendprivtext(text);
	}
	void SendPrivateMessage(int cn, const char * text) {
		get_ci(cn)->sendprivtext(text);
	}

#ifndef __IN_SERVER_CPP__
}
#endif