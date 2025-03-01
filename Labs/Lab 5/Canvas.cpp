#include "Canvas.h"
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
  //
}

void Canvas::addPoint(float x, float y, float r, float g, float b, float size) {
  points.push_back(new Point(x, y, r, g, b, size));
}

void Canvas::render() {
  for (unsigned int i = 0; i < points.size(); i++) {
    points[i]->draw();
  }
}

void Canvas::undo() {
        if (!points.empty()){
            delete points.back();
            points.pop_back();
        }
}

void Canvas::clear() {
  while (!points.empty()) {
    delete points.back();
    points.pop_back();
  }
}

int Canvas::getPointsCount() const { return points.size(); }