#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For _getch()
#include <limits>
#include <algorithm>
#include <cctype>
#include <set>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>
#include <cmath>
#include <ctime>
#include <iterator>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cstdlib> // for system()

using namespace std;

struct BusRoute
{
    string source;
    string destination;
    int distance;
    string busCompany;
    int price;
};

// Define the User struct
struct User
{
    string username;
    string name;
    int age;
    char sex;
    string phone;
    string email;
    string securityQuestionAnswer;
    string password;
};

// Structure to hold station data
struct Station
{
    int id;
    string name;
    string location;
};

struct Ticket
{
    string ticketNo;
    string username;
    string name;
    string dateTime;
    string source;
    string destination;
    int distance;
    int fare;
    string paymentMethod;
};
// Function declarations
void homePage();
void adminMenu();
void adminLogin();
void passengerMenu();
void handleBackOption();
void exitApp();
void resetAdminPassword();
void resetUserPassword();
void handleUserLogin();
void signUp();
void forgotPassword();
void userDashboard(const string &username);
void adminDashboard(const string &adminname);
void metroServiceDashboard(const string &username);
void stationDetails(const string &username);
void searchAndBook(const string &username);
void displayStationDetails(const string &stationName);
string toUpper(const string &str);
string toLower(const string &str);
void ticketSummary(const string &username);
void cancelTicket(const string &username);
void deleteUserAccount(const string &username);
void metroTicketSummary(const string &adminname);
void displayAllTickets();
void searchTicketByUsername();
void searchTicketToCancel(const string &username);
void displayTicketHistorySortedByFare();
void submitFeedback(const string &username);
void AdminFeedbackDashboard(const string &adminname);
void UserFeedbackDashboard(const string &username);
void viewFeedback();
void deleteFeedback(const string &username);
void generateFeedbackSummary();
void sortFeedbackByRating();
void GraphicalAnalysis(const string &adminname);
void callBusBooking();
void routeMap();
void displayBookingHistory();

// Function to exit the application
void exitApp()
{
    cout << "Exiting the application. Goodbye!" << endl;
    exit(0); // Exits the program
}

void displayBookingHistory()
{
    ifstream file("booking_history.txt");
    if (file.is_open())
    {
        string line;

        vector<BusRoute> bookings;

        string source, destination, busCompany;

        int distance, price;

        // Parse the booking history file and store the details in a vector
        while (getline(file, line))
        {

            if (line.find("Source: ") != string::npos)
            {

                // Extract source
                source = line.substr(8);
                // Skip "Destination" line
                getline(file, line);
                // Extract destination
                destination = line.substr(12);
                // Skip "Bus Company" line
                getline(file, line);
                // Extract bus company
                busCompany = line.substr(12);
                // Skip "Distance" line
                getline(file, line);
                // Extract distance
                distance = stoi(line.substr(10));
                // Skip "Price" line
                getline(file, line);
                // Extract price
                price = stoi(line.substr(7));

                bookings.push_back({source, destination, distance, busCompany, price});
                // Skip separator line
                getline(file, line);
            }
        }

        cout << "\n-------------------Booking History-------------------\n";

        cout << setw(15) << left << "Source" << " | "
             << setw(15) << "Destination" << " | "
             << setw(20) << "Bus Company" << " | "
             << setw(12) << "Distance" << " | "
             << setw(10) << "Price" << endl;

        cout << "------------------------------------------------------------" << endl;

        for (const auto &booking : bookings)
        {

            cout << setw(15) << left << booking.source << " | "
                 << setw(15) << booking.destination << " | "
                 << setw(20) << booking.busCompany << " | "
                 << setw(12) << booking.distance << " | "
                 << setw(10) << booking.price << endl;
        }

        cout << "------------------------------------------------------------\n";

        file.close();
    }

    else
    {
        cout << "Unable to open the booking history file!" << endl;
    }
}

// Home Page
void homePage()
{
    while (true)
    {
        int choice;
        cout << "====================================" << endl;
        cout << "         QUICK DESTINATION          " << endl;
        cout << "====================================" << endl;
        cout << "1. Admin Menu" << endl;
        cout << "2. Passenger Menu" << endl;
        cout << "3. Exit" << endl;
        cout << "====================================" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue; // restart the loop
        }

        switch (choice)
        {
        case 1:
            system("CLS");
            adminMenu();
            return;
        case 2:
            system("CLS");
            passengerMenu();
            return;
        case 3:
            system("CLS");
            exitApp();
            return;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

void adminMenu()
{
    int choice;
    cout << "====================================" << endl;
    cout << "         Admin Menu                 " << endl;
    cout << "====================================" << endl;
    cout << "1. Login as Admin" << endl;
    cout << "2. Reset User Password" << endl;
    cout << "3. Reset Admin Password" << endl;
    cout << "4. Back" << endl;
    cout << "5. Exit" << endl;
    cout << "====================================" << endl;
    cout << "Enter your choice: ";

    // Check if input is a valid integer
    if (!(cin >> choice))
    {
        // If input is invalid (not an integer)
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
        cout << "Invalid input! Please enter a number." << endl;
        adminMenu(); // Re-display Admin Menu
    }
    else
    {
        switch (choice)
        {
        case 1:
            system("CLS");
            // Login as Admin
            adminLogin();
            break;
        case 2:
            system("CLS");
            // Reset User Password
            resetUserPassword();
            break;
        case 3:
            system("CLS");
            // Reset Admin Password
            resetAdminPassword();
            break;
        case 4:
            system("CLS");
            // Go back to the home page
            homePage();
            break;
        case 5:
            system("CLS");
            // Exit the application
            exitApp();
            break;
        default:
            system("CLS");
            cout << "Invalid choice! Please try again." << endl;
            adminMenu(); // Re-display Admin Menu
            break;
        }
    }
}

// Admin Login
void adminLogin()
{
    string username, password;
    int attempts = 0;
    bool adminFound = false;

    while (attempts < 3)
    {
        cout << "Enter Admin Username: ";
        cin >> username;

        ifstream adminFile("admin.txt");

        if (!adminFile.is_open())
        {
            cerr << "Error: The file 'admin.txt' does not exist." << endl;
            return;
        }

        // Check if the username exists
        bool usernameExists = false;
        string line;
        while (getline(adminFile, line))
        {
            stringstream ss(line);
            string storedUsername, storedPassword, adminCode;
            getline(ss, storedUsername, ',');
            getline(ss, storedPassword, ',');
            getline(ss, adminCode, ',');

            if (username == storedUsername)
            {
                usernameExists = true;
                // Now prompt for the password if username exists
                cout << "Enter Admin Password: ";
                password = "";
                char ch;
                while ((ch = _getch()) != 13)
                {
                    cout << "*";
                    password += ch;
                }

                if (password == storedPassword)
                {
                    cout << "\nLogin successful!" << endl;
                    adminDashboard(username); // Go to Admin Menu after successful login
                    return;
                }
                else
                {
                    cout << "\nIncorrect password. Attempt " << attempts + 1 << "/3." << endl;
                    attempts++;
                    break; // Ask for username again
                }
            }
        }

        if (!usernameExists)
        {
            cout << "\nUsername does not exist. Please try again." << endl;
            cout << "\n Attempt " << attempts + 1 << "/3." << endl;
            attempts++;
        }

        if (attempts >= 3)
        {
            cout << "Too many failed attempts. Returning to home page." << endl;
            homePage();
        }
    }
}

// Handle back option
void handleBackOption()
{
    cout << "Press any key to go back..." << endl;
    _getch();
    homePage();
}

// Reset Admin Password
void resetAdminPassword()
{
    string username, securityCode, storedUsername, storedPassword, storedSecurityCode;
    string newPassword, confirmPassword;
    bool adminFound = false;

    cout << "Enter Admin Username: ";
    cin >> username;

    // Open the admin file to check if the username exists and retrieve the security code
    ifstream adminFile("admin.txt");
    if (!adminFile)
    {
        cout << "Error: Unable to open admin file." << endl;
        homePage();
        return;
    }

    string line;
    while (getline(adminFile, line))
    {
        stringstream ss(line);
        getline(ss, storedUsername, ',');
        getline(ss, storedPassword, ',');
        getline(ss, storedSecurityCode, ',');

        if (username == storedUsername)
        {
            adminFound = true;
            break;
        }
    }
    adminFile.close();

    if (!adminFound)
    {
        cout << "Admin username not found. Returning to home page." << endl;
        // Call homePage();
        homePage();
        return;
    }

    // Ask for the security code
    cout << "Enter Security Code: ";
    securityCode = "";
    char ch;
    while ((ch = _getch()) != 13) // 13 is Enter key
    {
        cout << "*";
        securityCode += ch;
    }

    if (securityCode == storedSecurityCode)
    {
        cout << "\nEnter New Password: ";
        newPassword = "";
        while ((ch = _getch()) != 13)
        {
            cout << "*";
            newPassword += ch;
        }

        cout << "\nConfirm New Password: ";
        confirmPassword = "";
        while ((ch = _getch()) != 13)
        {
            cout << "*";
            confirmPassword += ch;
        }

        if (newPassword == confirmPassword)
        {
            // Update the admin file with the new password
            ifstream inputFile("admin.txt");
            ofstream tempFile("temp.txt");

            while (getline(inputFile, line))
            {
                stringstream ss(line);
                getline(ss, storedUsername, ',');
                getline(ss, storedPassword, ',');
                getline(ss, storedSecurityCode, ',');

                if (storedUsername == username)
                {
                    tempFile << storedUsername << "," << newPassword << "," << storedSecurityCode << endl;
                }
                else
                {
                    tempFile << storedUsername << "," << storedPassword << "," << storedSecurityCode << endl;
                }
            }

            inputFile.close();
            tempFile.close();

            // Replace the old file with the updated one
            remove("admin.txt");
            rename("temp.txt", "admin.txt");

            cout << "\nPassword reset successfully!" << endl;
            homePage();
            return;
        }
        else
        {
            cout << "\nPasswords do not match! Try again." << endl;
            resetAdminPassword();
        }
    }
    else
    {
        cout << "\nIncorrect security code. Returning to home page." << endl;
        // Call homePage();
        homePage();
        return;
    }
}

vector<string> split(const string &line, char delimiter)
{
    vector<string> fields;
    stringstream ss(line);
    string field;

    while (getline(ss, field, delimiter))
    {
        fields.push_back(field);
    }

    return fields;
}

string join(const vector<string> &vec, char delimiter)
{
    stringstream result;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        result << vec[i];
        if (i != vec.size() - 1)
        {
            result << delimiter;
        }
    }
    return result.str();
}

// Reset User Password
void resetUserPassword()
{

    string adminUsername, adminPassword, userUsername, newPassword, confirmPassword;

    // Step 1: Admin Authentication
    cout << "Enter Admin Username: ";
    cin >> adminUsername;

    cout << "Enter Admin Password: ";
    adminPassword = "";
    char ch;
    while ((ch = _getch()) != 13) // 13 is the ASCII code for Enter
    {
        cout << "*";
        adminPassword += ch;
    }
    cout << endl;

    // Verify admin credentials from admin.txt
    ifstream adminFile("admin.txt");
    if (!adminFile.is_open())
    {
        cerr << "Error: Unable to open admin.txt file." << endl;
        homePage();
        return;
    }

    bool adminAuthenticated = false;
    string adminLine;
    while (getline(adminFile, adminLine))
    {
        vector<string> adminFields = split(adminLine, ',');
        if (adminFields.size() >= 2 && adminFields[0] == adminUsername && adminFields[1] == adminPassword)
        {
            adminAuthenticated = true;
            break;
        }
    }
    adminFile.close();

    if (!adminAuthenticated)
    {
        cout << "Incorrect Admin credentials. Returning to home page." << endl;
        homePage();
        return;
    }

    // Step 2: Get User Details
    cout << "Enter Username of User to Reset Password: ";
    cin >> userUsername;

    cout << "Enter New Password: ";
    newPassword = "";
    while ((ch = _getch()) != 13)
    {
        cout << "*";
        newPassword += ch;
    }
    cout << endl;

    cout << "Confirm New Password: ";
    confirmPassword = "";
    while ((ch = _getch()) != 13)
    {
        cout << "*";
        confirmPassword += ch;
    }
    cout << endl;

    if (newPassword != confirmPassword)
    {
        cout << "Passwords do not match! Try again." << endl;
        homePage();
        return;
    }

    // Step 3: Update users.txt
    ifstream usersFile("users.txt");
    if (!usersFile.is_open())
    {
        cerr << "Error: Unable to open users.txt file." << endl;
        homePage();
        return;
    }

    vector<string> updatedLines;
    string userLine;
    bool userFound = false;

    while (getline(usersFile, userLine))
    {
        vector<string> userFields = split(userLine, ',');
        if (userFields.size() >= 2 && userFields[0] == userUsername)
        {
            userFields[1] = newPassword; // Update the password field
            userFound = true;
        }
        updatedLines.push_back(join(userFields, ','));
    }

    usersFile.close();

    if (!userFound)
    {
        cout << "Error: User not found in the system.\n"
             << endl;
        homePage();
        return;
    }

    ofstream usersFileOut("users.txt");
    if (!usersFileOut.is_open())
    {
        cerr << "Error: Unable to write to users.txt file.\n"
             << endl;
        homePage();
        return;
    }

    for (const string &line : updatedLines)
    {
        usersFileOut << line << endl;
    }

    usersFileOut.close();

    cout << "Password reset successfully!\n"
         << endl;
    homePage();
    return;
}

void passengerMenu()
{
    int choice;

    cout << "\n================= Passenger Menu =================" << endl;
    cout << "1. Login as User" << endl;
    cout << "2. Sign Up as User" << endl;
    cout << "3. Forgot Password" << endl;
    cout << "4. Back" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================================" << endl;
    cout << "Enter your choice: ";

    // Take input and validate in one step
    if (!(cin >> choice))
    {
        // If input is invalid (not an integer)
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
        cout << "Invalid input! Please enter a number." << endl;
        passengerMenu(); // Re-display Passenger Menu
    }
    else
    {
        switch (choice)
        {
        case 1:
            system("CLS");
            handleUserLogin(); // Handle user login
            break;
        case 2:
            system("CLS");
            signUp(); // Sign Up as User
            break;
        case 3:
            system("CLS");
            forgotPassword(); // Forgot Password
            break;
        case 4:
            system("CLS");
            homePage();
            return; // Return to the previous menu (e.g., homePage)
        case 5:
            system("CLS");
            cout << "Thank you for using the system. Goodbye!" << endl;
            exit(0);
        default:
            system("CLS");
            cout << "Invalid choice. Please try again." << endl;
            passengerMenu(); // Re-display Passenger Menu
        }
    }
}

// Function for handling user login
void handleUserLogin()
{
    string username, password;
    bool userFound = false;
    int attempts = 0;

    while (attempts < 3)
    {
        cout << "Enter Passenger Username: ";
        cin >> username;
        cout << "Enter Password: ";
        password = "";
        char ch;
        while ((ch = _getch()) != 13)
        { // 13 is Enter key
            cout << "*";
            password += ch;
        }

        // Check if username and password match
        ifstream userFile("users.txt");
        string line;
        while (getline(userFile, line))
        {
            stringstream ss(line);
            string storedUsername, storedPassword, otherDetails;

            // Parse CSV values
            getline(ss, storedUsername, ',');
            getline(ss, storedPassword, ',');
            getline(ss, otherDetails); // Skip any remaining details in the row

            // Check if credentials match
            if (username == storedUsername && password == storedPassword)
            {
                userFound = true;
            }
        }
        userFile.close();

        if (userFound)
        {
            cout << "\nLogin successful!" << endl;
            userDashboard(username); // Call the user dashboard
            return;
        }
        else
        {
            attempts++;
            cout << "\nInvalid credentials. Attempt " << attempts << "/3." << endl;
            if (attempts >= 3)
            {
                cout << "Too many failed attempts. Returning to home page." << endl;
                homePage();
                return;
            }
        }
    }
}

// User Dashboard
void userDashboard(const string &username)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       USER DASHBOARD          " << endl;
        cout << "===============================" << endl;
        cout << "Welcome, " << username << "!" << endl;
        cout << "1. Metro Service" << endl;
        cout << "2. Bus Reservation." << endl;
        cout << "3. Feedback" << endl;
        cout << "4. Logout" << endl;
        cout << "5. Delete User Account." << endl;
        cout << "6. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            system("CLS");
            metroServiceDashboard(username);
            break;
        case 2:
            system("CLS");
            callBusBooking();
            break;
        case 3:
            system("CLS");
            // User Feedback Dashboard.
            UserFeedbackDashboard(username);
            break;
        case 4:
            system("CLS");
            cout << "Logging out. Returning to Home Page" << endl;
            // Go Home Page
            homePage();
            return;
        case 5:
            system("CLS");
            deleteUserAccount(username);
            break;
        case 6:
            system("CLS");
            exitApp(); // Exit the application
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

// Metro Service Dashboard
void metroServiceDashboard(const string &username)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       METRO SERVICE DASHBOARD " << endl;
        cout << "===============================" << endl;
        cout << "Welcome to Metro Service, " << username << "!" << endl;
        cout << "1. Station Details" << endl;
        cout << "2. View Route Map" << endl;
        cout << "3. Book Ticket" << endl;
        cout << "4. Ticket Summary" << endl;
        cout << "5. Cancel Ticket" << endl;
        cout << "6. Back" << endl;
        cout << "7. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            stationDetails(username); // Display station details
            break;
        case 2:
            routeMap();
            break;
        case 3:
            searchAndBook(username); // Call book ticket function
            break;
        case 4:
            ticketSummary(username);
            return; // Return to user dashboard
        case 5:
            cancelTicket(username);
            return; // Return to user dashboard
        case 6:
            userDashboard(username);
            return; // Return to user dashboard
        case 7:
            exitApp(); // Exit the application
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

// KMP Algorithm for string matching
vector<int> KMPPreprocess(const string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0); // Longest prefix suffix array
    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMPSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0)
        return false;

    vector<int> lps = KMPPreprocess(pattern);
    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            return true; // Found pattern
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return false; // Not found
}

