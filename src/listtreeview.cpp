// =====================================================================================
// 
//       Filename:  listtreeview.cpp
//
//    Description:  主窗口数据捕获控件的类实现文件
//
//        Version:  1.0
//        Created:  2013年01月22日 14时53分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "../include/listtreeview.h"

ListTreeView::ListTreeView()
{
	iPosition = 0;

	mainModel = new QStandardItemModel;

	mainModel->setColumnCount(6);
	mainModel->setHeaderData(0, Qt::Horizontal, tr("序号"));
	mainModel->setHeaderData(1, Qt::Horizontal, tr("时间"));
	mainModel->setHeaderData(2, Qt::Horizontal, tr("来源IP地址"));
	mainModel->setHeaderData(3, Qt::Horizontal, tr("目标IP地址"));
	mainModel->setHeaderData(4, Qt::Horizontal, tr("协议"));
	mainModel->setHeaderData(5, Qt::Horizontal, tr("发送长度"));

	this->setModel(mainModel);
}

ListTreeView::~ListTreeView()
{

}

void ListTreeView::rebuildInfo()
{
	mainModel->clear();
	iPosition = 0;

	mainModel->setColumnCount(6);
	mainModel->setHeaderData(0, Qt::Horizontal, tr("序号"));
	mainModel->setHeaderData(1, Qt::Horizontal, tr("时间"));
	mainModel->setHeaderData(2, Qt::Horizontal, tr("来源IP地址"));
	mainModel->setHeaderData(3, Qt::Horizontal, tr("目标IP地址"));
	mainModel->setHeaderData(4, Qt::Horizontal, tr("协议"));
	mainModel->setHeaderData(5, Qt::Horizontal, tr("发送长度"));
}

void ListTreeView::addOneCaptureItem(QString strNum, QString strTime, QString strSIP, 
										QString strDIP, QString strProto, QString strLength)
{
	QStandardItem *item;

	item = new QStandardItem(QString(strNum));
	mainModel->setItem(iPosition, 0, item);
	item = new QStandardItem(QString(strTime));
	mainModel->setItem(iPosition, 1, item);
	item = new QStandardItem(QString(strSIP));
	mainModel->setItem(iPosition, 2, item);
	item = new QStandardItem(QString(strDIP));
	mainModel->setItem(iPosition, 3, item);
	item = new QStandardItem(QString(strProto));
	mainModel->setItem(iPosition, 4, item);
	item = new QStandardItem(QString(strLength));
	mainModel->setItem(iPosition, 5, item);

	iPosition++;
}

void ListTreeView::getOrderNumber(QModelIndex &index, QString &strNumber)
{
	strNumber = mainModel->data(index, 0).toString();
}

bool ListTreeView::isChanged()
{
	// Qt::MatchWildcard 使用基于字符串的通配符  Qt::MatchRecursive 搜索整个目录结构
	QList<QStandardItem *> tmp = mainModel->findItems("*", Qt::MatchWildcard | Qt::MatchRecursive);

	if (tmp.size() != 0) {
		return true;
	}

	return false;
}
