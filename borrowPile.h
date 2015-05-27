#pragma once
#include "stackPile.h"
#include "fannedPile.h"
#include "stockPile.h"


class borrowPile : public stackPile, public fannedPile
{
public:
	borrowPile(sf::Vector2i = sf::Vector2i(0, 0), sf::Vector2f = sf::Vector2f(30.0, 15.0));
	bool canSplit(unsigned int);
	void addToStock(stockPile&);
	void sendAllToWaste();
	bool canAppend(const pile&);
	~borrowPile(void);
private:
	stockPile waste;
};

