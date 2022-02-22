#include <iostream>
#include <string>

#include "Course.h"
#include "Student.h"

Course course;

//necessary user interface functions
    //adds new student (if there is space in course)
void addNewStudent(int ID,string  name,string surname){
    course.addNewStudent(ID,  name, surname);
};
    //shows student corresponding to given ID
void showStudent(int ID)  {
    course.getStudentInfo(ID);
};
    //changes a students grades with a given scores
void changeStudentScores(int ID,int*  quiz_scores,int * hw_scores,int  final_score){
    course.changeStudentScore(ID,  quiz_scores, hw_scores,  final_score);
};
    //changes the weights of the exams
void updateWeights(float weightQ,float weightHW,float weightF){
    course.updateWeights(weightQ, weightHW, weightF);
};
    //shows classroom all exams' averages
void showAverage(){
    course.calculateAverage();
};
    //shows the students whose average is above the given threshold
void showAbove(float threshold){
    course.showAbove(threshold);
};
    ////shows the students whose average is below the given threshold
void showBelow(float threshold){
    course.showBelow(threshold);
};

int main(int argc, char const *argv[]) {

    //define necessary parameters
    int ID, quiz_scores[4], hw_scores[3], final_score, new_score;
    int i;
    float threshold;
    float weightQ, weightHW, weightF;
    string name, surname, exam_type;

    //shows the options user can select
    cout<<"Choose Your Option"<<endl;
    cout<<"1) Add a student"<<endl;
    cout<<"2) Search a student by ID"<<endl;
    cout<<"3) Change a student's score"<<endl;
    cout<<"4) Update weights"<<endl;
    cout<<"5) Show classroom average"<<endl;
    cout<<"6) Show students with overall score above a threshold"<<endl;
    cout<<"7) Show students with overall score below a threshold"<<endl;
    cout<<"8) Exit"<<endl;

    //while loop asks the users which operation they want continuously
  while(true){
    cout<<"Enter your option:"<<endl;
    cin>>i;
    if (i==1){
        // add new student if there are less than  students in the class
        if (course.getNum() < 10) {
        cout<<"Enter student's ID, Name, Surname:"<<endl;
        cin>>ID>>name>>surname;
        addNewStudent(ID,name,surname);
        }
        else cout << "There are lots of student. No more entry is allowed!" << endl;

    }
    else if (i==2){
        cout<<"Enter ID:"<<endl;
        cin>>ID;
        showStudent(ID);
    }
    else if (i==3){
        cout<<"Enter ID, Quiz Scores(4), HW Scores(3), Final Score:"<<endl;
        cin>>ID>> quiz_scores[0]>>quiz_scores[1]>>quiz_scores[2]>>quiz_scores[3]>> hw_scores[0]>>hw_scores[1]>>hw_scores[2]>>final_score;
        //below if else structure checks if any grade provided by user is valid or not ( 0 <= grade <= 100 must satisfied)
        if ( 0<=quiz_scores[0]&&quiz_scores[0]<=100 ){
            if ( 0<=quiz_scores[1]&&quiz_scores[1]<=100 ){
                if ( 0<=quiz_scores[2]&&quiz_scores[2]<=100 ){
                    if ( 0<=quiz_scores[3]&&quiz_scores[3]<=100 ){
                        if ( 0<=hw_scores[0]&&hw_scores[0]<=100 ){
                            if ( 0<=hw_scores[1]&&hw_scores[1]<=100 ){
                                if ( 0<=hw_scores[2]&&hw_scores[2]<=100 ){
                                    if ( 0<=final_score&&final_score<=100 ){
                                            changeStudentScores(ID, quiz_scores,  hw_scores, final_score);
                                            }
                                    else cout<<"Invalid Number!"<<endl;}
                                else cout<<"Invalid Number!"<<endl;}
                            else cout<<"Invalid Number!"<<endl;}
                        else cout<<"Invalid Number!"<<endl;}
                    else cout<<"Invalid Number!"<<endl;}
                else cout<<"Invalid Number!"<<endl;}
            else cout<<"Invalid Number!"<<endl;}
        else cout<<"Invalid Number!"<<endl;

    }
    else if (i==4){
        cout<<"Enter Weights:"<<endl;
        cin>> weightQ>> weightHW>> weightF;
        updateWeights( weightQ, weightHW, weightF);
    }
    else if (i==5){

        showAverage();

    }
    else if (i==6){
        if(course.getNum()>0){ // checks if there are any students exist or not.
            cout<<"Enter threshold:"<<endl;
            cin>>threshold;
            //shows the related students if the threshold is valid (0 <= threshold  <= 100 must satisfied)
            if ( 0<=threshold&&threshold<=100 ){
                    showAbove(threshold);}
            else cout<<"Invalid Number!"<<endl;
         }
        else cout<<"There is NOT any student. First, add a student please!"<<endl;

    }
    else if (i==7){
        if(course.getNum()>0){ // checks if there are any students exist or not.
            cout<<"Enter threshold:"<<endl;
            cin>>threshold;
            //shows the related students if the threshold is valid (0 <= threshold  <= 100 must satisfied)
            if ( 0<=threshold&&threshold<=100 ){
                    showBelow(threshold);}
            else cout<<"Invalid Number!"<<endl;
        }
        else cout<<"There is NOT any student. First, add a student please!"<<endl;

    }
    else if (i==8){
        cout<<"Exiting the Program..."<<endl;
        return 0;
    }
    else  {
        //if the user enters different than given eight numbers, the input will be invalid.
        cout<<"Invalid Input!"<<endl;
    }
  }
  return 0;
}
