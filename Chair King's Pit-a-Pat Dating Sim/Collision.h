#pragma once

#include <SDL.h>

bool Collision(const SDL_Rect* rc1, const SDL_Rect* rc2);

bool MouseCollision(SDL_Rect* rc, COORD pos);