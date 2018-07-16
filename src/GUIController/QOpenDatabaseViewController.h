/*
 * QOpenDatabaseViewController.h
 *
 *  Created on: 10 juin 2016
 *      Author: echopin
 */

#ifndef SRC_GUICONTROLLER_QOPENDATABASEVIEWCONTROLLER_H_
#define SRC_GUICONTROLLER_QOPENDATABASEVIEWCONTROLLER_H_

#include <QObject>
#include <QString>

#include "Model/DatabaseModel.h"
#include "Database/DatabaseController.h"

class QDatabaseConnectionViewController;
class QOpenDatabaseView;
class QWindowMain;

class QOpenDatabaseViewController : public QObject
{
	Q_OBJECT
/*public:
	enum TabIndex {
		FavouriteIndex = 0,
		ExplorerFileIndex,
		SQLiteIndex,
		MySQLIndex,
		PostgreSQLIndex,
	};*/

public:
	QOpenDatabaseViewController();
	virtual ~QOpenDatabaseViewController();

	void init(QWindowMain* pMainWindow, QOpenDatabaseView* pOpenDatabaseView);
	QString getFileUrl() const;
	void initFavouriteList();
	DatabaseModel selectedDatabase(int iType, QString szTabFileName);
	void loadDatabase(const DatabaseModel&  databaseModel);

private:
	//QStringList makeMySQLDatabaseInfoList();
	//QStringList makePostgreSQLDatabaseInfoList();
	void MySQLDatabaseInfo(DatabaseModel * database);
	void PostgreSQLInfo(DatabaseModel * database);

public slots:
	void buttonClicked(DatabaseModel::DatabaseType type);
	void openFileDialog();
	void openSQLiteFile(const QString& szFileUrl);
	void closeOpenDatabaseDialog();
	void openViews();
	void openFav();
	void openExplorer();
	void openMenuConn();
	void openSQLite();
	void openMySQL();
	void openPostgreSQL();

private:
	QOpenDatabaseView* m_pOpenDatabaseView;
	QString m_szFileUrl;
	QWindowMain* m_pMainWindow;
	bool m_bGoOn;
};

#endif /* SRC_GUICONTROLLER_QOPENDATABASEVIEWCONTROLLER_H_ */
