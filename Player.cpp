#include "Player.h"
#include "InputHandler.h"
#include "Game.h"
#include"Bullte.h"
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
	if (dely >= 0)
	{
		dely -= 1;
	}
	else
	{
		dely = 0;
	}
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(1);
	SDLGameObject::update();
}
void Player::clean()
{
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if ((dely == 0) && (TheInputHandler::Instance()->getMouseButtonState(LEFT)))
	{
		dely = 30;
		Game::Instance()->m_gameObjects.push_back(new Bullte(new LoaderParams(m_position.getX() + 64, m_position.getY() + 16, 32,32,"bullte")));
	}
}