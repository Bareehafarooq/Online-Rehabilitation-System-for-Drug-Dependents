#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include<iomanip>
#include<windows.h>
using namespace std;


const string YELLOW = "\033[33m";                 //declaration of global variables
const string BOLD_YELLOW = "\033[1;33m";
const string BG_YELLOW = "\033[43m";
const string RESET = "\033[0m";
const string BLACK = "\033[30m";
const string BOLD_RED = "\033[1;31m";
int Finalscore;


enum UserType
{
    ADMINISTRATOR,      //making userdefined data type using enumeration
    COUNSELOR,
    ADDICT
};

class User
{
protected:
    string name;                              //base class 
    int age;
    UserType userType;                       // object of enum

public:
    User(const string& n, int a, UserType type) : name(n), age(a), userType(type) {}  //parametrized constructor
    User() {}                                     //default constructor                               //default constructor
    virtual ~User() = default;                                                 // destructor of base class

    virtual string displayProfile() const = 0;
    virtual void updateProfile() {}
    virtual void scheduleAppointments() {}
    virtual void conductAndReportProgress() {}
    virtual void conductSession() {}
    virtual void attendSession() {}
    virtual string getUsername() const { return name; }
    virtual string getPassword() const { return getPassword(); }
    virtual void saveToFile(const char* fileName) const {}

    UserType getUserType() const
    {
        return userType;
    }
};

class Administrator : public User                                   //public inheritance 
{
private:
    string username;
    string password;

public:
    Administrator(const string& n, int a, const string& u, const string& p)
        : User(n, a, ADMINISTRATOR), username(u), password(p) {}              //parametrized constructor

    Administrator() {}                                  //default constructor

    string displayProfile() const override
    {
        ostringstream oss;
        oss << YELLOW << "Administrator Profile:\n" << RESET << "Name: " << name << "\nAge : " << age << endl;
        return oss.str();
    }

    void updateProfile() override
    {
        cout << BOLD_YELLOW << "Enter new name for Administrator: " << RESET;
        cin >> name;
        cout << BOLD_YELLOW << "Enter new age for Administrator: " << RESET;
        cin >> age;
        cout << BG_YELLOW << BLACK << "\t\t\t\t\t\tUpdated profile is:" << RESET << endl;
        cout << BOLD_YELLOW << "New Name:" << name << endl;
        cout << "New Age:" << age << RESET << endl;
    }

    string getUsername() const override
    {
        return username;
    }

    string getPassword() const override
    {
        return password;
    }
    void conductAndReportProgress() override
    {
        cout << "The total score of the addict was :" << " " << YELLOW << Finalscore << RESET << endl;
    }

    void saveToFile(const char* fileName) const override
    {
        ofstream outFile(fileName, ios::binary | ios::app);
        if (outFile.is_open())
        {
            outFile.write((char*)this, sizeof(*this));
            outFile.close();
            cout << "User profile saved successfully!" << endl;
        }
        else
        {
            cerr << "Unable to open file for writing." << endl;
        }
    }
};

class Counselor : public User                          //public inheritance
{
private:
    string username;
    string password;
    string appointments[10];
    string  appointmentDetails;
    bool availability[10];

public:
    Counselor(const string& n, int a, const string& u, const string& p)
        : User(n, a, COUNSELOR), username(u), password(p) {}               //parameterized constructor
    Counselor() {}                                                         //default constructor

    string displayProfile() const override
    {
        ostringstream oss;
        oss << YELLOW << "Counselor Profile" << RESET << "\nName: " << name << "\nAge : " << age << endl;
        return oss.str();
    }

    void updateProfile() override
    {
        cout << BOLD_YELLOW << "Enter new name for Counselor: " << RESET;
        cin >> name;
        cout << BOLD_YELLOW << "Enter new age for Counselor: " << RESET;
        cin >> age;
        cout << BG_YELLOW << BLACK << "\t\t\t\t\t\tUpdated profile is:" << RESET << endl;
        cout << BOLD_YELLOW << "New Name:" << name << endl;
        cout << "New Age:" << age << RESET << endl;
    }