// Read station data from file
vector<Station> readStationsFromFile(const string &filename)
{
    vector<Station> stations;
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        Station station;
        string id, name, location;

        // Read the station fields
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, location);

        // Trim whitespace and set values
        station.id = stoi(id);
        station.name = name.substr(name.find_first_not_of(" "));
        station.location = location.substr(location.find_first_not_of(" "));

        stations.push_back(station);
    }

    return stations;
}

// Function to display station details in a table format
void displayStationDetails(const string &stationName)
{
    vector<Station> stations = readStationsFromFile("stations.txt");
    bool found = false;

    // Header for the output table
    cout << "+-------------------------------------------------------------------------------------+\n";
    cout << "| Station ID | Station Name                       | Location                          |\n";
    cout << "+-------------------------------------------------------------------------------------+\n";

    for (const auto &station : stations)
    {
        string lowerName = station.name;
        string lowerInput = stationName;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

        if (KMPSearch(lowerName, lowerInput))
        {
            found = true;
            cout << "| " << setw(10) << station.id << " | " << setw(30) << station.name << " | " << setw(30) << station.location << " |\n";
        }
    }

    cout << "+-------------------------------------------------------------------------------------+\n";

    if (!found)
    {
        cout << "No matching stations found!" << endl;
    }
}

// Function to display all stations
void displayAllStations()
{
    vector<Station> stations = readStationsFromFile("stations.txt");

    // Header for the output table
    cout << "+---------------------------------------------------+\n";
    cout << "| Station ID | Station Name                       | Location                          |\n";
    cout << "+---------------------------------------------------+\n";

    for (const auto &station : stations)
    {
        cout << "| " << setw(10) << station.id << " | " << setw(30) << station.name << " | " << setw(30) << station.location << " |\n";
    }

    cout << "+---------------------------------------------------+\n";
}

vector<Station> readStationsFromFile1(const string &fileName)
{
    vector<Station> stations;
    ifstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << fileName << endl;
        return stations;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        Station station;
        string idStr;

        // Parse station details
        if (getline(ss, idStr, ',') && getline(ss, station.name, ',') && getline(ss, station.location, ','))
        {
            station.id = stoi(idStr);
            stations.push_back(station);
        }
    }

    file.close();
    return stations;
}

// Function to display matching stations
void displayMatchingStations(const vector<string> &matchingStations, const vector<Station> &allStations)
{
    cout << "+-------------------------------------------------------------------------------------+\n";
    cout << "| Station ID | Station Name                       | Location                          |\n";
    cout << "+-------------------------------------------------------------------------------------+\n";

    for (const auto &station : allStations)
    {
        string lowerName = station.name;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

        for (const auto &match : matchingStations)
        {
            string lowerMatch = match;
            transform(lowerMatch.begin(), lowerMatch.end(), lowerMatch.begin(), ::tolower);

            if (lowerName.find(lowerMatch) != string::npos)
            {
                cout << "| " << setw(10) << station.id << " | " << setw(30) << station.name << " | " << setw(30) << station.location << " |\n";
                break;
            }
        }
    }

    cout << "+-------------------------------------------------------------------------------------+\n";
}

// Metro Station Details (Modified)
void stationDetails(const string &username)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       METRO STATION DETAILS   " << endl;
        cout << "===============================" << endl;
        cout << "1. Search for a Station" << endl;
        cout << "2. Display All Stations" << endl;
        cout << "3. Back" << endl;
        cout << "4. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
        SEARCH_AGAIN:
            cout << "Enter station name to search: ";
            string searchStation;
            cin.ignore(); // To ignore any leftover newline from previous input
            getline(cin, searchStation);

            // Convert the search input to lowercase for case-insensitive matching
            searchStation = toLower(searchStation);

            vector<Station> stations = readStationsFromFile("stations.txt");

            vector<string> matchingStations;
            for (const auto &station : stations)
            {
                string stationNameLower = toLower(station.name);
                if (KMPSearch(stationNameLower, searchStation))
                {
                    matchingStations.push_back(station.name);
                }
            }

            if (matchingStations.empty())
            {
                cout << "No matching stations found for: " << searchStation << endl;
            }
            else
            {
                cout << "Matching stations: \n";
                string fileName = "stations.txt";

                // Read all stations from file
                vector<Station> allStations = readStationsFromFile1(fileName);

                // Display matching stations
                displayMatchingStations(matchingStations, allStations);
                cout << "\n";
                cout << "Would you like to search again? (yes/no): ";
                string choice;
                getline(cin, choice);
                if (toLower(choice) == "yes" || toLower(choice) == "y")
                {
                    goto SEARCH_AGAIN; // Restart search
                }
            }
            break;
        }
        case 2:
            displayAllStations(); // Display all stations
            break;
        case 3:
            metroServiceDashboard(username);
            return; // Go back to Metro Service Dashboard
        case 4:
            exitApp(); // Exit the application
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

// Function to check if a username exists in the file
bool isUserPresent(const string &username)
{
    const string filename = "users.txt"; // File name is users.txt
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Could not open " << filename << " for reading.\n";
        return false;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string storedUsername;
        getline(ss, storedUsername, ','); // Extract the username (first field in the line)

        if (storedUsername == username)
        {
            file.close();
            return true; // User found
        }
    }

    file.close();
    return false; // User not found
}

