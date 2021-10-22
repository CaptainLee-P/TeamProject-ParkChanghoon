#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include <iostream>
#include <SDL_image.h>
#include "GameObject.h"
#include <vector>
class Game {
public:
	static Game* Instance();
	~Game();
	bool Init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void Render();
	void Update();//업데이트
	bool Running();
	void HandleEvents();//사용자 입력
	void Clean();
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	bool m_bRunning;//윈도우가 생성되지 않으면 랜더링 하지 않기 위한 변수
	std::vector <GameObject*> m_gameObjects;
	static Game* s_pInstance;
	Game() = default;
	//밑에 부터는 게임상의 오브젝트
};

typedef Game TheGame;
#endif