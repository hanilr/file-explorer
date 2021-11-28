// UTILITY FILE (MAIN) //

// STANDARD LIBRARY //
#include <iostream>
#include <cstdlib>
#include <unistd.h>


// CROSS PLATFORM LIBRARY //
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>
#endif

// DIY LIBRARY //
#include "header/util.hpp"
#include "header/ui.hpp"

void cd_(void) { chdir(".."); }

void _cd(char path[128]) { chdir(path); }

int dkey(void)
{
    int key;

    #ifdef _WIN32
    key = _getch();
    #else
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &key, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    #endif

    return key;
}

int tpause(int term_width)
{
    nline(2);
    centerer("| ...PRESS ENTER TO CONTINUE... |", term_width);
    int check_enter = dkey();
}

std::string current_dir(void)
{
    char cdir[128];
    getcwd(cdir, 128);
    return cdir;
}

void list_file(void)
{
    #ifdef _WIN32
        system("dir /b");
    #else
        system("ls -la");
    #endif
}

int gtw(void)
{
    int rows;
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        rows = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        rows = w.ws_row;
    #endif
    return rows;
}

int cl_com(std::string cl_command, int term_width)
{
    if(cl_command == "q" || cl_command == "quit") { return 2; }

    if(cl_command == "gtw")
    {
        nline(1);
        std::cout << "Terminal Width: " << gtw();
        tpause(term_width);
        return 0;
    } // GET TERMINAL WIDTH

    if(cl_command == "dkey")
    {
        clrscr();
        nline(1);
        centerer("| DKEY-LOOP - '\' FOR BREAK THE LOOP", term_width);
        nline(1);
        repeater("-", term_width);
        nline(2);

        int key;
        while(1)
        {
            key = dkey();
            if(key == 92) { break; }
            else { std::cout << key << " "; }
        }
    } // DETECT KEY
} // RETURN '2' MEANS BREAK IN LOOP

// MADE BY @hanilr //