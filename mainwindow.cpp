#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->currentImgDisplay->setPixmap( imgHandler.getImage(0) );
    ui->frameDisplayLabel->setText(QString("latest image"));
    ui->currentImgDisplay->setScaledContents(true);

    ui->checkBox->setChecked(true);
    ui->prevFrameSlider->setVisible( false );

    ui->prevFrameSlider->setRange( 1, imgHandler.getNumImages() - 1 );

    // Set button icons
    QPixmap buttonImg0("C:\\Users\\jayso\\OneDrive\\Documents\\GreenBrainApp\\assets\\button_imgs\\icons8-home-50.png");
    QIcon ButtonIcon0(buttonImg0);
    ui->pushButton0->setIcon(ButtonIcon0);
    ui->pushButton0->setIconSize(buttonImg0.rect().size());


    QPixmap buttonImg1("C:\\Users\\jayso\\OneDrive\\Documents\\GreenBrainApp\\assets\\button_imgs\\icons8-check-all-50.png");
    QIcon ButtonIcon1(buttonImg0);
    ui->pushButton1->setIcon(ButtonIcon1);
    ui->pushButton1->setIconSize(buttonImg1.rect().size());

    QPixmap buttonImg2("C:\\Users\\jayso\\OneDrive\\Documents\\GreenBrainApp\\assets\\button_imgs\\icons8-settings-50.png");
    QIcon ButtonIcon2(buttonImg2);
    ui->pushButton2->setIcon(ButtonIcon2);
    ui->pushButton2->setIconSize(buttonImg2.rect().size());

    QPixmap buttonImg3("C:\\Users\\jayso\\OneDrive\\Documents\\GreenBrainApp\\assets\\button_imgs\\icons8-user-male-50.png");
    QIcon ButtonIcon3(buttonImg3);
    ui->pushButton3->setIcon(ButtonIcon3);
    ui->pushButton3->setIconSize(buttonImg3.rect().size());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    bool status = arg1 == 0 ? true : false;

    // hide/show previous frame select slider
    ui->prevFrameSlider->setVisible( status );

    // if selected then show the latest image
    if( arg1 == 1 )
    {
        ui->currentImgDisplay->setPixmap( imgHandler.getImage(0) );
        ui->frameDisplayLabel->setText(QString("latest image"));
    }
}


void MainWindow::on_prevFrameSlider_sliderMoved(int position)
{
    // Change the image displayed on the app
    QPixmap imgPm = imgHandler.getImage( position );
    ui->currentImgDisplay->setPixmap( imgPm );
    ui->frameDisplayLabel->setText(QString("image: ") + QString::number(position));

}

