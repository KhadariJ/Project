#include <iostream>
#include <fstream>
#include <string>

const int ROW = 3;
const int COLM = 4;
using namespace std;
class Person
{
public:
void setName(ifstream&);
void setId(ifstream&);

private:

};

class Subject
{
public:
void print() const;
void passing(ifstream&);

private:
string topic;
string classes[ROW][3];
int grade[ROW][4];
double ids[ROW][1];
};

class Student: public Person
{
Subject sub;
public:
void setClass(int g);
void passing(ifstream&)
{
ifstream grad;
  sub.passing(grad);
}

private:
int grade;
string name;
};

class Teacher: public Person
{
Student stu;
public:
void setuId(string id);
void getStudents(ifstream&);
void print() const;
void setClass(int g)
{
  stu.setClass(grade);
}
void passing(ifstream&){
  ifstream grad;
  stu.passing(grad);
}

private:
int grade;
string uid;
string name;
string students[ROW][COLM];
};


class Profile
{
public:
void login();
void create();

private:
string username;
string password;
string user;
string pass;
string fname;
string lname;
};

struct Grades{
void passing(ifstream&){
  ifstream grd;
  grd.open("grades.txt");
  int i=0, pass =70, index=0;
  while(i<3){
    grd>>ids[i];
    grd>>scig[i];
    grd>>matg[i];
    grd>>reag[i];
  
  if(scig[i]<pass){
    index = i;
      cout<<"Student: "<<ids[index]<<" needs help in science"<<endl;
    cout<<"Please have this student take the science intervention course, Course#: 1009876.\n"<<endl;
    }
    else if(matg[i]<pass){
      index =i;
      cout<<"Student: "<<ids[index]<<" needs help in math"<<endl;
      cout<<"Please have this student take the math intervention course, Course#: 1005961.\n"<<endl;
    }
    else if (reag[i]<pass){
      cout<<"Student: "<<ids[index]<<" needs help in reading"<<endl;
      cout<<"Please have this student take the reading intervention course, Course#: 1008876.\n"<<endl;
    }
    i++;
}
  grd.close();
}

private:
string ids[3];
int scig[3];
int matg[3];
int reag[3];


};

void enterG();

int main() {
  Grades Grades;
  int gr;
  Profile teacher1;
  Teacher teach;
  int opt;
  char choice,answ;
  cout <<"=========================================="<<endl;
  cout <<"Welcome to the Invoation Education Center"<<endl;
  cout <<"+++++++++++++++++ Menu +++++++++++++++++++"<<endl;
  cout <<"Enter 1 to Login"<<endl;
  cout <<"Enter 2 to Create New Profile"<<endl;
  cout <<"Enter 3 to exit"<<endl;
  cin >>opt;
  switch(opt)
  {
    case 1:
    teacher1.login();
      cout<<"\nWhat would you like to do today?"<<endl;
      cout<<"Enter a to see Students"<<endl;
      cout<<"Enter b to enter grades"<<endl;
      cout<<"Enter c to see Student progress"<<endl;
      cout<<"Enter d to see Intervention courses"<<endl;
      cout<<"Enter e to go back Home"<<endl;
      cin>>choice;
    if(choice == 'a'){
      cout<<"\nWhat grade do you teach?"<<endl;
      cin>> gr;
      teach.setClass(gr);
          ifstream input;
          input.open("students.txt");
          teach.getStudents(input);
          teach.print();
          input.close();
      cout<<"\nBack? (Enter y or n):"<<endl;
      char answ;
      cin>>answ;
      if(answ=='y'){
    main();
      }
      }
       else if(choice== 'b')
    {
      enterG();
      main();
    }
    else if(choice== 'c')
    {
      ifstream grd;
      grd.open("grades.txt");
      Grades.passing(grd);
      cout<<"\nBack? (Enter y or n):"<<endl;
      char answ;
      cin>>answ;
      if(answ=='y'){
    main();
    }
      }
    else if (choice == 'd'){
      cout<<"===================================="<<endl;
      cout<<"        INTERVENTION COURSES        "<<endl;
      cout<<"(1)1005961: Mathmathics "<<endl;
      cout<<"(2)1008876: Reading & Literacy "<<endl;
      cout<<"(3)1009876: Science(Introduction to STEM) "<<endl;
      cout<<"\nWould you like to learn more about them? y or n"<<endl;
      char ch;
      int num;
      cin>>ch;
      if(ch=='y'){
        cout<<"Please enter integer corresponding to the course"<<endl;
        cin>>num;
        if (num == 1){
          cout<<"\nThe Innovation Education Center's mathematics program gives students a invasive 5 week learning course to help improve their studies. Students take preporatory exam to help center gauge learning style and knowledge of math concepts"<<endl;
        }
        else if(num == 2){
          cout<<"\nThe Innovation Education Center's Reading & Literacy program gives students a invasive 7 week learning course to help improve their studies. Students take preporatory exam to help center gauge learning style and literacy skills"<<endl;
        }
        else if(num == 3){
         cout<<"\nThe Innovation Education Center's Sciene program gives students a invasive 4 week learning course to help improve their studies. Students take preporatory exam to help center gauge learning style. This course helps with science studies and also grooms interest in STEM fields"<<endl;
        }
      }
      cout<<"\nBack? (Enter y or n):"<<endl;
      char answ;
      cin>>answ;
      if(answ=='y'){
    main();
    }
    }
      else if (choice =='e'){
        main();
      }
    else{
      cout<<"Please enter from options below"<<endl;
    }
    break;
    case 2:
    teacher1.create();
    break;

    case 3:
    cout <<"Thank you.";
    break;
    default:
    cout<<"Please enter option from below"<<endl;
    main();
    
  }  
  return 0;
}
  