void signUp()
{
Restart:
    User newUser;

    // Get username
    cout << "Enter Username: ";
    cin >> newUser.username;

    if (isUserPresent(newUser.username))
    {
        cout << "Username " << newUser.username << "already exists.\n " << ". Please try another username.\n";
        goto Restart;
    }

    // Get name
    cout << "Enter Name: ";
    cin.ignore(); // To handle leftover newline from previous input
    getline(cin, newUser.name);

    // Get age with validation
    while (true)
    {
        cout << "Enter Age: ";
        cin >> newUser.age;

        if (cin.fail() || newUser.age <= 0)
        { // Non-numeric or non-positive age
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid age. Please enter a valid positive number." << endl;
        }
        else
        {
            break;
        }
    }

    // Get sex with validation
    while (true)
    {
        string inputSex;
        cout << "Enter Sex (M/F or Male/Female): ";
        cin >> inputSex;

        // Normalize input to lower case and check
        transform(inputSex.begin(), inputSex.end(), inputSex.begin(), ::tolower);
        if (inputSex == "m" || inputSex == "male")
        {
            newUser.sex = 'M';
            break;
        }
        else if (inputSex == "f" || inputSex == "female")
        {
            newUser.sex = 'F';
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'M', 'F', 'Male', or 'Female'." << endl;
        }
    }

    // Get phone number with validation
    while (true)
    {
        cout << "Enter Phone Number: ";
        cin >> newUser.phone;

        if (newUser.phone.length() != 10 || !all_of(newUser.phone.begin(), newUser.phone.end(), ::isdigit))
        {
            cout << "Invalid phone number. Please enter a 10-digit numeric value." << endl;
        }
        else
        {
            break;
        }
    }

    // Get email
    cout << "Enter Email: ";
    cin >> newUser.email;

    // Get security question answer
    cout << "Enter Security Question (Favorite Food): ";
    cin.ignore(); // To handle leftover newline
    getline(cin, newUser.securityQuestionAnswer);

    // Get password
    cout << "Enter Password: ";
    newUser.password = "";
    char ch;
    // 13 is Enter key
    while ((ch = _getch()) != 13)
    {
        cout << "*";
        newUser.password += ch;
    }

    // Confirm password
    string confirmPassword;
    cout << "\nConfirm Password: ";
    confirmPassword = "";
    while ((ch = _getch()) != 13)
    {
        cout << "*";
        confirmPassword += ch;
    }

    if (newUser.password != confirmPassword)
    {
        cout << "\nPasswords do not match. Please restart the sign-up process." << endl;
        passengerMenu();
        return;
    }

    // Store the new user in a file
    // Open the file in append mode
    ofstream userFile("users.txt", ios::app);

    if (!userFile)
    {
        cerr << "Error: Could not open the file for writing!" << endl;
        homePage();
        return;
    }

    // Write user data as a CSV row
    userFile << newUser.username << ","
             << newUser.password << ","
             << newUser.name << ","
             << newUser.age << ","
             << newUser.sex << ","
             << newUser.phone << ","
             << newUser.email << ","
             << newUser.securityQuestionAnswer << endl;

    userFile.close();
    cout << "\nSign up successful!" << endl;
    // Getting to Home Page
    homePage();
    return;
}

// Forgot Password Function
void forgotPassword()
{
    string username, answer, newPassword;
    bool userFound = false;

    cout << "Enter Username: ";
    cin >> username;

    // Open the users file to check if the username exists
    ifstream userFile("users.txt");
    if (!userFile)
    {
        cout << "Error: Unable to open users file." << endl;
        // Getting to Home Page
        homePage();
        return;
    }

    string storedUsername, storedPassword, storedName, storedAge, storedSex, storedPhone, storedEmail, storedAnswer;
    string line;
    while (getline(userFile, line))
    {
        stringstream ss(line);
        getline(ss, storedUsername, ',');
        getline(ss, storedPassword, ',');
        getline(ss, storedName, ',');
        getline(ss, storedAge, ',');
        getline(ss, storedSex, ',');
        getline(ss, storedPhone, ',');
        getline(ss, storedEmail, ',');
        getline(ss, storedAnswer, ',');

        if (username == storedUsername)
        {
            userFound = true;
            cout << "Security Question: What is your favorite food? ";
            cin >> answer;

            if (answer == storedAnswer)
            {
                cout << "Enter New Password: ";
                newPassword = "";
                char ch;
                while ((ch = _getch()) != 13) // Password input masked with '*'
                {
                    cout << "*";
                    newPassword += ch;
                }

                cout << "\nConfirm New Password: ";
                string confirmPassword = "";
                while ((ch = _getch()) != 13)
                {
                    cout << "*";
                    confirmPassword += ch;
                }

                if (newPassword == confirmPassword)
                {
                    // Update the users file with the new password
                    ifstream fileIn("users.txt");
                    ofstream tempFile("temp.txt");

                    while (getline(fileIn, line))
                    {
                        stringstream ss(line);
                        getline(ss, storedUsername, ',');
                        getline(ss, storedPassword, ',');
                        getline(ss, storedName, ',');
                        getline(ss, storedAge, ',');
                        getline(ss, storedSex, ',');
                        getline(ss, storedPhone, ',');
                        getline(ss, storedEmail, ',');
                        getline(ss, storedAnswer, ',');

                        if (storedUsername == username)
                        {
                            tempFile << storedUsername << "," << newPassword << "," << storedName << "," << storedAge << "," << storedSex << "," << storedPhone << "," << storedEmail << "," << storedAnswer << endl;
                        }
                        else
                        {
                            tempFile << line << endl;
                        }
                    }

                    fileIn.close();
                    tempFile.close();
                    remove("users.txt");
                    rename("temp.txt", "users.txt");

                    cout << "\nPassword reset successful!" << endl;
                    // Getting to Home Page
                    homePage();
                    return;
                }
                else
                {
                    cout << "\nPasswords do not match. Returning to Passenger Menu." << endl;
                    // Getting to Passenger Menu
                    passengerMenu();
                    return;
                }
            }
            else
            {
                cout << "\nIncorrect answer to security question. Returning to Home Page." << endl;
                // Getting to Home Page
                homePage();
                return;
            }
        }
    }
    userFile.close();

    if (!userFound)
    {
        cout << "\nUsername not found. Returning to Passenger Menu." << endl;
        // Getting to Passenger Menu
        passengerMenu();
    }
}

// Main function
int main()
{

    homePage();
    return 0;
}

const int INF = 1e9; // Representation of infinity for Dijkstra's algorithm

// Utility function to get current timestamp for unique ticket number and booking date/time
string getCurrentTimestamp()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << setfill('0') << setw(4) << 1900 + ltm->tm_year
       << setw(2) << 1 + ltm->tm_mon
       << setw(2) << ltm->tm_mday
       << setw(2) << ltm->tm_hour
       << setw(2) << ltm->tm_min
       << setw(2) << ltm->tm_sec;
    return ss.str();
}

// Utility function to get current date and time for ticket receipts
string getCurrentDateTime()
{
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << setw(2) << setfill('0') << ltm->tm_mday << "-"
       << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-"
       << 1900 + ltm->tm_year << " "
       << setw(2) << setfill('0') << ltm->tm_hour << ":"
       << setw(2) << setfill('0') << ltm->tm_min;
    return ss.str();
}

// Print a styled ticket receipt
void printReceipt(const string &username, const string &name, const string &phone, const string &email, const string &sex,
                  const string &source, const string &destination, int distance, double fare, const string &ticketNo, const string &bookingDateTime, const string &paymentMethod)
{

    cout << "\n==============================================" << endl;
    cout << "              TICKET RECEIPT                 " << endl;
    cout << "==============================================" << endl;
    cout << "Ticket Number      : " << ticketNo << endl;
    cout << "Booking Date/Time  : " << bookingDateTime << endl;
    cout << "Passenger Name     : " << name << endl;
    cout << "Username           : " << username << endl;
    cout << "Phone Number       : " << phone << endl;
    cout << "Email Address      : " << email << endl;
    cout << "Sex                : " << sex << endl;
    cout << "Source Station     : " << source << endl;
    cout << "Destination Station: " << destination << endl;
    cout << "Distance           : " << distance << " km" << endl;
    cout << "Fare               : Rs. " << fare << endl;
    cout << "Payment Method     : " << paymentMethod << endl;
    cout << "==============================================" << endl;
    cout << "   Thank you for choosing Quick Destination!  " << endl;
    cout << "==============================================\n"
         << endl;
    homePage();
}

// Dijkstra's algorithm for shortest path
pair<int, vector<int>> dijkstra(const vector<vector<int>> &matrix, int src, int dest)
{
    int n = matrix.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        int u = -1;
        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
            {
                u = v;
            }
        }

        if (dist[u] == INF)
            break;

        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (matrix[u][v] && !visited[v] && dist[u] + matrix[u][v] < dist[v])
            {
                dist[v] = dist[u] + matrix[u][v];
                parent[v] = u;
            }
        }
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    return {dist[dest], path};
}

// Load adjacency matrix from a file
vector<vector<int>> loadAdjacencyMatrix(const string &filename, vector<string> &stations)
{
    ifstream file(filename);
    string line;

    getline(file, line); // Read station names as the first line
    stringstream ss(line);
    string station;
    while (getline(ss, station, ','))
    {
        stations.push_back(station);
    }

    vector<vector<int>> matrix;
    while (getline(file, line))
    {
        stringstream rowStream(line);
        vector<int> row;
        int value;
        while (rowStream >> value)
        {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    return matrix;
}

// Load station details from station.txt
map<int, pair<string, string>> loadStations(const string &filename, vector<string> &stationNames)
{
    ifstream file(filename);
    string line;
    map<int, pair<string, string>> stations;

    while (getline(file, line))
    {
        stringstream ss(line);
        int id;
        string stationName, stationLocation;
        char delimiter;

        ss >> id >> delimiter;
        getline(ss, stationName, ',');
        getline(ss, stationLocation);

        stations[id] = {stationName, stationLocation};
        stationNames.push_back(stationName);
    }

    return stations;
}

// Fetch user details from users.txt
bool fetchUserDetails(const string &username, string &name, string &phone, string &email, string &sex)
{
    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string storedUsername, storedPass, storedName, storedAge, storedPhone, storedEmail, storedSex;
        getline(ss, storedUsername, ',');
        getline(ss, storedPass, ',');
        getline(ss, storedName, ',');
        getline(ss, storedAge, ',');
        getline(ss, storedSex, ',');
        getline(ss, storedPhone, ',');
        getline(ss, storedEmail, ',');

        if (storedUsername == username)
        {
            name = storedName;
            phone = storedPhone;
            email = storedEmail;
            sex = storedSex;
            return true;
        }
    }
    return false;
}

// Book ticket after finding the shortest path
void bookTicket(const string &username, const string &source, const string &destination, int distance)
{
    string name, phone, email, sex;
    if (!fetchUserDetails(username, name, phone, email, sex))
    {
        cout << "Error: User details not found for username: " << username << endl;
        return;
    }

    cout << "Payment Methods: Cash, Card, UPI" << endl;
    string paymentMethod;
    string uppperpaymentMethod;
    while (true)
    {
        cout << "Enter Payment Method: ";
        cin >> paymentMethod;
        uppperpaymentMethod = toUpper(paymentMethod);
        if (uppperpaymentMethod == "CASH" || uppperpaymentMethod == "CARD" || uppperpaymentMethod == "UPI")
        {
            break;
        }
        cout << "Invalid payment method! Please choose Cash, Card, or UPI." << endl;
    }

    double fare = distance * 3.0; // Example fare calculation
    string ticketNo = getCurrentTimestamp();
    string bookingDateTime = getCurrentDateTime();

    // Save receipt data to tickets.txt in CSV format
    ofstream ticketsFile("tickets.txt", ios::app); // Open file in append mode
    if (ticketsFile.is_open())
    {
        ticketsFile << ticketNo << ","
                    << bookingDateTime << ","
                    << name << ","
                    << username << ","
                    << phone << ","
                    << email << ","
                    << sex << ","
                    << source << ","
                    << destination << ","
                    << distance << ","
                    << fare << ","
                    << uppperpaymentMethod << endl;
        ticketsFile.close();
    }
    else
    {
        cerr << "Error: Unable to open tickets.txt file for writing." << endl;
        cerr << "Any deducted amount will be refunded to your payment method shortly." << endl;
        exitApp();
    }

    printReceipt(username, name, phone, email, sex, source, destination, distance, fare, ticketNo, bookingDateTime, uppperpaymentMethod);
}

bool rabinKarpSubstringMatch(const string &text, const string &pattern)
{
    int d = 256; // Number of characters in the input alphabet
    int q = 101; // A prime number for hashing
    int m = pattern.size();
    int n = text.size();
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1) % q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window of text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {
        // Check the hash values of current window of text and pattern
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                return true;
        }

        // Calculate hash value for next window of text
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
    return false;
}

string toLower(const string &str)
{
    string result;
    transform(str.begin(), str.end(), back_inserter(result), ::tolower);
    return result;
}

string toUpper(const string &str)
{
    string result;
    transform(str.begin(), str.end(), back_inserter(result), ::toupper);
    return result;
}

