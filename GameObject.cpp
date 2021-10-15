#include "GameObject.h"

void GameObject::Load(int x, int y, int width, int height, std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = 0;
	m_currentFrame = 0;
	m_angle = 0;
	m_center = nullptr;
	m_flip = SDL_FLIP_NONE;
}

void GameObject::Draw(SDL_Renderer* pRenderer)
{
	TheTextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame,m_angle,m_center, pRenderer,m_flip);
}

void GameObject::Update()
{

}

void GameObject::Clean()
{
}

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}
