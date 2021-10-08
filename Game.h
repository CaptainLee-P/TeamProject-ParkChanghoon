#pragma once
#include "SDL.h"
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.h"

class Game {
public:
	Game() {}
	~Game() {}
	bool Init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void Render();
	void Update();//업데이트
	bool Running();
	void HandleEvents();//사용자 입력
	void Clean();
private:
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	int m_currentFrame;
	bool m_bRunning;//윈도우가 생성되지 않으면 랜더링 하지 않기 위한 변수
};
