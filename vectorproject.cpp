#include<iostream>
#include<vector>
using namespace std;


template <class T>
class Student{
    private:
    T id;
    string name;
    public: 
      T stdid = id;
      string stdname = name;

      void addstudent(){
        cout << "Enter your id : " ;
        cin >> stdid;
         
         cout << "Enter your name : " ;
        cin >> stdname;

      }

      void displayStudent(){
        cout << "Student Id : " << stdid << endl;

        cout << "Student Name : " << stdname << endl;
      }


};


int main(){
  
 vector<Student<int>> students;
 int choice;

 do{
    cout << "--------Student Management System --------" << endl;
    cout <<"1. Add student details " << endl;
    cout <<"2. Display student details " << endl;
    cout <<"3. Search student details " << endl;
    cout <<"4. Remove student details " << endl;
    cout <<"5. Exit " << endl;

    cout << "Enter your choice : " ;
    cin >> choice;

    switch (choice){
        case 1: {
               Student<int> s;
               s.addstudent();
               students.push_back(s);
               cout <<"Student Added Successfully! " << endl;
               break; }

        case 2: {
              if(students.empty()){
                cout << " Student Detail is not available " << endl;
              }

              else{

                for(int i=0; i < students.size(); i++){
                students[i].displayStudent();
              }}
              break; }

        case 3:  {
             int studentid;
             cout << "Enter your id : ";
             cin >> studentid;

             bool found = false;

             for(int i=0; i < students.size(); i++){
                if(students[i].stdid == studentid){
                   students[i].displayStudent();
                    found = true;
                    break;
                }

              else{
                cout << "Student id not found!" << endl;
              }
             };
             break; }

        case 4: {
            int studentid;
             cout << "Enter your id : ";
             cin >> studentid;


             for(int i=0; i < students.size(); i++){
                if(students[i].stdid == studentid){
                   students.erase(students.begin() + i);
                   cout << "Student removed successfully! " << endl;
                }
                else{
                cout << "Student id not found!" << endl;
                }
                };
                break;  }

        case 5: {
             cout << "Program Exited Successfully!" << endl;
             break;  }
        
        default: 
            cout << "Enter Vaild Choice!" << endl;

    }
 } while (choice != 5);


}
