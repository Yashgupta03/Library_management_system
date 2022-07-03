#include<bits/stdc++.h>
#include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int main();

class checker{
public:
int check2(string name,string id,string pass,string title);
int check(string name,string id);
void update3(string name,string id,string pass,string title, string author);
void update2(string name,string id,string pass,string title, string author,int count);
void update1(string name,string id,string pass,string title, string author,int count);
void update(string name,string id,string pass,string title, string author);

};

int checker::check2(string name,string id,string pass,string title) {
  string fname;
  fname="issue_data.csv";
  vector<string> row;
	string line, word;

  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name && row[1]==id && row[2]==pass&&row[3]==title) return 1;
      }
		}
	
	else cout<<"Could not open the file book_data.csv in Book::list_books\n";
  return 0;
}

int checker::check(string name,string id) {
  string fname;
  int count=0;
  fname="book_num.csv";
  vector<string> row;
	string line, word;

  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name && row[1]==id) {
        count=stoi(row[4]);
      }
    }
	}
	
	else cout<<"Could not open the file book_num.csv in check function\n";
  return count;
}

void checker::update3(string name,string id,string pass,string title, string author){
  string fname;
  fstream fout;
  
  fout.open("issue_data2.csv",ios::out | ios::app);
  fname="issue_data.csv";
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[3]!=title) {
			    fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<","<<row[5]<<"\n";
      }
      
		}
	}
	else cout<<"Could not open the file issue_data.csv in update2\n";
 

  remove("issue_data.csv");
  rename("issue_data2.csv", "issue_data.csv");

}

void checker::update2(string name,string id,string pass,string title, string author,int count) {
  string fname;
  fstream fout;
  count--;
  int flag=0;
  fout.open("book_num2.csv",ios::out | ios::app);
  fname="book_num.csv";
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name && row[1]==id) {
			    fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<count<<"\n";
        flag=1;
      }
      else {
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<stoi(row[4])<<"\n";
      }
		}
    if(flag==0) {
      fout<<name<<","<<id<<","<<title<<","<<author<<","<<count<<"\n";
    }
	}
	else cout<<"Could not open the file book_num.csv in update1\n";
 

  remove("book_num.csv");
  rename("book_num2.csv", "book_num.csv");
}

void checker::update1(string name,string id,string pass,string title, string author,int count) {
  string fname;
  fstream fout;
  count++;
  int flag=0;
  fout.open("book_num2.csv",ios::out | ios::app);
  fname="book_num.csv";
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name && row[1]==id) {
			    fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<count<<"\n";
        flag=1;
      }
      else {
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<stoi(row[4])<<"\n";
      }
		}
    if(flag==0) {
      fout<<name<<","<<id<<","<<title<<","<<author<<","<<count<<"\n";
    }
	}
	else cout<<"Could not open the file book_num.csv in update1\n";
 

  remove("book_num.csv");
  rename("book_num2.csv", "book_num.csv");
}

void checker::update(string name,string id,string pass,string title, string author){
  string fname;
  fstream fout;
  
  fout.open("book_data2.csv",ios::out | ios::app);
  fname="book_data.csv";
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==title && row[1]==author) {
			    fout<<title<<","<<author<<","<<row[2]<<","<<row[3]<<","<<"0"<<"\n";
      }
      else {
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
		}
	}
	else cout<<"Could not open the file book_data.csv in update\n";
 

  remove("book_data.csv");
  rename("book_data2.csv", "book_data.csv");

}


class Book{
  public:
  void list_books();
  void add_book();
  void update_book();
  void delete_book();
  void issued_book();
void search_book();
};

class User : public Book{
public:
  string name,id,pass,des;
  User(string n="NA",string i="NA",string p="NA",string d="NA"){
    name=n;
    id=i;
    pass=p;
    des=d;
  }
  void list_user();
  void registration();
  void update_user();
  void delete_user();
  void issued_books();
  void issue(vector<string>&v);
  void returning(vector<string>&v);
void clear_fine(string name,string id);
void due_date();
};

class student : public User{
public:
  string name,id,pass;

  student(string n="NA",string i="NA",string p="NA") {
    name=n;
    id=i;
    pass=p;
  }
  void fine();
};

class professor : public User{
public:
  string name,id,pass;

  professor(string n="NA",string i="NA",string p="NA") {
    name=n;
    id=i;
    pass=p;
  }
  void fine();
};

