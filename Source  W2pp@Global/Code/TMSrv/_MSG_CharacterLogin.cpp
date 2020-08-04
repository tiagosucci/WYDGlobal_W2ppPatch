/*
*   Copyright (C) {2015}  {VK, Charles TheHouse}
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see [http://www.gnu.org/licenses/].
*
*   Contact at:
*/
#include "ProcessClientMessage.h"

void Exec_MSG_CharacterLogin(int conn, char* pMsg)
{
	MSG_CharacterLogin* m = (MSG_CharacterLogin*)pMsg;

	if (m->Slot < 0 || m->Slot >= MOB_PER_ACCOUNT)
	{
		SendClientMessage(conn, g_pMessageStringTable[_NN_SelectCharacter]);
		return;
	}

	if (pUser[conn].Mode == USER_SELCHAR)
	{
		m->Type = _MSG_DBCharacterLogin;
		m->ID = conn;

		pUser[conn].Mode = USER_CHARWAIT;
		pMob[conn].Mode = MOB_USER;

		pMob[conn].MOB.Merchant = 0;

		DBServerSocket.SendOneMessage((char*)m, sizeof(MSG_CharacterLogin));
		return;
	}

	SendClientMessage(conn, "Wait a moment.");
	sprintf(temp, "err,charlogin not user_selchar %d %d", conn, pUser[conn].Mode);
	Log(temp, pUser[conn].AccountName, pUser[conn].IP);

}