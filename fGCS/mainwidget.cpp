#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    styleIt();

    setupUi(this);

    connect(videoButton, SIGNAL(clicked()), this, SLOT(setVideoView()));
    connect(mapButton, SIGNAL(clicked()), this, SLOT(setMapView()));

    SystemParameters sParams;                             //sposob korzystania z uzupelnionego xml
    qDebug()<< sParams.getValue(QString("video/adress")); //

    video = new videoDecoder(this);
    connect(video,SIGNAL(frameRecieved(int)),this,SLOT(setGaugeValues(int)));

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

    createUpperLayout(Widget);

    stackWidget = new QStackedWidget(Widget);
    stackWidget->setObjectName(QStringLiteral("stackWidget"));  //  switching mode widget

    gridLayout->addWidget(stackWidget, 1, 0, 1, 1);

    createVideoView();
    createMapview();

    stackWidget->addWidget(view);
    stackWidget->addWidget(webView);

    retranslateUi(Widget);
}

// temporary solution, mode switch buttons will be shifted to each mode views
void mainWidget::createUpperLayout(QWidget *Widget)
{
    gridLayout = new QGridLayout(Widget);
    horizontalLayout = new QHBoxLayout();

    videoButton = new QPushButton(Widget);
    videoButton->setObjectName(QStringLiteral("videoButton"));//video mode switching button

    horizontalLayout->addWidget(videoButton);

    mapButton = new QPushButton(Widget);
    mapButton->setObjectName(QStringLiteral("mapButton"));// map mode switching button

    horizontalLayout->addWidget(mapButton);

    testButton = new QPushButton(Widget);
    testButton->setObjectName(QStringLiteral("testButton"));// button for testing

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
}

void mainWidget::createMapview()
{
    webView = new QWebView(stackWidget);                        //place for google maps
    webView->setObjectName(QStringLiteral("webView"));
    webView->setUrl(QUrl(QStringLiteral("about:blank")));
}

void mainWidget::createVideoView()
{
    view = new QGraphicsView(stackWidget);                      //place for camera view
    scene = new QGraphicsScene(this);
    view->setScene(scene);

    setLayout();

    createGauge();
    scene->addWidget(mAttitudeGauge);

    createConnections();
}

void mainWidget::setLayout()
{

}

void mainWidget::createConnections()
{
    connect(video,SIGNAL(frameRecieved(int)),this, SLOT(setGaugeValues(int)));
}

void mainWidget::setGaugeValues(int value)
{
    qDebug()<<value;
    mAttitudeNeedle->setCurrentValue(90-value);
    mAttMeter->setCurrentRoll(value);
}


void mainWidget::createGauge()
{
    mAttitudeGauge = new QcGaugeWidget;
    mAttitudeGauge->addBackground(99);
    QcBackgroundItem *bkg = mAttitudeGauge->addBackground(92);
    bkg->clearrColors();
    bkg->addColor(0.1,Qt::black);
    bkg->addColor(1.0,Qt::white);
    mAttMeter = mAttitudeGauge->addAttitudeMeter(88);

    mAttitudeNeedle = mAttitudeGauge->addNeedle(70);
    mAttitudeNeedle->setMinDegree(0);
    mAttitudeNeedle->setMaxDegree(180);
    mAttitudeNeedle->setValueRange(0,180);
    mAttitudeNeedle->setCurrentValue(90);
    mAttitudeNeedle->setColor(Qt::white);
    mAttitudeNeedle->setNeedle(QcNeedleItem::AttitudeMeterNeedle);
    mAttitudeGauge->addGlass(80);
   // ui->verticalLayout->addWidget(mAttitudeGauge);
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
    if (stackWidget->currentWidget() !=0) {
        stackWidget->currentWidget()->setSizePolicy(QSizePolicy::Ignored,
                                                    QSizePolicy::Ignored);
    }
    stackWidget->setCurrentIndex(idx);
    stackWidget->currentWidget()->setSizePolicy(QSizePolicy::Expanding,
                                                QSizePolicy::Expanding);
}

void mainWidget::setVideoView()
{
    changeCurrent(0);
}

void mainWidget::setMapView()
{
    changeCurrent(1);
}

void mainWidget::styleIt()
{

    this->setStyleSheet(QString::fromUtf8(
                            "QPushButton {\n"
                            "font-size: 24px;\n"
//                            "font: bold;\n"
                            "min-width: 35px;\n"
                            "min-height: 38px;\n"
                            "max-height: 38px;\n"
                            "max-width: 150px;\n"
                            "background-color: rgba(10, 10, 10, 50);\n"
                            //"qproperty-alignment: AlignLeft;\n"
                            "border: 2px solid #232;\n"
//                            /*"border-radius: 8px;\n"*/
                            "padding: 5px;\n"
                            "color: rgb(255, 255, 255);}\n" // kolor czcionki
                            "QPushButton:pressed {\n"
                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #555, stop: 0.6 #666, stop: 0.7 #777, stop:1 #888);}\n"
                            "GraphWidget {border: 3px solid #000;}\n"
                            "QLabel {\n"
                            "qproperty-alignment: AlignCenter;\n"
                            "font-size: 24px;\n"
//                            "font: bold;\n"
                            "color: rgb(255, 255, 255);}\n" // kolor czcionki
                            "min-width: 80px;\n"
                            "min-height: 48px;\n"
                            "max-width: 160px;\n"
                            "max-height: 48px;\n"
                            "background-color: rgba(10, 10, 10, 100);\n"
                            "border: 2px solid #444;\n"
//                            "border-radius: 8px;\n"
                            "padding: 5px;\n"
//                            "background: qlineargradient(x1:0, y0:0, x1:0, y1:1,stop:0 #222, stop: 0.6 #333, stop: 0.7 #444, stop:1 #555);\n"
                            "color: rgba(255, 255, 255, 0);}\n"

                            "QStackedWidget {background-color: rgba(10, 10, 10, 50);}\n"
                            "QGridLayout {padding: 0px;}\n"
                            "QHBoxLayout {padding: 0px;}\n"


                            ));
}