    string getUsername() const override
    {
        return username;
    }

    string getPassword() const override
    {
        return password;
    }


    void conductAndReportProgress() override
    {
        cout << "The total score of the addict was :" << " " << YELLOW << Finalscore << RESET << endl;
    }
    void conductSession() override
    {
        string response;
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tWelcome to the counseling session! \n" << endl << RESET;

        cout << "Today, we will discuss some strategies for managing your addiction.........\n\n\n";

        cout << BOLD_YELLOW << "Good " << (rand() % 2 == 0 ? "morning" : "afternoon") << "! " << RESET << endl;
        cout << endl;

        cin.ignore();
        cout << YELLOW << "How have you been feeling since our last session?\n" << RESET;
        getline(cin, response);
        cout << endl;

        cout << BOLD_YELLOW << "I appreciate your honesty.Let's explore some coping mechanisms together. One effective strategy is to identify your triggers. \n" << RESET;

        cout << YELLOW << "Can you recall any specific situations that led to drug use?\n" << RESET;
        getline(cin, response);
        cout << endl;

        cout << BOLD_YELLOW << "Remember! It's crucial to shift perspective and see relapse as an opportunity to learn.Every setback is a chance to grow and become stronger.\n";
        cout << "Now, let's work on creating a personalized plan to avoid those triggers. It's important to replace unhealthy habits with positive ones.\n" << RESET;

        cout << YELLOW << "What are some activities or hobbies you enjoy that we can incorporate into your routine?\n" << RESET;
        getline(cin, response);
        cout << endl;

        cout << BOLD_YELLOW << " Fantastic! That sounds like a great way to stay focused on your well-being.\n";


        cout << YELLOW << "Developing a strong support system is key to your recovery. Reach out to friends, family, or support groups for help and encouragement.There are many people who believe in you and want you to succeed.\n" << RESET;
        cout << YELLOW << "Now, let's talk about something different. On a scale from 1 to 10, where are you at in your recovery?\n" << RESET;
        getline(cin, response);
        cout << endl;

        int recoveryProgress;
        cin >> recoveryProgress;

        if (recoveryProgress < 5) {
            cout << BOLD_YELLOW << "It seems like you're still in the early stages of your recovery. Remember, it's okay to take it slow. You're making progress every day.\n" << RESET;
        }
        else
        {
            cout << BOLD_YELLOW << "Welldone! You're making great strides in your recovery. Keep up the good work!\n" << RESET;
        }

        cout << YELLOW << "Lastly, let's shift our perspective a bit. What would your life be like if you werent addicted to something?\n" << RESET;
        getline(cin, response);
        cout << YELLOW << "That's a powerful question. It can help you visualize your potential and motivate you to continue on your recovery journey.\n";
        cout << "That's a great point. Sharing your experiences can help others understand and support you better.\n";
        cout << endl;
        cout << BOLD_YELLOW << "Thank you for attending the session. Remember, you're not alone in this journey.\n";

    }
    void scheduleAppointments() override
    {
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tWelcome to the appointment scheduler!" << RESET << endl;
        cout << "Enter the details for the appointment:\n";

        string addictName;
        cout << "Enter your complete name: ";
        cin.ignore();
        getline(cin, addictName);
        cin.ignore();
        cout << "Enter your desired" << YELLOW << " " << "date and time" << RESET << " " << "you want to book : " << endl;
        getline(cin, appointmentDetails);

        int slot = -1;
        for (int i = 0; i < 10; ++i)
        {
            if (appointments[i].empty())
            {
                slot = i;
                break;
            }
        }

        if (slot != -1)
        {
            appointments[slot] = "Name: " + addictName + "\nDate and Time: " + appointmentDetails;
            cout << appointments[slot] << endl;
            cout << YELLOW << "Appointment scheduled successfully!\n";
            cout << "\n\n\n";
        }
        else
        {
            cerr << BOLD_RED << "Cannot schedule more than 10 appointments. Appointment list is full.\n";
        }
    }

