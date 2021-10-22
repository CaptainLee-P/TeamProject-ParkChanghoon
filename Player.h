#ifndef PLAYER_H
#define PLAYER_H
#include "SDLGameObject.h"
class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
};
#endif // !PLAYER_H
