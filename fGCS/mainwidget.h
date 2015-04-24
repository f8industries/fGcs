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
#include "systemparameters.h"
#include "videodecoder.h"
#include "qcgaugewidget.h"

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

    void createUpperLayout(QWidget *Widget);
    void createVideoView();
    void createMapview();

    void styleIt();

    videoDecoder *video;

    void setLayout();

    void createGauge();

    QcGaugeWidget * mAttitudeGauge;
    QcNeedleItem * mAttitudeNeedle;
    QcAttitudeMeter *mAttMeter;

    void createConnections();


public slots:
    void setMapView();
    void setVideoView();
    void setGaugeValues(int i);
};

#endif // MAINWIDGET_H
