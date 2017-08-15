// LUCAS VIEIRA COSTA NICOLAU
// 8517101
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

// booleano que determina se foi fixado o ponto p0 e p1
// para poder mover os vetores v0 e v1
int fixo;

// matriz que contem o p0, p1, v0 e v1
// a terceira coluna é o z (que é nulo)
float Geometry[4][3] = { 
	{ -5, 0, 0},	//	p0
	{ 5, 0, 0},		// p1
	{ 5, -1, 0},	//	v0
	{5, 1, 0}		//	v1
};

unsigned int QUALIDADE=20;		// numero de pontos a serem tracados, qnto mais melhor(menos ira ficar mais serrilhado)


// Funcao que reajusta a tela caso mude de tamanho
// ou seja minimizada
//	w - largura | h - altura
void reshape(int w, int h) {
	// Previne divisao por zero
	if (h==0)
		h=1;

	// Seta a regiao de desenho da viewport
	glViewport(0 ,0 ,w ,h);

	// seta a matriz de projecao
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// adota a perpectiva para a situcao
	// se quiser aumentar a tela para que os pontos fiquem mais distantes só mudar de 45 para 90
	gluPerspective(45 ,(float)w/h, 0.1, 100);


	// volta pra a matriz do modelo para mexer com os objetos
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


// Funcao que controla o mouse
// Sera usada para avisar que é para usar as teclas direcionais
void myMouse(int button, int state, int x, int y) {
	
	// se o mouse for clicado avisa que é para usar as teclas direcionais, pois estava tendo problema para identificar um ponto
	// sendo que a hitbox do ponto não estava funcionando apropriadamente
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	    if(button == GLUT_LEFT_BUTTON) {
	    	printf("Use a,s,d,w and i,j,k,l como teclas direcionais e f para fixar os pontos p0 e p1\n");
		}
  	}
}


// Funcao de desenho
// Responsavel por desenhar a curva e os pontos
void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	// seta a posicao que sera usada como referencial
	gluLookAt(	1,10,30,	
				0,5,0,	
				0,1,0);	

	glColor3f(0.5,0.5,1);
	glBegin(GL_LINE_STRIP);


	for(int i=0; i!=QUALIDADE; i++) {

		float u = (float)i/(QUALIDADE-1);

		// resultado da multiplicacao de matrizes
		float c0 =  2*u*u*u - 3*u*u + 1;	// coeficiente 0
		float c1 = -2*u*u*u + 3*u*u;	// coeficiente 1
		float c2 = u*u*u - 2*u*u + u;	// coeficiente 2
		float c3 = u*u*u - u*u;	// coeficiente 3


		// calcula os pontos x e y baseado nos coeficientes e pontos dados
		float x = c0*Geometry[0][0] + 
				  c1*Geometry[1][0] + 
				  c2*Geometry[2][0] + 
				  c3*Geometry[3][0] ;

		float y = c0*Geometry[0][1] + 
				  c1*Geometry[1][1] + 
				  c2*Geometry[2][1] + 
				  c3*Geometry[3][1] ;

		float z = 0;	// nao tera valor de z

		// especifica o ponto
		glVertex3f(x, y, z);
	}
	
	glEnd();

	// desenha o p0 e p1
	glColor3f(0,1, 0.5);
	glPointSize(3);
	glBegin(GL_POINTS);
		glVertex3fv(Geometry[0]);
		glVertex3fv(Geometry[1]);
	glEnd();


	glColor3f(0.5,1,0.5);
	glPushMatrix();
		

		// desenha a linha do v0
		glTranslatef(Geometry[0][0],Geometry[0][1],Geometry[0][2]);
		glBegin(GL_LINES);
			glVertex3f( 0,0,0 );
			glVertex3fv( Geometry[2] );
		glEnd();

		// desenha o ponto final do vetor v0
		glColor3f(0,1,0.5);
		glPointSize(3);
		glBegin(GL_POINTS);
			glVertex3fv( Geometry[2] );
		glEnd();




	glPopMatrix();

	glPushMatrix();


		// desenha a linha do v1
		glTranslatef(Geometry[1][0],Geometry[1][1],Geometry[1][2]);
		glBegin(GL_LINES);
			glVertex3f( 0,0,0 );
			glVertex3fv( Geometry[3] );
		glEnd();

		// desenha o ponto final do vetor v1
		glColor3f(0,1,0.5);
		glPointSize(3);
		glBegin(GL_POINTS);
			glVertex3fv( Geometry[3] );
		glEnd();
	glPopMatrix();

	// troca os buffers
	glutSwapBuffers();
}

// Funcao que sera executada no fim do programa
void myExit() {
	printf("That's all folks!\n");
}

// inicializa as variaveis
void init() {
	// seta pontos p0 e p1 livres para mover até o usuário fixar
	fixo = 0;
}

// Le as teclas pressionadas durante o programa
// a, s, d, w - direcionais do p0 e v0
// j, k, l, i - direcionais do p1 e v1
// f - para fixar o p0 e p1 e assim mexer só no v0 e v1
void leTecla(unsigned char key,int,int) {
	switch(key) {


	// move o ponto 1
	case 'a':
		if(!fixo)
			Geometry[0][0]--;
		else
			Geometry[2][0]--;
		break;

	case 's':
		if(!fixo)
			Geometry[0][1]--;	
		else
			Geometry[2][1]--;

		break;

	case 'd':
		if(!fixo)
			Geometry[0][0]++;
		else
			Geometry[2][0]++;

		break;

	case 'w':
		if(!fixo)
			Geometry[0][1]++;
		else
			Geometry[2][1]++;

		break;

	// move o ponto 2
	case 'j':
		if(!fixo)
			Geometry[1][0]--;
		else
			Geometry[3][0]--;

		break;

	case 'k':
		if(!fixo)
			Geometry[1][1]--;
		else
			Geometry[3][1]--;	

		break;

	case 'l':
		if(!fixo)
			Geometry[1][0]++;
		else
			Geometry[3][0]++;

		break;

	case 'i':
		if(!fixo)
			Geometry[1][1]++;
		else
			Geometry[3][1]++;

		break;

	// fixa o p0 e p1
	case 'f':
		fixo = 1;
	break;

	default:
		break;
	}

	glutPostRedisplay();
}

int main(int argc,char** argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(640,480);

	// Cria a janela com o titulo passado como parametro
	glutCreateWindow("Curva de Hermite");

	// Funcao de display da nossa função
	glutDisplayFunc(draw);

	// Funcao de mouse da nossa funcao
    glutMouseFunc(myMouse);

	// Funcao que realiza a mudanca de tamanho na tela, se for necessaria
	glutReshapeFunc(reshape);

	// Função que verifica se alguma tecla foi precionada
	glutKeyboardFunc(leTecla);
	
	// inicializa as variaveis que o programa precisa
	init();

	// Roda uma funcao de saida, pra realizar algo caso seja necessario
	atexit(myExit);

	glutMainLoop();
	return 0;
}
