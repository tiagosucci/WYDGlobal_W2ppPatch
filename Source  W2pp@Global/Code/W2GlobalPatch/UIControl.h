#pragma once

#define callCdecl(addr, Retn, ...) (*(Retn (__cdecl*)(__VA_ARGS__)) addr)
#define callThiscall(addr, Retn, ...) (*(Retn (__thiscall*)(__VA_ARGS__)) addr)
#define callstdcall(addr, Retn, ...) (*(Retn (__stdcall*)(__VA_ARGS__)) addr)

class UI_Main : public Singleton<UI_Main>
{
public:
	static DWORD getMainWindow()
	{
		static DWORD value;

		__asm
		{
			MOV EAX, DWORD PTR DS : [0x872000]
			MOV value, EAX
		}

		return value;
	}
 
	template<class T> static T* getGuiFromValue(DWORD Value)
	{
		return reinterpret_cast<T*>(*(DWORD*)(getMainWindow() + Value));
	}

};

