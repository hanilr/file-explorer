// UI FILE (MAIN) //

// STANDARD LIBRARY //
#include <iostream>
#include <cstdlib>

// CROSS PLATFORM LIBRARY //
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/ioctl.h>
#endif

// DIY LIBRARY //
#include "header/ui.hpp"
#include "header/util.hpp"

void clrscr(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void nline(int times) { for(; times>0; times-=1) { std::cout << std::endl; }}

void repeater(std::string str, int times) { for(; times>0; times-=1) { std::cout << str;} }

void centerer(std::string str, int term_width)
{
    int temp_int, temp_str, len_str;

    if(term_width%2 == 0) { temp_int = term_width/2; }
    else { temp_int = (term_width+1)/2; }

    temp_str = str.length();
    if(temp_str%2 == 0) { len_str = temp_str/2; }
    else { len_str = (temp_str+1)/2; }

    repeater(" ", temp_int-len_str);
    std::cout << str;
} // REQUIRED NEW LINE BEFORE AND AFTER USE

void mscr(std::string cdir, int term_width)
{
    clrscr();
    std::cout << cdir;
    nline(1);
    repeater("-", term_width);
    list_file();
}

void guide(int term_width)
{
    nline(1);
    repeater("-", term_width);
    nline(1);
    centerer(guide_text, term_width);
    nline(1);
    repeater("-", term_width);
    nline(1);
}

void cl_ui(void)
{
    nline(1);
    std::cout << " |> ";
} // NO NEED NEW LINE BEFORE USE

// MADE BY @hanilr //