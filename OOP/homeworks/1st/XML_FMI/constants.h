#ifndef INC_2_CONSTANTS_H
#define INC_2_CONSTANTS_H

//symbols:
const char TERMINATE_SYMBOL = '\0';
const char OPENING_SYMBOL = '<';
const char CLOSING_SYMBOL = '>';
const char DECIMAL_SIGN = '.';
const char BACKSLASH = '\\';
const char TAB[] = "    ";

const int DIFFERENCE_LOWER_UPPER = 'a' - 'A';

//sizes:
const int MAX_FILENAME_LENGTH = 100;
const int CONSOLE_BUFFER_SIZE = 200;
const int FILE_BUFFER_SIZE = 1000;
const int MAX_TAG_LENGTH = 25;
const int MAX_VALUE_LENGTH = 100;
const int BUFFER_SIZE_CONSOLE = 100;

//parameters:
const int MIN_AGE = 15;
const int MAX_AGE = 65;
const int MAX_NAME_LENGTH = 40;
const int MAX_EMAIL_LENGTH = 100;
const int MIN_GRADE = 2;
const int MAX_GRADE = 6;


//tags:
const char STUDENT_TAG[] = "student";
const char NAME_TAG[] = "name";
const char FN_TAG[] = "fn";
const char AGE_TAG[] = "age";
const char GENDER_TAG[] = "gender";
const char EMAIL_TAG[] = "email";
const char GRADE_TAG[] = "grade";
const int TAGS_NUMBER = 6;
const char MALE[] = "male";
const char FEMALE[] = "female";


//commands:
const char SAVE_CMD[] = "save";
const char VIEW_CMD[] = "view";
const char EDIT_CMD[] = "edit";
const char SORT_CMD[] = "sort";

#endif
