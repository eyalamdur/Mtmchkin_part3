#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string.h>

class Exception : public std::exception {
public:
    /* C'tor of Exception class.
     * @return a new instance of Exception. */
    Exception() = default;
    Exception(std::string message);

    /* D'tor of Exception class. */
    ~Exception() = default;

    /* Copy of Exception class.
     * @param Exception& - reference to another Exception object.
     * @return a new instance of Exception with copied values as the given Exception. */
    Exception(const Exception&) = default;

    /* Assigning of Exception class.
     * @param Exception& - reference to another Exception object.
     * @return a new instance of Exception with copied values as the given Exception. */
    Exception& operator=(const Exception& other) = default;

private:
    std::exception m_type;
};

class DeckFileNotFound : public Exception{
public:
    /* C'tor of DeckFileNotFound class.
     * @return a new instance of DeckFileNotFound. */
    DeckFileNotFound() = default;

    /* D'tor of DeckFileNotFound class. */
    ~DeckFileNotFound() = default;
};

class DeckFileFormatError : public Exception{
public:
    /* C'tor of DeckFileFormatError class.
     * @return a new instance of DeckFileFormatError. */
    DeckFileFormatError(int line) : m_line(line){};

    /* D'tor of DeckFileFormatError class. */
    ~DeckFileFormatError() = default;

    private:
        int m_line;
};

class DeckFileInvalidSize : public Exception{
public:
    /* C'tor of DeckFileInvalidSize class.
     * @return a new instance of DeckFileInvalidSize. */
    DeckFileInvalidSize() = default;

    /* D'tor of DeckFileInvalidSize class. */
    ~DeckFileInvalidSize() = default;

};

class CardNotFound : public Exception{
public:
    /* C'tor of CardNotFound class.
     * @return a new instance of CardNotFound. */
    CardNotFound() = default;

    /* D'tor of CardNotFound class. */
    ~CardNotFound() = default;

};

class PlayerCreationFailure : public Exception{
public:
    /* C'tor of PlayerCreationFailure class.
     * @return a new instance of PlayerCreationFailure. */
    PlayerCreationFailure() = default;

    /* D'tor of PlayerCreationFailure class. */
    ~PlayerCreationFailure() = default;

};

#endif //EX4_EXCEPTION_H
