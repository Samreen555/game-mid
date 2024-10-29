#include <iostream>
#include <limits>
using namespace std;

class Node {
public:
    int runs;
    Node* next;
    Node* prev;

    Node(int runs) : runs(runs), next(nullptr), prev(nullptr) {}
};

class CricketTeamPerformance {
private:
    Node* head;
    Node* tail;

public:
    CricketTeamPerformance() : head(nullptr), tail(nullptr) {}

    // Add runs at the start of the list
    void addRunsAtStart(int runs) {
        Node* newNode = new Node(runs);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Added score " << runs << " at the beginning.\n";
    }

    // Add runs at the end of the list
    void addRunsAtEnd(int runs) {
        Node* newNode = new Node(runs);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Added score " << runs << " at the end.\n";
    }

    // Delete all occurrences of a specific score
    void deleteScore(int runs) {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        Node* current = head;
        bool found = false;

        while (current) {
            if (current->runs == runs) {
                found = true;
                Node* temp = current;
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                current = current->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }

        if (found) {
            cout << "All occurrences of score " << runs << " deleted.\n";
        }
        else {
            cout << "Score not found in any match.\n";
        }
    }

    // Display all scores from first to last
    void displayScoresForward() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        cout << "Scores from first match to last match:\n";
        Node* current = head;
        while (current) {
            cout << current->runs << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Display all scores from last to first
    void displayScoresReverse() {
        if (!tail) {
            cout << "No matches recorded yet.\n";
            return;
        }

        cout << "Scores from last match to first match:\n";
        Node* current = tail;
        while (current) {
            cout << current->runs << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Find and display the highest and lowest scores
    void findHighestAndLowest() {
        if (!head) {
            cout << "No matches recorded yet.\n";
            return;
        }

        int highest = numeric_limits<int>::min();
        int lowest = numeric_limits<int>::max();

        Node* current = head;
        while (current) {
            if (current->runs > highest) highest = current->runs;
            if (current->runs < lowest) lowest = current->runs;
            current = current->next;
        }

        cout << "Highest score: " << highest << "\n";
        cout << "Lowest score: " << lowest << "\n";
    }

    // Destructor to clear the list
    ~CricketTeamPerformance() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    CricketTeamPerformance team;
    int choice, runs;

    while (true) {
        cout << "\n--- Cricket Team Performance Menu ---\n";
        cout << "1. Add Runs at Start\n";
        cout << "2. Add Runs at End\n";
        cout << "3. Delete All Occurrences of a Score\n";
        cout << "4. Display Scores in Sequence\n";
        cout << "5. Display Scores in Reverse Sequence\n";
        cout << "6. Find Highest and Lowest Scores\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter runs scored: ";
            cin >> runs;
            team.addRunsAtStart(runs);
            break;
        case 2:
            cout << "Enter runs scored: ";
            cin >> runs;
            team.addRunsAtEnd(runs);
            break;
        case 3:
            cout << "Enter score to delete: ";
            cin >> runs;
            team.deleteScore(runs);
            break;
        case 4:
            team.displayScoresForward();
            break;
        case 5:
            team.displayScoresReverse();
            break;
        case 6:
            team.findHighestAndLowest();
            break;
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
