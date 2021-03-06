#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill_12.cpp `fltk-config --ldflags --use-images` -o a2.out
*/

int main(){

	try{
	
	using namespace Graph_lib;
	
	Point t1 {100, 100};
	Simple_window win {t1, 600, 400, "My window"};
	win.wait_for_button();
	
	Axis xa {Axis::x, Point{20, 200}, 560, 20, "x axis"};
	win.attach(xa);
	
	win.set_label("X axis");
	win.wait_for_button();
	
	Axis ya {Axis::y, Point{280, 300}, 280, 10, "y axis"};
	ya.set_color(Color::green);
	ya.label.set_color(Color::white);
	win.attach(ya);
	
	win.set_label("Y axis");
	win.wait_for_button();
	
	Function sine {sin, 0, 100, Point{40, 180}, 700, 60, 60};
	win.attach(sine);
	sine.set_color(Color::dark_red);
	win.set_label("Sine function");
	win.wait_for_button();
	
	Polygon poly;
	poly.add(Point{300, 200});
	poly.add(Point{350, 100});
	poly.add(Point{450, 100});
	poly.add(Point{400, 200});
	
	poly.set_color(Color::yellow);
	poly.set_style(Line_style::dot);
	win.attach(poly);
	
	win.set_label("Polygon");
	win.wait_for_button();	
	
	Rectangle r {Point{210, 210}, 100, 150};
	win.attach(r);
	win.wait_for_button();
	
	Closed_polyline poly_rect;
	
	poly_rect.add(Point{72,38});
	poly_rect.add(Point{172,38});
	poly_rect.add(Point{172,90});
	poly_rect.add(Point{72,90});
	poly_rect.add(Point{38,71});
	win.attach(poly_rect);
	
	win.set_label("Rectangle");
	win.wait_for_button();
	
	r.set_fill_color(Color::red);
	poly.set_fill_color(Color::blue);
	poly.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::cyan);
	poly.set_style(Line_style::dashdot);
	poly_rect.set_style(Line_style::dashdot);
	
	win.set_label("Fill");
	win.wait_for_button();
	
	Text t {Point{150, 150}, "Hello, graphical world!"};
	t.set_font_size(20);
	win.attach(t);
	win.set_label("Text");
	win.wait_for_button();
	
	
	Image ii {Point{300,150},"amg_gt.jpeg"};
	win.attach(ii);
	win.set_label("amg_gt");
	win.wait_for_button();
	
	ii.move(100,200);
	win.set_label("amg_gt move");
	win.wait_for_button();
	
	Circle c(Point{150,250},80);
	Ellipse e (Point{150,250},40,80);
	c.set_color(Color::yellow);
	Mark m {Point{150,250},'x'};
	win.attach(c);
	win.attach(e);
	win.attach(m);
	win.set_label("Eye");
	c.set_fill_color(Color::red);
	e.set_fill_color(Color::cyan);
	win.wait_for_button();
	
	Image gg (Point(0,0), "ize.gif");
	gg.set_mask(Point{250,300},200,150);
	win.attach(gg);
	win.set_label("ize gif");
	win.wait_for_button();
	
	
	} catch (exception& e) {
		cerr << "exception: " << e.what() << '\n';
		return 1;
	} catch (...) {
		cerr << "error\n";
		return 2;
	}

}
	
	
	
	
	


