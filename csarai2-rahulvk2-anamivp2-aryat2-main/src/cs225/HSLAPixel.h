/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 */

#pragma once

namespace cs225 {
    class HSLAPixel {
        public: 
            double h;   // the hue of the pixel in degrees [0, 360)
            double s;   // the saturation of the pixel [0, 1]
            double l;   // the luminance of the pixel [0, 1]
            double a;   // the alpha channel of the pixel, or how transparent the pixel is [0, 1]


            /**
            * Default Constructor for a HSLA Pixel
            * A default pixel is completely opaque (non-transparent) and white. Thus, the alpha component 
            * of the pixel is 1.0 since lower alpha levels are semi-transparent.
            */
            HSLAPixel();

            /**
            * Constructor for an opaque HSLA Pixel with the given hue, saturation, and luminance values.
            * @param hue the hue value for the new pixel in degrees [0, 360)
            * @param saturation the saturation value for the new pixel [0, 1]
            * @param luminance the luminance value for the new pixel [0, 1]
            */
            HSLAPixel(double hue, double saturation, double luminance);

            /**
            * Constructor for an HSLAPixel with the given hue, saturation, luminance, and alpha values.
            * @param hue the hue value for the new pixel in degrees [0, 360)
            * @param saturation the saturation value fro the new pixel [0, 1]
            * @param luminance the luminance value for the new pixel [0, 1]
            * @param alpha the alpha level for the new pixel [0, 1]
            */
            HSLAPixel(double hue, double saturation, double luminance, double alpha);

        private:


    };
}