// Search and book tickets
void searchAndBook(const string &username)
{
    while (true)
    {
        vector<string> stationNames;
        map<int, pair<string, string>> stations = loadStations("stations.txt", stationNames);
        vector<vector<int>> adjacencyMatrix = loadAdjacencyMatrix("matrix.txt", stationNames);

        string source, destination;
        int srcIndex = -1, destIndex = -1;

        cin.ignore(); // Clear input buffer

        // Source station input
        while (true)
        {
            cout << "Enter Source Station: ";
            getline(cin, source);

            string sourceLower = toLower(source); // Convert input to lowercase
            auto it = find_if(stationNames.begin(), stationNames.end(), [&sourceLower](const string &station)
                              { return toLower(station) == sourceLower; });

            if (it != stationNames.end())
            {
                srcIndex = distance(stationNames.begin(), it);
                break;
            }

            // Suggest similar station names
            vector<string> suggestions;
            for (const string &station : stationNames)
            {
                if (rabinKarpSubstringMatch(toLower(station), sourceLower))
                {
                    suggestions.push_back(station);
                }
            }

            if (!suggestions.empty())
            {
                cout << "Invalid source station! Did you mean: ";
                for (const string &suggestion : suggestions)
                {
                    cout << suggestion << " ";
                }
                cout << "?" << endl;
            }
            else
            {
                cout << "Invalid source station! No matching stations found." << endl;
            }
        }

        // Destination station input
        while (true)
        {
            cout << "Enter Destination Station: ";
            getline(cin, destination);

            string destinationLower = toLower(destination); // Convert input to lowercase
            auto it = find_if(stationNames.begin(), stationNames.end(), [&destinationLower](const string &station)
                              { return toLower(station) == destinationLower; });

            if (it != stationNames.end())
            {
                destIndex = distance(stationNames.begin(), it);
                break;
            }

            // Suggest similar station names
            vector<string> suggestions;
            for (const string &station : stationNames)
            {
                if (rabinKarpSubstringMatch(toLower(station), destinationLower))
                {
                    suggestions.push_back(station);
                }
            }

            if (!suggestions.empty())
            {
                cout << "Invalid destination station! Did you mean: ";
                for (const string &suggestion : suggestions)
                {
                    cout << suggestion << " ";
                }
                cout << "?" << endl;
            }
            else
            {
                cout << "Invalid destination station! No matching stations found." << endl;
            }
        }

        // Dijkstra's algorithm for shortest path
        auto result = dijkstra(adjacencyMatrix, srcIndex, destIndex);
        int distance = result.first;
        vector<int> path = result.second;

        if (distance == INF)
        {
            cout << "No path exists between " << source << " and " << destination << "." << endl;
            continue;
        }

        double fare = distance * 3.0; // Example fare calculation
        cout << "\nShortest Path Found Successfully!" << endl;
        cout << "Total Distance: " << distance << " km" << endl;
        cout << "Total Fare: ₹" << fare << endl;

        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i)
        {
            cout << stationNames[path[i]];
            if (i != path.size() - 1)
                cout << " -> ";
        }
        cout << endl;

        int choice;

        cout << "====================================" << endl;
        cout << "1. Book Ticket" << endl;
        cout << "2. Search Again" << endl;
        cout << "3. Back" << endl;
        cout << "4. Exit" << endl;
        cout << "====================================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            // If input is invalid (not an integer)
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            cout << "Invalid input! Please enter a number." << endl;
            metroServiceDashboard(username);
            ; // Re-display Metro Service Dashboard
        }
        else
        {

            // Process valid input
            switch (choice)
            {
            case 1:
                bookTicket(username, source, destination, distance);
                return; // Exit the loop after calling bookTicket
            case 2:
                searchAndBook(username);
                return; // Exit the loop after calling Search And Booking
            case 3:
                metroServiceDashboard(username);
                return; // Exit the loop after calling
            case 4:
                exitApp();
                return; // Exit the loop after exiting the application
            default:
                cout << "Invalid choice! Please try again." << endl;
                searchAndBook(username);
            }
        }
    }
}

// Function to display all booked tickets of a specific user from tickets.txt
void ticketSummary(const string &username)
{
    ifstream ticketsFile("tickets.txt");
    if (!ticketsFile.is_open())
    {
        cerr << "Error: Unable to open tickets.txt file for reading." << endl;
        return;
    }

    vector<vector<string>> userTickets;
    string line;

    // Read the tickets.txt file line by line
    while (getline(ticketsFile, line))
    {
        stringstream ss(line);
        vector<string> ticketData;
        string field;

        // Split the line into fields
        while (getline(ss, field, ','))
        {
            ticketData.push_back(field);
        }

        // Check if the ticket belongs to the specific user
        if (ticketData.size() >= 12 && ticketData[3] == username)
        {
            userTickets.push_back(ticketData);
        }
    }

    ticketsFile.close();

    if (userTickets.empty())
    {
        cout << "No tickets found for user: " << username << endl;
        return;
    }

    // Display tickets in a styled table format
    cout << "\n==================================================================================" << endl;
    cout << "                                    Ticket Summary                                  " << endl;
    cout << "====================================================================================" << endl;
    cout << setw(15) << left << "Ticket No"
         << setw(20) << "Username"
         << setw(20) << "Name"
         << setw(20) << "Date/Time"
         << setw(15) << "Source"
         << setw(15) << "Destination"
         << setw(10) << "Distance"
         << setw(10) << "Fare"
         << setw(15) << "Payment" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    for (const auto &ticket : userTickets)
    {
        cout << setw(15) << left << ticket[0]   // Ticket Number
             << setw(20) << ticket[4]           // Username
             << setw(20) << ticket[3]           // Name
             << setw(20) << ticket[1]           // Date/Time
             << setw(15) << ticket[7]           // Source
             << setw(15) << ticket[8]           // Destination
             << setw(10) << ticket[9]           // Distance
             << setw(10) << ticket[10]          // Fare
             << setw(15) << ticket[11] << endl; // Payment Method
    }

    cout << "====================================================================================" << endl;

    // Ask if the user wants to print a receipt
    cout << "\nDo you want to print a receipt for a ticket? (yes/no): ";
    string choice;
    cin >> choice;

    if (choice == "yes" || choice == "Yes" || choice == "Y" || choice == "y")
    {
        cout << "Enter the Ticket Number: ";
        string ticketNo;
        cin >> ticketNo;

        // Search for the ticket with the specified ticket number
        for (const auto &ticket : userTickets)
        {
            if (ticket[0] == ticketNo)
            {
                // Call the printReceipt function
                printReceipt(
                    username, ticket[2], ticket[4], ticket[5], ticket[6],
                    ticket[7], ticket[8], stoi(ticket[9]), stod(ticket[10]),
                    ticket[0], ticket[1], ticket[11]);
                homePage();
                return;
            }
        }

        // If ticket number is not found
        cout << "Error: No ticket found with Ticket Number: " << ticketNo << endl;
    }
    else
    {
        cout << "Invalid Input...!!!\n";
        cout << "Getting to Dashboard.\n";
        metroServiceDashboard(username);
        return;
    }
}

// Admin Dashboard
void adminDashboard(const string &adminname)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       ADMIN DASHBOARD          " << endl;
        cout << "===============================" << endl;
        cout << "Welcome Admin, " << adminname << "!" << endl;
        cout << "1. Metro Ticket Summary " << endl;
        cout << "2. Bus Reservation History " << endl;
        cout << "3. Feedback Dashboard." << endl;
        cout << "4. Logout" << endl;
        cout << "5. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            metroTicketSummary(adminname);
            break;
        case 2:
            displayBookingHistory();
            break;
        case 3:
            AdminFeedbackDashboard(adminname);
            cout << "This option is not yet decided." << endl;
            break;
        case 4:
            // Go Home Page
            homePage();
            return;
        case 5:
            // Exit the application
            exitApp();
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

