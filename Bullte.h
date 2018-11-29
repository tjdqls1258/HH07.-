#pragma once
#include "SDLGameObject.h"

class Bullte : public SDLGameObject
{
private:
	void handleInput();
public:
	Bullte(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};