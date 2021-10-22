#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include <SDL.h>
#include "TextureManager.h"
#include "LoaderParams.h"
class GameObject {
public :
	virtual void Draw()=0;
	virtual void Update()=0;
	virtual void Clean()=0;
	virtual ~GameObject() {}
protected:
	GameObject(const LoaderParams* pParams) {}
};

#endif