#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE, WINGS, HEAD_X, HEAD_Y, SPEED, FPS, NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_YELLOW	1.0f, 0.8f, 0.0f
#define COLOR_ORANGE	0.3f, 0.15f, 0.0f
#define COLOR_TURQUOISE 0.25f, 0.87f, 0.81f
#define COLOR_GREY		0.5f, 0.5f, 0.5f
#define COLOR_BROWN		0.05f, 0.02f, 0.005f
#define COLOR_BLACK		0.01f, 0.01f, 0.01f
#define COLOR_WHITE		0.7f, 0.7f, 0.7f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif