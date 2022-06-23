# Computacao-Grafica

Este repositório foi criado para colocar em prática os conhecimentos básicos em computação gráfica com a criação de objetos em 2D e 3D utilizando o OpenGL.

## Guia de Instalação - OpenGL, GLUT e GLEW (Linux)

1. Instale a OpenGL Utility Toolkit (GLUT) por meio do comando: sudo apt-get install freeglut3-dev.
2. Instale o pacote Miscellaneous Mesa GL utilities por meio do comando: sudo apt-get install mesa-utils
3. Instale as bibliotecas X11 miscellaneous utility library e X11 Input extension library por meio do comando: sudo apt-get install libxmu-dev libxi-dev
4. Após completar as instalações, compile o código com o seguinte comando: g++ -o exemplo.o exemplo.cpp -lglut -lGLU -lGL -lm
5. Execute o programa com o comando ./exemplo.
