#ifndef __MAIN_H
#define __MAIN_H
#include <QElapsedTimer>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QTextEdit>
#include <QThread>
#include <QRadioButton>

//numbers generated will be between MAX and MIN
#define MIN   0
#define MAX 99
#define SLEEP_ms 500

/* create dealy in the qt */
/*!
 * \brief delay - create dealy in the qt
 */
void delay();
/* filling array with random numbers */
/*!
 * \brief updateArray - filling array with random numbers
 * \param data - array
 * \param length - lenth of array
 */
void updateArray(int data[], int length);
/* set the background of button to yellow to attract view */
/*!
 * \brief highlightButton - set the background of button to yellow to attract view
 * \param button - active int
 */
void highlightButton(QPushButton * button);
/* set the button to normal color */
/*!
 * \brief unhighlightButton - set the button to normal color
 * \param button - not active now
 */
void unhighlightButton(QPushButton * button);
/* swap value of a and b */
/*!
 * \brief swap - value of a and b
 * \param a - int
 * \param b - int
 */
void swap(int *a, int *b);
/* set button */
/*!
 * \brief setButtonValue - set button
 * \param button
 * \param data
 */
void setButtonValue( QPushButton *button, int data);
/* run selection sort algorith and update ui */
/*!
 * \brief bubbleSort - run selection sort algorith and update ui
 * \param button - array to sort for ui
 * \param data - array to sort
 * \param length - of array
 */
void bubbleSort(QPushButton *button[], int data[], int length);
/* run selection sort algorith and update ui */
/*!
 * \brief selectionSort - run selection sort algorith and update ui
 * \param button - array to sort for ui
 * \param data - array to sort
 * \param length - of array
 */
void selectionSort(QPushButton *button[], int data[], int length);
/* set button value corresponding to position data equivalent */
/*!
 * \brief updateButton
 * \param button - array to sort for ui
 * \param data - array to sort
 * \param length - of array
 */
void updateButton(QPushButton *button[],  int data[], int length);

#endif
