using System.Collections.Generic;

namespace Sauerbraten.Interfaces
{
    public interface IServer
    {
        IReadOnlyList<IPlugin> Plugins { get; }

        void SetMasterMode(int value, int cn = -1);

        void SendMessage(string text);
        void SendTeamMessage(string team, string text);
        void SendPrivateMessage(int clientNumber, string text);

        int GetClientNumber(string name);

        IEnumerable<int> GetPlayers();
        IEnumerable<int> GetPlayers(string team);
        IEnumerable<string> GetTeams();

        IClientInfo GetClientInfo(int cn);
        IClientInfo GetClientInfo(string name);
    }
}
