#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;

#include<iomanip>
using std::setw;

#include<cstdlib>
using std::srand;
using std::rand;

#include<ctime>
using std::time;

#include"shuffle_cards.h"

DeckOfCards::DeckOfCards()
{
  nextNum = 1;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      deck[i][j] = 0; // nullify deck 
    }
  }
  srand(time(0)); // seeds random number genetator
  for(int i = 0; i < numOfPlayers; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      playerCards[i][j] = 0; // nullify player cards
    } 
  } 
}

void DeckOfCards::shuffleCards()
{
  int i,j;
  for(int count = 1; count <= 52; count++)
  {
    do
    {
      i = rand() % 4;
      j = rand() % 13;
    }while(deck[i][j] != 0);
    deck[i][j] = count;
    deckStack[count - 1] = &deck[i][j];
//    printCardName(i,j);
  }
}

void DeckOfCards::dealAll()
{
  
  for(int count = 1;count <= 52; count++)
  {
    for(int i = 0 ; i < 4; i++)
    {
      for(int j = 0; j < 13; j++)
	if(deck[i][j] == count)
	{
	  printCardName(i,j);
	  if(count%2 ==0)
	  {
	    cout<<endl;
	  }
	  else
	  {
	    cout<<"\t";
	  }
	}
    }
    
  }
  cout << endl;
}

int DeckOfCards::findNextCard(int *suit, int *face)
{
  for(int i = 0 ; i < 4; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      if(deck[i][j] == nextNum)
      {
	*suit = i;
	*face = j;
        return 0;
      }
    }    
  }
  return 1;      
}

void DeckOfCards::dealForTwo(int numOfCards) // give 5 cards for each player
{
  int i, j;
  for(int count = 1; count <= numOfCards * 2; count++)
  {
    if(0 == takeNCards(count % 2 + 1, 1))
    {
      break; // the deck is empty
    }
  }
}

int DeckOfCards::takeNCards(int player, int cardsNumber)
{
  int count = 0;
  int i, j; // i- suit,, j- face
  while(cardsNumber-- >= 1 && playerCards[player][12] <= maxCards)
  {
    cout << "player  "<< player <<" takes "<< count + 1 << endl;

    if( 0 == findNextCard(&i, &j) )
    {  // card found
      cout<< "card found:" << i<<","<<j<<endl;
      deck[i][j] = -player;
      playerCards[player][playerCards[player][12] * 2] = i;
      playerCards[player][playerCards[player][12] * 2 + 1] = j;
      
      playerCards[player][12]++;
      
      nextNum++;
      count++;
    }
    else
    { // no more cards
      break;
    }
  }
  return count;
}
int DeckOfCards::checkSuit(int player)
{
/*   4  Стрит. 5 последовательных карт. Масти могут быть разные. Туз может быть как начинающей картой (туз, 2, 3, 4, 5), так и заканчиающей (10, валет, дама, король, туз)
     5  Флеш. 5 карт одной масти.
     8  Флеш стрит. 5 последовательных карт одной масти
     9  И самая сильная Флеш рояль. 10, валет, дама, король, туз одной масти.
*/
  int count = 0;

  //ckeck for Royal Flash
  for(int i = 0; i < 4;i++)
  { 
    for(int j = 8; j < 13 && deck[i][j] == -player; j++)
    {
	count++;
    }
    if(count == 5)
    {
      return 9;      
    }
    count = 0;
  }
  //check for Street Flash
  for(int i = 0; i < 4;i++)
  { 
    for(int j = 0; j < 13; j++)
    {
      (deck[i][j] == -player)? count++ : count = 0;
    }
    if(count == 5)
    {
      return 8;      
    }
    count = 0;
  }
  
  //check for Flash
  for(int i = 0; i < 4;i++)
  { 
    for(int j = 0; j < 13 ; j++)
    {
      if(deck[i][j] == -player)
	count++;
    }
    if(count == 5)
    {
      return 5;      
    }
    count = 0;
  }
  // check for Street
  for(int j = 0; j < 13 && count < 5; j++)
  {
    int flag = 0;
    for(int i = 0; i < 4;i++)
    {
      if(deck[i][j] == -player)
      {
	flag = 1;
	break;
      }
    }
    (flag == 1) ? count++ : count = 0;
  }
  if(5 == count )
  {
    return 4;
  }
  return 0;
}

int DeckOfCards::checkFace(int player)
{
  /*
   0 Старшая карта. В случае, если никто из игроков ничего не собрал, смотрится старшая карта у оппонентов
   1  Пара. Две карты одного достоинства.
   2  Две пары
   3  Тройка/триплет/сет. Три карты одного достоинства.
   6  Фулл хаус. Тройка и пара. Например 22233.
   7  Каре. Четыре карты одного достоинства.
   */
  int count = 0;
  int flag2 = 0;
  int flag3 = 0;
  int flag4 = 0;
  
  for (int j = 0; j < 13 ; j++)
  {
    int flag = 0;
    for(int i = 0; i < 4 ; i++)
    {
      if(deck[i][j] == -player)
      {
	flag++;
      }
    }
    switch(flag)
    {
      case 0:
        break;
      case 1:
        flag = 0;
        break;
      case 2:
        flag2++;
        if(flag2 == 2)
        {
          return 2;
        }
        flag = 0;
        break;
      case 3:
        flag3++;
        if(flag2 == 1 && flag3 == 1)
        {
          return 6;
        }
        flag = 0;
        break;
      case 4:
        return 7;
      break;
    }
  }
  if(flag3 == 1)
  {
    return 3;
  }
  if(flag2 == 1)
  {
    return 1;
  }
  return 0;
}

void DeckOfCards::printCardName(const int i, const int j)
{
  static const char *suit[4] = {"Hearts","Diamonds","Clubs","Spades"};
  static const char *face[13] = {"Ace","Deuce","Three","Four","Five","Six","Seven",
  "Eight","Nine","Ten","Jack","Queen","King"};
  
  cout <<setw(8)<<right<<face[j]<<" of "<< setw(5)<<left<< suit[i];
  
}

int DeckOfCards::game()
{
  int result1;
  int result2;
  cout << "Game Started ... " << endl;
  shuffleCards();
  cout << "Cards shuffled ... " << endl;
  dealForTwo(5);
  cout << "GDeal for two is done ... " << endl;

  result1 = checkFace(1);
  cout << "Check face 1 finished ... " << endl;
  if(result1 < checkSuit(1))
  {
    result1 = checkSuit(1);
  }

  result2 = checkFace(2);
  if(result2 < checkSuit(2))
  {
    result2 = checkSuit(2);
  }
  cout << "Player 1: "<< result1 << endl;
  cout << "Player 2: "<< result2 << endl;
  if(result1 > result2)
  {
    cout << "Player 1 wins! \n";
  }
  if(result1 < result2)
  {
    cout << "Player 2 wins! \n";
  }
  if(result1 == result2)
  {
    cout << "Nobody wins! \n";
  }
  cout << "Game finished! "<< endl;
  return 1;
}
/*void DeckOfCards::deal()
{
  
  for(int count = 1;count <= 52; count++)
  {
    for(int i = 0 ; i < 4; i++)
    {
      for(int j = 0; j < 13; j++)
	if(deck[i][j] == count)
	{
	  printCardName(i,j);
	  if(count%2 ==0)
	  {
	    cout<<endl;
	  }
	  else
	  {
	    cout<<"\t";
	  }
	}
    }
    
  }
  cout << endl;
}
*/