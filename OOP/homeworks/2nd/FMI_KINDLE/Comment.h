//
// Created by nikola354 on 30.04.22.
//

#ifndef FMI_KINDLE_COMMENT_H
#define FMI_KINDLE_COMMENT_H

#include <cstring>

#include "constants.h"
#include "String.h"

class Comment {
private:
    String text;
    String author;

public:
    Comment() = default;

    Comment(const Comment &other);

    Comment &operator=(const Comment &other);

    ~Comment();

    Comment(const String &text, const String &author);

private:
    void free();

    void copyFrom(const Comment &other);

public:
    String getText() const;

    String getAuthor() const;

    void print(bool isBookAuthor) const;
};


#endif //FMI_KINDLE_COMMENT_H
