#include<fstream>  
#include<string>
#include<vector>
#include<iostream>
#include"BTREE.h"
using namespace std;
int main()
{
	string command,filename,colnames;
	cout<<"     Type CREAT file_name  col_name col_name ....   (creat new file)"<<endl;
	cout<<"     Type EXIST File_name  open                     (use existing file)"<<endl;
	cout<<"~$";
    cin>>command>>filename;
    getline(cin,colnames);
    BTree t(3);
    if(command=="creat" || command=="CREAT")
	{
	t.coloums=colnames;
	ofstream myfile;
 	myfile.open(filename);
 	myfile<<colnames<<" ;";
 	cout<<"Enter data according to coloums sequence with primary key ex:-PK  DATA DATA DATA ......"<<endl; 
 	string comm;
	while(comm != "EXIT" && comm !="exit")
	{
		cout<<"~$";
		string pk;cin>>pk;
		string data;
	    getline(cin,data);
		myfile<<pk<<';'<<data<<" ;"; 
		t.insert(pk,data);
		cout<<endl;
		cout<<"Press any key for insert more data or Type EXIT"<<endl;
		cin>>comm;
	}
	myfile.close(); 
    }    
       
    else if(command=="exist" || command=="EXIST")
	{
	ifstream cfile;
	cfile.open(filename);
	int i=1;
	while(cfile.good())
	{
		if(i==1)
		{
		string  coloum; 
		getline(cfile,coloum,';');
		t.coloums=coloum;
		i++;
	    }
		string key;
		getline(cfile,key,';');
		string data;
		getline(cfile,data,';');
		t.insert(key,data);
	}
	cfile.close();		
	}    
        
     else
	 {
	 	cout<<"Envalid option:  Msg:-  Abeyyy  sal..."<<endl;
	 	return 0;
	 }   

string loop="continue";      
while(loop=="continue")
{  
	cout<<endl;
	cout<<endl;
	cout<<"~$ ";  
	string primary,data,command;  
	cout<<" TYPE: INSERT primary_key data,data,data,..."<<endl;
	cout<<"    TYPE: SEARCH primary_key print"<<endl;
	cout<<"    TYPE: DELETE primary_key all"<<endl;
	cout<<"    TYPE: EXIT Operations loop"<<endl;
	cout<<"~$ ";
	cin>>command>>primary>>data;
	if(command=="INSERT" || command=="insert")
	{
    	ofstream mfile;
    	mfile.open(filename);
		mfile<<primary<<';'<<data<<" ;";
		t.insert(primary,data);	
	}  
	
	else if(command=="search" || command=="SEARCH")
	{
		 Node *gg=t.search(primary);
	     if(gg==NULL)
	     {
	     	cout<<endl;
	     	cout<<"~$";
	     	cout<<"............. No Data exist ............"<<endl;
	     	cout<<endl;
	     }
	     
	     else if(data=="all" || data=="ALL")
	     {
	     	cout<<endl;
	     	cout<<"~$";
	     	cout<<" Search Result : "<<endl;
	     cout<<endl;	
	     string info=get;
	     string col=t.coloums;
		 string da,coloum;
		 vector<string> c,d;
	     for(int i=0;i<col.length();i++)
	     {
	     	if(col[i] != ' ')
	     	{
	     	  	coloum+=col[i];
	     	  	continue;
	     	}
	     	if(i==0)
	     	{
	     		continue;
	     	}
	     	c.push_back(coloum);
	     	coloum="";
	     }
	     
	     for(int i=0;i<info.length();i++)
	     {
	     	if(info[i] != ' ')
	     	{
	     	  	da+=info[i];
	     	  	continue;
	     	}
	     	if(i==0)
	     	{
	     		continue;
	     	}
	     	d.push_back(da);
	     	da="";	     	
	     }
	     for(int i=0;i<c.size();i++)
	     {
	       	cout<<c[i]<<" : ";
	       	if(i<d.size())
	       	{
	       	   cout<<d[i]<<endl;
	       	}
	     }
	     
	     }
	     
		else
		{
			cout<<endl;
		cout<<" search Results :"<<endl;
		cout<<endl;
		string col=t.coloums;
		string found;
		int count=0;
		bool print=true;
		for(int i=0;i<col.size();i++)
		{
			if(col[i] != ' ')
			{
				found+=col[i];
				continue;
			}
			count++;
			if(found==data)
			{
				cout<<" "<<found<<" : ";
				break;
			}
			else if(i==col.size()-1)
			{
				cout<<" attribute missing error....."<<endl;
				print=false;
			}
			found="";
		}
	    if(print==true)
	    {
	     string info=get;
	     string da;
	     int c=0;
	     for(int i=0;i<info.length();i++)
	     {
			if(info[i] != ' ')
			{
				da+=info[i];
				continue;
			}
            c++;
			if(c == count)
			{
				cout<<da<<endl;
				break;
			}
			da="";
				     	
	     }
	    }
	 }

	}

	else if(command=="DELETE" || command=="delete")
	{
		t.remove(primary);		
		cout<<"Data deleted successfully "<<endl;
	}	  	    
	else if(command=="exit" || command=="EXIT")
	{
		loop="exit";
	} 
	else
	{
		cout<<"~$ INVALID OPTION......"<<endl;
	}
}
	return 0;
}
