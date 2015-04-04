#include <System/XboxInput.hpp>


XboxInput::XboxInput(int playerNr)
{
	m_PlayerNr = playerNr;
	m_deadZone = 20;
}

XboxInput::~XboxInput()
{
}

void XboxInput::SetDeadZone(int deadZone)
{
	m_deadZone = deadZone;
}

#pragma region BUTTONS

bool XboxInput::IsAbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 0);
}

bool XboxInput::IsBbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 1);
}

bool XboxInput::IsXbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 2);
}

bool XboxInput::IsYbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 3);
}

bool XboxInput::IsLBbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 4);
}

bool XboxInput::IsRBbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 5);
}

bool XboxInput::IsBackbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 6);
}

bool XboxInput::IsStartbuttonPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 7);
}

bool XboxInput::IsLThumbStickPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 8);
}

bool XboxInput::IsRThumbStickPressed()
{
	return sf::Joystick::isButtonPressed(m_PlayerNr, 9);
}

#pragma endregion


#pragma region AXISES

float XboxInput::GetLThumbStickX()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::X);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}

float XboxInput::GetLThumbStickY()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::Y);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}


float XboxInput::GetRThumbStickX()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::U);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}

float XboxInput::GetRThumbStickY()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::R);

	if (position < m_deadZone && position > -m_deadZone)
		position = 0;

	return position;
}

float  XboxInput::GetDPadX()
{
	return sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::PovX);
}

float XboxInput::GetDPadY()
{
	return -sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::PovY);
}

#pragma endregion


#pragma region TRIGGERS

//TRIGGERS
float XboxInput::GetLTrigger()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::Z);

	if (position < 0)
		position = 0;

	return -position;
}

float XboxInput::GetRTrigger()
{
	float position = sf::Joystick::getAxisPosition(m_PlayerNr, sf::Joystick::Z);

	if (position > 0)
		position = 0;

	return position;
}

#pragma endregion