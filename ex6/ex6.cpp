// --------------------------------------------
// LUCAS VIEIRA COSTA NICOLAU     
// 8517101
// --------------------------------------------

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#define DEV 1		// Mensagem do desenvolvedor
#define GRID 1		// Coloca um grid para facilitar o teste
#define VER_3D 0	// Coloca um grid para facilitar o teste


// --------------------------------------------
// VAR GLOBAIS
// --------------------------------------------
float rotX, rotY, rotZ;
float cameraX, cameraY, cameraZ;
float movimento;
float altura;
float largura;
float angulo;
int fullscreen = 0;		// alternar entre fullscreen e tela de tamanho normal


// --------------------------------------------
// INIT
// --------------------------------------------
// Funcao que inicializa todas as variaveis do programa
void Init() {
	// tela preta
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// 3d tem que ter profundidade, para n ocorrer sobreposicao do vertice do fundo com o da frente
	// Se não ativar isso da problema
	glEnable(GL_DEPTH_TEST);
	
	// inicializa variavel movimento
	// pode ir de [2, 30], controlado pelas teclas '+' e '-'
	movimento = 2.0f;
	
	// inicializa variavel angulo com 0 angulo padrao de 60
	// pode ser alterado com os numeros 1, 2, 3, 4, 5, 6
	angulo = 60;

	// Define tamanho da janela
	largura = 640;
	altura = 480;

	// rotacao inicializa como nula
	rotX = 0.;
	rotY = 0;
	rotZ = 0;

	// posicao da camera no centro (0, 0, 0)
	cameraX = 0;
	cameraY = 0;
	
	if(VER_3D)
		cameraZ = 10.0f;
	else
		cameraZ = 0.0f;

	gluLookAt(cameraX, cameraY, cameraZ, 1,0,0, 0,0,1);
	
	glutReshapeWindow(largura, altura);
}


// --------------------------------------------
// DESENHA CUBO RGB
// --------------------------------------------
// Função que desenha um cubo cujas cores dos vértices
// mostram como é o espaço RGB
// os valores passados como red, green e blue pintarão o cubo com cores similares a essa
// mas para os lados ficarem diferente, a cor varia um pouco
// os paramentros var, var2 e var3 e para alterar os quadrantes
// pois altera a posição relativa de impressão
void DesenhaCuboRGB(float var, float var2, float var3, float red, float green, float blue) {
  	
  	// Desenha um ponto no centro para referencia da origem x, y, z
  	glColor3f(1.0f, 1.0f, 1.0f);		// branco
	glPointSize(5);		// tamanho do ponto
	glBegin(GL_POINTS);
		glVertex2i(0, 0);		// ponto q indicara o centro  - não é para aparecer, só para teste
	glEnd();

    // Desenhas as linhas das "bordas" do cubo
    // Usando uma adaptação que fiz do código do exemplo
	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);	// frontal
		glVertex3f(1.0+var, -1.0+var2, 1.0+var3);
        glVertex3f(-1.0+var, -1.0+var2, 1.0+var3);
        glVertex3f(-1.0+var, 1.0+var2, 1.0+var3);
        glVertex3f(1.0+var, 1.0+var2, 1.0+var3);					
	glEnd();
	glBegin(GL_LINE_LOOP);	//  posterior
		glVertex3f(1.0+var, 1.0+var2, -1.0+var3);
		glVertex3f(1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, -1.0+var2, -1.0+var3); 
		glVertex3f(-1.0+var, 1.0+var2, -1.0+var3);
	glEnd();
	glBegin(GL_LINES);	//  laterais
		glVertex3f(-1.0+var, 1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, 1.0+var2, 1.0+var3); 
		glVertex3f(-1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, -1.0+var2, 1.0+var3);     
		glVertex3f(1.0+var, 1.0+var2, -1.0+var3);
		glVertex3f(1.0+var, 1.0+var2, 1.0+var3); 
		glVertex3f(1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(1.0+var, -1.0+var2, 1.0+var3);  
	glEnd();
 
 
	// Desenha as faces do cubo preenchidas
	float cCor = 0.5f;   // coeficiente da cor  - irá varia a cor entre os lados
	// ira criar um cubo com lados de diferentes cores proxima a cor passada

	glBegin(GL_QUADS);
		// Face frontal
		glColor3f((float) red/2,(float) green/2, (float) blue/2);
        glVertex3f(1.0+var, 1.0+var2, 1.0+var3);
        glVertex3f(-1.0+var, 1.0+var2, 1.0+var3);
        glVertex3f(-1.0+var, -1.0+var2, 1.0+var3);
        glVertex3f(1.0+var, -1.0+var2, 1.0+var3);                                         					
	    // Face posterior
		glColor3f((float) red/2  + cCor,(float) green/2, (float) blue/2);	
		glVertex3f(1.0+var, 1.0+var2, -1.0+var3);
		glVertex3f(1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, 1.0+var2, -1.0+var3);
	    
	    // Face lateral esquerda
		glColor3f((float)red/2, (float)green, (float)blue/2);  
		glVertex3f(-1.0+var, 1.0+var2, 1.0+var3);
		glVertex3f(-1.0+var, 1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, -1.0+var2, 1.0+var3);

	    // Face lateral direita
		glColor3f((float)red, (float)green, (float)blue);	 
		glVertex3f(1.0+var, 1.0+var2, 1.0+var3); 
		glVertex3f(1.0+var, -1.0+var2, 1.0+var3); 
		glVertex3f(1.0+var, -1.0+var2, -1.0+var3);
		glVertex3f(1.0+var, 1.0+var2, -1.0+var3);
	    // Face superior  
		glColor3f((float) red/2,(float) green/2, (float) blue/2+cCor);
        glVertex3f(-1.0+var, 1.0+var2, -1.0+var3);
		glVertex3f(-1.0+var, 1.0+var2, 1.0+var3); 
		glVertex3f(1.0+var, 1.0+var2, 1.0+var3);
		glVertex3f(1.0+var, 1.0+var2, -1.0+var3);
	    // Face inferior

		glColor3f((float) red/2  + cCor,(float) green/2+cCor, (float) blue/2+cCor);
		glVertex3f(-1.0+var, -1.0+var2, -1.0+var3); 
		glVertex3f(1.0+var, -1.0+var2, -1.0+var3);  
		glVertex3f(1.0+var, -1.0+var2, 1.0+var3); 
		glVertex3f(-1.0+var, -1.0+var2, 1.0+var3);
	glEnd();
}

