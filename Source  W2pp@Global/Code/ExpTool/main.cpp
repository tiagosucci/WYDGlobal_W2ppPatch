#include "main.h"

 

struct STRUCT_SCORE_W2PP
{
	int Level;	 // The mob's level
	int Ac;		 // The mob's defense
	int Damage;   // The mob's damage force

	unsigned char  Merchant; // UNK
	unsigned char  AttackRun; // The mob's speed
	unsigned char  Direction;
	unsigned char  ChaosRate;

	int MaxHp;     // The max HP the mob can have
	int MaxMp;	  // The max MP the mob can have
	int Hp;		  // The current HP of the mob
	int Mp;		  // The current MP of the mob

	short		   Str;		  // The mob's strength points, affects it's attack power
	short		   Int;		  // The mob's intelligence points, affects it's skill attack powers and MP
	short		   Dex;		  // The mob's dexterity points, affects it's attack speed
	short		   Con;       // The mob's constitution points, affects it's HP

	short  Special[4]; // The mob's special points, affects it's skill tiers
};

struct STRUCT_MOB_W2PP
{
	char		   MobName[NAME_LENGTH];	  // The name of the mob
	char		   Clan;		  // The clan the mob belongs to
	unsigned char  Merchant;	  // The mob's merchant ID
	unsigned short Guild;		  // The ID of the guild the mob belongs to
	unsigned char  Class;		  // The mobs class
	unsigned short  Rsv;
	unsigned char Quest;

	int			   Coin;		  // The ammount of coins the mob has

	long long   Exp;			  // The ammount of experience the mob has to level up

	short		   SPX;			 // The Y position saved by the stellar gem, to teleport the mob there when using warp scroll
	short		   SPY;			 // The Y position saved by the stellar gem, to teleport the mob there when using warp scroll

	STRUCT_SCORE_W2PP   BaseScore;    // The base score of the mob 
	STRUCT_SCORE_W2PP   CurrentScore; // The score the mob actually has

	STRUCT_ITEM    Equip[16];	 // The items the mob is wearing
	STRUCT_ITEM	   Carry[MAX_CARRY];	 // The items the mob is carrying

	long LearnedSkill; // The skills the mob learned, divided into four categories (00 _ 00 _ 00 _ 00)

	unsigned int Magic;

	unsigned short ScoreBonus;   // The points the mob can use to increase score (Str, Int, Dex, Con)
	unsigned short SpecialBonus; // The points the mob can use to increase special, to increase effect of learned skills (score->Special[4])
	unsigned short SkillBonus;	 // The points the mob can use to buy skills

	unsigned char  Critical;	 // The chance the mob has to deliver critical hits
	unsigned char  SaveMana;	 // Uknown use, nomenclature of variable is correct to all current standards

	unsigned char  SkillBar[4];  // The skills saved on the first 4 slots of the skill bar

	unsigned char  GuildLevel;   // The mob's guuld level, used to define if it's a guild member or leader

	unsigned short  RegenHP;		 // UNK
	unsigned short  RegenMP;		 // UNK

	char  Resist[4];	 // The mob's resistencies, to fire / ice / thunder / magic
 
};

struct STRUCT_SCORE_763
{
	int Level;     // The mob's level
	int Ac;         // The mob's defense
	int Damage;   // The mob's damage force

	union
	{
		unsigned char Merchant; // UNK

		struct
		{
			unsigned char Type : 4;
			unsigned char Direction : 4;
		};
	};

	union
	{
		unsigned char  AttackRun; // The mob's speed

		struct
		{
			unsigned char Speed : 4;
			unsigned char Attack : 4;
		};
	};

	unsigned char  RegenHP;
	unsigned char  RegenMP;

	int MaxHp;     // The max HP the mob can have
	int MaxMp;      // The max MP the mob can have
	int Hp;          // The current HP of the mob
	int Mp;          // The current MP of the mob

	unsigned short           Str;          // The mob's strength points, affects it's attack power
	unsigned short           Int;          // The mob's intelligence points, affects it's skill attack powers and MP
	unsigned short           Dex;          // The mob's dexterity points, affects it's attack speed
	unsigned short           Con;       // The mob's constitution points, affects it's HP

	unsigned short  Special[4]; // The mob's special points, affects it's skill tiers
};

struct STRUCT_MOB_763
{
	union
	{
		char MobName[16];
		struct
		{
			char PlayerName[12];
			BYTE ChaosPoints;
			BYTE CurrentKill;
			short TotalKill;
		};
	};

	char Clan;

	union
	{
		unsigned char Merchant;
		struct
		{
			unsigned char Merchant : 6;
			unsigned char CityID : 2;
		} Info;
	};

	unsigned short Guild;
	unsigned char  Class;
	unsigned short  Rsv;
	unsigned char Quest;

	int			   Coin;

