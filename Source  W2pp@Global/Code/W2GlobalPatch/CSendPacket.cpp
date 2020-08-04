#include "pch.h"


void ClientPatch::CSendpacket(MSG_STANDARD* pMsg, int size)
{
	printf("packet: 0x%X Size: %d ID: %d\n", pMsg->Type, pMsg->Size, pMsg->ID);

	ClientPatch::instance().SendServerMessage(pMsg, size);
}