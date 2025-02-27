#include "Application.h"
#include "Point.h"

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget *sender, float mx,float my) {
  if (canvas){
    canvas->addPoint(mx, my, r, g, b, pointSize);
    canvas->invalidate();
  }
}

void Application::onCanvasDrag(bobcat::Widget *sender, float mx, float my) {
    if (canvas){
    canvas->addPoint(mx, my, r, g, b, pointSize);
    canvas->invalidate();
    }

}

void Application::onToolsClick(bobcat::Widget *sender) {
  if (sender == redButton) {
    r = 1.0f;
    g = 0.0f;
    b = 0.0f;
  } else if (sender == greenButton) {
    r = 0.0f;
    g = 1.0f;
    b = 0.0f;
  } else if (sender == blueButton) {
    r = 0.0f;
    g = 0.0f;
    b = 1.0f;

  } else if (sender == sizeIncreaseButton) {
    if (pointSize < 20)
      pointSize++;
  } else if (sender == sizeDecreaseButton) {
    if (pointSize > 1)
      pointSize--;
  }
}

Application::Application() {
  window = new Window(100, 100, 300, 250, "Simple Paint Application");

  redButton = new Button(0, 0, 50, 50, "Red");
  greenButton = new Button(0, 50, 50, 50, "Green");
  blueButton = new Button(0, 100, 50, 50, "Blue");
  sizeIncreaseButton = new Button(0, 150, 50, 50, "Increase Size");
  sizeDecreaseButton = new Button(0, 200, 50, 50, "Decrease Size");

  // initialize button components

  canvas = new Canvas(50, 0, 250, 250);
  pointSize = 7;
  r = 1;
  g = 0;
  b = 0;

  redButton->onClick([this](Widget *sender) { this->onToolsClick(sender); });
  greenButton->onClick([this](Widget *sender) { this->onToolsClick(sender); });
  blueButton->onClick([this](Widget *sender) { this->onToolsClick(sender); });
  sizeDecreaseButton->onClick([this](Widget *sender) { this->onToolsClick(sender); });
  sizeIncreaseButton->onClick([this](Widget *sender) { this->onToolsClick(sender); });

    canvas->onMouseDown([this](Widget* sender, float mx, float my){
        this->onCanvasMouseDown(sender, mx, my);
    });
    
    canvas->onDrag([this](Widget* sender, float mx, float my){
        this->onCanvasDrag(sender, mx, my);
    });



  window->show();
}
