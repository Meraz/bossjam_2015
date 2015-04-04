#pragma once

#include <Scene/SceneType.hpp>

class AbstractSceneManager
{
public:
	virtual void ChangeScene(SceneType newScene) = 0;
};