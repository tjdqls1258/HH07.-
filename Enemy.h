#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
	
public:
	Enemy(const LoaderParams* pParams);
	static bool coll;
	virtual void draw();
	virtual void update();
	virtual void clean();
};