#include "stackpile.h"
#include "squaredPile.h"

class foundationPile : public stackPile, public squaredPile
{
public:
	foundationPile(sf::Vector2i = sf::Vector2i(0,0));
	bool canAppend(const pile&);
	bool canSplit(unsigned int);
	~foundationPile(void);
};
