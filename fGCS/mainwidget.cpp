#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    connect(videoButton, SIGNAL(clicked()), this, SLOT(setVideoView()));
    connect(mapButton, SIGNAL(clicked()), this, SLOT(setMapView()));
}

mainWidget::~mainWidget()
{

}

void mainWidget::setupUi(QWidget *Widget)
{
    if (Widget->objectName().isEmpty())
                Widget->setObjectName(QStringLiteral("fGcs"));

    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
    Widget->setSizePolicy(sizePolicy);
    Widget->setMinimumSize(QSize(900, 600));
    gridLayout = new QGridLayout(Widget);
    horizontalLayout = new QHBoxLayout();

    videoButton = new QPushButton(Widget);
    videoButton->setObjectName(QStringLiteral("videoButton"));

    horizontalLayout->addWidget(videoButton);

    mapButton = new QPushButton(Widget);
    mapButton->setObjectName(QStringLiteral("mapButton"));

    horizontalLayout->addWidget(mapButton);

    testButton = new QPushButton(Widget);
    testButton->setObjectName(QStringLiteral("testButton"));

    horizontalLayout->addWidget(testButton);

    label_4 = new QLabel(Widget);
    label_4->setObjectName(QStringLiteral("label_4"));

    horizontalLayout->addWidget(label_4);

    label_3 = new QLabel(Widget);
    label_3->setObjectName(QStringLiteral("label_3"));

    horizontalLayout->addWidget(label_3);

    label_2 = new QLabel(Widget);
    label_2->setObjectName(QStringLiteral("label_2"));

    horizontalLayout->addWidget(label_2);

    label = new QLabel(Widget);
    label->setObjectName(QStringLiteral("label"));

    horizontalLayout->addWidget(label);

    gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

    stackWidget = new QStackedWidget(Widget);
    stackWidget->setObjectName(QStringLiteral("stackWidget"));

    gridLayout->addWidget(stackWidget, 1, 0, 1, 1);

    retranslateUi(Widget);
}

void mainWidget::retranslateUi(QWidget *Widget)
{
    Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
    videoButton->setText(QApplication::translate("Widget", "videoButton", 0));
    mapButton->setText(QApplication::translate("Widget", "mapButton", 0));
    testButton->setText(QApplication::translate("Widget", "testButton", 0));
    label_4->setText(QApplication::translate("Widget", "wifi rssi", 0));
    label_3->setText(QApplication::translate("Widget", "rc rssi", 0));
    label_2->setText(QApplication::translate("Widget", "sats", 0));
    label->setText(QApplication::translate("Widget", "battery", 0));
}


void mainWidget::changeCurrent(int idx)
{
    qDebug()<<"change to "<<idx;
//    if (stackWidget->currentWidget() !=0) {
//        stackWidget->currentWidget()->setSizePolicy(QSizePolicy::Ignored,
//                                                    QSizePolicy::Ignored);
//    }
//    stackWidget->setCurrentIndex(idx);
//    stackWidget->currentWidget()->setSizePolicy(QSizePolicy::Expanding,
//                                                QSizePolicy::Expanding);
    //adjustSize();
}

void mainWidget::setVideoView()
{
    changeCurrent(0);
    qDebug()<<"videoView";
}

void mainWidget::setMapView()
{
    changeCurrent(1);
    qDebug()<<"mapView";
}
