#pragma once

class card
{
public:
	enum cardSuit{SPADES, HEARTS, DIAMONDS, CLUBS};
	enum cardRank{ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, NONE};
	enum cardColor{RED, BLACK};
	card(cardRank, cardSuit);
	cardSuit getSuit() const;
	cardRank getRank() const;
	cardRank getDescendent();
	cardColor getColor();
	~card(void);

protected:
	cardSuit suit;
	cardRank rank;
};

