#ifndef SHAPE_H
#define SHAPE_H

#include <string>

/*!
 *  \ingroup   ac_shapre Shape
 *  \brief     Shape base class
 *  \details
 *  This class is the base class for all shapes.\n
 *  \author    Alen Alempijevic
 *  \author    Alex Virgona
 *  \version   1.02-1
 *  \date      2016
 *  \pre       none
 *  \bug       none reported as of 2016-04-11
 *  \warning
 */
class Shape
{
public:
    Shape();

    // The below is one style of comenting picked up by doxygen, there are many ways to document code
    // this is not detected as it is simple commenting, so Doxygen is oblivious to the comments 

    //! Computes the area and returns value [m2].
    /*!
      \return The area
      \sa Shape() and getDescription()
    */
    double getArea (void);
    double getPerimeter(void);
    std::string getDescription();
protected:
    std::string description_;//!< description of shape
};

#endif // SHAPE_H
