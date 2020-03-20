#include "mainwindow_with_tray.h"
#include <QCloseEvent>

mainWindow_with_tray::mainWindow_with_tray(QWidget  *parent) : QMainWindow(parent)
{
    trayicon = new QSystemTrayIcon(this);

    QIcon icon("./icon.png");
    trayicon->setIcon(icon);

    trayiconMenu = new QMenu(this);
    quitAction = new QAction(this);
    quitAction->setText(tr("退出"));

    trayiconMenu->addAction(quitAction);
    trayiconMenu->addSeparator();


    trayicon->setToolTip(tr("ezcloud"));
    trayicon->setContextMenu(trayiconMenu);
    trayicon->showMessage(tr("hahaya"), tr("托盘测试2"), QSystemTrayIcon::Information, 5000);

    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(on_action_quit_triggered()));

    trayicon->show();
}

void mainWindow_with_tray::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        //单击
        case QSystemTrayIcon::Trigger:
             this->setWindowState(Qt::WindowActive);
             this->show();
             break;
        //双击
        case QSystemTrayIcon::DoubleClick:
            //恢复窗口显示
            this->setWindowState(Qt::WindowActive);
            this->show();
            break;
        default:
            break;
    }
}
void mainWindow_with_tray::closeEvent(QCloseEvent *event)
{
    if(trayicon->isVisible())
    {
        hide();
        event->ignore();
    }
}
void mainWindow_with_tray::on_action_quit_triggered()
{
    trayicon->hide();
    close();
}
