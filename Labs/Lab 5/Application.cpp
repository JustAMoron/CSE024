#include "Application.h"
#include <string>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    canvas->addPoint(mx, my, r, g, b, pointSize);
    canvas->redraw();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    canvas->addPoint(mx, my, r, g, b, pointSize);
    canvas->redraw();
}

void Application::onToolsClick(bobcat::Widget* sender) {
    if (sender == redButton) {
        r = 1.0;
        g = 0.0;
        b = 0.0;
    }
    else if (sender == greenButton) {
        r = 0.0;
        g = 1.0;
        b = 0.0;
    }
    else if (sender == blueButton) {
        r = 0.0;
        g = 0.0;
        b = 1.0;
    }
    else if (sender == sizeIncreaseButton) {
        pointSize++;
    }
    else if (sender == sizeDecreaseButton) {
        if (pointSize > 1) {
            pointSize--;
        } 
    } else if (sender == undoButton) {
            canvas->undo();
            pointsCountTextbox->label("Count: " + to_string(canvas->getPointsCount()));


        } else if (sender == clearButton){
            canvas->clear();
            pointsCountTextbox->label("Count: " + to_string(canvas->getPointsCount()));
        }

    colorTextbox->label("Color: " + string(r==1.00f ? "Red" : g == 1.0f ? "Green" : "Blue"));
    pointSizeTextbox->label("Size: " + to_string(pointSize));
    pointsCountTextbox->label("Count: " + to_string(canvas->getPointsCount()));
}

Application::Application() {
    window = new Window(100, 100, 400, 400, "Simple Paint Application V2");
    
    redButton = new Button(0, 0, 50, 50, "Red");
    greenButton = new Button(0, 50, 50, 50, "Green");
    blueButton = new Button(0, 100, 50, 50, "Blue");
    sizeIncreaseButton = new Button(0, 150, 50, 50, "Size +");
    sizeDecreaseButton = new Button(0, 200, 50, 50, "Size -");
    undoButton = new Button(0, 250, 50, 50, "Undo");
    clearButton = new Button(0, 300, 50, 50, "Clear");

    canvas = new Canvas(50, 0, 350, 350);

    r = 1.0;
    g = 0.0;
    b = 0.0;
    pointSize = 7;
    color = "Red";

    colorTextbox = new TextBox(50, 350, 100, 50, "Color: Red");
    pointSizeTextbox = new TextBox(175, 350, 100, 50, "Size: 7");
    pointsCountTextbox = new TextBox(300, 350, 100, 50, "Count: 0");

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);

    ON_CLICK(redButton, Application::onToolsClick);
    ON_CLICK(greenButton, Application::onToolsClick);
    ON_CLICK(blueButton, Application::onToolsClick);
    ON_CLICK(sizeIncreaseButton, Application::onToolsClick);
    ON_CLICK(sizeDecreaseButton, Application::onToolsClick);
    ON_CLICK(undoButton, Application::onToolsClick);
    ON_CLICK(clearButton, Application::onToolsClick);

    window->show();
}