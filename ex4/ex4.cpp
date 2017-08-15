// Lucas Vieira Costa Nicolau 		8517101
#include <GL/glut.h> 
#include <unistd.h>


// LAB 2
// desenha casinha antes de flipar
void desenha_casinha() {


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //Define a cor branca para o fundo 
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  //Pinta a tela com a cor de fundo
  glClear(GL_COLOR_BUFFER_BIT);


    // centralizar a casinha
    glTranslatef(-75.0f, 0.0f, 0.0f);

    // depois do flip
    //desenha casinha
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


// LAB 2
// usa as transformacoes necessarias e desenha a casinha
void funcao_flip_casinha() {

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //Define a cor branca para o fundo 
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  //Pinta a tela com a cor de fundo
  glClear(GL_COLOR_BUFFER_BIT);



    //desenha a casinha normal, antes de flipar
    // esta sera flipada entorno do proprio eixo(centro da casinha)
    //desenha_casinha();


    // gira a casinha em 180 graus em torno do proprio eixo, não se movimenta
    // como o triangulo do lab2 

    // ------------------------------------------------

    
    glLoadIdentity();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-58.0f, 0.0f, 0.0f);

    //-------------------------------------------------


    // depois do flip
    //desenha casinha
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
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 400);
    glutCreateWindow("Rotacionar casinha");

    // desenha a casinha dps de rotacionada
    glutDisplayFunc(funcao_flip_casinha);
    
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    //Define a janela de selecao: esquerda, direita, baixo, cima
    gluOrtho2D(-100, 100, -100, 100);
     
     
 
    
    glutMainLoop();
}