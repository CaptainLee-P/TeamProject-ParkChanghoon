#ifndef ENEMY_H
#define ENEMY_H
#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};

#endif // !ENEMY_H