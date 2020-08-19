#include "demo.h"
#include "ui_demo.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/features2d.hpp>
#include<opencv2/core/types.hpp>
#include"QtConcurrent/QtConcurrent"
#include"iostream"
#include"QFileDialog"
using namespace std;
using namespace cv;

Demo::Demo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Demo)
{
    ui->setupUi(this);
}

Demo::~Demo()
{
    delete ui;
}


void Demo::on_PBLoad_clicked()
{
    try {


//Reading the image
       QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open Image"), "C:\\Users\\user\\Desktop", tr("Image Files (*.png *.jpg *.bmp)"));
Mat img=imread(fileName.toStdString());
//namedWindow( "Display window-Normal" , WINDOW_NORMAL | WINDOW_KEEPRATIO);
Size size(800,800);
Mat im;
cv::resize(img,im,size);
namedWindow( "Display window-Normal" , WINDOW_NORMAL | WINDOW_KEEPRATIO);
imshow("Display window-Normal", im );

//Thresholding
Mat thrsImg;
 QString temp=ui->te_threshold->toPlainText();
 double thr=temp.toLong();
 QString temp1=ui->textEditMax->toPlainText();
 double MaxVal=temp1.toLong();
threshold(img, thrsImg,thr,MaxVal,THRESH_BINARY );

//Finding the difference in the image
Mat diffImg;
absdiff(thrsImg, img, diffImg);
//cvtColor(img,img,COLOR_RGB2GRAY);
//equalizeHist( img, diffImg );

//Edge detection and marking
        Mat canny_output;
        QString temp2=ui->textEditTHR1->toPlainText();
        double thr1=temp2.toLong();
        QString temp3=ui->textEdit_THR2->toPlainText();
        double thr2=temp3.toLong();
        RNG rng(12345);
           Canny( diffImg, canny_output, thr1, thr2 );
           vector<vector<Point> > contours;
           findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE );
           vector<vector<Point> > contours_poly( contours.size() );
           vector<Rect> boundRect( contours.size() );
           vector<Point2f>centers( contours.size() );
           vector<float>radius( contours.size() );
           for( size_t i = 0; i < contours.size(); i++ )
           {
               approxPolyDP( contours[i], contours_poly[i], 3, true );
               boundRect[i] = boundingRect( contours_poly[i] );
               minEnclosingCircle( contours_poly[i], centers[i], radius[i] );
           }
           Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
           for( size_t i = 0; i< contours.size(); i++ )
           {
               Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
              // drawContours( drawing, contours_poly, (int)i, color );
               rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2 );
               //circle( drawing, centers[i], (int)radius[i], color, 2 );
           }

        namedWindow( "Display window-Processed" , WINDOW_NORMAL | WINDOW_KEEPRATIO);
        imshow("Display window-Processed",drawing );


    } catch (Exception ex) {

    }

}
