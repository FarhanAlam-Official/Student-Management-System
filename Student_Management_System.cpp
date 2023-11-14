#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>
#include<string.h>
#include<conio.h>
#include <map>

using namespace std;

map<int, string> courseMap =
{
    {1, "Technical_Writing"},
    {2, "Public_Speaking"},
    {3, "Entrepreneurship"},
    {4, "Web_Development"},
    {5, "Mobile_App_Development"},
    {6, "Foreign_Language"}
};

void headmsg(char msg[100])
{
    system("cls");  // Clear the console screen
    system("color a");  // Change the system font color
    cout << "\t\t\t\t*********************************************************************************************************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t**********************                STUDENT MANAGEMENT SYSTEM PROJECT            **********************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t*********************************************************************************************************\n";
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t     **** " << msg << " ****\n";  // Display the page message
}

void line(int n, int t)
{
    int i;
    cout << "\v\v\v";
    for (i = 0; i < n; i++)
    {
        if (i < t)    // To display tab space initially before printing line
        {
            cout << "\t";
        }
        else
        {
            cout << "===";  // Print line using = symbol
        }
    }
}
void delay(int nanoseconds)
{
    int i;
    for (i = 0; i < nanoseconds; i++)
    {
        int k = k + i;
    }
}

int otp_generator()
{
    // Set a new seed value based on the current time
    srand(static_cast<unsigned>(time(0)));

    // Generate a random integer between 100000 and 999999
    int g_otp = rand() % (999999 - 100000 + 1) + 100000;

    return g_otp;
}
// Function to check the OTP
void otp_check()
{
    int user_otp, otp;
    do
    {
        system("cls");
        headmsg("Login Page"); // Display the login page header
        line(31, 6);          // Draw a line

        // Generate a random OTP and display it to the user
        otp = otp_generator();
        cout << "\n\n\t\t\t\t\t\t\t\t Your OTP is " << otp;
        cout << "\n\n\t\t\t\t\t   OTP:";
        cin >> user_otp; // Get user input for OTP

        // Compare user-provided OTP with generated OTP
        if (user_otp == otp)
        {
            cout << "\n\n\t\t\t\t\t\t\t\t  PLEASE WAIT VERIFYING"; // Display "Verifying" message with a loading animation
            for (int i = 0; i < 4; i++)
            {
                delay(400000000);
                cout << ".";
            }
            return ;
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\t   Incorrect OTP !!! TRY AGAIN";
            delay(5000000000); // Delay to provide user feedback
        }
    }
    while (true);   // Run loop infinitely until the OTP matches
}
// Function to perform user login
int authenticateUser(const char* userType, char enteredUser[], char enteredPass[])
{
    char filename[30];
    strcpy(filename, userType);
    strcat(filename, "userpassword.dat");

    ifstream userFile(filename);

    if (!userFile.is_open())
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\a Error: Unable to open user file.\n";
        return 0;
    }

    int storeid=0;
    char storedUser[20], storedPass[16];
    while (userFile >> storeid>> storedUser >> storedPass)
    {

        if (strcmp(enteredUser, storedUser) == 0 && strcmp(enteredPass, storedPass) == 0)
        {
            otp_check();
            if (strcmp(userType, "admin") == 0)
            {
                return 1; // Admin login successful
            }
            else if (strcmp(userType, "student") == 0) // Ensure "student" is used here
            {
                return 2; // Student login successful
            }
        }
    }

    return 0; // No matching credentials found
}

int login()
{
    system("cls");

    const int MAX_ATTEMPTS = 3;
    int attempts = MAX_ATTEMPTS;
    int val = 0;
    int h=0;
    char userType[10];
    char enteredUser[20], enteredPass[16];

    while (attempts > 0)
    {
        headmsg("Login Page");
        line(31, 5);

        int userTypeChoice;
        do
        {
            if (h!=0)
            {
                system("cls");
                headmsg("Login Page");
                line(31, 5);
            }
            cout << "\n\n\n\t\t\t\t\t\t\t\t\t Who are you??\n\n\n";
            cout << "\t\t\t\t\t\t 1. Admin \t\t\t\t 2. Student\n\n\n";
            cout << "\t\t\t\t\t\t Enter your choice (1 or 2): ";
            cin >> userTypeChoice;

            if (userTypeChoice == 1)
            {
                strcpy(userType, "admin");
            }
            else if (userTypeChoice == 2)
            {
                strcpy(userType, "student");
            }
            else
            {
                h++;
                cout << "\n\t\t\t\t\t\t\t\a Invalid choice. Please enter 1 or 2.\n";
                delay(800000000);
                continue;
            }
        }while (userTypeChoice != 1 && userTypeChoice != 2);

        cout << "\n\n\n\t\t\t\t\t\t Username: ";
        cin >> enteredUser;
        cout << "\n\n\n\t\t\t\t\t\t Password: ";
        cin >> enteredPass;

        cout << "\n\n\t\t\t\t\t\t\t\t  PLEASE WAIT VERIFYING";

        for (int i = 0; i < 4; i++)
        {
            delay(400000000);
            cout << ".";
        }

        val = authenticateUser(userType, enteredUser, enteredPass);

        if (val != 0)
        {
            cout << "\n\n\t\t\t\t\t\t\t      " << userType << " Login Successful!!\n";
            delay(50000000);
            return val;
        }
        else
        {
            attempts--;
            cout << "\v\n\t\t\t\t\t\t\t\a Incorrect credentials! Please try again.\n";
            cout << "\n\t\t\t\t\t\t\t          " << attempts << " attempts remaining...\n";
            delay(600000000);
        }
    }

    if (attempts == 0)
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t\t             Too many unsuccessful attempts!!!\n";
        cout << "\n\n\t\t\t\t\t\t   Account has been blocked. Please try again after 24 hours.\n";
        cout << "\n\n\t\t\t\t Press any key to continue....";
        getch();
        return 0;
    }
}
void Close_app()
{
    system("cls"); // Clear the console screen
    cout<<"\n\n\t\t\t\t\t\t      THANK YOU FOR USING OUR APPLICATION !!!!";
    cout<<"\n\n\t\t\t\t\t\t Copyright \xC2\xA9  2023 Alam Group, All rights reserved.";
    cout<<"\n\n\t This material may not be reproduced, displayed, modified, or distributed without the express prior written permission of Alam Group \n\n";
    cout<<"\n\n\t\t\t\t\t----------------------- -Developed by Farhan Alam-------------------------"<<endl<<endl<<endl;
}

