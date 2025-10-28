#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Location {
    string name;
    string type;
    double latitude;
    double longitude;
};

// Search Function
vector<Location> searchLocations(const vector<Location>& locations, const string& query, bool debug=false) {
    vector<Location> results;
    string lowerQuery = query;
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    for (const auto& loc : locations) {
        string name = loc.name;
        string type = loc.type;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (debug)
            cout << "[DEBUG] Checking: " << name << " (" << type << ")\n";

        if (name.find(lowerQuery) != string::npos || type.find(lowerQuery) != string::npos)
            results.push_back(loc);
    }

    if (debug)
        cout << "[DEBUG] Total results found: " << results.size() << "\n";

    return results;
}

// Test Function
void runTests() {
    vector<Location> testLocations = {
        {"City Hospital", "Hospital", 20.2961, 85.8245},
        {"AIIMS Bhubaneswar", "Hospital", 20.2443, 85.8189},
        {"Utkal University", "Education", 20.2878, 85.8249},
        {"Kalinga Stadium", "Sports", 20.2852, 85.8248},
        {"Bhubaneswar Railway Station", "Transport", 20.2700, 85.8300}
    };

    struct TestCase {
        string query;
        int expectedCount;
    };

    vector<TestCase> tests = {
        {"Hospital", 2},
        {"Education", 1},
        {"stadium", 1},
        {"Transport", 1},
        {"Park", 0} // should return 0 results
    };

    cout << "\nRunning Test Cases...\n";
    for (auto& test : tests) {
        auto result = searchLocations(testLocations, test.query);
        cout << "Query: " << test.query
             << " | Expected: " << test.expectedCount
             << " | Got: " << result.size()
             << (result.size() == test.expectedCount ? " ✅" : " ❌")
             << "\n";
    }
}

//Main Function
int main() {
    vector<Location> locations = {
        {"City Hospital", "Hospital", 20.2961, 85.8245},
        {"Bhubaneswar Railway Station", "Transport", 20.2700, 85.8300},
        {"Utkal University", "Education", 20.2878, 85.8249},
        {"Kalinga Stadium", "Sports", 20.2852, 85.8248},
        {"AIIMS Bhubaneswar", "Hospital", 20.2443, 85.8189}
    };

//Enable Debugging or Tests
    cout << "Enter mode (search/test/debug): ";
    string mode;
    cin >> mode;
    cin.ignore();

    if (mode == "test") {
        runTests();
    }
    else if (mode == "debug") {
        string query;
        cout << "Enter search query: ";
        getline(cin, query);
        auto results = searchLocations(locations, query, true);
        if (results.empty())
            cout << "No matching locations found.\n";
        else
            for (auto& loc : results)
                cout << loc.name << " | " << loc.type << " | ("
                     << loc.latitude << ", " << loc.longitude << ")\n";
    }
    else if (mode == "search") {
        string query;
        cout << "Enter search query: ";
        getline(cin, query);
        auto results = searchLocations(locations, query);
        if (results.empty())
            cout << "No matching locations found.\n";
        else
            for (auto& loc : results)
                cout << loc.name << " | " << loc.type << " | ("
                     << loc.latitude << ", " << loc.longitude << ")\n";
    }
    else {
        cout << "Invalid mode. Use: search, test, or debug.\n";
    }

    return 0;
}