void moveCamera(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// https://www.opengl.org/sdk/docs/man2/xhtml/gluLookAt.xml
	// camera posicionada no ponto dado (0,0,0 - origem)
	gluLookAt(cameraX, cameraY, cameraZ, // cameraX, cameraY, cameraZ -> Especifica o ponot onde ta a camera
    			1, 0, 0, 				 // 1, 0, 0 - > Especifica a posicao do ponto de referencia
    			0, 0, 1); 				 // Especifica o vetor de direcao "up". -- no caso z é o "up"
    

	// https://www.opengl.org/sdk/docs/man2/xhtml/glRotate.xml
	glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
	glRotatef(rotZ, 0, 0, 1);
}

// --------------------------------------------
// AJUSTA DISPLAY
// --------------------------------------------
// Ajusta a view apos apertar uma tecla pra mover a camera
// ou em caso de redimensionamento de tela
void ajustaDisplay(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
	gluPerspective(angulo, // angulo na direcao y
					w/h,   // aspecto
					0.1,   // Distancia até o ponto mais prox (sempre positiva)
					100);  // Distancia até o ponto mais distante (sempre positiva)

	// move a camera
	moveCamera();
}


// --------------------------------------------
// DISPLAY
// --------------------------------------------
void Display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);  

	// imprime os grids
	if(GRID) {	
		glBegin(GL_LINES);


			// mais azul
			glColor3f(0.5f, 0.5f, 0.8f);	// red, green, blue
			// plano XY
			for(int i=-10;i<=10;++i) {
				glVertex3f(i, 10, 0);
				glVertex3f(i, -10, 0);

				glVertex3f(10,i,0);
				glVertex3f(-10,i,0);
			}


			// mais verde
			glColor3f(0.5f, 0.8f, 0.5f);	// red, green, blue
			// plano XZ
			for(int i=-10;i<=10;++i) {
				glVertex3f(i, 0, 10);
				glVertex3f(i, 0, -10);

				glVertex3f(10,0,i);
				glVertex3f(-10,0,i);
			}



			// mais vermelho
			glColor3f(0.8f, 0.5f, 0.5f);		// red, green, blue
			// plano YZ
			for(int i=-10;i<=10;++i) {
				glVertex3f(0, i, 10);
				glVertex3f(0, i, -10);

				glVertex3f(0,10,i);
				glVertex3f(0,-10,i);
			}

		glEnd();
	}
	
	// Funcao adaptada do código de exemplo do lab
	// imprimer os 8 cubos em seus respectivos quadrantes
	DesenhaCuboRGB(5.0, 5.0, 5.0, 1.0, 0.0, 0.0);		// vermelho


	DesenhaCuboRGB(-5.0, 5.0, 5.0, 0.0, 1.0, 0.0);		// verde
	DesenhaCuboRGB(5.0, -5.0, 5.0, 0.0, 0.0, 1.0);		// azul
	DesenhaCuboRGB(5.0, 5.0, -5.0, 1.0, 1.0, 0.0);		// vermelho + verde

	DesenhaCuboRGB(-5.0, -5.0, 5.0, 1.0, 0.0, 1.0);		// vermelho + azul
	DesenhaCuboRGB(-5.0, 5.0, -5.0, 0.0, 1.0, 1.0);		// verde + azul
	DesenhaCuboRGB(5.0, -5.0, -5.0, 1.0, 1.0, 1.0);		// branco

	DesenhaCuboRGB(-5.0, -5.0, -5.0, 0.5, 0.5, 0.5);	// cinza	

	glutSwapBuffers();
}


