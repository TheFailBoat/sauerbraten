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
    }
}
