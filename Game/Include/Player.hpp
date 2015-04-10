#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	//Id
	int m_playerNr;

	//stats
	float m_moveSpeedCurrent;
	float m_moveSpeedDefault;
	float m_moveSpeedMax;
	float m_accelerationCurrent;
	float m_accelerationDefault;
	float m_accelerationMax;
	float m_jumpHeightCurrent;
	float m_jumpHeightDefault;
	float m_jumpHeightMax;
	int m_jumpNrCurrent;
	int m_jumpNrDefault;
	int m_jumpNrMax;
	float m_airControlCurrent;
	float m_airControlDefault;
	float m_airControlMax;
	float m_groundControlCurrent;
	float m_groundControlDefault;
	float m_groundControlMax;

	int m_score;

public:
	Player(int playerNr);
	virtual ~Player();

	void update();

};

#endif