	union
	{
		long long       Exp;
		struct
		{
			int cExp;
			int tExp;
		};
	};// The ammount of experience the mob has to level up

	short		   SPX;			 // The Y position saved by the stellar gem, to teleport the mob there when using warp scroll
	short		   SPY;			 // The Y position saved by the stellar gem, to teleport the mob there when using warp scroll

	STRUCT_SCORE_763   BaseScore;    // The base score of the mob 
	STRUCT_SCORE_763   CurrentScore; // The score the mob actually has

	STRUCT_ITEM    Equip[18];	 // The items the mob is wearing
	STRUCT_ITEM	   Carry[MAX_CARRY];	 // The items the mob is carrying

	long LearnedSkill; // The skills the mob learned, divided into four categories (00 _ 00 _ 00 _ 00)
	long nLearnedSkill; // The new skills the mob learned, divided into four categories (00 _ 00 _ 00 _ 00)

	unsigned short ScoreBonus;   // The points the mob can use to increase score (Str, Int, Dex, Con)
	unsigned short SpecialBonus; // The points the mob can use to increase special, to increase effect of learned skills (score->Special[4])
	unsigned short SkillBonus;	 // The points the mob can use to buy skills

	unsigned char  Critical;	 // The chance the mob has to deliver critical hits
	unsigned char  SaveMana;	 // Uknown use, nomenclature of variable is correct to all current standards

	char  SkillBar[4];  // The skills saved on the first 4 slots of the skill bar

	unsigned char  GuildLevel;   // The mob's guuld level, used to define if it's a guild member or leader


	unsigned char  UNK_1;

	unsigned char  RegenHP;		 // UNK
	unsigned char  RegenMP;		 // UNK

	char UNK_2[206];

	union
	{
		unsigned short  Resist[4];	 // The mob's resistencies, to fire / ice / thunder / magic
		struct
		{
			unsigned short Fogo;
			unsigned short Gelo;
			unsigned short Sagrado;
			unsigned short Trovao;
		} Resistencia;//[4]
	};

	unsigned short Magic;
	unsigned short RegenBonus;
	char UNK_3[2];


};
 

char*  StringFormat(const char* str, ...)
{
	static char buffer[2048] = { 0, };
	va_list va;
	va_start(va, str);
	vsprintf_s(buffer, str, va);
	va_end(va);
	return buffer;
}

