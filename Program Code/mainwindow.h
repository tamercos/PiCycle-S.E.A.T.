#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libSonar.h"
#include <QBoxLayout>
#include <QWidget>
#include <QScrollBar>
#include <QCheckBox>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    ~MainWindow();

    Sonar sonar;

void timerEvent( QTimerEvent * );

public slots:

    void setVibInput1(bool vibInput1);
    void setVibInput2(bool vibInput2);
    void setVibInput3(bool vibInput3);
    void setDetectRange(int detectRange);

private:

    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QScrollBar *scrollbar;
    QLabel *sblabel;

    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    int detectRange = 10;
    bool vibInput1 = TRUE;
    bool vibInput2 = TRUE;
    bool vibInput3 = TRUE;
};

#endif // MAINWINDOW_H
