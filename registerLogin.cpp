#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    int loginChoice,nameChoice,temp;
    string userName,password,passWord,name;
    cout<<"WELCOME----TO----LOGIN----REGISTARTION----SYSTEM\n"<<endl;
    cout<<"Hello, would you like to login or register\n[1] Login\n[2] Register\n[3] Exit"<<endl;
    cin>>loginChoice;

    if(loginChoice==1){
        cout<<"Please enter your username"<<endl;
        cin>>userName;
        cout<<"Please enter your password"<<endl;
        cin>>password;
        cout<<"You are logged in.😀"<<endl;
    }

    else if(loginChoice==2){
        cout<<"Enter your name:"<<endl;
        cin>>name;
        cout<<"Create your username:"<<endl;
        cin>>userName;
        cout<<"Username- '"<<userName<<"'"<<endl;
        cout<<"Confirm ?"<<endl;
        cout<<"[1] Yes"<<endl;
        cout<<"[2] No"<<endl;
        cin>>nameChoice;

        if(nameChoice==1){
            cout<<"Create Password:"<<endl;
            cin>>password;
            cout<<"Re-enter Password"<<endl;
            cin>>passWord;
            while(password!=passWord){
                cout<<"You Entered differnet password"<<endl;
                cout<<"Create Password:"<<endl;
                cin>>password;
                cout<<"Re-enter Password"<<endl;
                cin>>passWord;
            }
            cout<<"Your password is confirmed."<<endl;
            cout<<"|Your registration is done.😀|"<<endl;
        }
        else if(nameChoice==2){
            cout<<"It's okay🙂."<<endl;
        }
        else{
            cout<<"Wrong choice!."<<endl;
        }
    }

    else if(loginChoice==3){
        cout<<"EXIT!!"<<endl;
        return 0;
        
    }
    else{
        cout<<"There's no option available like this."<<endl;
    }
}