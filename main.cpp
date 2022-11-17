#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;


    QFile file("C:\\Users\\jayso\\OneDrive\\Documents\\GreenBrainApp\\assets\\stylesheets\\SpyBot.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet { QLatin1String(file.readAll()) };
    //setup stylesheet
    app.setStyleSheet(styleSheet);



    w.show();

    return app.exec();
}
