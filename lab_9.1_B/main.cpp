#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

enum Specialnist { KN, IT, MATH_AND_ECON, PH_AND_INF, LABOR_TRAINING};
string specialnistStr[] = {"KN", "IT", "MATH_AND_ECON","PH_AND_INF", "LABOR_TRAINING"};

struct Student
{
    string surname;
    unsigned course;
    Specialnist specialnist;
    unsigned physics;
    unsigned math;
    union
    {
        unsigned prog;
        unsigned nMethods;
        unsigned pedagogy;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Excellent(Student* p, const int N);
double AverangeScore(Student* p, const int  N);

int main() {
    cout<<"Enter N: ";
    int N;
    cin>>N;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    Excellent(p, N);
    cout<<"Percentage of students with a Grade Point Average greater than 4.5: ";
    cout<<AverangeScore(p,  N)<< "%"<< endl;
    return 0;
}



void Create(Student* p, const int N)
{
    int specialnist;

    for (int i = 0; i < N; i++)
    {
        cout << "Student № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " Surname : "; getline(cin, p[i].surname);
        cout << " Course: "; cin >> p[i].course;
        cout << " Specialnist (0 - KN, 1 - IT, 2 - MATH_AND_ECON, 3 - PH_AND_INF, 4 - LABOR_TRAINING):";
        cin >> specialnist;
        cout << " Assessment in physics : "; cin >> p[i].physics;
        cout << "Assessment in math    : "; cin >> p[i].math;
        p[i].specialnist = Specialnist(specialnist);
        
        switch (p[i].specialnist) {
            case KN :
                cout<< "Third grade in programming: "; cin>>p[i].prog;
                break;
            case IT :
                cout<<"Third grade in numerical methods:"; cin>>p[i].nMethods;
                break;
            case MATH_AND_ECON:
            case PH_AND_INF:
            case LABOR_TRAINING:
                cout<<"Third grade in pedagogy: "; cin>>p[i].pedagogy;
                break;
                
        }
        cout << endl;
    }
}


void Print(Student* p, const int N)
{
    cout << "========================================================================================================"
        << endl;
    cout << "| № | Surname | Course | Spec | Score in PH | Score in MATH | Score in prog | Score in numerical methods | Score in pedagogy |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(9) << left << p[i].surname
            << "| " << setw(4) << right << p[i].course << " "
            << "| " << setw(14) << left << specialnistStr[p[i].specialnist]
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(10) << left << p[i].math << " ";
        switch (p[i].specialnist)
        {
        case KN:
            cout << "| " << setw(13) << right << p[i].prog << " " << "|" << setw(14) << "|" << setw(13) << "|";
            break;
        case IT:
            cout << "|" << setw(16) << right << fixed << "|" << setw(13) << left << p[i].nMethods << "|" << setw(11) << right << " " << " |";
            break;
        case MATH_AND_ECON:
        case PH_AND_INF:
        case LABOR_TRAINING:
            cout << "|" << setw(17) << right << fixed << "| " << setw(12) << left << " " << "| " << setw(11) << right << p[i].pedagogy << "|";
            break;
        }
        cout << endl;
    }
    cout << "========================================================================================================"
        << endl;
    cout << endl;
}




void Excellent(Student* p, const int N)
{
    for(int i = 0; i < N; i++)
    {
        if(p[i].math == 5  && p[i].physics == 5 && p[i].pedagogy ==5 && p[i].prog && p[i].nMethods)
        {
            cout<<" Excellent student among students is : "<<p[i].surname<<endl;
        }
    }
}


double AverangeScore(Student* p, const int  N)
{
    double AverangeScore = 0.0;
    int res = 0.0;
    
    for(int i = 0 ; i < N; i++)
    {
        AverangeScore = (p[i].physics + p[i].pedagogy + p[i].math + p[i].prog + p[i].nMethods) / 5;
        
        if(AverangeScore > 4.5)
        {
            res++;
        }
    }
    
    return 100.0 * res / N;
}