class page{
  public:
  void login_page(vector<string>&v);
  void student_page(vector<string>&v);
  void professor_page(vector<string>&v);
  void librarian_page(vector<string>&v);
};

class Base{
  public:
  vector<string> login();
  void forgot();
};
  
void Book::list_books() {
  string fname;
  fname="book_data.csv";
  vector<string> row;
	string line, word;
  int f=0;
  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
        f=1;
				row.push_back(word);
        cout<<word<<"  ";
	      }
      cout<<'\n';
      }
    if(f==0) cout<<"\nLibrary doesn't have any book\n";
		}
	
	else cout<<"Could not open the file book_data.csv in Book::list_books\n";
}

void User::list_user() {
  string fname;
  fname="user_data.csv";
  vector<string> row;
	string line, word;

  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      cout<<row[1]<<" "<<row[0]<<" ";
      if(row[3]=="1") cout<<"Student";
      else if(row[3]=="2") cout<<"Professor";
      else cout<<"Librarian";
      cout<<'\n';
      }
		}
	
	else cout<<"Could not open the file user_data.csv in Book::list_user\n";
}

void Book::add_book() {
  fstream fout;
  string title,author,isbn,pub,c;
  fout.open("book_data.csv",ios::out | ios::app);
  cin.ignore();
  cout<<"Enter title\n";
  getline(cin, title);
  cout<<"Enter author\n";
  getline(cin, author);
  cout<<"Enter isbn\n";
  getline(cin, isbn);
  cout<<"Enter publication\n";
  getline(cin, pub);
  cout<<"Are you sure you want to add book\n";
  cout<<"Enter Y/N\n";
  cin>>c;
  if(c=="Y")
  fout<<title<<","<<author<<","<<isbn<<","<<pub<<","<<"1"<<"\n";
}

void Book::update_book() {
  string fname;
  fstream fout;
  int k=0;
  int c;
  string b1,b2;
  cout<<"Press 1 if you want to update name of book\n";
  cout<<"Press 2 if you want to update author name of book\n";
  cout<<"Press 3 if you want to update ISBN code of book\n";
  cout<<"Press 4 if you want to update publication of book\n";
  cin>>c;
  switch(c){
    case 1:
      cin.ignore();
          cout<<"Enter original name of book\n";
          getline(cin, b1);
          cout<<"Enter updated name of book\n";
          getline(cin, b2);
          break;
    case 2:
      cin.ignore();
          cout<<"Enter original author name of book\n";
          getline(cin, b1);
          cout<<"Enter updated author name of book\n";
          getline(cin, b2);
          break;
    case 3:
      cin.ignore();
          cout<<"Enter original ISBN code of book\n";
          getline(cin, b1);
          cout<<"Enter updated ISBN code of book\n";
          getline(cin, b2);
          break;
    case 4:
      cin.ignore();
          cout<<"Enter original Publication of book\n";
          getline(cin, b1);
          cout<<"Enter updated Publication of book\n";
          getline(cin, b2);
          break;
    default :
          cout<<"invalid choice\n";
          update_book();
  }
  
  
  fout.open("book_data2.csv",ios::out | ios::app);
  fname="book_data.csv";
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      
      if(row[0]==b1 && c==1) {
        k++;
			    fout<<b2<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
      else if(row[1]==b1 && c==2) {
        k++;
          fout<<row[0]<<","<<b2<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
      else if(row[2]==b1 && c==3) {
            k++;
        fout<<row[0]<<","<<row[1]<<","<<b2<<","<<row[3]<<","<<row[4]<<"\n";
      }
      else if(row[3]==b1 && c==4) {
        k++;
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<b2<<","<<row[4]<<"\n";
      }
      else {
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
		}
    if(k==0) cout<<"Book does not exist\n";
	}
	else cout<<"Could not open the file book_data.csv in Book::update_book\n";
 

  remove("book_data.csv");
  rename("book_data2.csv", "book_data.csv");

}

void Book::delete_book() {
  string fname;
  fstream fout;
  int k=0;
  string b;
  fout.open("book_data2.csv",ios::out | ios::app);
  fname="book_data.csv";
  
	vector<string> row;
	string line, word;
  cin.ignore();
  cout<<"Enter name of book to be deleted\n";
  getline(cin, b);
  
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]!=b) {
			    fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
      else k++;
		}
    if(k==0) cout<<"Entered book does not exist\n";
	}
	else cout<<"Could not open the file book_data.csv in Book::delete_book\n";
 

  remove("book_data.csv");
  rename("book_data2.csv", "book_data.csv");

}

