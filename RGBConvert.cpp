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



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "RGBConvert.h"


void RGBConvert::hsvTorgb(float h, float s, float v, int *rgb){
    float r, g, b, f, p, q, t;
    int i;

    h = h/360.0;
    s = s/100.0;
    v = v/100.0;
    i = floor(h * 6);
    f = h * 6 - i;
    p = v * (1 - s);
    q = v * (1 - f * s);
    t = v * (1 - (1 - f) * s);
    switch (i % 6) {
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }
    rgb[0] = floor(r * 255);
    rgb[1] = floor(g * 255);
    rgb[2] = floor(b * 255);
} //END RGBConvert::hsvTorgb()


void RGBConvert::rgbTohsv(float r, float g, float b, int *hsv){
    float rr, gg, bb, h, s;
    r = r/255.0;
    g = g/255.0;
    b = b/255.0;
    float v = max(max(r, g), b);
    float diff = v - min(min(r, g),b);

    if (diff == 0) {
        h = s = 0;
    } else {
        s = diff / v;
        rr = (v - r) / 6.0 / diff + 1.0 / 2.0;
        gg = (v - g) / 6.0 / diff + 1.0 / 2.0;
        bb = (v - b) / 6.0 / diff + 1.0 / 2.0;

        if (r == v)
            h = bb - gg;
        else if (g == v)
            h = (1.0 / 3.0) + rr - bb;
        else if (b == v)
            h = (2.0 / 3.0) + gg - rr;
        
        if (h < 0) 
            h += 1;
        else if (h > 1)
            h -= 1;

        hsv[0] = round(h*360);
        hsv[1] = round(s*100);
        hsv[2] = round(v*100);
    }
} //END RGBConvert::rgbTohsv()

