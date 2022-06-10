// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2022 Pedro López-Cabanillas <plcl@users.sourceforge.net>

#define WINVER 0x0601
#define _WIN32_WINNT 0x0601
#include <windows.h>

#include <QVBoxLayout>
#include <QSvgWidget>
#include <QCheckBox>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle("Confidential Window");
	resize(640, 480);
	auto centralwidget = new QWidget(this);
	auto verticalLayout = new QVBoxLayout(centralwidget);
	auto checkBox = new QCheckBox("Protect this window against screenshots", centralwidget);
	connect(checkBox, &QCheckBox::toggled, this, &MainWindow::protectionChecked);
	verticalLayout->addWidget(checkBox);
	auto svgwidget = new QSvgWidget(":/sticker.svg", centralwidget);
	verticalLayout->addWidget(svgwidget);
	setCentralWidget(centralwidget);
	show();
}

void MainWindow::protectionChecked(bool checked)
{
	DWORD dwAffinity = checked ? WDA_MONITOR : WDA_NONE;
	HWND handle = (HWND) effectiveWinId();
	SetWindowDisplayAffinity(handle, dwAffinity);
	show();
}
