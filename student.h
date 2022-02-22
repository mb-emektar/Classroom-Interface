#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student{
private:
  string name, surname;
  int id, quiz_scores[4], hw_scores[3], final_score;
public:
    //constructor
  Student(int id_=0, string name="", string surname="",
          int quiz_scores0=0, int quiz_scores1=0, int quiz_scores2=0, int quiz_scores3=0,
          int hw_scores0=0,int hw_scores1=0,int hw_scores2=0, int final_score=0);

    //getter methods
  string getName();
  string getSurname();
  int* getQuizScores();
  int* getHwScores();
  int getFinalScore();
  int getID();

    //setter methods
  void setName(string new_name);
  void setSurname(string new_surname);
  void setQuizScores(int *new_quiz_scores);
  void setHwScores(int *new_hw_scores);
  void setFinalScore(int new_final_score);
  void setID(int new_id);

    //Overall score of a student
  float overallCourseScore(float weightQ, float weightHW, float weightF);
};

    //Constructor
Student::Student(int id, string name, string surname,
        int quiz_scores0, int quiz_scores1, int quiz_scores2, int quiz_scores3,
        int hw_scores0,int hw_scores1,int hw_scores2, int final_score){
      this->id=id;
      this->name=name;
      this->surname=surname;
      this->quiz_scores[0]=quiz_scores0;this->quiz_scores[1]=quiz_scores1;this->quiz_scores[2]=quiz_scores2;this->quiz_scores[3]=quiz_scores3;
      this->hw_scores[0]=hw_scores0;this->hw_scores[1]=hw_scores1;this->hw_scores[2]=hw_scores2;
      this->final_score=final_score;
}

    //Getter functions
string Student::getName() {
    return name;
}
string Student::getSurname() {
    return surname;
}
int* Student::getQuizScores() {
    return quiz_scores;
}
int* Student::getHwScores() {
    return hw_scores;
}
int Student::getFinalScore() {
    return final_score;
}
int Student::getID() {
    return id;
}

    //Setter Functions
void Student::setName(string new_name){
    name=new_name;
}
void Student::setSurname(string new_surname){
    surname=new_surname;
}
void Student::setQuizScores(int* new_quiz_scores){
    quiz_scores[0]=new_quiz_scores[0];
    quiz_scores[1]=new_quiz_scores[1];
    quiz_scores[2]=new_quiz_scores[2];
    quiz_scores[3]=new_quiz_scores[3];
}
void Student::setHwScores(int* new_hw_scores){
    hw_scores[0]=new_hw_scores[0];
    hw_scores[1]=new_hw_scores[1];
    hw_scores[2]=new_hw_scores[2];;
}
void Student::setFinalScore(int new_final_score){
  final_score=new_final_score;
}
void Student::setID(int new_ID){
  id=new_ID;
}

    //Calculates the overall score of a student according to given weights.
float Student::overallCourseScore(float weightQ, float weightHW, float weightF){
    float avg;
    int* quiz_scores=getQuizScores();
    int* hw_scores=getHwScores();
    int final_=getFinalScore();
    avg = ((weightQ*(quiz_scores[0]+quiz_scores[1]+quiz_scores[2]+quiz_scores[3])/4)+(weightHW*(hw_scores[0]+hw_scores[1]+hw_scores[2])/3)+(weightF*final_score));//( weightQ+ weightHW+ weightF);
    return avg;
}

#endif
