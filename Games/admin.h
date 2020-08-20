#ifndef H_admin
#define H_admin
#include"user.h"
char adminchoice();
void admin();
void adminlogin(){
    start:
    cout<<"\n\tEnter Admin Password: ";
    int i,x;
    char ch='/0',password[]="deepali",match[20];
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
        {
         cout<<"*";
         match[i]=ch;
         i++;
        }
      else if (ch==8) // if backspace is pressed
       {
         cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
         i--;
       }
      else if(ch==13)
    {
         match[i]='\0'; // if enter is pressed, last character in match[] becomes null
        break;         // for end of string
    }
    else
    {
         break;
    }
  }
  if(strcmp(match,password)==0)// comparing two strings.. if equal returns 0
  {
   cout<<endl<<"\n\tPassword Correct"<<endl;
   cout<<"\n\t";
   system("PAUSE");
   admin();
  }
  else
  {
   cout<<endl<<"\n\tWrong Password"<<endl;
   cout<<"\n\t";
   system("PAUSE");
   goto start;
   puts(match);
  }
}
char adminchoice(){
char choice;
cout<<"\n\tAdmin Menu"<<endl;
cout<<"\n\ta.View Users"<<endl;
cout<<"\n\tb.Search User"<<endl;
cout<<"\n\tc.Delete User"<<endl;
cout<<"\n\td.Update User"<<endl;
cout<<"\n\te.Back to Main Menu(You will be logged out)"<<endl;
cout<<"\n\tEnter Your Choice Admin: ";
cin>>choice;
return choice;
}
void admin(){
    char name[20];
    user data;
while(1){
        system("CLS");
    switch(adminchoice()){
case 'a' :
    data.viewuserdata();
    cout<<"\n\t";
    system("PAUSE");
    break;
case 'b' :
    cout<<"\n\tEnter UserName to Search: ";
    cin.ignore();
    cin.getline(name,19);
    data.searchuser(name);
    cout<<"\n\t";
    system("PAUSE");
    break;
case 'c':
    cout<<"\n\tEnter UserName to Delete: ";
    cin.ignore();
    cin.getline(name,19);
    data.deleteuser(name);
    cout<<"\n\tRecord Deleted Successfully"<<endl;
    cout<<"\n\t";
    system("PAUSE");
    break;
case 'd':
    cout<<"\n\tEnter UserName to Update: ";
    cin.ignore();
    cin.getline(name,19);
    data.updateuser(name);
    cout<<"\n\tRecord Updated Successfully"<<endl;
    cout<<"\n\t";
    system("PAUSE");
    break;
case 'e':
    return;
default :
    cout<<"\n\tInvalid Choice"<<endl;
    cout<<"\n\t";
    system("PAUSE");
    break;
    }
}
}




#endif // H_admin
