#include <iostream>
#include "date.h"

#include "RangerFusion.h"
#include "radar.h"
#include "sonar.h"


using namespace std;

void printSensorDetails(Ranger &ranger);
void printFusedData(ThreadBuffer &buffer);
void updateSonarSettings(Sonar &sonar);
void updateRadarSettings(Radar &radar);

int main ()
{
    vector<RangerBuffer*> ranger_buffers;
    NotificationBuffer notificationBuffer;

    cout << "Please configure the sensors:" << endl;

    Radar radar1;// = new Radar;
    updateRadarSettings(radar1);
    RangerBuffer radar_buffer(&notificationBuffer);
    ranger_buffers.push_back(&radar_buffer);
    thread radar_thread(&Radar::run,radar1,ref(radar_buffer));

    Sonar sonar1;
    updateSonarSettings(sonar1);
    RangerBuffer sonar_buffer1(&notificationBuffer);
    ranger_buffers.push_back(&sonar_buffer1);
    thread sonar_thread(&Sonar::run,sonar1,ref(sonar_buffer1));

    /*Radar radar2;// = new Radar;
    updateRadarSettings(radar2);
    RangerBuffer radar_buffer2(&notificationBuffer);
    ranger_buffers.push_back(&radar_buffer2);
    thread radar_thread2(&Radar::run,radar2,ref(radar_buffer2));
    */

    char rangerSettings = 'q';
    eFusionMethod method = eFUSION_MIN;


    cout << "Please enter fusion method: " << endl;
    cout << "1: MIN" << endl;
    cout << "2: MAX" << endl;
    cout << "3: MEAN" << endl;
    char method_char;
    cin >> method_char;
    switch (method_char) {
        case '1':
            method = eFUSION_MIN;
            break;
        case '2':
            method = eFUSION_MAX;
            break;
        case '3':
            method = eFUSION_MEAN;
            break;
    }
    RangerFusion rangerFusion(method);

    ThreadBuffer fused_buffer;

    //Declare thread for fusion
    thread fusion_thread;

    //pass ranger_buffers to fusion type
    rangerFusion.setRangerBuffers(ranger_buffers);

    //Start fusion thread according to fusion type
    cout << "Do you want to fuse at 5Hz or on every new data: " << endl;
    cout << "1: 5 Hz" << endl;
    cout << "2: On every new data" << endl;
    char type_char;
    cin >> type_char;
    switch (type_char) {
        case '1':
            fusion_thread = thread(&RangerFusion::runFusion5Hz,rangerFusion,ref(fused_buffer));
            break;
        case '2':
            fusion_thread = thread(&RangerFusion::runFusion,rangerFusion,ref(fused_buffer),ref(notificationBuffer));
            break;
    }

    cout << "Data transfer starts:"<<endl<<endl;

    //Start print thread which works on fusion buffer
    thread print_thread(printFusedData,ref(fused_buffer));

    //wait for ever as print thread never terminates
    print_thread.join();
}




void printFusedData(ThreadBuffer &buffer)
{
    while(true) {
        using namespace date;
        using namespace std::chrono;
        std::pair<double, std::chrono::system_clock::time_point> meas = buffer.getValues();

        cout << "Fused result measurement at " << meas.second << ":    " << meas.first << endl;
    }
}


void printSensorDetails(Ranger &ranger)
{
    cout <<endl<< "------------------------" << endl;
    cout << "Model: " << ranger.getModel() << endl;
    cout << "Baud: " << ranger.getBaud() << endl;
    cout << "Port: /dev/ttyUSB" << ranger.getPort() << endl;
    cout << "Field of View: " << ranger.getFieldOfView() << endl;
    cout << "Max Distance: " << ranger.getMaxDistance() << endl;
    cout << "Min Distance: " << ranger.getMinDistance() << endl;
    cout << "Data rate: " << ranger.getDataRate() << endl;
    cout << "------------------------" << endl;
}

void updateRadarSettings(Radar &radar) {
    printSensorDetails(radar);

    int usb;
    cout <<endl<< "Please enter USB port. Valid USB: " << radar.getValidPort() << endl;
    cin >> usb;
    if (radar.setPort(usb)) {
        cout << "USB port set to /dev/ttyUSB" << usb << endl;
    } else {
        cout << "Invalid port, using default value: /dev/ttyUSB" << radar.getPort() << endl;
    }

    int baud;
    cout << "Please enter baud rate. Valid Baud: " << radar.getValidBaud() << endl;
    cin >> baud;
    if (radar.setBaud(baud)) {
        cout << "Baud rate set to " << baud << endl;
    } else {
        cout << "Invalid baud rate, using default value: " << radar.getBaud() << endl;
    }

    double FOV;
    cout << "Please enter field of view. Valid field of view: " << radar.getValidFOV() << endl;
    cin >> FOV;
    if (radar.setFOV(FOV)) {
        cout << "Field of view set to: " << FOV << endl;
    } else {
        cout << "Invalid field of view, using default value: " << radar.getFieldOfView() << endl;
    }
    cout <<endl;
    printSensorDetails(radar);
    cout<<endl;
}


void updateSonarSettings(Sonar &sonar) {
    printSensorDetails(sonar);

    int usb;
    cout << "Please enter USB port. Valid USB: " << sonar.getValidPort() << endl;
    cin >> usb;
    if (sonar.setPort(usb)) {
        cout << "USB port set to /dev/ttyUSB" << usb << endl;
    } else {
        cout << "Invalid port, using default value: /dev/ttyUSB" << sonar.getPort() << endl;
    }

    int baud;
    cout << "Please enter baud rate. Valid Baud: " << sonar.getValidBaud() << endl;
    cin >> baud;
    if (sonar.setBaud(baud)) {
        cout << "Baud rate set to " << baud << endl;
    } else {
        cout << "Invalid baud rate, using default value: " << sonar.getBaud() << endl;
    }

    cout <<endl;
    printSensorDetails(sonar);
    cout<<endl;
}