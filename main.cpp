//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"
#include <iostream>
#include <list>
 using namespace std;

int x=0;
int y=0;
int xr=100;
int yr=100;
int zx=0;
int buttonssquare=1;
int bbs;
int cvet=TX_WHITE;
int cvetobv=TX_GRAY;
int obv=7;
int textdrw=0;

struct sixtangle
{
POINT line[6];//;={{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

};
sixtangle sixtangle1(int x , int y, int xr, int yr)
{
int xpoint = (xr-x)/2;
int ypoint = (yr-y)/3;
sixtangle A;
    A.line[0].x=x;
        A.line[0].y=ypoint+y;
            A.line[1].x=xpoint+x;
                A.line[1].y=y;
                    A.line[2].x=xr;
                        A.line[2].y=ypoint+y;
                            A.line[3].x=xr;
                                A.line[3].y=ypoint*2+y;
                                    A.line[4].x=xpoint+x;
                                        A.line[4].y=yr;
                                            A.line[5].x=x;
                                                A.line[5].y=ypoint*2+y;
//A.s = {{x, ypoint}, {xpoint, y}, {xr, ypoint}, {xr, ypoint*2}, {xpoint, yr}, {x, ypoint*2}};
return A;
};

class print //����� ��� ��������� �����
{
private:

 int x2, y2;

public:

  int draw=0;
  int x=0, y=0;         //������� ����� ����
  int xr=1, yr=1;       //������ ������ ����
  int cvet=TX_WHITE;    //�������� ���� ��������  txEllipse (100, 100, 300, 200);
  int cvetobv=TX_GRAY;  //���� ������� ��������
  int obv=7;            //������ ������� ��������
  int figure=3;         //����� ������ ����� ���������� 0-�������, 1-�����, 2-�������, 3-�����

string name;

int drawsquare()
{
    if (txMouseButtons()==1)
     {

      draw=1;
      x=txMouseX();
      y=txMouseY();
     }


     while(txMouseButtons() == 1)
        {

        txBegin();
        xr=txMouseX();
        yr=txMouseY();
       // txSetFillColor(cvet);
        //txSetColor(cvetobv, obv);

        switch ( figure )
            {
            case 2: txRectangle(x, y, xr, yr); break;
            case 3: txEllipse(x, y, xr, yr); break;
            case 4: sixtangle A; A=sixtangle1(x, y, xr, yr); txPolygon(A.line, 6); break;
            case 5: txLine(x, y, xr, yr); break;
            default :;
            }


        txSleep(1);
        txEnd();

        }


            //txSetFillColor(cvet);
            //txSetColor(cvetobv, obv);

  switch (figure)
            {
            case 0: txEllipse(x, y, xr, yr); break;
            case 2: txRectangle(x, y, xr, yr); break;
            case 3: txEllipse(x, y, xr, yr); break;
            case 4: sixtangle A; A=sixtangle1(x, y, xr, yr); txPolygon(A.line, 6);
            case 5: txLine(x, y, xr, yr); break;
            default :;
            }



}

    int draws()
    {

        switch (figure)
            {
            case 2: txRectangle(x, y, xr, yr); break;
            case 3: txEllipse(x, y, xr, yr); break;
            case 4: sixtangle A; A=sixtangle1(x, y, xr, yr); txPolygon(A.line, 6); break;
            case 5: txLine(x, y, xr, yr); break;
            default :;
            }


    }

};

class text
{
private:

public:

int k=1;
char c;
string s;
int x, y;


   string textdraw()
{
COLORREF CVT=txGetFillColor();
    x=txMouseX();
    y=txMouseY();
    while (k!=13)
    {
        //txBegin();
        k=getch();
        c=k;
        if ( c == '\b')
            {
            s.erase(s.length()-1);
            }
        else s=s+c;
                txTextOut(x, y, s.c_str());
               // txEnd();
                txSleep(200);
                txSetFillColor(TX_WHITE);
                txClear();

    }
    k=0;
    txSetFillColor(CVT);
        return s;
}
int draw()
{
txTextOut(x, y, s.c_str());


 }
};

class sizeSlider
{
private:
int smw,smh, slx, sly;

public:
  int begPX=20, begPY=20, endPX=230, endPY=43, result;


     sizeSlider(int sWidth, int sHeight, int slX, int slY)
        {
        smw=sWidth;
        smh=sHeight;
        slx=slX;
        sly=slY;
        }

