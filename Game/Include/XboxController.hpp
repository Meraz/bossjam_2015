#ifndef XBOXCONTROLLER_H
#define XBOXCONTROLLER_H

#include <System/XboxInput.hpp>

struct ButtonState
{
	bool last;
	bool current;
};

struct AnalogState
{
	float last;
	float current;
};

class XboxController
{
public:
	XboxController(int playerNr);
	virtual ~XboxController();

	void Update();

	ButtonState GetAButtonState() { return m_aButton; }
	ButtonState GetBButtonState() { return m_bButton; }
	ButtonState GetXButtonState() { return m_xButton; }
	ButtonState GetYButtonState() { return m_yButton; }
	ButtonState GetLBButtonState() { return m_lbButton; }
	ButtonState GetRBButtonState() { return m_rbButton; }
	ButtonState GetBackButtonState() { return m_backButton; }
	ButtonState GetStartButtonState() { return m_startButton; }
	ButtonState GetLeftStickButtonState() { return m_lStickButton; }
	ButtonState GetRightStickButtonState() { return m_rStickButton; }

	AnalogState GetLStickXState() { return m_lStickX; }
	AnalogState GetLStickYState() { return m_lStickY; }
	AnalogState GetRStickXState() { return m_rStickX; }
	AnalogState GetRStickYState() { return m_rStickY; }
	AnalogState GetLTriggerState() { return m_lTrigger; }
	AnalogState GetRTriggerState() { return m_rTrigger; }
	AnalogState GetDPadXState() { return m_dPadX; }
	AnalogState GetDPadYState() { return m_dPadY; }

private:
	XboxInput* m_input;

	ButtonState m_aButton;
	ButtonState m_bButton;
	ButtonState m_xButton;
	ButtonState m_yButton;
	ButtonState m_lbButton;
	ButtonState m_rbButton;
	ButtonState m_backButton;
	ButtonState m_startButton;
	ButtonState m_lStickButton;
	ButtonState m_rStickButton;

	AnalogState m_lStickX;
	AnalogState m_lStickY;
	AnalogState m_rStickX;
	AnalogState m_rStickY;
	AnalogState m_lTrigger;
	AnalogState m_rTrigger;
	AnalogState m_dPadX;
	AnalogState m_dPadY;
};

#endif
