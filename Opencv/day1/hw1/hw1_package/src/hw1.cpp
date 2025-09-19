#include"../include/hw1/hw1.hpp"


int main(){

    obj row;
    row.show("row");
    row.buler(51);
    row.show("bluer");

    obj ir;
    ir.hsv();
    ir.range(150,50,50,180,255,255,0,50,50,10,255,255);
    ir.show("inrageR");

    obj ig;
    ig.hsv();
    ig.range(30,100,150,70,255,255);
    ig.show("inrageG");

    obj ib;
    ib.hsv();
    ib.range(95,230,150,125,255,255);
    ib.show("inrageB");

    obj ibr;
    ibr.hsv();
    ibr.buler(51);
    ibr.range(150,50,50,180,255,255,0,50,50,10,255,255);
    ibr.show("inragebR");

    obj ibg;
    ibg.hsv();
    ibg.buler(51);
    ibg.range(30,100,150,70,255,255);
    ibg.show("inragebG");

    obj ibb;
    ibb.hsv();
    ibb.buler(51);
    ibb.range(95,230,150,125,255,255);
    ibb.show("inragebB");

    waitKey(0);
}
