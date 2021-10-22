#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include <iostream>
class LoaderParams {
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	std::string getTextureID() const;
private:
	int m_x, m_y;
	int m_width, m_height;
	std::string m_textureID;
};
#endif // !LOADERPARAMS_H
