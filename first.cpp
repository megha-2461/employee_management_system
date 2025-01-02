#include<iostream>
#include<unistd.h> //for sleep function
//#include<termios.h>
#include<stdlib.h> //for system("clear") function
using namespace std;


struct emp{
    string name, id, address;
    string contact, salary;
};
//global variables:
emp e[1000];
int total=0;

void empdata(){
  int choice;
  cout<<"How many employees data do you want to enter?"<<endl;
  cin>>choice;
  for(int i=total; i<total+choice; i++){
     cout<<"Enter data of employee "<<i+1<<endl;
     cout<<"Employee name: ";
     cin>>e[i].name;
     cout<<"Employee id: ";
     cin>>e[i].id;
     cout<<"Employee address: ";
     cin>>e[i].address;
     cout<<"Employee contact: ";
     cin>>e[i].contact;
     cout<<"Employee salary: ";
     cin>>e[i].salary;
  }
  total+=choice;
  
}

void show(){
  if (total==0) {
    cout<<"No data found"<<endl;
  }
  else {
 for(int i=0; i<total; i++){
    cout<<"\n\nData of employee "<<i+1<<endl;
    cout<<" Employee name "<<e[i].name<<endl;
    cout<<" Employee ID "<<e[i].id<<endl;
    cout<<" Employee address "<<e[i].address<<endl;
    cout<<" Employee contact "<<e[i].contact<<endl;
    cout<<" Employee salary "<<e[i].salary<<endl;
 }
  }
}


void search(){
if (total!=0){
    string id;
 cout<<"Enter ID of employee whose data you want to search "<<endl;
 cin>>id;
 for(int i=0; i<total; i++){
    if (e[i].id==id){
    cout<<"\n\nData of employee "<<i+1<<endl;
    cout<<" Employee name "<<e[i].name<<endl;
    cout<<" Employee ID "<<e[i].id<<endl;
    cout<<" Employee address "<<e[i].address<<endl;
    cout<<" Employee contact "<<e[i].contact<<endl;
    cout<<" Employee salary "<<e[i].salary<<endl;
    break;
    }
    if (i==total-1){
        cout<<"No such record found"<<endl;
    }
 }
}
else{
    cout<<" No data found "<<endl;
}
}

void update(){
 if (total!=0){
  string id;
 cout<<"Enter ID of employee whose data you want to update "<<endl;
 cin>>id;
 for(int i=0; i<total; i++){
    if (e[i].id==id){
    cout<<"Previous data: "<<endl;
    cout<<"Data of employee "<<i+1<<endl;
    cout<<" Employee name "<<e[i].name<<endl;
    cout<<" Employee ID "<<e[i].id<<endl;
    cout<<" Employee address "<<e[i].address<<endl;
    cout<<" Employee contact "<<e[i].contact<<endl;
    cout<<" Employee salary "<<e[i].salary<<endl;


    cout<<"Enter new data"<<endl;
    cout<<"Employee name: ";
     cin>>e[i].name;
     cout<<"Employee id: ";
     cin>>e[i].id;
     cout<<"Employee address: ";
     cin>>e[i].address;
     cout<<"Employee contact: ";
     cin>>e[i].contact;
     cout<<"Employee salary: ";
     cin>>e[i].salary;
    break;
    }
    if (i==total-1){
        cout<<"No such record found"<<endl;
    }
 }
 }
 else{
     cout<<" No data found "<<endl;
 }
}

void del(){
if (total!=0){
    char user;
cout<<"Press 1 to delete full record"<<endl;
cout<<"Press 2 to delete specific record"<<endl;
cin>>user;
if (user=='1'){
    total=0;
    cout<<"All record is deleted"<<endl;
}
else if (user=='2') {
    string id;
    cout<<"Enter ID of employee whose data you want to delete "<<endl;
 cin>>id;
 bool found=0;
 for(int i=0; i<total; i++){
    if (id==e[i].id){
     found=1;
      total--;
        for(int j=i; j<total; j++){
        e[j].name=e[j+1].name;
        e[j].id=e[j+1].id;
        e[j].address=e[j+1].address;
        e[j].contact=e[j+1].contact;
        e[j].salary=e[j+1].salary;
       
        //break;

    }
    cout<<"\nYour required data is deleted"<<endl;

 }
 
}
if (found==0){
    cout<<"No such record found"<<endl;
 }
}
}
else{
    cout<<" No data found "<<endl;
}
}


int main(){
    cout<<"\n\n\t\tEMPLOYEE MANAGEMENT SYSTEM"<<endl;
    cout<<"\n\n\t\tSign Up"<<endl;
    string username, password;
    cout<<"\n\t\tEnter username: ";
    cin>>username;
    cout<<"\n\t\tEnter password: ";
    cin>>password;
    cout<<"\n\t\tYour id is creating, please wait";


    for(int i=0; i<6; i++){
        cout<<".";
        usleep(1000000);
    }
    cout<<"\n\t\tYour id created successfully"<<endl;
    system("clear");
    start:
    cout<<"\n\n\t\tEMPLOYEE MANAGEMENT SYSTEM"<<endl;
    cout<<"\n\n\t\tLogin"<<endl;
    string usrname1, password1;
    cout<<"\n\t\tEnter username: ";
    cin>>usrname1;
    cout<<"\n\t\tEnter password";
    cin>>password1;
    if (usrname1==username && password1==password){
       system("clear");
       char user;
       while(1){

	cout<<"\n\nPress 1 to enter data"<<endl;

	cout<<"Press 2 to show data"<<endl;

	cout<<"Press 3 to search data"<<endl;

	cout<<"Press 4 to update data"<<endl;

	cout<<"Press 5 to delete data"<<endl;

	cout<<"Press 6 to logout"<<endl;

	cout<<"Press 7 to exit"<<endl;
    cin>>user;
    switch(user){

        case '1' :
        empdata();
        break;

        case '2' :
        show();
        break;

        case '3' :
        search();
        break;

        case '4' :
        update();
        break;

        case '5' :
        del();
        break;

        case '6':
        goto start;
        break;

       case '7':
        goto start;
        break;


        default:
        cout<<"\aInvalid input"<<endl;
        break;


        

    }
    }
    }
    else if (usrname1!=username){
        cout<<"Your username is incorrect"<<endl;
        sleep(2);
        goto start;
    }
    else if (password1!=password){
        cout<<"Incorrect password"<<endl;
        sleep(2);
        goto start;
    }
    else{
        cout<<"Incorrect credentials"<<endl;
        sleep(2);
        goto start;
    }
    return 0;

}
