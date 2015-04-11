#ifndef PLAYERCONTEXT_H
#define PLAYECONTEXTR_H

#include <vector>

class Player;

class PlayerContext
{
public:
	static PlayerContext* GetPlayerContext();
	Player* GetPlayer(int index);
private:
	PlayerContext();
	~PlayerContext(){};

	static PlayerContext* m_context;
	Player* m_players[4];
};

#endif
