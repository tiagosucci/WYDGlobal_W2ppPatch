#include "..\Basedef.h"
#include "..\ItemEffect.h"
#include "Language.h"

#include "Server.h"
#include "GetFunc.h"
#include "SendFunc.h"
#include "CCastleZakum.h"


int ControleDropGold(int conn,int target,int DropedGold)
{
	int GoldFinal = DropedGold;





	return GoldFinal;
}

STRUCT_ITEM* ControleDropItem(int conn, int target,int bonus,int PosX,int PosY, STRUCT_ITEM *Item)
{
	STRUCT_ITEM* ItemDrop = Item;




	if (ItemDrop->sIndex != 0 && CCastleZakum::KeyDrop(target, conn, PosX, PosY, ItemDrop) == TRUE)
	{
		SetItemBonus(ItemDrop, pMob[target].MOB.CurrentScore.Level, 0, bonus);
		if (PutItem(conn, ItemDrop))
		{

			sprintf(temp, "MobName:%s dropou o item: %s:%d %d.%d.%d.%d.%d.%d do mob:%s", pMob[conn].MOB.MobName, g_pItemList[ItemDrop->sIndex].Name, ItemDrop->sIndex, ItemDrop->stEffect[0].cEffect, ItemDrop->stEffect[0].cValue, ItemDrop->stEffect[1].cEffect, ItemDrop->stEffect[1].cValue, ItemDrop->stEffect[2].cEffect, ItemDrop->stEffect[2].cValue, pMob[target].MOB.MobName);
			if (conn > 0 && conn < MAX_USER)
				Log(temp, pUser[conn].AccountName, pUser[conn].IP);
		}
	}


	return ItemDrop;
}