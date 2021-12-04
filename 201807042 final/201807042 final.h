﻿#pragma once

#include "resource.h"

// 만든 게임
#include "Dodge.h"

using namespace std;


// 필요한 상수를 정의
#define WINDOW_COLOR RGB(230,230,230)
#define FRAME_TIMER 0
#define NOW_FPS 30/1000

#define WM_GAME_CREATE WM_USER
#define WM_GAME_START WM_USER+1
#define WM_GAME_OVER WM_USER+2