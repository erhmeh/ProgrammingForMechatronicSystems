#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include "dummy.h"
#include <random>

using namespace std;

dummy obj("one");
queue<int> nums;
int sum1;
int sum2;
mutex nums_mtx;

void fillnums(queue<int> & nums){
    for(int i = 0; i <= 1000000; i+=2){
        nums.push(i);
        nums.push(-i);
    }
}

void pushpopper(queue<int> & nums, int & sum, mutex & mtx){
    while (nums.size() != 0){
    mtx.lock();
    if(nums.size() != 0){
        sum += nums.front();
            nums.pop();
        }
    mtx.unlock();
    }
}

void fillRand(vector<double> & foo){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,100);
    while (true){
    nums_mtx.lock();
    foo.push_back(dis(gen));
    nums_mtx.unlock();
    }
}

void constrainVec(vector<double> & foo){
    while (true){
        nums_mtx.lock();
        if(foo.size() > 20){
            foo.resize(20);
            foo.shrink_to_fit();
        }
        nums_mtx.unlock();
    }
}

void limitVec(vector<double> & foo){
    while(true){
        nums_mtx.lock();

        for (int i = 0; i != foo.size(); i++){
            if (foo[i] > 80 || foo[i] < 20){
                foo.erase(foo.begin() + i);
                i--;
            }
        }

        nums_mtx.unlock();

    }
}

void task1(){
    fillnums(nums);
    std::thread th1(pushpopper, std::ref(nums), std::ref(sum1), std::ref(nums_mtx));
    std::thread th2(pushpopper, std::ref(nums), std::ref(sum2), std::ref(nums_mtx));
    th1.join();
    th2.join();
    int total = (sum1 + sum2);
    cout << "Sum 1 : " << sum1 << endl;
    cout << "Sum 2 : " << sum2 << endl;
    cout << "Total : " << total << endl;
}

void task2(){
    thread th1(fillRand, ref(obj.foo));
    thread th2(constrainVec, ref(obj.foo));
    thread th3(limitVec, ref(obj.foo));
    th1.join();
    th2.join();
    th3.join();
    while(true){
        for (int i = 0; i != 1000; i++){

        }
        nums_mtx.lock();
        for (int i = 0; i != obj.foo.size(); i++){
            cout << obj.foo[i] << endl;
        }
        nums_mtx.unlock();
    }
}

int main ()
{
    task2();
    return 0;
}
