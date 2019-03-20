#include "stdafx.h"

#define WINSIZE_X 800
#define WINSIZE_Y 600


MainProc::MainProc()
{
}


MainProc::~MainProc()
{
}


//int MainProc::Init()
int MainProc::Init()
{
	bIsBlack = true;

	bAct = false;

	bIsQuit = false;

	Subscript_Count = 0;

	Tick_Count = 1;

	animation = 0;

	bIsMoving = false;

	state = STATE_MAIN_MENU;

	((unsigned)time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING);
	
	pWnd = SDL_CreateWindow("Chair King's Pit-a-Pat Love Simulation", 200, 100, WINSIZE_X, WINSIZE_Y, NULL);
	
	Screen = SDL_GetWindowSurface(pWnd);
 
	player = new PLAYER;
	maid   = new MAID*[1];
	eunuch = new EUNUCH;

	for (int i = 0; i < 2; i++)
	{
		*(maid + i) = new MAID;
	}

	player->Init();
	maid[0]->Init();
	maid[1]->Init();
	eunuch->Init();

	ani = new ANIMATION[2];
	
	ani[0].Init(7);
	ani[1].Init(8);

	ani[0].Load_Bitmap(0, "./Pictures/surprised_eunuch_1.bmp");
	ani[0].Load_Bitmap(1, "./Pictures/surprised_eunuch_2.bmp");
	ani[0].Load_Bitmap(2, "./Pictures/b_king_solo_1.bmp"); // Random
	ani[0].Load_Bitmap(3, "./Pictures/b_subscript_1.bmp"); // Increasing
	ani[0].Load_Bitmap(4, "./Pictures/b_got_eunuch_1.bmp");  // Random
	ani[0].Load_Bitmap(5, "./Pictures/void_window.bmp");  // Void Window
	ani[0].Load_Bitmap(6, "./Pictures/b_ending.bmp");
	ani[0].Load_Bitmap(7, "./Pictures/void_window.bmp");  // Void Window

	ani[1].Load_Bitmap(0, "./Pictures/b_dead_by_maid_1.bmp");
	ani[1].Load_Bitmap(1, "./Pictures/b_dead_by_maid_2.bmp");
	ani[1].Load_Bitmap(2, "./Pictures/b_dead_by_maid_3.bmp");
	ani[1].Load_Bitmap(3, "./Pictures/b_dead_by_maid_4.bmp");
	ani[1].Load_Bitmap(4, "./Pictures/b_dead_by_maid_5.bmp");
	ani[1].Load_Bitmap(5, "./Pictures/dead_by_maid_6.bmp");
	ani[1].Load_Bitmap(6, "./Pictures/dead_by_maid_7.bmp");
	ani[1].Load_Bitmap(7, "./Pictures/dead_by_maid_8.bmp");
	ani[1].Load_Bitmap(8, "./Pictures/void_window.bmp");  // Void Window

	ani[0].SetColorKey(5);
	ani[0].SetColorKey(7);

	ani[1].SetColorKey(8);


	Image_How_To = SDL_LoadBMP("./Pictures/explanation.bmp");
	SDL_SetColorKey(Image_How_To, SDL_TRUE, SDL_MapRGB(Image_How_To->format, 255, 255, 255));

	Image_Main_Menu = SDL_LoadBMP("./Pictures/main_black.bmp");

	Image_Start_Button = SDL_LoadBMP("./Pictures/start_button.bmp");  Image_Lighten_Start_Button = SDL_LoadBMP("./Pictures/lighten_start_button.bmp");

	SDL_SetColorKey(Image_Start_Button, SDL_TRUE, SDL_MapRGB(Image_Start_Button->format, 255, 255, 255));
	SDL_SetColorKey(Image_Lighten_Start_Button, SDL_TRUE, SDL_MapRGB(Image_Lighten_Start_Button->format, 255, 255, 255));

	Print_Rect_Start_Button = new SDL_Rect;

	Print_Rect_Start_Button->x = 270;
	Print_Rect_Start_Button->y = 340;
	Print_Rect_Start_Button->w = 310;
	Print_Rect_Start_Button->h = 110;

	Image_Exit_Button = SDL_LoadBMP("./Pictures/exit_button.bmp");  Image_Lighten_Exit_Button = SDL_LoadBMP("./Pictures/lighten_exit_button.bmp");

	SDL_SetColorKey(Image_Exit_Button, SDL_TRUE, SDL_MapRGB(Image_Exit_Button->format, 255, 255, 255));
	SDL_SetColorKey(Image_Lighten_Exit_Button, SDL_TRUE, SDL_MapRGB(Image_Lighten_Exit_Button->format, 255, 255, 255));

	Print_Rect_Exit_Button = new SDL_Rect;

	Print_Rect_Exit_Button->x = 265;
	Print_Rect_Exit_Button->y = 450;
	Print_Rect_Exit_Button->w = 310;
	Print_Rect_Exit_Button->h = 110;

	Image_Golden_Hair_Button = SDL_LoadBMP("./Pictures/golden_hair_button.bmp");  Image_Lighten_Golden_Hair_Button = SDL_LoadBMP("./Pictures/lighten_golden_hair_button.bmp");

	SDL_SetColorKey(Image_Golden_Hair_Button, SDL_TRUE, SDL_MapRGB(Image_Golden_Hair_Button->format, 255, 255, 255));
	SDL_SetColorKey(Image_Lighten_Golden_Hair_Button, SDL_TRUE, SDL_MapRGB(Image_Lighten_Golden_Hair_Button->format, 255, 255, 255));

	Print_Rect_Golden_Hair_Button = new SDL_Rect;

	Print_Rect_Golden_Hair_Button->x = 680;
	Print_Rect_Golden_Hair_Button->y = 20;
	Print_Rect_Golden_Hair_Button->w = 110;
	Print_Rect_Golden_Hair_Button->h = 110;

	Image_Black_Hair_Button = SDL_LoadBMP("./Pictures/black_hair_button.bmp");  Image_Lighten_Black_Hair_Button = SDL_LoadBMP("./Pictures/lighten_black_hair_button.bmp");

	SDL_SetColorKey(Image_Black_Hair_Button, SDL_TRUE, SDL_MapRGB(Image_Black_Hair_Button->format, 255, 255, 255));
	SDL_SetColorKey(Image_Lighten_Black_Hair_Button, SDL_TRUE, SDL_MapRGB(Image_Lighten_Black_Hair_Button->format, 255, 255, 255));

	Print_Rect_Black_Hair_Button = new SDL_Rect;

	Print_Rect_Black_Hair_Button->x = 570;
	Print_Rect_Black_Hair_Button->y = 20;
	Print_Rect_Black_Hair_Button->w = 110;
	Print_Rect_Black_Hair_Button->h = 110;


	Image_How_To_Button = SDL_LoadBMP("./Pictures/how_to_button.bmp");  Image_Lighten_How_To_Button = SDL_LoadBMP("./Pictures/lighten_how_to_button.bmp");

	SDL_SetColorKey(Image_How_To_Button, SDL_TRUE, SDL_MapRGB(Image_How_To_Button->format, 255, 255, 255));
	SDL_SetColorKey(Image_Lighten_How_To_Button, SDL_TRUE, SDL_MapRGB(Image_Lighten_How_To_Button->format, 255, 255, 255));


	Print_Rect_How_To_Button = new SDL_Rect;

	Print_Rect_How_To_Button->x = 0;
	Print_Rect_How_To_Button->y = 497;
	Print_Rect_How_To_Button->w = 100;
	Print_Rect_How_To_Button->h = 100;



	Image_Background = SDL_LoadBMP("./Pictures/main_black.bmp");


	Image_In_Game_Background = SDL_LoadBMP("./Pictures/in_game_background.bmp");

	
	int End_Maid_Count = maid[0]->Return_NumOfMaid();
	int Start_Maid_Count = maid[0]->Return_StartNumOfMaid();
	

	return 0;
}


