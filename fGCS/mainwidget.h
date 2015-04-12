#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QSizePolicy>
#include <QWebView>
#include <QtWidgets/QGraphicsView>
#include <QDebug>

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();

    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *videoButton;
    QPushButton *mapButton;
    QPushButton *testButton;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QStackedWidget *stackWidget;

    QWebView *webView;
    QGraphicsView *view;
    QGraphicsScene *scene;

    void setupUi(QWidget *Widget);
    void retranslateUi(QWidget *Widget);
    void changeCurrent(int idx);

public slots:
    void setMapView();
    void setVideoView();
};

#endif // MAINWIDGET_H
