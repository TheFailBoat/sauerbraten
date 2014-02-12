using System.Collections.Generic;
using System.Security.Cryptography.X509Certificates;

namespace Sauerbraten.Interfaces
{
    public interface IServer
    {
        IReadOnlyList<IPlugin> Plugins { get; }

        void SetMasterMode(int value, int cn = -1);
    }
}
