#include <gl\glut.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>


int is_depth;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown =false;

float w(int x){
	float hasil = x;
	if(x>=255){
		hasil = 255;
	}else if(x<=0){
		hasil = 0;
	};
	return (float) hasil/255;
};
float c[100][4] = {{w(0),w(127),w(255),1.0f},
					{w(255),w(127),w(0),1.0f}
					};

void tabung(float radatas,float radbawah,float tinggi, float x, float y,float z,float atas[4],float selimut[4], float bawah[4],int mulai ,int stop){
	float theta,theti;
	int i,j;

	if(mulai <=0){
		mulai= 0;
	}else if(mulai>=360){
		mulai = 360;
	};
	if(stop <= 0){
		stop = 0;
	}else if(stop >=360){
		stop = 360;
	};

	glPushMatrix();//bawah
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor4f(bawah[0],bawah[1],bawah[2],bawah[3]);
	for(i=mulai;i<stop;i++){
		theta = i*3.14/180;
		glVertex3f(x+radbawah*cos(theta),y,z+radbawah*sin(theta));
	};
	glEnd();
	//selimut
	glBegin(GL_POLYGON);
	glColor4f(selimut[0],selimut[1],selimut[2],selimut[3]);
	for(i=mulai;i<stop;i++){
		theta = i*3.14/180;
		if(i==359){
			j=0;
		}else{
			j=i+1;
		};
		theti = j*3.14/180;
		glVertex3f(x+radatas*cos(theta),y+tinggi,z+radatas*sin(theta));
		glVertex3f(x+radatas*cos(theti),y+tinggi,z+radatas*sin(theti));
		glVertex3f(x+radbawah*cos(theti),y,z+radbawah*sin(theti));
		glVertex3f(x+radbawah*cos(theta),y,z+radbawah*sin(theta));
	};
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor4f(atas[0],atas[1],atas[2],atas[3]);
	for(i=mulai;i<stop;i++){
		theta = i*3.14/180;
		glVertex3f(x+radatas*cos(theta),y+tinggi,z+radatas*sin(theta));
	};
	glEnd();
	glPopMatrix();
	glPopMatrix();
};

	

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON&& state == GLUT_DOWN){
	mousedown=true;
	xdiff=x-yrot;
	ydiff=-y+xrot;
	}
	else{
	mousedown = false;
	}
	glutPostRedisplay();
}
void mousemotion(int x, int y){
		if (mousedown){
		yrot=x-xdiff;
		xrot=y+ydiff;

		glutPostRedisplay();
		}
	}