class commonfunctions
{

protected:

    //Student details data members
    int Student_Id, Age,Roll_number;
    string Name, Parent_name, Phone_number, Address, Gender,Username,Password;

    //existing data member of student
    int existingStudentId, existingAge,existingRoll_number;
    string existingName, existingParent_name, existingPhone_number, existingAddress, existingGender,existingUsername,existingPassword;

        //existing data member of admin
 int existingAdmin_Id;

 public:
    //member functions
    void Generate_Report();
    void EnrollStudentInCourses();
    void DisplayCourseList();
};
void commonfunctions::Generate_Report()
{
    ifstream marksfile("studentmarks.dat", ios::in);

    // Check if the file was opened successfully
    if (!marksfile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the studentmarks.dat file..!!";
        return;
    }

    // Define subject names
    string subjectNames[] = {"DSA", "OOP", "ACCOUNT-II", "MICROPROCESSOR", "SAD"};

    system("cls"); // Clear the console screen
    headmsg("STUDENT PERFORMANCE REPORT"); // Display the header
    line(35, 0); // Draw a line

    cout <<endl<< left << setw(15) << "Student ID" << setw(20) << "Total Marks" << setw(20) << "Percentage(%)" << setw(10) << "Grade"
         << setw(20) << "Weak Subject" << setw(20) << "Strong Subject" << endl;

    cout << setfill('-') << setw(108) << "-" << setfill(' ') << endl;

    while (marksfile >> Student_Id >> Name)
    {
        cout << left << setw(15) << Student_Id;

        double marks[5];
        double totalMarks = 0.0;
        double percentage;
        char grade;
        int weakSubject = 1, strongSubject = 1;  // Initialize to the first subject

        // Read marks for each subject
        for (int i = 0; i < 5; ++i)
        {
            marksfile >> marks[i];
            totalMarks += marks[i];

            // Update weak subject
            if (marks[i] < marks[weakSubject - 1])
            {
                weakSubject = i + 1;  // Subjects are 1-indexed
            }

            // Update strong subject
            if (marks[i] > marks[strongSubject - 1])
            {
                strongSubject = i + 1;  // Subjects are 1-indexed
            }
        }

        // Calculate percentage
        percentage = totalMarks / 5.0;

        // Determine grade
        if (percentage >= 90.0)
        {
            grade = 'A';
        }
        else if (percentage >= 80.0)
        {
            grade = 'B';
        }
        else if (percentage >= 70.0)
        {
            grade = 'C';
        }
        else if (percentage >= 60.0)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }

        cout << fixed << setprecision(2) << setw(20) << totalMarks << setw(20) << (percentage) << setw(10) << grade
             << setw(20) << subjectNames[weakSubject - 1] << setw(20) << subjectNames[strongSubject - 1] << endl;
    }
    cout<<"=========================================================================================================";

    cout<<"\n \n Press any key to return to main menu....";
    getch();
    marksfile.close();
}
void commonfunctions::DisplayCourseList() {
    cout << "\nAvailable Courses:\n";
    cout << "1. Technical Writing\n";
    cout << "2. Public Speaking\n";
    cout << "3. Entrepreneurship\n";
    cout << "4. Web Development\n";
    cout << "5. Mobile App Development\n";
    cout << "6. Foreign Language (French, German, Spanish, etc.)\n";
}
void commonfunctions::EnrollStudentInCourses()
{
    system("cls");
    headmsg("COURSES ENROLLMENT");
    line(32,5);
    int searchStudentID = 0;
    ifstream coursesFile("studentcourses.dat", ios::in);

    if (!coursesFile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the studentcourses.dat file..!!";
        return;
    }

    cout << "\nEnter Student ID: ";
    cin >> searchStudentID;

    // Display the current enrollment status
    cout << "\nCurrent Enrollment for Student ID " << searchStudentID << ":\n";
    bool studentFound = false;
    string line;
    while (getline(coursesFile, line))
    {
        istringstream iss(line);
        iss >> Student_Id >> Name;

        if (iss.fail())
        {
            cout << "\nError reading student information from the file.\n";
            delay(50000000);
            return;
        }

        if (Student_Id == searchStudentID)
        {
            cout << " - " << Name << " (" << Student_Id << "): " << line.substr(line.find(' ') + 1) << endl;
            studentFound = true;
            break;
        }
    }

    if (!studentFound)
    {
        cout << "Student ID " << searchStudentID << " not found.\n";
        delay(50000000);
        return;
    }

    coursesFile.close();

    // Display the course list
    DisplayCourseList();

    cout << "Enter the course numbers to enroll (comma-separated): ";
    cin.ignore();
    getline(cin, line);

    // Check if the student is already enrolled in some courses
    string currentCourses;
    bool studentEnrolled = false;

    ifstream readFile("studentcourses.dat", ios::in);

    ofstream tempFile("temp.dat");

    while (getline(readFile, currentCourses))
    {
        istringstream iss(currentCourses);
        iss >> Student_Id >> Name;

        if (Student_Id == searchStudentID)
        {
            // Found the student, append the new courses
            studentEnrolled = true;
            tempFile << Student_Id << ' ' << Name << ' ';

            // Extract existing courses
            string existingCourses;
            getline(iss, existingCourses);

            // If the student is not already enrolled, add a comma before appending the new courses
            if (!existingCourses.empty())
            {
                tempFile << existingCourses;

                // Add a comma only if there are existing courses
                if (!line.empty())
                {
                    tempFile << ',';
                }
            }

// Split the input line into course numbers
            istringstream courseStream(line);
            string courseNumber;
            bool firstCourse = true;  // Flag to avoid adding comma before the first course
            while (getline(courseStream, courseNumber, ','))
            {
                int num = stoi(courseNumber);
                if (courseMap.find(num) != courseMap.end())
                {
                    if (!firstCourse)
                    {
                        tempFile << ',';
                    }
                    tempFile << courseMap[num];  // Enroll course name in tempFile
                    firstCourse = false;
                }
                else
                {
                    cout << "Invalid course number: " << num << endl;
                }
            }

            tempFile << endl;
        }
        else
        {
            tempFile << currentCourses << endl;
        }
    }

    readFile.close();

    if (!studentEnrolled)
    {
        // If the student is not enrolled in any courses, add a new entry
        tempFile << Student_Id << ' ' << Name << ' ';

        // Split the input line into course numbers
        istringstream courseStream(line);
        string courseNumber;
        while (getline(courseStream, courseNumber))
        {
            int num = stoi(courseNumber);
            if (courseMap.find(num) != courseMap.end())
            {
                tempFile <<courseMap[num];  // Enroll course name in tempFile
            }
            else
            {
                cout << "Invalid course number: " << num << endl;
            }
        }

        tempFile << endl;
    }

    cout << "\nStudent enrolled in courses successfully!\n";

    tempFile.close();

    // Ask if the user wants to add courses for another student
    cout << "Do you want to add courses for another student? (y/n): ";
    char choice;
    cin >> choice;

    if (tolower(choice) == 'y')
    {
        remove("studentcourses.dat");
        rename("temp.dat", "studentcourses.dat");
        EnrollStudentInCourses(); // Recursive call
    }
    else
    {
        cout<<"\n \n Press any key to return to main menu....";
    getch();
        // Remove the original file and rename the temporary file
        remove("studentcourses.dat");
        rename("temp.dat", "studentcourses.dat");
    }
}