int MainProc::Update()
{
	if (bAct)
	{
		if (state == STATE_IN_GAME)
		{
			static int Static_Tick = SDL_GetTicks();
			int Tick = SDL_GetTicks();

			if (Tick_Count == 1) Static_Tick = SDL_GetTicks();

			if (Tick_Count == 0) ++Tick_Count;
			int Rand_Count = rand() % Tick_Count + 1;

			if (Static_Tick < (Tick - 1000 + Rand_Count))
			{
				*(maid + End_Maid_Count) = new MAID;
				maid[End_Maid_Count]->Init();
				maid[0]->Plus_1_NumOfMaid();
				End_Maid_Count++;

				Static_Tick = SDL_GetTicks();
			}

			Tick_Count++;


			for (int j = Start_Maid_Count; j < End_Maid_Count; j++)
			{
				maid[j]->Move();
			}


			eunuch->Move();

			// Eunuch Release
			if (eunuch->Return_Print_Rect_Eunuch()->x <= -200) eunuch->Bring_Back();

			// Maid Release
			for (int i = Start_Maid_Count; i < End_Maid_Count; i++)
			{
				if (maid[i]->Return_Print_Rect_Maid()->x <= -300)
				{
					maid[i]->Release();
					Start_Maid_Count++;
				}
			}


			for (int i = Start_Maid_Count; i < End_Maid_Count; i++)
			{
				if (maid[i]->Return_Print_Rect_Maid()->x < -500)
				{
					maid[i]->Release();
				}
			}

			 //Maid Collision
			for (int k = Start_Maid_Count; k < End_Maid_Count; k++)
			{
				if (player->Return_Line() == maid[k]->Return_Line())
					if (player->Return_Print_Rect()->x <= (maid[k]->Return_Print_Rect_Maid()->x + maid[k]->Return_Print_Rect_Maid()->w))
						if ((player->Return_Print_Rect()->x + player->Return_Print_Rect()->w) >= maid[k]->Return_Print_Rect_Maid()->x)
						{
							state = STATE_MAIN_MENU;

							In_Game_Release();

							animation = ANIMATION_DEAD_BY_MAID;

							if (bIsBlack)
							{
								ani[1].Load_Bitmap(0, "./Pictures/b_dead_by_maid_1.bmp");
								ani[1].Load_Bitmap(1, "./Pictures/b_dead_by_maid_2.bmp");
								ani[1].Load_Bitmap(2, "./Pictures/b_dead_by_maid_3.bmp");
								ani[1].Load_Bitmap(3, "./Pictures/b_dead_by_maid_4.bmp");
								ani[1].Load_Bitmap(4, "./Pictures/b_dead_by_maid_5.bmp");
							}
							else
							{
								ani[1].Load_Bitmap(0, "./Pictures/g_dead_by_maid_1.bmp");
								ani[1].Load_Bitmap(1, "./Pictures/g_dead_by_maid_2.bmp");
								ani[1].Load_Bitmap(2, "./Pictures/g_dead_by_maid_3.bmp");
								ani[1].Load_Bitmap(3, "./Pictures/g_dead_by_maid_4.bmp");
								ani[1].Load_Bitmap(4, "./Pictures/g_dead_by_maid_5.bmp");
							}

							bAct = false;
						}
			}
			

			// Eunuch Collision
			if (player->Return_Line() == eunuch->Return_Line())
				if (player->Return_Print_Rect()->x <= (eunuch->Return_Print_Rect_Eunuch()->x + eunuch->Return_Print_Rect_Eunuch()->w))
					if ((player->Return_Print_Rect()->x + player->Return_Print_Rect()->w) >= eunuch->Return_Print_Rect_Eunuch()->x)
					{

						player->Meet_Eunuch();

						bAct = false;
						player->Plus_Eunuch_count();

						eunuch->Bring_Back();

						animation = ANIMATION_GOt_EUNUCH;

						
						if (bIsBlack)
						{  // Black Version
							int rand_num_1 = rand() % 4;

							
							switch (rand_num_1)
							{
							case 0:
								ani[0].Load_Bitmap(2, "./Pictures/b_king_solo_1.bmp");
								break;
							case 1:
								ani[0].Load_Bitmap(2, "./Pictures/b_king_solo_2.bmp");
								break;
							case 2:
								ani[0].Load_Bitmap(2, "./Pictures/b_king_solo_3.bmp");
								break;
							case 3:
								ani[0].Load_Bitmap(2, "./Pictures/b_king_solo_4.bmp");
								break;
							case 4:
								ani[0].Load_Bitmap(2, "./Pictures/b_king_solo_5.bmp");
								break;
							}


							switch (Subscript_Count)
							{
							case 0:
								ani[0].Load_Bitmap(3, "./Pictures/b_subscript_1.bmp");
								break;
							case 1:
								ani[0].Load_Bitmap(3, "./Pictures/b_subscript_2.bmp");
								break;
							case 2:
								ani[0].Load_Bitmap(3, "./Pictures/b_subscript_4.bmp");
								break;
							case 3:
								ani[0].Load_Bitmap(3, "./Pictures/b_subscript_6.bmp");
								break;
							case 4:
								ani[0].Load_Bitmap(3, "./Pictures/b_subscript_8.bmp");
								break;
							}

							int rand_num_2 = rand() % 4;

							switch (rand_num_2)
							{
							case 0:
								ani[0].Load_Bitmap(4, "./Pictures/b_got_eunuch_1.bmp");
								break;
							case 1:
								ani[0].Load_Bitmap(4, "./Pictures/b_got_eunuch_2.bmp");
								break;
							case 2:
								ani[0].Load_Bitmap(4, "./Pictures/b_got_eunuch_3.bmp");
								break;
							case 3:
								ani[0].Load_Bitmap(4, "./Pictures/b_got_eunuch_4.bmp");
								break;
							case 4:
								ani[0].Load_Bitmap(4, "./Pictures/b_got_eunuch_5.bmp");
								break;
							}
						}
						else
						{  // Golden Version
							int rand_num_1 = rand() % 4;

							switch (rand_num_1)
							{
							case 0:
								ani[0].Load_Bitmap(2, "./Pictures/g_king_solo_1.bmp");
								break;
							case 1:
								ani[0].Load_Bitmap(2, "./Pictures/g_king_solo_2.bmp");
								break;
							case 2:
								ani[0].Load_Bitmap(2, "./Pictures/g_king_solo_3.bmp");
								break;
							case 3:
								ani[0].Load_Bitmap(2, "./Pictures/g_king_solo_4.bmp");
								break;
							case 4:
								ani[0].Load_Bitmap(2, "./Pictures/g_king_solo_5.bmp");
								break;
							}


							switch (Subscript_Count)
							{
							case 0:
								ani[0].Load_Bitmap(3, "./Pictures/g_subscript_1.bmp");
								break;
							case 1:
								ani[0].Load_Bitmap(3, "./Pictures/g_subscript_2.bmp");
								break;
							case 2:
								ani[0].Load_Bitmap(3, "./Pictures/g_subscript_4.bmp");
								break;
							case 3:
								ani[0].Load_Bitmap(3, "./Pictures/g_subscript_6.bmp");
								break;
							case 4:
								ani[0].Load_Bitmap(3, "./Pictures/g_subscript_8.bmp");
								break;
							}

							int rand_num_2 = rand() % 4;

							switch (rand_num_2)
							{
							case 0:
								ani[0].Load_Bitmap(4, "./Pictures/g_got_eunuch_1.bmp");
								break;
							case 1:
								ani[0].Load_Bitmap(4, "./Pictures/g_got_eunuch_2.bmp");
								break;
							case 2:
								ani[0].Load_Bitmap(4, "./Pictures/g_got_eunuch_3.bmp");
								break;
							case 3:
								ani[0].Load_Bitmap(4, "./Pictures/g_got_eunuch_4.bmp");
								break;
							case 4:
								ani[0].Load_Bitmap(4, "./Pictures/g_got_eunuch_5.bmp");
								break;
							}
						}
						Subscript_Count++;
					}

		}
	}


	SDL_PollEvent(&event);

	COORD MousePos;

	MousePos.X = event.button.x;
	MousePos.Y = event.button.y;

	if (state == STATE_MAIN_MENU)
	{
		if (MouseCollision(Print_Rect_Start_Button, MousePos))
		{
			Mouse_Lighten = LIGHTEN_START_BUTTON;
		}
		else if (MouseCollision(Return_Print_Rect_Exit_Button(), MousePos))
		{
			Mouse_Lighten = LIGHTEN_EXIT_BUTTON;
		}
		else if (MouseCollision(Return_Print_Rect_Golden_Hair_Button(), MousePos))
		{
			Mouse_Lighten = LIGHTEN_GOLDEN_HAIR_BUTTON;
		}
		else if (MouseCollision(Return_Print_Rect_Black_Hair_Button(), MousePos))
		{
			Mouse_Lighten = LIGHTEN_BLACK_HAIR_BUTTON;
		}
		else if (MouseCollision(Return_Print_Rect_How_To_Button(), MousePos))
		{
			Mouse_Lighten = LIGHTEN_HOW_TO_BUTTON;
		}
	}



		switch (event.type)
		{
		case SDL_QUIT:
			bIsQuit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (state == STATE_MAIN_MENU)
				{
					if (MouseCollision(Print_Rect_Start_Button, MousePos))
					{
						state = STATE_IN_GAME;
						bAct = true;
						if (!Tick_Count) In_Game_Init();
					}
					else if (MouseCollision(Print_Rect_Exit_Button, MousePos))
					{
						bIsQuit = true;
					}
					else if (MouseCollision(Print_Rect_Black_Hair_Button, MousePos))
					{
						if (!bIsBlack)
						{
							Image_Main_Menu = SDL_LoadBMP("./Pictures/main_black.bmp");

							bIsBlack = true;
						}
					}
					else if (MouseCollision(Print_Rect_Golden_Hair_Button, MousePos))
					{
						if (bIsBlack)
						{
							Image_Main_Menu = SDL_LoadBMP("./Pictures/main_golden.bmp");

							bIsBlack = false;
						}
					}
					else if (MouseCollision(Print_Rect_How_To_Button, MousePos))
					{
						state = STATE_HOW_TO;
					}
				}
			}
		case SDL_KEYDOWN:
			if (state == STATE_IN_GAME)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					bIsMoveUp = true;
					bIsMoving = true;
					break;
				case SDLK_DOWN:
					bIsMoveUp = false;
					bIsMoving = true;
					break;
				}
			}
			else if (state == STATE_HOW_TO)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					state = STATE_MAIN_MENU;
					break;
				}
			}

		}

		
	
		if (bAct)
		{
			if (bIsMoving)
			{
				player->Move(bIsMoveUp);
				if (player->Return_bIsMoveEnough()) bIsMoving = false;
			}
		}


	int delay = 0;

	//delay = 1000 / 30 - (SDL_GetTicks() - startTick);
	if (state != STATE_IN_GAME) delay = 30;
	else delay = 100;


	if (delay > 0)
		SDL_Delay(delay);	

		return 0;
}


