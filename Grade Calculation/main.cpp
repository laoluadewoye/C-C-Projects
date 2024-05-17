#include <iostream>
#include <vector>

using namespace std;

void calculation(double pr, double hw, double pa, double tst, double fe)
{
    double finalPR = pr * 0.3;
    double finalHW = hw * 0.1;
    double finalPA = pa * 0.2;
    double finalTST = tst * 0.1;
    double finalEX = fe * 0.3;
    
    double finalGrade = finalPR + finalHW + finalPA + finalTST + finalEX;
    
    cout << "The current grade is " << finalGrade << "%" << endl;
    cout << "End of Program.";
}

int main()
{
    //declaration
    int gradeType, actGrade;
    string decision;
    bool infinite = true;
    double aveProject, aveHomework, avePaper, aveTest;
    double finalExam = 0;
    vector<double> project;
    vector<double> homework;
    vector<double> paper;
    vector<double> test;
    
    //input and calculation
    while (infinite == true) 
    {
        cout << "What Type of grade do you want to put in?" << endl;
        cout << "(1)Project, (2)Homework, (3)Paper, (4)Test, (5)FinalExam" << endl;
        cin >> gradeType;
        cout << "What is the grade?" << endl;
        cin >> actGrade;
        
        if (gradeType == 1)
        {
            project.push_back(actGrade);
            double sum = 0;
            int i = 0;
            while(i < project.size())
            {
                sum = sum + project[i];
                i++;
            }
            aveProject = sum / project.size();
        }
        else if (gradeType == 2)
        {
            homework.push_back(actGrade);
            double sum = 0;
            int i = 0;
            while(i < homework.size())
            {
                sum = sum + homework[i];
                i++;
            }
            aveHomework = sum / project.size();;
        }
        else if (gradeType == 3)
        {
            paper.push_back(actGrade);
            double sum = 0;
            int i = 0;
            while(i < paper.size())
            {
                sum = sum + paper[i];
                i++;
            }
            avePaper = sum / project.size();;
        }
        else if (gradeType == 4)
        {
            test.push_back(actGrade);
            double sum = 0;
            int i = 0;
            while(i < test.size())
            {
                sum = sum + test[i];
                i++;
            }
            aveTest = sum / project.size();;
        }
        else if (gradeType == 5)
        {
            if (finalExam != 0)
            {
                cout << "Are you sure you wanted to override this grade? (yes/no)" << endl;
                cin >> decision;
                if (decision == "yes") 
                {
                    finalExam = actGrade;
                }
            }
            else 
            {
                finalExam = actGrade;
            }
        }
        
        cout << "Do you want to keep putting in grades? (yes/no)" << endl;
        cin >> decision;
        if (decision == "no")
        {
            infinite = false;
        }
    }
    
    //output
    calculation(aveProject, aveHomework, avePaper, aveTest, finalExam);

    return 0;
}


