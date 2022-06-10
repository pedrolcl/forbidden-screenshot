// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 Pedro López-Cabanillas <plcl@users.sourceforge.net>

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
