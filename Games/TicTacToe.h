#ifndef H_TicTacToe
#define H_TicTacToe
#include<iostream>
#include<stdlib.h>
using namespace std;
void playerturn();
void choice(int ,char );
bool win();
void DisplayBoard();
char box[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void DisplayBoard(){
system("CLS");
cout<<"\t\tWelcome to Tic Tac Toe Game"<<endl;
cout<<"\t\t---------------------------"<<endl;
cout<<"\t\tPlayer[1]=X and Player[2]=O"<<endl<<endl<<endl;
cout<<"\t\t"<<box[0][0]<<"\t|"<<"\t"<<box[0][1]<<"\t|\t"<<box[0][2]<<endl;
cout<<"\t\t________|_______________|________"<<endl;
cout<<"\t\t"<<box[1][0]<<"\t|"<<"\t"<<box[1][1]<<"\t|\t"<<box[1][2]<<endl;
cout<<"\t\t________|_______________|________"<<endl;
cout<<"\t\t"<<box[2][0]<<"\t|"<<"\t"<<box[2][1]<<"\t|\t"<<box[2][2]<<endl;
cout<<"\t\t        |               |        "<<endl;
}
void playerturn(){
    DisplayBoard();
    int a;
    while(win()){
        cout<<endl<<"\n\t\tPlayer 1 Choose any No. : ";
        cin>>a;
        choice(a,'X');
        DisplayBoard();

            if(win()){
        cout<<endl<<"\n\t\tPlayer 2 Choose any No. : ";
        cin>>a;
            choice(a,'O');
        DisplayBoard();
            }
    }
}
void choice(int a,char xo){
    switch(a)
    {
 case 1:
    if(box[0][0]!='X'&&box[0][0]!='O')
    box[0][0]=xo;
    break;
 case 2:
    if(box[0][1]!='X'&&box[0][1]!='O')
    box[0][1]=xo;
    break;
 case 3:
    if(box[0][2]!='X'&&box[0][2]!='O')
    box[0][2]=xo;
    break;
 case 4:
    if(box[1][0]!='X'&&box[1][0]!='O')
    box[1][0]=xo;
    break;
 case 5:
    if(box[1][1]!='X'&&box[1][1]!='O')
    box[1][1]=xo;
    break;
 case 6:
    if(box[1][2]!='X'&&box[1][2]!='O')
    box[1][2]=xo;
    break;
 case 7:
    if(box[2][0]!='X'&&box[2][0]!='O')
    box[2][0]=xo;
    break;
 case 8:
    if(box[2][1]!='X'&&box[2][1]!='O')
    box[2][1]=xo;
    break;
 case 9:
    if(box[2][2]!='X'&&box[2][2]!='O')
    box[2][2]=xo;
    break;
 default:
    cout<<"\n\t\tEnter Valid Choice"<<endl;
    cout<<"\n\t\t";
    system("PAUSE");
    }
}
bool win(){
  static int count=0;
for(int i=0;i<3;i++){
if(box[i][0]==(box[i][1])&&box[i][0]==(box[i][2])&&box[i][0]=='X'){
        cout<<"\n\t\tPlayer 1 Wins"<<endl;
        cout<<"\n\t\t";
        system("PAUSE");
        return false;
}
else if(box[0][i]==box[1][i]&&box[0][i]==box[2][i]&&box[0][i]=='X'){
        cout<<"\n\t\tPlayer 1 Wins"<<endl;
        cout<<"\n\t\t";
        system("PAUSE");
        return false;

}
else if(box[i][0]==(box[i][1])&&box[i][0]==(box[i][2])&&box[i][0]=='O'){
        cout<<"\n\t\tPlayer 2 Wins"<<endl;
        cout<<"\n\t\t";
        system("PAUSE");
        return false;
}
else if(box[0][i]==box[1][i]&&box[0][i]==box[2][i]&&box[0][i]=='O'){
        cout<<"\n\t\tPlayer 2 Wins"<<endl;
        cout<<"\n\t\t";
        system("PAUSE");
        return false;
}
}
if(box[0][0]==box[1][1]&&box[1][1]==box[2][2]&&box[2][2]=='X'){
    cout<<"\n\t\tPlayer 1 Wins"<<endl;
    cout<<"\n\t\t";
    system("PAUSE");
    return false;
}
else if(box[0][0]==box[1][1]&&box[1][1]==box[2][2]&&box[2][2]=='O'){
    cout<<"\n\t\tPlayer 2 Wins"<<endl;
    cout<<"\n\t\t";
    system("PAUSE");
    return false;
}
else if(box[0][2]==box[1][1]&&box[1][1]==box[2][0]&&box[2][0]=='X'){
    cout<<"\n\t\tPlayer 1 Wins"<<endl;
    cout<<"\n\t\t";
    system("PAUSE");
    return false;
}
else if(box[0][2]==box[1][1]&&box[1][1]==box[2][0]&&box[2][0]=='O'){
    cout<<"\n\t\tPlayer 2 Wins"<<endl;
    cout<<"\n\t\t";
    system("PAUSE");
    return false;
}
else if(count>=9)
{
    cout<<"\n\t\tIt's a Draw Gentleman"<<endl;
    cout<<"\n\t\t";
    system("PAUSE");
    return false;
}
else{
     count++;
     return true;
}
}
#endif // H_TicTacToe
