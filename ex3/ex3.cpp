// Lucas Vieira Costa Nicolau 		8517101
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
 
 
// Variрveis para controles de navegacao
GLfloat Px, Py;
GLsizei largura=300, altura=200;
GLdouble ortholeft = -1, orthoright = 1, orthobot=-1, orthotop = 1;
bool mouse_over = false;
bool mouse_click = false;
bool mouse_up = false;
 
float but_x1 = 90.0f, but_x2 = 50.0f;
float but_y1 = -17.5f, but_y2 = -10.0f;
float seg_but_y1 = -19.5f, seg_but_y2 = -12.0f;
int x_start = 100;
bool segunda_pos = false;

// Funcao callback para eventos de botшes do mouse
void gerencia_mouse(int button, int state, int mouse_x, int mouse_y) {
    	
    if(button == GLUT_LEFT_BUTTON) {
 		if(state==GLUT_DOWN) {    
 			mouse_up = false; 
            if(segunda_pos) {
                if((mouse_x > x_start &&  mouse_x < (x_start+80)) &&  (mouse_y > 160  && mouse_y < 198)) {
                  mouse_click = true;
                } else {
                  mouse_click = false;
				  segunda_pos = false;
                }
            } else {

              if((mouse_x > x_start &&  mouse_x < (x_start+80)) &&  (mouse_y > 152  && mouse_y < 190)) {
                  mouse_click = true;
                  mouse_up = false; 
            
              } else {
                mouse_click = false;
              }
            }
        }


    	if(state==GLUT_UP) {
    	    
    	    if(segunda_pos) {
                if((mouse_x > x_start &&  mouse_x < (x_start+80)) &&  (mouse_y > 160  && mouse_y < 198)) {
                  mouse_up = true; 
                } else {
                  mouse_up = false;
                }
            } else {

              if((mouse_x > x_start &&  mouse_x < (x_start+80)) &&  (mouse_y > 152  && mouse_y < 190)) {
                  mouse_up = true;
              } else {
                mouse_up = false;
              }
            }
    	}

    }

    glutPostRedisplay();
}

void gerencia_movimentacao(int mouse_x, int mouse_y) {
       
      //printf("mouse_x = %d, mouse_y = %d", mouse_x, mouse_y);
      if(segunda_pos) {
            if((mouse_x > x_start &&  mouse_x < (x_start+80)) &&  (mouse_y > 160  && mouse_y < 198)) {
              mouse_over = true; 
            } else {
              mouse_over = false;
            }
      } else {
            if((mouse_x > x_start &&  mouse_x < (x_start+80)) &&  (mouse_y > 152  && mouse_y < 190)) {
                mouse_over = true; 
            } else {
              mouse_over = false;
            }
      }

      glutPostRedisplay();
}

// Funcao desenha uma casa
void desenha_casa(){ 

 
   
}

