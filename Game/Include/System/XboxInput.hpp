#ifndef XBOXINPUT_H
#define XBOXINPUT_H

#include <SFML/Graphics.hpp>

class XboxInput
{
private:
	int m_PlayerNr;
	int m_deadZone;

public:
	XboxInput(int playerNr);
	~XboxInput();

	void SetDeadZone(int deadZone);

	//BUTTONS
	bool IsAbuttonPressed();
	bool IsBbuttonPressed();
	bool IsXbuttonPressed();
	bool IsYbuttonPressed();
	bool IsLBbuttonPressed();
	bool IsRBbuttonPressed();
	bool IsBackbuttonPressed();
	bool IsStartbuttonPressed();
	bool IsLThumbStickPressed();
	bool IsRThumbStickPressed();


	//AXISES
	float GetLThumbStickX();
	float GetLThumbStickY();

	float GetRThumbStickX();
	float GetRThumbStickY();

	float GetDPadX();
	float GetDPadY();


	//TRIGGERS
	float GetLTrigger();
	float GetRTrigger();


};

#endif