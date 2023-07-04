#include <iostream>
using namespace std;
class student
{
    char name[50];
    int reg;
    char section[50];
public:
    virtual void getCourseType()
    {
        cout<<endl;
    }
    virtual void getdetails()
    {
        cout<<"Enter the name : ";
        cin>>name;
        cout<<"Enter registration number : ";
        cin>>reg;
        cout<<"Enter section : ";
        cin>>section;
        cout<<endl;
    }
   virtual void showdetails()
    {
        cout<<"Student name : "<<name<<endl;
        cout<<"Student registration number : "<<reg<<endl;
        cout<<"Student section : "<<section<<endl;
    }
};
class course:public student
{
    char course_name[50];
    char course_code[10];
    int course_credit;
public:
    void getdetails()
    {
        fflush(stdin);
        cout<<"Enter the name of the course : ";
        cin>>course_name;
        cout<<"Enter the course code : ";
        cin>>course_code;
        cout<<"Enter the course credit : ";
        cin>>course_credit;
        cout<<endl;
    }
    void showdetails()
    {
        cout<<"Course name : "<<course_name<<endl;
        cout<<"Course code : "<<course_code<<endl;
        cout<<"Course credit : "<<course_credit<<endl;
    }
};
class marks:public course
{
    int i,n=0,ca_full;
    float ca[5];
    float mte_marks;
    float ete_marks;
    float att_marks;
    int course_type1;
public:
void getCourseType()
{
        cout<<"Enter the course type(1 for Practical or 2 for Theory) : ";
        cin>>course_type1;
}
    void getdetails()
    {
      if(course_type1==1)
        {
            n=3;
            ca_full=50;
 cout<<"Enter marks for ca out of 50 : "<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"CA"<<i<<" : ";
        cin>>ca[i];
    }
    cout<<"Enter end term marks out of 50 : ";
    cin>>ete_marks;
    cout<<"Enter attendance marks : ";
    cin>>att_marks;
    cout<<endl;

      }
        else if(course_type1==2)
        {
            n=2;
            ca_full=30;
 cout<<"Enter marks for ca out of 30 : "<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"CA"<<i<<" : ";
        cin>>ca[i];

    }

    cout<<"Enter mid term marks out of 20 : ";
    cin>>mte_marks;
    cout<<"Enter end term marks out of 50: ";
    cin>>ete_marks;
    cout<<"Enter attendance marks : ";
    cin>>att_marks;
    cout<<endl;

        }
else{
    cout<<"Wrong type of course chosen!"<<endl;
}
    }
    void showdetails()
    {
        cout<<"Attendance marks :  "<<att_marks<<endl;
        cout<<"Marks of ca : "<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"CA"<<i+1<<" : "<<ca[i];
            cout<<endl;
        }
        cout<<"Mid term marks : "<<mte_marks<<endl;
        cout<<"End term marks : "<<ete_marks<<endl;
    }

};
int main()
{
    int students,courses;
    student *s;
    cout<<"Number of students : ";
    cin>>students;
    student s1[students];

    for(int i=1;i<=students;i++)
    {
        s=&s1[i];
  s->getdetails();

  cout<<"Number of courses : ";
 cin>>courses;
  course c1[courses];
  marks m1[courses];
  for(int j=1;j<=courses;j++)
  {
  s=&c1[j];
  s->getdetails();
  s=&m1[j];
  s->getCourseType();
  s->getdetails();
  }
    }
  for(int i=1;i<=students;i++)
  {
  s=&s1[i];
  s->showdetails();
  course c1[courses];
  marks m1[courses];
    for(int j=0;j<=courses;j++)
    {
        s=&c1[j];
  s->showdetails();
    s=&m1[j];
  s->showdetails();
    }
  }
    return 0;
}
