using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sauerbraten.Interfaces
{
    public interface IPlugin
    {
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

        //TODO extern lua::event< boost::tuple<int,const char *> >                         event_text;
        //TODO extern lua::event< boost::tuple<int,const char *> >                         event_sayteam;
        //TODO extern lua::event< boost::tuple<int,const char *> >                         event_servcmd;

        //TODO extern lua::event< boost::tuple<int,const char *,const char *> >            event_mapvote;
        //TODO extern lua::event< boost::tuple<int, const char *,const char *> >           event_setmastermode;
        //TODO extern lua::event< boost::tuple<int, const char *,const char *> >           event_setmastermode_request;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_spectator;
        //TODO extern lua::event< boost::tuple<int,int,int> >                              event_privilege;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_teamkill;
        //TODO extern lua::event< boost::tuple<int,const char *,const char *> >            event_authreq;
        //TODO extern lua::event< boost::tuple<int,int,const char *> >                     event_authrep;
        //TODO extern lua::event< boost::tuple<int,int,int> >                              event_addbot;
        //TODO extern lua::event< boost::tuple<int> >                                      event_delbot;
        //TODO extern lua::event< boost::tuple<int> >                                      event_botleft;
        //TODO extern lua::event< boost::tuple<int, const char *, int> >                   event_modmap;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_teamkill;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_frag;
        //TODO extern lua::event< boost::tuple<int,int,int> >                              event_shot;
        //TODO extern lua::event< boost::tuple<int> >                                      event_suicide;
        //TODO extern lua::event< boost::tuple<int> >                                      event_spawn;
        //TODO extern lua::event< boost::tuple<int, int, int, int> >                       event_damage;
        //TODO extern lua::event< boost::tuple<int,const char*,bool> >                     event_setmaster;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_respawnrequest;
        //TODO extern lua::event< boost::tuple<> >                                         event_clearbans_request;
        //TODO extern lua::event< boost::tuple<int, const char *, int, int, const char *> >  event_kick_request;
        //TODO extern lua::event< boost::tuple<> >                                         event_intermission;
        //TODO extern lua::event< boost::tuple<> >                                         event_finishedgame;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_timeupdate;
        //TODO extern lua::event< boost::tuple<const char *,const char *> >                event_mapchange;
        //TODO extern lua::event< boost::tuple<> >                                         event_setnextgame;
        //TODO extern lua::event< boost::tuple<> >                                         event_gamepaused;
        //TODO extern lua::event< boost::tuple<> >                                         event_gameresumed;
        //TODO extern lua::event< boost::tuple<int,const char *> >                         event_beginrecord;
        //TODO extern lua::event< boost::tuple<int,int> >                                  event_endrecord;
        //TODO extern lua::event< boost::tuple<const char *,const char *> >                event_votepassed;
        //TODO extern lua::event< boost::tuple<int, const char *> >                        event_takeflag;
        //TODO extern lua::event< boost::tuple<int, const char *> >                        event_dropflag;
        //TODO extern lua::event< boost::tuple<int, const char *, int> >                   event_scoreflag;
        //TODO extern lua::event< boost::tuple<int, const char *> >                        event_returnflag;
        //TODO extern lua::event< boost::tuple<const char *> >                             event_resetflag;
        //TODO extern lua::event< boost::tuple<const char *, int> >                        event_scoreupdate;
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
