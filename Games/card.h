#ifndef H_card
#define H_card
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class card{
private:
    string face;
    string suit;
    int value;
public:
    card(string cardface,string cardsuit,int cardvalue){
    face=cardface;
    suit=cardsuit;
    value=cardvalue;
    }
card()
{
}
string print() const
{
 return (face + " OF " +suit);
}
int values() const
{
    return(value);
}


};
#endif // H_card

