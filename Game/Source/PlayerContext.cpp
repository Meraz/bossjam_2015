#include <PlayerContext.hpp>
#include <Player.hpp>

PlayerContext* PlayerContext::m_context = nullptr;

PlayerContext::PlayerContext()
{
	NrOfActivePlayers = 0;
	m_players[0] = nullptr;
	m_players[1] = nullptr;
	m_players[2] = nullptr;
	m_players[3] = nullptr;
}

Player* PlayerContext::GetPlayer(int index)
{
	if (m_players[index] == nullptr)
	{
		m_players[index] = new Player(index);
		//m_players.at(index)->Init or reset 
	}
	return m_players[index];
}

PlayerContext* PlayerContext::GetPlayerContext()
{
	if (m_context == nullptr)
	{
		m_context = new PlayerContext();
	}
	return m_context;
}