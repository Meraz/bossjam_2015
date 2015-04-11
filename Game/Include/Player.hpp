#ifndef PLAYER_H
#define PLAYER_H

#include <string>

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
	//(int playerNr);
	Player(int playerNr);
	virtual ~Player();

	void Update(float time);

	void LoadStats(std::string characterName);

	void IncreaseScore(int amount);
	void DecreaseScore(int amount);


	//Set
	void SetCurrentMoveSpeed(float moveSpeed);
	void SetDefaultMoveSpeed(float moveSpeed);
	void SetMaxMoveSpeed(float moveSpeed);

	void SetCurrentAcceleration(float acceleration);
	void SetDefaultAcceleration(float acceleration);
	void SetMaxAcceleration(float acceleration);

	void SetCurrentJumpHeight(float jumpHeight);
	void SetDefaultJumpHeight(float jumpHeight);
	void SetMaxJumpHeight(float jumpHeight);

	void SetCurrentJumpNr(int jumpNr);
	void SetDefaultJumpNr(int jumpNr);
	void SetMaxJumpNr(int jumpNr);

	void SetCurrentAirControl(float airControl);
	void SetDefaultAirControl(float airControl);
	void SetMaxAirControl(float airControl);

	void SetCurrentGroundControl(float groundControl);
	void SetDefaultGroundControl(float groundControl);
	void SetMaxGroundControl(float groundControl);

	//get
	float GetCurrentMoveSpeed();
	float GetDefaultMoveSpeed();
	float GetMaxMoveSpeed();

	float GetCurrentAcceleration();
	float GetDefaultAcceleration();
	float GetMaxAcceleration();

	float GetCurrentJumpHeight();
	float GetDefaultJumpHeight();
	float GetMaxJumpHeight();

	int GetCurrentJumpNr();
	int GetDefaultJumpNr();
	int GetMaxJumpNr();

	float GetCurrentAirControl();
	float GetDefaultAirControl();
	float GetMaxAirControl();

	float GetCurrentGroundControl();
	float GetDefaultGroundControl();
	float GetMaxGroundControl();


};

#endif