class Student:public commonfunctions
{
public:
    void Generate_Performance_Report();
    void Display_Student_Report();
    void Edit_Student_Account_Student();


};
void Student::Generate_Performance_Report()
{
    system("cls");
    headmsg("STUDENT PERFORMANCE REPORT");
    line(32,5);
    cout << "\n \n Enter Student ID to generate the performance report: ";
    int searchStudentID;
    cin >> searchStudentID;

    ifstream marksfile("studentmarks.dat", ios::in);

    // Check if the file was opened successfully
    if (!marksfile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the studentmarks.dat file..!!";
        return;
    }

    bool studentFound = false;

    while (marksfile >> Student_Id >> Name)
    {
        if (Student_Id == searchStudentID)
        {
            studentFound = true;
            cout << "\n=========================================================================================================";
            cout << "\n\t\t\t\t\t STUDENT PERFORMANCE REPORT";
            cout << "\n=========================================================================================================";
            cout << "\nStudent ID: " << Student_Id;
            cout << "\nName: " << Name << endl;

            double marks[5];
            double totalMarks = 0.0;
            double percentage;
            char grade;
            int weakSubject = 1, strongSubject = 1;  // Initialize to the first subject

            // Read marks for each subject
            for (int i = 0; i < 5; ++i)
            {
                marksfile >> marks[i];
                totalMarks += marks[i];

                // Update weak subject
                if (marks[i] < marks[weakSubject - 1])
                {
                    weakSubject = i + 1;  // Subjects are 1-indexed
                }

                // Update strong subject
                if (marks[i] > marks[strongSubject - 1])
                {
                    strongSubject = i + 1;  // Subjects are 1-indexed
                }
            }

            // Calculate percentage
            percentage = totalMarks / 5.0;

            // Determine grade
            const double gradeA = 90.0;
            const double gradeB = 80.0;
            const double gradeC = 70.0;
            const double gradeD = 60.0;

            if (percentage >= gradeA)
            {
                grade = 'A';
            }
            else if (percentage >= gradeB)
            {
                grade = 'B';
            }
            else if (percentage >= gradeC)
            {
                grade = 'C';
            }
            else if (percentage >= gradeD)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }

            // Subject names
            string subjectNames[] = {"DSA", "OOP", "ACCOUNT-II", "MICROPROCESSOR", "SAD"};

            cout << fixed << setprecision(2);
            cout << "=========================================================================================================";
            cout << "\nSubject-wise Marks:\n";
            cout << setw(15) << "Subject" << setw(15) << "Marks" << endl;
            for (int i = 0; i < 5; ++i)
            {
                cout << setw(15) << subjectNames[i] << setw(15) << marks[i] << endl;
            }

            cout << "\nTotal Marks: " << totalMarks;
            cout << "\nPercentage: " << percentage<<"%";
            cout << "\nGrade: " << grade;
            cout << "\nWeak Subject: " << subjectNames[weakSubject - 1];
            cout << "\nStrong Subject: " << subjectNames[strongSubject - 1] << endl;
            cout << "=========================================================================================================";
        }
        else
        {
            // Skip reading marks for other students
            marksfile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout<<"\n Press any key to return to main menu....";
    getch();
    marksfile.close();

    if (!studentFound)
    {
        cout << "\n\n\t\t\t\t !! Student ID not found. Report not available.";
    }
}

void Student::Display_Student_Report() {
    system("cls"); // Clear the console screen
    headmsg("STUDENT PERFORMANCE REPORT"); // Display the header
    line(32, 5); // Draw a line
    ifstream marksfile("studentmarks.dat", ios::in);

    // Check if the file was opened successfully
    if (!marksfile.is_open()) {
        cout << "\n\n\t\t\t\t !!Error loading the studentmarks.dat file..!!";
        return;
    }

    // Define subject names
    string subjectNames[] = {"DSA", "OOP", "ACCOUNT-II", "MICROPROCESSOR", "SAD"};

    int searchStudentID;
    cout << "\n\n\t\t\t\t\t Enter Student ID to Display Report: ";
    cin >> searchStudentID;
    cout<<"=========================================================================================================";

    cout <<endl<< left << setw(15) << "Student ID" << setw(20) << "Total Marks" << setw(20) << "Total Percentage" << setw(10) << "Grade"
         << setw(20) << "Weak Subject" << setw(20) << "Strong Subject" << endl;
    cout << setfill('-') << setw(105) << "-" << setfill(' ') << endl;

    bool studentFound = false;

    while (marksfile >> Student_Id >> Name) {
        if (Student_Id == searchStudentID) {
            studentFound = true;
            cout << left << setw(15) << Student_Id;

            double marks[5];
            double totalMarks = 0.0;
            double percentage;
            char grade;
            int weakSubject = 1, strongSubject = 1;  // Initialize to the first subject

            // Read marks for each subject
            for (int i = 0; i < 5; ++i) {
                marksfile >> marks[i];
                totalMarks += marks[i];

                // Update weak subject
                if (marks[i] < marks[weakSubject - 1]) {
                    weakSubject = i + 1;  // Subjects are 1-indexed
                }

                // Update strong subject
                if (marks[i] > marks[strongSubject - 1]) {
                    strongSubject = i + 1;  // Subjects are 1-indexed
                }
            }

            // Calculate percentage
            percentage = totalMarks / 5.0;

            // Determine grade
            if (percentage >= 90.0) {
                grade = 'A';
            } else if (percentage >= 80.0) {
                grade = 'B';
            } else if (percentage >= 70.0) {
                grade = 'C';
            } else if (percentage >= 60.0) {
                grade = 'D';
            } else {
                grade = 'F';
            }
            cout<< fixed << setprecision(2) << setw(20) << totalMarks << setw(20) << (percentage) << setw(10) << grade
                 << setw(20) << subjectNames[weakSubject - 1] << setw(20) << subjectNames[strongSubject - 1] << endl;
    cout<<"=========================================================================================================";

        }
        else {
            // Skip reading marks for other students
            marksfile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout<<"\n \n Press any key to return to main menu....";
    getch();
    marksfile.close();

    if (!studentFound) {
        cout << "\n\n\t\t\t\t !! Student ID not found. Report not available.";
    }
}

void Student:: Edit_Student_Account_Student()
{
    int test = 0;
    char choice;
    int checkStudent_Id = 0;

    while (true)
    {
        ifstream infile("student.dat", ios::in);
        ofstream outfile("new.dat", ios::out);

        // Check if the file was opened successfully
        if (!infile.is_open() || !outfile.is_open())
        {
            cout << "\n\n\t\t\t\t !!Error loading the file..!!";
            return;
        }
        system("cls"); // Clear the console screen
        headmsg("UPDATING DETAILS"); // Display the header
        line(32, 5); // Draw a line

        cout << "\n\t\t\t\t\t\t     Please provide Student Id to update its details" << endl;
        cout << "\n\n\n\t\t\t\t\t Student Id:";
        cin >> checkStudent_Id;

        infile.clear(); // Clear the error state of the file
        infile.seekg(0, ios::beg);

        while (infile >> existingStudentId >> existingName >> existingAge >> existingParent_name
                >> existingPhone_number >> existingAddress >> existingRoll_number >> existingGender)
        {
            if (checkStudent_Id == existingStudentId)
            {
                test++;
                // Display existing details
                cout << "\n\t\t\t\t\t\t Student Current Details" << endl;
                cout << "Student ID: " << existingStudentId << endl;
                cout << "Name: " << existingName << endl;
                cout << "Age: " << existingAge << endl;
                cout << "Parent Name: " << existingParent_name << endl;
                cout << "Phone Number: " << existingPhone_number << endl;
                cout << "Address: " << existingAddress << endl;
                cout << "Roll Number: " << existingRoll_number << endl;
                cout << "Gender: " << existingGender << endl << endl;

                cout << "Do you want to update details[Y/N]? ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    // User wants to update, so take new data

                    cout << "Enter Age: ";
                    cin >> existingAge;


                    cout << "Enter Phone Number: ";
                    cin >> existingPhone_number;

                    cout << "Enter Address: ";
                    cin >> existingAddress;

                }

                // Write the data to the new file
                outfile << existingStudentId << ' ' << existingName << ' ' << existingAge << ' '
                        << existingParent_name << ' ' << existingPhone_number << ' ' << existingAddress << ' '
                        << existingRoll_number << ' ' << existingGender << endl;
            }
            else
            {
                // If the student ID doesn't match, write to the new file as is
                outfile << existingStudentId << ' ' << existingName << ' ' << existingAge << ' '
                        << existingParent_name << ' ' << existingPhone_number << ' ' << existingAddress << ' '
                        << existingRoll_number << ' ' << existingGender << endl;
            }
        }

        // If the test is 0, account record was not found
        if (test == 0)
        {
            infile.close(); // Close the original file
            outfile.close(); // Close the new file
            remove("student.dat");     // Remove the file student.dat
            rename("new.dat", "student.dat"); // Rename the new.dat to student.dat
            cout << "\n\n\n\n\a\t\t\t\t\t\t\t\t        Record not found!!!";
            cout << "\n\n\t\t\t\t\t\t\t\t Please check credentials properly!";
            delay(50000000);
            cout << "\n\n\t\t\t\t\t\t\t Press T to try again and any key to return to the main menu....";
            char try_return;
            cin >> try_return;

            // If the user wants to try again, continue the loop
            if (try_return == 't' || try_return == 'T')
            {
                continue;
            }
            else
            {
                break; // Exit the loop if the user doesn't want to try again
            }
        }
        else
        {
            infile.close(); // Close the original file
            outfile.close(); // Close the new file
            remove("student.dat");     // Remove the file student.dat
            rename("new.dat", "student.dat"); // Rename the new.dat to student.dat
            cout << "\n\n\t\t\t\t\t\t Press any key to return to the main menu....";
            getch(); // Use cin.get() instead of getch()
            break;     // Exit the loop when the operation is completed
        }
    }
}

class Admin:public commonfunctions
{
private:
    //Admin details data members
    int Admin_Id, Age;
    string Name, Phone_number, Address, Username, Password;

public:
    void Create_Student_Account();
    void Edit_Student_Account_Admin();
    void Delete_Account(int studentIdToDelete);
    void Delete_Student_Account();
    void View_All_Student_Accounts();
    void Update_Username_Password(int userIdToUpdate, string newUsername, string newPassword, int userType);
    void Reset_Password();
    void Create_Admin_Account();
    vector<string> split(const string &s, char delimiter);
    void Attendance();

};
void Admin::Create_Student_Account()
{
    char try_return;
    int checkStudent_Id = 0;

    // Open the student.dat file in append and read mode
    ifstream studentFileRead("student.dat");

    ofstream studentFileAppend("student.dat" ,ios::out | ios::app);

    // Open the studentuserpassword.dat file in append and read mode
    ifstream userPasswordFileRead("studentuserpassword.dat");

    // Open the studentuserpassword.dat file in append mode
    ofstream userPasswordFileAppend("studentuserpassword.dat", ios::app);

    ofstream studentCourse("studentcourses.dat", ios::app);

    // Check if the files were opened successfully
    if (!studentFileRead.is_open() || !userPasswordFileRead.is_open() || !userPasswordFileAppend.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the files..!!" << endl;
        delay(50000000);
        return;
    }

    while (true)
    {
        system("cls"); // Clear the console screen
        headmsg("New Student Form");
        line(32, 5);
        int record_found = 0;

        cout << "\n Enter Student ID: ";
        cin >> checkStudent_Id;

        // Check if the Student ID already exists in student.dat
        studentFileRead.seekg(0, ios::beg);
        while (studentFileRead >> existingStudentId >> existingName >> existingAge >> existingParent_name
                >> existingPhone_number >> existingAddress >> existingRoll_number >> existingGender)
        {
            if (checkStudent_Id == existingStudentId)
            {
                record_found = 1;
                break;
            }
        }

        // Check if the Student ID already exists in studentuserpassword.dat
        userPasswordFileRead.seekg(0, ios::beg);
        while (userPasswordFileRead >> existingStudentId >> existingUsername >> existingPassword)
        {
            if (checkStudent_Id == existingStudentId)
            {
                record_found = 1;
                break;
            }
        }

        if (record_found == 1)
        {
            cout << "\n\n\t\t\t\t\t\t\t       Student Id already in use !!" << endl;
            cout << "\n\n\t\t\t\t\t\t\t Press T to try again and any key to return to the main menu...." << endl;
            cin >> try_return;

            if (try_return == 't' || try_return == 'T')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, Name);

            cout << "Enter Age: ";
            cin >> Age;

            cout << "Enter Parent Name: ";
            cin.ignore();
            getline(cin, Parent_name);

            cout << "Enter Phone Number: ";
            cin >> Phone_number;

            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, Address);

            cout << "Enter Roll Number: ";
            cin >> Roll_number;

            cout << "Enter Gender (M/F): ";
            cin >> Gender;

            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;

            // Append the new student record to the studentuserpassword.dat file
            userPasswordFileAppend << checkStudent_Id << ' ' << Username << ' ' << Password << endl;

            // Append the new student record to the student.dat file
            studentFileAppend << checkStudent_Id << ' ' << Name << ' ' << Age << ' ' << Parent_name << ' '
                        << Phone_number << ' ' << Address << ' ' << Roll_number << ' ' << Gender << endl;

                        string common_course="Web_Development";

            studentCourse << checkStudent_Id << ' ' << common_course <<endl;

            cout << "\n\n\n\t\t\t\t\t\t\t\t  **** Student Account created successfully ****" << endl;
            cout << "\n\n\t\t\t\t\t\t\t Press A to add more records and any key to return to the main menu...." << endl;
            cin >> try_return;

            if (try_return == 'a' || try_return == 'A')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    // Close all files
    studentFileRead.close();
    studentFileAppend.close();
    studentCourse.close();
    userPasswordFileRead.close();
    userPasswordFileAppend.close();
}

void Admin::Edit_Student_Account_Admin()
{
    int test = 0;
    char choice;
    int checkStudent_Id = 0;

    while (true)
    {
        ifstream infile("student.dat", ios::in);
        ofstream outfile("new.dat", ios::out);

        // Check if the file was opened successfully
        if (!infile.is_open() || !outfile.is_open())
        {
            cout << "\n\n\t\t\t\t !!Error loading the file..!!";
            return;
        }
        system("cls"); // Clear the console screen
        headmsg("UPDATING DETAILS"); // Display the header
        line(32, 5); // Draw a line

        cout << "\n\t\t\t\t\t\t     Please provide Student Id to update its details" << endl;
        cout << "\n\n\n\t\t\t\t\t Student Id:";
        cin >> checkStudent_Id;

        infile.clear(); // Clear the error state of the file
        infile.seekg(0, ios::beg);

        while (infile >> existingStudentId >> existingName >> existingAge >> existingParent_name
                >> existingPhone_number >> existingAddress >> existingRoll_number >> existingGender)
        {
            if (checkStudent_Id == existingStudentId)
            {
                test++;
                // Display existing details
                cout << "\n\t\t\t\t\t\t Student Current Details" << endl;
                cout << "Student ID: " << existingStudentId << endl;
                cout << "Name: " << existingName << endl;
                cout << "Age: " << existingAge << endl;
                cout << "Parent Name: " << existingParent_name << endl;
                cout << "Phone Number: " << existingPhone_number << endl;
                cout << "Address: " << existingAddress << endl;
                cout << "Roll Number: " << existingRoll_number << endl;
                cout << "Gender: " << existingGender << endl << endl;

                cout << "Do you want to update details[Y/N]? ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    // User wants to update, so take new data
                    cout << "Enter Student Name: ";
                    cin >> existingName;

                    cout << "Enter Age: ";
                    cin >> existingAge;

                    cout << "Enter Parent Name: ";
                    cin >> existingParent_name;

                    cout << "Enter Phone Number: ";
                    cin >> existingPhone_number;

                    cout << "Enter Address: ";
                    cin >> existingAddress;

                    cout << "Enter Roll Number: ";
                    cin >> existingRoll_number;

                    cout << "Enter Gender (M/F): ";
                    cin >> existingGender;
                }

                // Write the data to the new file
                outfile << existingStudentId << ' ' << existingName << ' ' << existingAge << ' '
                        << existingParent_name << ' ' << existingPhone_number << ' ' << existingAddress << ' '
                        << existingRoll_number << ' ' << existingGender << endl;
            }
            else
            {
                // If the student ID doesn't match, write to the new file as is
                outfile << existingStudentId << ' ' << existingName << ' ' << existingAge << ' '
                        << existingParent_name << ' ' << existingPhone_number << ' ' << existingAddress << ' '
                        << existingRoll_number << ' ' << existingGender << endl;
            }
        }

        // If the test is 0, account record was not found
        if (test == 0)
        {
            infile.close(); // Close the original file
            outfile.close(); // Close the new file
            remove("student.dat");     // Remove the file student.dat
            rename("new.dat", "student.dat"); // Rename the new.dat to student.dat
            cout << "\n\n\n\n\a\t\t\t\t\t\t\t\t        Record not found!!!";
            cout << "\n\n\t\t\t\t\t\t\t\t Please check credentials properly!";
            delay(50000000);
            cout << "\n\n\t\t\t\t\t\t\t Press T to try again and any key to return to the main menu....";
            char try_return;
            cin >> try_return;

            // If the user wants to try again, continue the loop
            if (try_return == 't' || try_return == 'T')
            {
                continue;
            }
            else
            {
                break; // Exit the loop if the user doesn't want to try again
            }
        }
        else
        {
            infile.close(); // Close the original file
            outfile.close(); // Close the new file
            remove("student.dat");     // Remove the file student.dat
            rename("new.dat", "student.dat"); // Rename the new.dat to student.dat
            cout << "\n\n\t\t\t\t\t\t Press any key to return to the main menu....";
            getch();
            break;     // Exit the loop when the operation is completed
        }
    }
}

void Admin::Delete_Account(int studentIdToDelete)
{
    ifstream infile("student.dat", ios::in);
    ofstream outfile("temp.dat", ios::out);

    // Check if the file was opened successfully
    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the file..!!";
        return;
    }

    while (infile >> Student_Id >> Name >> Age >> Parent_name >> Phone_number >> Address >> Roll_number >> Gender)
    {
        if (studentIdToDelete != Student_Id)
        {
            outfile << Student_Id << ' ' << Name << ' ' << Age << ' ' << Parent_name << ' '
                    << Phone_number << ' ' << Address << ' ' << Roll_number << ' ' << Gender << endl;
        }
    }

    infile.close();
    outfile.close();

    remove("student.dat");     // Remove the original file
    rename("temp.dat", "student.dat"); // Rename the temp file to the original file
}

