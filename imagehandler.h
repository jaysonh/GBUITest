#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QMainWindow>
#include <QDebug>

#include <string>
#include <vector>
#include <filesystem>

using namespace std;

class ImageHandler
{
public:

    ImageHandler();

    void      loadImages( const string & folderPath );
    QPixmap & getImage  ( const int    & indx );
    int       getNumImages();

private:

    bool checkFileExtension( const string & extension );

    string defaultFolder = "C:\\Users\\jayso\\OneDrive\\Documents\\GreenBrainApp\\assets\\images";

    vector <QPixmap> imageSequence;
    vector <string>  allowedFileTypes = {".jpg", ".png"};
};

#endif // IMAGEHANDLER_H
