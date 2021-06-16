// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	// draw the floor
	/*setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5,0,-5);
	drawBox(10,0.01f,10);
	glPopMatrix();*/

	// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		double i = 1;
		glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		glTranslated(0, 0, VAL(HEIGHT));		

		//****Draw Wings****//
		
		//Draw Left Wing
		glPushMatrix();
		if(getBirdType() == BLUE)
			setDiffuseColor(COLOR_TURQUOISE);
		if (getBirdType() == RED)
			setDiffuseColor(COLOR_RED);
		else if (getBirdType() == YELLOW)
			setDiffuseColor(COLOR_BLACK);
		else if (getBirdType() == EAGLE) {
			setDiffuseColor(COLOR_BROWN);glScaled(1.5, 1, 1);
		}
		glTranslated(0, VAL(HEIGHT), 0);
		glRotated(VAL(WINGS), 0, 0, 1);
		drawTriangle(0.0, 0.0, 3.0, 1.5, 0.5, 4.0, 1.5, 0.5, 1);
		drawTriangle(1.5, 0.5, 1.0, 1.5, 0.5, 4.0, 3, VAL(WINGS)/25, 3);
		glPopMatrix();

		//Draw Right Wing
		glPushMatrix();
		glRotated(180, 0, 1, 0);
		glScaled(1, 1, -1);
		glTranslated(0, VAL(HEIGHT), 0);
		glRotated(VAL(WINGS), 0, 0, 1);
		if (getBirdType() == EAGLE)
			glScaled(1.5, 1, 1);
		drawTriangle(0.0, 0.0, 3.0, 1.5, 0.5, 4.0, 1.5, 0.5, 1);
		drawTriangle(1.5, 0.5, 1.0, 1.5, 0.5, 4.0, 3, VAL(WINGS)/25, 3);
		glPopMatrix();


		//****Draw Body****//
		glPushMatrix();
		i = 1;
		glRotated(-90, 1.0, 0.0, 0.0);
		if (getBirdType() == BLUE)
			setDiffuseColor(COLOR_BLUE);
		if (getBirdType() == RED)
			setDiffuseColor(COLOR_RED);
		else if (getBirdType() == YELLOW)
			setDiffuseColor(COLOR_YELLOW);
		else if (getBirdType() == EAGLE) {
			setDiffuseColor(COLOR_BROWN);
			glTranslated(0, 0.7, 0);
			i = 1.15;
		}
		glTranslated(0.0, .0, VAL(HEIGHT));
		glRotated(90, 1.0, 0.0, 0.0);
		glRotated(-10, 1.0, 0.0, 0.0);
		drawCylinder(4*i, 0.7*i, 0.7*i);
		glPopMatrix();


		//****Draw Head****//
		glPushMatrix();
		glTranslated(0.0, VAL(HEIGHT) + 1, 4);
		glRotated(VAL(HEAD_X), 0, 1, 0);
		glRotated(VAL(HEAD_Y), 1, 0, 0);
		if (getBirdType() == BLUE)
			setDiffuseColor(COLOR_BLUE);
		if (getBirdType() == RED)
			setDiffuseColor(COLOR_BLACK);
		else if (getBirdType() == YELLOW)
			setDiffuseColor(COLOR_YELLOW);
		else if (getBirdType() == EAGLE)
			setDiffuseColor(COLOR_WHITE);
		drawSphere(0.7); //Head
		setDiffuseColor(COLOR_YELLOW);
		if (getBirdType() == RED)
			setDiffuseColor(COLOR_RED);
		else if (getBirdType() == YELLOW)
			setDiffuseColor(COLOR_ORANGE);
		else if (getBirdType() == EAGLE)
			glScaled(1, 1, 1.3);
		drawCylinder(1.5, 0.5, 0.01); //Beak
		if (getBirdType() == RED) {
			glRotated(130, -1, 0, 0);
			setDiffuseColor(COLOR_RED);
			glTranslated(0, -0.3, 0);
			drawCylinder(1.5, 0.5, 0.01);
		}
		glPopMatrix();


		//****Draw Back****//
		glPushMatrix();
		i = 1;
		if (getBirdType() == BLUE)
			setDiffuseColor(COLOR_BLUE);
		if (getBirdType() == RED)
			setDiffuseColor(COLOR_RED);
		else if (getBirdType() == YELLOW)
			setDiffuseColor(COLOR_YELLOW);
		else if (getBirdType() == EAGLE) {
			setDiffuseColor(COLOR_WHITE);
			i = 1.15;
			glTranslated(0, 0.1, -1.2);
		}
		glTranslated(0, VAL(HEIGHT) + 0.5, -2.5);
		glRotated(10, 1.0, 0, 0);
		drawCylinder(3.0*i, 0.01*i, 0.7*i);
		glPopMatrix();


		//****Draw Feet****//
		glPushMatrix();
		setDiffuseColor(COLOR_ORANGE);
		glRotated(-15, 1, 0, 0);
		glTranslated(0.25, -1 + VAL(HEIGHT), 0.2);
		if (getBirdType() == EAGLE)
			glScaled(1, 1, 1.3);
		drawCylinder(1.0, 0.05, 0.05);
		glTranslated(-0.5, 0, 0);
		drawCylinder(1.0, 0.05, 0.05);
		glPopMatrix();



	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
	controls[WINGS] = ModelerControl("Wings", -25, 25, 1, 0);
	controls[HEAD_X] = ModelerControl("Head X", -50, 50, 1, 0);
	controls[HEAD_Y] = ModelerControl("Head Y", -50, 50, 1, 0);
	controls[SPEED] = ModelerControl("SPEED", 5, 380, 1, 40);
	controls[FPS] = ModelerControl("FPS", 5, 80, 1, 40);


    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}