void Admin::Delete_Student_Account()
{
    int checkStudent_Id = 0;
    char confirm;

    // Open the student.dat file in read mode
    ifstream infile("student.dat", ios::in);

    // Check if the file was opened successfully
    if (!infile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the file..!!";
        return;
    }

    system("cls"); // Clear the console screen
    headmsg("DELETE STUDENT ACCOUNT"); // Display the header
    line(45, 0); // Draw a line

    cout << "\n\t\t\t\t\t\t     Please provide Student Id to delete the account" << endl;
    cout << "\n\n\n\t\t\t\t\t Student Id:";
    cin >> checkStudent_Id;

    infile.seekg(0, ios::beg);

    int record_found = 0;

    while (infile >> Student_Id >> Name >> Age >> Parent_name >> Phone_number >> Address >> Roll_number >> Gender)
    {
        if (checkStudent_Id == Student_Id)
        {
            record_found = 1;
            cout << "\n\t\t\t\t\t\t Student Current Details" << endl;
            line(45,0);
            cout << left << setw(15) <<endl<< "Student ID" << setw(20) << "Name" << setw(5) << "Age" << setw(20) << "Parent Name"
                 << setw(15) << "Phone Number" << setw(30) << "Address" << setw(15) << "Roll No" << setw(15) << "Gender";
            line(45, 0); // Draw a line
            cout << endl
                 << left << setw(15) << Student_Id << setw(20) << Name << setw(5) << Age << setw(20) << Parent_name
                 << setw(15) << Phone_number << setw(30) << Address << setw(15) << Roll_number << setw(15) << Gender;

            cout << "\n\n\t\t\t\t\t\t\t   Do you want to delete this account? (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y')
            {
                // Remove the account from the file
                infile.close();
                Delete_Account(checkStudent_Id);
                cout << "\n\n\t\t\t\t\t\t\t\t  **** Account deleted successfully ****" << endl;
                delay(50000000);
            }
            else
            {
                cout << "\n\n\t\t\t\t\t\t\t   Account deletion canceled by user." << endl;
                delay(50000000);
            }

            break; // Exit loop after finding the record
        }
    }

    infile.close();

    // If the record was not found
    if (record_found == 0)
    {
        cout << "\n\n\n\n\a\t\t\t\t\t\t\t\t        Record not found!!!";
        cout << "\n\n\t\t\t\t\t\t\t\t Please check credentials properly!";
        delay(50000000);
        cout << "\n\n\t\t\t\t\t\t\t Press T to try again and any key to return to the main menu....";
        char try_return;
        cin >> try_return;

        // If the user wants to try again, call the function recursively
        if (try_return == 't' || try_return == 'T')
        {
            Delete_Student_Account();
        }
    }
}

