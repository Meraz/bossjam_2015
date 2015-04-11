#pragma once
#include <Scene/Impl/BaseScene.hpp>

class EditScene : public BaseScene
{
public:
	EditScene();
	~EditScene();

	void Update(float deltaT) override;
	void Render(sf::RenderWindow* window) override;

private:



};