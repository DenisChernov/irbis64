/*
 * File:   consts.h
 * Author: F10-kafedra
 *
 * Created on 7 Февраль 2011 г., 11:47
 */

#ifndef CONSTS_H
#define	CONSTS_H
#include <QtCore/QString>
#include <QtCore/QFile>
#include <string>

    const QString progress[] = {"Чтение базы", "Обработка запроса", "Запрос выполнен"};
    const QString hostname = "192.168.9.250";
  //const QString hostname = "localhost";
        //const QString hostname = "192.168.9.120";
    const QString users = "bases/readersRDR.txt";
    const QString fields[] = {"200: ",  // поле заглавия
                              "^A",     // заголовок
                              "910: ",  // поле места хранения (филиала)
                              "^B",     // инвентарный номер книги
                              "^D",     // место хранения
                              "700: ",  // поле автора
                              "^A",     // фамилия
                              "^B",     // инициалы
                              "906: ",  // раздел
                              "461: ",  // поле заглавия многотомника
                              "^C",     // заглавие
                              "^E",     // доп. инфо
                              "^V",     // номер тома в многотомнике
                              "961:",   // поле автора в многотомнике
                              "210:",   // поле издательства
                              "^D"      // год издания
                              //"906:"    // код
                             };

    const QString patterns[] = {
                                "\\^B(.*)\\^C.*\\^",    // ID  \^U
                                "\\^D(.*)\\^",          // филиал
                                "#906: (.*)",          // раздел знаний
                                "\\^A(.*)\\^",
                                "(\\s.*)",              // еще один вариант ID
                                "\\^(.*)",              // еще один вариант филиала
                                "\\^B(.*)\\^u.*\\^",    // еще один вариант ID
                                "\\^D(\\d{4})",         // год издания
                                "\\^D\\d{4}(.*)"        // все кроме года издания
                               };
    const std::string bases[] = {"OLDEK", "RETRO"};

    /*
     * Цвета для соответствия инвентарных номеров и филиалов
     */
    const std::string colors[] = {"de3163", "1faee9", "3b5998", "9c7c1e", "871e9c", "1e9c91", "1e9c55", "00ff00", "d7ff00", "7e8944"};
    
    /*
     *  Цвета вывода в консоль
     */
    const std::string txt_black = "\x1b[30m";
    const std::string txt_b_black = "\x1b[1;30m";
    const std::string txt_red = "\x1b[31m";
    const std::string txt_b_red = "\x1b[1;31m";
    const std::string txt_green = "\x1b[32m";
    const std::string txt_b_green = "\x1b[1;32m";
    const std::string txt_yellow = "\x1b[33m";
    const std::string txt_b_yellow = "\x1b[1;33m";
    const std::string txt_blue = "\x1b[34m";
    const std::string txt_b_blue = "\x1b[1;34m";
    const std::string txt_purple = "\x1b[35m";
    const std::string txt_b_purple = "\x1b[1;35m";
    const std::string txt_lblue = "\x1b[36m";
    const std::string txt_b_lblue = "\x1b[1;36m";
    const std::string txt_white = "\x1b[37m";
    const std::string txt_b_white = "\x1b[1;37m";
    const std::string txt_end = "\x1b[0m";

    
#endif	/* CONSTS_H */