void metroTicketSummary(const string &adminname)
{
    int ch;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       Metro Ticket Summary" << endl;
        cout << "===============================" << endl;
        cout << "\n1. Show All" << endl;
        cout << "2. Show Sorted (by fare)." << endl;
        cout << "3. Search by username" << endl;
        cout << "4. Logout" << endl;
        cout << "5. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> ch))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (ch)
        {
        case 1:
            displayAllTickets();
            break;
        case 2:
            displayTicketHistorySortedByFare();
            break;
        case 3:
            searchTicketByUsername();
            break;

        case 4:
            // Getting to Home Page
            homePage();
            break;
        case 5:
            // Exitting the App.
            exitApp();
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

void displayAllTickets()
{
    ifstream file("tickets.txt");
    if (!file.is_open())
    {
        cerr << "Error: The file 'tickets.txt' does not exist." << endl;
        return;
    }

    string line;
    cout << "\n==================================================================================" << endl;
    cout << "                                    Ticket Summary                                  " << endl;
    cout << "==================================================================================" << endl;
    cout << setw(15) << left << "Ticket No"
         << setw(20) << "Username"
         << setw(20) << "Name"
         << setw(20) << "Date/Time"
         << setw(15) << "Source"
         << setw(15) << "Destination"
         << setw(10) << "Distance"
         << setw(10) << "Fare"
         << setw(15) << "Payment" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    while (getline(file, line))
    {
        stringstream ss(line);
        string ticketNo, dateTime, name, username, phone, email, gender, source, destination, distance, fare, payment;

        getline(ss, ticketNo, ',');
        getline(ss, dateTime, ',');
        getline(ss, name, ',');
        getline(ss, username, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, gender, ',');
        getline(ss, source, ',');
        getline(ss, destination, ',');
        getline(ss, distance, ',');
        getline(ss, fare, ',');
        getline(ss, payment, ',');

        cout << setw(15) << left << ticketNo
             << setw(20) << username
             << setw(20) << name
             << setw(20) << dateTime
             << setw(15) << source
             << setw(15) << destination
             << setw(10) << distance
             << setw(10) << fare
             << setw(15) << payment << endl;
    }

    file.close();
}

void searchTicketByUsername()
{
    string searchUsername;
    cout << "Enter username to search: ";
    cin >> searchUsername;

    ifstream file("tickets.txt");
    if (!file.is_open())
    {
        cerr << "Error: The file 'tickets.txt' does not exist." << endl;
        return;
    }

    string line;
    bool found = false;

    cout << "\n==================================================================================" << endl;
    cout << "                                    Ticket Summary                                  " << endl;
    cout << "==================================================================================" << endl;
    cout << setw(15) << left << "Ticket No"
         << setw(20) << "Username"
         << setw(20) << "Name"
         << setw(20) << "Date/Time"
         << setw(15) << "Source"
         << setw(15) << "Destination"
         << setw(10) << "Distance"
         << setw(10) << "Fare"
         << setw(15) << "Payment" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    while (getline(file, line))
    {
        stringstream ss(line);
        string ticketNo, dateTime, name, username, phone, email, gender, source, destination, distance, fare, payment;

        getline(ss, ticketNo, ',');
        getline(ss, dateTime, ',');
        getline(ss, name, ',');
        getline(ss, username, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, gender, ',');
        getline(ss, source, ',');
        getline(ss, destination, ',');
        getline(ss, distance, ',');
        getline(ss, fare, ',');
        getline(ss, payment, ',');

        if (username == searchUsername)
        {
            found = true;
            cout << setw(15) << left << ticketNo
                 << setw(20) << username
                 << setw(20) << name
                 << setw(20) << dateTime
                 << setw(15) << source
                 << setw(15) << destination
                 << setw(10) << distance
                 << setw(10) << fare
                 << setw(15) << payment << endl;
        }
    }

    if (!found)
    {
        cout << "No tickets found for username '" << searchUsername << "'." << endl;
    }

    file.close();
}

void searchTicketToCancel(const string &username)
{

    ifstream file("tickets.txt");
    if (!file.is_open())
    {
        cerr << "Error: The file 'tickets.txt' does not exist." << endl;
        return;
    }

    string line;
    bool found = false;

    cout << "\n==================================================================================" << endl;
    cout << "                                    Ticket Summary                                  " << endl;
    cout << "==================================================================================" << endl;
    cout << setw(15) << left << "Ticket No"
         << setw(20) << "Username"
         << setw(20) << "Name"
         << setw(20) << "Date/Time"
         << setw(15) << "Source"
         << setw(15) << "Destination"
         << setw(10) << "Distance"
         << setw(10) << "Fare"
         << setw(15) << "Payment" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    while (getline(file, line))
    {
        stringstream ss(line);
        string ticketNo, dateTime, name, tempusername, phone, email, gender, source, destination, distance, fare, payment;

        getline(ss, ticketNo, ',');
        getline(ss, dateTime, ',');
        getline(ss, name, ',');
        getline(ss, tempusername, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, gender, ',');
        getline(ss, source, ',');
        getline(ss, destination, ',');
        getline(ss, distance, ',');
        getline(ss, fare, ',');
        getline(ss, payment, ',');

        if (username == tempusername)
        {
            found = true;
            cout << setw(15) << left << ticketNo
                 << setw(20) << tempusername
                 << setw(20) << name
                 << setw(20) << dateTime
                 << setw(15) << source
                 << setw(15) << destination
                 << setw(10) << distance
                 << setw(10) << fare
                 << setw(15) << payment << endl;
        }
    }

    if (!found)
    {
        cout << "No tickets found for username '" << username << "'." << endl;
    }

    file.close();
}

void cancelTicket(const string &username)
{
    // Display the user's tickets first
    searchTicketToCancel(username);

    // Prompt user for ticket number to cancel
    string ticketNoToCancel;
    cout << "\n======================================================================================" << endl;
    cout << "                            Enter the Ticket Number to Cancel                        " << endl;
    cout << "======================================================================================" << endl;
    cout << "Ticket Number: ";
    cin >> ticketNoToCancel;

    ifstream ticketFile("tickets.txt");
    ofstream tempFile("temp_tickets.txt");
    bool ticketFound = false;

    if (!ticketFile.is_open())
    {
        cerr << "Error: The file 'tickets.txt' does not exist." << endl;
        return;
    }

    string line;
    while (getline(ticketFile, line))
    {
        stringstream ss(line);
        string ticketNo, dateTime, bookedBy, passengerName, phone, email, gender, source, destination, distance, fare, paymentMode;

        getline(ss, ticketNo, ',');
        getline(ss, dateTime, ',');
        getline(ss, bookedBy, ',');
        getline(ss, passengerName, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, gender, ',');
        getline(ss, source, ',');
        getline(ss, destination, ',');
        getline(ss, distance, ',');
        getline(ss, fare, ',');
        getline(ss, paymentMode, ',');

        // Cancel the ticket if the ticket number matches
        if (ticketNo == ticketNoToCancel && passengerName == username)
        {
            ticketFound = true;
            cout << "\n======================================================================================" << endl;
            cout << "                            Ticket Cancellation Success!                             " << endl;
            cout << "======================================================================================" << endl;
            cout << "Ticket with Booking ID: " << ticketNo << " has been successfully cancelled." << endl;
            cout << "We are processing your refund. The amount will be credited back to your payment method." << endl;
            cout << "Thank you for your patience!" << endl;
            cout << "======================================================================================" << endl;
            continue; // Skip writing this ticket to the temp file
        }

        // Write the line to the temporary file if the ticket is not cancelled
        tempFile << line << endl;
    }

    ticketFile.close();
    tempFile.close();

    // Replace the original tickets file with the temporary file
    if (ticketFound)
    {
        remove("tickets.txt");
        rename("temp_tickets.txt", "tickets.txt");
    }
    else
    {
        // If no ticket was found for the ticket number, notify the user
        cout << "\n======================================================================================" << endl;
        cout << "                            Ticket Cancellation Failed!                             " << endl;
        cout << "======================================================================================" << endl;
        cout << "No ticket found with the given Ticket Number for user: " << username << endl;
        cout << "======================================================================================" << endl;
        remove("temp_tickets.txt"); // Delete the temp file
    }
}

void deleteUserAccount(const string &username)
{
    ifstream inputFile("users.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile.is_open() || !tempFile.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        // Getting to Home Page
        homePage();
        return;
    }

    string line;
    bool userFound = false;

    while (getline(inputFile, line))
    {
        // Extract the username (first field) from the line
        stringstream ss(line);
        string currentUsername;
        // Get the username (up to the first comma)
        getline(ss, currentUsername, ',');

        if (currentUsername == username)
        {
            // Skip writing this line to the temp file
            userFound = true;
        }
        else
        {
            // Write other lines to the temp file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    // Replace original file with updated file
    if (userFound)
    {
        if (remove("users.txt") != 0 || rename("temp.txt", "users.txt") != 0)
        {
            cerr << "Error: Unable to update file." << endl;
            // Getting to Home Page
            homePage();
        }
        else
        {
            cout << "User account deleted successfully." << endl;
            // Getting to Home Page
            homePage();
            return;
        }
    }
    else
    {
        // If the user is not found, delete the temp file
        remove("temp.txt");
        cout << "Error: User not found." << endl;
        // Getting to Home Page
        homePage();
    }
}

// Merge function to combine two sorted halves
// Merge function to combine two sorted halves
void merge(vector<Ticket> &tickets, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Ticket> leftTickets(n1), rightTickets(n2);

    for (int i = 0; i < n1; i++)
        leftTickets[i] = tickets[left + i];
    for (int i = 0; i < n2; i++)
        rightTickets[i] = tickets[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        // Change the comparison to sort in descending order of fare
        if (leftTickets[i].fare >= rightTickets[j].fare)
        { // Modify the comparison to >=
            tickets[k] = leftTickets[i];
            i++;
        }
        else
        {
            tickets[k] = rightTickets[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        tickets[k] = leftTickets[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        tickets[k] = rightTickets[j];
        j++;
        k++;
    }
}

// Merge Sort function to sort tickets based on fare
void mergeSort(vector<Ticket> &tickets, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(tickets, left, mid);      // Sort first half
        mergeSort(tickets, mid + 1, right); // Sort second half

        merge(tickets, left, mid, right); // Merge the sorted halves
    }
}

void displayTicketHistorySortedByFare()
{
    ifstream file("tickets.txt");
    string line;
    vector<Ticket> tickets;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream ss(line);
            Ticket ticket;

            // Parsing ticket data
            getline(ss, ticket.ticketNo, ',');
            getline(ss, ticket.dateTime, ',');
            string temp;
            getline(ss, ticket.name, ',');     // Skip name
            getline(ss, ticket.username, ','); // Skip surname
            getline(ss, temp, ',');            // Skip phone number
            getline(ss, temp, ',');            // Skip email
            getline(ss, temp, ',');            // Skip gender
            getline(ss, ticket.source, ',');
            getline(ss, ticket.destination, ',');
            ss >> ticket.distance;
            ss.ignore(); // To skip the comma between distance and fare
            ss >> ticket.fare;
            getline(ss, ticket.paymentMethod);

            tickets.push_back(ticket);
        }
        file.close();

        // Sorting tickets using Merge Sort (Descending order by fare)
        mergeSort(tickets, 0, tickets.size() - 1);

        // Display sorted tickets
        cout << "\n==================================================================================" << endl;
        cout << "                                    Ticket Summary                                  " << endl;
        cout << "====================================================================================" << endl;
        cout << setw(15) << left << "Ticket No"
             << setw(20) << "Username"
             << setw(20) << "Name"
             << setw(20) << "Date/Time"
             << setw(15) << "Source"
             << setw(15) << "Destination"
             << setw(10) << "Distance"
             << setw(10) << "Fare"
             << setw(15) << "Payment" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;

        for (const auto &ticket : tickets)
        {
            cout << setw(15) << left << ticket.ticketNo
                 << setw(20) << ticket.username
                 << setw(20) << ticket.name
                 << setw(20) << ticket.dateTime
                 << setw(15) << ticket.source
                 << setw(15) << ticket.destination
                 << setw(10) << ticket.distance
                 << setw(10) << ticket.fare
                 << setw(15) << ticket.paymentMethod << endl;
        }
    }

    else
    {
        cout << "Unable to open tickets file." << endl;
    }
}

void submitFeedback(const string &usernameTemp)
{
    string username = usernameTemp;
    string anonymousChoice;
check:
    // Ask if the user wants to submit feedback anonymously
    cout << "Would you like to submit feedback anonymously? (Y/N): ";
    cin >> anonymousChoice;

    if (toUpper(anonymousChoice) != "Y" && toUpper(anonymousChoice) != "N")
    {
        cout << "\n Invalid Input !!!";
        cout << "\nEnter valid input (Y/N)!!!" << endl;
        goto check;
    }
    if (toUpper(anonymousChoice) == "Y")
    {
        username = "Anonymous";
    }

    vector<string> categories = {
        "Service Quality", "Train Punctuality", "Cleanliness",
        "Ticket Booking Experience", "Other"};

    cout << "\n--- Select a Feedback Category ---\n"
         << endl;
    cout << "1. Service Quality" << endl;
    cout << "2. Train Punctuality" << endl;
    cout << "3. Cleanliness" << endl;
    cout << "4. Ticket Booking Experience" << endl;
    cout << "5. Other\n"
         << endl;
    cout << "===============================" << endl;

categoryChoice:

    cout << "\nEnter the category number (e.g., 1): ";
    int categoryChoice;

    // Validate input
    if (!(cin >> categoryChoice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid choice (1-7)." << endl;
        goto categoryChoice;
    }

    string selectedCategory = categories[categoryChoice - 1];

    cout << "Enter your feedback: ";
    cin.ignore(); // Clear the input buffer
    string message;
    getline(cin, message);

rateTheService:
    cout << "Rate the service (1 to 5): ";
    float rating;
    cin >> rating;

    // round of to 1 decimal
    rating = round(rating * 10) / 10;

    if (message.empty() || rating < 1 || rating > 5)
    {
        cout << "Invalid feedback. Please provide valid inputs.\n";
        goto rateTheService;
    }

    ofstream feedbackFile("feedback.txt", ios::app);
    if (!feedbackFile)
    {
        cout << "Error opening feedback file.\n";
        return;
    }

    // Write feedback using '#' as delimiter
    feedbackFile << username << "#"
                 << getCurrentDateTime() << "#"
                 << selectedCategory << "#"
                 << message << "#"
                 << rating << endl;

    cout << "Thank you for your feedback!\n";
}

void userViewFeedback(const string &username)
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "No feedback available.\n";
        homePage();
        return;
    }

    // Display table header
    cout << "===============================================================================================================================================" << endl;
    cout << left << setw(15) << "Username"
         << setw(25) << "Date"
         << setw(30) << "Category"
         << setw(50) << "Message"
         << setw(6) << "Rating" << endl;
    cout << "===============================================================================================================================================" << endl;

    string line;
    while (getline(feedbackFile, line))
    {
        vector<string> fields;
        size_t pos = 0;

        // Split the line into fields using '#' as the delimiter
        while ((pos = line.find('#')) != string::npos)
        {
            fields.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        fields.push_back(line); // Add the remaining part of the line

        // Ensure the line contains all expected fields
        if (fields.size() == 5 && fields[0] == username)
        {
            cout << left << setw(15) << fields[0]
                 << setw(25) << fields[1]
                 << setw(30) << fields[2]
                 << setw(50) << fields[3]
                 << setw(6) << fields[4] << endl;
        }
        else if (fields.size() != 5 && fields[0] == username)
        {
            cout << "Invalid feedback entry encountered. Skipping...\n";
        }
    }

    cout << "===============================================================================================================================================" << endl;
    feedbackFile.close();
}

// User Feedback Dashboard
void UserFeedbackDashboard(const string &username)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       Feedback Dashboard        " << endl;
        cout << "===============================" << endl;
        cout << "Welcome User, " << username << "!" << endl;
        cout << "1. Submit Feedback ." << endl;
        cout << "2. View Feedback." << endl;
        cout << "3. Delete." << endl;
        cout << "4. Back" << endl;
        cout << "5. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            submitFeedback(username);
            break;
        case 2:
            userViewFeedback(username);
            break;
        case 3:
            deleteFeedback(username);
            break;
        case 4:
            // Go User Dashboard
            userDashboard(username);
            return;
        case 5:
            // Exit the application
            exitApp();
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

// Function to generate the bad character rule table for Boyer-Moore
unordered_map<char, int> createBadCharacterTable(const string &pattern)
{
    unordered_map<char, int> badCharTable;
    int m = pattern.length();

    // Initialize the table
    for (int i = 0; i < m; i++)
    {
        badCharTable[pattern[i]] = i;
    }

    return badCharTable;
}

// Boyer-Moore Pattern Matching algorithm
bool BoyerMooreSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0)
        return true;

    // Create bad character table
    unordered_map<char, int> badCharTable = createBadCharacterTable(pattern);

    int i = 0; // index for text
    while (i <= n - m)
    {
        int j = m - 1; // index for pattern
        while (j >= 0 && pattern[j] == text[i + j])
        {
            j--;
        }

        if (j < 0)
        {
            return true; // Pattern found
            i += (i + m < n) ? m - badCharTable[text[i + m]] : 1;
        }
        else
        {
            i += max(1, j - badCharTable[text[i + j]]);
        }
    }
    return false; // Pattern not found
}

// Function to display the feedback of a specific user using Boyer-Moore for pattern matching
void displayUserFeedback()
{
    string username;

    // Prompt for username input
    cout << "Enter username to view feedback: ";
    cin >> username;

    // Open the feedback file
    ifstream feedbackFile("feedback.txt");

    // Handle the case where the file doesn't exist or cannot be opened
    if (!feedbackFile)
    {
        cout << "Error: Could not open feedback file. Please make sure the file exists.\n";
        return;
    }

    // Initialize a flag to check if any feedback was found for the user
    bool feedbackFound = false;

    // Read through each feedback entry in the file
    string line;
    while (getline(feedbackFile, line))
    {
        stringstream ss(line);
        string storedUsername, date, category, message, ratingStr;

        // Split the line by '#' delimiter
        getline(ss, storedUsername, '#');
        getline(ss, date, '#');
        getline(ss, category, '#');
        getline(ss, message, '#');
        getline(ss, ratingStr, '#');

        // Use Boyer-Moore to check if storedUsername matches input username
        if (BoyerMooreSearch(storedUsername, username))
        {
            feedbackFound = true;

            // Display feedback details
            cout << "\n--- Feedback for User: " << username << " ---\n";
            cout << "Date: " << date << endl;
            cout << "Category: " << category << endl;
            cout << "Message: " << message << endl;
            cout << "Rating: " << ratingStr << endl;
            cout << "---------------------------------------------\n";
        }
    }

    // If no feedback was found for the user
    if (!feedbackFound)
    {
        cout << "No feedback found for username: " << username << "\n";
    }

    feedbackFile.close();
}

// Admin Feedback Dashboard
void AdminFeedbackDashboard(const string &adminname)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       Feedback Dashboard        " << endl;
        cout << "===============================" << endl;
        cout << "Welcome Admin, " << adminname << "!" << endl;
        cout << "1. View All Feedback. " << endl;
        cout << "2. Graphical Analysis. " << endl;
        cout << "3. Sort Feedback By Rating. " << endl;
        cout << "4. generateFeedbackSummary" << endl;
        cout << "5. Search Feedback by Username." << endl;
        cout << "6. Back" << endl;
        cout << "7. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            viewFeedback();
            break;
        case 2:
            GraphicalAnalysis(adminname);
            break;
        case 3:
            sortFeedbackByRating();
            break;
        case 4:
            generateFeedbackSummary();
            break;
        case 5:
            displayUserFeedback();
            break;
        case 6:
            // Go Admin Dashboard
            adminDashboard(adminname);
            return;
            break;
        case 7:
            // Exit the application
            exitApp();
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

void viewFeedback()
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "No feedback available.\n";
        homePage();
        return;
    }

    // Display table header
    cout << "=====================================================================================================================================" << endl;
    cout << left << setw(15) << "Username"
         << setw(30) << "Date"
         << setw(50) << "Category"
         << setw(30) << "Message"
         << setw(6) << "Rating" << endl;
    cout << "=====================================================================================================================================" << endl;

    string line;
    while (getline(feedbackFile, line))
    {
        vector<string> fields;
        size_t pos = 0;

        // Split the line into fields using '#' as the delimiter
        while ((pos = line.find('#')) != string::npos)
        {
            fields.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        fields.push_back(line); // Add the remaining part of the line

        // Ensure the line contains all expected fields
        if (fields.size() == 5)
        {
            cout << left << setw(15) << fields[0]
                 << setw(30) << fields[1]
                 << setw(50) << fields[2]
                 << setw(30) << fields[3]
                 << setw(6) << fields[4] << endl;
        }
        else
        {
            cout << "Invalid feedback entry encountered. Skipping...\n";
        }
    }

    cout << "=====================================================================================================================================" << endl;
    feedbackFile.close();
}

void deleteFeedback(const string &username)
{
    // Open the feedback file for reading
    ifstream feedbackFile("feedback.txt");

    // Check if the feedback file exists or can be opened
    if (!feedbackFile)
    {
        // Display a message if no feedback file is available
        cout << "No feedback available to delete.\n";

        // Redirect the user back to their dashboard
        userDashboard(username);
        return; // Exit the function since there is no file
    }

    // Vector to store all feedback entries from the file
    vector<string> feedbackEntries;

    // Vector to store feedbacks specific to the logged-in user
    vector<string> userFeedbacks;

    // Variable to read each line from the file
    string line;

    // Display the header for the user's feedback section
    cout << "\n----- Your Feedback -----\n";

    // Read each line from the feedback file
    while (getline(feedbackFile, line))
    {
        // Store the line in the feedbackEntries vector
        feedbackEntries.push_back(line);

        // Use a stringstream to parse the feedback line
        stringstream ss(line);

        // Variables to store individual fields from the feedback entry
        string field, user, category, message, rating;

        // Extract the username field from the feedback entry
        getline(ss, user, '#');

        // Skip the second field (optional ID or metadata)
        getline(ss, field, '#');

        // Extract the category, message, and rating fields
        getline(ss, category, '#');
        getline(ss, message, '#');
        getline(ss, rating, '#');

        // Check if the feedback entry belongs to the current user
        if (user == username)
        {
            // Store the feedback entry in the user's feedback vector
            userFeedbacks.push_back(line);

            // Display the feedback details with a numbered list
            cout << userFeedbacks.size() << ". "
                 << "Category: " << category
                 << "\n   Message : " << message
                 << "\n   Rating  : " << rating << endl
                 << endl;
        }
    }

    // Close the feedback file after reading all entries
    feedbackFile.close();

    // Check if the user has no feedback entries in the file
    if (userFeedbacks.empty())
    {
        // Inform the user and redirect them to their dashboard
        cout << "No feedback found for username: " << username << endl;
        userDashboard(username);
        return; // Exit the function since there is no user feedback
    }

    // Prompt the user to select a feedback to delete or cancel
    cout << "\nEnter the feedback number you want to delete: ";

    // Variable to store the user's choice
    int choice;

    // Validate the user's input for a valid feedback number
    if (!(cin >> choice) || choice < 0 || choice > static_cast<int>(userFeedbacks.size()))
    {
        // Clear the input stream in case of invalid input
        cin.clear();

        // Ignore invalid characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Inform the user about the invalid choice
        cout << "Invalid choice. Operation cancelled.\n";

        // Redirect the user to their dashboard
        userDashboard(username);
        return; // Exit the function since input was invalid
    }

    // Check if the user chose to cancel the operation
    if (choice == 0)
    {
        // Inform the user about the cancellation
        cout << "Operation cancelled.\n";

        // Redirect the user to their dashboard
        userDashboard(username);
        return; // Exit the function since the operation was cancelled
    }

    // Retrieve the selected feedback from the user's feedback vector
    auto selectedFeedback = userFeedbacks[choice - 1];

    // Remove the selected feedback from the main feedback list
    feedbackEntries.erase(
        remove(feedbackEntries.begin(), feedbackEntries.end(), selectedFeedback),
        feedbackEntries.end());

    // Inform the user that the feedback has been deleted
    cout << "Feedback deleted successfully.\n";

    // Open the feedback file for writing to save updated entries
    ofstream outputFile("feedback.txt");

    // Write all remaining feedback entries back to the file
    for (const auto &entry : feedbackEntries)
    {
        // Write each entry on a new line in the file
        outputFile << entry << endl;
    }

    // Close the feedback file after writing all entries
    outputFile.close();

    // Redirect the user to their dashboard after the operation
    userDashboard(username);
}

void generateFeedbackSummary()
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "No feedback available.\n";
        return;
    }

    // Data structures for summary
    map<string, pair<int, int>> categoryRatings; // Category -> (Sum of ratings, Count)
    set<string> uniqueUsers;                     // To store unique usernames
    int totalFeedback = 0;                       // Total feedback count

    string line;
    while (getline(feedbackFile, line))
    {
        vector<string> fields;
        size_t pos = 0;

        // Split line using '#' delimiter
        while ((pos = line.find('#')) != string::npos)
        {
            fields.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        fields.push_back(line);

        if (fields.size() == 5)
        {
            string username = fields[0];
            string category = fields[2];  // Extract category
            int rating = stoi(fields[4]); // Extract rating

            // Update data
            uniqueUsers.insert(username);
            categoryRatings[category].first += rating; // Add rating
            categoryRatings[category].second++;        // Increment count
            totalFeedback++;
        }
    }
    feedbackFile.close();

    // Menu for summary options
    cout << "\n--- Feedback Summary Options ---\n";
    cout << "1. Total Feedback Received\n";
    cout << "2. Average Rating Per Category\n";
    cout << "3. List of Users Who Submitted Feedback\n";
    cout << "4. All Summary Options\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1: // Total Feedback Received
        cout << "\nTotal Feedback Received: " << totalFeedback << endl;
        break;

    case 2: // Average Rating Per Category
        cout << "\n--- Average Rating Per Category ---\n";
        cout << setw(30) << left << "Category" << "Average Rating\n";
        cout << "-----------------------------------------------\n";
        for (map<string, pair<int, int>>::iterator it = categoryRatings.begin(); it != categoryRatings.end(); ++it)
        {
            double average = static_cast<double>(it->second.first) / it->second.second;
            cout << setw(30) << left << it->first << fixed << setprecision(2) << average << endl;
        }
        break;

    case 3: // List of Users Who Submitted Feedback
        cout << "\n--- Users Who Submitted Feedback ---\n";
        for (const string &user : uniqueUsers)
        {
            cout << user << endl;
        }
        break;

    case 4: // All Summary Options
        // Total Feedback Received
        cout << "\nTotal Feedback Received: " << totalFeedback << endl;

        // Average Rating Per Category
        cout << "\n--- Average Rating Per Category ---\n";
        cout << setw(20) << left << "Category" << "Average Rating\n";
        cout << "-----------------------------------------------\n";
        for (map<string, pair<int, int>>::iterator it = categoryRatings.begin(); it != categoryRatings.end(); ++it)
        {
            double average = static_cast<double>(it->second.first) / it->second.second;
            cout << setw(20) << left << it->first << fixed << setprecision(2) << average << endl;
        }

        // List of Users Who Submitted Feedback
        cout << "\n--- Users Who Submitted Feedback ---\n";
        for (const string &user : uniqueUsers)
        {
            cout << user << endl;
        }
        break;

    default:
        cout << "Invalid choice. Please select a valid option.\n";
    }
}

