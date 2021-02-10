#include "raycasting.h"
#include "ui_raycasting.h"

RayCasting::RayCasting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RayCasting)
{
    ui->setupUi(this);
}

RayCasting::~RayCasting()
{
    delete ui;
}

void RayCasting::on_pushButton_clicked()
{
    QImage image =  QImage(this->sizeX, this->sizeY, QImage::Format_RGB32 );
    Camera *c = new Camera(W,H,-d,sizeX,sizeY);
    Point Po(0,0,0);

    for( int i=0; i<this->sizeX; i++)
    {

        float Yi= (c->h/2)-(c->DY/2)-(i*c->DY);

        for( int j=0; j<sizeY; j++)
        {
//            image.setPixel(j,i, qRgb(this->Bg->R*255,this->Bg->G*255,this->Bg->B*255));

            float Xj = (-c->w/2)+(c->DX/2)+(j*c->DX);
            Point Pij(Xj,Yi,c->d);
            Pij.normalize();

            ColorRGB print = this->scene_ref->Ray_Pix_Ilm(Po, Pij);
            image.setPixel( j, i, qRgb(print.R*255, print.G*255, print.B*255));
        }
    }

    QGraphicsScene *graphic = new QGraphicsScene( this );
    graphic->addPixmap( QPixmap::fromImage( image ) );
    ui->graphicsView->setScene(graphic);


}

void RayCasting::setScene(Scene *S){
    this->scene_ref=S;
}



void RayCasting::on_w_valueChanged(double arg1)
{
    this->W=arg1;
}

void RayCasting::on_h_valueChanged(double arg1)
{
    this->H=arg1;
}

void RayCasting::on_d_valueChanged(double arg1)
{
    this->d=arg1;
}

void RayCasting::on_sizeX_valueChanged(double arg1)
{
    this->sizeX=arg1;
}

void RayCasting::on_sizeY_valueChanged(double arg1)
{
    this->sizeY=arg1;
}


void RayCasting::on_bgR_sliderMoved(int position)
{
    this->scene_ref->Bg->R=(float)position/255;
}

void RayCasting::on_bgG_sliderMoved(int action)
{
    this->scene_ref->Bg->G=(float)action/255;
}

void RayCasting::on_bgB_sliderMoved(int action)
{
    this->scene_ref->Bg->B=(float)action/255;
}

void RayCasting::on_iaR_sliderMoved(int action)
{
    this->scene_ref->Amb->R=(float)action/255;
}

void RayCasting::on_iaG_sliderMoved(int action)
{
    this->scene_ref->Amb->G=(float)action/255;
}

void RayCasting::on_iaB_sliderMoved(int action)
{
    this->scene_ref->Amb->B=(float)action/255;
}

