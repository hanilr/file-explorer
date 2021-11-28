// FILE FILE (MAIN) //

// STANDARD LIBRARY //
#include <iostream>
#include <fstream>
#include <string.h>

// DIY LIBRARY //
#include "header/file.hpp"
#include "header/util.hpp"

void create_file(std::string file_name)
{
    std::ofstream cfile(file_name); // CREATE FILE
    cfile.close();
}

int delete_file(char file_name[128]) { remove(file_name); }

void write_file(std::string file_name, std::string file_str)
{
    std::ofstream wfile(file_name); // WRITE FILE
    wfile << file_str;
    wfile.close();
}

std::string read_file(std::string file_name)
{
    std::string ret_str; // RETURN STRING

    std::ifstream rfile(file_name); // READ FILE
    rfile >> ret_str;
    rfile.close();

    return ret_str;
}

// MADE BY @hanilr //