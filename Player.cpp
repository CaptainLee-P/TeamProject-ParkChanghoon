#include "Player.h"

void Player::Update()
{
	//캐릭터 움직임
	m_x += xInterval;

	if ((m_x < 0 && xInterval < 0) || (m_x + this->m_width > 650 && xInterval > 0))
	{
		xInterval = -xInterval;
		if (xInterval > 0)
		{
			m_flip = SDL_FLIP_NONE;
		}
		else
		{
			m_flip = SDL_FLIP_HORIZONTAL;
		}
	}
	//캐릭터 애니메이션
	m_currentFrame = (SDL_GetTicks() / 100) % 6;

}
//생성자에서 멤버변수 초기화
Player::Player() :xInterval(1)
{
}

Player::~Player()
{
}
