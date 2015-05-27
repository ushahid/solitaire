#pragma once
#include "squaredpile.h"

class borrowPile;

class stockPile : public squaredPile
{
public:
	stockPile(borrowPile*, sf::Vector2i = sf::Vector2i(0,0));
	bool canSplit(unsigned int);
	bool canAppend(const pile&);
	stickyPile * splitPile(const sf::Vector2i&);
	~stockPile(void);

private:
	borrowPile* bPile;
};

