#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>
#define SIMULATIONS 100
using namespace std;
// Helped by tutor: Pablo Cesar Bedolla Ortiz

void Shuffle(vector<int> &deck);
void Deal(vector<int> &deck, vector<int> &hand);
int sumHands(vector<int> &hand);
void Deck(vector<int> &deck);
void showDeck(vector<int> &deck);

int main() 
{

  // STARTS

  int playerScore = 0;
  int dealerScore = 0;

  int dealerSum = 0; //Sum of the player cards to compare who has the highest score
  int playerSum = 0;

  std::vector<int> deck;
  std::vector<int> dealerHand;
  std::vector<int> playerHand;
  //Seed
  srand(time(NULL));

  //Loop to simulate 100 rounds of BlackJack
  for (int i = 0; i < SIMULATIONS; i++) 
  {

    Deck(deck);    // Creation of the deck
    Shuffle(deck); // Shuffling of the cards
    Deal(deck, dealerHand);//Players starr with two cards
    Deal(deck, dealerHand);
    Deal(deck, playerHand);
    Deal(deck, playerHand);

    showDeck(dealerHand);
    showDeck(playerHand);

    cout << "---------" << endl;

    // PLAYER AI CODE to tell when to deal, or stop dealing a card
    if (sumHands(playerHand) < 16) 
    {
      cout << "Deal a card" << endl;
      Deal(deck, playerHand);

    } else if (sumHands(playerHand) > 16) 
    {
      cout << "Stopped Dealing cards" << endl;

      cout << playerSum << endl;
    }

    // DEALER AI CODE to tell when to deal, or stop dealing a card
    if (sumHands(dealerHand) < 16) 
    {
      cout << "Deal a card" << endl;
      Deal(deck, dealerHand);
    } else if (sumHands(dealerHand) > 16) 
    {
      cout << "Stopped Dealing cards" << endl;
      cout << dealerSum << endl;
    }

    showDeck(playerHand);
    showDeck(dealerHand);

    cout << "---------" << endl;

    playerSum = sumHands(playerHand);
    dealerSum = sumHands(dealerHand);

    cout << playerSum << endl;
    cout << dealerSum << endl;

    cout << "---------" << endl;

    // SUM EM UP
    // determines who busts, or win the round

    // ERROR ---
    if (playerSum > 21) 
    {
      cout << "You Bust, Dealer wins this round" << endl;
      dealerScore++;

    } else if (playerSum == 21) 
    {
      cout << "Player Wins this round" << endl;
      playerScore++;

    } else if (dealerSum > 21) 
    {
      cout << "You Bust, Player wins this round" << endl;
      playerScore++;

    } else if (dealerSum == 21) 
    {
      cout << "Player Wins this round" << endl;
      dealerScore++;

    } else if (playerSum > dealerSum) 
    {
      cout << "Player Wins this round" << endl;
      playerScore++;

    } else if (dealerSum < playerSum) 
    {
      cout << "Dealer Wins this round" << endl;
      dealerScore++;
    
    } else 
    {
      cout << "Draw!" << endl;
      cout << "No points awarded to either person" << endl;
    }
    //resets the cards given to the players and also the deck
    deck.clear();
    dealerHand.clear();
    playerHand.clear();

    // ENDS
  }

    //Decides who wins by comparing who has the highest score if they didnt bust
  if (playerScore > dealerScore) 
  {
    cout << "Player WON: " << playerScore << endl;
  } else 
  {
    cout << "DEALER WON: " << dealerScore << endl;
  }
}

void showDeck(vector<int> &deck) 
{
  for (int i = 0; i < deck.size(); i++) 
  {
    std::cout << deck[i] << " ";
  }
  cout << "\n" << endl;
}
//Creates the deck 
void Deck(vector<int> &deck) 
{
  for (int i = 0; i < 4; i++) 
  {
    for (int c = 1; c < 14; c++) 
    {
      if (c > 9) 
      {
        deck.push_back(10);
      }

      if (c <= 9) 
      {
        deck.push_back(c);
      }
    }
  }
}
//Shuffles the deck of cards
void Shuffle(vector<int> &deck) 
{

  std::random_shuffle(deck.begin(), deck.end());
}
//Gives a card to someone from the deck vector
void Deal(vector<int> &deck, vector<int> &hand) 
{
  hand.push_back(deck.back());
  deck.pop_back();
}
//Method to sum a hand vector
int sumHands(vector<int> &hand) 
{

  return accumulate(hand.begin(), hand.end(), 0);
}
