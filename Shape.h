#pragma once

#include <vector>
#include "SDL.h"

class Shape
{

public:
	static void SetRender(SDL_Renderer* ren);
	static void DrawAll();

	static int GetCount();

	Shape(int x, int y);
	~Shape();
	
	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	virtual void draw() const = 0;
	virtual void remove() = 0;
	virtual void move(int x, int y) = 0;
	virtual void rotate() = 0;


protected:
	static int current_id;
	static SDL_Renderer* render;
	static std::vector<Shape*> shapes;

	int id;
	int coords[2];

	int GetID();
};


class Point : public Shape {
public:
	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	void draw() const override;
	void remove() override;
	void move(int x, int y) override;
	void rotate() override;
};


class Line : public Shape {
public:
	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	void draw() const override;
	void remove() override;
	void move(int x, int y) override;
	void rotate() override;
};


class Rect : public Shape {
public:
	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	void draw() const override;
	void remove() override;
	void move(int x, int y) override;
	void rotate() override;
};


class Circle : public Shape {
public:
	int radius;

	Circle(int x, int y, int radius);

	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	void draw() const override;
	void remove() override;
	void move(int x, int y) override;
	void rotate() override;
};


class Rhombus : public Shape {
public:
	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	void draw() const override;
	void remove() override;
	void move(int x, int y) override;
	void rotate() override;
};


class Parallelogram : public Shape {
public:
	void SetCoords(int x, int y);
	void SetCoords(int* arr);
	int* GetCoords();

	void draw() const override;
	void remove() override;
	void move(int x, int y) override;
	void rotate() override;
};

