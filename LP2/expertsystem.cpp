#include <iostream>
using namespace std;

int main() {

    char fever, cough, headache, stomachPain;
    char bodyPain, cold, vomiting, tiredness;

    cout << "===========================================\n";
    cout << "      HOSPITAL EXPERT SYSTEM\n";
    cout << "===========================================\n";

    cout << "\nAnswer the following questions (y/n)\n";

    // User Symptoms
    cout << "\nDo you have Fever? ";
    cin >> fever;

    cout << "Do you have Cough? ";
    cin >> cough;

    cout << "Do you have Headache? ";
    cin >> headache;

    cout << "Do you have Stomach Pain? ";
    cin >> stomachPain;

    cout << "Do you have Body Pain? ";
    cin >> bodyPain;

    cout << "Do you have Cold? ";
    cin >> cold;

    cout << "Do you have Vomiting? ";
    cin >> vomiting;

    cout << "Do you feel Tiredness? ";
    cin >> tiredness;

    cout << "\n===========================================\n";
    cout << "           MEDICAL REPORT\n";
    cout << "===========================================\n";

    // Rule-Based Expert System

    if(fever == 'y' && cough == 'y' && cold == 'y') {

        cout << "\nPossible Disease : Common Flu\n";
        cout << "Advice : Take proper rest and drink warm water.\n";
    }

    else if(fever == 'y' && headache == 'y' && bodyPain == 'y') {

        cout << "\nPossible Disease : Viral Fever\n";
        cout << "Advice : Consult a doctor and stay hydrated.\n";
    }

    else if(stomachPain == 'y' && vomiting == 'y') {

        cout << "\nPossible Disease : Food Poisoning\n";
        cout << "Advice : Avoid outside food and drink ORS.\n";
    }

    else if(cough == 'y' && tiredness == 'y') {

        cout << "\nPossible Disease : Throat Infection\n";
        cout << "Advice : Avoid cold drinks and take steam.\n";
    }

    else if(fever == 'y' && tiredness == 'y' && bodyPain == 'y') {

        cout << "\nPossible Disease : Dengue Symptoms\n";
        cout << "Advice : Immediate medical checkup recommended.\n";
    }

    else {

        cout << "\nNo major illness detected.\n";
        cout << "Maintain healthy lifestyle.\n";
    }

    cout << "\n===========================================\n";
    cout << " Thank You for Using Expert System\n";
    cout << "===========================================\n";

    return 0;
}