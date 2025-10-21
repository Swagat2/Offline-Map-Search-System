
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


vector<Location> searchLocations(const vector<Location>& locations, const string& query, bool debug = false) {
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


// FUNCTION: Automated test cases