    int drawSizeSlider()
            {
        txSetFillColor(TX_BLACK);
        txLine(smw, smw, smh-10, smh+20);//1 �����
        txLine(smw, smw+10, smh+200, smh);//2 �����
        txLine(smw+210, smw, smh+200, smh+20);//3 �����
        }

    int mainSlider()
            {
            txSetFillColor(TX_BLACK);
            txLine(slx,sly,slx,sly+10);
                if (txMouseX() > begPX && txMouseY() > begPY && txMouseX() < endPX && txMouseY() < endPY)
                    if (txMouseButtons() == 1)
                            slx=txMouseX();
                                 result=(slx-begPX)/5;
                                    std::stringstream ss;
                                    ss << result;
                                    std::string s = ss.str();
                                        txTextOut(220, 53, s.c_str());
                                            return result;

            }

};

class button
{
private:

int x,y,w,h;

public:
COLORREF color=TX_WHITE;


string pic;
int picterVisible=0;
int picterW, picterH;

HDC picter;



    button(int x1, int y1, int width, int height)
    {
    x=x1;
    y=y1;
    w=width;
    h=height;
    }

        int drawButton()
        {
        txSetFillColor(color);
        txRectangle(x, y, x+w, y+h);

        if (picterVisible)
                    {
                    txBitBlt (txDC(), x, y, picterW, picterH, picter);
                    }

        }

        int click()
        {
        if (txMouseButtons() == 1)
        if (txMouseX() > x && txMouseY() > y && txMouseX() < x+w && txMouseY() < y+h)
        return 1;
        }


        int clickr()
        {
        if (txMouseButtons() == 2)
        if (txMouseX() > x && txMouseY() > y && txMouseX() < x+w && txMouseY() < y+h)
        return 2;
        }

        int SetColor(COLORREF C)
                {
                color=C;
                }



        int PicterAdd(string Pic, int picW, int picH)
                        {
                        picter = txLoadImage (Pic.c_str());

                        picterVisible=1;
                        picterW=picW;
                        picterH=picH;
                        }

};

struct  colormenuCvet
{COLORREF cvt1;
COLORREF cvt2;} ;

colormenuCvet colormenu()
{
colormenuCvet x;

x.cvt1=TX_TRANSPARENT;
x.cvt2=TX_TRANSPARENT;

    button white(30,220,50,50);
        white.SetColor(TX_WHITE);
        white.drawButton();

          if (white.click())
            {
            x.cvt1=TX_WHITE;
            }

            if (white.clickr())
            {
             x.cvt2=TX_WHITE;
            }




            button black(100,220,50,50);
        black.SetColor(TX_BLACK);
        black.drawButton();

          if (black.click())
            {
            x.cvt1=TX_BLACK;
            }

            if (black.clickr())
            {
          x.cvt2=TX_BLACK;
            }


        button red(170,220,50,50);
        red.SetColor(TX_RED);
        red.drawButton();

          if (red.click())
            {
            x.cvt1=TX_RED;
            }

            if (red.clickr())
            {
            x.cvt2=TX_RED;
            }

            button yellow(30,290,50,50);
        yellow.SetColor(TX_YELLOW);
        yellow.drawButton();

          if (yellow.click())
            {
            x.cvt1=TX_YELLOW;
            }

            if (yellow.clickr())
            {
            x.cvt2=TX_YELLOW;
            }

             button blue(100,290,50,50);
        blue.SetColor(TX_BLUE);
        blue.drawButton();

          if (blue.click())
            {
            x.cvt1=TX_BLUE;
            }

            if (blue.clickr())
            {
            x.cvt2=TX_BLUE;
            }


            button green(170,290,50,50);
        green.SetColor(TX_GREEN);
        green.drawButton();

          if (green.click())
            {
            x.cvt1=TX_GREEN;
            }

            if (green.clickr())
            {
            x.cvt2=TX_GREEN;
            }

            button gray(30,360,50,50);
        gray.SetColor(TX_GRAY);
        gray.drawButton();

          if (gray.click())
            {
            x.cvt1=TX_GRAY;
            }

            if (gray.clickr())
            {
             x.cvt2=TX_GRAY;
            }

             button pink(100,360,50,50);
        pink.SetColor(TX_PINK);
        pink.drawButton();

          if (pink.click())
            {
            x.cvt1=TX_PINK;
            }

            if (pink.clickr())
            {
             x.cvt2=TX_PINK;
            }

            button cyan(170,360,50,50);
        cyan.SetColor(TX_CYAN);
        cyan.drawButton();

          if (cyan.click())
            {
            x.cvt1=TX_CYAN;
            }

            if (cyan.clickr())
            {
             x.cvt2=TX_CYAN;
            }


            return x;


}

