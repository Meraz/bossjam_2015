#ifndef PLAYERCONTEXT_H
#define PLAYECONTEXTR_H

#include <vector>

class Player;

class PlayerContext
{
public:
	static Player* GetPlayer(int index);
private:
	PlayerContext(){};
	~PlayerContext(){};

	static Player* m_players[4];
};

#endif