    void updateAvailability() {
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tCurrent Availability is for the following slots only!\n" << RESET;
        for (int i = 0; i < 10; ++i) {
            cout << BOLD_YELLOW << "Slot " << i + 1 << ": " << (availability[i] ? "Available" : "Not Available") << "\n" << RESET;
        }

        cout << YELLOW << "Enter the time slot number to update availability (1-" << 10 << "): " << RESET;
        int slot;
        cin >> slot;

        if (slot >= 1 && slot <= 10) {
            if (availability[slot - 1]) {
                availability[slot - 1] = false; // Slot is available, book it
                cout << endl;
                cout << BG_YELLOW << BLACK << "\t\t\t\t\t Availability for slot " << slot << " booked successfully!\n" << RESET;
            }
            else {
                cerr << BOLD_RED << "Error: Slot " << slot << " is already booked. Please choose another slot.\n" << RESET;
                cin >> slot;
                cout << BG_YELLOW << BLACK << "\t\t\t\t\t Availability for slot " << slot << " booked successfully!\n" << RESET;
            }
        }
        else {
            cerr << BOLD_RED << "Invalid time slot. Please enter a number between 1 and " << 10 << ".\n" << RESET;
        }
    }


    void saveToFile(const char* fileName) const override
    {
        ofstream outFile(fileName, ios::binary | ios::app);
        if (outFile.is_open())
        {
            outFile.write((char*)this, sizeof(*this));
            outFile.close();
            cout << "User profile saved successfully!" << endl;
        }
        else
        {
            cerr << "Unable to open file for writing." << endl;
        }
    }

};

class Addict : public User
{
private:
    string username;
    string password;
    string appointments[10];
    string appointmentDetails;
public:
    Addict(const string& n, int a, const string& u, const string& p)
        : User(n, a, ADDICT), username(u), password(p) {}
    Addict() {}
    string displayProfile() const override
    {
        ostringstream oss;
        oss << YELLOW << "Addict Profile\n" << RESET << "Name: " << name << "\nAge : " << age << endl;
        return oss.str();
    }

    void updateProfile() override
    {
        cout << BOLD_YELLOW << "Enter new name for Addict: " << RESET;
        cin >> name;
        cout << BOLD_YELLOW << "Enter new age for Addict: " << RESET;
        cin >> age;
        cout << BG_YELLOW << BLACK << "\t\t\t\t\t\tUpdated profile is:" << RESET << endl;
        cout << BOLD_YELLOW << "New Name:" << name << endl;
        cout << "New Age:" << age << RESET << endl;
    }


    string getUsername() const override
    {
        return username;
    }

    string getPassword() const override
    {
        return password;
    }


    void scheduleAppointments() override
    {
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tWelcome to the appointment scheduler!" << RESET << endl;
        cout << "Enter the details for the appointment:\n";

        string addictName;
        cout << "Enter your complete name: ";
        cin.ignore();
        getline(cin, addictName);
        cin.ignore();
        cout << "Enter your desired" << YELLOW << " " << "date and time" << RESET << " " << "you want to book : " << endl;
        getline(cin, appointmentDetails);

        int slot = -1;
        for (int i = 0; i < 10; ++i)
        {
            if (appointments[i].empty())
            {
                slot = i;
                break;
            }
        }

        if (slot != -1)
        {
            appointments[slot] = "Name: " + addictName + "\nDate and Time: " + appointmentDetails;
            cout << appointments[slot] << endl;
            cout << YELLOW << "Appointment scheduled successfully!\n";
            cout << "\n\n\n";
            cout << BG_YELLOW << BLACK << "* You're requested to adhere to the scheduled timings for smooth conduction of the sesion!!" << RESET << endl;
        }
        else
        {
            cerr << BOLD_RED << "Cannot schedule more than 10 appointments. Appointment list is full.\n";
        }
    }

