#include "Enemy.h"
#include "InputHandler.h"
#include "Colletent.h"
bool Enemy::coll = false;

Enemy::Enemy(const LoaderParams* pParams) : 
	SDLGameObject(pParams)
{
	m_currentFrame = 0;
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	handleInput();
	Colletent::Instance()->setPostion1(m_position.getX(),m_position.getY(), m_height, m_width);
	if (coll)
	{
		m_currentFrame = 1;
	}
	SDLGameObject::update();
}
void Enemy::clean()
{
}

void Enemy::handleInput()
{
}