// Function to heapify the ratings and feedback
void heapify(vector<int> &ratings, vector<string> &feedbackEntries, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child is larger than root
    if (left < n && ratings[left] > ratings[largest])
        largest = left;

    // Check if right child is larger than largest so far
    if (right < n && ratings[right] > ratings[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(ratings[i], ratings[largest]);
        swap(feedbackEntries[i], feedbackEntries[largest]);

        // Recursively heapify the affected sub-tree
        heapify(ratings, feedbackEntries, n, largest);
    }
}

// Function to perform heap sort
void heapSort(vector<int> &ratings, vector<string> &feedbackEntries)
{
    int n = ratings.size();

    // Build max heap (this ensures the largest rating comes to the root)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ratings, feedbackEntries, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(ratings[0], ratings[i]);
        swap(feedbackEntries[0], feedbackEntries[i]);

        // Call heapify on the reduced heap
        heapify(ratings, feedbackEntries, i, 0);
    }
}

// Function to sort feedback by rating using Heap Sort
void sortFeedbackByRating()
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "No feedback available to sort.\n";
        return;
    }

    vector<string> feedbackEntries; // Store feedback entries
    vector<int> ratings;            // Store ratings

    string line;
    while (getline(feedbackFile, line))
    {
        size_t lastDelimiter = line.rfind('#');
        if (lastDelimiter != string::npos)
        {
            string ratingStr = line.substr(lastDelimiter + 1);
            int rating = stoi(ratingStr); // Extract rating
            ratings.push_back(rating);
            feedbackEntries.push_back(line);
        }
    }
    feedbackFile.close();

    // Debugging: Print the feedback before sorting
    cout << "Before sorting:\n";
    for (size_t i = 0; i < feedbackEntries.size(); ++i)
    {
        cout << " Rating: " << ratings[i] << endl;
    }

    // Sort using Heap Sort
    heapSort(ratings, feedbackEntries);

    // Debugging: Print the feedback after sorting
    cout << "\nAfter sorting:\n";
    for (size_t i = 0; i < feedbackEntries.size(); ++i)
    {
        cout << " Rating: " << ratings[i] << endl;
    }

    // Display sorted feedback
    cout << "\n--- Feedback Sorted by Rating ---\n";
    cout << left << setw(15) << "Username"
         << setw(30) << "Date & Time"
         << setw(50) << "Category"
         << setw(30) << "Message"
         << setw(8) << "Rating" << endl;
    cout << string(93, '-') << endl;

    for (const auto &entry : feedbackEntries)
    {
        size_t pos1 = entry.find('#');
        size_t pos2 = entry.find('#', pos1 + 1);
        size_t pos3 = entry.find('#', pos2 + 1);
        size_t pos4 = entry.find('#', pos3 + 1);

        string username = entry.substr(0, pos1);
        string dateTime = entry.substr(pos1 + 1, pos2 - pos1 - 1);
        string category = entry.substr(pos2 + 1, pos3 - pos2 - 1);
        string message = entry.substr(pos3 + 1, pos4 - pos3 - 1);
        string rating = entry.substr(pos4 + 1);

        cout << left << setw(15) << username
             << setw(30) << dateTime
             << setw(50) << category
             << setw(30) << message
             << setw(8) << rating << endl;
    }
}

