#include<iostream>
#include<conio.h>v
#include<cstdlib>
#include<fstream>
#include<string.h>
using namespace std;
class ICM{
    string usn;char p[15];
    public:
void reg(){
     cout<<"Enter username: "<<endl;
    cin>>usn;
    cout<<"Create password: "<<endl;
    int j=0;
    do{
        p[j]=getch();
        if(p[j]!=13){
            cout<<"*";
            }
            j++;
    }
    while(p[j-1]!=13);
        p[j-1]=NULL;
    cout<<endl;
	ofstream info;
    info.open("info.txt",ios::app);
    info<<usn<<p<<endl;
    info.close();
    string file_name = usn + ".txt";
    ofstream users;
    users.open(file_name.c_str());
    users.close();
   }

void login(){
    cout<<"Enter username"<<endl;
    cin>>usn;
    cout<<"Enter password"<<endl;
        int i=0;
        do{
            p[i]=getch();
            if(p[i]!=13){
                cout<<"*";
            }
            i++;
        }
        while(p[i-1]!=13);
        p[i-1]=NULL;
        cout<<endl;
        string userinput=usn+p;
        string userpass;
        ifstream info1("info.txt");
        int y=0;int a;
        while(info1>>userpass){
            a=userpass.compare(userinput);
            if(a==0){
                y++;
                break;
            }
        }
        info1.close();
         if(y==1){
            system("cls");
            cout<<"Logged in successfully"<<endl;
            complaint_menu();
        }
        else{
            cout<<"Register first"<<endl;
            reg();
        }
    }

void complaint_menu(){
    int b;
    cout<<"\t\t================================\n";
    cout<<"\t\t|      1.Create new complaints |\n";
    cout<<"\t\t|      2.Update complaints     |\n";
    cout<<"\t\t|      3.View complaints       |\n";
    cout<<"\t\t|      4.Delete complaints     |\n";
    cout<<"\t\t|      0.BACK                  |\n";
    cout<<"\t\t================================\n";
    cout<<"Enter your choice: ";
    cin>>b;
    string filename=usn+".txt";
    if(b==1){
        cout<<"Enter New Complaint"<<endl;
        char c[500];int k=0;
         do{
            c[k]=getch();
            if(c[k]!=13){
            cout<<c[k];
            }
            k++;
         }
        while(c[k-1]!=13);
        c[k-1]=NULL;
        ofstream create;
        create.open(filename.c_str());
        create<<c<<"\n";
        create.close();
        system("cls");
        cout<<"Complaint Registered"<<endl;
        complaint_menu();
    }
    if(b==2){
        cout<<"Update Complaint"<<endl;
          char f[500];
        ifstream read;
        read.open(filename.c_str());
        while(!read.eof()){
            read.getline(f,500);
            cout<<f<<endl;}
        char d[500];int l=0;
         do{
            d[l]=getch();
            if(d[l]!=13){
            cout<<d[l];
            }
            l++;
         }
        while(d[l-1]!=13);
        d[l-1]=NULL;
        ofstream update;
        update.open(filename.c_str(),ios::app);
        update<<d<<"\n";
        update.close();
        system("cls");
        cout<<"Complaint Updated"<<endl;
        complaint_menu();
    }
    if(b==3){
        ifstream view(filename.c_str());
        char d[500];
        cout<<"Your complaints: "<<endl;
        while(view>>d){
            view.getline(d,500);
            cout<<d<<endl;}
            view.close();
            getch();
            system("cls");
            complaint_menu();
    }
    if(b==4){
        int status=remove(filename.c_str());
        system("cls");
        if(status==0){
          cout<<"Complaint Deleted"<<endl;
        }
        ofstream del;
        del.open(filename.c_str());
        del.close();
        complaint_menu();
    }
    if(b==0){

            ;}
    }
};
int main(){
int a;
ICM I;
do{
system("cls");
cout<<"\t\t================================\n";
cout<<"\t\t|   INTERNET COMPLAINT CELL    |\n";
cout<<"\t\t================================\n\n";
cout<<"\t\t--------------------------------\n";
cout<<"\t\t|         1.REGISTER           |\n";
cout<<"\t\t|         2.LOGIN              |\n";
cout<<"\t\t|         0.EXIT               |\n";
cout<<"\t\t--------------------------------\n";
cout<<"\t\tEnter your choice: ";
cin>>a;
if(a==1){
    I.reg();
    system("cls");
     cout<<"Registered Successfully"<<endl;
    I.complaint_menu();
}
if(a==2){
    I.login();
}
if(a==0){break;}
}
while(a!=0);
}
