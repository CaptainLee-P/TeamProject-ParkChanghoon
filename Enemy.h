#ifndef ENEMY_H
#define ENEMY_H
#include "SDLGameObject.h"
class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Clean();
private:
  int speed;
};

#endif // !ENEMY_H