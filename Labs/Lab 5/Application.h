#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include "Canvas.h"

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    bobcat::Button* redButton;
    bobcat::Button* greenButton;
    bobcat::Button* blueButton;
    bobcat::Button* sizeIncreaseButton;
    bobcat::Button* sizeDecreaseButton;
    bobcat::Button* undoButton;
    bobcat::Button* clearButton;
    bobcat::TextBox* colorTextbox;
    bobcat::TextBox* pointSizeTextbox;
    bobcat::TextBox* pointsCountTextbox;

    Canvas* canvas;

    float r;
    float g;
    float b;
    int pointSize;
    std::string color;
    
    void onCanvasMouseDown(bobcat::Widget* sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget* sender, float mx, float my);
    void onToolsClick(bobcat::Widget* sender);
    void undo(bobcat::Widget* sender);
    void clear(bobcat::Widget* sender);

public:
    Application();

    friend struct::AppTest;
};


#endif