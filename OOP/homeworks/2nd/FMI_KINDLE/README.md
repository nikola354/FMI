explanation of files architecture:

users.csv structure:

usersCount|
id|name|password|booksCount|readBooksId[0]|readBooksId[1]|...|readBooksId[booksCount - 1]

books.csv structure:

booksCount|
id|title|author|pagesCount|commentsCount|comments[0].author|comments[0].value|...|ratesCount|rates[0].author|rates[0].value