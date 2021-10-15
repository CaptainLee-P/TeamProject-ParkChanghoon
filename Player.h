#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
class Player : public GameObject
{
public:
	//Load와 Draw는 부모의 것을 상속 받아서 그대로 쓴다.
	//void Load(int x, int y, int width, int height, std::string textureID);
	//void Draw(SDL_Renderer* pRenderer);
	//Update()는 이름만 같고 다른 내용을 실행한다.
	void Update();
	//생성자와 소멸자
	Player();
	~Player();
private:
	int xInterval;
};
#endif // !PLAYER_H