void Admin::View_All_Student_Accounts()
{
    ifstream infile("student.dat", ios::in);

    // Check if the file was opened successfully
    if (!infile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the file..!!";
        return;
    }

    system("cls"); // Clear the console screen
    headmsg("VIEW ALL STUDENT ACCOUNTS"); // Display the header
    line(45,0); // Draw a line

    cout <<endl<< left << setw(15) << "Student ID" << setw(20) << "Name" << setw(5) << "Age" << setw(20) << "Parent Name"
         << setw(15) << "Phone Number" << setw(30) << "Address" << setw(15) << "Roll No" << setw(15) << "Gender";

    line(45,0); // Draw a line

    while (infile >> Student_Id >> Name >> Age >> Parent_name >> Phone_number >> Address >> Roll_number >> Gender)
    {
        cout <<endl<< left << setw(15) << Student_Id << setw(20) << Name << setw(5) << Age << setw(20) << Parent_name
             << setw(15) << Phone_number << setw(30) << Address << setw(15) << Roll_number << setw(15) << Gender << endl;
    }
    line(45,0);

    infile.close();
    cout << "\n\n\t\t\t\t\t Press any key to return to the main menu....";
    getch();
}
void Admin::Update_Username_Password(int userIdToUpdate, string newUsername, string newPassword, int userType) {
    int existingId=0;
    ifstream infile;
    ofstream outfile;
    string inputFileName, outputFileName;

    if (userType == 1) {
        inputFileName = "adminuserpassword.dat";
        outputFileName = "tempadmin.dat";
    } else if (userType == 2) {
        inputFileName = "studentuserpassword.dat";
        outputFileName = "tempstudent.dat";
    } else {
        cout << "\n\n\t\t\t\t !!Invalid user type..!!";
        return;
    }

    infile.open(inputFileName.c_str(), ios::in);
    outfile.open(outputFileName.c_str(), ios::out);

    // Check if the file was opened successfully
    if (!infile.is_open() || !outfile.is_open()) {
        cout << "\n\n\t\t\t\t !!Error loading the file..!!";
        return;
    }

    while (infile >> existingId >> existingUsername >> existingPassword) {
        if (userIdToUpdate == existingId) {
            // Update the username and password
            existingUsername = newUsername;
            existingPassword = newPassword;
        }
        outfile << existingId << ' ' << existingUsername << ' ' << existingPassword << endl;
    }

    infile.close();
    outfile.close();

    remove(inputFileName.c_str());     // Remove the original file
    rename(outputFileName.c_str(), inputFileName.c_str()); // Rename the temp file to the original file
}

