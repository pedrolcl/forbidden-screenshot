// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 Pedro López-Cabanillas <plcl@users.sourceforge.net>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = nullptr);
	
public slots:
	void protectionChecked(bool checked);
	
};
#endif // MAINWINDOW_H
