// UTILITY FILE (LINK) //

void cd_(void); // GOTO PARENT DIRECTORY

void _cd(char path[128]); // GOTO SPECIFIC DIRECTORY

int dkey(void); // DETECT KEY

int tpause(int term_width); // TERMINAL PAUSE

std::string current_dir(void); // RETURN CURRENT DIRECTORY PATH

void list_file(void); // LIST FILES FROM CURRENT DIRECTORY

int gtw(void); // GET TERMINAL WIDTH

int cl_com(std::string cl_command, int term_width); // COMMAND LINE COMMAND
/* gtw, dkey */

// MADE BY @hanilr //