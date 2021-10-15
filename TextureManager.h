#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H


#include "SDL.h"
#include <iostream>
#include <string>
#include <map>

class TextureManager {
public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	~TextureManager() {}
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height,int, const SDL_Point*, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, int angle, const SDL_Point* center, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	TextureManager() {}
};

typedef TextureManager TheTextureManager;

#endif // !TEXTUREMANAGER_H