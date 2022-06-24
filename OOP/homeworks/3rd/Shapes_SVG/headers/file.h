//
// Created by nikola354 on 27.05.22.
//

#ifndef SVG_FILES_FILE_H
#define SVG_FILES_FILE_H

#include "String.h"

const char FILE_PREFIX[] = "<?xml version=\"1.0\" standalone=\"no\"?>\n"
                           "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n"
                           " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">";

bool checkFile(const String &filename);

String fileToString(const String &filename);

#endif //SVG_FILES_FILE_H
