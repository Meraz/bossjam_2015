#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include <Entity/Impl/BaseEntity.hpp>

#include <SFML/Graphics.hpp>
#include <System/XboxInput.hpp>
#include <Sprite/AnimatedSprite.hpp>
#include <Sprite/Animation.hpp>
#define CHAR_WIDTH 44
#define CHAR_HEIGHT 75
#include <XboxController.hpp>

enum class MovementDirection
{
	LEFT,
	RIGHT
};

class Player : public BaseEntity
{
private:
	//Id
	int m_playerNr;

	//PlayerBox
	sf::Vector2f m_vel;
	float m_maxVertSpeed;

	bool m_isJumping;
	int m_timesJumped;
	float m_timeJumpButtonHeld;


	//controller
	XboxController* m_playerController;

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

	std::string m_textureName;
	std::string m_scriptName;
	int m_color;
	
	int m_score;
	sf::Texture m_animationTexture;
	Animation* m_currentAnimation;
	Animation m_walkingAnimation;
	Animation m_jumpingAnimation;
	AnimatedSprite m_walkingAnimatedSprite; 
	float m_time;
	sf::Time m_deltaT;
	bool m_animating;

	bool m_isDead;

	void InitAnimation(std::string texture);
	void HandleBoundaries();

public:
	//(int playerNr);
	Player(int playerNr);
	virtual ~Player();

	void Update(sf::Time deltaT) override;
	void Render(sf::RenderWindow* window) override;

	void LoadStats(std::string characterName);
	void LoadInitStats(std::string characterName);
	void HandleMovement(float deltaT);

	void IncreaseScore(int amount);
	void DecreaseScore(int amount);

	sf::FloatRect getCollisionRect() override;
	void CollisionEvent(sf::Vector2f velocity);
	void PlayerCollisionEvent(sf::Vector2f velocity);

	bool IsDead() { return m_isDead; };

	//Set
	void SetTextureName(std::string texture);
	void SetScriptName(std::string script);
	void SetColor(int color);

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
	std::string GetTextureName() { return m_textureName; };
	std::string GetScriptName() { return m_scriptName; };
	int GetColor() { return m_color; };

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

	XboxController* GetController() { return m_playerController; };
};

#endif
