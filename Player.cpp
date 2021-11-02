#include "Player.h"
Player::Player(const LoaderParams* pParams)
	:SDLGameObject(pParams), speed(1)
{

}

void Player::Draw()
{
	SDLGameObject::Draw();
}


void Player::Clean()
{
}
