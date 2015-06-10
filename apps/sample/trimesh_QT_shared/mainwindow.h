/****************************************************************************
 * VCGLib                                                            o o     *
 * Visual and Computer Graphics Library                            o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2007                                                \/)\/    *
 * Visual Computing Lab                                            /\/|      *
 * ISTI - Italian National Research Council                           |      *
 *                                                                    \      *
 * All rights reserved.                                                      *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *   
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
 * for more details.                                                         *
 *                                                                           *
 ****************************************************************************/
/****************************************************************************
  History

$Log: not supported by cvs2svn $

****************************************************************************/
#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "ui_mainwindow.h"
#include "glarea.h"
#include "ml_thread_safe_memory_info.h"

class MainWindow:public QMainWindow
{
Q_OBJECT 
public:
  MainWindow(QWidget * parent = 0);
public slots:
  void chooseMesh();
  void loadTetrahedron();
  void loadDodecahedron();
  void initMesh(QString message);

signals:
  void loadMesh(QString newMesh);
private:
  Ui::mainWindow ui;
  GLArea* glar[2];

  GLArea* shared;
  MLThreadSafeMemoryInfo mi;
  /// the active mesh instance
  CMesh mesh;
  MLThreadSafeGLMeshAttributesFeeder feeder;
};

#endif /*MAINWINDOW_H_ */
