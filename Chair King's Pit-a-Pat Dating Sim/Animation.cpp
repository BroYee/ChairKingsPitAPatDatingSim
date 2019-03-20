#include "stdafx.h"


void ANIMATION::Init(int num)
{
	NumOfImage = num;

	Image = new SDL_Surface*[NumOfImage];
}

void ANIMATION::Release()
{
	delete[] Image;
}

int ANIMATION::Return_NumOfImage()
{
	return NumOfImage;
}

void ANIMATION::Load_Bitmap(const int index, const char* str)
{
	if (index > NumOfImage) exit(0);
	Image[index] = SDL_LoadBMP(str);
}

SDL_Surface* ANIMATION::Return_Image(int index)
{
	return Image[index];
}

void ANIMATION::SetColorKey(int index)
{
	SDL_SetColorKey(Image[index], SDL_TRUE, SDL_MapRGB(Image[index]->format, 255, 255, 255));


}