int MainProc::Render()
{
	if (animation)
	{
		static int Ani_Count = 0;
		switch (animation)
		{ 
		case ANIMATION_DEAD_BY_MAID:
			SDL_BlitSurface(ani[1].Return_Image(Ani_Count), NULL, Screen, NULL);
			SDL_Delay(1000);

			if ((Ani_Count) == ani[1].Return_NumOfImage())
			{
				animation = 0;

				SDL_Delay(1000);
			}
			break;
		case ANIMATION_GOt_EUNUCH:
			SDL_BlitSurface(ani[0].Return_Image(Ani_Count), NULL, Screen, NULL);
			SDL_Delay(1000);

			if ((player->Return_Eunuch_Count() == 5) && (Ani_Count == 6))
			{
				SDL_BlitSurface(ani[0].Return_Image(6), NULL, Screen, NULL);
				SDL_BlitSurface(ani[0].Return_Image(7), NULL, Screen, NULL);
				SDL_Delay(2500);

				state == STATE_MAIN_MENU;
				bAct = false;
				In_Game_Release();
			}
			

			if ((Ani_Count + 1) == ani[0].Return_NumOfImage())
			{
				animation = 0;
				bAct = true;
			}
			break;
		}
		Ani_Count++;
		if (animation == 0) Ani_Count = 0;
	}
	else {
		static int Ani_Count = 0;
		switch (state)
		{
		case STATE_MAIN_MENU:
			SDL_BlitSurface(Image_Main_Menu, NULL, Screen, NULL);
			SDL_BlitSurface(Image_Start_Button, NULL, Screen, Print_Rect_Start_Button);
			SDL_BlitSurface(Image_Exit_Button, NULL, Screen, Print_Rect_Exit_Button);
			SDL_BlitSurface(Image_Golden_Hair_Button, NULL, Screen, Print_Rect_Golden_Hair_Button);
			SDL_BlitSurface(Image_Black_Hair_Button, NULL, Screen, Print_Rect_Black_Hair_Button);
			SDL_BlitSurface(Image_How_To_Button, NULL, Screen, Print_Rect_How_To_Button);

			switch (Mouse_Lighten)
			{
			case LIGHTEN_START_BUTTON:
				SDL_BlitSurface(Image_Lighten_Start_Button, NULL, Screen, Print_Rect_Start_Button);
				break;
			case LIGHTEN_EXIT_BUTTON:
				SDL_BlitSurface(Image_Lighten_Exit_Button, NULL, Screen, Print_Rect_Exit_Button);
				break;
			case LIGHTEN_GOLDEN_HAIR_BUTTON:
				SDL_BlitSurface(Image_Lighten_Golden_Hair_Button, NULL, Screen, Print_Rect_Golden_Hair_Button);
				break;
			case LIGHTEN_BLACK_HAIR_BUTTON:
				SDL_BlitSurface(Image_Lighten_Black_Hair_Button, NULL, Screen, Print_Rect_Black_Hair_Button);
				break;
			case LIGHTEN_HOW_TO_BUTTON:
				SDL_BlitSurface(Image_Lighten_How_To_Button, NULL, Screen, Print_Rect_How_To_Button);
				break;
			}
			

			break;
		case STATE_IN_GAME:
			SDL_BlitSurface(Image_In_Game_Background, NULL, Screen, NULL);
			SDL_BlitSurface(player->Return_Image(Ani_Count), NULL, Screen, player->Return_Print_Rect());
			SDL_BlitSurface(eunuch->Return_Image(Ani_Count), NULL, Screen, eunuch->Return_Print_Rect_Eunuch());
			for (int i = Start_Maid_Count; i < End_Maid_Count; i++)
			{
				SDL_BlitSurface(maid[i]->Return_Image(Ani_Count), NULL, Screen, maid[i]->Return_Print_Rect_Maid());
			}
			

			Ani_Count++;
			if (Ani_Count == 3) Ani_Count = 0;
			break;
		case STATE_HOW_TO:
			SDL_BlitSurface(Image_How_To, NULL, Screen, NULL);
			break;
		}
	}
	

	SDL_UpdateWindowSurface(pWnd);


	return 0;
}