    void conductAndReportProgress() override
    {
        int totalScore = 0;
        int responses[10];

        // Questions
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tWelcome to the Drug Addiction Questionnaire" << RESET << endl;
        cout << endl;

        cout << YELLOW << "Please complete the following questionnaire by answering the questions (1-3):\n";
        cout << " 1- Agree " << endl;
        cout << " 2- Uncertain" << endl;
        cout << " 3- Disagree" << endl;
        cout << RESET;

        // loop will ask questions and store responses in the array
        for (int i = 0; i < 10; ++i)
        {
            switch (i)
            {
            case 0:
                cout << BOLD_YELLOW << "1. Do you experience cravings for drugs? ";
                break;
            case 1:
                cout << "2. Have you engaged in drug use in the last month? ";
                break;
            case 2:
                cout << "3. Do you feel anxious or stressed, leading to drug use? ";
                break;
            case 3:
                cout << "4. Do you neglect responsibilities at home, work, or school because of your drug use? ";
                break;
            case 4:
                cout << "5. Are you spending a significant amount of time on recovering from the effects of drugs? ";
                break;
            case 5:
                cout << "6. Do you engage in risky behaviors under the influence of drugs ";
                break;
            case 6:
                cout << "7. Are you experiencing physical health issues related to drug use? ";
                break;
            case 7:
                cout << "8. Have you lost interest in activities or hobbies that you once enjoyed? ";
                break;
            case 8:
                cout << "9. Do you use drugs as a way to cope with stress or emotional pain? ";
                break;
            case 9:
                cout << "10. Do you have a support system or network to help you during recovery ? " << RESET;
                break;
            }
            cin >> responses[i];

            // Check if the response is within the valid range
            if (responses[i] >= 1 && responses[i] <= 3)
            {
                totalScore += responses[i];
                Finalscore = totalScore;
            }
            else
            {
                cerr << BOLD_RED << "Invalid response! Please enter a number between 1 and 3 only.\n" << BOLD_YELLOW;
                --i; // Decrement i to repeat the same question
            }
        }

        cout << endl;
        cout << endl;

        cout << BG_YELLOW << BLACK << "\t\t\t\t\tProgress Report" << RESET << endl;

        cout << YELLOW << "Your total score is : " << RESET << totalScore << "\n";

        // will determine the progress level based on the total score

        string progressLevel = (totalScore < 7) ? "Low" : (totalScore < 14) ? "Moderate" : "High";

        cout << YELLOW << "Your progress level is: " << RESET << progressLevel << "\n";
        cout << BOLD_YELLOW << " Remember, progress takes time! Keep striving .......";
        cout << endl;
        cout << endl;

        // will provide recommendations based on the progress level
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tRecomendations" << RESET << endl;
        cout << endl;
        if (progressLevel == "Low")
            cout << YELLOW << "Continue with the rehabilitation program and stay committed.";

        else if (progressLevel == "Moderate")
            cout << YELLOW << "Consider additional counseling sessions and support.";
        else
            cout << YELLOW << "Intensify the rehabilitation efforts. Seek professional help.";
        cout << RESET << "\n";
    }

