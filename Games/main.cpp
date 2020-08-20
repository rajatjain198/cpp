#include"admin.h"
#include"login.h"
#include"TicTacToe.h";
using namespace std;
int mainmenu(){
    int choice;
    cout<<"\n\tMain Menu"<<endl<<endl;
    cout<<"\t1.User Login"<<endl<<endl;
    cout<<"\t2.New User? Register"<<endl;
    cout<<"\n\t3.Play a Two Player Free Game"<<endl;
    cout<<"\n\t4.Admin Panel"<<endl;
    cout<<"\n\t5.Exit"<<endl;
    cout<<"\n\tEnter Your Choice: ";
    cin>>choice;
    return choice;
}
int main()
{

    while(1){
            system("CLS");
    cout<<"\tQUARANTINE AND CHILL"<<endl;
        switch(mainmenu()){
    case 1:
        userlogin();
        break;
    case 2:
        newuser();
        break;
    case 3:
        playerturn();
        break;
    case 4:
        adminlogin();
        break;
    case 5:
        exit(0);
        break;
    default :
        cout<<"\n\tInvalid Choice"<<endl;
        cout<<"\n\t";
        system("PAUSE");
        }
    }
    return 0;
}
