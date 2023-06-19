#include "Card.h"

/* Operator << of Card class.
 * @param std::ostream& - reference to ostream object.
 * @return a new instance of ostream. */
std::ostream& operator<<(std::ostream& os, const Card& card){
    return card.printInfo(os);
}
