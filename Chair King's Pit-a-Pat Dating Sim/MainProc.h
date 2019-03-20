#pragma once

// STATE
#define STATE_MAIN_MENU 0x0001
#define STATE_HOW_TO 0x0002
#define STATE_IN_GAME 0x0003

// animation
#define ANIMATION_GOt_EUNUCH 0x01
#define ANIMATION_DEAD_BY_MAID 0x02

// Mouse Lighten
#define LIGHTEN_START_BUTTON 0x00000001
#define LIGHTEN_EXIT_BUTTON 0x00000002
#define LIGHTEN_GOLDEN_HAIR_BUTTON 0x00000003
#define LIGHTEN_BLACK_HAIR_BUTTON 0x00000004
#define LIGHTEN_HOW_TO_BUTTON 0x00000005


class MainProc
{
private:
	bool bAct;
	bool bIsQuit;

	int state;
	int pc;

	bool bIsBlack;

	int animation;

	int Subscript_Count;

	int Tick_Count;

	bool bIsMoveUp;

	int bIsMoving;

	bool Lighten_Check;

	int End_Maid_Count;
	int Start_Maid_Count;

	SDL_Event event;



	SDL_Window* pWnd;

	SDL_Surface* Screen;

	
	PLAYER* player;
	MAID** maid;
	EUNUCH* eunuch;

	ANIMATION* ani;

	SDL_Surface* Image_How_To;

	SDL_Surface* Image_Main_Menu;

	SDL_Surface* Image_Background;

	SDL_Surface* Image_Start_Button; SDL_Surface* Image_Lighten_Start_Button;

	SDL_Rect* Print_Rect_Start_Button;

	SDL_Surface* Image_Exit_Button;  SDL_Surface* Image_Lighten_Exit_Button;

	SDL_Rect* Print_Rect_Exit_Button;

	SDL_Surface* Image_Golden_Hair_Button;  SDL_Surface* Image_Lighten_Golden_Hair_Button;

	SDL_Rect* Print_Rect_Golden_Hair_Button;

	SDL_Surface* Image_Black_Hair_Button;  SDL_Surface* Image_Lighten_Black_Hair_Button;

	SDL_Rect* Print_Rect_Black_Hair_Button;

	SDL_Surface* Image_How_To_Button;  SDL_Surface* Image_Lighten_How_To_Button;

	SDL_Rect* Print_Rect_How_To_Button;


	SDL_Surface* Image_In_Game_Background;

	int Mouse_Lighten = 3;

	

public:
	int Init();
	int Update();
	int Render();
	int Release();

	bool GetAct();

	bool BISQUIT();

	SDL_Rect* Return_Print_Rect_Start_Button();
	SDL_Rect* Return_Print_Rect_Exit_Button();
	SDL_Rect* Return_Print_Rect_Golden_Hair_Button();
	SDL_Rect* Return_Print_Rect_Black_Hair_Button();
	SDL_Rect* Return_Print_Rect_How_To_Button();

	MainProc();
	virtual ~MainProc();

	void In_Game_Release();
	void In_Game_Init();
};