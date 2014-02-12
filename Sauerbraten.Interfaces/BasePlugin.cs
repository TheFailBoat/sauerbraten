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
    }
}
