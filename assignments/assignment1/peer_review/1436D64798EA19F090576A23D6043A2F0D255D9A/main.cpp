#include "sensor.h"

using namespace std;

void defaultParameters(Sensor a){                                       //function to print out the default parameters with getters
    cout << "Sensor Parameters" << endl;
    cout << "Model: UTM-XXL" << endl;
    cout << "Baud Rate: " << a.getBaudRate() << endl;
    cout << "Port: " << a.getPort() << endl;
    cout << "Field of View: 180 degrees" << endl;
    cout << "Angular Resolution: " << a.getAngRes() << " deg" << endl;
    cout << "Scanning Time: " << a.getScanTime() << " ms" << endl;
    cout << "Max Distance: 8.0m, Min Distance: 0.2m\n" << endl;
}

void parameterSetter(Sensor a){                                         //function for user to set the sensor parameters
    int userBaud = 0;
    int userPort = 0;
    char initiate;
    double userRes = 0;
    double userScan = 0;

    cout << "Please select a Baud rate (38400 or 115200): " << endl;
    cin >> userBaud;
    a.setBaudRate(userBaud);

    cout << "Please select a port (0, 1 or 2): " << endl;
    cin >> userPort;
    a.setPort(userPort);

    cout << "Please select an angular resolution (0.5 or 1.0 deg): " << endl;
    cin >> userRes;
    a.setAngRes(userRes);

    cout << "Please select a scanning time (25 or 50 ms): " << endl;
    cin >> userScan;
    a.setScanTime(userScan);
    cout << "\n" << endl;

    cout << "Sensor initialised with user inputs... " << endl;
    cout << "Please enter any letter/numerical key to initiate scanning. " << endl;
    cin >> initiate;
}

int main(void){
    Sensor a;
    defaultParameters(a);
    parameterSetter(a);
    a.scanning();
}

