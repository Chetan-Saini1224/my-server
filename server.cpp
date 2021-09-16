#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include"BTREE.h"
#include<boost/filesystem.hpp>
using namespace std;

void server()
{
    
    string cmd,obj,name;
    while(true)
    {
    cout<<"myserver>";cin>>cmd>>obj>>name;
    transform(cmd.begin(),cmd.end(),cmd.begin(), ::tolower);

    if(cmd=="use")
    {
        //boost::filesystem::create_directory(name);
        //cd(name);
        continue;  
    }    

    if(cmd=="insert")
    {   
        cout<<"Enter Data : "<<endl;
        string data;cin>>data;
    	ofstream mfile;
    	mfile.open(name);
		mfile<<data<<" ;";	
	}  
            
    else if(cmd=="create")
    {

    }
    else if(cmd=="remove")
    {

    }
    else if(cmd=="delete")
    {

    }

    else if(cmd=="exit")
    {
        break;
    }
    }
}