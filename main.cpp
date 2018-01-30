#ifdef _WIN32
#  include <windows.h>
#endif
#include <stdio.h>
#ifdef _WIN32
#  define snprintf _snprintf
#endif
#include <string.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "highgui.h"

using namespace cv;

void draw() {

	//设置清屏色
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//设置颜色，红色
	glColor3f(1.0f, 0.0f, 0.0f);
	//设置绘图时的坐标系统
	glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
	//开始渲染
	glBegin(GL_POLYGON);
	//设置多边形的4个顶点
	glVertex3f(0.25f, 0.25f, 0.0f);
	glVertex3f(0.75f, 0.25f, 0.0f);
	glVertex3f(0.75f, 0.75f, 0.0f);
	glVertex3f(0.25f, 0.75f, 0.0f);
	//结束渲染
	glEnd();
	//强制刷新缓冲区，保证绘制命令被执行
	glFlush();

}

void Display()
{

}

void display()
{
	cv::Mat img;
	cv::VideoCapture webcam = cv::VideoCapture(0);
	webcam.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	webcam.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	if (!webcam.isOpened()){
		webcam.release();
		std::cerr << "Error during opening capture device!" << std::endl;
		return;
	}
	cv::namedWindow( "output", 0 );
	
	for(;;){

		webcam >> img; 

		int c = waitKey(10);
		if( (c & 255) == 27 ) {
			std::cout << "Exiting ..." << std::endl;
			break;
		}
		//some control
		switch( (char)c ){
			case 'i':
				//g_trackerInitialized = false;
				//g_topLeft = cv::Point(0,0);
				//g_botRight_tmp = cv::Point(0,0);
				break;
			default:;

		}
		cv::imshow("output", img);
	}
}

int main(int argc, const char* argv[]) {
	//初始化GLUT库
	glutInit(&argc, (char**)argv);
	//创建一个窗口并制定窗口名
	glutCreateWindow("HelloWorld");
	//注册一个绘图函数，操作系统在必要时刻就会对窗体进行重新绘制操作
	glutDisplayFunc(Display);
	//glutReshapeFunc(Reshape);
	//glutVisibilityFunc(Visibility);
	//glutKeyboardFunc(Keyboard);
	
	//进入GLUT事件处理循环，让所有的与“事件”有关的函数调用无限循环(永生循环)
	glutMainLoop();

	return (0);
	return 0;
}



