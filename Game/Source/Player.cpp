#include <Player.hpp>
#include <LuaScript.hpp>
#include <System/Text.hpp>
#include <Audio/SoundManager.hpp>

Player::Player(int playerNr)
:
	BaseEntity(EntityType::PLAYER),
	m_animating(false)
{
	//Id
	m_playerNr = playerNr;

	//controller
	m_playerController = new XboxController(playerNr);

	m_flag = 0;
	m_animal = 0;

	//PlayerBox
	m_shape.setPosition(100 * (playerNr + 1), 50);
	m_shape.setFillColor(sf::Color((playerNr + 1) * 60, (playerNr + 1) * 20, (playerNr + 1) * 40));
	m_shape.setSize(sf::Vector2f(CHAR_WIDTH, CHAR_HEIGHT));
	m_vel = sf::Vector2f(0, 0);

	m_maxVertSpeed = 7;

	m_isJumping = false;
	m_timesJumped = 0;
	m_timeJumpButtonHeld = 0.f;

	m_score = 0;

	m_isDead = false;
	m_color = -1;

	//InitAnimation("spritesheet_rabbit_5.png");

	m_time = 0;
}

Player::~Player()
{
	// TODO
}

void Player::InitAnimation(std::string texture)
{
	m_animationTexture.loadFromFile(texture);
	//m_animationTexture.loadFromFile("spritesheet_rabbit_5.png");
	
	m_walkingAnimation.setSpriteSheet(m_animationTexture);
	m_walkingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 0, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));
	m_walkingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 1, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));
	m_walkingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 2, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));
	m_walkingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 3, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));
	m_walkingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 4, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));
	m_walkingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 5, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));

	m_jumpingAnimation.setSpriteSheet(m_animationTexture);
	m_jumpingAnimation.addFrame(sf::IntRect(CHAR_WIDTH * 2, CHAR_HEIGHT * m_color, CHAR_WIDTH, CHAR_HEIGHT));

	m_currentAnimation = &m_walkingAnimation;

	m_walkingAnimatedSprite = AnimatedSprite(sf::seconds(0.15), true, true);
	m_walkingAnimatedSprite.setPosition(m_shape.getPosition());
	m_time = 0;
	m_dashTimer = 0;
	m_maxDashTime = 0.05f;
	m_dashing = false;
}

void Player::Update(sf::Time deltaT)
{
	m_deltaT = deltaT;
	m_time = deltaT.asSeconds();
	m_playerController->Update();
	if (!m_isDead)
	{
		HandleMovement(deltaT.asSeconds());
		if (m_vel.x > 0)
		{
			m_animating = true;
			m_walkingAnimatedSprite.SetFlippedXAxis(false);

		}
		else if (m_vel.x < 0)
		{
			m_animating = true;
			m_walkingAnimatedSprite.SetFlippedXAxis(true);
		}

		else
		{
			m_animating = false;
		}
	}
	else
	{
		m_animating = false;
		float grav = 9.81f * 400.f;
		m_vel.y += grav*deltaT.asSeconds();
		m_shape.move(m_vel*deltaT.asSeconds());
	}
	HandleBoundaries();
}

void Player::Render(sf::RenderWindow* window)
{
	//window->draw(m_shape);
	m_walkingAnimatedSprite.play(*m_currentAnimation);
	m_walkingAnimatedSprite.setPosition(m_shape.getPosition());
	if (m_animating)
	{
		m_walkingAnimatedSprite.update(m_deltaT);
	}
	Text score;
	sf::Vector2f scorePos;
	if (m_playerNr == 0)
		scorePos = sf::Vector2f(245.f, 78.f);
	if (m_playerNr == 1)
		scorePos = sf::Vector2f(445.f, 78.f);
	if (m_playerNr == 2)
		scorePos = sf::Vector2f(860.f, 78.f);
	if (m_playerNr == 3)
		scorePos = sf::Vector2f(1057.f, 78.f);
	score.Init(std::to_string(m_score), sf::Color::White, scorePos);
	score.SetSize(15);
	window->draw(score.GetText());
	window->draw(m_walkingAnimatedSprite);
}

