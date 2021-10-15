#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <SDL.h>
#include "TextureManager.h"
class GameObject {
public :
	virtual void Load(int x, int y, int width, int height, std::string textureID);
	virtual void Draw(SDL_Renderer* pRenderer);
	virtual void Update();
	virtual void Clean();
	GameObject();
	virtual ~GameObject();
protected:
	std::string m_textureID;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_angle;
	SDL_Point* m_center;
	SDL_RendererFlip m_flip;
};

#endif