    void conductSession() override
    {
        string response;
        cout << BG_YELLOW << BLACK << "\t\t\t\t\tWelcome to the counseling session! \n" << endl << RESET;

        cout << "Today, we will discuss some strategies for managing your addiction.........\n\n\n";

        cout << BOLD_YELLOW << "Good " << (rand() % 2 == 0 ? "morning" : "afternoon") << "! " << RESET << endl;
        cout << endl;

        cin.ignore();
        cout << YELLOW << "How have you been feeling since our last session?\n" << RESET;
        getline(cin, response);
        cout << endl;

        cout << BOLD_YELLOW << "I appreciate your honesty.Let's explore some coping mechanisms together. One effective strategy is to identify your triggers. \n" << RESET;

        cout << YELLOW << "Can you recall any specific situations that led to drug use?\n" << RESET;
        getline(cin, response);
        cout << endl;

        cout << BOLD_YELLOW << "Remember! It's crucial to shift perspective and see relapse as an opportunity to learn.Every setback is a chance to grow and become stronger.\n";
        cout << "Now, let's work on creating a personalized plan to avoid those triggers. It's important to replace unhealthy habits with positive ones.\n" << RESET;

        cout << YELLOW << "What are some activities or hobbies you enjoy that we can incorporate into your routine?\n" << RESET;
        getline(cin, response);
        cout << endl;

        cout << BOLD_YELLOW << " Fantastic! That sounds like a great way to stay focused on your well-being.\n";


        cout << YELLOW << "Developing a strong support system is key to your recovery. Reach out to friends, family, or support groups for help and encouragement.There are many people who believe in you and want you to succeed.\n" << RESET;
        cout << YELLOW << "Now, let's talk about something different. On a scale from 1 to 10, where are you at in your recovery?\n" << RESET;
        getline(cin, response);
        cout << endl;

        istringstream iss(response);
        int recoveryProgress;
        iss >> recoveryProgress;

        if (recoveryProgress < 5) {
            cout << BOLD_YELLOW << "It seems like you're still in the early stages of your recovery. Remember, it's okay to take it slow. You're making progress every day.\n" << RESET;
        }
        else
        {
            cout << BOLD_YELLOW << "Welldone! You're making great strides in your recovery. Keep up the good work!\n" << RESET;
        }

        cout << YELLOW << "Lastly, let's shift our perspective a bit. What would your life be like if you werent addicted to something?\n" << RESET;
        getline(cin, response);
        cout << YELLOW << "That's a powerful question. It can help you visualize your potential and motivate you to continue on your recovery journey.\n";
        cout << "That's a great point. Sharing your experiences can help others understand and support you better.\n";

        cout << BOLD_YELLOW << "Thank you for attending the session. Remember, you're not alone in this journey.\n";

    }
    void saveToFile(const char* fileName) const override
    {
        ofstream outFile(fileName, ios::binary | ios::app);
        if (outFile.is_open())
        {
            outFile.write((char*)this, sizeof(*this));
            outFile.close();
            cout << "User profile saved successfully!" << endl;
        }
        else
        {
            cerr << "Unable to open file for writing." << endl;
        }
    }
};

class UserDatabase
{
private:
    static const int nuser = 100;
    User* users[nuser];
    int numUsers;

public:
    UserDatabase() : numUsers(0) {}

    ~UserDatabase()
    {
        for (int i = 0; i < numUsers; ++i)
        {
            delete users[i];
        }
    }

    void signUp(User* user)
    {
        if (numUsers < nuser)
        {
            users[numUsers++] = user;
        }
        else
        {
            cerr << BOLD_RED << "User database is full. Cannot sign up new user." << endl;
        }
    }

    User* login(const string& username, const string& password) const
    {
        for (int i = 0; i < numUsers; ++i)
        {
            if (users[i]->getUsername() == username && users[i]->getPassword() == password)
            {
                return users[i];
            }
        }
        return nullptr;
    }


    bool usernameExists(const string& username) const
    {
        for (int i = 0; i < numUsers; ++i)
        {
            if (users[i]->getUsername() == username)
            {
                return true;
            }
        }
        return false;
    }

    void saveAllToFile(const char* fileName) const {
        ofstream outFile(fileName, ios::binary | ios::app);
        if (outFile.is_open()) {
            for (int i = 0; i < numUsers; ++i) {

                outFile.write((char*)(users[i]), sizeof(*(users[i])));
            }
            outFile.close();
            cout << "All user profiles saved successfully!" << endl;
        }
        else {
            cerr << "Unable to open file for writing." << endl;
        }
    }


};
void saveUserToFile(const User& user, const char* fileName)
{
    ofstream outFile(fileName, ios::binary | ios::app);
    if (outFile.is_open())
    {
        outFile << user.displayProfile();
        outFile.close();
        cout << YELLOW << "User profile saved successfully!" << RESET << endl;
    }
    else
    {
        cerr << BOLD_RED << "Unable to open file for writing." << endl;
    }
}