void Admin::Reset_Password()
{
    int checkUser_Id = 0;
    int userType;
    char confirm;
    int existingId=0;

    do
    {
        system("cls"); // Clear the console screen
        headmsg("RESET USERNAME AND PASSWORD"); // Display the header
        line(45, 0); // Draw a line

        cout << "\n\t\t\t\t\t\t\t     Please provide user type.... ";
        cout<<"\n\t\t\t\t\t\t 1.Admin \t\t\t 2.Student"<<endl;
        cout<<"\n\t\t\t\t\t\t\t     Enter your choice..? "<<endl;
        cin >> userType;

        if (userType != 1 && userType != 2)
        {
            cout << "\n\n\t\t\t\t\t\t\t   Invalid user type! Please enter 1 or 2." << endl;
            delay(2000000000); // Delay to provide user feedback
        }

    }
    while (userType != 1 && userType != 2);

    cout << "\n\t\t\t\t\t\t     Please provide User Id to reset the username and password: ";
    cin >> checkUser_Id;

    int record_found = 0;

    if (userType == 1)
    {
        ifstream adminfile("adminuserpassword.dat", ios::in);
        while (adminfile >> existingId >> existingUsername >> existingPassword)
        {
            if (checkUser_Id == existingId)
            {
                record_found = 1;
                cout << "\n\t\t\t\t\t\t\t\t Admin Current Details" << endl;
                line(30,0);
                cout << left << setw(15) << "Admin ID" << setw(20) << "Username" << setw(20) << "Password";
                line(30, 0); // Draw a line
                cout << endl
                     << left << setw(15) << existingId << setw(20) << existingUsername << setw(20) << existingPassword;
                line(30,0);

                cout << "\n\n\t\t\t\t\t\t\t   Do you want to reset the Username and Password for this account? (Y/N): ";
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y')
                {
                    // Allow the user to input new username and password
                    cout << "\n\t\t\t\t\t\t Username: ";
                    cin >> existingUsername;
                    cout << "\n\t\t\t\t\t\t Password: ";
                    cin >> existingPassword;

                    // Update the username and password in the file
                    adminfile.close();
                    Update_Username_Password(checkUser_Id, existingUsername, existingPassword, userType);
                    cout << "\n\n\t\t\t\t\t\t\t\t  **** Username and Password reset successfully ****" << endl;
                }
                else
                {
                    cout << "\n\n\t\t\t\t\t\t\t   Username and Password reset canceled by user." << endl;
                }

                break; // Exit loop after finding the record
            }
        }
        adminfile.close();
    }
    else if (userType == 2)
    {
        ifstream studentfile("studentuserpassword.dat", ios::in);
        while (studentfile >> existingId >> existingUsername >> existingPassword)
        {
            if (checkUser_Id == existingId)
            {
                record_found = 1;
                cout << "\n\t\t\t\t\t\t Student Current Details" << endl;
                line(30,0);
                cout << left << setw(15) << "Student ID" << setw(20) << "Username" << setw(20) << "Password";
                line(30, 0); // Draw a line
                cout << endl
                     << left << setw(15) << existingId << setw(20) << existingUsername << setw(20) << existingPassword;
                line(30,0);

                cout << "\n\n\t\t\t\t\t\t\t   Do you want to reset the Username and Password for this account? (Y/N): ";
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y')
                {
                    // Allow the user to input new username and password
                    cout << "\n\t\t\t\t\t\t Username: ";
                    cin >> existingUsername;
                    cout << "\n\t\t\t\t\t\t Password: ";
                    cin >> existingPassword;

                    // Update the username and password in the file
                    studentfile.close();
                    Update_Username_Password(checkUser_Id, existingUsername, existingPassword, userType);
                    cout << "\n\n\t\t\t\t\t\t\t\t  **** Username and Password reset successfully ****" << endl;
                }
                else
                {
                    cout << "\n\n\t\t\t\t\t\t\t   Username and Password reset canceled by user." << endl;
                }

                break; // Exit loop after finding the record
            }
        }
        studentfile.close();
    }

    // If the record was not found
    if (record_found == 0)
    {
        cout << "\n\n\n\n\a\t\t\t\t\t\t\t\t        Record not found!!!";
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Please check credentials properly!";
        delay(50000000);
        cout << "\n\n\t\t\t\t\t\t\t Press T to try again and any key to return to the main menu....";
        char try_return;
        cin >> try_return;
        // If the user wants to try again, call the function recursively
        if (try_return == 't' || try_return == 'T')
        {
            Reset_Password();
        }
    }
    else{
        cout<<"\n \n Press any key to return to main menu....";
    getch();
    }
}

