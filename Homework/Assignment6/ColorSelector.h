#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include <bobcat_ui/bobcat_ui.h>
#include "Color.h"
#include "Enums.h"


class ColorSelector : public bobcat::Group{
private:


public:

    bobcat::Button* redButton;
    bobcat::Button* orangeButton;
    bobcat::Button* yellowButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* indigoButton;
    bobcat::Button* violetButton;

    Color selectedColor;

    void ColorSelect(bobcat::Widget* sender);
    Color normalizeColor(int r,int g, int b);

    ColorSelector(int x, int y ,int width , int height);
    Color getColor() const;



};

#endif