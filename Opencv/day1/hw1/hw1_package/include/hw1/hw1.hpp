#include <opencv2/highgui.hpp> 
#include <string>
#include <opencv2/opencv.hpp> 

using namespace cv;
using namespace std;

class obj {
    private: Mat i,i1;

    public:
    obj(){
        i= imread("/home/david/intern_ws/opencv/day1/src/hw1/src/Lenna.png",IMREAD_COLOR);
        i1= imread("/home/david/intern_ws/opencv/day1/src/hw1/src/Lenna.png",IMREAD_COLOR);

        }
    void hsv(){
        cvtColor(i, i, COLOR_BGR2HSV);
        cvtColor(i1, i1, COLOR_BGR2HSV);
    }
    void buler(int a){

            if(a%2==1){
            GaussianBlur(i,i,Size(a,a),0);
            GaussianBlur(i1,i1,Size(a,a),0);
            }
            else{
                cout<<"홀수 or 양수"<<endl;
            }
        
    }
    void range(int mh, int ms, int mv,int hh, int hs, int hv,int mh1=0, int ms1=0, int mv1=0,int hh1=0, int hs1=0, int hv1=0){
        inRange(i,Scalar(mh,ms,mv),Scalar(hh,hs,hv),i);
        inRange(i1,Scalar(mh1,ms1,mv1),Scalar(hh1,hs1,hv1),i1);
        i+=i1;
    }
    void show(const char name [200] ){
        imshow(name,i);
        
    }
};