#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QFiledialog>

#include <opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Load_clicked();

    void on_Brightness_valueChanged(int value);

    void on_R_bar_valueChanged(int value);

    void on_G_bar_valueChanged(int value);

    void on_B_bar_valueChanged(int value);

    void on_Grayscale_clicked();

    void on_Blur_clicked();

    void on_Save_clicked();

    void on_Negative_clicked();

    void on_Contrast_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    cv::Mat img;
    cv::Mat img_save;
};

#endif // MAINWINDOW_H
