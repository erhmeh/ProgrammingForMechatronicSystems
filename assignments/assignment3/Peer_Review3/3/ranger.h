#ifndef RANGER_H
#define RANGER_H

#include <string>
#include <vector>
#include "RangerBuffer.h"
#include "CustomTypes.h"

/** Enum specifying the different ports
 *  USB Ports at which sensors can be connected
 */
enum PORT{
    USB0 = 0,
    USB1 = 1,
    USB2 = 2
};

/** Enum specifying the different baud rates the ranger can communicate at
 *  The ranger can be set to communicate at different baud rates
 */
enum BAUD{
    c38400 = 38400,
    c115200 = 115200,
};

/*! \class Ranger
    \brief Abstract parent class of rangers implementing the interface for different rangers
 *  \date      20.05.2018
    Class holding all common member variables and implementing all common functions allowing to fuse different ranger
    measurements without knowing the specific ranger type
    Pure virtual method specific to each ranger have to be implemented when inheriting from this parent class.
*/
class Ranger
{
protected:
    /**
    * String specifying the model of the ranger
    */
    const std::string model_;
    /**
    * Enum specifying the type of the ranger
    */
    const eRangerType type_;

    /**
    * Baud number the ranger is set to
    */
    int baud_;

    /**
    * Port at which the ranger is connected
    */
    int port_;
    /**
    * field of view of the ranger in degrees
    */
    double field_of_view_;
    /**
    * Maximal sensing range of the ranger in meter
    */
    double max_distance_;
    /**
    * Minimal sensing range of the ranger in meter
    */
    double min_distance_;
    /**
    * Data rate at which the ranger produces a measurement
    */
    double data_rate_;


public:
    //!Default constructor of the ranger
    /*! Default constructor set model and ranger type to unknown
    */
    Ranger();
    //!Constructor of the ranger
    /*! \param model String containing the model of the new ranger passed to the parent class as in the initialization list
    */
    Ranger(std::string model, eRangerType type);     //Constructor with constant variable
    //!Default destructor of the ranger
    virtual ~Ranger();

    //! Returns the model of the ranger.
    /*!
      \return The model
    */
    virtual std::string getModel();

    //! Returns the baud number of the ranger.
    /*!
      \return The baud number
    */
    virtual int getBaud();

    //! Returns the selected port of the ranger.
    /*!
      \return The port
    */
    virtual int getPort();

    //! Returns the type of the ranger.
    /*!
      \return The type
    */
    virtual eRangerType getType();

    //! Returns the field of view of the ranger.
    /*!
      \return The field of view
    */
    virtual double getFieldOfView();

    //! Returns the maximal sensing distance of the ranger.
    /*!
      \return The maximal distance
    */
    virtual double getMaxDistance();

    //! Returns the minimal sensing distance of the ranger.
    /*!
      \return The minimal distance
    */
    virtual double getMinDistance();

    //! Returns the data rate of the ranger.
    /*!
      \return The data rate
    */
    virtual double getDataRate();

    //! Returns the valid ports of the ranger.
    /*!
      \return The valid ports
    */
    virtual std::string getValidPort() = 0;

    //! Returns the valid baud numbers of the ranger.
    /*!
      \return The valid baud numbers
    */
    virtual std::string getValidBaud() = 0;

    //Setter
    //! Sets the baud number of the ranger
    /*!
      \param baud The desired baud number
      \return Indicator whether the baud number was accepted
    */
    virtual bool setBaud(int baud) = 0;

    //! Sets the port of the ranger
    /*!
      \param port The desired port
      \return Indicator whether the port number was accepted
    */
    virtual bool setPort(int port) = 0;


    //! Function to start the ranger as a thread
    /*!
      \param buffer The buffer into which the ranger stores its generated data
    */
    virtual void run(RangerBuffer& buffer) = 0;
};

#endif // RANGER_H

