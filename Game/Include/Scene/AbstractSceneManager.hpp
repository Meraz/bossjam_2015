#pragma once

#include <Scene/SceneType.hpp>

class MusicManager;

class AbstractSceneManager
{
public:
	virtual void ChangeScene(SceneType newScene) = 0;
};