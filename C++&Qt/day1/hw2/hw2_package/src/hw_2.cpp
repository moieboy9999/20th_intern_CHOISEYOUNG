#include "../include/cpp_test/hw_2.hpp"


double pross::sqrt (int a){
    double t=0;
    while (a>(t*t)){t++;}
    t--;
    while (a>(t*t)){t+=0.0001;}
    t-=0.0001;
    return t;
}


float pross::input(){
    char s[1000]={0};
    int i=0,sig=0,k=0;
    cin>>s;
    if(s[0]=='-'){sig=1;i=1;}
    if(s[0]==0){return 0.1;}
    while (1)
    {
        if(s[i]==0){
            int mult=1,a=0;
            while (k+sig<i){
                a+=(s[i-k-1]-'0')*mult;
                k++;
                mult*=10;
            }
            if(sig==1){a=-a;}
            return a;
        }
        else if('0'>s[i]||s[i]>'9'){return 0.1;}
        i++;
    }
}


int main(){

    srand((unsigned int)time(NULL));

    pross point;
    int i,mi,ma,sh,sh1,lo,lo1;
    float p=0.1,min=0.1,max=0.1;

    while(p<1||(p-int(p)!=0)){//입력들(개수, 최대, 최소) 
        cout<<"Please define the number of points(natural number): ";
        p=point.input();
    }
    i=p;
    while(min-(int)min!=0){
        cout<<"Please define minimum of coor. value(int): ";
        min=point.input();
    }   
    mi=min;
    while(max<min||(max-(int)max!=0)){
        cout<<"Please define maximum of coor. value(bigger int than min): ";
        max=point.input();
    }
    ma=max;

    cout<<endl<<endl<<"Generate Random point"<<endl;

    float mid,mad,len;
    cold *list=new cold[i];

    for(int k=0;i>k;k++){
        int d=0;
        while(d==0){//겹치면 다시 돌리고 더 이상 새로운 좌표 없으면 겹치기
            list[k].X=(rand()%(ma-mi+1))+mi;
            list[k].Y=(rand()%(ma-mi+1))+mi;
            if(k<(ma-mi+1)*(ma-mi+1)){
                for(int j=0;j<k;j++){
                    if((list[k].X==list[j].X)&&(list[k].Y==list[j].Y)){
                        d=0;
                        break;
                    }
                    else{d=1;}
                }
                if(k==0){d=1;}
            }
            else{d=1;}
        }
        cout<<"Point "<<k+1<<". nX="<<list[k].X<<" , nY="<<list[k].Y<<endl;
    }
    for(int k=0;i>k;k++){
        for(int j=1+k; i>j;j++){
            len=point.sqrt(((list[k].X-list[j].X)*(list[k].X-list[j].X))+((list[k].Y-list[j].Y)*(list[k].Y-list[j].Y)));
            if(j==1){mid=210000000;mad=0;}//최소에 매우 큰수, 최대에 작은 수
            if (len<0){len=0;}
            if(mad<len){mad=len;lo=k;lo1=j;}
            if(mid>len){mid=len;sh=k;sh1=j;}
        }
    }
//과제 나온대로 출력
    cout<<endl<<"--------Result--------"<<endl;
    cout<<"MinDist="<<mid<<endl;
    cout<<"Pair of Min Coor.<x,y>: P1<"<<list[sh].X<<","<<list[sh].Y<<"> & P2<"<<list[sh1].X<<","<<list[sh1].Y<<">"<<endl<<endl;
    cout<<"MinDist="<<mad<<endl;
    cout<<"Pair of Max Coor.<x,y>: P1<"<<list[lo].X<<","<<list[lo].Y<<"> & P2<"<<list[lo1].X<<","<<list[lo1].Y<<">"<<endl<<endl<<endl;
    cout<<"*********************Completed*********************"<<endl<<endl<<endl;
    cout<<"Press <RETURN> to close this window...";

        
}
delete []list;
