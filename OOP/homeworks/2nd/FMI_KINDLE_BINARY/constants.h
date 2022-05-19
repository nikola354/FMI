//
// Created by nikola354 on 30.04.22.
//

#ifndef FMI_KINDLE_CONSTANTS_H
#define FMI_KINDLE_CONSTANTS_H

//FILE_NAMES
const char KINDLE_FILE[] = "kindle.dat";

//sizes:
const short FILE_BUFFER_SIZE = 100;
const short CONSOLE_BUFFER_SIZE = 100;
const short LINE_BUFFER_SIZE = 1024;
const short MAX_NAME_LENGTH = 25;
const short MIN_NAME_LENGTH = 3;
const short MAX_PASS_LENGTH = 40;
const short MIN_PASS_LENGTH = 6;
const short MIN_RATE = 0;
const short MAX_RATE = 10;

//COMMANDS:
const char LOGIN_CMD[] = "login";
const char SIGNUP_CMD[] = "signup";
const char VIEW_CMD[] = "view";
const char READ_CMD[] = "read";
const char RATE_CMD[] = "rate";
const char COMMENT_CMD[] = "comment";
const char WRITE_CMD[] = "write";
const char QUIT_CMD[] = ":quit";
const char LOGOUT_CMD[] = "logout";
const char Q_CMD[] = "q";
const char NEXT_CMD[] = "n";
const char PREV_CMD[] = "p";
const char EDIT_CMD[] = "edit";
const char VIEW_RATES_CMD[] = "rates";
const char VIEW_COMMENTS_CMD[] = "comments";


//symbols
const char TERMINATE_SYMBOL = '\0';
const char TAB = '\t';

#endif //FMI_KINDLE_CONSTANTS_H
