/* Description of DeckOfCards class*/

class DeckOfCards
{
public:
  DeckOfCards();
  void shuffleCards();
  void dealAll();
  void dealForTwo(int numOfCards);
  int takeNCards(int player, int cardsNumber);
  int game();
private:
  static const int numOfPlayers = 2;
  static const int maxCards = 5; // maximum number of cards per player.
  int deck[4][13]; // deck with numbers
  int *deckStack[52]; // stack of pointers cards in deck array
  int nextNum ;// number of next card in the deck
  int currS,currF; // current card
  int playerCards[numOfPlayers][13]; // even- suit, odd-face,playerCards[..][13] - number of cards

  void printCardName(const int i, const int j);
  int findNextCard(int *i, int *j);
  int checkFace(int player);
  int checkSuit(int player);
};