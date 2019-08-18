


//açýyla vuruþ
//yapay zeka


//-----------------------------------------------------------------
// Fore Application
// C++ Source - FootballGame.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "FootballGame.h"

//-----------------------------------------------------------------
// Game Engine Functions
//-----------------------------------------------------------------
BOOL GameInitialize(HINSTANCE hInstance)
{
	// Create the game engine
	_pGame = new GameEngine(hInstance, TEXT("DreamFootball"),
		TEXT("DreamFootball"), IDI_Footbaal_Icon, IDI_Footbaal_Icon_SM, 1080, 700);
	if (_pGame == NULL)
		return FALSE;

	// Set the frame rate
	_pGame->SetFrameRate(30);

	// Store the instance handle
	_hInstance = hInstance;
	
	return TRUE;
}

void GameStart(HWND hWindow)
{
	// Seed the random number generator
	srand(GetTickCount());


	Sprite* pSprite;
	// Create the offscreen device context and bitmap
	_hOffscreenDC = CreateCompatibleDC(GetDC(hWindow));
	_hOffscreenBitmap = CreateCompatibleBitmap(GetDC(hWindow),
		_pGame->GetWidth(), _pGame->GetHeight());
	SelectObject(_hOffscreenDC, _hOffscreenBitmap);
	
	// Create and load the bitmaps
	HDC hDC = GetDC(hWindow);
	
    Player_Red_bitmap1= new Bitmap(hDC, IDB_Players_Red1, _hInstance);
	Player_Red_bitmap2 = new Bitmap(hDC, IDB_Players_Red2, _hInstance);
	Player_Red_bitmap3 = new Bitmap(hDC, IDB_Players_Red3, _hInstance);
	Player_Red_bitmap4 = new Bitmap(hDC, IDB_Players_Red4, _hInstance);
	Player_Blue_bitmap = new Bitmap(hDC, IDB_Player_Blue, _hInstance);
	Areabitmap = new Bitmap(hDC, IDB_Background, _hInstance);
	Footballballbitmap = new Bitmap(hDC, IDB_Ball, _hInstance);
	KaleBitmap = new Bitmap(hDC, IDB_Kale, _hInstance);
	Kale_BlueBitmap = new Bitmap(hDC, IDB_Kale_Blue, _hInstance);
	_GameOver_Football = new Bitmap(hDC,IDB_GAMEOVER,_hInstance);
	_Win_Football = new Bitmap(hDC, IDB_YOUWIN, _hInstance);

	RECT Kale_BluercBounds = { 1045, 300, 1080, 350 };
	Kale_BlueSprite = new Sprite(Kale_BlueBitmap,Kale_BluercBounds, BA_STOP);
	Kale_BlueSprite->SetPosition(1080,300);
	_pGame->AddSprite(Kale_BlueSprite);

	

	RECT Kale_rcBounds = { 0, 300, 29, 350 };
	KaleSprite = new Sprite(KaleBitmap, Kale_rcBounds,BA_STOP);
	KaleSprite->SetPosition(0,300);
	_pGame->AddSprite(KaleSprite);



	RECT Player_FootballrcBounds = { 29, 0, 1055, 700 };
	Footballballsprite = new Sprite(Footballballbitmap, Player_FootballrcBounds, BA_BOUNCE);
	Footballballsprite->SetPosition(540, 350);
	Footballballsprite->SetVelocity(3, -5); 
	_pGame->AddSprite(Footballballsprite);

	
	

	// Create the golf ball sprites
	RECT Player_RedrcBounds = { 30, 0, 1050, 700 };
	Player_Red_sprite[0] = new Sprite(Player_Red_bitmap1, Player_RedrcBounds,BA_STOP);
	Player_Red_sprite[1] = new Sprite(Player_Red_bitmap2, Player_RedrcBounds,BA_STOP);
	Player_Red_sprite[2] = new Sprite(Player_Red_bitmap3, Player_RedrcBounds,BA_STOP);
	Player_Red_sprite[3] = new Sprite(Player_Red_bitmap4, Player_RedrcBounds, BA_STOP);


	Player_Red_sprite[0]->SetPosition(300, 100);
	_pGame->AddSprite(Player_Red_sprite[0]);
	_pGame->AddSprite(Player_Red_sprite[0]);
	

	Player_Red_sprite[1]->SetPosition(400, 300);
	_pGame->AddSprite(Player_Red_sprite[1]);
	_pGame->AddSprite(Player_Red_sprite[1]);
	
	
	Player_Red_sprite[2]->SetPosition(300, 500);
	_pGame->AddSprite(Player_Red_sprite[2]);
	_pGame->AddSprite(Player_Red_sprite[2]);


	Player_Red_sprite[3]->SetPosition(100, 300);
	_pGame->AddSprite(Player_Red_sprite[3]);
	_pGame->AddSprite(Player_Red_sprite[3]);
	
	RECT Player0_BluercBounds = { 30, 2, 1050, 200 };
	RECT Player1_BluercBounds = { 550, 200, 1050, 400 };
	RECT Player2_BluercBounds = { 30, 500, 1050, 690 };
	RECT Player3_BluercBounds = { 30, 100, 1050, 600 };
	
	Player_Blue_sprite[0] = new Sprite(Player_Blue_bitmap, Player0_BluercBounds, BA_STOP);
	Player_Blue_sprite[1] = new Sprite(Player_Blue_bitmap, Player1_BluercBounds, BA_STOP);
	Player_Blue_sprite[2] = new Sprite(Player_Blue_bitmap, Player2_BluercBounds, BA_STOP);
	Player_Blue_sprite[3] = new Sprite(Player_Blue_bitmap, Player3_BluercBounds, BA_STOP);
	

	Player_Blue_sprite[0]->SetPosition(700, 100);
	Player_Blue_sprite[0]->SetVelocity(5, 2);

	_pGame->AddSprite(Player_Blue_sprite[0]);
	_pGame->AddSprite(Player_Blue_sprite[0]);



	Player_Blue_sprite[1]->SetPosition(800, 300);
	Player_Blue_sprite[1]->SetVelocity(3, -5);
	_pGame->AddSprite(Player_Blue_sprite[1]);
	_pGame->AddSprite(Player_Blue_sprite[1]);


	Player_Blue_sprite[2]->SetPosition(700, 500);
	Player_Blue_sprite[2]->SetVelocity(2, 5);
	_pGame->AddSprite(Player_Blue_sprite[2]);
	_pGame->AddSprite(Player_Blue_sprite[2]);
	
	
	Player_Blue_sprite[3]->SetPosition(600, 300);
	Player_Blue_sprite[3]->SetVelocity(2, 5);
	_pGame->AddSprite(Player_Blue_sprite[3]);
	_pGame->AddSprite(Player_Blue_sprite[3]);

	// Set the initial drag info
	//_pDragSprite = NULL;
}

