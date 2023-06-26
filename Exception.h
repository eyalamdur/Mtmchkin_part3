#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string.h>

using namespace std;

class Exception : public exception {
public:
    /* C'tor of Exception class.
     * @return a new instance of Exception. */
    Exception() = default;

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

};

class DeckFileNotFound : public Exception{
public:
    /* C'tor of DeckFileNotFound class.
     * @return a new instance of DeckFileNotFound. */
    DeckFileNotFound() = default;

    /* D'tor of DeckFileNotFound class. */
    ~DeckFileNotFound() = default;
    
    /* Returns string thats describes the error */
    const char * what() const noexcept override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public Exception{
public:
    /* C'tor of DeckFileFormatError class.
     * @return a new instance of DeckFileFormatError. */
    DeckFileFormatError(int line) : m_line(line){};

    /* D'tor of DeckFileFormatError class. */
    ~DeckFileFormatError() = default;

    /* Returns string thats describes the error */
    const char * what() const noexcept override{
        static string errorMessage;
        errorMessage = "Deck File Error: File format error in line " + to_string(this->m_line);
        return errorMessage.c_str();
    }

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

        /* Returns string thats describes the error */
    const char * what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }


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
