#include "ofApp.h"


//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::setup(){
	//Sets the window shape based on the information set in Constrants.h
		ofSetWindowShape(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);

	//Sets the framerate based on the information set in Constrants.h
		ofSetFrameRate(Constants::DESIRED_FRAMERATE);

	//Sets Background color
		ofSetBackgroundColor(23, 23, 23);    //Dark charcoal grey

	//Sets the title for the window
		ofSetWindowTitle("Image Editor");

	//Sets up the fonts
		//For strings
			Font_Regular.load("OpenSans-Regular.ttf", 10.5f);      //Font name, size
			Font_Bold.load("OpenSans-Bold.ttf", 11.0f);            //Font name, size
		//For GUI
			GUI_Adjust.loadFont("OpenSans-Regular.ttf", 9.5f);     //Font name, size
			GUI_Filters.loadFont("OpenSans-Regular.ttf", 9.5f);    //Font name, size

	//Sets up the Images
		//Loads in an image & duplicates it (So that the user can see the original version of the image while editing a copy of it)
			Image_Original.load(Constants::IMG_PATH);    //The original image loaded from Constrants.h
			Image_Edited = Image_Original;               //The duplicated image ("=" means that it takes the data from origImg and copies it)
		//Loads in the eyedropper image that is connected to the mouse cursor
			Image_Cursor.load("Eyedropper.png");    

	//GUI#1 setup
		//Sets up GUI#1 and labels it as "Adjust"
			GUI_Adjust.setup("Adjust: ");
		//Adds in the brightness label and slider
			GUI_Adjust.add(Label_Brightness.setup("Brightness", ""));            //Label: name
			GUI_Adjust.add(Slider_Brightness.setup("", 0.0f, -80.0f, 80.0f));    //Slider: name, initial value, range of values
		//Adds in the contrast label and slider
			GUI_Adjust.add(Label_Contrast.setup("Contrast", ""));                //Label: name
			GUI_Adjust.add(Slider_Contrast.setup("", 0.0f, -80.0f, 80.0f));      //Slider: name, initial value, range of values
		//Adds in the saturation label and slider
			GUI_Adjust.add(Label_Saturation.setup("Saturation", ""));            //Label: name
			GUI_Adjust.add(Slider_Saturation.setup("", 40.0f, 0.0f, 80.0f));     //Slider: name, initial value, range of values
		//Adds in the RGB color balance label and slider
			GUI_Adjust.add(Label_RGBColorBalance.setup("Color balance", ""));    //Label: name
			GUI_Adjust.add(Slider_Red.setup("Cyan                                               Red", 0.0f, -80.0f, 80.0f));    //Slider: name, initial value, range of values
			GUI_Adjust.add(Slider_Green.setup("Magenta                                    Green", 0.0f, -80.0f, 80.0f));        //Slider: name, initial value, range of values
			GUI_Adjust.add(Slider_Blue.setup("Yellow                                           Blue", 0.0f, -80.0f, 80.0f));    //Slider: name, initial value, range of values
		//Sets position of GUI#1
			GUI_Adjust.setPosition(1050.0f, 90.0f);

	//GUI#2 setup
		//Sets up GUI#2 and labels it as "Filters"
			GUI_Filters.setup("Filters: ");
		//Adds the button for the B&W filter
			GUI_Filters.add(Button_BlackandWhiteFilter.setup("Black & White"));    //Name of filter
		//Adds the button for the Sepia filter
			GUI_Filters.add(Button_SepiaFilter.setup("Sepia"));                    //Name of filter
		//Adds the button for the Inverted filter
			GUI_Filters.add(Button_InvertFilter.setup("Invert"));                  //Name of filter
		//Adds the button for the Edge detection filter
			GUI_Filters.add(Button_EdgeDetectFilter.setup("Edge Detect"));         //Name of filter
		//Adds the button for the Gaussian blur filter
			GUI_Filters.add(Button_GaussianBlurFilter.setup("Gaussian Blur"));     //Name of filter
		//Adds the button for the Sharpen filter
			GUI_Filters.add(Button_SharpenFilter.setup("Sharpen"));                //Name of filter
		//Sets position of GUI#1
			GUI_Filters.setPosition(1050.0f, 310.0f);
	
	//Connects the GUI variables to their functions
		//GUI#1
			//Brightness
				Slider_Brightness.addListener(this, &ofApp::AdjustBrightness);
			//Contrast
				Slider_Contrast.addListener(this, &ofApp::AdjustContrast);
			//Saturation
				Slider_Saturation.addListener(this, &ofApp::AdjustSaturation);
			//RGB color balance
				Slider_Red.addListener(this, &ofApp::AdjustRedColorbalance);
				Slider_Green.addListener(this, &ofApp::AdjustGreenColorbalance);
				Slider_Blue.addListener(this, &ofApp::AdjustBlueColorbalance);
		//GUI#2
			//B&W
				Button_BlackandWhiteFilter.addListener(this, &ofApp::ApplyBlackandWhiteFilter);
			//Sepia
				Button_SepiaFilter.addListener(this, &ofApp::ApplySepiaFilter);
			//Inverted
				Button_InvertFilter.addListener(this, &ofApp::ApplyInvertFilter);
			//Edge detection
				Button_EdgeDetectFilter.addListener(this, &ofApp::ApplyEdgeDetectFilter);
			//Gaussian Blur
				Button_GaussianBlurFilter.addListener(this, &ofApp::ApplyGaussianBlurFilter);
			//Sharpen
				Button_SharpenFilter.addListener(this, &ofApp::ApplySharpenFilter);
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::update(){
	
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::draw(){
	//Draws a string of text that tells the user to press 's' in order to save the image they edited
		//Sets the font color for a string 
			ofSetColor(255);     //White
		//Bold text
			Font_Bold.drawString("Press 's' to save your edited image", 540.0f, 35.0f);                                     //Message, position (width , height)
		//Regular text
			Font_Regular.drawString("Note: The image will automatically be saved into your bin folder", 485.0f, 57.0f);     //Message, position (width , height)

	//Draws the Image and it's duplicate
		//Image that will be edited
			Image_Edited.draw(380.0f , 90.0f);     //position (width , height)
		//Original Image
			Image_Original.draw(Image_Original.getWidth() - 490.f, 120.0f, Image_Edited.getWidth() / 3.0f, Image_Edited.getHeight() / 3.0f);     //position (width , height) , size (width , height)
			//A string of text to label it for the user to know why the image is there
				Font_Bold.drawString("Original image", Image_Original.getWidth() - 490.f, 110.0f);     //position (width , height) , size (width , height)

	//Draws the color picker rectangle color and sets it so that it could detect color 
		//Sets the initial color of the rectangle to white (so that the colors detected turn out accurate)
			ofSetColor(255);     //White
		//Fills the rectangle with the image (IMPORTANT!!! unless you want the rectangle to only have a border color)
			ofFill();
		//Sets the rectangle color to the color detected
			ofSetColor(Color_Detected);
		//Draws the rectangle (ALWAYS COMES LAST!!!)
			ofDrawRectangle(1060.0f, 470.0f, Image_Edited.getWidth() / 3.3f, Image_Edited.getHeight() / 3.3f);     //position (width , height) , size (width , height)

	//Draws a string of text that tells the RGB values of the color being detected
		//Sets the color of the text
			ofSetColor(255);     //White
		//Prints out the text + sets the font for it
			Font_Regular.drawString("Color Detected (RGB):\n      " + ofToString(int(Color_Detected.r)) +      
											                 "    " + ofToString(int(Color_Detected.g)) +
		                                                     "    " + ofToString(int(Color_Detected.b)) , 1085.0f, 670.0f);     //text, r value, g value, b value,  size (width , height)
		//Instructional text + sets the font for it
			Font_Bold.drawString("Click and drag the mouse over an area to view its color", 485.0f, 740.0f);     //text, size (width , height)

	//Sets the eyedropper image to appear IF the mouse is being pressed 
		if (ofGetMousePressed()) {
			//Draws the eyedropper image in relation to the mouse
				Image_Cursor.draw(ofGetMouseX(), ofGetMouseY(), 45.0f, 45.0f);     //position (width , height) , size (width , height)
		}

	//Draws the GUIs
		//GUI#1
			GUI_Adjust.draw();
		//GUI#2
			GUI_Filters.draw();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::exit(){
	//Cleans up the listeners that we added before exiting the program
		//GUI#1
			//Brightness
				Slider_Brightness.removeListener(this, &ofApp::AdjustBrightness);
			//Contrast
				Slider_Contrast.removeListener(this, &ofApp::AdjustContrast);
			//Saturation
				Slider_Saturation.removeListener(this, &ofApp::AdjustSaturation);
			//RGB color balance
				Slider_Red.removeListener(this, &ofApp::AdjustRedColorbalance);
				Slider_Green.removeListener(this, &ofApp::AdjustGreenColorbalance);
				Slider_Blue.removeListener(this, &ofApp::AdjustBlueColorbalance);
        //GUI#2
			//B&W
				Button_BlackandWhiteFilter.removeListener(this, &ofApp::ApplyBlackandWhiteFilter);
			//Sepia
				Button_SepiaFilter.removeListener(this, &ofApp::ApplySepiaFilter);
			//Inverted
				Button_InvertFilter.removeListener(this, &ofApp::ApplyInvertFilter);
			//Edge detection
				Button_EdgeDetectFilter.removeListener(this, &ofApp::ApplyEdgeDetectFilter);
			//Gaussian Blur
				Button_GaussianBlurFilter.removeListener(this, &ofApp::ApplyGaussianBlurFilter);
			//Sharpen
				Button_SharpenFilter.removeListener(this, &ofApp::ApplySharpenFilter);
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::AdjustBrightness(float & intensity) {
	//Initializes the variables for the brightness function
		ofColor tempCol;
		ofColor newCol;

	//Loops around the pixels/colors of the original image 
		for (int x = 0; x < Image_Original.getWidth(); x++) {
			for (int y = 0; y < Image_Original.getHeight(); y++) {

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sets the RGB colors for brightness and applies it to newCol
					newCol.set(MAX(MIN(tempCol.r + intensity, 255.0f), 0.0f),       //Red values 
							   MAX(MIN(tempCol.g + intensity, 255.0f), 0.0f),       //Green values
							   MAX(MIN(tempCol.b + intensity, 255.0f), 0.0f));      //Blue values

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies brightness
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::AdjustContrast(float & intensity) {
	//Initializes the variables for the contrast function
		ofColor tempCol;
		ofColor newCol;
		float contrastFactor;
	
	//Defines the contrastFactor variable for the contrast function
		contrastFactor = (259.0f * (intensity + 255.0f)) / (255.0f * (259.0f - intensity));

	//Loops around the pixels/colors of the original image  
		for (int x = 0; x < Image_Original.getWidth(); x++) {
			for (int y = 0; y < Image_Original.getHeight(); y++) {

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sets the RGB colors for contrast and applies it to newCol
					newCol.set(MAX(MIN(contrastFactor * (tempCol.r - 128.0f) + 128.0f, 255.0f), 0.0f),       //Red values
							   MAX(MIN(contrastFactor * (tempCol.g - 128.0f) + 128.0f, 255.0f), 0.0f),       //Green values
							   MAX(MIN(contrastFactor * (tempCol.b - 128.0f) + 128.0f, 255.0f), 0.0f));      //Blue values

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);

			}
		}

	//Updates the editted image / Applies contrast
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::AdjustSaturation(float &intensity) {
	//Initializes the variables for the saturation function
		ofColor tempCol;
		ofColor newCol;

	//Loops around the pixels/colors of the original image 
		for (int y = 0; y < Image_Original.getHeight(); y++) {
			for (int x = 0; x < Image_Original.getWidth(); x++) {

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);
					tempCol.setSaturation(intensity);

				//Sets the RGB colors for saturation and applies it to newCol
					newCol.set(MAX(MIN(tempCol.r, 255.0f), 0.0f),         //Red values
						       MAX(MIN(tempCol.g, 255.0f), 0.0f),         //Green values
						       MAX(MIN(tempCol.b, 255.0f), 0.0f));        //Blue values

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies saturation
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::AdjustRedColorbalance(float & intensity) {
	//Initializes the variables for the RGB color balance (Red) function
		ofColor tempCol;
		ofColor newCol;

	//Loops around the pixels/colors of the original image 
		for (int y = 0; y < Image_Original.getHeight(); y++) {
			for (int x = 0; x < Image_Original.getWidth(); x++) {

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);
			
				//Sets the RGB colors for the RGB color balance (Red) and applies it to newCol
					newCol.set(MAX(MIN(tempCol.r + intensity, 255.0f), 0.0f),
							   MAX(MIN(tempCol.g, 255.0f), 0.0f),
							   MAX(MIN(tempCol.b, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies red color balance
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::AdjustGreenColorbalance(float & intensity) {
	//Initializes the variables for the RGB color balance (Green) function
		ofColor tempCol;
		ofColor newCol;

	//Loops around the pixels/colors of the original image 
		for (int y = 0; y < Image_Original.getHeight(); y++) {
			for (int x = 0; x < Image_Original.getWidth(); x++) {

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sets the RGB colors for the RGB color balance (Green) and applies it to newCol
					newCol.set(MAX(MIN(tempCol.r, 255.0f), 0.0f),
							   MAX(MIN(tempCol.g + intensity, 255.0f), 0.0f),
							   MAX(MIN(tempCol.b, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies green color balance
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::AdjustBlueColorbalance(float & intensity) {
	//Initializes the variables for the RGB color balance (Blue) function
		ofColor tempCol;
		ofColor newCol;

	//Loops around the pixels/colors of the original image 
		for (int y = 0; y < Image_Original.getHeight(); y++) {
			for (int x = 0; x < Image_Original.getWidth(); x++) {

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sets the RGB colors for the RGB color balance (Blue) and applies it to newCol
					newCol.set(MAX(MIN(tempCol.r, 255.0f), 0.0f),
							   MAX(MIN(tempCol.g, 255.0f), 0.0f),
							   MAX(MIN(tempCol.b + intensity, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies blue color balance
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::ApplyBlackandWhiteFilter() {
	//Initializes the variables for the B&W filter function
		ofColor tempCol;
		ofColor newCol;
		ofVec3f sum;
		int imgWidth = Image_Original.getWidth();
		int imgHeight = Image_Original.getHeight();

	//Loops around the pixels/colors of the original image 
		for (int y = 0; y < imgHeight; y++) {
			for (int x = 0; x < imgWidth; x++) {

				//Sets the initial values for x, y, z
					sum.set(0.0f, 0.0f, 0.0f);

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sums up the different co-orinates of the image
					sum.x += (tempCol.r + tempCol.g + tempCol.b) / 3.0f;
					sum.y += (tempCol.r + tempCol.g + tempCol.b) / 3.0f;
					sum.z += (tempCol.r + tempCol.g + tempCol.b) / 3.0f;

				//Sets the RGB colors for the Black&White filter and applies it to newCol
					newCol.set(MAX(MIN(sum.x, 255.0f), 0.0f),
							   MAX(MIN(sum.y, 255.0f), 0.0f),
							   MAX(MIN(sum.z, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies the black & white filter
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::ApplySepiaFilter() {
	//Initializes the variables for the Sepia filter function
		ofColor tempCol;
		ofColor newCol;
		ofVec3f sum;
		int imgWidth = Image_Original.getWidth();
		int imgHeight = Image_Original.getHeight();

	//Loops around the pixels/colors of the original image 
		for (int y = 0; y < imgHeight; y++) {
			for (int x = 0; x < imgWidth; x++) {

				//Sets the initial values for x, y, z
					sum.set(0.0f, 0.0f, 0.0f);

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sums up the different co-orinates of the image
					sum.x += tempCol.r * 0.393 + tempCol.g * 0.769 + tempCol.b * 0.189;
					sum.y += tempCol.r * 0.349 + tempCol.g * 0.686 + tempCol.b * 0.168;
					sum.z += tempCol.r * 0.272 + tempCol.g * 0.534 + tempCol.b * 0.131;

				//Sets the RGB colors for the Sepia filter and applies it to newCol
					newCol.set(MAX(MIN(sum.x, 255.0f), 0.0f),
						       MAX(MIN(sum.y, 255.0f), 0.0f),
						       MAX(MIN(sum.z, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies the Sepia filter
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::ApplyInvertFilter() {
	//Initializes the variables for the Sepia filter function
		ofColor tempCol;
		ofColor newCol;
		ofVec3f sum;
		int imgWidth = Image_Original.getWidth();
		int imgHeight = Image_Original.getHeight();

	//Loops around the pixels/colors of the original image
		for (int y = 0; y < imgHeight; y++) {
			for (int x = 0; x < imgWidth; x++) {

				//Sets the initial values for x, y, z
					sum.set(0.0f, 0.0f, 0.0f);

				//Defines what tempCol is
					tempCol = Image_Original.getColor(x, y);

				//Sums up the different co-orinates of the image
					sum.x += (255.0f - tempCol.r);
					sum.y += (255.0f - tempCol.g);
					sum.z += (255.0f - tempCol.b);

				//Sets the RGB colors for the Inverted filter and applies it to newCol
					newCol.set(MAX(MIN(sum.x, 255.0f), 0.0f),
							   MAX(MIN(sum.y, 255.0f), 0.0f),
							   MAX(MIN(sum.z, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}

	//Updates the editted image / Applies the Sepia filter
		Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::ApplyEdgeDetectFilter() {
	//Calls the matrix for this filter from Constants.h and processes it through the applyConvolution7x7 function
		applyConvolution7x7(Constants::CONVOLUTION_MAT_TYPE::EDGEDETECTION);
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::ApplyGaussianBlurFilter() {
	//Calls the matrix for this filter from Constants.h and processes it through the applyConvolution7x7 function
		applyConvolution7x7(Constants::CONVOLUTION_MAT_TYPE::GAUSSIANBLUR);
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::applyConvolution7x7(Constants::CONVOLUTION_MAT_TYPE matType) {
	//Initializes and defines the variables for the Edge detect and Gaussian blur filters
		ofColor tempCol;
		ofColor newCol;
		ofVec3f sum;
		int neighbourX = 0;                      //Kernal X
		int neighbourY = 1;                      //Kernal Y
		int startIndex = (int)matType * 49;      //Start of loop for kernal/convulotion variables | 49 because a 7x7 matrix contains 49 values
		int imgWidth = Image_Original.getWidth();
		int imgHeight = Image_Original.getHeight();

	//Loops through the kernal (the pixels of the image + it's neighbor values)
		for (int y = 0; y < imgHeight; y++) {
			for (int x = 0; x < imgWidth; x++) {

				//Sets the initial values for kernel
					sum.set(0.0f, 0.0f, 0.0f);

					//Loops through the kernel 7x7 times = 49 
						for (int k = startIndex; k < startIndex + 49; k++) {

							//Checks if we are trying to access an image coordinate out of bounds, if so it would extend edges
								neighbourX = x + Constants::CONVOLUTION_KERNAL_CONVERT_X[k % 49];
								if (neighbourX < 0) {
									neighbourX = 0;
								}
								else if (neighbourX > imgWidth - 1) {
									neighbourX = imgWidth - 1;
								}
								neighbourY = y + Constants::CONVOLUTION_KERNAL_CONVERT_Y[k % 49];
								if (neighbourY < 0) {
									neighbourY = 0;
								}
								else if (neighbourY > imgHeight - 1) {
									neighbourY = imgHeight - 1;
								}

							//Find out which 2D coordinate of image k belongs to
							tempCol = Image_Original.getColor(neighbourX, neighbourY);

							//Sums up kernel factors
								sum.x += tempCol.r * Constants::CONVOLUTION_MATS_7X7[k];
								sum.y += tempCol.g * Constants::CONVOLUTION_MATS_7X7[k];
								sum.z += tempCol.b * Constants::CONVOLUTION_MATS_7X7[k];
						}

			    	//Sets the RGB colors for the Edge detect and Gaussian blur filters and applies it to newCol
						newCol.set(MAX(MIN(sum.x, 255.0f), 0.0f),
								   MAX(MIN(sum.y, 255.0f), 0.0f),
								   MAX(MIN(sum.z, 255.0f), 0.0f));

					//Sets the new colors to apply to the editted image 
						Image_Edited.setColor(x, y, newCol);
			}
		}
		//Updates the editted image / Applies the Edge detect and Gaussian blur filters
			Image_Edited.update();
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::ApplySharpenFilter() {
	//Calls the matrix for this filter from Constants.h and processes it through the applyConvolution5x5 function
		applyConvolution5x5(Constants::CONVOLUTION_MAT_TYPE2::SHARPEN);
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::applyConvolution5x5(Constants::CONVOLUTION_MAT_TYPE2 matType2) {
	//Initializes and defines the variables for the Edge detect and Gaussian blur filters
		ofColor tempCol;
		ofColor newCol;
		ofVec3f sum;
		int neighbourx = 0;                       //Kernal X
		int neighboury = 0;                       //Kernal Y
		int startIndex = (int)matType2 * 25;      //Start of loop for kernal/convulotion variables | 25 because a 5x5 matrix contains 25 values
		int imgWidth = Image_Original.getWidth();
		int imgHeight = Image_Original.getHeight();

	//Loops through the kernal (the pixels of the image + it's neighbor values)
		for (int y = 0; y < imgHeight; y++) {
			for (int x = 0; x < imgWidth; x++) {

				//Sets the initial values for kernel
					sum.set(0.0f, 0.0f, 0.0f);

				//Loops through the kernel 5x5 times = 25
					for (int k = startIndex; k < startIndex + 25; k++) {

						//Checks if we are trying to access an image coordinate out of bounds, if so it would extend edges
							neighbourx = x + Constants::CONVOLUTION_KERNAL_CONVERT_x[k % 25];
							if (neighbourx < 0) {
								neighbourx = 0;
							}
							else if (neighbourx > imgWidth - 1) {
								neighbourx = imgWidth - 1;
							}
							neighboury = y + Constants::CONVOLUTION_KERNAL_CONVERT_x[k % 25];
							if (neighboury < 0) {
								neighboury = 0;
							}
							else if (neighboury > imgHeight - 1) {
								neighboury = imgHeight - 1;
							}

						//Find out which 2D coordinate of image k belongs to
							tempCol = Image_Original.getColor(neighbourx, neighboury);

						//sum up kernel factors
							sum.x += tempCol.r * Constants::CONVOLUTION_MATS_5X5[k];
							sum.y += tempCol.g * Constants::CONVOLUTION_MATS_5X5[k];
							sum.z += tempCol.b * Constants::CONVOLUTION_MATS_5X5[k];
					}

				//Sets the RGB colors for the sharpen filter and applies it to newCol
					newCol.set(MAX(MIN(sum.x, 255.0f), 0.0f),
							   MAX(MIN(sum.y, 255.0f), 0.0f),
							   MAX(MIN(sum.z, 255.0f), 0.0f));

				//Sets the new colors to apply to the editted image 
					Image_Edited.setColor(x, y, newCol);
			}
		}
	//Updates the editted image / Applies the sharpen filter
		Image_Edited.update();
}




//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//Changes the color of the rectangle based on the mouse position that was pressed / pixel of the image that was detected and reveals the color of it
		Color_Detected = Image_Edited.getPixels().getColor(x, y);
}




//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//Gives the user the option to not only press on the image to detect a color, but also drag through the different pixels
		Color_Detected = Image_Edited.getPixels().getColor(x, y);
}



//----------------------------------------------------------------------------------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//Saves the editted image once the user presses the letter s on the keyboard
		if (key == 's') {
			//Sets a ratio for the screen grab (so that only that of the screen gets exported out)
				Image_Saved.grabScreen(380.0f, 90.0f, 600.0f, 600.0f);      //position (width , height) , size (width , height)
			//Sets the format that the image will be saved in
				string fileName = "EditedImage_" + ofToString(1, 2, '0') + ".png";      //name_0(and another value after it depending on the number of times the image was saved).png
			//Saves the image to the set folder (which in this case is the bin folder) with the final name that was set here^ & also saves the image to the best quality
				Image_Saved.save(fileName, OF_IMAGE_QUALITY_BEST);
		}
}