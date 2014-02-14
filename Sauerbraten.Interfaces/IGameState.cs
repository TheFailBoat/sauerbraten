namespace Sauerbraten.Interfaces
{
    public interface IGameState
    {
        float X { get; }
        float Y { get; }
        float Z { get; }

        int Health { get; }
        int MaxHealth { get; }
        int Armour { get; }

        int GunSelect { get; }
        int GunWait { get; }
        
        int State { get; }
        int EditState { get; }

        int LastDeath { get; }
        int LastSpawn { get; }
        int LastShot { get; }

        int Frags { get; }
        int Flags { get; }
        int Deaths { get; }
        int Teamkills { get; }
        int ShotDamage { get; }
        int Damage { get; }
        int Tokens { get; }
        int Suicides { get; }
        int Hits { get; }
        int Misses { get; }
        int Shots { get; }

        int TimePlayed { get; }
    }
}
