#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "timer.h"

size_t arraySize = 10; // переменная отвечающая за размер массива

MainWindow::MainWindow(QWidget *parent) //конструктор окна
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() // деструктор окна
{
	delete ui;
}


void MainWindow::on_pushButton_clicked() // обработка нажатия кнопки старт
{
       std::mutex firstMt, secondMt;
	   QString first = "0";
	   QString second ="0";
	   int M1[arraySize]; // объявление массива М1
	   int M2[arraySize]; // объявление массива М2
       Timer CTimer, DTimer, HTimer, FTimer, ETimer ;
           Timer mainTimer; //таймер всего исполнения
	   mainTimer.start();
		   Timer ATimer;// таймер задачи А
		   ATimer.start();
           for(size_t i = 0; i< arraySize; i++)
		   {
			   M1[i] = rand() % 10;
		   }
		   std::cout<<std::endl;
		   for(size_t i =0; i<arraySize; i++)
		   {
			   M2[i] = rand() % 10;
		   }

		   // вывод данных о задачи А
        ui->WorkTimeA->setNum(ATimer.stop()); // время выполнения задачи А
		ui->progressBarA->setValue(100); // индикатор состояния задачи А
        ui->AM1->setText(toString(M1,arraySize)); // результат работы над массивом 1
        ui->AM2->setText(toString(M2,arraySize)); // результат работы над массивом 2
		ui->calledByA->setText("0");
		ui->calledA->setText("B,C");


        std::thread t1([&]() // создание потока с задачами C
			{
                CTimer.start();
                f2(M1, M2, arraySize);
                CTimer.stop();

			});

       Timer BTimer;
       BTimer.start();
       f1(M1, M2, arraySize);
       ui->WorkTimeB->setNum(BTimer.stop());
       ui->progressBarB->setValue(100);
       ui->BM1->setText(toString(M1,arraySize));
       ui->BM2->setText(toString(M2,arraySize));
       ui->calledB->setText("F");
       ui->calledByB->setText("A");





       std::thread t2([&]() // создание потока с задачами E
           {
               ETimer.start();
               f4(M1, M2, arraySize);
               ETimer.stop();
           });



       std::thread t3([&]() // создание потока с задачами D
           {
               DTimer.start();
               f3(M1, M2, arraySize);
               DTimer.stop();
           });


       FTimer.start();
       f5(M1, M2, arraySize);
       ui->WorkTimeF->setNum(FTimer.stop());
       ui->progressBarF->setValue(100);
       ui->FM1->setText(toString(M1,arraySize));
       ui->FM2->setText(toString(M2,arraySize));
       ui->calledF->setText("G,H");
       ui->calledByF->setText("B");


       ui->WorkTimeE->setNum(ETimer.timeOfStop);
       ui->progressBarE->setValue(100);
       ui->EM1->setText(toString(M1,arraySize));
       ui->EM2->setText(toString(M2,arraySize));
       ui->calledE->setText("G,H");
       ui->calledByE->setText("B");


       ui->WorkTimeD->setNum(DTimer.timeOfStop);
       ui->progressBarD->setValue(100);
       ui->DM1->setText(toString(M1,arraySize));
       ui->DM2->setText(toString(M2,arraySize));
       ui->calledD->setText("G,H");
       ui->calledByD->setText("B");


       firstMt.unlock();
          t1.join(); // ожидание потока с задачами C и E
          t2.join();





       std::thread t4([&]()
		   {
               HTimer.start();
               f7(M1, M2, arraySize);
               HTimer.stop();
			   secondMt.lock();

		   });

       std::thread t5([&]()
		   {
			   HTimer.start();
			   f7(M1, M2, arraySize);
			   HTimer.stop();
			   secondMt.lock();
		   });


		Timer GTimer;
		f6(M1, M2, arraySize);
        ui->WorkTimeG->setNum(GTimer.stop());
		ui->progressBarG->setValue(100);
		ui->GM1->setText(toString(M1,arraySize));
        ui->GM2->setText(toString(M2,arraySize));
		secondMt.lock();
		if(second=="0")

		t3.join();
		t2.join();

        ui->WorkTimeH->setNum(HTimer.timeOfStop);
		ui->progressBarH->setValue(100);
		ui->HM1->setText(toString(M1,arraySize));
		ui->HM2->setText(toString(M2,arraySize));
		if(second=="H")
		{
		  ui->calledH->setText("K");
		}
		else
		{
		  ui->calledH->setText("0");
		}
		ui->calledByH->setText(first);

		ui->WorkTimeF->setNum(FTimer.timeOfStop);
		ui->progressBarF->setValue(100);
		ui->FM1->setText(toString(M1,arraySize));
		ui->FM2->setText(toString(M2,arraySize));
		if(second =="F")
		{
		  ui->calledF->setText("K");
		}
		else
		{
		  ui->calledF->setText("0");
		}
		ui->calledByF->setText(first);

		Timer KTimer;
		f8(M1, M2, arraySize);
		ui->WorkTimeK->setNum(KTimer.stop());
		ui->progressBarK->setValue(100);
		ui->KM1->setText(toString(M1,arraySize));
		ui->KM2->setText(toString(M2,arraySize));
		ui->calledK->setText(second);


		ui->WorkTimeMain->setNum(mainTimer.stop()); // вывод времени исполнения всего процесса

}
