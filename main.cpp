#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

/*
 * ==========================================================
 *  GroceryTracker Class
 * ----------------------------------------------------------
 *  Purpose:
 *      - Reads grocery purchase data from an input file
 *      - Stores item frequencies using std::map
 *      - Automatically generates a backup file (frequency.dat)
 *      - Provides reporting functionality via public methods
 *
 *  Design:
 *      - Encapsulated private data members
 *      - Clear separation of responsibilities
 *      - Const-correct member functions
 * ==========================================================
 */
class GroceryTracker {
private:
    map<string, int> itemFrequencyMap;     // Stores item name and purchase count
    string inputFileName;                  // Input file name
    string backupFileName = "frequency.dat";  // Backup output file

    /*
     * Reads grocery items from file and populates frequency map.
     */
    void LoadDataFromFile() {
        ifstream inputFile(inputFileName);
        string currentItem;

        if (!inputFile.is_open()) {
            cerr << "Error: Unable to open input file.\n";
            return;
        }

        // Increment frequency for each item read
        while (getline(inputFile, currentItem)) {
            itemFrequencyMap[currentItem]++;
        }

        inputFile.close();
    }

    /*
     * Creates a backup data file containing item frequencies.
     */
    void CreateBackupFile() {
        ofstream outputFile(backupFileName);

        if (!outputFile.is_open()) {
            cerr << "Error: Unable to create backup file.\n";
            return;
        }

        // Write each item and its count to backup file
        for (const auto& [itemName, count] : itemFrequencyMap) {
            outputFile << itemName << " " << count << endl;
        }

        outputFile.close();
    }

public:
    /*
     * Constructor
     * Initializes object by loading data and generating backup file.
     */
    explicit GroceryTracker(const string& fileName)
        : inputFileName(fileName) {
        LoadDataFromFile();
        CreateBackupFile();
    }

    /*
     * Returns frequency of specified item.
     * If item does not exist, returns 0.
     */
    int GetItemFrequency(const string& itemName) const {
        auto search = itemFrequencyMap.find(itemName);

        if (search != itemFrequencyMap.end()) {
            return search->second;
        }

        return 0;
    }

    /*
     * Prints all items and their purchase frequencies.
     */
    void PrintAllFrequencies() const {
        cout << "\nItem Purchase Frequencies\n";
        cout << "--------------------------\n";

        for (const auto& [itemName, count] : itemFrequencyMap) {
            cout << setw(15) << left << itemName
                 << count << endl;
        }
    }

    /*
     * Prints histogram representation of purchase frequencies.
     * Each '*' represents one purchase.
     */
    void PrintHistogram() const {
        cout << "\nItem Frequency Histogram\n";
        cout << "--------------------------\n";

        for (const auto& [itemName, count] : itemFrequencyMap) {
            cout << setw(15) << left << itemName;

            for (int i = 0; i < count; ++i) {
                cout << "*";
            }

            cout << endl;
        }
    }
};

/*
 * Displays program menu options.
 */
void DisplayMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Search for item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Select an option: ";
}

/*
 * Entry point of the program.
 */
int main() {
    const int MIN_MENU_OPTION = 1;
    const int MAX_MENU_OPTION = 4;

    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int userChoice = 0;
    string itemName;

    while (userChoice != 4) {
        DisplayMenu();
        cin >> userChoice;

        // Validate numeric menu selection
        if (cin.fail() || userChoice < MIN_MENU_OPTION || userChoice > MAX_MENU_OPTION) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid selection. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (userChoice) {
        case 1:
            cout << "Enter item name: ";
            cin >> itemName;

            cout << itemName << " was purchased "
                 << tracker.GetItemFrequency(itemName)
                 << " time(s).\n";
            break;

        case 2:
            tracker.PrintAllFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    }

    return 0;
}