#include <Player.hpp>
#include <LuaScript.hpp>

Player::Player(int playerNr)
:
	BaseEntity(EntityType::PLAYER)
{
	//Id
	m_playerNr = playerNr;

	//controller
	m_playerController = new XboxController(playerNr);
		
	//PlayerBox
	m_shape.setSize(sf::Vector2f(100, 100));
	m_shape.setFillColor(sf::Color(playerNr * 60, playerNr * 20, playerNr * 40));


	m_score = 0;


	m_walking.setSpriteSheet(m_animationTexture);
	m_walking.addFrame(sf::IntRect(88, 0, CHAR_WIDTH, CHAR_HEIGHT));
	m_walking.addFrame(sf::IntRect(88 * 1, 0, CHAR_WIDTH, CHAR_HEIGHT));
	m_walking.addFrame(sf::IntRect(88 * 2, 0, CHAR_WIDTH, CHAR_HEIGHT));
	m_walking.addFrame(sf::IntRect(88 * 3, 0, CHAR_WIDTH, CHAR_HEIGHT));
	m_walking.addFrame(sf::IntRect(88 * 4, 0, CHAR_WIDTH, CHAR_HEIGHT));
	m_currentAnimation = &m_walking;

	m_walkingAnimatedSprite = AnimatedSprite(sf::seconds(0.2), true, true);
	//m_walkingAnimatedSprite.set
	m_walkingAnimatedSprite.setPosition(sf::Vector2f(m_collisionRectangle.left, m_collisionRectangle.top));
}

Player::~Player()
{
	//
}

void Player::Update(float deltaT)
{

}

void Player::Render(sf::RenderWindow* window)
{
//	m_walkingAnimatedSprite.play(*m_currentAnimation);
//	m_walkingAnimatedSprite.move(
}

void Player::LoadStats(std::string characterName)
{
	LuaScript* characterScript = new LuaScript(characterName);
	m_moveSpeedCurrent		 = characterScript->GetVariable<float>("m_moveSpeedCurrent");
	m_moveSpeedDefault		 = characterScript->GetVariable<float>("m_moveSpeedDefault");
	m_moveSpeedMax			 = characterScript->GetVariable<float>("m_moveSpeedMax");
	m_accelerationCurrent	 = characterScript->GetVariable<float>("m_accelerationCurrent");
	m_accelerationDefault	 = characterScript->GetVariable<float>("m_accelerationDefault");
	m_accelerationMax		 = characterScript->GetVariable<float>("m_accelerationMax");
	m_jumpHeightCurrent		 = characterScript->GetVariable<float>("m_jumpHeightCurrent");
	m_jumpHeightDefault		 = characterScript->GetVariable<float>("m_jumpHeightDefault");
	m_jumpHeightMax			 = characterScript->GetVariable<float>("m_jumpHeightMax");
	m_jumpNrCurrent			 = characterScript->GetVariable<int>("m_jumpNrCurrent");
	m_jumpNrDefault			 = characterScript->GetVariable<int>("m_jumpNrDefault");
	m_jumpNrMax				 = characterScript->GetVariable<int>("m_jumpNrMax");
	m_airControlCurrent		 = characterScript->GetVariable<float>("m_airControlCurrent");
	m_airControlDefault		 = characterScript->GetVariable<float>("m_airControlDefault");
	m_airControlMax			 = characterScript->GetVariable<float>("m_airControlMax");
	m_groundControlCurrent	 = characterScript->GetVariable<float>("m_groundControlCurrent");
	m_groundControlDefault	 = characterScript->GetVariable<float>("m_groundControlDefault");
	m_groundControlMax		 = characterScript->GetVariable<float>("m_groundControlMax");
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

