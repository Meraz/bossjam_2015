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

	void setDeadZone(int deadZone);

	//BUTTONS
	bool isAbuttonPressed();
	bool isBbuttonPressed();
	bool isXbuttonPressed();
	bool isYbuttonPressed();
	bool isLBbuttonPressed();
	bool isRBbuttonPressed();
	bool isBackbuttonPressed();
	bool isStartbuttonPressed();
	bool isLThumbStickPressed();
	bool isRThumbStickPressed();


	//AXISES
	float getLThumbStickX();
	float getLThumbStickY();

	float getRThumbStickX();
	float getRThumbStickY();

	float getDPadX();
	float getDPadY();


	//TRIGGERS
	float getLTrigger();
	float getRTrigger();


};

#endif