int MainProc::Release()
{
	bAct = false;

	delete Print_Rect_How_To_Button;
	SDL_FreeSurface(Image_Lighten_How_To_Button);
	SDL_FreeSurface(Image_How_To_Button);

	SDL_FreeSurface(Image_Black_Hair_Button);
	SDL_FreeSurface(Image_Lighten_Black_Hair_Button);
	delete Print_Rect_Black_Hair_Button;

	SDL_FreeSurface(Image_Golden_Hair_Button);
	SDL_FreeSurface(Image_Lighten_Golden_Hair_Button);
	delete Print_Rect_Golden_Hair_Button;

	SDL_FreeSurface(Image_Exit_Button);
	SDL_FreeSurface(Image_Lighten_Exit_Button);
	delete Print_Rect_Exit_Button;

	SDL_FreeSurface(Image_Start_Button);
	SDL_FreeSurface(Image_Lighten_Start_Button);
	delete Print_Rect_Start_Button;
	
	player->Release();
	for (int i = Start_Maid_Count; i < End_Maid_Count; i++)
	{
		maid[i]->Release();
	}
	eunuch->Release();

	SDL_DestroyWindow(pWnd);

	SDL_Quit();

	return 0;
}


// Get

bool MainProc::GetAct()
{
	return bAct;
}

