#include "Exception.h"

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