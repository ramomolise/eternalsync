#include <iostream>
#include <string>

using namespace std;

int main(){

    // Get system info

    string monitorName;
    
    system("cvt 720 1500 > cvtInfo.txt");

    cout << system("xrandr");
    cout << "\n\nFrom the above, input monitor name and press 'Enter': ";
    cin >> monitorName;

    // Create resMod.sh
    return 0;


}

