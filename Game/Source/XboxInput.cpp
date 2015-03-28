#include "XboxInput.hpp"


XboxInput::XboxInput(int playerNr)
{
	m_PlayerNr = playerNr;
	m_deadZone = 20;
}

XboxInput::~XboxInput()
{
}

void XboxInput::setDeadZone(int deadZone)
{
	m_deadZone = deadZone;
}

#pragma region BUTTONS

bool XboxInput::isAbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 0);
}

bool XboxInput::isBbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 1);
}

bool XboxInput::isXbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 2);
}

bool XboxInput::isYbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 3);
}

bool XboxInput::isLBbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 4);
}

bool XboxInput::isRBbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 5);
}

bool XboxInput::isBackbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 6);
}

bool XboxInput::isStartbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 7);
}

bool XboxInput::isLThumbStickPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 8);
}

bool XboxInput::isRThumbStickPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 9);
}

#pragma endregion


#pragma region AXISES

float XboxInput::getLThumbStickX()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::X);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}

float XboxInput::getLThumbStickY()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::Y);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}


float XboxInput::getRThumbStickX()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::U);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}

float XboxInput::getRThumbStickY()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::R);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}

float  XboxInput::getDPadX()
{
	return sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::PovX);
}

float XboxInput::getDPadY()
{
	return -sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::PovY);
}

#pragma endregion


#pragma region TRIGGERS

//TRIGGERS
float XboxInput::getLTrigger()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::Z);

	if (position < 0)
		position = 0;

	return -position;
}

float XboxInput::getRTrigger()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::Z);

	if (position > 0)
		position = 0;

	return position;
}

#pragma endregion