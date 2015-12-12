/**
	KGAT-15 LD1
	main.cpp
	Purpose: draw author's initials (character symbols have to be filled with gradient).

	@author: Robertas Kvietkauskas
	@version: 0.2.0

 */

#include <iostream>
#include "BMP24.h"

#define RESULT_IMAGE_HEIGHT 600
#define RESULT_IMAGE_WIDTH 600
#define RESULT_FILENAME "result.bmp"
#define BORDER_WIDTH 50

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

int main() {
	std::cout << "Programa darbą pradėjo.\n";

	BMP24 resultImage = BMP24(RESULT_IMAGE_WIDTH,RESULT_IMAGE_HEIGHT);

	fillBitmapWithGradient(resultImage, RESULT_IMAGE_HEIGHT, RESULT_IMAGE_HEIGHT);

	resultImage.rasykIByla(RESULT_FILENAME);

	std::cout << "Programa darbą baigė.\n";
}