#include <PlayerContext.hpp>
#include <Player.hpp>


PlayerContext::PlayerContext()
{

}

PlayerContext::~PlayerContext()
{
	
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