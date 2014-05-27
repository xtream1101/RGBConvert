/*
 * RGBConvert.h - Arduino library for converting between RGB and HSV
 * 
 * hsvTorgb function was ported from the javascript at http://axonflux.com/handy-rgb-to-hsl-and-rgb-to-hsv-color-model-c
 * rgbTohsv function was ported from the javascript at http://stackoverflow.com/a/8023734
 *
 * Eddy Hintze, May 2014
 *
 * https://github.com/xtream1101/RGBConvert
 *
 */


#ifndef RGBConvert_h
#define RGBConvert_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class RGBConvert{

  public:
    void rgbTohsv(float r, float g, float b, int *hsv);
    void hsvTorgb(float h, float c, float l, int *rgb);

  private:

};



#endif

