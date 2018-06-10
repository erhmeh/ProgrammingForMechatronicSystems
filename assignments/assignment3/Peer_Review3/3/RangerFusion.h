#ifndef RANGER_FUSION_H
#define RANGER_FUSION_H

#include "CustomTypes.h"
#include "ranger.h"

#include "RangerBuffer.h"
#include "ThreadBuffer.h"
#include "NotificationBuffer.h"

#include <thread>
#include <vector>


enum eFusionMethod{
    eFUSION_MAX = 0,
    eFUSION_MIN = 1,
    eFUSION_MEAN = 2,
};

/*! \class RangerFusion
    \brief Class to fuse measurements of multiple rangers of different types
 *  \date      20.05.2018
    Ranger fusion is a class which implements different fusion methods as averaging all measurements, taking the maximum
    or the minimum value and returning the fused result.
    The fusion thread can return a value with a frequency of 5 Hz or on every new available measurement depending on which
    function is started as a thread.
    The fusion class can fuse unlimited number of rangers in unspecified order.
*/

class RangerFusion
{
private:
    /**
    * Vector storing pointer to all RangerBuffers which are connected to the ranger fusion
    */
    std::vector<RangerBuffer*> ranger_buffers_;
    /**
    * Paramter specifiying the fusion method
    */
    eFusionMethod fusion_method_;

    //! Private function to extrapolate measurements.
    /*! Linear extrapolation of the measurement limiting the value to the sensing range of the ranger as exceeding the
     * sensing range would produce unreliable information. This would predict the measurement not only into the future but
     * also outside of the field of view of the sensor.
     * \param time Time_point for which the measurement should be extrapolated
     * \param meas Pair holding cMeasurement structs containing the latest(first) and last(second) measurement
      \return cMeasuerment struct holding the extrapolated distance measurement at time specied in time
    */
    cMeasurement extrapolateMeasurements(std::chrono::system_clock::time_point time,
                                         std::pair<cMeasurement, cMeasurement> meas);

    //! Private function to find the maximum measurement
    /*! Measurements at the minimal sensing range of a ranger are disregarded as these give no reliable information
     * \param measurements Vector holding all cMeasurment structs which should be compared
      \return double representing the maximum value of all measurements
    */
    double findMax(std::vector<cMeasurement> measurements);

    //! Private function to find the minimum measurement
    /*! Measurements at the maximal sensing range of a ranger are disregarded as these give no reliable information
     * \param measurements Vector holding all cMeasurment structs which should be compared
      \return double representing the minimum value of all measurements
    */
    double findMin(std::vector<cMeasurement> measurements);

    //! Private function to find the average measurement
    /*! All measurements disregarding sensing boundaries are used to find an average of all measurements.
     * Sensing range boundaries are not taken into account as the fusion is not specified and not trivial. See my post in
     * the discussion board.
     * \param measurements Vector holding all cMeasurment structs which should be compared
      \return double representing the average value of all measurements
    */
    double findMean(std::vector<cMeasurement> measurements);

public:
    //!Constructor of the RangerFusion
    /*! Sets the parameter for the desired fusion method
      \param method Enum specifying the desired fusion method
    */
    RangerFusion(eFusionMethod method);

    //!Function passed to a thread running the fusion with a frequency of 5HZ
    /*! Thread functionality fusing all measurements in the RangerBuffers which are stored as a member
     * Fusion of measurements runs according to specified fusion method
      \param buffer A pointer to a ThreadBuffer to hold store the fused result
    */
    void runFusion5Hz(ThreadBuffer &buffer);

    //!Function passed to a thread running the fusion on every new data
    /*! Thread functionality fusing all measurements in the RangerBuffers which are stored as a member
     * Fusion of measurements runs according to specified fusion method
     * Fusion is activated by notification of the Notification buffer which is triggered by on RangerBuffer
     * \param notificationBuffer Notification buffer to allow multiple notification by one of the muliple prucer threads
      \param buffer A pointer to a ThreadBuffer to hold store the fused result
    */
    void runFusion(ThreadBuffer &buffer, NotificationBuffer &notificationBuffer);

    //!Function to accept a vector holding pointers to all RangerBuffer
    /*! This function must be called before the ranger fusion is started as a setup.
      \param buffers Vector holding pointers to all RangerBuffer
    */
    void setRangerBuffers(std::vector<RangerBuffer*> buffers);
};

#endif //RANGER_FUSION_H