void Admin::Create_Admin_Account()
{
    char try_return;
    int checkAdmin_Id = 0;

    // Open the admin.dat file in append and read mode
    fstream adminFile("admin.dat", ios::in | ios::out | ios::app);

    // Open the adminusername.dat file in append mode
    ofstream usernameFile("adminusername.dat", ios::app);

    // Check if the files were opened successfully
    if (!adminFile.is_open() || !usernameFile.is_open())
    {
        cout << "\n\n\t\t\t\t !!Error loading the files..!!" << endl;
        return;
    }

    while (true)
    {
        system("cls"); // Clear the console screen
        headmsg("New Admin Form");
        line(32, '=');
        int record_found = 0;

        cout << "Enter Admin ID: " << endl;
        cin >> checkAdmin_Id;

        adminFile.seekg(0, ios::beg);

        while (adminFile >> existingAdmin_Id >> existingName >> existingAge >> existingPhone_number
                >> existingAddress >> existingUsername >> existingPassword)
        {
            if (checkAdmin_Id == existingAdmin_Id)
            {
                record_found = 1;
                break;
            }
        }

        if (record_found == 1)
        {
            cout << "\n\n\t\t\t\t\t\t\t       Admin Id already in use !!" << endl;
            cout << "\n\n\t\t\t\t\t\t\t Press T to try again and any key to return to the main menu...." << endl;
            cin >> try_return;

            if (try_return == 't' || try_return == 'T')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            existingAdmin_Id = checkAdmin_Id;

            cout << "Enter Admin Name: ";
            cin.ignore();
            getline(cin, existingName);

            cout << "Enter Age: ";
            cin >> existingAge;

            cout << "Enter Phone Number: ";
            cin >> existingPhone_number;

            cout << "Enter Address: ";
            cin.ignore();
            getline(cin, existingAddress);

            cout << "Enter Username: ";
            cin >> existingUsername;

            cout << "Enter Password: ";
            cin >> existingPassword;

            // Close and reopen the admin.dat file in append mode
            adminFile.close();
            adminFile.open("admin.dat", ios::app);

            // Append the new admin record to the admin.dat file
            adminFile << existingAdmin_Id << ' ' << existingName << ' ' << existingAge << ' ' << existingPhone_number
                      << ' ' << existingAddress << ' ' << existingUsername << ' ' << existingPassword << endl;

            // Append the username and password to the adminusername.dat file
            usernameFile << existingAdmin_Id << ' ' << existingUsername << ' ' << existingPassword << endl;

            cout << "\n\n\n\t\t\t\t\t\t\t\t  **** Admin Account created successfully ****" << endl;
            cout << "\n\n\t\t\t\t\t\t\t Press A to add more records and any key to return to the main menu...." << endl;
            cin >> try_return;

            if (try_return == 'a' || try_return == 'A')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    // Close both files
    adminFile.close();
    usernameFile.close();
}
vector<string> Admin::split(const string &s, char delimiter)// Function to split a string by delimiter
 {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


void Admin::Attendance(){
    system("cls"); // Clear the console screen
        headmsg("ATTENDANCE OF STUDENTS"); // Display the admin menu header
        line(32, 5); // Draw a line
        cout<<endl<<endl;
// Function to read data from a CSV file and display it
    string filename = "studentattendance.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return;
    }


    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        cout <<endl<<"\t\t\t    " <<left << setw(10) << tokens[0] << setw(20) << tokens[1];
        for (size_t i = 2; i < tokens.size(); ++i) {
            cout << setw(8) << tokens[i];
        }
        cout << endl;
    }
    file.close();
    cout << "\n\n\t\t\t\t\t\t\t Press any key to return to the main menu...." << endl;
            getch();
}


// Function to display and manage the administrator menu
void Admin_Menu()
{
    int choice = 0;
    while (choice != 10) // Loop until the administrator chooses to exit (choice = 9)
    {
        system("cls"); // Clear the console screen
        headmsg("ADMINISTRATOR MENU"); // Display the admin menu header
        line(32, 5); // Draw a line

        Admin a;

        // Display menu options for admin
        cout << "\v\v\n\t\t\t\t\t\t\t\t    1. Create student accounts \v";
        cout << "\n\t\t\t\t\t\t\t\t    2. Edit Student Details \v";
        cout << "\n\t\t\t\t\t\t\t\t    3. Delete Student Account \v";
        cout << "\n\t\t\t\t\t\t\t\t    4. View all Student Data \v";
        cout << "\n\t\t\t\t\t\t\t\t    5. Enroll Students in Courses \v";
        cout << "\n\t\t\t\t\t\t\t\t    6. Generate Student reports \v";
        cout << "\n\t\t\t\t\t\t\t\t    7. Reset Login Credentials \v";
        cout << "\n\t\t\t\t\t\t\t\t    8. Add Admin \v";
        cout << "\n\t\t\t\t\t\t\t\t    9. View Attendance \v";
        cout << "\n\t\t\t\t\t\t\t\t    10. Exit \v";

        line(40, 5); // Draw a line

        cout << "\n\t\t\t\t\t\t\t\t  Enter your choice....";
        cin >> choice; // Get admin's menu choice

        // Execute the chosen menu option using a switch statement
        switch (choice)
        {
        case 1:
            a.Create_Student_Account();
            break;
        case 2:
            a.Edit_Student_Account_Admin();
            break;
        case 3:
            a.Delete_Student_Account();
            break;
        case 4:
            a.View_All_Student_Accounts();
            break;
        case 5:
            a.EnrollStudentInCourses();
            break;
        case 6:
            a.Generate_Report();
            break;
        case 7:
            a.Reset_Password();
            break;
        case 8:
            a.Create_Admin_Account();
            break;
            case 9:
            a.Attendance();
            break;
        case 10:
            Close_app(); // Exit the admin menu
            break;

        default:
            cout << "\n\n\t\t\t\t\t\t\t INVALID CHOICE !!! PLEASE CHOOSE AGAIN";
            delay(40000000000); // Delay to provide admin feedback
        }
    }
}

// Function to display and manage the student menu
void Student_Menu()
{
    int choice = 0;
    while (choice != 5) // Loop until the student chooses to exit (choice = 6)
    {
        system("cls"); // Clear the console screen
        system("color 3"); // Set console color

        headmsg("STUDENT MENU"); // Display the student menu header
        line(32, 5); // Draw a line

        Student s;

        // Display menu options for student
        cout << "\v\v\n\t\t\t\t\t\t\t\t    1. View Academic progress \v";
        cout << "\n\t\t\t\t\t\t\t\t    2. Enroll in courses \v";
        cout << "\n\t\t\t\t\t\t\t\t    3. Update personal details \v";
        cout << "\n\t\t\t\t\t\t\t\t    4. View your reports \v";
        cout << "\n\t\t\t\t\t\t\t\t    5. Exit \v";
        line(32, 5); // Draw a line
        cout << "\n\t\t\t\t\t\t\t\t  Enter your choice....";
        cin >> choice; // Get student's menu choice

        // Execute the chosen menu option using a switch statement
        switch (choice)
        {
        case 1:
            s.Display_Student_Report();
            break;
        case 2:
            s.EnrollStudentInCourses();
            break;
        case 3:
            s.Edit_Student_Account_Student();
            break;
        case 4:
            s.Generate_Performance_Report();
            break;
        case 5:
            Close_app(); // Exit the student menu
            break;
        default:
            cout << "\n\n\t\t\t\t\t\t\t INVALID CHOICE !!! PLEASE CHOOSE AGAIN";
            delay(40000000000); // Delay to provide student feedback
        }
    }
}

int main()
{

    headmsg("Student Management System"); // Display the header msg
    line(25, 7); // Draw the line

    cout << "\v\v\v\v\v";
    cout << "\t\t\t\t\t\t\t\t            WELCOME   \v\v";
    cout << "\t\t\t\t\t\t\t\t              TO      \v\v";
    cout << "\t\t\t\t\t\t\t\t      STUDENT MANAGEMENT APPLICATION \v\v";
    cout << "\t\t\t\t\t\t\t\t          APPLICATION \n";
    line(25, 7); // Draw the line

    cout << "\n\t\t\t\t\t\t\t\t        -Together We Learn";
    cout << "\n\n\n\n\t\t\t\t     Press any key to continue....";
    getch();

    // Call the login function to validate username and password
    int r = login();
    if (r == 1)
    {
        Admin_Menu(); // If login is successful, continue to main menu
    }
    else if (r==2)
    {
        Student_Menu();
    }
    else
    {
        Close_app(); // If login is not successful, exit the application
    }
    return 0;
}
