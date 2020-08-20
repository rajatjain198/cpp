#ifndef H_user
#define H_user
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
class user{
public:
    int user_id;
    char name[20];
    float money;

    user(){
    user_id=0;
    strcpy(name,"NO NAME");
    }
    void getuserdata(){
    cout<<"\n\n\tEnter User Pin: ";
    cin>>user_id;
    cout<<"\n\n\tEnter Name: ";
    cin.ignore();
    cin.getline(name,20);
    cout<<"\n\n\tEnter Your Starting Balance: ";
    cin>>money;
    cout<<endl;
    }
    void showuserdata(){
    cout<<"\n\tUserPin: "<<user_id<<endl;
    cout<<"\n\tName   : "<<name<<endl;
    cout<<"\n\tChips  : $"<<money<<endl;
    }
    int storedata();
    void viewuserdata();
    void searchuser(char*);
    void deleteuser(char*);
    void updateuser(char*);
    int useridentity(char*);
    void updatemoney(char*,float,int);
};
int user::storedata(){
if(user_id==0&&money==0){
    cout<<"\n\tUser Data Not Initialised"<<endl;
    return 0;
}
ofstream fout;
fout.open("file1.dat",ios::app|ios::binary);
fout.write((char*)this,sizeof(*this));
fout.close();
return 1;
}
void user::viewuserdata(){
ifstream fin;
fin.open("file1.dat",ios::app|ios::binary);
if(!fin)
    cout<<"\n\tFile Not Found"<<endl;
else{
        fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
        showuserdata();
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
}
}
void user::searchuser(char *n){
    int counter=0;
    ifstream fin;
    fin.open("file1.dat",ios::app|ios::binary);
    if(!fin)
        cout<<"File Not Found"<<endl;
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(n,name)){
                showuserdata();
                counter++;
            }
            fin.read((char*)this,sizeof(*this));
        }
        if(counter==0)
            cout<<"\n\tRecord Not Found"<<endl;
        fin.close();
    }
}
void user::deleteuser(char *n){
ifstream fin;
ofstream fout;
fin.open("file1.dat",ios::app|ios::binary);
if(!fin)
    cout<<"File Not Found"<<endl;
else{
    fout.open("tempfile.dat",ios::app|ios::binary);
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof()){
    if(strcmp(name,n))
        fout.write((char*)this,sizeof(*this));
        fin.read((char *)this,sizeof(*this));
    }
        fin.close();
        fout.close();
        remove("file1.dat");
        rename("tempfile.dat","file1.dat");
    }
}
void user::updateuser(char *n){
    fstream file;
    file.open("file1.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof()){
        if(!strcmp(n,name)){
            getuserdata();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
    file.close();
}
int user::useridentity(char *n){
int counter=0;
    ifstream fin;
    fin.open("file1.dat",ios::app|ios::binary);
    if(!fin)
        cout<<"File Not Found"<<endl;
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(n,name)){
                    cout<<"\n\tEnter User Pin: ";
                counter++;
            }
            if(counter==0)
            fin.read((char*)this,sizeof(*this));
            else
            break;
        }
        if(counter==0){
            cout<<"\n\tWrong UserName"<<endl;
            cout<<"\n\t";
            system("PAUSE");
        fin.close();
        return 0;
        }
        else{
            fin.close();
            return 1;
        }
    }
}
void user::updatemoney(char *n,float m,int x){
    int counter=0;
    fstream file;
    file.open("file1.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof()){
        if(!strcmp(n,name)){
            money=m;
            strcpy(name,n);
            user_id=x;
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
            counter++;
        }
        if(counter==0)
        file.read((char*)this,sizeof(*this));
        else
            break;
    }
    file.close();
}

#endif // H_user
