#pragma once
#include <Scene/Impl/BaseScene.hpp>

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	void Update(float deltaT) override;
	void Render() override;

private:



};