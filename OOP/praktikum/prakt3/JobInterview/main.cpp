#include <iostream>
#include <fstream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int MAX_NAME = 25;
const char FILENAME[] = "job_offers.bin";

struct JobOffer {
    char name[MAX_NAME];
    int developers;
    int paidLeave;
    long long salary;

    void print() const {
        cout << name << ", ";
        cout << "developers: " << developers << ", ";
        cout << "paid leave: " << paidLeave << ", ";
        cout << "salary: " << salary << endl;

    }

};

void initOffers(int n);

bool writeOfferToFile(const JobOffer &offer);

void filterOffers(long long minSalary);

void perfectOffers(int maxCoworkers, int minVacancyDays, int minSalary);

bool offerExists(const char *companyName);

int main() {
    //exists
    char *name = "Microsoft";
    cout << "Checking if company with name - " << name << " exists..." << endl;
    cout << boolalpha << offerExists(name) << endl;

    //filter offers
    int minSalary = 100;

    cout << "Companies with minimum salary " << minSalary << ": " << endl;
    filterOffers(minSalary);
    cout << endl;

    //perfect offers
    int minVacancyDays = 15;
    int maxCoworkers = 20;

    cout << "Perfect offers:" << endl;
    perfectOffers(maxCoworkers, minVacancyDays, minSalary);
    cout << endl;

    cout << "How many offers do you want to enter?" << endl;
    int n;
    cin >> n;

    initOffers(n);

    return 0;
}

void initOffers(int n) {
    for (int i = 0; i < n; ++i) {
        JobOffer offer;
        cout << "Enter the name of company " << i + 1 << ":" << endl;
        cin >> offer.name;

        cout << "Enter the number of developers you will work with:" << endl;
        cin >> offer.developers;

        cout << "Enter the paid leave days they offer:" << endl;
        cin >> offer.paidLeave;

        cout << "Enter the salary they offer:" << endl;
        cin >> offer.salary;

        if (writeOfferToFile(offer)) {
            cout << "Successfully added an offer to the file!" << endl;
        } else {
            cout << "Something went wrong!" << endl;
        }
    }
}

bool writeOfferToFile(const JobOffer &offer) {
    ofstream writeFile;
    writeFile.open(FILENAME, ofstream::app);

    if (!writeFile.is_open())
        return false;

    writeFile.write((char *) &offer, sizeof(JobOffer));

    writeFile.close();
    return true;
}

int getFileLength(ifstream &readFile) {
    readFile.seekg(0, ios::end);

    int length = readFile.tellg();

    readFile.seekg(0);

    return length;
}

void filterOffers(long long minSalary) {
    ifstream readFile(FILENAME);

    if (!readFile.is_open())
        return;

    int size = getFileLength(readFile) / sizeof(JobOffer);

    for (int i = 0; i < size; ++i) {
        JobOffer offer;

        readFile.read((char *) &offer, sizeof(JobOffer));

        if (offer.salary >= minSalary)
            offer.print();

    }

    readFile.close();
}

void perfectOffers(int maxCoworkers, int minVacancyDays, int minSalary) {
    ifstream readFile(FILENAME);

    if (!readFile.is_open())
        return;

    int size = getFileLength(readFile) / sizeof(JobOffer);

    for (int i = 0; i < size; ++i) {
        JobOffer offer;

        readFile.read((char *) &offer, sizeof(JobOffer));

        if (offer.salary >= minSalary && offer.developers <= maxCoworkers && offer.paidLeave >= minVacancyDays)
            offer.print();

    }

    readFile.close();
}

unsigned my_strlen(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

bool isStrEqual(const char *str1, const char *str2) {
    unsigned str1Length = my_strlen(str1);
    unsigned str2Length = my_strlen(str2);

    if (str1Length != str2Length) return false;

    for (int i = 0; i < str1Length; ++i) {
        if (str1[i] != str2[i])
            return false;

    }

    return true;
}

bool offerExists(const char *companyName) {
    ifstream readFile(FILENAME);

    if (!readFile.is_open())
        return false;

    int size = getFileLength(readFile) / sizeof(JobOffer);

    for (int i = 0; i < size; ++i) {
        JobOffer offer;

        readFile.read((char *) &offer, sizeof(JobOffer));

        if (isStrEqual(companyName, offer.name))
            return true;
    }

    return false;
}

