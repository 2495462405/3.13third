//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
using namespace std;

string window_name = "binaryMat";

void threshod_Mat(int th, void*data)
{
    
    Mat src = *(Mat*)(data);
    
    Mat dst;
    threshold(src, dst, th, 255, 0);
    
    imshow(window_name, dst);
}
int main(int argc, const char * argv[]) {
    
    
    Mat srcMat;
    Mat gryMat;
    int lowTh = 30;
    int maxTh = 255;
    srcMat = imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.3.13/Trackbar/RGB.JPG");
    if(!srcMat.data)
    {
        cout<<"图像载入失败！"<<endl;
        return 0;
    }
    cvtColor(srcMat,gryMat, COLOR_BGR2GRAY);
    imshow(window_name, gryMat);
    createTrackbar("threshold",window_name,&lowTh,maxTh,threshod_Mat,&gryMat);
        waitKey(0);
        return 0;
    }
