#include "Student_status_information.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Student_status_information w;
	w.setWindowTitle(QStringLiteral("ѧ������ϵͳ"));
	w.resize(800, 600);
	w.show();
	return a.exec();
}
