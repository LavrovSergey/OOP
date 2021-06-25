#include "main.h"

void delay() {
    QTime dieTime= QTime::currentTime().addMSecs(SLEEP_ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void updateArray(int data[], int length) {
    for(int i=0; i<length; i++) {
        int value = MIN + (std::rand() % (MAX - MIN +1));
        data[i] = value;
    }
}

void highlightButton(QPushButton * button) {
    button->setStyleSheet("\
        background-color: yellow; \
        color: blue; \
        font-weight: bold; \
    ");
}

void unhighlightButton(QPushButton * button) {
    button->setStyleSheet("\
        font-weight: bold; \
    ");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void setButtonValue( QPushButton *button, int data) {
    std::string name = std::to_string(data);
    button->setText(name.c_str());
}

void bubbleSort(QPushButton *button[], int data[], int length, QLabel *time) {

    QElapsedTimer timer;
    timer.start();
    for (int iter =0; iter< length -1; iter++) {
        int swapped = 0;
        for(int i=0; i< length-1; i++) {
            highlightButton(button[i]);
            highlightButton(button[i+1]);
            delay();
            if (data[i] > data[i+1]) {
                swap(&data[i], &data[i+1]) ;
                setButtonValue(button[i], data[i]);
                setButtonValue(button[i+1], data[i+1]);
                delay();
                swapped = 1;
            }
            unhighlightButton(button[i]);
            unhighlightButton(button[i+1]);
        }
        // if no swapping had occoured then list is sorted
        if (swapped == 0) {
            break;
        }
    }
    QString t=QString::number(timer.elapsed()/1000);
    time->setText(t+" seconds");
}

void selectionSort(QPushButton *button[], int data[], int length, QLabel *time) {
    QElapsedTimer timer;
    for (int step = 0; step < length - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < length; i++) {
            highlightButton(button[i]);
            highlightButton(button[step]);
            delay();

            if (data[i] < data[min_idx])  {
                min_idx = i;

            }
            unhighlightButton(button[step]);
            unhighlightButton(button[i]);
        }
        highlightButton(button[min_idx]);
        highlightButton(button[step]);
        // put min at the correct position
        swap(&data[min_idx], &data[step]);
        setButtonValue(button[min_idx], data[min_idx]);
        setButtonValue(button[step], data[step]);
        delay();
        unhighlightButton(button[min_idx]);
        unhighlightButton(button[step]);
    }
    QString t=QString::number(timer.elapsed()/1000);
    time->setText(t+" seconds");
}

void updateButton(QPushButton *button[],  int data[], int length) {
    std::string name;
    for(int i=0; i<length; i++) {
        name  = std::to_string(data[i]);
        button[i]->setText(name.c_str());
    }
}

int main(int argc, char **argv) {
    // size of array
    const int length = 10;
    int data[length];
    // when sorting process is on value is True
    int sorting = false;

    QApplication app(argc, argv);
    // creating window
    QWidget *window = new QWidget;
    window->resize(200, 100);
    window->setWindowTitle("sorting algorithm");
    // create layout inside window
    QGridLayout *layout = new QGridLayout(window);
    QPushButton *button[length];
    updateArray(data, length);
    for(int i=0; i<length; i++) {
        std::string name  = std::to_string(data[i]);
        button[i] = new QPushButton(name.c_str());
        button[i]->setStyleSheet("\
        font-weight: bold; \
        ");
        layout->addWidget(button[i], 0, i, 1 ,1);
    }

    QRadioButton *radioBubble = new QRadioButton(QObject::tr("bubble sort"));
    QRadioButton *radioSelection = new QRadioButton(QObject::tr("selection sort"));
    QLabel *time= new QLabel();
    radioBubble->setChecked(true);
    layout->addWidget(radioBubble, 3, 0, 1 , 1);
    layout->addWidget(radioSelection, 3, 1, 1 , 1);
     layout->addWidget(time, 3, 7, 1 , 1);
    //reset button
    QPushButton *resetBtn = new QPushButton("RESET");
    resetBtn->setStyleSheet("\
        color: red; \
        font-weight: bold; \
    ");
    layout->addWidget(resetBtn, 3, 8, 1 , 1);

    // sort button
    QPushButton *sortBtn = new QPushButton("SORT");
    sortBtn->setStyleSheet("\
        color: green; \
        font-weight: bold; \
    ");
    layout->addWidget(sortBtn, 3, 9, 1 , 1);

    // when reset button is pressed
    QObject::connect(resetBtn, &QPushButton::clicked, [&](){
        // when reset button is pressed generate another random set of array
        // and update it in GUI
        updateArray(data, length);
        updateButton(button, data, length);
        sortBtn->setText("SORT");
    });

    // when sort button is pressed
    QObject::connect(sortBtn, &QPushButton::clicked, [&](){
        if (sorting ==true) {
            //if sorting already in place don't do anything
            return;
        }
        sorting =true;
        resetBtn->setVisible(false);
        sortBtn->setText("sorting...");
        // if binary sort radio button is clicked do binary sort
        // else do selection sort
        radioBubble->isChecked() ?
            bubbleSort(button, data, length, time):
            selectionSort(button, data, length, time);
        resetBtn->setVisible(true);
        sortBtn->setText("SORT");
        sorting = false;
    });

    window->show();
    return app.exec();
}
