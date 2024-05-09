#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRegister_clicked();

    void on_btnForgotPassword_clicked();

    void on_btnSignIn_clicked();

    void on_btnSignOut_ProfileInfo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
