#include <iostream>
#include "sober.h"

#include <dlib/algs.h>
#include <opencv2/opencv.hpp>
using namespace std;


int main() {
    Sober sober;
    std::cout << "2 + 2 = " << sober.add(2, 2) << std::endl;
    cout << "OpenCV version is " << CV_VERSION << endl;

    return 0;
    
}