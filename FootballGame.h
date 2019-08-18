//-----------------------------------------------------------------
// Fore Application
// C++ Header - Fore.h
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <windows.h>
#include "Resource.h"
#include "GameEngine.h"
#include "Bitmap.h"
#include "Sprite.h"

//-----------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------
HINSTANCE   _hInstance;
GameEngine* _pGame;
Bitmap*     Player_Red_bitmap1;
Bitmap*     Player_Red_bitmap2;
Bitmap*     Player_Red_bitmap3;
Bitmap*     Player_Red_bitmap4;
Bitmap*     Player_Blue_bitmap;
Bitmap*     Areabitmap;

HDC         _hOffscreenDC;
HBITMAP     _hOffscreenBitmap;

Bitmap*      Kale_BlueBitmap;
Bitmap*     KaleBitmap;
Bitmap*     Footballballbitmap;
Bitmap*     _GameOver_Football;
Bitmap*     _Win_Football;

Sprite*     Player_Red_sprite[4];
Sprite*     Player_Blue_sprite[4];
Sprite*     Areasprite;
Sprite*     Footballballsprite;
Sprite*     KaleSprite;
Sprite*      Kale_BlueSprite;
Sprite* pSprite;
Sprite*     _pDragSprite;

BOOL        _bDragging;
int         _iDragBall;
int               _iNumLives, _RediScore, _BlueiScore, _iDifficulty;
BOOL              _bGameOver;
BOOL              _bWin;
void NewGame();
void UpdateBlue_Player();