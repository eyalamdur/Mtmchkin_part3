#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string.h>

class Exception : std::exception {
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

class DeckFileNotFound : Exception{
    /* C'tor of DeckFileNotFound class.
     * @return a new instance of DeckFileNotFound. */
    DeckFileNotFound();

    /* D'tor of DeckFileNotFound class. */
    ~DeckFileNotFound() = default;

    private:
        Exception m_exception;
};

class DeckFileFormatError : Exception{
    /* C'tor of DeckFileFormatError class.
     * @return a new instance of DeckFileFormatError. */
    DeckFileFormatError(int line);

    /* D'tor of DeckFileFormatError class. */
    ~DeckFileFormatError() = default;

    private:
        Exception m_exception;
};

class DeckFileInvalidSize : Exception{
    /* C'tor of DeckFileInvalidSize class.
     * @return a new instance of DeckFileInvalidSize. */
    DeckFileInvalidSize();

    /* D'tor of DeckFileInvalidSize class. */
    ~DeckFileInvalidSize() = default;

    private:
        Exception m_exception;
};

/*------------------------------Class Functions------------------------------*/

/* C'tor of Exception class.
 * @return a new instance of Exception. */
Exception::Exception(std::string message){
    this->m_type = std::runtime_error(message);
}

/* C'tor of DeckFileNotFound class.
 * @return a new instance of DeckFileNotFound. */
DeckFileNotFound::DeckFileNotFound(){
    this->m_exception = Exception("Deck File Error: File not found");
}

/* C'tor of DeckFileFormatError class.
 * @return a new instance of DeckFileFormatError. */
DeckFileFormatError::DeckFileFormatError(int line){
    char exceptionMessage[] = "Deck File Error: File format error in line ", *temp = nullptr;
    sprintf(temp, "%d", line);
    strcat(exceptionMessage, temp);
    this->m_exception = Exception(exceptionMessage);
}

/* C'tor of DeckFileInvalidSize class.
 * @return a new instance of DeckFileInvalidSize. */
DeckFileInvalidSize::DeckFileInvalidSize(){
    this->m_exception = Exception("Deck File Error: Deck size is invalid");
}

#endif //EX4_EXCEPTION_H