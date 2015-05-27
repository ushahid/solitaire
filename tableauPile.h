#pragma once
#include "fannedpile.h"

class tableauPile : public fannedPile
{
public:
	tableauPile(sf::Vector2i = sf::Vector2i(0, 0), sf::Vector2f = sf::Vector2f(30.0, 15.0));
	~tableauPile(void);
	bool canSplit(unsigned int);
	bool canAppend(const pile&);
};

