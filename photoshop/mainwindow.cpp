#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    cv::Mat src = cv::imread(fileName.toStdString());

    double width = src.cols;
    double height = src.rows;
    cv::resize(src,src,cv::Size(width/1.5,height/1.5));
    this->img = src.clone();
    cv::imshow("picture",this->img);
}

void MainWindow::on_Brightness_valueChanged(int value)
{
    cv::Mat dst;
    dst = this->img.clone();
    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                if(this->img.at<cv::Vec3b>(i,j)[k] + value > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->img.at<cv::Vec3b>(i,j)[k] + value < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                    dst.at<cv::Vec3b>(i,j)[k] = this->img.at<cv::Vec3b>(i,j)[k] + value;
            }
        }
    }

    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}

void MainWindow::on_B_bar_valueChanged(int value)
{
    cv::Mat dst;

    QVector<int> colorval(3);
    colorval[0] = ui->B_bar->value();
    colorval[1] = ui->G_bar->value();
    colorval[2] = ui->R_bar->value();

    dst = this->img.clone();

    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                if(this->img.at<cv::Vec3b>(i,j)[k] + colorval[k] > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->img.at<cv::Vec3b>(i,j)[k] + colorval[k] < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                    dst.at<cv::Vec3b>(i,j)[k] = this->img.at<cv::Vec3b>(i,j)[k] + colorval[k];
            }
        }
    }
    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}

void MainWindow::on_G_bar_valueChanged(int value)
{
    cv::Mat dst;

    QVector<int> colorval(3);
    colorval[0] = ui->B_bar->value();
    colorval[1] = ui->G_bar->value();
    colorval[2] = ui->R_bar->value();

    dst = this->img.clone();

    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                if(this->img.at<cv::Vec3b>(i,j)[k] + colorval[k] > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->img.at<cv::Vec3b>(i,j)[k] + colorval[k] < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                    dst.at<cv::Vec3b>(i,j)[k] = this->img.at<cv::Vec3b>(i,j)[k] + colorval[k];
            }
        }
    }
    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}

void MainWindow::on_R_bar_valueChanged(int value)
{
    cv::Mat dst;

    QVector<int> colorval(3);
    colorval[0] = ui->B_bar->value();
    colorval[1] = ui->G_bar->value();
    colorval[2] = ui->R_bar->value();

    dst = this->img.clone();

    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                if(this->img.at<cv::Vec3b>(i,j)[k] + colorval[k] > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->img.at<cv::Vec3b>(i,j)[k] + colorval[k] < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                    dst.at<cv::Vec3b>(i,j)[k] = this->img.at<cv::Vec3b>(i,j)[k] + colorval[k];
            }
        }
    }
    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}

void MainWindow::on_Grayscale_clicked()
{
    cv::Mat dst;
    dst.create(cv::Size(this->img.cols,this->img.rows),CV_8UC1);

    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            dst.at<uchar>(i, j) = (this->img.at<cv::Vec3b>(i,j)[0] + this->img.at<cv::Vec3b>(i,j)[1] + this->img.at<cv::Vec3b>(i,j)[2])/3;
        }
    }
    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}

void MainWindow::on_Blur_clicked()
{
    cv::Mat dst;

    for(int i = 1 ; i < this->img.rows - 1 ; i++)
    {
        for(int j = 1 ; j < this->img.cols - 1 ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                dst.at<cv::Vec3b>(i, j)[k] = (this->img.at<cv::Vec3b>(i-1,j-1)[k]
                                        + this->img.at<cv::Vec3b>(i-1,j)[k]
                                        + this->img.at<cv::Vec3b>(i,j-1)[k]
                                        + this->img.at<cv::Vec3b>(i,j)[k]
                                        + this->img.at<cv::Vec3b>(i+1,j)[k]
                                        + this->img.at<cv::Vec3b>(i,j+1)[k]
                                        + this->img.at<cv::Vec3b>(i+1,j+1)[k]
                                        + this->img.at<cv::Vec3b>(i-1,j+1)[k]
                                        + this->img.at<cv::Vec3b>(i+1,j-1)[k])/9;
            }

        }
    }
    cv::imshow("picture", dst);
    this->img_save = dst.clone();
}


void MainWindow::on_Save_clicked()
{
    imwrite("picture", this->img_save);
    this->img = this->img_save.clone();
}

void MainWindow::on_Negative_clicked()
{
    cv::Mat dst;

    dst = this->img.clone();

    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                dst.at<cv::Vec3b>(i,j)[k] = 255 - this->img.at<cv::Vec3b>(i,j)[k];
            }
        }
    }
    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}

void MainWindow::on_Contrast_valueChanged(int value)
{
    float contrast_val = value / 10.0;
    cv::Mat dst;
    dst = this->img.clone();
    for(int i = 0 ; i < this->img.rows ; i++)
    {
        for(int j = 0 ; j < this->img.cols ; j++)
        {
            for(int k = 0 ; k < this->img.channels() ; k++)
            {
                if(this->img.at<cv::Vec3b>(i,j)[k] * contrast_val > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->img.at<cv::Vec3b>(i,j)[k] * contrast_val < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                    dst.at<cv::Vec3b>(i,j)[k] = this->img.at<cv::Vec3b>(i,j)[k] * contrast_val ;
            }
        }
    }

    cv::imshow("picture",dst);
    this->img_save = dst.clone();
}