void Player::LoadStats(std::string characterName)
{
	if (m_playerController->GetStartButtonState().current)
	{
		LuaScript* characterScript = new LuaScript(characterName);
		m_moveSpeedCurrent = characterScript->GetVariable<float>("m_moveSpeedCurrent");
		m_moveSpeedDefault = characterScript->GetVariable<float>("m_moveSpeedDefault");
		m_moveSpeedMax = characterScript->GetVariable<float>("m_moveSpeedMax");
		m_accelerationCurrent = characterScript->GetVariable<float>("m_accelerationCurrent");
		m_accelerationDefault = characterScript->GetVariable<float>("m_accelerationDefault");
		m_accelerationMax = characterScript->GetVariable<float>("m_accelerationMax");
		m_jumpHeightCurrent = characterScript->GetVariable<float>("m_jumpHeightCurrent");
		m_jumpHeightDefault = characterScript->GetVariable<float>("m_jumpHeightDefault");
		m_jumpHeightMax = characterScript->GetVariable<float>("m_jumpHeightMax");
		m_jumpNrCurrent = characterScript->GetVariable<int>("m_jumpNrCurrent");
		m_jumpNrDefault = characterScript->GetVariable<int>("m_jumpNrDefault");
		m_jumpNrMax = characterScript->GetVariable<int>("m_jumpNrMax");
		m_airControlCurrent = characterScript->GetVariable<float>("m_airControlCurrent");
		m_airControlDefault = characterScript->GetVariable<float>("m_airControlDefault");
		m_airControlMax = characterScript->GetVariable<float>("m_airControlMax");
		m_groundControlCurrent = characterScript->GetVariable<float>("m_groundControlCurrent");
		m_groundControlDefault = characterScript->GetVariable<float>("m_groundControlDefault");
		m_groundControlMax = characterScript->GetVariable<float>("m_groundControlMax");
	}
}


void Player::LoadInitStats(std::string characterName)
{
	LuaScript* characterScript = new LuaScript(characterName);
	m_moveSpeedCurrent = characterScript->GetVariable<float>("m_moveSpeedCurrent");
	m_moveSpeedDefault = characterScript->GetVariable<float>("m_moveSpeedDefault");
	m_moveSpeedMax = characterScript->GetVariable<float>("m_moveSpeedMax");
	m_accelerationCurrent = characterScript->GetVariable<float>("m_accelerationCurrent");
	m_accelerationDefault = characterScript->GetVariable<float>("m_accelerationDefault");
	m_accelerationMax = characterScript->GetVariable<float>("m_accelerationMax");
	m_jumpHeightCurrent = characterScript->GetVariable<float>("m_jumpHeightCurrent");
	m_jumpHeightDefault = characterScript->GetVariable<float>("m_jumpHeightDefault");
	m_jumpHeightMax = characterScript->GetVariable<float>("m_jumpHeightMax");
	m_jumpNrCurrent = characterScript->GetVariable<int>("m_jumpNrCurrent");
	m_jumpNrDefault = characterScript->GetVariable<int>("m_jumpNrDefault");
	m_jumpNrMax = characterScript->GetVariable<int>("m_jumpNrMax");
	m_airControlCurrent = characterScript->GetVariable<float>("m_airControlCurrent");
	m_airControlDefault = characterScript->GetVariable<float>("m_airControlDefault");
	m_airControlMax = characterScript->GetVariable<float>("m_airControlMax");
	m_groundControlCurrent = characterScript->GetVariable<float>("m_groundControlCurrent");
	m_groundControlDefault = characterScript->GetVariable<float>("m_groundControlDefault");
	m_groundControlMax = characterScript->GetVariable<float>("m_groundControlMax");
}

void Player::HandleBoundaries()
{
	//Sides
	if (m_shape.getPosition().x > 1280.f) //Hardcoded values woo!
	{
		m_shape.setPosition(-m_shape.getSize().x, m_shape.getPosition().y);
	}
	else if (m_shape.getPosition().x < -m_shape.getSize().x)
	{
		m_shape.setPosition(1280.f, m_shape.getPosition().y);
	}
	//Down
	if (m_shape.getPosition().y > 850.f) //Hardcoded values woo!
	{
		m_shape.setPosition(m_shape.getPosition().x, 0.f);
		m_isDead = false;
		m_walkingAnimatedSprite.SetFlippedYAxis(false);
	}
}