// --------------------------------------------
// RESHAPE
// --------------------------------------------
void Reshape(GLsizei w, GLsizei h){
	if (h == 0)	 		//evitar div 0
        h = 1;

    glViewport(0, 0, w, h); //dimensoes viewport
    
	ajustaDisplay(w, h);
}

	 
// --------------------------------------------
// LE TECLA
// --------------------------------------------
// Le tecla do teclado
void leTecla(unsigned char key, int x, int y){
	// case insensitive(pode ser maisculo ou minusculo)
	switch (key){
		case 27: 		    // esc
			exit(0);
		break;
		
		case 'w':			// cima
            rotY += movimento;
            break;

        case 's':			// baixo
            rotY -= movimento;
        	break;

        case 'a':			// esquerda
            rotZ -= movimento;
            break;

        case 'd':			// direita
            rotZ += movimento;
            break;
       
        case 'q':
        	rotX += movimento;		// prof aumenta
        	break;

         case 'e':
        	rotX -= movimento;		// prof diminui
        	break;
        case 'r':		// R de restart
        	Init();			
        	break;

        case 'f':
	       if(!fullscreen){
	        	glutFullScreen();
	        	fullscreen = 1;
	    	} else if(fullscreen){
	        	glutReshapeWindow(largura, altura);
	        	glutPositionWindow(0,0);
	        	fullscreen = 0;
	    	}
        	break;
        
        case 'W':			// up
            rotY += movimento;
            break;

        case 'S':			// down
            rotY -= movimento;
        	break;

        case 'A':			// left
            rotZ -= movimento;
            break;

        case 'D':			// right
            rotZ += movimento;
            break;
       
        case 'Q':
        	rotX += movimento;
        	break;

        case 'E':
        	rotX -= movimento;
        	break;
        
        case 'R':		// R de restart
        	Init();			
        	break;
  		
  		case 'F':
	       if(!fullscreen){
	        	glutFullScreen();
	        	fullscreen = 1;
	    	} else if(fullscreen){
	        	glutReshapeWindow(largura, altura);
	        	glutPositionWindow(0,0);
	        	fullscreen = 0;
	    	}
        	break;
        case '+':
        	// evita de ficar mto alto o valor de movimento
        	if(movimento < 30.0f) {
  					movimento += (float)1.0f;
					if(DEV)	printf("mov(+):%f\n", movimento);
        	} else {
        		if(DEV)	printf("why so fast?\n", movimento);
        	}
        	break;
        case '-':
        	// evita um valor mto baixo para movimento
        	if(movimento > 1.0f) {
        		movimento -= (float)1.0f;
        		if(DEV)	printf("mov(-s):%f\n", movimento);
        	} else {
        		if(DEV)	printf("why so slow?\n", movimento);
        	}

        	break;

        case '1':
        	angulo = 15;
        	if(DEV) printf("a:%f\n", angulo);
        	break;

        case '2':
        	angulo = 30;
        	if(DEV) printf("a:%f\n", angulo);
        	break;

        case '3':
        	angulo = 45;
        	if(DEV) printf("a:%f\n", angulo);
        	break;

        case '4':
        	angulo = 60;
        	if(DEV) printf("a:%f\n", angulo);
        	break;
        	
        case '5':
        	angulo = 90;
        	if(DEV) printf("a:%f\n", angulo);
        	break;

         case '6':
        	angulo = 120;
        	if(DEV) printf("a:%f\n", angulo);
        	break;

       	default:
        	break;

    }
    
    ajustaDisplay(largura, altura);
	glutPostRedisplay();
}


// --------------------------------------------
// MAIN
// --------------------------------------------
int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

	glutInitWindowSize(largura, altura);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Camera na origem");


	// Imprime a tela
	glutDisplayFunc(Display);

	// Reajusta o view em caso de minimizar ou resize na tela 
	glutReshapeFunc(Reshape);
	
	// Função que verifica se o mouse click foi precionada
	//glutMouseFunc(Mouse);
	
	// Função que verifica se o movimento mouse foi precionada
	//glutMotionFunc(Motion);
	
	// Função que verifica se alguma tecla foi precionada
	glutKeyboardFunc(leTecla);

	Init();

	glutMainLoop();

	return 0;
}












