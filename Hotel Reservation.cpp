#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a hotel room
class Room {
public:
    Room(int roomNumber, bool isOccupied = false) : roomNumber(roomNumber), occupied(isOccupied) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    bool isOccupied() const {
        return occupied;
    }

    void occupy() {
        occupied = true;
    }

    void vacate() {
        occupied = false;
    }

private:
    int roomNumber;
    bool occupied;
};

// Function to display the menu
void displayMenu() {
    cout << "Hotel Reservation System" << endl;
    cout << "1. Check Room Availability" << endl;
    cout << "2. Reserve a Room" << endl;
    cout << "3. Vacate a Room" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    vector<Room> rooms;

    // Initialize rooms
    for (int i = 1; i <= 10; i++) {
        rooms.push_back(Room(i));
    }

    int choice;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Room Availability:" << endl;
                for (const Room& room : rooms) {
                    cout << "Room " << room.getRoomNumber() << ": ";
                    if (room.isOccupied()) {
                        cout << "Occupied" << endl;
                    } else {
                        cout << "Available" << endl;
                    }
                }
                break;

            case 2:
                int roomNumber;
                cout << "Enter room number to reserve: ";
                cin >> roomNumber;
                if (roomNumber >= 1 && roomNumber <= 10) {
                    Room& room = rooms[roomNumber - 1];
                    if (!room.isOccupied()) {
                        room.occupy();
                        cout << "Room " << room.getRoomNumber() << " reserved successfully." << endl;
                    } else {
                        cout << "Room " << room.getRoomNumber() << " is already occupied." << endl;
                    }
                } else {
                    cout << "Invalid room number." << endl;
                }
                break;

            case 3:
                cout << "Enter room number to vacate: ";
                cin >> roomNumber;
                if (roomNumber >= 1 && roomNumber <= 10) {
                    Room& room = rooms[roomNumber - 1];
                    if (room.isOccupied()) {
                        room.vacate();
                        cout << "Room " << room.getRoomNumber() << " vacated successfully." << endl;
                    } else {
                        cout << "Room " << room.getRoomNumber() << " is not occupied." << endl;
                    }
                } else {
                    cout << "Invalid room number." << endl;
                }
                break;

            case 4:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

