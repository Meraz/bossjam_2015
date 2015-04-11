#include <XboxController.hpp>

XboxController::XboxController(int playerNr)
{
	m_input = new XboxInput(playerNr);

	m_aButton.current = m_input->IsAbuttonPressed();
	m_bButton.current = m_input->IsBbuttonPressed();
	m_xButton.current = m_input->IsXbuttonPressed();
	m_yButton.current = m_input->IsYbuttonPressed();
	m_lbButton.current = m_input->IsLBbuttonPressed();
	m_rbButton.current = m_input->IsRBbuttonPressed();
	m_backButton.current = m_input->IsBackbuttonPressed();
	m_startButton.current = m_input->IsStartbuttonPressed();
	m_lStickButton.current = m_input->IsLThumbStickPressed();
	m_rStickButton.current = m_input->IsRThumbStickPressed();

	m_lStickX.current = m_input->GetLThumbStickX();
	m_lStickY.current = m_input->GetLThumbStickY();
	m_rStickX.current = m_input->GetRThumbStickX();
	m_rStickY.current = m_input->GetRThumbStickY();
	m_lTrigger.current = m_input->GetLTrigger();
	m_rTrigger.current = m_input->GetRTrigger();
	m_dPadX.current = m_input->GetDPadX();
	m_dPadY.current = m_input->GetDPadY();
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
	
	m_aButton.current = m_input->IsAbuttonPressed();
	m_bButton.current = m_input->IsBbuttonPressed();
	m_xButton.current = m_input->IsXbuttonPressed();
	m_yButton.current = m_input->IsYbuttonPressed();
	m_lbButton.current = m_input->IsLBbuttonPressed();
	m_rbButton.current = m_input->IsRBbuttonPressed();
	m_backButton.current = m_input->IsBackbuttonPressed();
	m_startButton.current = m_input->IsStartbuttonPressed();
	m_lStickButton.current = m_input->IsLThumbStickPressed();
	m_rStickButton.current = m_input->IsRThumbStickPressed();

	m_lStickX.current = m_input->GetLThumbStickX();
	m_lStickY.current = m_input->GetLThumbStickY();
	m_rStickX.current = m_input->GetRThumbStickX();
	m_rStickY.current = m_input->GetRThumbStickY();
	m_lTrigger.current = m_input->GetLTrigger();
	m_rTrigger.current = m_input->GetRTrigger();
	m_dPadX.current = m_input->GetDPadX();
	m_dPadY.current = m_input->GetDPadY();
}