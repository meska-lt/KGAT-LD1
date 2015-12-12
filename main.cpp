/**
	KGAT-15 LD1
	main.cpp
	Purpose: draw author's initials (character symbols have to be filled with gradient).

	@author: Robertas Kvietkauskas
	@version: 0.2.0

 */

#include <iostream>
#include "BMP24.h"

#define RESULT_IMAGE_WIDTH 800
#define RESULT_IMAGE_HEIGHT 800
#define RESULT_FILENAME "result.bmp"
#define BORDER_WIDTH 50

struct Point{
	int x;
	int y;
};

bool pointInsideTriangle(Point s, Point a, Point b, Point c) {
	int as_x = s.x - a.x;
	int as_y = s.y - a.y;
	bool s_ab = (((b.x - a.x) * as_y) - ((b.y - a.y) * as_x)) > 0;
	bool result = false;

	if (((c.x - a.x) * as_y) - ((c.y - a.y) * as_x) > 0 == s_ab)
		result = true;

	if (((c.x - b.x) * (s.y - b.y)) - ((c.y-b.y) * (s.x-b.x)) > 0 != s_ab)
		result = true;

	return result;
}

void drawTriangleInBitmap(BMP24 &pav, int c1x, int c1y, int c2x, int c2y, int c3x, int c3y) {
	std::cout << "void drawTriangleInBitmap(BMP24, int, int, int, int, int, int);\n";

	for (int x = 0; x < RESULT_IMAGE_WIDTH; x++) {
		for (int y = 0; y < RESULT_IMAGE_HEIGHT; y++) {
			Point p = {x, y};
			Point p1 = {c1x, c1y};
			Point p2 = {c2x, c2y};
			Point p3 = {c3x, c3y};

			if(!pointInsideTriangle(p, p1, p2, p3))
				pav.dekTaska( x, y, 255, 255, 255);
		}
	}
}

void fillBitmapWithGradient(BMP24 &bitmap, int bitmapWidth, int bitmapHeight) {
	std::cout << "void fillBitmapWithGradient(BMP24, int, int);\n";

	for (int x = 0; x < RESULT_IMAGE_WIDTH; x++) {
		for (int y = 0; y < RESULT_IMAGE_HEIGHT; y++) {
			char redValue = 255-255.0 * y / RESULT_IMAGE_HEIGHT;
			char greenValue = 255-255.0 * y / RESULT_IMAGE_WIDTH;
			char blueValue = 0 + (255.0 * y / RESULT_IMAGE_WIDTH);

			bitmap.dekTaska(x, y, redValue, greenValue, blueValue);
		}
	}
}

void drawBordersInBitmap(BMP24 &bitmap) {
	std::cout << "void drawBordersInBitmap(BMP24);\n";

	// Right
	drawTriangleInBitmap(bitmap, RESULT_IMAGE_WIDTH, 0, RESULT_IMAGE_WIDTH, RESULT_IMAGE_HEIGHT, RESULT_IMAGE_WIDTH - BORDER_WIDTH, RESULT_IMAGE_HEIGHT);
	drawTriangleInBitmap(bitmap, RESULT_IMAGE_WIDTH, 0, RESULT_IMAGE_WIDTH - BORDER_WIDTH, 0, RESULT_IMAGE_WIDTH - BORDER_WIDTH, RESULT_IMAGE_HEIGHT);

	// Bottom
	drawTriangleInBitmap(bitmap, 0, -1, RESULT_IMAGE_WIDTH, 0, RESULT_IMAGE_WIDTH, BORDER_WIDTH);
	drawTriangleInBitmap(bitmap, 0, -1, 0, BORDER_WIDTH, RESULT_IMAGE_WIDTH, BORDER_WIDTH);
	
	// Left
	drawTriangleInBitmap(bitmap, 0, 0, 0, RESULT_IMAGE_HEIGHT, BORDER_WIDTH, RESULT_IMAGE_HEIGHT);
	drawTriangleInBitmap(bitmap, BORDER_WIDTH, 0, 0, 0, BORDER_WIDTH, RESULT_IMAGE_HEIGHT);

	// Top
	drawTriangleInBitmap(bitmap, 0, RESULT_IMAGE_HEIGHT, RESULT_IMAGE_WIDTH, RESULT_IMAGE_HEIGHT, RESULT_IMAGE_WIDTH, RESULT_IMAGE_HEIGHT - BORDER_WIDTH);
	drawTriangleInBitmap(bitmap, 0, RESULT_IMAGE_HEIGHT, 0, RESULT_IMAGE_HEIGHT - BORDER_WIDTH, RESULT_IMAGE_WIDTH, RESULT_IMAGE_HEIGHT - BORDER_WIDTH);
}

int main() {
	std::cout << "Programa darbą pradėjo.\n";

	BMP24 resultImage = BMP24(RESULT_IMAGE_WIDTH,RESULT_IMAGE_HEIGHT);

	fillBitmapWithGradient(resultImage, RESULT_IMAGE_HEIGHT, RESULT_IMAGE_HEIGHT);
	drawBordersInBitmap(resultImage);

	resultImage.rasykIByla(RESULT_FILENAME);

	std::cout << "Programa darbą baigė.\n";
}