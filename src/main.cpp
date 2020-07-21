#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char *argv[]) {
    int imgNum = argc - 1;

    vector<Mat3b> imgs;

    // read images
    int sizeX = 0;
    int sizeY = 0;
    for (int i = 0; i < imgNum; ++i)
    {
        Mat3b img = imread(argv[1+i]);
        imgs.push_back( img );
        sizeX += img.cols;
        if ( sizeY < img.rows )
        {
            sizeY = img.rows;
        }
    }

    // set canvas
    Mat3b canvas = Mat3b::zeros(sizeY, sizeX);
    sizeX = 0;
    for (int i = 0; i < imgNum; ++i)
    {
        const Mat3b &img = imgs[i];
        int xSta = sizeX;
        int xEnd = sizeX + img.cols;
        int ySta = 0;
        int yEnd = img.rows;
        Mat3b sub = canvas(Range(ySta, yEnd), Range(xSta, xEnd));
        img.copyTo( sub );

        sizeX += img.cols;
    }

    imwrite("out.png", canvas);

    return 0;
}