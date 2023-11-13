#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Get CVT Info 

string getCVTInfo(){

    // Change "720 1500" to desired display resolution | CVT Section
    
    system("cvt 720 1500 | grep -o '\".*' > cvtInfo.txt");

    fstream cvtInfo;
    string cvt;

    cvtInfo.open("cvtInfo.txt",ios::in);
    
    if (cvtInfo.is_open()){

        getline(cvtInfo, cvt);
        return cvt;

    } else {

        cout << "Failed to get CVT";

    }
    cvtInfo.close();
}

string getMonitorRes(){

    system("cvt 720 1500 | grep -o '\".*' | cut -d' ' -f1 > monitorRes.txt");

    fstream monitorRes;
    string res;

    monitorRes.open("monitorRes.txt",ios::in);
    
    if (monitorRes.is_open()){

        getline(monitorRes, res);
        return res;

    } else {

        cout << "Failed to get Resolution";

    }
    monitorRes.close();
}

string getMonitorName(){

    // Get Monitor Name using xrandr i.e (HDMI-1, DP-1, VIRTUAL-1)
    string monitorName;

    cout << system("xrandr");
    cout << "\n\nFrom the above, input monitor name and press 'Enter' e.g (HDMI-1, DP-1, VIRTUAL-1): ";
    cin >> monitorName;
    return monitorName;
}

// Create autoStart.sh

void createAutoStart(){

    // Add CVT information to command
    fstream autoStart;
    string cvt = getCVTInfo();
    string monitorRes = getMonitorRes();
    string monitorName = getMonitorName();

    autoStart.open("autoStart.sh",ios::out); //Create Auto Start

    if (autoStart.is_open()){

        autoStart << "#!/bin/bash\n\nxrandr --newmode " << cvt << endl;
        autoStart << "xrandr --addmode " << monitorName << " " << monitorRes << endl;
        autoStart << "xrandr -s " << monitorRes;

    } 
    else{

        cout << "Failed to create autoStart.sh";

    }
    autoStart.close();

}


int main(){

    // Run Program

    createAutoStart();
  
    return 0;


}

