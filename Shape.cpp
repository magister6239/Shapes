#include <iostream>
#include <vector>
#include <SDL.h>
#include "Shape.h"
#include "SDL2_gfxPrimitives.h"


//Point





//Shape

SDL_Renderer* Shape::render = nullptr;
std::vector<Shape*> Shape::shapes;
int Shape::current_id = 0;


void Shape::SetRender(SDL_Renderer* ren)
{
	if (Shape::render != nullptr) {
		return;
	}

	Shape::render = ren;
}

void Shape::DrawAll()
{
	for (Shape* shape : Shape::shapes)
	{
		shape->draw();
	}
}

int Shape::GetCount()
{
	return Shape::shapes.size();
}

Shape::Shape(int x, int y)
{
	this->coords[0] = x;
	this->coords[1] = y;
	this->id = Shape::current_id++;
	Shape::shapes.push_back(this);
}

Shape::~Shape()
{
	0;
}

void Shape::SetCoords(int x, int y) 
{
	this->coords[0] = x;
	this->coords[1] = y;
}

void Shape::SetCoords(int* arr) 
{
	this->coords[0] = arr[0];
	this->coords[1] = arr[1];
}

int* Shape::GetCoords() 
{
	int* arr = new int[2];

	arr[0] = this->coords[0];
	arr[1] = this->coords[1];

	return arr;
}


// Circle
Circle::Circle(int x, int y, int radius) : Shape(x, y)
{
	this->radius = radius;
}

void Circle::draw() const
{
	circleRGBA(Shape::render, this->coords[0], this->coords[1], this->radius, 255, 0, 0, 255);
}

void Circle::remove()
{
	Shape::shapes.erase(std::remove(Shape::shapes.begin(), Shape::shapes.end(), this), Shape::shapes.end());
}

void Circle::move(int x, int y)
{
	this->coords[0] += x;
	this->coords[1] += y;
}

void Circle::rotate()
{
	0;
}
