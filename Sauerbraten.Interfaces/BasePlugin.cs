using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sauerbraten.Interfaces
{
    public abstract class BasePlugin : IPlugin
    {
        public virtual bool OnInit()
        {
            return true;
        }

        public virtual bool OnConnecting(int clientNumber, string hostname, string name, string password, bool isReserved)
        {
            return true;
        }
        public virtual bool OnConnect(int clientNumber, bool spy)
        {
            return true;
        }
        public virtual bool OnDisconnect(int clientNumber, string reason)
        {
            return true;
        }
        public virtual bool OnFailedConnect(string hostname, string reason)
        {
            return true;
        }

        public bool OnRenaming(int clientNumber)
        {
            return true;
        }
        public bool OnAllowRename(int clientNumber, string newName)
        {
            return true;
        }
        public bool OnRename(int clientNumber, string oldName, string newName)
        {
            return true;
        }

        public bool OnTeamChange(int clientNumber, string oldTeam, string newTeam)
        {
            return true;
        }
        public bool OnTeamChangeRequest(int clientNumber, string oldTeam, string newTeam)
        {
            return true;
        }

        public bool OnText(int clientNumber, string text)
        {
            return true;
        }
        public bool OnSayTeam(int clientNumber, string text)
        {
            return true;
        }
        public bool OnServerCommand(int clientNumber, string text)
        {
            return true;
        }

        public bool OnMapVote(int clientNumber, string map, string mode)
        {
            return true;
        }
        public bool OnMapVotePassed(string map, string mode)
        {
            return true;
        }

        public bool OnSetMasterMode(int clientNumber, string oldMode, string newMode)
        {
            return true;
        }
        public bool OnSetMasterModeRequest(int a, string oldMode, string newMode)
        {
            return true;
        }
        public bool OnSpectator(int clientNumber)
        {
            return true;
        }
        public bool OnPrivilege(int clientNumber, int oldLevel, int newLevel)
        {
            return true;
        }
        public bool OnSetMaster(int clientNumber, string password, bool force)
        {
            return true;
        }
        public bool OnClearBansRequest()
        {
            return true;
        }
        public bool OnKickRequest(int kickerClientNumber, string kickerName, int banTime, int victimClientNumber, string victimName)
        {
            return true;
        }

        public bool OnAuthRequest(int clientNumber, string username, string domain)
        {
            return true;
        }
        public bool OnAuthResponse(int clientNumber, int id, string val)
        {
            return true;
        }

        public bool OnModMap(int clientNumber, string map, int crc)
        {
            return true;
        }

        public bool OnTeamkill(int actorClientNumber, int targetClientNumber)
        {
            return true;
        }
        public bool OnFrag(int actorClientNumber, int targetClientNumber)
        {
            return true;
        }
        public bool OnShot(int clientNumber, int weapon, int hits)
        {
            return true;
        }
        public bool OnSuicide(int clientNumber)
        {
            return true;
        }
        public bool OnSpawn(int clientNumber)
        {
            return true;
        }
        public bool OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon)
        {
            return true;
        }
        public bool OnTakeFlag(int clientNumber, string team)
        {
            return true;
        }
        public bool OnDropFlag(int clientNumber, string team)
        {
            return true;
        }
        public bool OnScoreFlag(int clientNumber, string team, int score)
        {
            return true;
        }
        public bool OnReturnFlag(int clientNumber, string team)
        {
            return true;
        }
        public bool OnFlagReset(string team)
        {
            return true;
        }
        public bool OnScoreUpdate(string team, int score)
        {
            return true;
        }
    }
}
