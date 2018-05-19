/**
 * data_fusion.h
 * Programming for Mechatronic systems
 * Assignment 3
 *
 * @author: Jamin Early 99133391
 * @date: Week 8 Autumn Semester 2018
 */

 #ifndef DATA_FUSION_H
 #define DATA_FUSION_H

 #include <queue>
 #include <chrono>
 #include <mutex>
 #include <condition_variable>
 #include <thread>
 #include "ranger.h"

using namespace std;

class DataFusion {
public:
DataFusion();
void startFusion(queue<double> &stream1, queue<double> &stream2, mutex &mu, condition_variable &cond, int fuseMethod);
protected:
double lastReading1_;
double lastReading2_;
double fusedData_;
std::chrono::duration<double> lastFuseTime_;
int fuseRate_;
};

#endif /** ifndef DATA_FUSION_H */
