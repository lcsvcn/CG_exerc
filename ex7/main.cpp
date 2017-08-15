// Lucas Viera Costa Nicolau
// 8517101	
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "renderingEsfera.cpp"
#define DEV 1
#define N 250		// valores bons para teste : 20, 50, 100, 250, 500, 1000
					// valores menores(ex. 50) mostram as faces, arestas e vertices porém tem performance muito superior aos maiores (ex. 500)
					// tanto que valores como 1000 chegam a bugar o renderizador

#define SHADE_MODEL 1	// se 0 -- flat , outro valor Gouraud



/*Definição da superfície*/
GLfloat x_min = 0.0, x_max = 2*(3.14159265359), y_min = 0.0, y_max = (3.14159265359), R = 30.0;
typedef vector<vector<GLCell> > MALHA;
MALHA malha;
Rendering renObj(N, x_min, x_max, y_min, y_max, R, true);

// Variáveis para controles de navegação
GLfloat angle, fAspect;
GLfloat rotX, rotY, rotX_ini, rotY_ini;
GLfloat obsX, obsY, obsZ, obsX_ini, obsY_ini, obsZ_ini;
int x_ini,y_ini,bot;

// Propriedades do material
GLint especMaterial;
GLint emite = 0;
bool elipsoide;

// Cores difusa e emissiva
GLfloat cores[2][4] = {
	{ 0,1,0,1 },
	{ 0,1,0,1 }
};

// Função responsável por inicializar parâmetros e variáveis
void Inicializa (void) {   
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);  
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	if(SHADE_MODEL == 1) {
	   	// Habilita o modelo de colorização de Flat
	   	glShadeModel(GL_FLAT);
   	} else {
		// Habilita o modelo de colorização de Gouraud
		glShadeModel(GL_SMOOTH);
   	}
	// Inicializa a variável que especifica o ângulo da projeção
	// perspectiva
	angle = 45;
    
	// Inicializa as variáveis usadas para alterar a posição do 
	// observador virtual
	rotX = 0;
	rotY = 0;
	obsX = obsY = 0;
	obsZ = 150;    

	// Inicializa variáveis usadas para especificação do material
	especMaterial = 60;

	elipsoide = false;
}

// Função responsável pela especificação dos parâmetros de iluminação
void DefineIluminacao (void) {
	GLfloat luzAmbiente[4]={0.0,0.0,0.0,1.0}; 
	GLfloat luzDifusa[4]={1.0,1.0,1.0,1.0};	   // "cor" da fonte de luz 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={100.0, 100.0, 70.0, 1.0};
	GLfloat semCorEmissao[4]={0.0,0.0,0.0,1.0};

	GLfloat diffuse[] = {0.5f, 0.5f, 0.8f, 1.0f};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 

	// Define a refletância do material 
	glMaterialfv(GL_FRONT,GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,100);

	if (emite) {
		// Especifica a luz emitida pelo material
		glMaterialfv(GL_FRONT,GL_EMISSION,cores[1]);
	}
	else {
		glMaterialfv(GL_FRONT,GL_EMISSION,semCorEmissao);
	}

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );   
}

MALHA getMalha() {
	MALHA m = renObj.getMesh();

	if(!elipsoide) {
		glScalef(1.0,0.7,1.0);
		elipsoide = true;
	}
	
	return m;
}
// Função callback de redesenho da janela de visualização
void Desenha(void) {
	// Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	// Chama a função que especifica os parâmetros de iluminação
	DefineIluminacao();
    
	// Altera a cor do desenho para azul
	glColor3f(0.0f, 0.0f, 1.0f);
	
	malha = getMalha();

	for (int i = 1; i < (N+2) - 1; i++) {
		for (int j = 1; j < (N+2) - 1; j++) {
			
			glBegin(GL_TRIANGLE_STRIP);
				glNormal3f(malha[i][j].vetor_normal.x, malha[i][j].vetor_normal.y, malha[i][j].vetor_normal.z);
				glVertex3f(malha[i+1][j].ponto.x, malha[i+1][j].ponto.y, malha[i+1][j].ponto.z);
				glVertex3f(malha[i+1][j+1].ponto.x, malha[i+1][j+1].ponto.y, malha[i+1][j+1].ponto.z);
				glVertex3f(malha[i][j].ponto.x, malha[i][j].ponto.y, malha[i][j].ponto.z);
				glVertex3f(malha[i][j+1].ponto.x, malha[i][j+1].ponto.y, malha[i][j+1].ponto.z);
			glEnd();
    		}
		}
	

	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void) {
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Posiciona e orienta o observador
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void) {
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,1,500); 
	gluLookAt(0.0, 0.0, 20.0,
	          0.0, 0.0, 0.0,
			  0.0, 1.0, -1.0);

	PosicionaObservador();
}