void Profile:: login()
{

  int count;
  cout<< "Please enter username"<<endl;
  cin>> username;
  cout<< "Please enter password"<<endl;
  cin>> password;
    ifstream infile("profiles.txt");
  while(infile >>user>>pass>>fname>>lname)
    {
      if(username == user && password== pass){
        count = 1;
      }
    }
 
  if (count == 1){
    cout << "\nProfile: "<<fname<<" "<<lname<<endl;
  }
  else if(username != user || password!=pass){
    cout<<"Login error. Please Try again"<<endl;
    main();
  }
  infile.close();
}

void Profile::create(){
  string nuser,npass;
  cout <<"Time to create your profile"<<endl;
  cout<<"Please enter desired username"<<endl;
  cin >> nuser;
  cout<<"Please enter desired password"<<endl;
  cin >> npass;
  cout<<"Please enter first and last name."<<endl;
  cin>>fname>>lname;
  ofstream outfile("profiles.txt", ios::app);
  outfile<<nuser<<" "<<npass<<" "<<fname<<" "<<lname<<endl;
  cout<<"Congrats you made a profile!"<<endl;
  main();  
}
void Student::setClass(int g)
{
  grade = g;
}
void Teacher::getStudents(ifstream&)
{
  setClass(grade);
  ifstream input;
  input.open("students.txt");
  for (int i=0 ;i<3;i++)
  {
    for(int j=0; j<COLM; j++){
    input >> students[i][j];
      }
    }
    input.close();
  }

void Teacher::print() const
{
  for (int i=0;i<ROW;i++){
    cout<<"\n";
    for(int j=0;j<COLM;j++){
    cout<<students[i][j]<<" ";
      }
}
  }

void Subject::print() const{
  for (int i=0; i<ROW; i++){
    for(int j=2; j<4;j++){
      cout<<classes[i][j]<<" ";
    }
  }
}
void enterG(){
  string top, fname, lname;
  int ngrade;
  cout<<"Please enter student name(first name, last name): ";
  cin >> fname >> lname;
  cout<<"\nPlease enter subject: ";
  cin >>top;
  cout<<"\nPlease enter integer grade: ";
  cin >> ngrade;
  ofstream output("grades.txt",ios::app);
  output <<"\n"<<lname<<", "<<fname<<" "<<top<<": "<<ngrade;
  cout <<lname<<", "<<fname<<" "<<top<<": "<<ngrade<<endl;
  cout <<"Thank you!"<<endl;
}

  

