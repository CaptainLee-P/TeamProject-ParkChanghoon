#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H
#include "GameObject.h"
#include <iostream>
#include "Vector2D.h"
class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	virtual ~SDLGameObject() {}
protected:
	Vector2D m_position;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;

};
#endif // !1
