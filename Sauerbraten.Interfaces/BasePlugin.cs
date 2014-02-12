namespace Sauerbraten.Interfaces
{
    public abstract class BasePlugin : IPlugin
    {
        public abstract string Name { get; }

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

        public virtual bool OnRenaming(int clientNumber)
        {
            return true;
        }
        public virtual bool OnAllowRename(int clientNumber, string newName)
        {
            return true;
        }
        public virtual bool OnRename(int clientNumber, string oldName, string newName)
        {
            return true;
        }

        public virtual bool OnTeamChange(int clientNumber, string oldTeam, string newTeam)
        {
            return true;
        }
        public virtual bool OnTeamChangeRequest(int clientNumber, string oldTeam, string newTeam)
        {
            return true;
        }

        public virtual bool OnText(int clientNumber, string text)
        {
            return true;
        }
        public virtual bool OnSayTeam(int clientNumber, string text)
        {
            return true;
        }
        public virtual bool OnServerCommand(int clientNumber, string text)
        {
            return true;
        }

        public virtual bool OnMapVote(int clientNumber, string map, string mode)
        {
            return true;
        }
        public virtual bool OnMapVotePassed(string map, string mode)
        {
            return true;
        }

        public virtual bool OnSetMasterMode(int clientNumber, string oldMode, string newMode)
        {
            return true;
        }
        public virtual bool OnSetMasterModeRequest(int a, string oldMode, string newMode)
        {
            return true;
        }
        public virtual bool OnSpectator(int clientNumber)
        {
            return true;
        }
        public virtual bool OnPrivilege(int clientNumber, int oldLevel, int newLevel)
        {
            return true;
        }
        public virtual bool OnSetMaster(int clientNumber, string password, bool force)
        {
            return true;
        }
        public virtual bool OnClearBansRequest()
        {
            return true;
        }
        public virtual bool OnKickRequest(int kickerClientNumber, string kickerName, int banTime, int victimClientNumber, string victimName)
        {
            return true;
        }

        public virtual bool OnAuthRequest(int clientNumber, string username, string domain)
        {
            return true;
        }
        public virtual bool OnAuthResponse(int clientNumber, int id, string val)
        {
            return true;
        }

        public virtual bool OnModMap(int clientNumber, string map, int crc)
        {
            return true;
        }

        public virtual bool OnTeamkill(int actorClientNumber, int targetClientNumber)
        {
            return true;
        }
        public virtual bool OnFrag(int actorClientNumber, int targetClientNumber)
        {
            return true;
        }
        public virtual bool OnShot(int clientNumber, int weapon, int hits)
        {
            return true;
        }
        public virtual bool OnSuicide(int clientNumber)
        {
            return true;
        }
        public virtual bool OnSpawn(int clientNumber)
        {
            return true;
        }
        public virtual bool OnDamage(int actorClientNumber, int targetClientNumber, int damage, int weapon)
        {
            return true;
        }
        public virtual bool OnTakeFlag(int clientNumber, string team)
        {
            return true;
        }
        public virtual bool OnDropFlag(int clientNumber, string team)
        {
            return true;
        }
        public virtual bool OnScoreFlag(int clientNumber, string team, int score)
        {
            return true;
        }
        public virtual bool OnReturnFlag(int clientNumber, string team)
        {
            return true;
        }
        public virtual bool OnFlagReset(string team)
        {
            return true;
        }
        public virtual bool OnScoreUpdate(string team, int score)
        {
            return true;
        }
    }
}