void GameEnd()
{
	// Cleanup the offscreen device context and bitmap
	DeleteObject(_hOffscreenBitmap);
	DeleteDC(_hOffscreenDC);
	// Cleanup the bitmaps
	delete Areabitmap;
	delete Player_Red_bitmap1;
	delete Player_Red_bitmap2;
	delete Player_Red_bitmap3;
	delete Player_Red_bitmap4;
	delete Player_Blue_bitmap;
	delete KaleBitmap;
	delete Kale_BlueBitmap;
	delete _GameOver_Football;
	delete _Win_Football;
	// Cleanup the sprites
	for (int i = 0; i < 4; i++)
		delete Player_Red_sprite[i];

	for (int i = 0; i < 4; i++)
		delete Player_Blue_sprite[i];
	// Cleanup the game engine
	delete _pGame;
	delete Footballballbitmap;
}

void GameActivate(HWND hWindow)
{
}

void GameDeactivate(HWND hWindow)
{
}

void GamePaint(HDC hDC)
{
	// Draw the background forest
	Areabitmap->Draw(hDC, 0, 0);
	Footballballsprite->Draw(hDC);
	KaleSprite->Draw(hDC);
	Kale_BlueSprite->Draw(hDC);
	// Draw the golf ball sprites
	for (int i = 0; i < 4; i++)
		Player_Red_sprite[i]->Draw(hDC);
	

	for (int i = 0; i < 4; i++)
		Player_Blue_sprite[i]->Draw(hDC);
	//game
	if (_bGameOver){
		_GameOver_Football->Draw(hDC, 20, 100, TRUE);

	}
	if (_bWin){
		_Win_Football->Draw(hDC, 330, 140, TRUE);
	}

	// Draw the score
	TCHAR szText[64];
	RECT  rect = { 400, 0, 600, 10 };
	wsprintf(szText, "Score %d : %d ", _RediScore, _BlueiScore);
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(255, 255, 255));
	DrawText(hDC, szText, -1, &rect, DT_SINGLELINE | DT_RIGHT | DT_VCENTER);

	
}