bool MainProc::BISQUIT()
{
	return bIsQuit;
}


SDL_Rect* MainProc::Return_Print_Rect_Start_Button()
{
	return Print_Rect_Start_Button;
}

SDL_Rect* MainProc::Return_Print_Rect_Exit_Button()
{
	return Print_Rect_Exit_Button;
}

SDL_Rect* MainProc::Return_Print_Rect_Golden_Hair_Button()
{
	return Print_Rect_Golden_Hair_Button;
}

SDL_Rect* MainProc::Return_Print_Rect_Black_Hair_Button()
{
	return Print_Rect_Black_Hair_Button;
}

SDL_Rect* MainProc::Return_Print_Rect_How_To_Button()
{
	return Print_Rect_How_To_Button;
}


void MainProc::In_Game_Release()
{
	player->Release();
	for (int i = Start_Maid_Count; i < End_Maid_Count; i++)
	{
		maid[i]->Release();
	}
	eunuch->Release();

	Tick_Count = 0;
}

void MainProc::In_Game_Init()
{
	// Init
	Subscript_Count = 0;

	player = new PLAYER;
	maid = new MAID*[1];
	eunuch = new EUNUCH;

	for (int i = 0; i < 2; i++)
	{
		*(maid + i) = new MAID;
	}

	player->Init();
	maid[0]->Init();
	maid[1]->Init();
	eunuch->Init();

	End_Maid_Count = 2;
	Start_Maid_Count = 0;


	Tick_Count = 1;
}