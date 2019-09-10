#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>

MainWindow::MainWindow(const QRect& rect, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    keyMovePressed(false),
    degree(90)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QWidget* mainWidget = new QWidget(this);
    QVBoxLayout* root = new QVBoxLayout(mainWidget);
    mainWidget->setLayout(root);
    mLabel = new QLabel("test");
    root->addWidget(mLabel);
    setCentralWidget(mainWidget);
    setGeometry(rect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePicture()
{
    mPixmap = new QPixmap("/tmp/screen-shot.png");
    mLabel->setPixmap(*mPixmap);
}

void MainWindow::setPictureSize(const QRect &rect)
{
    setGeometry(rect);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        qApp->exit();
    } else if (event->key() == Qt::Key_Space) {
        QMatrix matrix;
        matrix.rotate(degree);
        mLabel->setPixmap(mPixmap->transformed(matrix, Qt::SmoothTransformation));
        degree += 90;
        if (degree % 360 == 0) {
            degree = 0;
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton) {
        //move 用的是 globalPos, 所以，需要要取出本窗口的(0,0)对应的全局坐标
        //pos()返回的是父窗口中位置，不能直接用
        startPos = mouseEvent->globalPos() - mapToGlobal(QPoint(0,0));

        keyMovePressed = true;
    }

    mouseEvent->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
    keyMovePressed = false;
    mouseEvent->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    if (keyMovePressed) {
        move(mouseEvent->globalPos() - startPos);
    }

    mouseEvent->accept();
}

