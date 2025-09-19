#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
    VideoCapture cap(0);
    // cap.set(cv::CAP_PROP_FRAME_HEIGHT,360);
    // cap.set(cv::CAP_PROP_FRAME_WIDTH,);

    
    Mat frame;
    while (1)
    {
        cap.read(frame);
        resize(frame,frame,Size(640,360));
        imshow("cam",frame);
        if(waitKey(1)=='q'){
            break;
        }
    }    
}