void User::registration() {
  fstream fout;
  string c;
  string user,pass,id,checker;
  fout.open("user_data.csv",ios::out | ios::app);
  cin.ignore();
  cout<<"Enter Username\n";
  getline(cin, user);
  cout<<"Enter ID\n";
  getline(cin, id);
  cout<<"Enter password\n";
  getline(cin, pass);
  cout<<"Enter 1 if you are student\n";
  cout<<"Enter 2 if you are Professor\n";
  cout<<"Enter 3 if you are Librarian\n";
  getline(cin, checker);
  cout<<"\n"<<"\n"<<"Are you sure above entered credentials are correct\n";
  cout<<"Enter [Y/N] in capital letters\n";
  getline(cin, c);
  if(c=="Y")
  fout<<id<<","<<user<<","<<pass<<","<<checker<<"\n";
  else main();
}

void User::update_user() {
  string fname;
  fstream fout;
  int k=0;
  int c;
  string b1,b2;
  cout<<"Press 1 if you want to update ID of user\n";
  cout<<"Press 2 if you want to update name of user\n";
  cout<<"Press 3 if you want to update Password of user\n";
  cout<<"Press 4 if you want to update designation of user\n";
  cin>>c;
  switch(c){
    case 1:
      cin.ignore();
          cout<<"Enter original ID of user\n";
          getline(cin, b1);
          cout<<"Enter updated ID of user\n";
          getline(cin, b2);
          break;
    case 2:
      cin.ignore();
          cout<<"Enter original name of user\n";
          getline(cin, b1);
          cout<<"Enter updated name of user\n";
          getline(cin, b2);
          break;
    case 3:
      cin.ignore();
          cout<<"Enter original Password of user\n";
          getline(cin, b1);
          cout<<"Enter updated Password of user\n";
          getline(cin, b2);
          break;
    case 4:
      cin.ignore();
          cout<<"Enter original designation of user\n";
          getline(cin, b1);
          cout<<"Enter updated designation of user\n";
          getline(cin, b2);
          break;
    default :
          cout<<"invalid choice\n";
          update_user();
  }
  
  
  fout.open("user_data2.csv",ios::out | ios::app);
  fname="user_data.csv";
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      
      if(row[0]==b1 && c==1) {
        k++;
			    fout<<b2<<","<<row[1]<<","<<row[2]<<","<<row[3]<<"\n";
      }
      else if(row[1]==b1 && c==2) {
        k++;
          fout<<row[0]<<","<<b2<<","<<row[2]<<","<<row[3]<<"\n";
      }
      else if(row[2]==b1 && c==3) {
            k++;
        fout<<row[0]<<","<<row[1]<<","<<b2<<","<<row[3]<<"\n";
      }
      else if(row[3]==b1 && c==4) {
        k++;
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<b2<<"\n";
      }
      else {
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<"\n";
      }
		}
    if(k==0) cout<<"Entered user credential are incorrect\n";
	}
	else cout<<"Could not open the file user_data.csv in Book::update_user\n";
 

  remove("user_data.csv");
  rename("user_data2.csv", "user_data.csv");

}

void User::delete_user(){
  string fname;
  fstream fout;
  string b;
  int k=0;
  fout.open("user_data2.csv",ios::out | ios::app);
  fname="user_data.csv";
  
	vector<string> row;
	string line, word;
  cin.ignore();
  cout<<"Enter name of user to be deleted\n";
  getline(cin, b);
  
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
        
	      }
      if(row[1]!=b) {
			    fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<"\n";
      }
      else k++;
		}
    if(k==0) cout<<"Username does not exist\n";
	}
	else cout<<"Could not open the file user_data.csv in Book::delete_user\n";
 

  remove("user_data.csv");
  rename("user_data2.csv", "user_data.csv");
}

void Book::issued_book() {
  string fname;
  int k=0;
  fname="issue_data.csv";
  vector<string> row;
	string line, word;

  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
        k++;
				row.push_back(word);
	      }
      cout<<row[0]<<" "<<row[1]<<" "<<row[3]<<"\n";
      }
    if(k==0) cout<<"No book has been issued\n";
		}
	
	else cout<<"Could not open the file issue_data.csv in Book::issued_book\n";
}

