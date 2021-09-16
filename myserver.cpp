#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(int args,char** credentials)
{    
    string user=credentials[1];
    string password=credentials[2];
    fstream file;
    file.open("users.txt");
    if(file.fail())
    { 
        ofstream newfile("users.txt");
        newfile<<user<<";"<<password<<";"<<endl;
        newfile.close();
        cout<<"First user created login again ~"<<endl; 
    }  
    else
    {
       ifstream readfile("users.txt");
       string data;
       while(readfile.good())
       {
           string username,pass;
           getline(readfile,username,';');
           getline(readfile,pass,';');
           if(username==user)
           {
               if(pass==password)
               {
                cout<<"login successful ...."<<endl;   
                 server();
               }
               else 
               {
                cout<<"error:  incorrect password....."<<endl;
                return 0;   
               }
           }
       }
       cout<<"NO user exist ........"<<endl;
    }
    
    return 0;
}
