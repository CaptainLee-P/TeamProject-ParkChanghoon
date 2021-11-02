#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams)
	:SDLGameObject(pParams),speed(1)
{

}

void Enemy::Draw()
{
	SDLGameObject::Draw();
}

void Enemy::Clean()
{
  
}
