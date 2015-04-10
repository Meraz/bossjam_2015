#include <Player.hpp>


Player::Player(int playerNr)
{
	//Id
	m_playerNr = playerNr;

	//stats
	m_moveSpeedCurrent = 1;
	m_moveSpeedDefault = 1;
	m_moveSpeedMax = 1;
	m_accelerationCurrent = 1;
	m_accelerationDefault = 1;
	m_accelerationMax = 1;
	m_jumpHeightCurrent = 1;
	m_jumpHeightDefault = 1;
	m_jumpHeightMax = 1;
	m_jumpNrCurrent = 1;
	m_jumpNrDefault = 1;
	m_jumpNrMax = 1;
	m_airControlCurrent = 1;
	m_airControlDefault = 1;
	m_airControlMax = 1;
	m_groundControlCurrent = 1;
	m_groundControlDefault = 1;
	m_groundControlMax = 1;

	m_score = 0;
}

Player::~Player()
{
	//
}

void Player::update()
{

}