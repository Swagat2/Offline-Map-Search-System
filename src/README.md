🗺️ Offline Map Search Tool

An Offline Map Search Tool that allows users to search for places, routes, and nearby locations without needing an internet connection.
The system stores all map data locally (in files or a local database) and retrieves results using efficient search algorithms.

🚀 Features

✅ Offline Access – Works completely offline using preloaded map data.
✅ Location Search – Find places by name or category (e.g., hospital, school, restaurant).
✅ Nearby Search – Locate points of interest near your current location.
✅ Efficient Retrieval – Uses optimized search and filtering techniques for fast lookups.
✅ Test Mode – Built-in test cases to validate search functionality.
✅ Debug Mode – View detailed logs of the search process for development and testing.

🧩 How It Works

The application uses locally stored data (e.g., .txt or .csv files, or a lightweight local database) containing:

Place Name

Category/Type

Latitude & Longitude Coordinates

When a user searches, the tool scans the local dataset and returns matching entries using substring and category matching.

📘 Example Output
Enter mode (search/test/debug): search
Enter search query: hospital

Found: City Hospital
Type: Hospital
Coordinates: (20.2961, 85.8245)

Found: AIIMS Bhubaneswar
Type: Hospital
Coordinates: (20.2443, 85.8189)
