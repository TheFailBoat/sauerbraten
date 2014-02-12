using System.Collections.Generic;

namespace Sauerbraten.Interfaces
{
    public interface IServer
    {
        IReadOnlyList<IPlugin> Plugins { get; }

        void SetMasterMode(int value, int cn = -1);
    }
}
