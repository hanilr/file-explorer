// MAIN FILE //

// STANDARD LIBRARY //
#include <iostream>

// DIY LIBRARY //
#include "header/util.hpp"
#include "header/file.hpp"
#include "header/ui.hpp"

int main()
{
    // INITIAL CLAIMING
    std::string cdir, com, tmp;
    char ccom[128];
    int term_width, key, ret;

    while(1)
    {
        term_width = gtw();
        cdir = current_dir();

        mscr(cdir, term_width);
        guide(term_width);

        // COMMAND STATEMENT //
        key = dkey();
        if(key == 113) { break; } // (Q - QUIT)

        else if(key == 47)
        {
            cl_ui();
            std::cin >> com;
            ret = cl_com(com, term_width);
            
            if(ret == 2) { break; }
        } // ('/' - COMMAND LINE)

        else if(key == 99)
        {
            mscr(cdir, term_width);
            nline(1);
            repeater("-", term_width);
            nline(1);
            std::cout << "WHAT WILL BE YOUR NEW FILE NAME: (IF FILE NAME WAS 'cancel' THEN THE FILE WON'T EXIST)";
            cl_ui();
            std::cin >> com;
            if(com != "cancel") { create_file(com); }
        }

        else if(key == 100)
        {
            mscr(cdir, term_width);
            nline(1);
            repeater("-", term_width);
            nline(1);
            std::cout << "WHAT IS YOUR FILE NAME: (IF FILE NAME WAS 'cancel' THEN THE FILE WON'T DELETE)";
            cl_ui();
            std::cin >> ccom;
            if(com != "cancel") { delete_file(ccom); }
        }

        else if(key == 119)
        {
            mscr(cdir, term_width);
            nline(1);
            repeater("-", term_width);
            nline(1);
            std::cout << "WHAT IS YOUR FILE NAME: (IF FILE NAME WAS 'cancel' THEN THE FILE WON'T WRITE)";
            cl_ui();
            std::cin >> com;

            if(com != "cancel")
            {
                nline(2);
                std::cout << "WHAT DO YOU WANT TO WRITE:";
                nline(1);
                std::cin >> tmp;
                write_file(com, tmp);
            }
        }

        else if(key == 114)
        {
            mscr(cdir, term_width);
            nline(1);
            repeater("-", term_width);
            nline(1);
            std::cout << "WHAT IS YOUR FILE NAME: (IF FILE NAME WAS 'cancel' THEN THE FILE WON'T READ)";
            cl_ui();
            std::cin >> com;

            if(com != "cancel")
            {
                tmp = read_file(com);
                clrscr();
                std::cout << tmp;
                tpause(term_width);
            }
        }

        else if(key == 91) { cd_(); }

        else if(key == 93)
        {
            nline(1);
            std::cout << " |> cd ";
            std::cin >> ccom;
            _cd(ccom);
        }
        // ----------------- //
    }

    return 0;
}

// MADE BY @hanilr //
