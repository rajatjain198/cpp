#ifndef H_BlackJack
#define H_BlackJack
#include"deckOfcards.h"
#include"TicTacToe.h"
using namespace std;
class blackjack{
private:
    deckOfcards deck;
    card Card1;
    card Card2;
    card Dealercard1;
    card Dealercard2;
    card Hitcard;
    card Hitcard2;
    int cardtotal;
    int dealercardtotal;
    float bet;
public:
    void Dealing();
    void rules();
    float Playgame(char*,float);
    void Dealcard();
    int Hit();

};
void blackjack::Dealing(){
    deck.shuffle();
Card1=deck.dealcard();
Card2=deck.dealcard();
Dealercard1=deck.dealcard();
Dealercard2=deck.dealcard();
cardtotal=Card1.values()+Card2.values();
dealercardtotal=Dealercard1.values()+Dealercard2.values();
bet=1;
}
void blackjack::rules(){
    cout<<"\n\t\tWELCOME TO BLACKJACK"<<endl;
    cout<<"\t\t*********************"<<endl;
cout<<"\n\tRules To Play BlackJack :"<<endl<<"\n\tTwo cards face up provided to Player and two cards for Dealer of which one Face Down."<<endl;
cout<<"\n\tThe Player Needs to Beat the Dealer by getting Card Value more then Dealers Card"<<endl;
cout<<"\n\tBut not Exceeding 21 i.e. an ACE Card Value 11 and a 10 value card [TEN, JACK, Queen, King] adds Up to 21"<<endl;
cout<<"\n\tPlayer can choose ACE Card Value to Be 1 or 11 as per there requirement"<<endl;
cout<<"\n\tPlayer can place there bet and win 1.5 times there Bet if they beat the dealer"<<endl;
cout<<"\n\tPlayer can HIT or STAND until there card total is less then 21 and 'BUST' if there total exceeds 21 i.e. Lose"<<endl;
cout<<"\n\tIf a Player gets card total 21 it's a 'BLACKJACK' i.e. Player hand Won"<<endl;
cout<<"\n\tThe Dealer's total must be above 16 and therefore after the Player is done Hitting the dealer will Hit Until it is Greater than 16 or Gets BUST"<<endl<<endl;
cout<<"\n\tIf the Dealer's Hand and Player's Hand Total is Equal it is a Push and Player will be returned Bet Amount"<<endl;
//cout<<"
cout<<"\n\t";
system("PAUSE");
}
float blackjack::Playgame(char *n,float m){
    up:
    system("CLS");
    cout<<"\tWelcome "<<n<<endl;
    cout<<"\n\tChips: $"<<m<<endl;
    cout<<"\n\tPlace Your Bet : $";
    cin>>bet;
    if(bet>m||bet<=0){
        cout<<"\n\tNot Enough Chips"<<endl;
        cout<<"\n\t";
        system("PAUSE");
        goto up;
     }
     m=m-bet;
    cout<<"\n\tDealer is Shuffling the Cards"<<endl;
    getch();
    cout<<"\n\tNow the Player will be dealt two Cards"<<endl<<endl;
    cout<<"\n\t"<<Card1.print()<<endl;
    cout<<"\n\t"<<Card2.print()<<endl;
    cout<<"\n\tPlayer's Card Total is : "<<cardtotal<<endl<<endl;
    cout<<"\n\tNow Dealer will deal two Cards"<<endl<<endl;
    cout<<"\n\t"<<Dealercard1.print()<<endl;
    cout<<"\n\tXXXXXXXXXXXXX"<<endl;
    int flag=0;
    char yes;
        if(Card1.values()==11||Card2.values()==11){
            cout<<"\n\tDo You Want ACE Card Value 1"<<endl;
            cout<<"\n\tYour Cardtotal will be : "<<cardtotal-10<<"  Y/N ? ";
            cin>>yes;
            if(yes=='y'||yes=='Y')
                cardtotal=cardtotal-10;
         }
        if(Hit()&&cardtotal!=21){
            cout<<"\n\tHit Card: "<<Hitcard.print()<<endl;
            cout<<"\n\tPlayer Card Total: "<<cardtotal<<endl;
            flag=1;
            if(Hitcard.values()==11){
                cout<<"\n\tDo You Want ACE Card Value 1"<<endl;
                cout<<"\n\tYour Cardtotal will be : "<<cardtotal-10<<"  Y/N ? ";
                cin>>yes;
                if(yes=='y'||yes=='Y')
                   cardtotal=cardtotal-10;
            }
            if(cardtotal<21){
                cout<<"\n\tDo You wanna Hit again or Stand? H/S : ";
                cin>>yes;
                if(yes=='h'||yes=='H'){
                     Hitcard2=deck.dealcard();
                     cardtotal=cardtotal + Hitcard2.values();
                     flag=2;
                     if(Hitcard2.values()==11){
                        cout<<"\n\tDo You Want ACE Card Value 1"<<endl;
                        cout<<"\n\tYour Cardtotal will be : "<<cardtotal-10<<"  Y/N ? ";
                        cin>>yes;
                        if(yes=='y'||yes=='Y')
                            cardtotal=cardtotal-10;
                        }
            }
        }
        }
            system("CLS");
            cout<<"\n\tYour Hand has :"<<endl<<endl;
            cout<<"\n\t"<<Card1.print()<<endl<<endl;
            cout<<"\n\t"<<Card2.print()<<endl<<endl;
            if(flag==1)
            cout<<"\n\t"<<Hitcard.print()<<endl<<endl;
            if(flag==2)
            cout<<"\n\t"<<Hitcard2.print()<<endl<<endl;
            cout<<"\n\tYour Hand Total : "<<cardtotal<<endl;
            cout<<"\n\n\tNow Dealers Cards will be revealed"<<endl;
            cout<<"\n\t"<<Dealercard1.print()<<endl<<endl;
            cout<<"\n\t"<<Dealercard2.print()<<endl<<endl;
            cout<<"\n\tDealers card Total : "<<dealercardtotal<<endl<<endl;

            while(dealercardtotal<17){
                    Hitcard=deck.dealcard();
                cout<<"\n\tNew Card Dealt: "<<Hitcard.print()<<endl;
                dealercardtotal=dealercardtotal + Hitcard.values();
            }
            cout<<"\n\tDealer Card Total: "<<dealercardtotal<<endl;


           if(cardtotal==21&&dealercardtotal!=cardtotal){
                cout<<"\n\tBLACKJACK!"<<endl;
                m=m+(1.5)*bet;
                cout<<"\n\tYou have won "<<bet*(1.5)<<"\n\tChips : $"<<m<<endl;
                cout<<"\n\t";
                system("PAUSE");
            }

           else if(dealercardtotal>21){
                cout<<"\n\tThe Dealer got Busted"<<endl;
                cout<<"\n\tYou will receive 3:2 your Bet "<<endl;
                m=m+bet*(1.5);
                cout<<"\n\tChips: $"<<m<<endl;
                cout<<"\n\t";
                system("PAUSE");

            }
            else if(dealercardtotal>cardtotal&&dealercardtotal<22){
                cout<<"\n\tDealer's Hand Won"<<endl;
                cout<<"\n\tYou have lost Bet amount: "<<bet<<endl;
                cout<<"\n\tChips Left: $"<<m<<endl;
                cout<<"\n\t";
                system("PAUSE");
            }
            else if(dealercardtotal<cardtotal&&cardtotal<21){
                cout<<"\n\tYour Hand Won"<<endl;
                m=m+(1.5)*bet;
                cout<<"\n\tChips: $"<<m<<endl;
                cout<<"\n\t";
                system("PAUSE");
            }
            else if(dealercardtotal==cardtotal&&dealercardtotal<22){
                cout<<"\n\tIt's a Push"<<endl;
                m=m+bet;
                cout<<"\n\tChips: $"<<m<<endl;
                cout<<"\n\t";
                system("PAUSE");
            }
            else if(dealercardtotal<22&&cardtotal>21){
                cout<<"\n\tIt's a BUST"<<endl;
                cout<<"\n\tYou have lost Bet amount: "<<bet<<endl;
                cout<<"\n\tChips Left: $"<<m<<endl;
                cout<<"\n\t";
                system("PAUSE");
            }
            return m;
    }
int blackjack::Hit(){
char y;
            cout<<"\n\tDo You want to Hit or Stand H/S : ";
            cin>>y;
            if(y=='H'||y=='h'){
                Hitcard=deck.dealcard();
                cardtotal=cardtotal + Hitcard.values();
                return 1;
                }
                return 0;
}


#endif // H_BlackJack

/*void BlackJack(){
  deckOfcards deck;
    card currentcard;
    deck.printDeck();
    cout<<endl;
    deck.shuffle();
    deck.printDeck();
    cout<<endl;
    deck.shuffle();
    for(int i=0;i<52;i++){
        currentcard=deck.dealcard();
        cout<<setw(20)<<currentcard.print()<<currentcard.values()<<endl;
    }
system("PAUSE");
}*/
//
