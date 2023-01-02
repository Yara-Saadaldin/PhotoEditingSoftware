#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "Constants.h"


class ofApp : public ofBaseApp{

	public:
	//-------------------------------------------------------------------Variables-------------------------------------------------------------------
		//Fonts:
			ofTrueTypeFont Font_Bold;       //OpenSans bold font (used for important text)
			ofTrueTypeFont Font_Regular;    //OpenSans regular font (used for less important text + settings)
			
		//Images:
			ofImage   Image_Original;    //The image that is loaded in
			ofImage   Image_Edited;      //The image that will be modified
			ofImage   Image_Saved;       //The image that will be saved when the user presses 's' to save their editted image
			ofImage   Image_Cursor;      //The eyedropper image that is set to show up when the mouse is pressed  

		//GUI:
			//GUI panel#1: Adjustment panel
				//Setting #1: Brightness
					ofxLabel         Label_Brightness;         //Label for brightness
					ofxFloatSlider   Slider_Brightness;        //Slider that allows user to adjust the brightness
				//Setting #2: Contrast
					ofxLabel         Label_Contrast;           //Label for contrast
					ofxFloatSlider   Slider_Contrast;          //Slider that allows user to adjust the contrast
				//Setting #3: Saturation
					ofxLabel         Label_Saturation;         //Label for saturation
					ofxFloatSlider   Slider_Saturation;        //Slider that allows user to adjust the saturation
				//Setting #4: RGB colorbalance
					ofxLabel         Label_RGBColorBalance;    //Label for RGB color balance
					ofxFloatSlider   Slider_Red;               //Slider that allows user to adjust the intensity of red 
					ofxFloatSlider   Slider_Green;             //Slider that allows user to adjust the intensity of blue
					ofxFloatSlider   Slider_Blue;              //Slider that allows user to adjust the intensity of green
				//The GUI panel that contains all the settings above
					ofxPanel         GUI_Adjust;

			//GUI panel#2: Filters panel
				//Filter #1: B&W
					ofxButton   Button_BlackandWhiteFilter;    //Button that displays the image as B&W 
				//Filter #2: Sepia
					ofxButton   Button_SepiaFilter;            //Button that displays the image as Sepia
				//Filter #3: Inverted
					ofxButton   Button_InvertFilter;           //Button that displays the image Inverted
				//Filter #4: Edge Detection
					ofxButton   Button_EdgeDetectFilter;       //Button that displays the image with edge detection
				//Filter #5: Gaussian Blur
					ofxButton   Button_GaussianBlurFilter;     //Button that displays the image blurred
				//Filter #6: Sharpen
					ofxButton   Button_SharpenFilter;          //Button that displays the image sharpened
				//The GUI panel that contains all the settings above
					ofxPanel    GUI_Filters;

		//Color picker:
			ofColor   Color_Detected;    //The color that will be detected from the selected part of the image

	//-------------------------------------------------------------------Functions-------------------------------------------------------------------
			//Main functions
				void setup();     //function where everything gets setup
				void update();    //function that allows you to update what you setup
				void draw();      //function that draws everything on the screen
				void exit();      //function that will be called before the app closes

			//GUI#1 functions:
				void AdjustBrightness(float &intensity);           //Brightness function
				void AdjustContrast(float &intensity);             //Contrast function
				void AdjustSaturation(float &intensity);           //Saturation function
				void AdjustRedColorbalance(float &intensity);      //RGB color balance (Red) function
				void AdjustGreenColorbalance(float &intensity);    //RGB color balance (Green) function
				void AdjustBlueColorbalance(float &intensity);     //RGB color balance (Blue) function

			//GUI#2 functions:
				void ApplyBlackandWhiteFilter();                                        //B&W function
				void ApplySepiaFilter();                                                //Sepia function
				void ApplyInvertFilter();                                               //Inverted function
				void ApplyEdgeDetectFilter();                                           //Edge Detection function
				void ApplyGaussianBlurFilter();                                         //Gaussian Blur function
				void applyConvolution7x7(Constants::CONVOLUTION_MAT_TYPE matType);      //Function that reads 7x7 matrices (Edge & Gaussian blur)
				void ApplySharpenFilter();                                              //Sharpen function
				void applyConvolution5x5(Constants::CONVOLUTION_MAT_TYPE2 matType2);    //Function that reads 5x5 matrices  (Sharpen)

			//Color detection functions:
				void mousePressed(int x, int y, int button);
				void mouseDragged(int x, int y, int button);

			//Function for saving the edited image:
				void keyPressed(int key); 

};