void GameCycle()
{
	// Update the players and ball sprites


		for (int i = 0; i < 4; i++) Player_Blue_sprite[i];
	for (int i = 0; i < 4; i++) Player_Red_sprite[i];
	
        Footballballsprite->Update();
		_pGame->UpdateSprites();
		UpdateBlue_Player();

	InvalidateRect(_pGame->GetWindow(), NULL, FALSE);

	

	// Obtain a device context for repainting the game
	HWND  hWindow = _pGame->GetWindow();
	HDC   hDC = GetDC(hWindow);

	// Paint the game to the offscreen device context
	GamePaint(_hOffscreenDC);


	

	// Blit the offscreen bitmap to the game screen
	BitBlt(hDC, 0, 0, _pGame->GetWidth(), _pGame->GetHeight(),
		_hOffscreenDC, 0, 0, SRCCOPY);

	// Cleanup
	ReleaseDC(hWindow, hDC);
}

void HandleKeys()
{

	if (!_bGameOver &&!_bWin){



	if (GetKeyState(0x31) ){
	Player_Red_sprite[0]->SetVelocity(0, 0);
	if (GetAsyncKeyState(VK_LEFT) < 0) Player_Red_sprite[0]->SetVelocity(-3, 0);
	else if (GetAsyncKeyState(VK_RIGHT) < 0)Player_Red_sprite[0]->SetVelocity(3, 0);
	if (GetAsyncKeyState(VK_UP) < 0) Player_Red_sprite[0]->SetVelocity(0, -3);
	else if (GetAsyncKeyState(VK_DOWN) < 0) Player_Red_sprite[0]->SetVelocity(0, 3);

	if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[0]->SetVelocity(3, -3);
	else if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[0]->SetVelocity(-3, -3);
	if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[0]->SetVelocity(3, 3);
	else if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[0]->SetVelocity(-3, 3);

	
	}
	
 if (GetKeyState(0x32)){
	Player_Red_sprite[1]->SetVelocity(0, 0);
	if (GetAsyncKeyState(VK_LEFT) < 0) Player_Red_sprite[1]->SetVelocity(-3, 0);
	else if (GetAsyncKeyState(VK_RIGHT) < 0)Player_Red_sprite[1]->SetVelocity(3, 0);
	if (GetAsyncKeyState(VK_UP) < 0) Player_Red_sprite[1]->SetVelocity(0, -3);
	else if (GetAsyncKeyState(VK_DOWN) < 0) Player_Red_sprite[1]->SetVelocity(0, 3);

	if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[1]->SetVelocity(3, -3);
	else if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[1]->SetVelocity(-3, -3);
	if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[1]->SetVelocity(3, 3);
	else if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[1]->SetVelocity(-3, 3);


	}


	if (GetKeyState(0x33)){
	Player_Red_sprite[2]->SetVelocity(0, 0);
	if (GetAsyncKeyState(VK_LEFT) < 0) Player_Red_sprite[2]->SetVelocity(-3, 0);
	else if (GetAsyncKeyState(VK_RIGHT) < 0)Player_Red_sprite[2]->SetVelocity(3, 0);
	if (GetAsyncKeyState(VK_UP) < 0) Player_Red_sprite[2]->SetVelocity(0, -3);
	else if (GetAsyncKeyState(VK_DOWN) < 0) Player_Red_sprite[2]->SetVelocity(0, 3);


	if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[2]->SetVelocity(3, -3);
	else if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[2]->SetVelocity(-3, -3);
	if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[2]->SetVelocity(3, 3);
	else if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[2]->SetVelocity(-3, 3);
	}

	if (GetKeyState(0x34)) {
		Player_Red_sprite[3]->SetVelocity(0, 0);
		if (GetAsyncKeyState(VK_LEFT) < 0) Player_Red_sprite[3]->SetVelocity(-3, 0);
		else if (GetAsyncKeyState(VK_RIGHT) < 0)Player_Red_sprite[3]->SetVelocity(3, 0);
		if (GetAsyncKeyState(VK_UP) < 0) Player_Red_sprite[3]->SetVelocity(0, -3);
		else if (GetAsyncKeyState(VK_DOWN) < 0) Player_Red_sprite[3]->SetVelocity(0, 3);


		if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[3]->SetVelocity(3, -3);
		else if ((GetAsyncKeyState(VK_UP) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[3]->SetVelocity(-3, -3);
		if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_RIGHT)< 0)) Player_Red_sprite[3]->SetVelocity(3, 3);
		else if ((GetAsyncKeyState(VK_DOWN) < 0) && (GetAsyncKeyState(VK_LEFT)< 0)) Player_Red_sprite[3]->SetVelocity(-3, 3);
	}
	//
	}
	


	
}
void MouseButtonDown(int x, int y, BOOL bLeft)
{
	// See if a ball was clicked with the left mouse button
	if (bLeft && !_bDragging)
	{
		for (int i = 0; i < 3; i++)
			if (Player_Red_sprite[i]->IsPointInside(x, y))
			{
				// Capture the mouse
				SetCapture(_pGame->GetWindow());

				// Set the drag state and the drag ball
				_bDragging = TRUE;
				_iDragBall = i;

				// Simulate a mouse move to get started
				MouseMove(x, y);

				// Don't check for more balls
				break;
			}
		for (int i = 0; i < 3; i++)
			if (Player_Blue_sprite[i]->IsPointInside(x, y))
			{
				// Capture the mouse
				SetCapture(_pGame->GetWindow());

				// Set the drag state and the drag ball
				_bDragging = TRUE;
				_iDragBall = i;

				// Simulate a mouse move to get started
				MouseMove(x, y);

				// Don't check for more balls
				break;
			}
	}
}

void MouseButtonUp(int x, int y, BOOL bLeft)
{
	// Release the mouse
	ReleaseCapture();

	// Stop dragging
	_bDragging = FALSE;
}

void MouseMove(int x, int y)
{
	if (_bDragging)
	{
		//// Move the sprite to the mouse cursor position
		//tanksprite[_iDragBall]->SetPosition(
		//  x - (tanksprite->GetWidth() / 2),
		//  y - (tanksprite->GetHeight() / 2));

		//// Force a repaint to redraw the golf balls
		//InvalidateRect(_pGame->GetWindow(), NULL, FALSE);
	}
}

void HandleJoystick(JOYSTATE jsJoystickState)
{
}
BOOL SpriteCollision(Sprite* pSpriteHitter, Sprite* pSpriteHittee)
{
  // Swap the sprite velocities so that they appear to bounce
  POINT ptSwapVelocity = pSpriteHitter->GetVelocity();
  pSpriteHitter->SetVelocity(pSpriteHittee->GetVelocity());
  pSpriteHittee->SetVelocity(ptSwapVelocity);

  // Update the score
  Bitmap* pHitter = pSpriteHitter->GetBitmap();
  Bitmap* pHittee = pSpriteHittee->GetBitmap();

  if ((pHitter == Footballballbitmap && (pHittee == KaleBitmap)))
  {
	  PlaySound((LPCSTR)IDR_GOL, _hInstance, SND_ASYNC |
		  SND_RESOURCE);
	  _BlueiScore += 1;

	  if (_BlueiScore == 3){
		  PlaySound((LPCSTR)IDR_GAMEOVER, _hInstance, SND_ASYNC |
			  SND_RESOURCE);
		  _bGameOver = TRUE;
	  }
	  
	  
	  Footballballsprite->SetPosition(540, 350);
	  Player_Red_sprite[0]->SetPosition(300, 100);
	  Player_Red_sprite[1]->SetPosition(400, 300);
	  Player_Red_sprite[3]->SetPosition(100, 300);
	  Player_Red_sprite[2]->SetPosition(300, 500);

	  Player_Blue_sprite[0]->SetPosition(700, 100);
	  Player_Blue_sprite[1]->SetPosition(600, 300);
	  Player_Blue_sprite[3]->SetPosition(800, 300);
	  Player_Blue_sprite[2]->SetPosition(700, 500);

	  
	  
	  

  }
  
	  
  else if ((pHitter == Footballballbitmap && (pHittee == Kale_BlueBitmap)))
  {
	  PlaySound((LPCSTR)IDR_GOL, _hInstance, SND_ASYNC |
		  SND_RESOURCE);
	  _RediScore += 1;
	  if (_RediScore == 3){
		  PlaySound((LPCSTR)IDR_WAVE1, _hInstance, SND_ASYNC |
			  SND_RESOURCE);
		  _bWin = TRUE;

	  }
	  
	  Footballballsprite->SetPosition(500, 300);

	  Player_Red_sprite[0]->SetPosition(300, 100);
	  Player_Red_sprite[1]->SetPosition(400, 300);
	  Player_Red_sprite[2]->SetPosition(300, 500);

	  Player_Blue_sprite[0]->SetPosition(700, 100);

	  Player_Blue_sprite[1]->SetPosition(600, 300);
	  Player_Blue_sprite[2]->SetPosition(700, 500);
	  Kale_BlueSprite->SetPosition(1080, 300);
	  
  }
 
  
 

  return TRUE;
}


