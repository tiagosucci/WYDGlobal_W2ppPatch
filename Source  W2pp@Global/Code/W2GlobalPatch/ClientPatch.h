#pragma once
 
class ClientPatch : public Singleton<ClientPatch>
{
public:
    bool Initialize();

	static char* SetLoadConstume(int a2, char* a3, char* a4);

private:
    HookMgr *Hook() {
        static auto &hook = Singleton<HookMgr>::instance();
        return &hook;
    }
     
    void SSendPacket(MSG_STANDARD* pMsg, int _Size);
	 
    void SendServerMessage(MSG_STANDARD* pMsg, int hSize);
    

    //Controle de Send
   static void CSendpacket(MSG_STANDARD* pMsg, int size);
protected:
    friend class Singleton<ClientPatch>;
    ClientPatch() {}
    virtual ~ClientPatch() {}
    ClientPatch(const ClientPatch&) = delete;
    ClientPatch& operator=(const ClientPatch&) = delete;
    
};

