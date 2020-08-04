#include "pch.h"

bool ClientPatch::Initialize()
{
	static auto& hook = Singleton<HookMgr>::instance();

	unsigned int checksumAddrs_27032020[] = {
		/*ItemList*/0x005645B3 ,
		/*ExtraItem*/0x0056470A,
		/*SkillData*/0x005644B2
	};
	BYTE checkValue[] = { 0xEB,0xEB ,0xEB };

	//Altera a Leitura da ServerList
	//hook.setHook(eHookType::JMP, fServerListAddr_27032020, this->ChangeReadServerList());
	//Controle de SendPacket
	//hook.setHook(eHookType::JMP, SendPacketAddr_27032020, hook.getAddress(&ClientPatch::CSendpacket));
	//Chemove o checksum do client
	hook.setArrayValue<BYTE>(checksumAddrs_27032020, checkValue, sizeof(checksumAddrs_27032020) / sizeof(decltype(checksumAddrs_27032020)));


	//hook.setHook(eHookType::JMP, 0x004EB830, hook.getAddress(&ClientPatch::SetLoadConstume));

	return true;
}






//----- (004EB830) --------------------------------------------------------
//char* __thiscall sub_4EB830(_DWORD* this, int a2, char* a3, char* a4)
//a2 = trajeID
//a3 = MSH
//a4 = WYT



char* ClientPatch::SetLoadConstume(int a2, char* a3, char* a4)
{


	return 0;
}















 

void ClientPatch::SSendPacket(MSG_STANDARD* pMsg, int _Size)
{
	//sub_4364E0((SOCKET *)dword_2453260, &v35, 116);

	static int address = CSendPacketAddr_27032020;

	__asm
	{
		push _Size
		push pMsg
		mov ecx, dword ptr ds : [CSockAddr_27032020]
		call address
	}
}
 
void ClientPatch::SendServerMessage(MSG_STANDARD* pMsg, int hSize)
{
	DWORD Address = SendPacketAddr_27032020;

	__asm
	{
		PUSH hSize
		PUSH pMsg

		CALL Address
	}
}

 