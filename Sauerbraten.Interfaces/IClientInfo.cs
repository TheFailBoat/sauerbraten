namespace Sauerbraten.Interfaces
{
    public interface IClientInfo
    {
        int ClientNumber { get; }

        string Name { get; }
        string Team { get; }

        int PlayerModel { get; }

        int Privilege { get; }
        bool Connected { get; }
        bool Local { get; }

        IGameState State { get; }

        int Ping { get; }
    }
}
