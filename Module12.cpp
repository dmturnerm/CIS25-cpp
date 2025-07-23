#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Class that represents one row (student) from the dataset
class StudentRecord {
public:
    string gender;
    string ethnicity;
    string parentalEducation;
    string lunch;
    string testPrep;
    int mathScore;
    int readingScore;
    int writingScore;

    // Constructor to break up CSV line
    StudentRecord(const string &line) {
        stringstream ss(line);
        string field;
        vector<string> fields;

        // Split line by comma
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        // Assign values from the csv fields
        if (fields.size() >= 8) {
            gender = fields[0];
            ethnicity = fields[1];
            parentalEducation = fields[2];
            lunch = fields[3];
            testPrep = fields[4];
            mathScore = stoi(fields[5]);
            readingScore = stoi(fields[6]);
            writingScore = stoi(fields[7]);
        }
    }

    // Function to print 
    void display() const {
        cout << "Gender: " << gender
             << ", Ethnicity: " << ethnicity
             << ", Parent Education: " << parentalEducation
             << ", Lunch: " << lunch
             << ", Test Prep: " << testPrep
             << ", Math: " << mathScore
             << ", Reading: " << readingScore
             << ", Writing: " << writingScore
             << endl;
    }
};

int main() {
    ifstream file("StudentsPerformance.csv"); 
    if (!file.is_open()) {
        cerr << "Could not open the CSV file!" << endl;
        return 1;
    }

    string line;
    vector<StudentRecord> students;
    int rowCount = 0;

    // Skip header
    getline(file, line);

    // Load up to 10 rows from the file
    while (getline(file, line) && rowCount < 10) {
        StudentRecord student(line);
        students.push_back(student);
        rowCount++;
    }

    file.close();

    // Displays student records
    cout << "\n--- Loaded Student Records ---\n" << endl;
    for (const auto &student : students) {
        student.display();
    }

    return 0;
}