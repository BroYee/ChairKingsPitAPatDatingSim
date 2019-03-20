#pragma once

#define LINE_1_Y_POS 200
#define LINE_2_Y_POS 250
#define LINE_3_Y_POS 300
#define LINE_4_Y_POS 350
#define LINE_5_Y_POS 400


class MAID
{
private:
	static int NumOfMaid;
	static int StartNumOfMaid;

	int Pre_X_Pos;

	int speed;
	int line;

	SDL_Surface** Image_Maid;

	SDL_Rect* Print_Rect_Maid;
public:
	void Init();
	void Release();

	void Move();

	void Change_Speed(int sp);

	SDL_Surface* Return_Image(int index);
	SDL_Rect* Return_Print_Rect_Maid();

	int Return_XPos();

	int Return_NumOfMaid();
	int Return_StartNumOfMaid();

	void Plus_1_NumOfMaid();
	void Plus_1_StartNumOfMaid();

	int Return_Line();

	void Bring_Back();
};




class EUNUCH
{
private:
	int speed;

	int Pre_X_Pos;

	int line;

	SDL_Surface** Image_Eunuch;

	SDL_Rect* Print_Rect_Eunuch;
public:
	void Init();

	void Release();

	void Move();

	int Return_Line();

	void Bring_Back();

	SDL_Surface* Return_Image(int index);
	SDL_Rect* Return_Print_Rect_Eunuch();
};



class PLAYER
{
private:
	bool KingIsDead;
	int Eunuch_Count;

	int line;

	bool bIsMoveEnough;

	SDL_Surface** Image_Player;

	SDL_Rect* Print_Rect_Player;

public:
	PLAYER() {}

	void Init();
	void Release();

	void Move(bool bIsMoveUp);

	int Return_Eunuch_Count();

	bool Return_bIsMoveEnough();

	int Return_Line();

	bool Meet_Eunuch();

	void Plus_Eunuch_count();

	SDL_Surface* Return_Image(int index);
	SDL_Rect* Return_Print_Rect();
};








