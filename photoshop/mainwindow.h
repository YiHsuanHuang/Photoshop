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

private:
    Ui::MainWindow *ui;
    cv::Mat img;
};

#endif // MAINWINDOW_H
