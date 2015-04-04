#pragma once

#include <Scene/SceneType.hpp>

class AbstractScene
{
public:
	virtual SceneType GetSceneType() = 0;
	virtual void Update(float deltaT) = 0;
	virtual void Render() = 0;
};