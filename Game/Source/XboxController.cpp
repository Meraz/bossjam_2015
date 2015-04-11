#include <XboxController.hpp>

XboxController::XboxController(int playerNr)
{
	m_input = new XboxInput(playerNr);
}

XboxController::~XboxController()
{
	delete m_input;
}

void XboxController::Update()
{
	//Update last values
	m_aButton.last = m_aButton.current;
	m_bButton.last = m_bButton.current;
	m_xButton.last = m_xButton.current;
	m_yButton.last = m_yButton.current;
	m_lbButton.last = m_lbButton.current;
	m_rbButton.last = m_rbButton.current;
	m_backButton.last = m_backButton.current;
	m_startButton.last = m_startButton.current;
	m_lStickButton.last = m_lStickButton.current;
	m_rStickButton.last = m_rStickButton.current;

	m_lStickX.last = m_lStickX.current;
	m_lStickY.last = m_lStickY.current;
	m_rStickX.last = m_rStickX.current;
	m_rStickY.last = m_rStickY.current;
	m_rTrigger.last = m_rTrigger.current;
	m_lTrigger.last = m_lTrigger.current;
	m_dPadX.last = m_dPadX.current;
	m_dPadY.last = m_dPadY.current;

	//Set new values
	
	m_aButton.last = m_input->IsAbuttonPressed();
	m_bButton.last = m_input->IsBbuttonPressed();
	m_xButton.last = m_input->IsXbuttonPressed();
	m_yButton.last = m_input->IsYbuttonPressed();
	m_lbButton.last = m_input->IsLBbuttonPressed();
	m_rbButton.last = m_input->IsRBbuttonPressed();
	m_backButton.last = m_input->IsBackbuttonPressed();
	m_startButton.last = m_input->IsStartbuttonPressed();
	m_lStickButton.last = m_input->IsLThumbStickPressed();
	m_rStickButton.last = m_input->IsRThumbStickPressed();

	m_lStickX.last = m_input->GetLThumbStickX();
	m_lStickY.last = m_input->GetLThumbStickY();
	m_rStickX.last = m_input->GetRThumbStickX();
	m_rStickY.last = m_input->GetRThumbStickY();
	m_lTrigger.last = m_input->GetLTrigger();
	m_rTrigger.last = m_input->GetRTrigger();
	m_dPadX.last = m_input->GetDPadX();
	m_dPadY.last = m_input->GetDPadY();
}