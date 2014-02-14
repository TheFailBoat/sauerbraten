#pragma once

#define AUTOPROP(T, N) private: T p_ ## N; public: virtual property T N { T get() { return p_ ## N; } void set(T value) { p_ ## N = value; } }

public ref class ClientInfo : public Sauerbraten::Interfaces::IClientInfo
{
public:
	ClientInfo();
	~ClientInfo();

	AUTOPROP(int, ClientNumber);

	AUTOPROP(System::String^, Name);
	AUTOPROP(System::String^, Team);

	AUTOPROP(int, PlayerModel);

	AUTOPROP(int, Privilege);
	AUTOPROP(bool, Connected);
	AUTOPROP(bool, Local);

	AUTOPROP(Sauerbraten::Interfaces::IGameState^, State);

	AUTOPROP(int, Ping); 
};

public ref class GameState : public Sauerbraten::Interfaces::IGameState
{
public:
	GameState();
	~GameState();

	AUTOPROP(float, X);
	AUTOPROP(float, Y);
	AUTOPROP(float, Z);

	AUTOPROP(int, Health);
	AUTOPROP(int, MaxHealth);
	AUTOPROP(int, Armour);

	AUTOPROP(int, GunSelect);
	AUTOPROP(int, GunWait);

	AUTOPROP(int, State);
	AUTOPROP(int, EditState);

	AUTOPROP(int, LastDeath);
	AUTOPROP(int, LastSpawn);
	AUTOPROP(int, LastShot);

	AUTOPROP(int, Frags);
	AUTOPROP(int, Flags);
	AUTOPROP(int, Deaths);
	AUTOPROP(int, Teamkills);
	AUTOPROP(int, ShotDamage);
	AUTOPROP(int, Damage);
	AUTOPROP(int, Tokens);
	AUTOPROP(int, Suicides);
	AUTOPROP(int, Hits);
	AUTOPROP(int, Misses);
	AUTOPROP(int, Shots);

	AUTOPROP(int, TimePlayed);
};

