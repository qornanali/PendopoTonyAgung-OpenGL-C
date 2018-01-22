#include "scene.h"

#include "pendopo.h"
#include "cJSON.h"
#include "list_string.h"
#include "list_int.h"
#include "list_double.h"
#include "interface.h"

 LInts lTextures;
 LStrings lConfigs;
 LDoubles lMeasures;

 cJSON * jsonPendopo;


 float xrot;
 float yrot;
 float zrot;
 float xdiff;
 float ydiff;
 float scale;
 BOOL mouseDown;
GLfloat widthTembok, heightTembok, depthTembok;
GLfloat widthBase, heightBase, depthBase;
GLfloat widthGapura, heightGapura, depthGapura;
GLfloat widthTiang, heightTiang, depthTiang;
GLfloat widthTangga, heightTangga, depthTangga;
GLfloat widthFentilasi, heightFentilasi, depthFentilasi;


void onWorldDisplay(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(
		0.0f, 10.0f, 30.0f,
		0.0f, 10.0f, 0.0f,
		0.0f, 40.0f, 0.0f);
//	glPushMatrix();
  	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
  	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
	  	glRotatef(xrot, 0.1f, 0.0f, 0.0f);
		glRotatef(yrot, 0.0f, 0.1f, 0.0f);
		glRotatef(zrot, 0.0f, 0.0f, 0.1f);
		glPushMatrix();		
		  
//	widthBase = 80;
//	widthTembok = widthBase - 20;
//	heightBase = 2;
//	heightTembok = 13;
//	depthBase = widthBase + 15;
//	depthTembok = depthBase - 20;
//	heightFentilasi = 1;
//	depthFentilasi = 0.5;
//	P_Int PPondasi = getInt(lTextures, "atap-2");
//	P_Int PFloor = getInt(lTextures, "lantai");
//	P_Int PPlafon = getInt(lTextures, "interior");
//	P_Int PTembok = getInt(lTextures, "tembok4");
//	P_Int PTiang = getInt(lTextures, "pilar-2");
//	
//	widthBase = getDouble(lMeasures, "pendopo_width")->value;
//	heightBase = getDouble(lMeasures, "pendopo_height")->value;
//	widthBase = getDouble(lMeasures, "pendopo_depth")->value;
//	
//	glPushMatrix();
//	glScalef(widthBase, heightBase, widthBase);
//	//Base
//	glPushMatrix();
//	glTranslatef(0,heightBase * 0.5,0);
//	drawBox(widthBase,heightBase,depthBase, PPondasi == NULL ? 0 : PPondasi->value, PPondasi == NULL ? 0 : PPondasi->value, 
//	PPondasi == NULL ? 0 : PPondasi->value, PPondasi == NULL ? 0 : PPondasi->value, PFloor == NULL ? 0 : PFloor->value, 0, 40.0);
//	glPopMatrix();
//	
//	//Depan kiri
//	glPushMatrix();
//	glTranslatef(-widthTembok*0.5 + widthTiang * 3,heightBase * 0.5, depthBase * 0.5 + depthTiang);
//	drawBox(widthBase - 48,heightBase, 5, 0,PPondasi == NULL ? 0 : PPondasi->value,PPondasi == NULL ? 0 : PPondasi->value,
//	PPondasi == NULL ? 0 : PPondasi->value,PFloor == NULL ? 0 : PFloor->value, 0,4);
//	glPopMatrix();
//	
//	//Depan kanan
//	glPushMatrix();
//	glTranslatef(widthTembok*0.5 - widthTiang * 3,heightBase * 0.5, depthBase * 0.5 + depthTiang);
//	drawBox(widthBase - 48,heightBase, 5, 0,PPondasi == NULL ? 0 : PPondasi->value,PPondasi == NULL ? 0 : PPondasi->value,PPondasi == NULL ? 0 : PPondasi->value,
//	PFloor == NULL ? 0 : PFloor->value,0,4);
//	glPopMatrix();
//	
//	//Kiri
//	glPushMatrix();
//	glTranslatef(widthBase * 0.5 + (widthTangga * 0.5) * 0.5, heightBase * 0.5, 0);
//	drawBox(widthTangga * 0.5, heightBase, 10, PPondasi == NULL ? 0 : PPondasi->value,PPondasi == NULL ? 0 : PPondasi->value,
//	PPondasi == NULL ? 0 : PPondasi->value,0,PFloor == NULL ? 0 : PFloor->value,0,1);
//	glPopMatrix();
//	
//	//Kanan
//	glPushMatrix();
//	glTranslatef(-widthBase * 0.5 - (widthTangga * 0.5) * 0.5, heightBase * 0.5, 0);
//	drawBox(widthTangga * 0.5, heightBase, 10, PPondasi == NULL ? 0 : PPondasi->value,PPondasi == NULL ? 0 : PPondasi->value,0,
//	PPondasi == NULL ? 0 : PPondasi->value,PFloor == NULL ? 0 : PFloor->value,0,1);
//	glPopMatrix();
//	
//	//	Bangunan Inti
//	glPushMatrix();
//	glTranslatef(0,heightTembok * 0.5 - heightFentilasi + heightBase - 0.25 ,0);
//	bangunanInti(widthTembok,heightTembok - heightFentilasi * 2.5,depthTembok, PTiang == NULL ? 0 : PTiang->value, 
//	PTembok == NULL ? 0 : PTembok->value, PTembok == NULL ? 0 : PTembok->value, PTembok == NULL ? 0 : PTembok->value, 
//	PPlafon == NULL ? 0 : PPlafon->value, PFloor == NULL ? 0 : PFloor->value, 1);
//	glPopMatrix();
//	
//	// Atap
//	glPushMatrix();
//	glTranslatef(0, heightBase + heightTembok + 0.25 * 0.5 + 0.05 *40, 0);
//	glScalef(42,40,44);
//		glPushMatrix();
//		glTranslatef(0,0.15,0);
//		glScalef(0.65, 0.55, 0.65);
//		atap();
//		glPopMatrix();
//		glPushMatrix();
//		glScalef(0.7,1.8,0.7);
//		atap();
//		glPopMatrix();
//	atap();
//	bawahAtap();
//		glPushMatrix();
//		glTranslatef(0,0.2,0);
//		atasAtap();
//		glPopMatrix();
//	glPopMatrix();
//	
//	ventilasi();
//	gapura();
//	tangga();
	
//		  	drawWalls();
//			drawPillars();
//			drawFront();
//			drawRoof();
//			drawLand();
//			drawSky();
//			drawFloors();
		glPopMatrix();
//	  	drawCartesius(DEFAULT_COORD, 100.0);
//	glPopMatrix();
	
  	glutSwapBuffers();
}

