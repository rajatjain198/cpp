#ifndef H_login
#define H_login
#include"user.h"
#include"BlackJack.h"
using namespace std;
user data;
blackjack game;
void newuser();
void userlogin();
void usermenu();
char userchoice();
void userlogin(){
    start:
        system("CLS");
    cout<<"\n\tLogin to Your Account"<<endl;
    cout<<"\n\tEnter Username: ";
    char n[20];
    int pin;
    cin.ignore();
    cin.getline(n,19);
    if(data.useridentity(n)){
    cin>>pin;
    if(pin==data.user_id){
        cout<<"\n\tLogin Successful"<<endl;
        cout<<"\n\t";
        system("PAUSE");
        usermenu();
    }
    else{
    cout<<"\n\tUser Pin Wrong"<<endl;
    cout<<"\n\t";
    system("PAUSE");
    goto start;
         }
}
else
    return;
}
void newuser(){
data.getuserdata();
data.storedata();
cout<<"\n\tRegistration Completed"<<endl;
userlogin();
}
char userchoice(){
char choice;
system("CLS");
cout<<"\n\tUser Menu"<<endl;
cout<<"\n\ta.Play Black Jack"<<endl;
cout<<"\n\tb.Play Three Card Poker"<<endl;
cout<<"\n\tc.Buy Chips"<<endl;
cout<<"\n\td.Check Chips Balance"<<endl;
cout<<"\n\te.Update Your Information"<<endl;
cout<<"\n\tf.Rule Book of BlackJack"<<endl;
cout<<"\n\tg.Log Out"<<endl;
cout<<"\n\tSelect Option: ";
cin>>choice;
return choice;
}
void usermenu(){
    float chips;
    char name[20];
while(1){
        switch(userchoice()){
    case 'a':
        game.Dealing();
        data.money=game.Playgame(data.name,data.money);
        data.updatemoney(data.name,data.money,data.user_id);
        break;
    case 'b':
        cout<<"\n\tGame Under Development"<<endl;
        cout<<"\n\t";
        system("PAUSE");
        break;
    case 'c':
        cout<<"\n\tYou can Request upto $100 chips at a Time"<<endl;
        cout<<"\n\tRequest Chips :$";
        cin>>chips;
        if(chips<=100){
            data.money=data.money+chips;
            data.updatemoney(data.name,data.money,data.user_id);
            cout<<"\n\tYour Request will be Responded."<<endl<<endl;
            cout<<"\n\t";
            system("PAUSE");
            break;
        }
        cout<<"\n\tRequested Amount Exceeded Limit"<<endl<<endl;
        cout<<"\n\t";
        system("PAUSE");
        break;
    case 'd':
        cout<<"\n\n\tTotal Chips : $"<<data.money<<endl;
        getch();
        break;
    case 'e':
        cout<<"\n\t1.Change UserName"<<endl;
        cout<<"\n\t2.Change User Pin"<<endl;
        cout<<"\n\t3.Back"<<endl;
        cout<<"\n\tSelect Option: ";
        cin>>chips;
        if(chips==1){
            cout<<"\n\tEnter New UserName: ";
            cin.ignore();
            cin.getline(name,19);
            data.updatemoney(name,data.money,data.user_id);
            cout<<"\n\tUserName Not Changed"<<endl;
            cout<<"\n\t";
            system("PAUSE");
        }
        else if(chips==2){
            cout<<"\n\tEnter New Pin: ";
            cin>>data.user_id;
            data.updatemoney(data.name,data.money,data.user_id);
            cout<<"\n\tPin Changed"<<endl;
            cout<<"\n\t";
            system("PAUSE");
        }
        break;
    case 'f':
        game.rules();
        break;
    case 'g':
        return;
    default:
        cout<<"\n\tInvalid Choice\n"<<endl;
        cout<<"\n\t";
        system("PAUSE");
        }
}
}
#endif // H_login