void ReadMobInDir( char* fileName)
{
	 
	
	STRUCT_MOB_W2PP mob = STRUCT_MOB_W2PP();

	FILE* fp;
	fp = fopen(StringFormat("./npc/%s", fileName), "rb");
	int tsum;
	if (fp == NULL)
	{
		 
		return;
	}
	fread((char*)&mob, sizeof(STRUCT_MOB_W2PP), 1, fp);
	fclose(fp);



	STRUCT_MOB_763  MobToSave =   STRUCT_MOB_763();

	
	printf(StringFormat("./npc/%s\n", mob.MobName));
 

	//MOBNAME
	strcpy(MobToSave.MobName, mob.MobName);
	//OTHERINFOS
	MobToSave.Clan = mob.Clan;
	MobToSave.Merchant = mob.Merchant;
	MobToSave.Guild = mob.Guild;
	MobToSave.Class = mob.Class;
	MobToSave.Rsv = mob.Rsv;
	MobToSave.Quest = mob.Quest;
	MobToSave.Coin = mob.Coin;
	MobToSave.Exp = mob.Exp;
	MobToSave.SPX = mob.SPX;			 // The Y position saved by the stellar gem, to teleport the mob there when using warp scroll
	MobToSave.SPY = mob.SPY;		 // The Y position saved by the stellar gem, to teleport the mob there when using warp scroll

	MobToSave.LearnedSkill = mob.LearnedSkill;// The skills the mob learned, divided into four categories (00 _ 00 _ 00 _ 00)
	MobToSave.nLearnedSkill = 0; // The new skills the mob learned, divided into four categories (00 _ 00 _ 00 _ 00)

	MobToSave.ScoreBonus = mob.ScoreBonus;   // The points the mob can use to increase score (Str, Int, Dex, Con)
	MobToSave.SpecialBonus = mob.SpecialBonus; // The points the mob can use to increase special, to increase effect of learned skills (score->Special[4])
	MobToSave.SkillBonus = mob.SkillBonus;	 // The points the mob can use to buy skills

	MobToSave.Critical = mob.Critical;	 // The chance the mob has to deliver critical hits
	MobToSave.SaveMana = mob.SaveMana;	 // Uknown use, nomenclature of variable is correct to all current standards

	  // The skills saved on the first 4 slots of the skill bar

	MobToSave.GuildLevel = mob.GuildLevel;   // The mob's guuld level, used to define if it's a guild member or leader


	MobToSave.UNK_1 = 0;

	MobToSave.RegenHP = mob.RegenHP;		 // UNK
	MobToSave.RegenMP = mob.RegenMP;		 // UNK


	//BASESCORE
	MobToSave.BaseScore.Level = mob.BaseScore.Level;    // The mob's level
	MobToSave.BaseScore.Ac = mob.BaseScore.Ac;     // The mob's defense
	MobToSave.BaseScore.Damage = mob.BaseScore.Damage;  // The mob's damage force
	MobToSave.BaseScore.Merchant = mob.BaseScore.Merchant; // UNK
	MobToSave.BaseScore.AttackRun = mob.BaseScore.AttackRun;// The mob's speed
	MobToSave.BaseScore.RegenHP = 0;
	MobToSave.BaseScore.RegenMP = 0;
	MobToSave.BaseScore.MaxHp = mob.BaseScore.MaxHp;    // The max HP the mob can have
	MobToSave.BaseScore.MaxMp = mob.BaseScore.MaxMp;     // The max MP the mob can have
	MobToSave.BaseScore.Hp = mob.BaseScore.Hp;    // The current HP of the mob
	MobToSave.BaseScore.Mp = mob.BaseScore.Mp;       // The current MP of the mob
	MobToSave.BaseScore.Str = mob.BaseScore.Str;     // The mob's strength points, affects it's attack power
	MobToSave.BaseScore.Int = mob.BaseScore.Int;        // The mob's intelligence points, affects it's skill attack powers and MP
	MobToSave.BaseScore.Dex = mob.BaseScore.Dex;      // The mob's dexterity points, affects it's attack speed
	MobToSave.BaseScore.Con = mob.BaseScore.Con;   // The mob's constitution points, affects it's HP
	for (int i = 0; i < 4; i++)
		MobToSave.BaseScore.Special[i] = mob.BaseScore.Special[i]; // The mob's special points, affects it's skill tiers
	//CURENT SCORE
	MobToSave.CurrentScore.Level = mob.CurrentScore.Level;    // The mob's level
	MobToSave.CurrentScore.Ac = mob.CurrentScore.Ac;     // The mob's defense
	MobToSave.CurrentScore.Damage = mob.CurrentScore.Damage;  // The mob's damage force
	MobToSave.CurrentScore.Merchant = mob.CurrentScore.Merchant; // UNK
	MobToSave.CurrentScore.AttackRun = mob.CurrentScore.AttackRun;// The mob's speed
	MobToSave.CurrentScore.RegenHP = 0;
	MobToSave.CurrentScore.RegenMP = 0;
	MobToSave.CurrentScore.MaxHp = mob.CurrentScore.MaxHp;    // The max HP the mob can have
	MobToSave.CurrentScore.MaxMp = mob.CurrentScore.MaxMp;     // The max MP the mob can have
	MobToSave.CurrentScore.Hp = mob.CurrentScore.Hp;    // The current HP of the mob
	MobToSave.CurrentScore.Mp = mob.CurrentScore.Mp;       // The current MP of the mob
	MobToSave.CurrentScore.Str = mob.CurrentScore.Str;     // The mob's strength points, affects it's attack power
	MobToSave.CurrentScore.Int = mob.CurrentScore.Int;        // The mob's intelligence points, affects it's skill attack powers and MP
	MobToSave.CurrentScore.Dex = mob.CurrentScore.Dex;      // The mob's dexterity points, affects it's attack speed
	MobToSave.CurrentScore.Con = mob.CurrentScore.Con;   // The mob's constitution points, affects it's HP
	for (int i = 0; i < 4; i++)
	{
		MobToSave.CurrentScore.Special[i] = mob.CurrentScore.Special[i]; // The mob's special points, affects it's skill tiers
		MobToSave.SkillBar[i] = mob.SkillBar[i];
	}
	//EQUIPAMENTS
	for (int i = 0; i < 16; i++)
		MobToSave.Equip[i] = mob.Equip[i];
	//CARRY
	for (int i = 0; i < MAX_CARRY; i++)
		MobToSave.Carry[i] = mob.Carry[i];


	FILE* fs = nullptr;
	fopen_s(&fs, StringFormat("./convertidos/%s", fileName), "wb");
	if (fs == nullptr)
		return;



	fwrite((char*)&MobToSave, 1, sizeof(STRUCT_MOB_763), fs);
	fclose(fs);
	 
	 
}


void list_dir(const char* path) {
	struct dirent* entry;
	DIR* dir = opendir(path);

	if (dir == NULL) {
		return;
	}
	while ((entry = readdir(dir)) != NULL) {

		if (!strncmp(entry->d_name, ".", 1))
			continue;

		
		ReadMobInDir(entry->d_name);
	}
	closedir(dir);
}


int main()
{

	_wmkdir(L"./convertidos");
	list_dir("./npc/");

	return 1;
}