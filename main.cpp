/*
The assignment requires the rasterization of the arcs of two circles. 
The first circle is defined as x2 +y2 = R2 where x 􏰁 0 and R = 100. 
The second circle is defined as x2 + y2 = R2 where y 􏰁 0 and R = 150. 
The radius is 200, and the dimension of the image will be radius × radius (200 × 200).

*/


#include <iostream>
#include "BMP.h"
#include <cmath>

int main() {

    BMP bmpNew(2001,2000,false);
    bmpNew.fill_region(0, 0, 2001, 2000, 0, 0, 0, 0); 

    //draw white line
    for(int i=0;i<bmpNew.bmp_info_header.width;i++){

        bmpNew.set_pixel(i, 0, 255, 255, 255, 0);
    }


    for(int x=0;x<bmpNew.bmp_info_header.width;x++)
    {
      if((x >= 232) && (x <= 1768)){
        int x2 = x - 1000;
        int y = (int) (sqrt(589824-(x2 * x2))/2);
        bmpNew.set_pixel(x2, y, 255, 255, 255, 0);
      }

    }
    bmpNew.write("output.bmp");


}