#include "pch.h"
#include "CSockt.h"


int CSockt::SendPacket(char* Msg, int size)
{
	return	(*(int(__thiscall*)(CSockt*, char*, int))SendPacketAddr_27032020)(this, Msg, size);
}