#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED


#include <iostream>
#include <string>
#include "Student.h"
#define MAX_SIZE 10

using namespace std;

class Course{
private: //private members
    Student Entries[MAX_SIZE];
    int num;
    float weightQ, weightHW, weightF;

public:  //public methods
    Course(int num = 0, float weightQ = 0.3, float weightHW = 0.3, float weightF = 0.4);//Constructor
    int getNum() ;//Getter
    void addNewStudent(int ID,string  name,string surname);//Add student function
    void updateWeights(float wQ,float wHW ,float wF);//Change weights function
    void getStudentInfo(int ID );//Show by ID
    void calculateAverage();//Course Average Calculator

    //additional methods (not defined in the hw pdf)
    void changeStudentScore(int ID,int*  quiz_scores,int * hw_scores,int  final_score);
    void showAbove(float threshold);
    void showBelow(float threshold);
};

    //Constructor
Course::Course(int _num, float _weightQ , float _weightHW, float _weightF) {
    num = _num;
    weightQ = _weightQ;
    weightHW = _weightHW;
    weightF = _weightF;
  };

    //Getter
int Course::getNum() {
    return num;
  };

    //Add student
void Course::addNewStudent(int ID,string  name,string surname) {
        bool check = false;
        for(int i = 0; i<num;i++){
            if(Entries[i].getID()==ID) {check=true; break;}
        }
        if(check ==false){  //this if statement check if there is any students with the same ID number. If yes, it gives an error.
            Student student(ID, name, surname);
            Entries[num] = student;
            num=num+1;}
        else cout<<"There is already a student with the same ID."<<endl;

  }

  //Change weights function
void Course::updateWeights(float wQ,float wHW ,float wF){
    if((wQ+wHW+wF)==1 ){//this if statement check if the sum of the provided weights is '1' or not.
    weightQ=wQ;
    weightHW=wHW;
    weightF=wF;}
    else
        cout<< "Sum of the weights must be '1'!"<<endl;
  }

    //Show by ID
void Course::getStudentInfo (int ID ){
    Student st;
    int i;
    for (i=0; i<num; i++){
      if (Entries[i].getID()==ID){
        st=Entries[i];
        break;
      }
    }
    if (i==num){
        cout<<"Invalid Number!"<<endl;//If there is no student with the given ID, it gives an error.
    }
    else {
        cout <<st.getID()<<" "<<st.getName()<<" "<<st.getSurname()<<" ";
        cout <<st.getQuizScores()[0]<<" "<<st.getQuizScores()[1]<<" "<<st.getQuizScores()[2]<<" "<<st.getQuizScores()[3]<<" ";
        cout <<st.getHwScores()[0]<<" "<<st.getHwScores()[1]<<" "<<st.getHwScores()[2]<<" ";
        cout <<st.getFinalScore()<<endl;
    }
  }

  //Course Average Calculator
void Course::calculateAverage(){
    int Q1=0,Q2=0,Q3=0,Q4=0,HW1=0,HW2=0,HW3=0,F=0;
    float overall=0;

    if(num>0){//shows the average of all the exams if there are any students.
    for (int i=0; i<num; i++){
      Q1=Q1+(Entries[i].getQuizScores()[0]);
      Q2=Q2+(Entries[i].getQuizScores()[1]);
      Q3=Q3+(Entries[i].getQuizScores()[2]);
      Q4=Q4+(Entries[i].getQuizScores()[3]);
      HW1=HW1+(Entries[i].getHwScores()[0]);
      HW2=HW2+(Entries[i].getHwScores()[1]);
      HW3=HW3+(Entries[i].getHwScores()[2]);
      F=F+(Entries[i].getFinalScore());
      overall=overall+Entries[i].overallCourseScore(weightQ, weightHW, weightF);
    }
    cout<<"The Classroom Average:"<<endl;
    cout<<"Average of Quiz1: "<<Q1/(float)num<<endl;
    cout<<"Average of Quiz2: "<<Q2/(float)num<<endl;
    cout<<"Average of Quiz3: "<<Q3/(float)num<<endl;
    cout<<"Average of Quiz4: "<<Q4/(float)num<<endl;
    cout<<"Average of HW1: "<<HW1/(float)num<<endl;
    cout<<"Average of HW2: "<<HW2/(float)num<<endl;
    cout<<"Average of HW3: "<<HW3/(float)num<<endl;
    cout<<"Average of Final Exam: "<<F/(float)num<<endl;
    cout<<"Average of Overall Course: "<<overall/((float)num)<<endl;}

    else cout<<"There are no student. First, add a student please!"<<endl;
  }


//additional methods implementation
    //In order to change a student's grades, 'Entries' must be reached. So this operation must be done
    //in the course class, because Entries's variables (defined in private) are not available from main function.
void Course::changeStudentScore(int ID,int*  quiz_scores,int * hw_scores,int  final_score){

    for(int i=0;i<num; i++){
      if(Entries[i].getID()==ID){
        Entries[i].setQuizScores(quiz_scores);
        Entries[i].setHwScores(hw_scores);
        Entries[i].setFinalScore(final_score);
      }
  }
}

//shows the students whose average is above the threshold
void Course::showAbove(float threshold){
    float overall=0,avg=0;
    Student st;
    bool check=false;

        for(int i=0; i<num; i++){
                // checks if there are any students whose grade is above the threshold.
          if(Entries[i].overallCourseScore(weightQ, weightHW, weightF)>threshold){
            check = true;
            st=Entries[i];
            cout <<st.getID()<<" "<<st.getName()<<" "<<st.getSurname()<<" ";
            cout <<st.getQuizScores()[0]<<" "<<st.getQuizScores()[1]<<" "<<st.getQuizScores()[2]<<" "<<st.getQuizScores()[3]<<" ";
            cout <<st.getHwScores()[0]<<" "<<st.getHwScores()[1]<<" "<<st.getHwScores()[2]<<" ";
            cout <<st.getFinalScore()<<endl;
          }
        }
        if (check == false) cout<<"There are no students with an average of more than "<< threshold <<"."<<endl;



}
//shows the students whose average is below the threshold
  void Course::showBelow(float threshold){
    float overall=0,avg=0;
    Student st;
    bool check=false;
        for(int i=0 ; i<num; i++){
                // checks if there are any students whose grade is below the threshold.
          if(Entries[i].overallCourseScore(weightQ, weightHW, weightF)<threshold){
            check = true;
            st=Entries[i];
            cout <<st.getID()<<" "<<st.getName()<<" "<<st.getSurname()<<" ";
            cout <<st.getQuizScores()[0]<<" "<<st.getQuizScores()[1]<<" "<<st.getQuizScores()[2]<<" "<<st.getQuizScores()[3]<<" ";
            cout <<st.getHwScores()[0]<<" "<<st.getHwScores()[1]<<" "<<st.getHwScores()[2]<<" ";
            cout <<st.getFinalScore()<<endl;

          }
         }

         if (check == false) cout<<"There are no students with an average of less than "<< threshold <<"."<<endl;
 }
#endif // COURSE_H_INCLUDED
