#pragma once

#define WIN32_LEAN_AND_MEAN             // Excluir itens raramente utilizados dos cabeçalhos do Windows
// Arquivos de Cabeçalho do Windows
#include <windows.h>
#include <new>
#include <cstdint>
#include <cstdio>



#define _MSG      	short		  Size;			\
					char		  KeyWord;		\
					char		  CheckSum;		\
					short		  Type;			\
					short		  ID;			\
					unsigned int  ClientTick;

struct		 MSG_STANDARD
{
	_MSG;
};

struct		  MSG_AccountLogin
{
	_MSG;

	char AccountPassword[36];
	char AccountName[16];

	char Zero[52];


	int  ClientVersion;

	int  DBNeedSave;

	int AdapterName[4];
};
 










#define curDate 27032020



// sub_4364F0((SOCKET *)dword_2453BC0, &v35, 116);
#define CSockAddr_27032020 0x2453BC0
#define CSendPacketAddr_27032020 0x4364F0
#define SendPacketAddr_27032020 0x57A100


#define fServerListAddr_27032020 0x56C300
#define BufferServerList_27032020 0x007CB9E0