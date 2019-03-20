#pragma once


class ANIMATION
{
private:
	int NumOfImage;

	SDL_Surface** Image;

public:
	ANIMATION(int n) : NumOfImage(n) {}

	ANIMATION() {}

	void Init(int num);

	void Release();

	int Return_NumOfImage();

	void Load_Bitmap(int index, const char* str);

	void SetColorKey(int index);

	SDL_Surface* Return_Image(int index);
};




