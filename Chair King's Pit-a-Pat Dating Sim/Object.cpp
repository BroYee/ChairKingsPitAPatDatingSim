#include "stdafx.h"

int Line_Pos[5] = { LINE_1_Y_POS, LINE_2_Y_POS, LINE_3_Y_POS, LINE_4_Y_POS, LINE_5_Y_POS };

int MAID::NumOfMaid = 3;
int MAID::StartNumOfMaid = 0;

void MAID::Init()
{
	speed = 3;
	line = rand() % 5 + 1;

	Image_Maid = new SDL_Surface*[2];

	Image_Maid[0] = SDL_LoadBMP("./Pictures/maid_1.bmp");
	Image_Maid[1] = SDL_LoadBMP("./Pictures/maid_2.bmp");
	Image_Maid[2] = SDL_LoadBMP("./Pictures/maid_3.bmp");

	SDL_SetColorKey(Image_Maid[0], SDL_TRUE, SDL_MapRGB(Image_Maid[0]->format, 255, 255, 255));
	SDL_SetColorKey(Image_Maid[1], SDL_TRUE, SDL_MapRGB(Image_Maid[1]->format, 255, 255, 255));
	SDL_SetColorKey(Image_Maid[2], SDL_TRUE, SDL_MapRGB(Image_Maid[2]->format, 255, 255, 255));
	 
	Print_Rect_Maid = new SDL_Rect;

	Print_Rect_Maid->x = 1000;
	Print_Rect_Maid->y = (Line_Pos[line - 1] - 80);
	Print_Rect_Maid->w = 92;
	Print_Rect_Maid->h = 112;

	Pre_X_Pos = 1000;
}

void MAID::Release()
{
	delete[] Print_Rect_Maid;
	SDL_FreeSurface(*Image_Maid);
}

void MAID::Move()
{
	Print_Rect_Maid->x = Pre_X_Pos;
	Print_Rect_Maid->x -= 6 * speed;

	Pre_X_Pos = Print_Rect_Maid->x;
}

void MAID::Change_Speed(int sp)
{
	speed = sp;
}

SDL_Rect* MAID::Return_Print_Rect_Maid()
{
	return Print_Rect_Maid;
}

SDL_Surface* MAID::Return_Image(int index)
{
	return Image_Maid[index];
}

int MAID::Return_XPos()
{
	return Print_Rect_Maid->x;
}

int MAID::Return_NumOfMaid()
{
	return NumOfMaid;
}

int MAID::Return_StartNumOfMaid()
{
	return StartNumOfMaid;
}

void MAID::Plus_1_NumOfMaid()
{
	NumOfMaid++;
}

void MAID::Plus_1_StartNumOfMaid()
{
	StartNumOfMaid++;
}

int MAID::Return_Line()
{
	return line;
}

void MAID::Bring_Back()
{
	Print_Rect_Maid->x = 1000;
}







void EUNUCH::Init()
{
	speed = 2;
	
	Pre_X_Pos = 1000;

	line = rand() % 5 + 1;

	Image_Eunuch = new SDL_Surface*[2];

	Image_Eunuch[0] = SDL_LoadBMP("./Pictures/eunuch_1.bmp");
	Image_Eunuch[1] = SDL_LoadBMP("./Pictures/eunuch_2.bmp");
	Image_Eunuch[2] = SDL_LoadBMP("./Pictures/eunuch_3.bmp");


	SDL_SetColorKey(Image_Eunuch[0], SDL_TRUE, SDL_MapRGB(Image_Eunuch[0]->format, 255, 255, 255));
	SDL_SetColorKey(Image_Eunuch[1], SDL_TRUE, SDL_MapRGB(Image_Eunuch[1]->format, 255, 255, 255));
	SDL_SetColorKey(Image_Eunuch[2], SDL_TRUE, SDL_MapRGB(Image_Eunuch[2]->format, 255, 255, 255));

	Print_Rect_Eunuch = new SDL_Rect;

	Print_Rect_Eunuch->x = 1000;
	Print_Rect_Eunuch->y = (Line_Pos[line - 1] + 60);
	Print_Rect_Eunuch->w = 68;
	Print_Rect_Eunuch->h = 144;
}