// Funcao desenha um botao
void desenha_botao() {
  //Define a cor branca para o fundo 
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  //Pinta a tela com a cor de fundo
  glClear(GL_COLOR_BUFFER_BIT);

  

  // se tiver sido clicado o botao
  if(mouse_click) {
    if(segunda_pos) {
      segunda_pos = false;      // ativa o modo pra imprimir a segunda pos do botao + a casinha
    } else {
       segunda_pos = true;      // ativa o modo pra imprimir a posicao normal do botao sem a casinha
    }
    mouse_click = false;   // aguarda o prox clique
   }

    if(segunda_pos) {

     
    //desenha a casinha qndo ocorrer o mouse up
   	if(mouse_up) {
       // Casinha
    
      //Define a cor vermelha
      glColor3f(1.0f, 0.0f, 0.0f);  
      
       //TELHADO
      //Desenha um triangulo
      glBegin(GL_TRIANGLES);
         glVertex2f(38.0f, 5.0f);
         glVertex2f(66.6f, 16.5f);
         glVertex2f(95.0f, 5.0f);
      glEnd();
       // FIM DO TELHADO

      //Define a cor azul
      glColor3f(0.0f, 0.0f, 1.0f);  
      
      // PAREDE
      //Desenha um retangulo  
      glBegin(GL_QUADS);
          glVertex2f(90.0f, -10.0f);
          glVertex2f(90.0f, 5.0f);
          glVertex2f(43.0f, 5.0f);
          glVertex2f(43.0f, -10.0f);                  
      glEnd();
      // FIM DA PAREDE

      // PORTA
      //Define a cor branco
      glColor3f(1.0f, 1.0f, 1.0f);  
       
      //Desenha um retangulo  
      glBegin(GL_QUADS);
          glVertex2f(50.0f, -9.5f);
          glVertex2f(50.0f, -1.0f);
          glVertex2f(65.0f, -1.0f);
          glVertex2f(65.0f, -9.5f);                  
      glEnd();
      // FIM DA PORTA

      //JANELA
      //Desenha um retangulo  
      glBegin(GL_QUADS);
          glVertex2f(79.5f, -2.0f);
          glVertex2f(79.5f, 0.0f);
          glVertex2f(75.0f, 0.0f);
          glVertex2f(75.0f, -2.0f);                  
      glEnd();


      //Desenha um retangulo  
      glBegin(GL_QUADS);
          glVertex2f(85.0f, -2.0f);
          glVertex2f(85.0f, 0.0f);
          glVertex2f(80.5f, 0.0f);
          glVertex2f(80.5f, -2.0f);                  
      glEnd();

        //Desenha um retangulo  
      glBegin(GL_QUADS);
          glVertex2f(79.5f, -4.5f);
          glVertex2f(79.5f, -2.5f);
          glVertex2f(75.0f, -2.5f);
          glVertex2f(75.0f, -4.5f);                  
      glEnd();

       //Desenha um retangulo  
      glBegin(GL_QUADS);
          glVertex2f(85.0f, -4.5f);
          glVertex2f(85.0f, -2.5f);
          glVertex2f(80.5f, -2.5f);
          glVertex2f(80.5f, -4.5f);                  
      glEnd();
  		//FIM DA JANELA
       // Fim da casinha 

  	}


  	//Define a cor azul escuro como padrao
  	glColor3f(0.0f, 0.0f, 0.5f);  

    // muda a cor com o mouse over
    if(mouse_over == true) {

      //Define a cor azul claro
      glColor3f(0.0f, 0.0f, 1.0f);  
    }
      //Desenha um retangulo  
    glBegin(GL_QUADS);
        glVertex2f(but_x1, seg_but_y1);
        glVertex2f(but_x1, seg_but_y2);
        glVertex2f(but_x2, seg_but_y2);
        glVertex2f(but_x2, seg_but_y1);                  
    glEnd();
      
    } else {
  	//Define a cor azul escuro como padrao
  	glColor3f(0.0f, 0.0f, 0.5f);  

    // muda a cor com o mouse over
     if(mouse_over == true) {
        //Define a cor azul claro
         glColor3f(0.0f, 0.0f, 1.0f);  
      }

      //Desenha um botao
      glBegin(GL_QUADS);
          glVertex2f(but_x1, but_y1);
          glVertex2f(but_x1, but_y2);
          glVertex2f(but_x2, but_y2);
          glVertex2f(but_x2, but_y1);                  
      glEnd();
      // fim do botao
  }

  glFlush();    
}


 
// Programa Principal 
int main(int argc, char* argv[]) {
     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 200);
    glutCreateWindow("Exercicio 3");
    //Define a janela de selecao: esquerda, direita, baixo, cima
    gluOrtho2D(0, 150, -20, 20);  
     
    glutDisplayFunc(desenha_botao);
    glutMouseFunc(gerencia_mouse);
 
    glutMotionFunc(gerencia_movimentacao);
    glutPassiveMotionFunc(gerencia_movimentacao);
     
     
    glutMainLoop();

}