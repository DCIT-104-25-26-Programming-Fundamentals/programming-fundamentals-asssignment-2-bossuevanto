// =============================================================================
//// Struct to store student records
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;


struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to clear input buffer when switching between cin >> and getline()
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function to calculate average score from a vector of scores
double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// FEATURE 1: Add a Student
void addStudent(vector<Student>& students) {
    Student s;

    clearInputBuffer(); // Clear leftover newline
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// FEATURE 2: Display All Students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }

    cout << "\n-------------------------------------------------------------------\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << "Average\n";
    cout << "-------------------------------------------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(20) << s.name 
             << setw(12) << s.id;

        // Build a display string for scores (e.g., "78, 85, 90")
        string scoreStr = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoreStr += to_string(static_cast<int>(s.scores[i]));
            if (i < s.scores.size() - 1) scoreStr += ", ";
        }
        
        cout << setw(20) << scoreStr;
        cout << fixed << setprecision(2) << calculateAverage(s.scores) << "\n";
    }
    cout << "-------------------------------------------------------------------\n";
}

// FEATURE 3: Calculate Average Score for a Specific Student
void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available.\n";
        return;
    }

    int targetId;
    cout << "Enter student ID: ";
    cin >> targetId;

    for (const auto& s : students) {
        if (s.id == targetId) {
            double avg = calculateAverage(s.scores);
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << avg << "\n";
            return;
        }
    }

    cout << "Error: Student ID " << targetId << " not found.\n";
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU   \n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select an option between 1 and 4.\n";
                break;
        }
    }

    return 0;
}