void Player::HandleMovement(float deltaT)
{
	float grav = 9.81f * 400.f;
	float acc = 100.f * m_accelerationCurrent;
	bool notMoving = true;
	float controlStickNormalized = m_playerController->GetLStickXState().current / 100.f;
	float adjuster = std::abs(std::pow(controlStickNormalized, 1));
	if (m_playerController->GetLStickXState().current < 0)
	{
		notMoving = false;
		if (m_timesJumped > 0)
			m_vel.x -= acc*deltaT * m_airControlCurrent;
		else
			m_vel.x -= acc*deltaT * m_groundControlCurrent;
		if (m_vel.x < -1.f * adjuster * m_moveSpeedCurrent)
		{
			m_vel.x = -1.f * adjuster * m_moveSpeedCurrent;
		}
	}
	else if (m_playerController->GetLStickXState().current > 0)
	{
		notMoving = false;
		if (m_timesJumped > 0)
			m_vel.x += acc*deltaT * m_airControlCurrent;
		else
			m_vel.x += acc*deltaT * m_groundControlCurrent;
		if (m_vel.x > adjuster * m_moveSpeedCurrent)
		{
			m_vel.x = adjuster * m_moveSpeedCurrent;
		}
	}
	if (notMoving)
	{
		float friction = 3000.f;
		if (m_vel.x > 0.f)
		{
			m_vel.x -= friction * deltaT;
			if (m_vel.x < 0.f)
				m_vel.x = 0.f;
		}
		else if (m_vel.x < 0.f)
		{
			m_vel.x += friction * deltaT;
			if (m_vel.x > 0.f)
				m_vel.x = 0.f;
		}
	}

	//Handle jump

	if (m_playerController->GetAButtonState().current == true && m_timesJumped < m_jumpNrCurrent)
	{
		m_currentAnimation = &m_jumpingAnimation;
		if (m_playerController->GetAButtonState().last == false)
		{
			m_timeJumpButtonHeld = 0;
			m_vel.y = -m_jumpHeightCurrent;
		}
		else
		{
			m_timeJumpButtonHeld += deltaT;
			if (m_timeJumpButtonHeld < 0.2f)
			{
				m_vel.y = -m_jumpHeightCurrent;
			}
		}
	}
	else if (m_playerController->GetAButtonState().current == false && m_playerController->GetAButtonState().last == true)
	{
		m_timesJumped++;
	}

	if (m_playerController->GetLTriggerState().current < -0.1f || m_playerController->GetRTriggerState().current < -0.1f) // Any of the two L/R buttons
	{
		if (m_playerController->GetLTriggerState().current < -0.1f && m_playerController->GetLTriggerState().last > -0.1)
		{
			m_dashing = true;
			m_dashTimer = 0.0f;
			SoundManager::GetSoundManagerContext()->PlaySound("Audio/Dash.flac");
		}
		else if (m_playerController->GetRTriggerState().current < -0.1f && m_playerController->GetRTriggerState().last > -0.1)
		{
			m_dashing = true;
			m_dashTimer = 0.0f;
			SoundManager::GetSoundManagerContext()->PlaySound("Audio/Dash.flac");
		}		
		if (m_playerController->GetLTriggerState().current < -0.1f && m_dashTimer < m_maxDashTime)
		{
			m_vel.x = -1500.0f;
		}
		else if (m_playerController->GetRTriggerState().current < -0.1f && m_dashTimer < m_maxDashTime)
		{
			m_vel.x = 1500.0f;
		}		
	}
	if (m_dashing)
	{
		m_dashTimer += deltaT;
		if (m_dashTimer > m_maxDashTime)
		{
			m_dashing = false;
		}
	}

	//Gravity
	if (!m_dashing)
		m_vel.y += grav*deltaT;
	m_shape.move(m_vel*deltaT); //os?ker
}

void Player::IncreaseScore(int amount)
{
	m_score += amount;
}

void Player::DecreaseScore(int amount)
{
	m_score -= amount;
}

sf::FloatRect Player::getCollisionRect()
{
	m_shape.setSize(sf::Vector2f(CHAR_WIDTH / 2, CHAR_HEIGHT));
	m_shape.move(sf::Vector2f(CHAR_WIDTH / 4, 0));
	sf::FloatRect temp = m_shape.getGlobalBounds();
	m_shape.move(sf::Vector2f(-CHAR_WIDTH / 4, 0));
	m_shape.setSize(sf::Vector2f(CHAR_WIDTH, CHAR_HEIGHT));

	return temp;
}

void Player::CollisionEvent(sf::Vector2f velocity)
{
	m_shape.move(velocity);
	if (velocity.y < 0)
	{
		m_vel.y = 0;
		m_timesJumped = 0;
		m_currentAnimation = &m_walkingAnimation;
	}
	else if (velocity.y > 0)
	{
		m_vel.y = 0;
	}
}

void Player::PlayerCollisionEvent(sf::Vector2f velocity)
{
	m_shape.move(velocity.x, 0);
	if (velocity.y < 0)
	{
		m_vel.y -= m_jumpHeightCurrent * 1.7f;
		IncreaseScore(1);
	}
	else if (velocity.y > 0)
	{
		//Start death animation
		m_isDead = true;
		m_walkingAnimatedSprite.SetFlippedYAxis(true);
	}
}


void Player::SetAnimal(int animal)
{
	m_animal = animal;
}

void Player::SetFlag(int flag)
{
	m_flag = flag;
}

int Player::GetAnimal()
{
	return m_animal;
}

int Player::GetFlag()
{
	return m_flag;
}


//set
void Player::SetTextureName(std::string texture)
{
	m_textureName = texture;
}

void Player::SetScriptName(std::string script)
{
	m_scriptName = script;
}

void Player::SetColor(int color)
{
	m_color = color;
}

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