// Function to categorize feedback ratings
string categorizeRating(int rating)
{
    if (rating >= 4)
    {
        return "Positive";
    }
    else if (rating == 3)
    {
        return "Neutral";
    }
    else
    {
        return "Negative";
    }
}

// Function to generate feedback heatmap
void generateFeedbackHeatmap()
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "No feedback available to generate heatmap.\n";
        return;
    }

    // Maps to store counts for each category and rating type
    map<string, map<string, int>> feedbackCounts;

    string line;
    while (getline(feedbackFile, line))
    {
        size_t pos1 = line.find('#');
        size_t pos2 = line.find('#', pos1 + 1);
        size_t pos3 = line.find('#', pos2 + 1);
        size_t pos4 = line.find('#', pos3 + 1);

        // Extract category and rating from feedback line
        string category = line.substr(pos2 + 1, pos3 - pos2 - 1);
        int rating = stoi(line.substr(pos4 + 1));

        // Categorize the rating (Positive, Neutral, Negative)
        string ratingCategory = categorizeRating(rating);

        // Increment the corresponding count for the category and rating
        feedbackCounts[category][ratingCategory]++;
    }
    feedbackFile.close();

    // Output the heatmap table
    cout << "\n--- Feedback Heatmap ---\n";
    cout << "Category                      | Positive | Neutral  | Negative\n";
    cout << "------------------------------------------------------\n";

    // Loop through the categories and output the counts
    for (const auto &categoryEntry : feedbackCounts)
    {
        const string &category = categoryEntry.first;
        const map<string, int> &ratings = categoryEntry.second;

        int positive = ratings.count("Positive") ? ratings.at("Positive") : 0;
        int neutral = ratings.count("Neutral") ? ratings.at("Neutral") : 0;
        int negative = ratings.count("Negative") ? ratings.at("Negative") : 0;

        // Print the category and its counts in a formatted manner
        cout << left << setw(30) << category
             << setw(10) << positive
             << setw(10) << neutral
             << setw(10) << negative << endl;
    }

    cout << "------------------------------------------------------\n";
}

// Function to read feedback file and calculate ratings distribution
void generateFeedbackRatingDistribution()
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "Error: No feedback data available.\n";
        return;
    }

    // Array to hold the count of ratings (1-5)
    int ratingsCount[5] = {0}; // Index 0 for rating 1, Index 1 for rating 2, ..., Index 4 for rating 5

    string line;
    while (getline(feedbackFile, line))
    {
        // Split the line by '#' delimiter
        stringstream ss(line);
        string username, date, category, message, ratingStr;
        getline(ss, username, '#');
        getline(ss, date, '#');
        getline(ss, category, '#');
        getline(ss, message, '#');
        getline(ss, ratingStr, '#');

        // Convert rating from string to integer
        int rating = stoi(ratingStr);

        if (rating >= 1 && rating <= 5)
        {
            ratingsCount[rating - 1]++; // Increment the appropriate rating count
        }
    }

    feedbackFile.close();

    // Displaying the feedback rating distribution as a bar chart
    cout << "\nFeedback Rating Distribution\n";
    cout << "--------------------------------------\n";

    // Maximum bar length (adjust according to your needs)
    const int MAX_BAR_LENGTH = 20;

    for (int i = 0; i < 5; ++i)
    {
        int barLength = (ratingsCount[i] * MAX_BAR_LENGTH) / 5; // Calculate the proportional length of the bar

        // Use "█" block for the bar or a simpler character like "*"
        cout << "Rating " << i + 1 << " | ";
        for (int j = 0; j < barLength; ++j)
        {
            cout << "**"; // Block character used for the bar
        }
        cout << " " << ratingsCount[i] << " (" << (ratingsCount[i] * 100) / 5 << "%)\n";
    }

    cout << "--------------------------------------\n";
}

// Function to generate Category-wise Feedback Distribution
void generateCategoryFeedbackDistribution()
{
    ifstream feedbackFile("feedback.txt");
    if (!feedbackFile)
    {
        cout << "Error: No feedback data available.\n";
        return;
    }

    // Map to store the count of feedback per category
    map<string, int> categoryCount;
    int totalFeedback = 0;

    string line;
    while (getline(feedbackFile, line))
    {
        // Split the line by '#' delimiter
        stringstream ss(line);
        string username, date, category, message, ratingStr;
        getline(ss, username, '#');
        getline(ss, date, '#');
        getline(ss, category, '#');
        getline(ss, message, '#');
        getline(ss, ratingStr, '#');

        categoryCount[category]++; // Increment count for this category
        totalFeedback++;
    }

    feedbackFile.close();

    if (totalFeedback == 0)
    {
        cout << "No feedback available to display.\n";
        return;
    }

    // Displaying the category-wise feedback distribution
    cout << "\nCategory-wise Feedback Distribution (Pie Chart)\n";
    cout << "-----------------------------------------------\n";

    // Define maximum width for the bar
    const int MAX_BAR_LENGTH = 40;

    // Iterate through the categories and display their feedback distribution
    for (const auto &entry : categoryCount)
    {

        string category = entry.first;

        int count = entry.second;

        // Calculate percentage

        double percentage = (static_cast<double>(count) / totalFeedback) * 100;

        // Calculate the proportional length of the bar

        int barLength = (count * MAX_BAR_LENGTH) / totalFeedback;

        // Display category and its corresponding bar

        cout << left << setw(20) << category << " | ";
        for (int i = 0; i < barLength; ++i)
        {
            cout << "*"; // Each "*" represents a portion of the feedback
        }

        cout << " " << count << " (" << fixed << setprecision(2) << percentage << "%)\n";
    }

    cout << "-----------------------------------------------\n";
}

