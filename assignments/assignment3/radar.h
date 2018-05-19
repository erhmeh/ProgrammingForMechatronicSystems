/**
 * radar.h
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */

#ifndef RADAR_H
#define RADAR_H

#include "ranger.h"

class Radar : public Ranger
{
public:
	Radar();
	bool setFov(double i);
};

#endif /** RADAR_H */
