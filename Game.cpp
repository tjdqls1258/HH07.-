#include "Game.h"
#include "TextureManger.h"
#include "InputHandler.h"
Game* Game::s_pInstance = 0;


bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (!TheTextureManager::Instance()->load("assets/animate-alpha.png",
				"animate", m_pRenderer))
			{
				return false;
			}
			if (!TheTextureManager::Instance()->load("assets/bullet.png",
				"bullte", m_pRenderer))
			{
				return false;
			}
			if (!TheTextureManager::Instance()->load("assets/Walls.png",
				"walls", m_pRenderer))
			{
				return false;
			}
			m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
			m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 64, 128, "walls")));
			SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		}
	}
	else
	{
		return false;
	}

	return true;
}


void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type j = 0;
		j != m_gameObjects.size(); j++)
	{
		m_gameObjects[j]->draw();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean()
{
	std::cout << "cleaning game \n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::update()
{
	for ( i = 0;i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

Game::Game()
{
	
}

// void Game::clean() �߰� 

void Game::quit()
{
	clean();
}