#include "ColorSelector.h"
using namespace bobcat;

Color ColorSelector::normalizeColor(int r, int g, int b){
    return Color(r/255.0f, g / 255.0f, b / 255.0f);
}

void ColorSelector::ColorSelect(bobcat::Widget* sender){
    if (sender == redButton){
        selectedColor = normalizeColor(255, 0, 0);
    } else if (sender == orangeButton){
        selectedColor = normalizeColor(255, 127, 0);
    }else if (sender == yellowButton){
            selectedColor = normalizeColor(255, 255, 0);
    }else if (sender == greenButton){
            selectedColor = normalizeColor(0, 255, 0);
    }else if (sender == blueButton){
            selectedColor = normalizeColor(0, 0, 255);
    }else if (sender == indigoButton){
            selectedColor = normalizeColor(75, 0, 130);
    }else if (sender == violetButton){
        selectedColor = normalizeColor(148, 0, 211);
    }
}


ColorSelector::ColorSelector(int x, int y, int width, int height) : Group(x,y,width,height), selectedColor(255,0,0) {
    int ButtonWidth = width / 7;
    int ButtonHeight = height;

    redButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "red");
    orangeButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "orange");
    yellowButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "yellow");
    greenButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "green");
    blueButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "blue");
    indigoButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "indigo");
    violetButton = new Button(0 * ButtonWidth,0, ButtonWidth, ButtonHeight, "violet");

    selectedColor = normalizeColor(255, 0, 0);

    this->add(redButton);
    this->add(orangeButton);
    this->add(yellowButton);
    this->add(greenButton);
    this->add(blueButton);
    this->add(indigoButton);
    this->add(violetButton);

    ON_CLICK(redButton, ColorSelector::ColorSelect);
     ON_CLICK(orangeButton, ColorSelector::ColorSelect);
      ON_CLICK(yellowButton, ColorSelector::ColorSelect);
       ON_CLICK(greenButton, ColorSelector::ColorSelect);
        ON_CLICK(indigoButton, ColorSelector::ColorSelect);
         ON_CLICK(violetButton, ColorSelector::ColorSelect);
            ON_CLICK(blueButton, ColorSelector::ColorSelect);



}

Color ColorSelector::getColor() const{
    return selectedColor;

}



