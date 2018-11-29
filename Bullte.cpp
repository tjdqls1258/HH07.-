#include "Bullte.h"
#include "InputHandler.h"
#include "Colletent.h"
#include "Game.h"
#include "Enemy.h"

Bullte::Bullte(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}
void Bullte::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Bullte::update()
{
	m_position.setX(m_position.getX() + 1);
	m_currentFrame = 0;
	Colletent::Instance()->setPostion2(m_position.getX(), m_position.getY(), m_height, m_width);
	if (Colletent::Instance()->getColletent())
	{
		Game::Instance()->m_gameObjects.erase(Game::Instance()->m_gameObjects.begin() + Game::Instance()->here());
		Game::Instance()->collision();
		Enemy::coll = true;
	}
	SDLGameObject::update();
	
}
void Bullte::clean()
{
}

void Bullte::handleInput()
{

}