User* signUp(UserDatabase& userDb)
{
    string name, username, password;
    int age;

    cout << YELLOW << "Enter your name: " << RESET;
    cin >> name;
    cout << YELLOW << "Enter your age: " << RESET;
    cin >> age;

    do
    {
        cout << YELLOW << "Enter your username: " << RESET;
        cin >> username;

        if (userDb.usernameExists(username))
        {
            cerr << BOLD_RED << "Username already exists. Please choose a different username.\n" << RESET;
        }

    } while (userDb.usernameExists(username));

    cout << YELLOW << "Enter your password: " << RESET;
    cin >> password;

    char userType;
    cout << endl << endl;
    cout << "\t\t\t\t\t---------------------\n";
    cout << "\t\t\t\t\t\tUserType\n";
    cout << "\t\t\t\t\t---------------------\n";
    cout << BG_YELLOW << BLACK << "\t\t\t\t\tSelect user type.........:\n" << RESET << YELLOW << "(A)Administrator\n(B) Counselor\n(C) Addict\n" << RESET;
    cout << "Enter your choice: ";
    cin >> userType;

    User* newUser = nullptr;

    switch (userType)
    {
    case 'A':
        newUser = new Administrator(name, age, username, password);
        break;
    case 'a':
        newUser = new Administrator(name, age, username, password);
        break;
    case 'B':
        newUser = new Counselor(name, age, username, password);
        break;
    case 'b':
        newUser = new Counselor(name, age, username, password);
        break;
    case 'C':
        newUser = new Addict(name, age, username, password);
        break;
    case 'c':
        newUser = new Addict(name, age, username, password);
        break;
    default:
        cerr << BOLD_RED << "Invalid user type selected." << RESET << endl;
        break;
    }


    if (newUser != nullptr)
    {
        userDb.signUp(newUser);
        saveUserToFile(*newUser, "users.dat");
        cout << "User signed up successfully!" << endl << RESET;
    }

    return newUser;
}


void printMenu()
{
    cout << BG_YELLOW << BLACK;
    cout << "1. Sign Up\n";
    cout << "2. Log In\n";
    cout << "3. Exit\n" << RESET;
}


void printHeader(const string& title) {
    cout << "\t\t\t\t\t===================================" << endl;
    cout << "\t\t\t\t\t         " << title << "             " << endl;
    cout << "\t\t\t\t\t===================================" << RESET << endl;
}

void printUserOptions(User* loggedInUser)
{
    cout << "1. View Profile\n"
        << "2. Update Profile\n"
        << "3. Log Out\n";

    switch (loggedInUser->getUserType())
    {
    case ADMINISTRATOR:
        cout << "4. View Progress\n";
        break;
    case COUNSELOR:

        cout << "4. View Progress\n"
            << "5. Schedule Appointments\n"
            << "6. Conduct Sessions\n"
            << "7. Update availability\n";
        break;
    case ADDICT:
        cout << "4.Generate report\n"
            << "5. Schedule Appointments\n"
            << "6. Attend Sessions\n";
        break;
    }
}