// Função callback para tratar eventos de teclas especiais
void TeclasEspeciais (int tecla, int x, int y) {
	int redraw = 1;

	switch (tecla) {
		case GLUT_KEY_HOME:	
			elipsoide = false;
			if(angle>=10)  angle -=5;
		break;

		case GLUT_KEY_END:	
			elipsoide = false;
			if(angle<=150) angle +=5;
		break;
		
		default:
			elipsoide = true;
			redraw = 0;
		break;
	}


	EspecificaParametrosVisualizacao();
	
	if(redraw) {
		glutPostRedisplay();
	}
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);
 
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos de teclas normais
void Teclado (unsigned char key, int x, int y) {
	int redraw = 1;
	switch(key) {
		case 27:		// ESC
				exit(0);
		break;
		
		// alterna emite -- emite ou não a fonte de luz  (t)oggle
		case 't':
			elipsoide = true;	
			emite = !emite;
			if(DEV){
				if(emite) printf("--emitindo--\n"); else printf("-- não ta emitindo--\n"); 
			}
		break;
		


		// mexe no coeficiente de red (RGB)
		case '1':
			elipsoide = true;	
			if (cores[emite][0]>0) cores[emite][0]-=0.1;
			if(DEV)
				printf("%f\n", cores[emite][0]);
		break;
		
		case '2':
			elipsoide = true;
			if (cores[emite][0]<1.0) cores[emite][0]+=0.1;	
			if(DEV)
				printf("%f\n", cores[emite][0]);		
		break;
		

		// mexe no coeficiente de green (RGB)
		case '3':
			elipsoide = true;	
			if (cores[emite][1]>0) cores[emite][1]-=0.1;
			if(DEV)
				printf("%f\n", cores[emite][1]);
		break;
		
		case '4':
			elipsoide = true;
			if (cores[emite][1]<1.0) cores[emite][1]+=0.1;
			if(DEV)
				printf("%f\n", cores[emite][1]);
		break;
		
		// mexe no coeficiente de blue (RGB)
		case '5':	
			elipsoide = true;
			if (cores[emite][2]>0) cores[emite][2]-=0.1;
			if(DEV)
				printf("%f\n", cores[emite][2]);			
		break;
		
		case '6':
			elipsoide = true;
			if (cores[emite][2]<1.0) cores[emite][2]+=0.1;
			if(DEV)
				printf("%f\n", cores[emite][2]);
		break;
		
		// mexe na especificação do material
			case '7':
			if (especMaterial>0){
				especMaterial--;
				if(DEV)
					printf("%d\n", especMaterial);
			}
			elipsoide = true;
		break;

		case '8':
			if (especMaterial<128){ 
				especMaterial++;
				if(DEV)
					printf("%d\n", especMaterial);
			}
			elipsoide = true;	
		break;
		
		default:
			redraw = 0;
		break;
	}

	if(redraw) {		// se alguma especificação mudou da redraw
		glutPostRedisplay();
	}
}

// Função callback para eventos de botões do mouse
void GerenciaMouse(int button, int state, int x, int y) {
	if(state==GLUT_DOWN){
		// Salva os parâmetros atuais
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
		elipsoide = false;
	}
		
	else bot = -1;
}

// Função callback para eventos de movimento do mouse
#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	10.0
void GerenciaMovim(int x, int y){
	// Botão esquerdo ?
	if(bot==GLUT_LEFT_BUTTON) {
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica ângulos
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;

		elipsoide = false;
	} else if(bot==GLUT_RIGHT_BUTTON) {	// Botão direito
		// Calcula diferença
		int deltaz = y_ini - y;
		// E modifica distância do observador
		obsZ = obsZ_ini + deltaz/SENS_OBS;

		elipsoide = false;

	} else if(bot==GLUT_MIDDLE_BUTTON) { // Botão do meio
		// Calcula diferenças
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		// E modifica posições
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;

		elipsoide = false;

	}

	PosicionaObservador();
	glutPostRedisplay();
}



// Programa Principal 
int main(int argc, char **argv) {
  glutInit(&argc, argv);
	// Define o modo de operação da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
 
	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(5,5); 
    
	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450); 
 
	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Exercicio 7");
 
	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc(Desenha);
  	
  	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Registra a função callback para tratamento das teclas especiais
	glutSpecialFunc (TeclasEspeciais);

	// Registra a função callback para eventos de botões do mouse	
	glutMouseFunc(GerenciaMouse);
	 
	// Registra a função callback para eventos de movimento do mouse	
	glutMotionFunc(GerenciaMovim);

	// Chama a função responsável por fazer as inicializações 
	Inicializa();
 
	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();
 
	return 0;
}