void User::issued_books(){
  string fname;
  int k=0;
  fname="issue_data.csv";
  vector<string> row;
	string line, word;

  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name && row[1]==id && row[2]==pass) {
        cout<<row[3]<<'\n';
        k++;
      }
    }
    if(k==0) cout<<"\nYou does not have any book\n\n";
	}
	
	else cout<<"Could not open the file issue_data.csv in User::issued_books\n";
}

void User::issue(vector<string>&v) {
  string title,author;
  int k=0;
  string fname;
  cin.ignore();
  cout<<"Enter Title\n";
  getline(cin, title);
  cout<<"Enter Author name\n";
  getline(cin, author);
  vector<string> row;
	string line, word,isbn,pub;
  fname="book_data.csv";
  fstream file (fname, ios::in);
  checker ch;
  if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')) {
				row.push_back(word);
      }
      if(row[0]==title && row[1]==author){
        k++;
        if(row[4]=="0") {
          cout<<"Book not available\n";
        }
        else {
          
          isbn=row[2];
          pub=row[3];
          int x;
          x=ch.check(name,id);
          cout<<"\n"<<x<<"\n";
          if(x<5||v[3]=="2"){
          ch.update( name, id, pass,title, author);
          fstream fout;
          fout.open("issue_data.csv",ios::out | ios::app);
          fout<<name<<","<<id<<","<<pass<<","<<title<<","<<time(0)<<"\n";
          ch.update1(name, id, pass,title, author,x);
          }
          else cout<<"You already have 5 books\n";
        }
      }
		}
    if(k==0) cout<<"Book does not exist\n";
	}
	else
		cout<<"Could not open the file book_data.csv in User::issue\n";
}

void User::returning(vector<string>&v) {
  string title,author;
  string fname;
  int count=0;
  cin.ignore();
  cout<<"Enter Title\n";
  getline(cin, title);
  cout<<"Enter Author name\n";
  getline(cin, author);
  vector<string> row;
	string line, word;
  fname="book_data.csv";
  fstream file (fname, ios::in);
  checker ch;
  
  if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')) {
				row.push_back(word);
      }
      if(row[0]==title && row[1]==author) {
        count++;
        if(ch.check2(v[1],v[0],v[2],title)==0){
          cout<<"You does not have this book\n";
          remove("book_data2.csv");
          return;
        }
        else{
        fstream fout;
        fout.open("book_data2.csv",ios::out | ios::app);
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<"1"<<"\n";
        int x=ch.check(name,id);
        ch.update2( name, id, pass,title, author,x);
        }
      }
      else {
        fstream fout;
        fout.open("book_data2.csv",ios::out | ios::app);
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
		}
  if(count==0) cout<<"You does not have this book\n";
  remove("book_data.csv");
  rename("book_data2.csv", "book_data.csv");
  // int x=check(name,id);
  // update2( name, id, pass,title, author,x);
  ch.update3( name, id, pass,title, author);
	}
	else
		cout<<"Could not open the file book_data in User::returning\n";
}

void student::fine(){
  string fname;
  int s=0,a;
  fname="issue_data.csv";
  // long int time = time(0);
  vector<string> row;
	string line, word,title;
  // cin.ignore();
  // getline(cin,title);
  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name&&row[1]==id&&row[2]==pass) {
        a=((ceil((time(0)-(stoi(row[4])))/86400.0))-30)*2;
        if(a>0) s+=a;
      }
      }
    if(s>=0)
    cout<<"Your fine amount is : "<<s<<endl;
    else cout<<"Your fine amount is : 0"<<endl;
		}
	else cout<<"Could not open the file book_data.csv in Book::list_books\n";
  
}

void professor::fine(){
  string fname;
  int s=0,a;
  fname="issue_data.csv";
  vector<string> row;
	string line, word,title;
  // cin.ignore();
  // getline(cin,title);
  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==name&&row[1]==id&&row[2]==pass) {
        a=((ceil((time(0)-(stoi(row[4])))/86400.0))-60)*5;
        if(a>0) s+=a;
      }
      }
    if(s>=0)
    cout<<"Your fine amount is : "<<s<<endl;
    else cout<<"Your fine amount is : 0"<<endl;
		}
	else cout<<"Could not open the file book_data.csv in Book::list_books\n";
}