void onWorldIdle(){
//	if (!mouseDown){
//		xrot += 0.01f;
//		yrot += 0.01f;
//		zrot += 0.01f;
//	}
	 
//	glutPostRedisplay();
}

void onWorldReshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
  	gluPerspective(65.0f, 1.0f * (float)w / (float) h, 1.0, 1000);
  	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void onSpecialKeyClicked(int key, int x, int y ){
  	if (key == GLUT_KEY_RIGHT)
    	xrot++;
 
 	else if (key == GLUT_KEY_LEFT)
    	xrot--;
 
  	else if (key == GLUT_KEY_UP)
    	yrot++;
 
  	else if (key == GLUT_KEY_DOWN)
    	yrot--;
	
	else if(key == GLUT_KEY_PAGE_UP)
		glTranslated(0,-1,0);
    
  	else if(key == GLUT_KEY_PAGE_DOWN)
		glTranslated(0,1,0);
  	
//  	else if(key == GLUT_KEY_F5)
//  	loadTexture();
	glMatrixMode(GL_MODELVIEW);
  	glutPostRedisplay();
} 

void onNormalKeyClicked(unsigned char key, int x, int y){
	glMatrixMode(GL_PROJECTION);
	switch (key){
		case 27 :
		case 'w':
            glTranslatef(0,0,1);
			break;
		case 's':
	        glTranslatef(0,0,-1);
			break;
		case 'a':
			glTranslatef(1,0,0);
			break;
		case 'd':
            glTranslatef(-1,0,0);
			break;
		case 61 :
			scale += 0.01;
			break;
		case 45 :
			scale -= 0.01;
			break;
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void onMotionMouseClicked(int x, int y){
	if (mouseDown){
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
}

void onButtonMouseClicked(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = TRUE;
		 
		xdiff = x - yrot;
		ydiff = -y + xrot;
	} else{
		mouseDown = FALSE;
	}
}

void onPassiveMouseActived(int x, int y){
	
}

