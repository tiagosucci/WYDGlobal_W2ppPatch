#pragma once

class CSockt
{
	static CSockt& Instance()
	{
		static uint32_t rtnValue = 0;

		__asm
		{
			MOV EAX, DWORD PTR DS : [CSockAddr_27032020]
			MOV rtnValue, EAX
		}

		static auto p = reinterpret_cast<CSockt*>(rtnValue);
		return *p;
	}
private:
	int SendPacket(char* Msg, int size);

};