void User::clear_fine(string Name,string Id){
  string fname;
  fstream fout;
  fout.open("issue_data2.csv",ios::out | ios::app);
  fname="issue_data.csv";
  vector<string> row;
	string line, word;
  
  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
    
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==Name&&row[1]==Id){
        fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<time(0)<<"\n";
      }
      else fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<"\n";
      }
    remove("issue_data.csv");
  rename("issue_data2.csv", "issue_data.csv");
		}
	
	else cout<<"Could not open the file user_data.csv in Book::list_user\n";
}

void User::due_date() {
  string fname,title,author;
  int k=0;
  fname="issue_data.csv";
  vector<string> row;
	string line, word;
  cout<<"Enter Title of the book\n";
  cin.ignore();
  getline(cin,title);
  fstream file (fname, ios::in);
  time_t ttime;
  
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[3]==title) {
        if(des=="1"){
        ttime = stoi(row[4])+2592000;
          }
        else if(des=="2") ttime = stoi(row[4])+2592000*2;
        tm *local_time = localtime(&ttime);
         cout<< local_time->tm_mday<<"/"<<1 + local_time->tm_mon<<"/"<<1900 + local_time->tm_year<<"\n";
        k++;
      }
    }
    if(k==0) cout<<"\nbook is not issued\n\n";
	}
	
	else cout<<"Could not open the file issue_data.csv in User::issue_date\n";
}

void Book::search_book() {
  string fname,title,author;
  fname="book_data.csv";
  vector<string> row;
	string line, word;
  int f=0;
  cin.ignore();
  cout<<"Enter title of book\n";
  
  getline(cin,title);
  cout<<"Enter author name\n";
  getline(cin,author);
  fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==title&&row[1]==author){
        f=1;
        if(row[4]=="1"){
          cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<" "<<row[3]<<" "<<"Available\n";
        }
        else cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<" "<<row[3]<<" "<<"Not Available\n";
      }
      }
    if(f==0) cout<<"Book not found\n";
		}
	
	else cout<<"Could not open the file book_data.csv in Book::list_books\n";
}

void page::student_page(vector<string>&v){
  int c;
  string user=v[1];
  cout<<"\nWelocme "<<user<<endl;
  cout<<"You Are accessing this page as Student"<<endl;
  cout<<"\n";
  cout<<"Press 1 to see list of all books along with availability\n";
  cout<<"Press 2 to see list of books that you have issued\n";
  cout<<"Press 3 to see due date of a book\n";
  cout<<"Press 4 to see fine\n";
  cout<<"Press 5 to search a book\n";
  cout<<"Press 6 to issue available book\n";
  cout<<"Press 7 to return the issued book\n";
  cout<<"Press 8 to Logout\n";
  cin>>c;
  User u1(v[1],v[0],v[2],v[3]);
  student s1(v[1],v[0],v[2]);
  switch(c){
    case 1:
          u1.list_books();
          break;
    case 2:
          u1.issued_books();
          break;
    case 3:
          u1.due_date();
          break;
    case 4:
          s1.fine();
          break;
    case 5:
          u1.search_book();
          break;
    case 6:
          u1.issue(v);
          break;
    case 7:
          u1.returning(v);
          break;
    case 8:
          main();
          break;
    default:
          cout<<"Please select from the given options above\n";
          student_page(v);
    
  }
  student_page(v);
}

void page::professor_page(vector<string>&v){
  int c;
  string user=v[1];
  cout<<"Welocme "<<user<<endl;
  cout<<"You Are accessing this page as Professor"<<endl;

  cout<<"Press 1 to see list of all books along with availability\n";
  cout<<"Press 2 to see list of books that you have issued\n";
  cout<<"Press 3 to see due date of a book\n";
  cout<<"Press 4 to see fine\n";
  cout<<"Press 5 to search a book\n";
  cout<<"Press 6 to issue available book\n";
  cout<<"Press 7 to return the issued book\n";
  cout<<"Press 8 to Logout\n";
  cin>>c;
  User u2(v[1],v[0],v[2],v[3]);
  professor p1(v[1],v[0],v[2]);
  switch(c){
    case 1:
          u2.list_books();
          break;
    case 2:
          u2.issued_books();
          break;
    case 3:
          u2.due_date();
          break;
    case 4:
          p1.fine();
          break;
    case 5:
          u2.search_book();
          break;
    case 6:
          u2.issue(v);
          break;
    case 7:
          u2.returning(v);
          break;
    case 8:
          main();
          break;
    default:
          cout<<"Please select from the given options above\n";
          professor_page(v);
    
  }
  professor_page(v);
}

