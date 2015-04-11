#include <Player.hpp>


//Player::Player(int playerNr)
//{
//	//Id
//	m_playerNr = playerNr;
//
//	//stats
//	m_moveSpeedCurrent = 1;
//	m_moveSpeedDefault = 1;
//	m_moveSpeedMax = 1;
//	m_accelerationCurrent = 1;
//	m_accelerationDefault = 1;
//	m_accelerationMax = 1;
//	m_jumpHeightCurrent = 1;
//	m_jumpHeightDefault = 1;
//	m_jumpHeightMax = 1;
//	m_jumpNrCurrent = 1;
//	m_jumpNrDefault = 1;
//	m_jumpNrMax = 1;
//	m_airControlCurrent = 1;
//	m_airControlDefault = 1;
//	m_airControlMax = 1;
//	m_groundControlCurrent = 1;
//	m_groundControlDefault = 1;
//	m_groundControlMax = 1;
//
//	m_score = 0;
//}

Player::Player(int playerNr, float movespeed, float acceleration, float jumpHeight, int jumpNr, float airControl, float groundControl)
{
	//Id
	m_playerNr = playerNr;

	//stats
	m_moveSpeedCurrent = movespeed;
	m_moveSpeedDefault = movespeed;
	m_moveSpeedMax = 100;
	m_accelerationCurrent = acceleration;
	m_accelerationDefault = acceleration;
	m_accelerationMax = 100;
	m_jumpHeightCurrent = jumpHeight;
	m_jumpHeightDefault = jumpHeight;
	m_jumpHeightMax = 100;
	m_jumpNrCurrent = jumpNr;
	m_jumpNrDefault = jumpNr;
	m_jumpNrMax = 100;
	m_airControlCurrent = airControl;
	m_airControlDefault = airControl;
	m_airControlMax = 100;
	m_groundControlCurrent = groundControl;
	m_groundControlDefault = groundControl;
	m_groundControlMax = 100;

	m_score = 0;
}

Player::~Player()
{
	//
}

void Player::Update(float time)
{

}

void Player::LoadStats()
{

}

void Player::IncreaseScore(int amount)
{
	m_score += amount;
}

void Player::DecreaseScore(int amount)
{
	m_score -= amount;
}

//set
void Player::SetCurrentMoveSpeed(float moveSpeed)
{
	m_moveSpeedCurrent = moveSpeed;
}

void Player::SetDefaultMoveSpeed(float moveSpeed)
{
	m_moveSpeedDefault = moveSpeed;
}

void Player::SetMaxMoveSpeed(float moveSpeed)
{
	m_moveSpeedMax = moveSpeed;
}


void Player::SetCurrentAcceleration(float acceleration)
{
	m_accelerationCurrent = acceleration;
}

void Player::SetDefaultAcceleration(float acceleration)
{
	m_accelerationDefault = acceleration;
}

void Player::SetMaxAcceleration(float acceleration)
{
	m_accelerationMax = acceleration;
}


void Player::SetCurrentJumpHeight(float jumpHeight)
{
	m_jumpHeightCurrent = jumpHeight;
}

void Player::SetDefaultJumpHeight(float jumpHeight)
{
	m_jumpHeightDefault = jumpHeight;
}

void Player::SetMaxJumpHeight(float jumpHeight)
{
	m_jumpHeightMax = jumpHeight;
}


void Player::SetCurrentJumpNr(int jumpNr)
{
	m_jumpNrCurrent = jumpNr;
}

void Player::SetDefaultJumpNr(int jumpNr)
{
	m_jumpNrDefault = jumpNr;
}

void Player::SetMaxJumpNr(int jumpNr)
{
	m_jumpNrMax = jumpNr;
}


void Player::SetCurrentAirControl(float airControl)
{
	m_airControlCurrent = airControl;
}

void Player::SetDefaultAirControl(float airControl)
{
	m_airControlDefault = airControl;
}

void Player::SetMaxAirControl(float airControl)
{
	m_airControlMax = airControl;
}


void Player::SetCurrentGroundControl(float groundControl)
{
	m_groundControlCurrent = groundControl;
}

void Player::SetDefaultGroundControl(float groundControl)
{
	m_groundControlDefault = groundControl;
}

void Player::SetMaxGroundControl(float groundControl)
{
	m_groundControlMax = groundControl;
}


//get
float Player::GetCurrentMoveSpeed()
{
	return m_moveSpeedCurrent;
}

float Player::GetDefaultMoveSpeed()
{
	return m_moveSpeedDefault;
}

float Player::GetMaxMoveSpeed()
{
	return m_moveSpeedDefault;
}


float Player::GetCurrentAcceleration()
{
	return m_accelerationCurrent;
}

float Player::GetDefaultAcceleration()
{
	return m_accelerationDefault;
}

float Player::GetMaxAcceleration()
{
	return m_accelerationMax;
}


float Player::GetCurrentJumpHeight()
{
	return m_jumpHeightCurrent;
}

float Player::GetDefaultJumpHeight()
{
	return m_jumpHeightDefault;
}

float Player::GetMaxJumpHeight()
{
	return m_jumpHeightMax;
}


int Player::GetCurrentJumpNr()
{
	return m_jumpNrCurrent;
}

int Player::GetDefaultJumpNr()
{
	return m_jumpNrDefault;
}

int Player::GetMaxJumpNr()
{
	return m_jumpNrMax;
}


float Player::GetCurrentAirControl()
{
	return m_airControlCurrent;
}

float Player::GetDefaultAirControl()
{
	return m_airControlDefault;
}

float Player::GetMaxAirControl()
{
	return m_airControlMax;
}


float Player::GetCurrentGroundControl()
{
	return m_groundControlCurrent;
}

float Player::GetDefaultGroundControl()
{
	return m_groundControlDefault;
}

float Player::GetMaxGroundControl()
{
	return m_groundControlMax;
}

