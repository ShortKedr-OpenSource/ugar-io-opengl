//#define GLEW_STATIC
//#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include "game.h"
#include "GLBasics.h"
#include "ugarplayer.h"
#include "GameWindow.h"

int main(int argc, char** argv) {
	GameWindow::Initialize(argc, argv);
	return 0;
}