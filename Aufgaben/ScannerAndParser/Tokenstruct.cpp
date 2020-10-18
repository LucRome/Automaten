#include "Tokenstruct.h"

bool Token::operator==(const Token& b)
{
    return this->type == b.type;
}

bool Token::operator==(const Terminals& b)
{
    return this->type == b;
}
