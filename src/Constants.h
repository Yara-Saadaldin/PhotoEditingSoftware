#pragma once
#include "ofMain.h" 


namespace Constants {
	//Sets the height and width of the window
		static const int WINDOW_WIDTH       = 1366;
		static const int WINDOW_HEIGHT      = 768;

	//Sets the framerate
		static const int DESIRED_FRAMERATE  = 60;

	//The image that will be displayed
		static const std::string IMG_PATH = "Koala.jpg";

	//The 7x7 matrix filters
		//Matrix types
			enum CONVOLUTION_MAT_TYPE {
				EDGEDETECTION = 0,    //Edge detection
				GAUSSIANBLUR = 1    //Gaussian blur
			};
		//The different matrices for each type 
			static const float CONVOLUTION_MATS_7X7[] = {
				//Edge detection matrix
					 -9/140.0,     -9/140.0,    -18/140.0,   0.0,   18/140.0,    9/140.0,     9/140.0,
					 -9/140.0,    -18/140.0,    -18/140.0,   0.0,   18/140.0,   18/140.0,     9/140.0,
					-18/140.0,    -18/140.0,    -36/140.0,   0.0,   36/140.0,   18/140.0,    18/140.0,
					-18/140.0,    -36/140.0,    -72/140.0,   0.0,   72/140.0,   36/140.0,    18/140.0,
					-18/140.0,    -18/140.0,    -36/140.0,   0.0,   36/140.0,   18/140.0,    18/140.0,
					 -9/140.0,    -18/140.0,    -18/140.0,   0.0,   18/140.0,   18/140.0,     9/140.0,
					 -9/140.0,     -9/140.0,    -18/140.0,   0.0,   18/140.0,    9/140.0,     9/140.0,

				//Gaussian blur matrix
					1/140.0,   1/140.0,   2/140.0,    2/140.0,   2/140.0,   1/140.0,   1/140.0,
					1/140.0,   2/140.0,   2/140.0,    4/140.0,   2/140.0,   2/140.0,   1/140.0,
					2/140.0,   2/140.0,   4/140.0,    8/140.0,   4/140.0,   2/140.0,   2/140.0,
					2/140.0,   4/140.0,   8/140.0,   16/140.0,   8/140.0,   4/140.0,   2/140.0,
					2/140.0,   2/140.0,   4/140.0,    8/140.0,   4/140.0,   2/140.0,   2/140.0,
					1/140.0,   2/140.0,   2/140.0,    4/140.0,   2/140.0,   2/140.0,   1/140.0,
					1/140.0,   1/140.0,   2/140.0,    2/140.0,   2/140.0,   1/140.0,   1/140.0,
			};
		//Converts between 1D array and 2D array coordinates
				//X co-ordinates
					static const float CONVOLUTION_KERNAL_CONVERT_X[] = { -1,    -1,    -1,     0,     1,     1,     1,
																		  -1,    -1,    -1,     0,     1,     1,     1,
																		  -1,    -1,    -1,     0,     1,     1,     1,
																		  -1,    -1,    -1,     0,     1,     1,     1,
																		  -1,    -1,    -1,     0,     1,     1,     1,
																		  -1,    -1,    -1,     0,     1,     1,     1,
																		  -1,    -1,    -1,     0,     1,     1,     1 
					};
				//Y co-ordinates
					static const float CONVOLUTION_KERNAL_CONVERT_Y[] = { -1,    -1,    -1,    -1,    -1,    -1,    -1,
																		  -1,    -1,    -1,    -1,    -1,    -1,    -1,
																		  -1,    -1,    -1,    -1,    -1,    -1,    -1,
																		   0,     0,     0,     0,     0,     0,     0,
																		   1,     1,     1,     1,     1,     1,     1,
																		   1,     1,     1,     1,     1,     1,     1,
																		   1,     1,     1,     1,     1,     1,     1 
					};

	//The 5x5 matrix filters
		//Matrix types
			enum CONVOLUTION_MAT_TYPE2 {
				SHARPEN = 0    //Sharpen
			};
		//The different matrices for each type
			static const float CONVOLUTION_MATS_5X5[] = {
				//Sharpen matrix
					 0.0f,    0.0f,   0.0f,    0.0f,   0.0f,
					 0.0f,    0.0f,  -1.0f,    0.0f,   0.0f,
					 0.0f,   -1.0f,   5.0f,   -1.0f,   0.0f,
					 0.0f,    0.0f,  -1.0f,    0.0f,   0.0f,
					 0.0f,    0.0f,   0.0f,    0.0f,   0.0f,
			};
		//Converts between 1D array and 2D array coordinates
			//X co-ordinates
				static const float CONVOLUTION_KERNAL_CONVERT_x[] = { -1,    -1,     0,     1,     1,
																	  -1,    -1,     0,     1,     1,
																	  -1,    -1,     0,     1,     1,
																	  -1,    -1,     0,     1,     1,
																	  -1,    -1,     0,     1,     1 
				};
			//Y co-ordinates										      
				static const float CONVOLUTION_KERNAL_CONVERT_y[] = { -1,    -1,    -1,    -1,    -1,
																	  -1,    -1,    -1,    -1,    -1,
																	   0,     0,     0,     0,     0,
																	   1,     1,     1,     1,     1,
																	   1,     1,     1,     1,     1 
				};													      
};