#include <Scene/Impl/EditScene.hpp>

#include <Level/Level.hpp>

EditScene::EditScene()
: BaseScene(SceneType::GAME)
{
	m_level = new Level();
}

EditScene::~EditScene()
{

}

void EditScene::Update(sf::Time deltaT)
{

}

void EditScene::Render(sf::RenderWindow* window)
{
	//m_level->Render(window);
}