// Graphical Analysis OF FEEDBACK
void GraphicalAnalysis(const string &adminname)
{
    int choice;
    while (true)
    {
        cout << "\n===============================" << endl;
        cout << "       Graphical Analysis        " << endl;
        cout << "===============================" << endl;
        cout << endl;
        cout << "1. Rating-wise Feedback Distribution. " << endl;
        cout << "2. Generate Feedback Heatmap. " << endl;
        cout << "3. Category-wise Feedback Distribution. " << endl;
        cout << "4. Back" << endl;
        cout << "5. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter your choice: ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid choice (1-4)." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            generateFeedbackRatingDistribution();
            break;
        case 2:
            generateFeedbackHeatmap();
            break;
        case 3:
            generateCategoryFeedbackDistribution();
            break;

        case 4:
            // Go Admin Dashboard
            adminDashboard(adminname);
            return;
        case 5:
            // Exit the application
            exitApp();
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
}

// Bus management

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <climits>
#include <queue>
#include <map>
#include <iomanip> // For setw and setfill

#include <algorithm> // For transforming and string matching

#include <string>

// To use cout and cin
using namespace std;

// Function to normalize strings by converting to lowercase and removing spaces
string normalizeString(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
    return str;
}

class BusBookingSystem
{
private:
    vector<BusRoute> routes;
    map<string, vector<pair<string, int>>> graph;


public:
    int readIntegerInput(const std::string &prompt)
    {
        int value;
        while (true)
        {
            std::cout << prompt;
            std::cin >> value;

            // Check for invalid input
            if (std::cin.fail())
            {
                std::cin.clear();                                                   // Clear the error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input! Please enter a valid number." << std::endl;
            }
            else
            {
                break; // If input is valid, exit the loop
            }
        }
        return value;
    }


    // Read bus routes from a file and build the graph
    void readBusRoutesFromFile(const string &filename)
    {
        ifstream file(filename);

        string line;

        // If the file cannot be opened
        if (!file.is_open())
        {

            cout << "Error opening file!" << endl;
            return;
        }

        // Read each line of the file and process it
        while (getline(file, line))
        {

            stringstream ss(line);

            string source, destination, busCompany;

            int distance, price;
            // Read data from the file line by line, splitting by commas

            // Extract source
            getline(ss, source, ',');

            // Extract destination
            getline(ss, destination, ',');

            // Extract distance
            ss >> distance;

            ss.ignore();

            // Extract distance

            getline(ss, busCompany, ',');

            // Extract price
            ss >> price;

            // Add both directions to the graph
            routes.push_back({source, destination, distance, busCompany, price});

            graph[source].push_back({destination, distance});

            // Since routes are bidirectional
            graph[destination].push_back({source, distance});
        }
        // Close the file after reading
        file.close();
    }

    // Dijkstra's Algorithm to calculate the shortest distance between source and destination
    int calculateShortestDistance(const string &source, const string &destination)
    {
        // Min-heap priority queue to store the city and its distance from the source
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        // Store the shortest distance to each city
        map<string, int> dist;

        // Store the previous city for the shortest path reconstruction
        map<string, string> prev;

        // Initialize distances
        for (const auto &route : routes)
        {

            dist[route.source] = INT_MAX;
            dist[route.destination] = INT_MAX;
        }
        dist[source] = 0;
        pq.push({0, source});

        // Dijkstra's algorithm to find the shortest path
        while (!pq.empty())
        {
            // Get the city with the shortest distance
            string u = pq.top().second;

            pq.pop();

            // If we reached the destination, no need to continue
            if (u == destination)
                break;

            // Explore all neighboring cities
            for (const auto &neighbor : graph[u])
            {

                // The neighboring city
                string v = neighbor.first;

                // Distance from city u to city v
                int weight = neighbor.second;

                // If a shorter path to the neighbor is found, update it
                if (dist[u] + weight < dist[v])
                {
                    // Update the shortest distance to v
                    dist[v] = dist[u] + weight;

                    // Mark city u as the previous city for v
                    prev[v] = u;

                    // Push the updated distance and city v to the priority queue
                    pq.push({dist[v], v});
                }
            }
        }

        // If the destination is unreachable, return a large value (INT_MAX)
        if (dist[destination] == INT_MAX)
        {
            cout << "No path found from " << source << " to " << destination << ".\n";
            return -1;
        }

        // Return the shortest distance to the destination
        return dist[destination];
    }

    // Display the booking history in a tabular format

    // Utility function to convert a string to lowercase and remove spaces
    static string normalizeString(const string &str)
    {
        string result = str;

        // Convert to lowercase
        transform(result.begin(), result.end(), result.begin(), ::tolower);

        // Remove spaces
        result.erase(remove(result.begin(), result.end(), ' '), result.end());

        return result;
    }
    void handleOnlinePayment()
    {
        // Show online payment options
        displayOnlinePaymentOptions();

        int onlinePaymentChoice = readIntegerInput("Enter your choice (1/2/3/4/5): ");

        // Handle online payment choice
        switch (onlinePaymentChoice)
        {
        case 1:
            cout << "You selected PhonePe for online payment.\n";
            break;

        case 2:
            cout << "You selected Google Pay for online payment.\n";
            break;

        case 3:
            cout << "You selected Paytm for online payment.\n";
            break;

        case 4:
            cout << "You selected PayPal for online payment.\n";
            break;

        case 5:
            cout << "You selected PayZapp for online payment.\n";
            break;

        default:
            cout << "Invalid option selected for online payment.\n";
            break;
        }
    }

    void bookTicket(const string &source, const string &destination)
    {
        string busCompany;

        int minPrice, maxPrice;

        cout << "\nEnter the bus company name: ";

        cin.ignore();

        getline(cin, busCompany);

        // Read and validate numeric input for minPrice
        minPrice = readIntegerInput("Enter the minimum price: ");

        // Read and validate numeric input for maxPrice
        maxPrice = readIntegerInput("Enter the maximum price: ");

        // Normalize and remove spaces from source, destination, and bus company for comparison
        string normalizedSource = normalizeString(source);

        string normalizedDestination = normalizeString(destination);

        string normalizedBusCompany = normalizeString(busCompany);

        bool found = false;

        // Displaying the output
        for (const auto &route : routes)
        {
            // Normalize and remove spaces from route source, destination, and bus company
            string routeSource = normalizeString(route.source);

            string routeDestination = normalizeString(route.destination);

            string routeBusCompany = normalizeString(route.busCompany);

            // Check the conditions for booking using case-insensitive string comparison and no spaces
            if (routeSource == normalizedSource &&
                routeDestination == normalizedDestination &&
                routeBusCompany == normalizedBusCompany &&
                route.price >= minPrice && route.price <= maxPrice)
            {

                // Ticket successfully booked
                cout << "\n------------------------------------------------------------\n";
                cout << " Ticket Successfully Booked!\n";
                cout << "------------------------------------------------------------\n";

                cout << setw(15) << left << "Source" << " | "
                     << setw(15) << "Destination" << " | "
                     << setw(20) << "Bus Company" << " | "
                     << setw(10) << "Price" << endl;

                cout << "------------------------------------------------------------" << endl;
                cout << setw(15) << left << route.source << " | "
                     << setw(15) << route.destination << " | "
                     << setw(20) << route.busCompany << " | "
                     << setw(10) << route.price << endl;

                cout << "------------------------------------------------------------\n";

                // Calculate and display the shortest distance
                int shortestDistance = route.distance;

                cout << "Shortest distance: " << shortestDistance << " km" << endl;

                // Log the booked ticket to the booking history file
                logBookingToFile(route);

                found = true; // A ticket has been booked
                break;        // Exit loop after booking
            }
        }

        // If no matching route is found
        if (!found)
        {
            cout << "No Specific ticket found from " << source << " to " << destination << ".\n";
            return; // Exit the function early if no route was found
        }

        // Ask user for the payment method
        displayPaymentMethods();
        int paymentChoice = readIntegerInput("Enter your payment choice (1/2/3/4): ");

        // Handle payment method selection
        switch (paymentChoice)
        {
        case 1: // Credit Card
            cout << "You selected Credit Card payment.\n";
            break; // Ensure break after the case

        case 2: // Debit Card
            cout << "You selected Debit Card payment.\n";
            break; // Ensure break after the case

        case 3: // Cash
            cout << "You selected Cash payment.\n";
            break; // Ensure break after the case

        case 4:                    // Online Payment
            handleOnlinePayment(); // Call to handle online payment options
            break;                 // Ensure break after online payment case

        default:
            cout << "Invalid payment method selected.\n";
            break; // Ensure break after the default case
        }

        cout << "Payment processed successfully. Enjoy your trip!\n";
    }

    // Log the booking details to the history file
    void logBookingToFile(const BusRoute &route)
    {
        // Writing into the file
        ofstream file("booking_history.txt", ios::app);

        // Inserting into file
        if (file.is_open())
        {
            file << "\nBooking: " << endl;

            file << "Source: " << route.source << endl;

            file << "Destination: " << route.destination << endl;

            file << "Bus Company: " << route.busCompany << endl;

            file << "Distance: " << route.distance << " km" << endl;

            file << "Price: " << route.price << endl;

            file << "----------------------------------------" << endl;

            // Closing the file
            file.close();
        }
        // If the file didn't open
        else
        {
            cout << "Unable to open the booking history file!" << endl;
        }
    }
    void displayPaymentMethods()
    {
        cout << "\nChoose a Payment Method:\n";
        cout << "1. Credit Card\n";
        cout << "2. Debit Card\n";
        cout << "3. Cash\n";
        cout << "4. Online Payment\n";
        cout << "Enter your choice (1/2/3/4): ";
    }

    void displayOnlinePaymentOptions()
    {
        cout << "\nChoose an Online Payment Option:\n";
        cout << "1. PhonePe\n";
        cout << "2. Google Pay\n";
        cout << "3. Paytm\n";
        cout << "4. PayPal\n";
        cout << "5. PayZapp\n";
        cout << "Enter your choice (1/2/3/4/5): ";
    }

    void deleteBookedTicket()
    {
        string destination, busCompany;

        cout << "Enter the destination city: ";

        cin >> destination;

        cout << "Enter the bus company: ";

        cin.ignore();

        getline(cin, busCompany);

        // Normalize the inputs (convert to lowercase and remove spaces)
        string normalizedDestination = normalizeString(destination);

        string normalizedBusCompany = normalizeString(busCompany);

        // Open the booking history file and a temporary file
        ifstream file("booking_history.txt");
        ofstream tempFile("temp.txt");

        if (file.is_open() && tempFile.is_open())
        {
            string line;
            stringstream booking;
            bool found = false;
            bool found1 = false;

            while (getline(file, line))
            {
                booking << line << endl;

                // If we reach the end of a booking block (separator line)
                if (line == "----------------------------------------")
                {
                    string accumulatedBooking = booking.str();

                    // Extract "Destination: " and "Bus Company: " info from the accumulated booking
                    size_t destinationPos = accumulatedBooking.find("Destination: ");
                    size_t busCompanyPos = accumulatedBooking.find("Bus Company: ");

                    if (destinationPos != string::npos && busCompanyPos != string::npos)
                    {
                        string bookingDestination = accumulatedBooking.substr(
                            destinationPos + 12,
                            accumulatedBooking.find("\n", destinationPos) - (destinationPos + 12));
                        string bookingBusCompany = accumulatedBooking.substr(
                            busCompanyPos + 13,
                            accumulatedBooking.find("\n", busCompanyPos) - (busCompanyPos + 13));

                        // Normalize the extracted booking data
                        bookingDestination = normalizeString(bookingDestination);
                        bookingBusCompany = normalizeString(bookingBusCompany);

                        // Check if the booking matches the given destination and bus company
                        if (bookingDestination == normalizedDestination && bookingBusCompany == normalizedBusCompany)
                        {
                            found = true;
                            found1 = true;
                        }
                    }

                    // If not found, write this booking to the temp file
                    if (!found)
                    {
                        tempFile << booking.str();
                    }

                    // Reset for the next booking
                    booking.str("");
                    booking.clear();
                    found = false; // Reset the flag for the next booking
                }
            }

            file.close();
            tempFile.close();

            if (found1)
            {
                cout << "Booking for destination " << destination << " with bus company " << busCompany << " deleted successfully.\n";
            }
            else
            {
                cout << "No matching booking found.\n";
            }

            // Replace the original file with the updated one
            remove("booking_history.txt");
            rename("temp.txt", "booking_history.txt");
        }
        else
        {
            cout << "Unable to open the booking history file!" << endl;
        }
    }
    // Sorting function for booked tickets by price
    void sortBookingsByPrice()
    {
        // Reading from booking_hidtory.txt file
        ifstream file("booking_history.txt");

        vector<BusRoute> bookings;

        string line;

        // Variables for bus ticket records
        string source, destination, busCompany;

        int distance, price;

        // If booking_history.txt file is open
        if (file.is_open())
        {

            // Parse the booking history file
            while (getline(file, line))
            {

                // Checking the conditions for sorting until it comes to null
                if (line.find("Source: ") != string::npos)
                {
                    // Getting all the records
                    source = line.substr(8);

                    getline(file, line);

                    destination = line.substr(12);

                    getline(file, line);

                    busCompany = line.substr(12);

                    getline(file, line);

                    distance = stoi(line.substr(10));

                    getline(file, line);

                    price = stoi(line.substr(7));

                    bookings.push_back({source, destination, distance, busCompany, price});

                    getline(file, line);
                }
            }

            // Closing of file
            file.close();

            // Sorting the bookings by price in ascending order
            sort(bookings.begin(), bookings.end(), [](const BusRoute &a, const BusRoute &b)
                 {
                     return a.price < b.price;
                 });

            // Display sorted bookings
            cout << "\n-------------------Sorted Booking History-------------------\n";

            cout << setw(15) << left << "Source" << " | "
                 << setw(15) << "Destination" << " | "
                 << setw(20) << "Bus Company" << " | "
                 << setw(12) << "Distance" << " | "
                 << setw(10) << "Price" << endl;

            cout << "------------------------------------------------------------" << endl;

            // Displaying the sorted tickets
            for (const auto &booking : bookings)
            {

                cout << setw(15) << left << booking.source << " | "
                     << setw(15) << booking.destination << " | "
                     << setw(20) << booking.busCompany << " | "
                     << setw(12) << booking.distance << " | "
                     << setw(10) << booking.price << endl;
            }

            cout << "------------------------------------------------------------\n";
        }

        // If file didn't opened
        else
        {

            cout << "Unable to open the booking history file!" << endl;
        }
    }

    // Method to display matched routes from a source city (based on prefix)
    void displayMatchedRoutes(const string &source, const string &prefix)
    {

        // To check if the route is found
        bool found = false;

        cout << "\nMatching routes from " << source << " where the destination starts with '" << prefix << "':\n";

        cout << setw(15) << left << "Destination"
             << setw(12) << "Distance (km)"
             << setw(20) << "Bus Company"
             << setw(10) << "Price" << endl;
        cout << "------------------------------------------------------------" << endl;

        // For displaying
        for (const auto &route : routes)
        {

            // Check if the route is from the specified source and the destination starts with the prefix
            if (route.source == source)
            {

                // Convert route.destination to lowercase for case-insensitive matching
                string lowerDestination = route.destination;

                // transform function is used to perform case-insensitive matching of strings.
                transform(lowerDestination.begin(), lowerDestination.end(), lowerDestination.begin(), ::tolower);

                // Convert prefix to lowercase for case-insensitive matching
                string lowerPrefix = prefix;

                transform(lowerPrefix.begin(), lowerPrefix.end(), lowerPrefix.begin(), ::tolower);

                // If the destination starts with the prefix
                if (lowerDestination.find(lowerPrefix) == 0)
                {

                    // Displaying the matched route in a formatted table
                    cout << setw(15) << left << route.destination
                         << setw(12) << route.distance
                         << setw(20) << route.busCompany
                         << setw(10) << route.price << endl;

                    found = true;
                }
            }
        }

        // If matches are not found
        if (!found)
        {

            cout << "No matching routes found.\n";
        }
    }

    // Start the bus booking system and present options to the user
    void startBooking()
    {

        string destination;

        string prefix;

        int option;

        cout << "\n-------------------------\n";

        cout << " Bus Booking System\n";

        cout << "-------------------------\n\n";

        do
        {
            cout << "\n";

            cout << "1. Search Bus Routes\n";

            cout << "2. Book a Ticket\n";

            cout << "3. Display Booking History\n";

            cout << "4. Delete Booked Ticket\n";

            cout << "5. Sort Bookings by Price\n";

            cout << "6. Exit\n";

            option = readIntegerInput("Enter your choice: ");

            switch (option)
            {

            // Searching the bus routes
            case 1:

                cout << "\nEnter the destination city : ";

                cin >> prefix;

                displayMatchedRoutes("Delhi", prefix);

                break;

            // Booking a ticket
            case 2:

                cout << "\nEnter the destination city: ";

                cin >> destination;

                bookTicket("Delhi", destination);

                break;

            // Display booking history
            case 3:

                displayBookingHistory();

                break;

                // Deleting the booked ticket
            case 4:
                deleteBookedTicket();

                break;

            // Sorting the booked tickets by price
            case 5:
                sortBookingsByPrice();

                break;

                // Exit after the desired operations
            case 6:
                cout << "Exiting the system. Thank you for using the Bus Booking System!\n";

                break;

            // Invalid choice
            default:
                cout << "Invalid choice. Please try again.\n";

                break;
            }

            // As only six operations are valid
        } while (option != 6);
    }
};

// The main function

void callBusBooking()
{

    // The class creating an identifier
    BusBookingSystem busBooking;

    // Reading the bus routes from the file
    busBooking.readBusRoutesFromFile("bus_routes.txt");

    // Function to choose what all operations we want to perform
    busBooking.startBooking();
}

void routeMap()
{
    // Google Drive link for the route map
    string googleDriveLink = "https://drive.google.com/file/d/18-H2HydOJOyq0GYjoajE9tSeMrlPjs-G/view?usp=sharing";

    // Message for the user
    cout << "Redirecting to the route map in your default browser...\n";

    // Command to open the URL in the default browser
    // This works on Windows. Adjust for Linux/Mac as needed.
    string command = "start " + googleDriveLink;

    // Execute the command to open the link
    int result = system(command.c_str());

    // Check if the command executed successfully
    if (result != 0)
    {
        // Notify the user in case of an error
        cout << "Failed to open the route map. Please check your internet connection or try again.\n";
    }
}