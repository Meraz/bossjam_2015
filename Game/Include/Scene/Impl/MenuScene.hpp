#pragma once
#include <Scene/Impl/BaseScene.hpp>

class MenuScene : public BaseScene
{
public:
	MenuScene();
	~MenuScene();

	void Update(float deltaT) override;
	void Render() override;

private:



};