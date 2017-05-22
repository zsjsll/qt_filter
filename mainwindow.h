#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QEvent>
#include  <QMouseEvent>
#include  <QString>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
	QTimer *timer = new QTimer(this);

public slots:
	void watch();
	
protected:
    bool eventFilter(QObject *, QEvent *);

};

#endif // MAINWINDOW_H
