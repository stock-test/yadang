#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QRect& rect = QRect(), QWidget *parent = nullptr);
    ~MainWindow();

    void setPictureSize(const QRect& rect);
    void updatePicture();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *mouseEvent);

private:
    Ui::MainWindow *ui;
    QLabel* mLabel;
    bool keyMovePressed;
    QPoint startPos;
    QPixmap* mPixmap;
    int degree;
};

#endif // MAINWINDOW_H