void EUNUCH::Release()
{
	delete Print_Rect_Eunuch;
	SDL_FreeSurface(*Image_Eunuch);
}

void EUNUCH::Move()
{
	Print_Rect_Eunuch->x = Pre_X_Pos;
	Print_Rect_Eunuch->x -= 6 * speed;

	Pre_X_Pos = Print_Rect_Eunuch->x;
}

int EUNUCH::Return_Line()
{
	return line;
}

void EUNUCH::Bring_Back()
{
	line = rand() % 5 + 1;

	Print_Rect_Eunuch->y = (Line_Pos[line - 1] + 60);

	Pre_X_Pos = 1000;
}

SDL_Rect* EUNUCH::Return_Print_Rect_Eunuch()
{
	return Print_Rect_Eunuch;
}

SDL_Surface* EUNUCH::Return_Image(int index)
{
	return Image_Eunuch[index];
}



void PLAYER::Init()
{
	KingIsDead = false;
	Eunuch_Count = 0;
	bIsMoveEnough = false;

	line = 3;

	Image_Player = new SDL_Surface*[2];


	Image_Player[0] = SDL_LoadBMP("./Pictures/king_1.bmp");
	Image_Player[1] = SDL_LoadBMP("./Pictures/king_2.bmp");
	Image_Player[2] = SDL_LoadBMP("./Pictures/king_3.bmp");


	SDL_SetColorKey(Image_Player[0], SDL_TRUE, SDL_MapRGB(Image_Player[0]->format, 255, 255, 255));
	SDL_SetColorKey(Image_Player[1], SDL_TRUE, SDL_MapRGB(Image_Player[1]->format, 255, 255, 255));
	SDL_SetColorKey(Image_Player[2], SDL_TRUE, SDL_MapRGB(Image_Player[2]->format, 255, 255, 255));

	Print_Rect_Player = new SDL_Rect;

	Print_Rect_Player->x = 100;
	Print_Rect_Player->y = LINE_3_Y_POS;
	Print_Rect_Player->w = 77;
	Print_Rect_Player->h = 200;
}

void PLAYER::Release()
{
	delete[] Print_Rect_Player;
	SDL_FreeSurface(*Image_Player);
}

void PLAYER::Move(bool bIsMoveUp)
{
	if (bIsMoveUp)
	{
		// Move Up

		if (line == 1) return;

		while (1)
		{
			for (int i = 0; i < 3; i++)
			{
				Print_Rect_Player->y -= 10;

				if (((Print_Rect_Player->y - 10) <= Line_Pos[line - 1 - 1]) && (i == 2))
				{
					--line;
					Print_Rect_Player->y = Line_Pos[line - 1];
					bIsMoveEnough = true;
					return;
				}
			}
		}
	}
	else
	{
		// Move Down

		if (line == 5) return;

		while (1)
		{
			for (int i = 0; i < 3; i++)
			{
				Print_Rect_Player->y += 10;

				if (((Print_Rect_Player->y + 10) >= Line_Pos[line + 1 - 1]) && (i == 2))
				{
					++line;
					Print_Rect_Player->y = Line_Pos[line - 1];
					bIsMoveEnough = true;
					return;
				}
			}
		}
	}
}

int PLAYER::Return_Eunuch_Count()
{
	return Eunuch_Count;
}

bool PLAYER::Return_bIsMoveEnough()
{
	return bIsMoveEnough;
}

int PLAYER::Return_Line()
{
	return line;
}

bool PLAYER::Meet_Eunuch()
{
	return true;
}

void PLAYER::Plus_Eunuch_count()
{
	Eunuch_Count++;
}

SDL_Surface* PLAYER::Return_Image(int index)
{
	return Image_Player[index];
}

SDL_Rect* PLAYER::Return_Print_Rect()
{
	return Print_Rect_Player;
}