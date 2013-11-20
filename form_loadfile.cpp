/*
 * File:   form_loadfile.cpp
 * Author: f10-kafedra
 *
 * Created on 18 Январь 2012 г., 17:41
 */

#include "form_loadfile.h"

form_loadfile::form_loadfile() {
    formLoadInfos.setupUi(this);
}

form_loadfile::~form_loadfile() {
}
void form_loadfile::setCount(int count)
{
    formLoadInfos.lblAmountInfos->setText(QString::number(count));
}