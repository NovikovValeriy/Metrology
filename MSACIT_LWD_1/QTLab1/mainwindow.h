#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <regex>
#include <unordered_set>
#include <cmath>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_openFileButton_clicked();

    void on_calculateButton_clicked();

private:
    QString fileAdress, line;
    std::vector<std::map<std::string, int>> parse();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
