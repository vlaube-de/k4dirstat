/*
 *   File name:	kdirtreemaparea.cpp
 *   Summary:	Support classes for KDirStat
 *   License:	LGPL - See file COPYING.LIB for details.
 *   Author:	Alexander Rawass <alexannika@users.sourceforge.net>
 *
 *   Updated:	2001-06-11
 *
 *   $Id: kdirtreemaparea.cpp,v 1.1 2001/11/19 13:13:11 hundhammer Exp $
 *
 */

#include <string.h>
#include <sys/errno.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <qtimer.h>
#include <kdebug.h>
#include <kapp.h>
#include <klocale.h>
#include "kdirtree.h"
#include "kdirtreeview.h"
#include "kdirsaver.h"
#include "kdirtreemap.h"
#include <qmainwindow.h>
//#include <bits/mathcalls.h>

using namespace KDirStat;

KDirTreeMapArea::KDirTreeMapArea(QWidget *parent) : QTreeMapArea(parent) {
}

QString KDirTreeMapArea::shortName(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return kdi_node->name();
}

QString KDirTreeMapArea::fullName(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return kdi_node->debugUrl();
}

int KDirTreeMapArea::thisDirItems(Object *node){
  //  KDirInfo *kdi_node=(KDirInfo *)node;
  int count=0;
  
  if(isNode(node)){
    Object *child=firstChild(node);
    bool dotentry_flag=FALSE;

    while(child!=NULL){
      count++;
      child=nextChild(child);
	      if(child==NULL && dotentry_flag==FALSE){
		dotentry_flag=TRUE;
		Object *dotentry=sameLevelChild(node);
		if(dotentry){
		  child=firstChild(dotentry);
		}
	      }
     }
  }
  else{
  }

  return count;
}

Object *KDirTreeMapArea::firstChild(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return (Object *)(kdi_node->firstChild());
}



asize KDirTreeMapArea::totalSize(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return (asize)(kdi_node->totalSize());
}
int KDirTreeMapArea::totalItems(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return kdi_node->totalItems();
}

bool KDirTreeMapArea::isLeaf(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return kdi_node->isFile();
}

bool KDirTreeMapArea::isNode(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return kdi_node->isDir();
}

bool KDirTreeMapArea::isSameLevelChild(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return kdi_node->isDotEntry();
}

Object *KDirTreeMapArea::nextChild(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return (Object *)kdi_node->next();
}

Object *KDirTreeMapArea::sameLevelChild(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return (Object *)kdi_node->dotEntry();
}

Object *KDirTreeMapArea::parentNode(Object *node){
  KDirInfo *kdi_node=(KDirInfo *)node;

  return (Object *)kdi_node->parent();
}

QString KDirTreeMapArea::tellUnit(asize size){
  QString str;
  if(size<1024){
    str.sprintf("%d bytes",(int)size);
  }
  else if(size<(1024*1024)){
    str.sprintf("%.2f kB",((float)size)/(1024.0));
  }
  else if(size<(1024*1024*1024)){
    str.sprintf("%.2f MB",((float)size)/(1024*1024));
  }
  else {
    str.sprintf("%.2f GB",((float)size)/(1024*1024*1024));
  }

  return str;
}

void KDirTreeMapArea::dirChange(Object *node){
  NOT_USED(node);
#if 0
  //  printf("CALLBACK KDirTreeMapArea\n");
  emit changedDirectory(node);
#endif
}
void KDirTreeMapArea::directoryUp(){
  //  printf("CALLBACK KDirTreeMapArea\n");
  ((QTreeMapArea *)this)->directoryUp();

}

void KDirTreeMapArea::saveAsBitmap(){
  //printf("CALLBACK KDirTreeMapArea\n");
  ((QTreeMapArea *)this)->saveAsBitmap();

}

void KDirTreeMapArea::saveAsXML(){
  //printf("CALLBACK KDirTreeMapArea\n");
  ((QTreeMapArea *)this)->saveAsXML();

}

void KDirTreeMapArea::zoomIn(){
  //printf("CALLBACK KDirTreeMapArea\n");
  ((QTreeMapArea *)this)->zoomIn();

}

void KDirTreeMapArea::zoomOut(){
  //printf("CALLBACK KDirTreeMapArea\n");
  ((QTreeMapArea *)this)->zoomOut();

}
/*
void KDirTreeMapArea::highlighted(Object *high){
  printf("CALLBACK KDirTreeMapArea\n");
  ((QTreeMapArea *)this)->highlighted(high);

}

*/