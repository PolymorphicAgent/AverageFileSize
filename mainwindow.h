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
    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    double m_avgSizeBytes;

    double calculateAverageFileSize(const QString &rootPath, qint64 &totalSize, int &fileCount);
    double getAverageFileSize(const QString &rootPath);
    void updateResult();
};
#endif // MAINWINDOW_H