void UpdateBlue_Player() {
	RECT rcSaucer, rcRoid;
	rcSaucer = Footballballsprite->GetPosition();

	// Find out which asteroid is closest to the saucer
	int iXCollision = 1050, iYCollision = 700, iXYCollision = 1750;
	for (int i = 0; i < 4; i++)
	{
		// Get the asteroid position
		rcRoid = Player_Blue_sprite[i]->GetPosition();

		// Calculate the minimum XY collision distance
		int iXCollisionDist = (rcSaucer.left +
			(rcSaucer.right - rcSaucer.left) / 2) -
			(rcRoid.left +
			(rcRoid.right - rcRoid.left) / 2);
		int iYCollisionDist = (rcSaucer.top +
			(rcSaucer.bottom - rcSaucer.top) / 2) -
			(rcRoid.top +
			(rcRoid.bottom - rcRoid.top) / 2);
		if ((abs(iXCollisionDist) < abs(iXCollision)) ||
			(abs(iYCollisionDist) < abs(iYCollision)))
			if ((abs(iXCollisionDist) + abs(iYCollisionDist)) < iXYCollision)
			{
				iXYCollision = abs(iXCollision) + abs(iYCollision);
				iXCollision = iXCollisionDist;
				iYCollision = iYCollisionDist;
			}
	}

	// Move to dodge the asteroids, if necessary
	POINT ptVelocity, ptVelocity1, ptVelocity2, ptVelocity3;
	ptVelocity = Player_Blue_sprite[0]->GetVelocity();
	ptVelocity1 = Player_Blue_sprite[1]->GetVelocity();
	ptVelocity2 = Player_Blue_sprite[2]->GetVelocity();
	ptVelocity3 = Player_Blue_sprite[3]->GetVelocity();
	POINT TOP = Footballballsprite->GetVelocity();
	if (abs(iXCollision))
	{
		// Adjust the X velocity
		if (iXCollision > 0)
			ptVelocity.x = max(ptVelocity.x -2,4);
		else
			ptVelocity.x = min(ptVelocity.x + 2,-4);
	}
	if (abs(iYCollision))
	{
		// Adjust the Y velocity
		if (iYCollision > 0)
			ptVelocity.y = max(ptVelocity.y - 2,4 );
		else
			ptVelocity.y = min(ptVelocity.y + 2, -4);
	}

	if (abs(iXCollision))
	{
		// Adjust the X velocity
		if (iXCollision > 0)
			ptVelocity1.x = max(ptVelocity1.x - 2, 4);
		else
			ptVelocity1.x = min(ptVelocity1.x + 2, -4);
	}
	if (abs(iYCollision))
	{
		// Adjust the Y velocity
		if (iYCollision > 0)
			ptVelocity1.y = max(ptVelocity1.y - 2, +4);
		else
			ptVelocity1.y = min(ptVelocity1.y + 2, -4);
	}
	if (abs(iXCollision))
	{
		// Adjust the X velocity
		if (iXCollision > 0)
			ptVelocity2.x = max(ptVelocity2.x - 2, 4);
		else
			ptVelocity2.x = min(ptVelocity2.x + 2, -4);
	}
	if (abs(iYCollision))
	{
		// Adjust the Y velocity
		if (iYCollision > 0)
			ptVelocity2.y = max(ptVelocity2.y - 2, +4);
		else
			ptVelocity2.y = min(ptVelocity2.y + 2, -4);
	}



	if (abs(iXCollision))
	{
		// Adjust the X velocity
		if (iXCollision > 0)
			ptVelocity3.x = max(ptVelocity3.x - 2, 4);
		else
			ptVelocity3.x = min(ptVelocity3.x + 2, -2);
	}
	if (abs(iYCollision))
	{
		// Adjust the Y velocity
		if (iYCollision > 0)
			ptVelocity3.y = max(ptVelocity3.y - 2, +4);
		else
			ptVelocity3.y = min(ptVelocity3.y + 2, -4);
	}

	// Update the saucer to the new position
	Player_Blue_sprite[0]->SetVelocity(ptVelocity);
	Player_Blue_sprite[1]->SetVelocity(ptVelocity1);
	Player_Blue_sprite[2]->SetVelocity(ptVelocity2);
	Player_Blue_sprite[3]->SetVelocity(ptVelocity3);
}