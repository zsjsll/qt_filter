#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("123123123123");
	ui->label->installEventFilter(this);
	//this->connect(timer, SIGNAL(timeout()), this, SLOT(watch()));
	//timer->start(100);
	
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::watch()
{
	auto time = QTime::currentTime();
	auto Qtime =time.toString("hh:mm:ss");
	ui->label->setText(Qtime);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    /*
 if (obj == textEdit) {
          if (event->type() == QEvent::KeyPress) {
              QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
              qDebug() << "Ate key press" << keyEvent->key();
              return true;
          } else {
              return false;
          }
      } else {
          // pass the event on to the parent class
          return QMainWindow::eventFilter(obj, event);
      }
*/
    if(obj==ui->label){
        if(event->type()==QEvent::MouseButtonPress){
			this->watch();
            return true;

        }else{
            return false;
        }
    }else{
        return QMainWindow::eventFilter(obj,event);
    }
}
