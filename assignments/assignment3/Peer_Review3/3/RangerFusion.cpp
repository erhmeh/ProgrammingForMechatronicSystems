#include "RangerFusion.h"
#include <cmath>


//Constructor
RangerFusion::RangerFusion(eFusionMethod method) {
    fusion_method_ = method;
}



void RangerFusion::setRangerBuffers(std::vector<RangerBuffer*> buffers) {
    ranger_buffers_ = buffers;
}


void RangerFusion::runFusion5Hz(ThreadBuffer &buffer) {
    while(true) {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::vector<cMeasurement> measurements_extrapolated;
        for (auto &i :ranger_buffers_) {
            std::pair<cMeasurement, cMeasurement> measurements = i->getValues(); //get measurements of buffer
            measurements_extrapolated.push_back(
                    extrapolateMeasurements(now, measurements)); //extrapolate to current time and store
        }

        double distance;
        //fuse measurements according to fusion method
        switch (fusion_method_) {
            case eFUSION_MAX:
                distance = findMax(measurements_extrapolated);
                break;
            case eFUSION_MIN:
                distance = findMin(measurements_extrapolated);
                break;
            case eFUSION_MEAN:
                distance = findMean(measurements_extrapolated);
                break;
        }
        //push into output buffer and notify
        buffer.addValue(std::pair<double, std::chrono::system_clock::time_point>(distance, now));

        //sleep for 5 hz frequency
        std::this_thread::sleep_until(now + std::chrono::milliseconds(200));
    }
}


void RangerFusion::runFusion(ThreadBuffer &buffer,NotificationBuffer &notificationBuffer)
{
    while(true)
    {
        RangerBuffer* latest_buffer = notificationBuffer.wait_for_notification(); //Wait until any ranger buffer receives a new value

        std::vector<cMeasurement> measurements_extrapolated;
        measurements_extrapolated.push_back(latest_buffer->getValues().first); //First value is recent value

        auto time = latest_buffer->getValues().first.time; //store time of latest measurement

        for (auto &i :ranger_buffers_) {
            if(i == latest_buffer)
            {
                continue; //Skip the buffer which received the latest value
            }
            std::pair<cMeasurement, cMeasurement> measurements = i->getValues(); //get measurements of buffer
            measurements_extrapolated.push_back(
                    extrapolateMeasurements(time, measurements)); //extrapolate to current time and store

        }
        double distance;

        //fuse measurements according to fusion method
        switch (fusion_method_) {
            case eFUSION_MAX:
                distance = findMax(measurements_extrapolated);
                break;
            case eFUSION_MIN:
                distance = findMin(measurements_extrapolated);
                break;
            case eFUSION_MEAN:
                distance = findMean(measurements_extrapolated);
                break;
        }
        //push into output buffer and notify
        buffer.addValue(std::pair<double, std::chrono::system_clock::time_point>(distance, time));
    }
}


cMeasurement RangerFusion::extrapolateMeasurements(std::chrono::system_clock::time_point now,
                                                   std::pair<cMeasurement, cMeasurement> meas)
{
    if(meas.first.time == now)
    {
        return meas.first;
    }else
    {
        // Linear extrapolation
        //
        //                  x* - x_k-1
        // y(x*) = y_k-1 + ------------ * (y_k - y_k-1)
        //                  x_k - x_k-1
        //

        double factor = (double)(now-meas.second.time).count() / (double)(meas.first.time-meas.second.time).count() ;// (meas.first.time-meas.second.time);

        double extrapolated = meas.second.measurement.front() + factor * (meas.first.measurement.front() - meas.second.measurement.front());

        //Extrapolation does not make sense if it exceeds the sensing range of the sensor
        // This would predict the obstacle into the future and would include knowledge outside of the FOV which is
        // not possible
        if (extrapolated > meas.first.ranger_max_distance)
        {
            extrapolated = meas.first.ranger_max_distance;
        }
        if (extrapolated < meas.first.ranger_min_distance)
        {
            extrapolated = meas.first.ranger_min_distance;
        }

        cMeasurement extrap;
        extrap.time = now;
        extrap.measurement.push_back(extrapolated);
        extrap.ranger_min_distance = meas.first.ranger_min_distance;
        extrap.ranger_max_distance = meas.first.ranger_max_distance;
        extrap.ranger_FOV = meas.first.ranger_FOV;
        extrap.rangerType = meas.first.rangerType;

        return extrap;
    }
}


//Returns the maximum distance of a ranger taking minimal measuring ranges into account
double RangerFusion::findMax(std::vector<cMeasurement> measurements) {
    double max = 0;
    for (auto &i: measurements) {
        //Take distance as a new maximum when it is larger but not the minimum distance of the ranger, as this
        //gives no definite output
        if(i.measurement.front() > max && i.measurement.front() > i.ranger_min_distance)
        {
            max = i.measurement.front();
        }
    }
    return max;
}



//Returns the minimum distance of a ranger taking maximal measuring ranges into account
double RangerFusion::findMin(std::vector<cMeasurement> measurements) {
    if(measurements.empty())
    {
        return 0;
    }
    double min = std::numeric_limits<double>::infinity();
    for (auto &i: measurements) {
        //Take distance as a new minimum when it is smaller but not the maximum distance of the ranger, as this
        //gives no definite output
        if(i.measurement.front() < min && i.measurement.front() < i.ranger_max_distance)
        {
            min = i.measurement.front();
        }
    }
    //If all sensors return their maximal distance, no object can be detected. Therefore the maximal value is the most
    //accurate information when
    if (min == std::numeric_limits<double>::infinity())
    {
        min = findMax(measurements);
    }
    return min;
}


//Returns the average distance of all measurements
//No further instruction is given on how to handle measuring limits in calculating the average.
//Therefore all measurements are taken into account, as all other ways of handling maximum and minimum distances
//are not consistent if more than two rangers are present.
double RangerFusion::findMean(std::vector<cMeasurement> measurements) {
    if(measurements.empty())
    {
        return 0;
    }
    double mean = 0;
    for (auto &i:measurements) {
        mean += i.measurement.front();
    }
    mean /= measurements.size();
    return mean;
}


