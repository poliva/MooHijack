#pragma once

#include <Windows.h>

#include "util.h"

#define NUMBER_OF_GAMES		8

typedef enum { CPS1, CPS2, CPS3, UNKNOWN } SYSTEM;

typedef struct _GFX_SPRITES {
	DWORD	dwGfxSpritesStart;
	DWORD	dwGfxSpritesEnd;
	DWORD	dwBankStart;
	DWORD	dwBankEnd;
} GFX_SPRITES;

typedef struct _GFX_SCROLL {
	DWORD	dwGfxScrollStart;
	DWORD	dwGfxScrollEnd;
	DWORD	dwBankStart;
	DWORD	dwBankEnd;
	DWORD   dwEndMarker;
} GFX_SCROLL;

typedef struct _MAPPER_GFX {
	GFX_SPRITES	GfxSpritesInfo[3];
	DWORD		dwGfxSpritesEndMarker;
	GFX_SCROLL	GfxScrollInfo[3];
} MAPPER_GFX;

typedef struct _CPSB_INFO {
	DWORD	dwCpuClockRate;
	DWORD	dwCPSB;
	DWORD	dwCtrl;
	DWORD	dwPalctrl;
	DWORD	dwPriorityMask[4];
	DWORD   dwMultiplyProtection[4];
	DWORD	dwIn2;
	DWORD	dwID;
	DWORD	dwLayerEnableMask[5];
} CPSB_INFO;

typedef struct _GAME_INFO {
	CPSB_INFO	CpsbInfo;
	MAPPER_GFX	MapperGfx;
} GAME_INFO;

typedef struct _ROMS_INFO {
	DWORD	dw68kSize;
	DWORD	dwVromSize;
	DWORD	dwOkiSize;
	DWORD	dwZ80Size;
	DWORD	dwLogoSize;
} ROMS_INFO;

typedef struct _GAME_LIST {
	GAME_INFO       GameInfo;
	ROMS_INFO       RomsInfo;
	SYSTEM			System;
	BOOL			bIsMulti;
	WORD			CoinOffset;
	PCHAR			Name;
	PCHAR			Hash;
} GAME_LIST;

GAME_LIST GameList[NUMBER_OF_GAMES];
INT dwCurrentGameID;

VOID DB_Init();