void initGL() {
   glClearColor((float)77/255.0f,(float)72/255.0f,(float)63/255.0f,1); 
   glClearDepth(1.0f);                  
   glEnable(GL_DEPTH_TEST);   
   glDepthFunc(GL_LEQUAL);   
   glShadeModel(GL_SMOOTH);   
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
is_depth=1;
}
void Traktor(float x, float y, float z, float px, float py, float pz)
{

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glLineWidth(2);
	glPushMatrix();
	//udud dulu asdos bngsd
	tabung(7.0f,7.0f,5.0f,12.0,3.0,1.0,c[1],c[0],c[1],0,360);

	//Ruang Supir
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//depan
	glVertex3f( 0.0, 0.0, 0.0);
    glVertex3f( 0.0, 5.0, 0.0);
    glVertex3f( 5.0, 5.0, 0.0);
    glVertex3f( 5.0, 0.0, 0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kanan
	glVertex3f( 5.0, 0.0, 0.0);
    glVertex3f( 5.0, 5.0, 0.0);
    glVertex3f( 5.0, 5.0, -3.0);
    glVertex3f( 5.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//belakang
	glVertex3f( 5.0, 0.0, -3.0);
    glVertex3f( 5.0, 5.0, -3.0);
    glVertex3f( 0.0, 5.0, -3.0);
    glVertex3f( 0.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kiri
	glVertex3f( 0.0, 0.0, -3.0);
    glVertex3f( 0.0, 5.0, -3.0);
    glVertex3f( 0.0, 5.0, 0.0);
    glVertex3f( 0.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);//atas
	glVertex3f( 0.0, 5.0, 0.0);
    glVertex3f( 0.0, 5.0, -3.0);
    glVertex3f( 5.0, 5.0, -3.0);
    glVertex3f( 5.0, 5.0, 0.0);
	glEnd();

	//Bodi
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);//depan
	glVertex3f( -7.0, 0.0, -3.0);
    glVertex3f( -7.0, 3.0, -3.0);
    glVertex3f( 6.0, 3.0, -3.0);
    glVertex3f( 6.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);//kanan
	glVertex3f( 6.0, 0.0, -3.0);
    glVertex3f( 6.0, 3.0, -3.0);
    glVertex3f( 6.0, 3.0, -7.0);
    glVertex3f( 6.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);//belakang
	glVertex3f( 6.0, 0.0, -7.0);
    glVertex3f( 6.0, 3.0, -7.0);
    glVertex3f( -7.0, 3.0, -7.0);
    glVertex3f( -7.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex3f( -7.0, 0.0, -7.0);
    glVertex3f( -7.0, 3.0, -7.0);
    glVertex3f( -7.0, 3.0, -3.0);
    glVertex3f( -7.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//atas
	glVertex3f( -7.0, 3.0, -3.0);
    glVertex3f( -7.0, 3.0, -7.0);
    glVertex3f( 6.0, 3.0, -7.0);
    glVertex3f( 6.0, 3.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -7.0, 0.0, -3.0);
    glVertex3f( -7.0, 0.0, -7.0);
    glVertex3f( 6.0, 0.0, -7.0);
    glVertex3f( 6.0, 0.0, -3.0);
	glEnd();

	//Alas bodi
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, -0.5, 0.0);
    glVertex3f( -8.0, 0.0, 0.0);
    glVertex3f( 6.0, 0.0, 0.0);
    glVertex3f( 6.0, -0.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( 6.0, -0.5, 0.0);
    glVertex3f( 6.0, 0.0, 0.0);
    glVertex3f( 6.0, 0.0, -8.0);
    glVertex3f( 6.0, -0.5, -8.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( 6.0, -0.5, -8.0);
    glVertex3f( 6.0, 0.0, -8.0);
    glVertex3f( -8.0, 0.0, -8.0);
    glVertex3f( -8.0, -0.5, -8.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, -0.5, -8.0);
    glVertex3f( -8.0, 0.0, -8.0);
    glVertex3f( -8.0, 0.0, 0.0);
    glVertex3f( -8.0, -0.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, 0.0, 0.0);
    glVertex3f( -8.0, 0.0, -8.0);
    glVertex3f( 6.0, 0.0, -8.0);
    glVertex3f( 6.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, -0.5, 0.0);
    glVertex3f( -8.0, -0.5, -8.0);
    glVertex3f( 6.0, -0.5, -8.0);
    glVertex3f( 6.0, -0.5, 0.0);
	glEnd();

	//roda
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -4.0, -2.0, -2.0);
    glVertex3f( -4.0, -0.5, -2.0);
    glVertex3f( 4.0, -0.5, -2.0);
    glVertex3f( 4.0, -2.0, -2.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 4.0, -2.0, -2.0);
    glVertex3f( 4.0, -0.5, -2.0);
    glVertex3f( 4.0, -0.5, -6.0);
    glVertex3f( 4.0, -2.0, -6.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 4.0, -2.0, -6.0);
    glVertex3f( 4.0, -0.5, -6.0);
    glVertex3f( -4.0, -0.5, -6.0);
    glVertex3f( -4.0, -2.0, -6.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -4.0, -2.0, -6.0);
    glVertex3f( -4.0, -0.5, -6.0);
    glVertex3f( -4.0, -0.5, -2.0);
    glVertex3f( -4.0, -2.0, -2.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -4.0, -2.0, -2.0);
    glVertex3f( -4.0, -2.0, -6.0);
    glVertex3f( 4.0, -2.0, -6.0);
    glVertex3f( 4.0, -2.0, -2.0);
	glEnd();
	
	

}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective pojection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void display(void){
    glPushMatrix();
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0,10,20,0,0,0,0,1,0);
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);
	glColor3f(1,0,0);	
    Traktor(0,0,0,10,10,10);
    glPopMatrix();
	glutSwapBuffers();
}

void keyboard(unsigned char pencetan, int uh, int ah) {
   switch (pencetan) {
		
			 //geser ke kiri
		case 'a':
			glTranslatef(-0.5f, 0.0, 0.0);
			break;
		case 'A':
			glTranslatef(-1.0, 0.0, 0.0);
			break;
			//geser ke kanan
		case 'd':
			glTranslatef(0.5f, 0.0, 0.0);
			break;
		case 'D':
			glTranslatef(1.0, 0.0, 0.0);
			break;
			 //gerak ke atas
		case 'w':
			glTranslatef(0.0, 0.5f, 0);
			break;
		case 'W':
			glTranslatef(0.0, 1.0, 0);
			break;
			 //gerak ke bawah
		case 's':
			glTranslatef(0.0, -0.5f, 0);
			break;
		case 'S':
			glTranslatef(0.0, -1.0, 0);
			break;
			 //gerak ke depan
		case 'z':
			glTranslatef(0.0, 0, 0.5f);
			break;
		case 'Z':
			glTranslatef(0.0, 0, 1.0);
			break;
			 //gerak ke belakang
		case 'c':
			glTranslatef(0.0, .0, -0.5f);
			break;
		case 'C':
			glTranslatef(0.0, .0, -1.0);
			break;
			 //rotate ke kiri
		case 'k':
			glRotatef(1.0, 0.0, -5.0, 0.0);
			break;
		case 'K':
			glRotatef(2.0, 0.0, -5.0, 0.0);
			break;
			//rotate ke kanan
		case ';':
			glRotatef(1.0, 0.0, 5.0, 0.0);
			break;
		case ':':
			glRotatef(2.0, 0.0, 5.0, 0.0);
			break;
			//rotate ke samping kanan
		case 'p':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
		case 'P':
			glRotatef(2.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case 'i':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
		case 'I':
			glRotatef(2.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case 'o':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
		case 'O':
			glRotatef(2.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case 'l':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
		case 'L':
			glRotatef(2.0, 5.0, 0.0, 0.0);
			break;
   }
   display();
   //glutPostRedisplay(); 
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(880, 700);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("3GP");          // Create window with the given title
    initGL(); 
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	// Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}

