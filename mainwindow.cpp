#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileInfoList>
#include <QMessageBox>
#include <QFileInfo>
#include <QString>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_avgSizeBytes(0.0)
{
    ui->setupUi(this);
    this->setWindowTitle("Average File Size Calculator");
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [this](){updateResult();});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
    QDir root = ui->lineEdit->text();
    if(ui->lineEdit->text() == "" || !root.exists()){
        QMessageBox::critical(this, "Error", "The requested directory does not exist.");
        return;
    }

    m_avgSizeBytes = getAverageFileSize(ui->lineEdit->text());

    updateResult();
}

void MainWindow::updateResult(){
    if(m_avgSizeBytes == 0.0) ui->result->setText("0");
    else if(ui->comboBox->currentText() == "B")
        ui->result->setText(QString::number(m_avgSizeBytes)+" Bytes");
    else if(ui->comboBox->currentText() == "KB")
        ui->result->setText(QString::number(m_avgSizeBytes*0.001)+" Kilobytes");
    else if(ui->comboBox->currentText() == "MB")
        ui->result->setText(QString::number(m_avgSizeBytes*0.000001)+" Megabytes");
    else if(ui->comboBox->currentText() == "GB")
        ui->result->setText(QString::number(m_avgSizeBytes*0.000000001)+" Gigabytes");
}

// Recursive helper funcion
double MainWindow::calculateAverageFileSize(const QString &rootPath, qint64 &totalSize, int &fileCount) {
    QDir dir(rootPath);
    if (!dir.exists()) {
        return 0.0; // Return 0 if the directory doesn't exist
    }

    QFileInfoList entries = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            // Recursive call for subdirectories
            calculateAverageFileSize(entry.absoluteFilePath(), totalSize, fileCount);
        } else if (entry.isFile()) {
            totalSize += entry.size();
            fileCount++;
        }
    }

    return fileCount > 0 ? static_cast<double>(totalSize) / fileCount : 0.0;
}

// Returns the average file size of all files in the root directory, in Bytes
double MainWindow::getAverageFileSize(const QString &rootPath) {
    qint64 totalSize = 0;
    int fileCount = 0;
    return calculateAverageFileSize(rootPath, totalSize, fileCount);
}
