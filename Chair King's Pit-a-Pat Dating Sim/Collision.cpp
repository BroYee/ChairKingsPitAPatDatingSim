#include "stdafx.h"

bool Collision(const SDL_Rect* rc1, const SDL_Rect* rc2)
{
	SDL_Rect rc;
	if (SDL_IntersectRect(rc1, rc2, &rc))
	{
		return true;
	}
	return false;
}


bool MouseCollision(SDL_Rect* rc, COORD pos)
{
	if ((rc->x <= pos.X) && (pos.X <= (rc->x + rc->w)))
	{
		if ((rc->y <= pos.Y) && (pos.Y <= (rc->y + rc->h)))
		{
			return true; printf("Collision True");
		}
	}
	return false;
}