#ifndef H_deckOfcards
#define H_deckOfcards
#include"card.h"
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
const int cards_per_deck=52;
class deckOfcards{
private:
    card *deck;
    int currentcard;
public:
deckOfcards();
void shuffle();
card dealcard();
void printDeck() const;


};
void deckOfcards::printDeck() const
{
    cout<<left;
    for(int i=0;i<cards_per_deck;i++){
        cout<<setw(20)<<deck[i].print()<<setw(10)<<deck[i].values();
        if((i+1)%4 == 0)
            cout<<endl;
    }

}
deckOfcards::deckOfcards(){
string faces[]={"ACE","DEUCE","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","JACK","QUEEN","KING"};
string suits[]={"SPADES","HEART","CLUB","DIAMOND"};
int values[]={11,2,3,4,5,6,7,8,9,10,10,10,10};
deck= new card[cards_per_deck];
currentcard=0;
for(int count=0;count<cards_per_deck;count++){
    deck[count]=card(faces[count%13],suits[count/13],values[count%13]);
}
}
void deckOfcards::shuffle(){
currentcard=0;
for(int first=0;first<cards_per_deck;first++){
    int second=(rand()+time(0))%cards_per_deck;
    card temp=deck[first];
    deck[first]=deck[second];
    deck[second]=temp;
}
}
card deckOfcards::dealcard(){
if(currentcard>cards_per_deck)
    shuffle();
if(currentcard<cards_per_deck)
    return (deck[currentcard++]);
    return (deck[0]);
}
#endif // H_deckOfcards
