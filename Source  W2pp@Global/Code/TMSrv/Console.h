#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <locale.h>

inline void CreateConsole(char* Titulo)
{
    //Fixed bug printf vs 15 - 17
    //By seitbnao
    char Temp[256];
    AllocConsole();
    sprintf(Temp, "%s", Titulo);
#ifdef _DEBUG
    sprintf(Temp, "[DEBUG] - %s", Titulo);
#endif // _DEBUG

#ifdef __RELEASE
    sprintf(Temp, "[RELEASE] - %s", Titulo);
#endif // __RELEASE

    SetConsoleTitleA(Temp);
    typedef struct
    {
        char* _ptr;
        int _cnt;
        char* _base;
        int _flag;
        int _file;
        int _charbuf;
        int _bufsiz;
        char* _tmpfname;
    } FILE_COMPLETE;
    *(FILE_COMPLETE*)stdout = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w");
    *(FILE_COMPLETE*)stderr = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_ERROR_HANDLE), _O_TEXT), "w");
    *(FILE_COMPLETE*)stdin = *(FILE_COMPLETE*)_fdopen(_open_osfhandle((long)GetStdHandle(STD_INPUT_HANDLE), _O_TEXT), "r");
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setlocale(LC_ALL, "Portuguese");
}
