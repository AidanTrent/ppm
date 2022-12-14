/* Aidan Trent
 * Creates an example ppm image
 */
#include "ppm.h"
#include <stdio.h>

int main(void){
	int width = 100;
	int height = 100;

	PPMHeader header = {"P6", width, height, 255};
	PPMImg* img = makeImage(&header);
	RGB color = {0,0,0};

	float blueIntermediate = 0;
	float redIntermediate = 0;
	float widthInc = (255. / width);
	float heightInc = (255. / height);

	for (int y = 0; y < height; y++){
		blueIntermediate += heightInc;
		color.blue = blueIntermediate;
		redIntermediate = 0;
		for (int x = 0; x < width; x++){
			redIntermediate += widthInc;
			color.red = redIntermediate;
			setPixel(img, color, x, y);
		}
	}

	saveImage("testImage.ppm", img);
	PPMImg* img2 = loadImage("testImage.ppm");
	if (img2 != NULL){
		saveImage("testImage2.ppm", img2);
	}
}