void page::librarian_page(vector<string>&v){
  int c;
  string user=v[1];
  string name,id;
  cout<<"Welocme "<<user<<endl;
  cout<<"You Are accessing this page as Librarian"<<endl;

  cout<<"Press 1 to see list of all books along with availability\n";
  cout<<"Press 2 to see list of all user\n";
  cout<<"Press 3 to add book\n";
  cout<<"Press 4 to update book\n";
  cout<<"Press 5 to delete a book\n";
  cout<<"Press 6 to register a user\n";
  cout<<"Press 7 to update a user\n";
  cout<<"Press 8 to delete a user\n";
  cout<<"Press 9 to see list of all books which are issued to different user\n";
  cout<<"Press 10 to see due date of a book\n";
  cout<<"Press 11 to clear fine of a user\n";
  cout<<"Press 12 to search a book\n";
  
  cout<<"Press 13 to Logout\n";
  cin>>c;
  Book b;
  User u1(v[1],v[0],v[2],v[3]);
  switch(c){
    case 1:
          b.list_books();
          break;
    case 2:
          u1.list_user();
          break;
    case 3:
          b.add_book();
          break;
    case 4:
          b.update_book();
          break;
    case 5:
          b.delete_book();
          break;
    case 6:
          u1.registration();
          break;
    case 7:
          u1.update_user();
          break;
    case 8:
          u1.delete_user();
          break;
    case 9:
          b.issued_book();
          break;
    case 10:
          u1.due_date();
          break;
    case 11:
          cout<<"Enter user name\n";
          cin.ignore();
          getline(cin,name);
      cout<<"Enter user id\n";
          
          getline(cin,id);
          u1.clear_fine(name,id);
          break;
    case 12:
          u1.search_book();
          break;
    case 13:
          main();
          break;
    default:
          cout<<"Please select from the given options above\n";
          librarian_page(v);
    
  }
  librarian_page(v);
}

void Base::forgot() {
  string fname,user,id;
  int count=0;
  fname="user_data.csv";
  cin.ignore();
  cout<<"Enter username\n";
  getline(cin, user);
  cout<<"Enter Login ID\n";
  getline(cin, id);
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')) {
				row.push_back(word);
      }
      if(row[0]==id && row[1]==user){
        cout<<"\n\nYour password is : "<<row[2]<<'\n'<<"\n";
        count++;
      }
		}
	}
	else
		cout<<"Could not open the file\n";

  if(count==0) cout<<"Please enter correct username, user id";
 main();
}

vector<string> Base::login() {
  string fname,pass,id;
  int count=0;
  vector<string> v;
  fname="user_data.csv";
  cin.ignore();
  cout<<"Enter LoginID\n";
  getline(cin,id);
  cout<<"Enter Password\n";
  
  getline(cin,pass);
  
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
	      }
      if(row[0]==id && row[2]==pass) {
			    cout<<"\n\nThanks for Logging in "<<row[1]<<'\n'<<'\n'<<'\n';
          count++;
          return row;
      }
		}
	}
	else cout<<"Could not open the file\n";
 if(count==0){ cout<<"Please enter correct LoginID, Password\n";
   main();
   }
  line="";
  v.push_back(line);
  return v;
}

void page::login_page(vector<string>&v) {
  string qual=v[3];
  page p;
  if(qual=="1") p.student_page(v);
  else if (qual=="2") p.professor_page(v);
  else if(qual=="3") p.librarian_page(v);
}

int main() {
  int c;
  vector<string> v;
  cout<<"\t\t\t___________________________________\n\n";
  cout<<"\t\t\t       Welcome to login page       \n\n";
  cout<<"\t\t\t_______________MENU________________\n\n";
  cout<<"\t Press 1 to Login      \n";
  cout<<"\t Press 2 to Register      \n";
  cout<<"\t Press 3 to Forgot your Password      \n";
  cout<<"\t Press 4 to Exit      \n";
  cout<<"Please Enter Your Choice\n";
  User u1;
  page p;
  Base b;
  cin>>c;
  cout<<endl;
  switch(c){
    case 1:
          v=b.login();
          break;
    case 2:
          
          u1.registration();
          break;
    case 3:
          b.forgot();
          break;
    case 4:
          cout<<"\nThank you\n";
          goto Exit;
          break;
    default:
          cout<<"Please select from the given options above\n";
          main();
    
  }
  if(c==1) {
    p.login_page(v);
  }
  main();
  Exit:
  return 0;
}
