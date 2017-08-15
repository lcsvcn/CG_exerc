// Lucas Vieira Costa Nicolau 		8517101
#include <GL/glut.h>
 
// Funcao desenha uma casa
void desenha_casa(){ 
  //Define a cor branca para o fundo 
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  //Pinta a tela com a cor de fundo
  glClear(GL_COLOR_BUFFER_BIT);
 
  //Define a cor vermelha
  glColor3f(1.0f, 0.0f, 0.0f);  
   
   //TELHADO
  //Desenha um triangulo
  glBegin(GL_TRIANGLES);
     glVertex2f(38.0f, 5.0f);
     glVertex2f(66.6f, 16.5f);
     glVertex2f(95.0f, 5.0f);
  glEnd();
 

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

  glFlush();     
}
 
// Programa Principal 
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 200);
    glutCreateWindow("Casinha");
    //Define a janela de selecao: esquerda, direita, baixo, cima
    gluOrtho2D(0, 150, -20, 20);
     
    glutDisplayFunc(desenha_casa);
     
 
     
     
    glutMainLoop();
}