// UI FILE (LINK) //

// DEFINES
#define guide_text "| 'Q' - QUIT | '/' - COMMAND LINE | 'C' - CREATE FILE | 'D' - DELETE FILE | 'W' - WRITE INTO FILE | 'R' - READ FILE | '[' - GOTO PARENT DIRECTORY | ']' - GOTO SPECIFIC DIRECTORY |"

// FUNCTIONS

void clrscr(void); // CLEAR SCREEN

void nline(int times); // NEW LINE WITH TIMES

void repeater(std::string str, int times); // REPEATER A CERTAIN STRING

void centerer(std::string str, int term_width); // PUT THE STRING IN MIDDLE OF THE TERMINAL

void mscr(std::string cdir, int term_width); // MAIN SCREEN

void guide(int term_width); // MESSAGE SCRREN

void cl_ui(void); // COMMAND LINE USER INTERFACE

// MADE BY @hanilr //