class paintmenu
{
private:
int mw, mh, bw, bh;

public:

    paintmenu(int mWidth, int mHeight, int buttonsW, int buttonsH)
    {
    mw=mWidth;
    mh=mHeight;
    bw=buttonsW;
    bh=buttonsH;
    }

    int drawMenu()
        {
    txSetFillColor(TX_WHITE);
    txSetColor(TX_BLACK, 5);
    txRectangle(10,10,250,1000);
        }

};


int main()
        {

    txCreateWindow (1600, 1000);
    txSetColor (TX_WHITE);

     paintmenu menu(200,300,2,3); //���� ���� ���������� ���������
     button b1(30, 80, 50, 50); //�������(������)
     b1.PicterAdd("�����������.bmp",50,50);

     button b2(100, 80, 50, 50); //���� (������)
     b2.PicterAdd("��������.bmp",50,50);

     button b3(170, 80, 50, 50); //������������� �� ��� 666
     b3.PicterAdd("����������������.bmp",50,50);

     button b4(30, 900, 50, 50);
     b4.PicterAdd("�������.bmp",50,50);

     button b5(30, 150, 50, 50);
     b5.PicterAdd("�����������.bmp",50,50);

     button b6(100, 150, 50, 50);//����� ���� ����
     b6.PicterAdd("����.bmp",50,50);

    sizeSlider slider(20,30,25,30);
    print sq;//��������� ���
    text t1;
    int currentObject=2;//��� ������ �����
    int obvodka;



    list <print> qs;
    list <text> qt;


    while(1)
    {
        txSetFillColor(TX_WHITE);
        txClear();
        txSetColor(TX_GRAY,2);
        txSetFillColor(TX_GRAY);
        txRectangle(300+10,10+10,1900+10,1000+10);
        txSetFillColor(TX_WHITE);
        txSetColor(TX_BLACK,1);
        txRectangle(300,10,1900,1000);

        txBegin();

            for (print k:qs)
            {

            txSetFillColor(k.cvet);
            txSetColor(k.cvetobv, k.obv);

            k.draws();
               }

                for (text k:qt)
            {

            //txSetFillColor(k.cvet);
            txSetColor(TX_RED);
            txSelectFont ("Comic Sans MS", 40);

            k.draw();
               }


        menu.drawMenu();

        slider.drawSizeSlider();
        slider.mainSlider();




         colormenuCvet cvetT=colormenu();

         if (cvetT.cvt1!=TX_TRANSPARENT){sq.cvet=cvetT.cvt1;}


         if (cvetT.cvt2!=TX_TRANSPARENT)sq.cvetobv=cvetT.cvt2;




         b1.drawButton();
         b1.click();
         b2.drawButton();
         b2.click();
         b3.drawButton();
         b3.click();
         b4.drawButton();
         b4.click();
         b5.drawButton();
         b5.click();
         b6.drawButton();
         b6.click();

         if (b1.click()) currentObject=2;// b1.�������
         if (b2.click()) currentObject=3;//sq.figure=currentObject;
         if (b3.click()) currentObject=4; //bbs=slider.result;
         if (b4.click()) { if(!qs.empty()) qs.pop_back(); if(!qs.empty()) qs.pop_back();}
         if (GetAsyncKeyState(VkKeyScan('z'))) { if(!qs.empty()) qs.pop_back(); if(!qs.empty()) qs.pop_back(); txSleep(100);}
         if (b5.click()) currentObject=5;
         if (b6.click()) textdrw=1;


        string s111;
        if (textdrw==1 && txMouseX()>=300&& txMouseY()>=10&& txMouseY()<1000 && txMouseX()<=1900 && txMouseButtons()==1)
         {t1.textdraw();
          qt.push_back(t1); textdrw=0;}


if (txMouseX()>=300&& txMouseY()>=10&& txMouseY()<1000 && txMouseX()<=1900 )
   sq.drawsquare();
         if (sq.draw && txMouseX()>=300 && txMouseX()<=1900 && txMouseY()>=10&& txMouseY()<1000 )

                {

            sq.figure=currentObject;
            sq.obv=slider.result;
            qs.push_back(sq);
            sq.draw=0;


                }
                sq.draw=0;




        txEnd();
            }

        return 0;

        }

