using System.Collections.Generic;

namespace Sauerbraten.Interfaces
{
    public interface IServer
    {
        IReadOnlyList<IPlugin> Plugins { get; }
    }
}
