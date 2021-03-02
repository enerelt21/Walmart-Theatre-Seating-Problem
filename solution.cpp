#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <map>

using namespace std;
map <string, int> res; // input hashtable
map <string, vector<string> > ans; // output hashtable
bool check[10][20] = {0}; // check if the current seat is available

// Function that assigns the seats following the safety guideline 
// while providing the most convenient seat as possible per each reservation
void solve(int row, string key){
    int col=-1; // initial value of the column assuming the row is unavailable
    for(int i=0; i<20; i++)
        if (!check[row][i]){
            col = i; // if the available seat is found, mark the seat as available
            break;
        }
    
    // If there is no seat available in row, or the reservation capacity exceeds the available seat in the row
    if (col == -1 || (col != -1 && col + res[key] > 20)){
        solve(row+1, key);
        return;
    }

    // If all possible seats are reserved, put the reservation on Waitlist
    if (row > 9 || (row == 9 && col + res[key] > 20)){
        ans[key].push_back("Waitlisted");
        return;
    }

    // Temporary storage to keep the number of seats requested
    int seatCount = res[key];
    while(seatCount--){

        // The following process assigns tickets for each seats
        string s;
        char temp = 'J' - row;
        s += temp;
        s += to_string(col+1);
        ans[key].push_back(s);
        check[row][col] = true;
        col++;
    }

    // Due to the safety guideline, we have to mark next 3 seats as unavailable
    // If there are less than 3 seats left in the row, simply mark rest of the seats as unavailable
    int count = 3;
    while(col < 20 && count){
        check[row][col] = true;
        col++;
        count--;
    }
}
int main(){
    // Input file stream
    ifstream cin("input.txt");

    // Output file stream
    ofstream cout("output.txt");

    // Reservation ID
    string resNum;
    // Number of seats requested for that specific resNum
    int resCount;
    string line;

    // Read input file line by line
    while(getline(cin, line)){
        // Within the read line, take reservation ID and reservation count separately
        istringstream iss(line);
        iss >> resNum;
        iss >> resCount;

        // resNum is the key for our input hashtable and the number of seat requested is the value
        res[resNum] = resCount;

        // reserve number of seats in our output hashtable
        ans[resNum].reserve(resCount);

        // Solving the problem
        solve(0,resNum);
    }

    // Outputing corresponding tickets or waitlist status per each reservation
    for(auto &el: ans){
        cout << el.first << " ";
        for(int k=0;k<el.second.size()-1;k++)
            cout << el.second[k] << ", ";
        
        // The last element of output shouldn't followed by comma
        cout << el.second[el.second.size()-1];
        cout << endl;
    }
    return 0;
}