using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sauerbraten.Interfaces
{
    public interface IPlugin
    {
        string Name { get; }

        bool OnInit();

        bool OnConnecting(int clientNumber, string hostname, string name, string password, bool isReserved);
        bool OnConnect(int clientNumber, bool spy);
        bool OnDisconnect(int clientNumber, string reason);
        bool OnFailedConnect(string hostname, string reason);

        bool OnRenaming(int clientNumber);
        bool OnAllowRename(int clientNumber, string newName);
        bool OnRename(int clientNumber, string oldName, string newName);

        bool OnTeamChange(int clientNumber, string oldTeam, string newTeam);
        bool OnTeamChangeRequest(int clientNumber, string oldTeam, string newTeam);

        bool OnText(int clientNumber, string text);
        bool OnSayTeam(int clientNumber, string text);
        bool OnServerCommand(int clientNumber, string text);

        bool OnMapVote(int clientNumber, string map, string mode);
        bool OnMapVotePassed(string map, string mode);

        bool OnSetMasterMode(int clientNumber, string oldMode, string newMode);
        bool OnSetMasterModeRequest(int a, string oldMode, string newMode);
        bool OnSpectator(int clientNumber);
        // bool OnPrivilege(int clientNumber, int oldLevel, int newLevel);
        bool OnSetMaster(int clientNumber, string password, bool force);
        bool OnClearBansRequest();
        bool OnKickRequest(int kickerClientNumber, string kickerName, int banTime, int victimClientNumber, string victimName);

        bool OnAuthRequest(int clientNumber, string username, string domain);
        bool OnAuthResponse(int clientNumber, int id, string val);

        bool OnModMap(int clientNumber, string map, int crc);

        //TODO extern lua::event< boost::tuple<int,int,int> >                              event_addbot;
        //TODO extern lua::event< boost::tuple<int> >                                      event_delbot;
        //TODO extern lua::event< boost::tuple<int> >                                      event_botleft;

        bool OnTeamkill(int actorClientNumber, int targetClientNumber);
        bool OnFrag(int actorClientNumber, int targetClientNumber);
        bool OnShot(int clientNumber, int weapon, int hits);
        bool OnSuicide(int clientNumber);
        bool OnSpawn(int clientNumber);
        bool OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon);
        bool OnTakeFlag(int clientNumber, string team);
        bool OnDropFlag(int clientNumber, string team);
        bool OnScoreFlag(int clientNumber, string team, int score);
        bool OnReturnFlag(int clientNumber, string team);
        bool OnFlagReset(string team);
        bool OnScoreUpdate(string team, int score);

        //TODO extern lua::event< boost::tuple<int,int> >                                  event_respawnrequest;

        //TODO extern lua::event< boost::tuple<> >                                         event_intermission;
        //TODO extern lua::event< boost::tuple<> >                                         event_finishedgame;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_timeupdate;
        //TODO extern lua::event< boost::tuple<const char *,const char *> >                event_mapchange;
        //TODO extern lua::event< boost::tuple<> >                                         event_setnextgame;

        //TODO extern lua::event< boost::tuple<> >                                         event_gamepaused;
        //TODO extern lua::event< boost::tuple<> >                                         event_gameresumed;

        //TODO extern lua::event< boost::tuple<int,const char *> >                         event_beginrecord;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_endrecord;

        //TODO extern lua::event< boost::tuple<> >                                         event_started;
        //TODO extern lua::event< boost::tuple<int> >                                      event_shutdown;
        //TODO extern lua::event< boost::tuple<> >                                         event_shutdown_scripting;
        //TODO extern lua::event< boost::tuple<> >                                         event_reloadhopmod;
        //TODO extern lua::event< boost::tuple<const char *> >                             event_varchanged;
        //TODO extern lua::event< boost::tuple<> >                                         event_sleep;
        //TODO extern lua::event< boost::tuple<> >                                         event_interval;
        //TODO extern lua::event< boost::tuple<int, int, int, const char *> >              event_cheat;
    }
}