int main()
{

    system("cls");

    cout << " \n\n\n\n\n\n\n\n\n\n\n\n ";
    cout << BG_YELLOW << BLACK;
    cout << "\t\t\t\t==================================================================" << endl;
    cout << "\t\t\t\t          Online Rehabilitation System for Drug Dependents        " << endl;
    cout << "\t\t\t\t==================================================================" << endl;
    cout << RESET;
    cout << " \n\n\n\n ";
    cout << YELLOW << "\t\t\t\t\tWelcome to the Online Rehabilitation System!\n" << RESET;

    Sleep(8000);

    UserDatabase userDb;
    User* loggedInUser = nullptr;
    Counselor c;

    while (true)
    {
        system("cls");
        printHeader("User Options");
        printMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Sign Up
            system("cls");
            printHeader("Sign up");
            loggedInUser = signUp(userDb);
            Sleep(2000);
            break;
        case 2:
            // Log In
        {
            system("cls");
            printHeader("Login in ");
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            loggedInUser = userDb.login(username, password);

            if (loggedInUser == nullptr)
            {
                cerr << "Login failed. Incorrect username or password.\n";
            }
            else
            {
                cout << "Login successful. Welcome, " << loggedInUser->getUsername() << "!\n";
            }
            Sleep(2000);
        }
        break;
        case 3:
            // Exit
            system("cls");
            printHeader("Exit");
            cout << BG_YELLOW << BLACK << "Exiting the program. Goodbye!\n";
            Sleep(2000);
            return 0;

        default:
            cerr << "Invalid choice. Please enter a valid option.\n";
            break;

        }

        // If the user is logged in, allow them to perform user-specific actions
        while (loggedInUser != nullptr)
        {
            printHeader("User Options");
            printUserOptions(loggedInUser);

            int userOption;
            cout << "Enter your choice: ";
            cin >> userOption;

            switch (userOption)
            {
            case 1:
                // View Profile
                system("cls");
                printHeader("View profile");
                cout << loggedInUser->displayProfile() << endl;
                Sleep(2000);

                break;

            case 2:
                // Update Profile
                system("cls");
                printHeader("Update Profile");
                loggedInUser->updateProfile();
                cout << YELLOW << "Profile updated successfully!\n" << RESET;
                Sleep(2000);
                break;

            case 3:
                // Log Out
                system("cls");
                printHeader("Log out");
                cout << YELLOW << "Logging out. Goodbye, " << loggedInUser->getUsername() << "!\n" << RESET << endl;
                loggedInUser = nullptr; // Set loggedInUser to null to exit the inner loop
                Sleep(2000);
                break;

            case 4:
                // Generate Reports (Administrator and Addict)
                system("cls");
                if (loggedInUser->getUserType() == ADDICT)
                {
                    printHeader("Generate Report");
                    loggedInUser->conductAndReportProgress();
                }
                else if (loggedInUser->getUserType() == ADMINISTRATOR || loggedInUser->getUserType() == COUNSELOR)
                {
                    printHeader("View Progress");
                    loggedInUser->conductAndReportProgress();
                }
                else
                {
                    cerr << BOLD_RED << "Invalid option for the current user type.\n" << RESET;
                }
                Sleep(2000);
                break;

            case 5:
                // Schedule Appointments (Counselor and Addict)
                system("cls");
                printHeader("Schedule Appointment");

                cout << endl;
                if (loggedInUser->getUserType() == COUNSELOR || loggedInUser->getUserType() == ADDICT)
                {
                    loggedInUser->scheduleAppointments();
                }
                else {
                    cerr << BOLD_RED << "Invalid option for the current user type.\n" << RESET;
                }
                Sleep(2000);
                break;

            case 6:
                // Monitor Progress (Counselor)
                system("cls");
                if (loggedInUser->getUserType() == COUNSELOR) {
                    printHeader("Conduct Session");
                    loggedInUser->conductSession();
                }
                else if (loggedInUser->getUserType() == ADDICT) {
                    printHeader("Attend session");
                    loggedInUser->conductSession();
                }
                else {
                    cerr << BOLD_RED << "Invalid option for the current user type.\n" << RESET;
                }
                Sleep(200);
                break;

            case 7:
                system("cls");
                if (loggedInUser->getUserType() == COUNSELOR) {
                    printHeader("Update Availability");
                    c.updateAvailability();
                }

                else {
                    cerr << BOLD_RED << "Invalid option for the current user type.\n" << RESET;
                }
                Sleep(2000);
                break;
                Sleep(2000);
                break;

            default:
                cerr << BOLD_RED << "Invalid choice. Please enter a valid option.\n" << RESET;
                break;
            }
        }
    }

    return 0;
}

