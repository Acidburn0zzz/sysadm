// ===============================
//  PC-BSD REST API Server
// Available under the 3-clause BSD License
// Written by: Ken Moore <ken@pcbsd.org> 2015-2016
// =================================
#ifndef _PCBSD_SYSADM_EVENT_WATCHER_SYSTEM_H
#define _PCBSD_SYSADM_EVENT_WATCHER_SYSTEM_H

#include "globals-qt.h"

//#define DISPATCHWORKING QString("/var/tmp/appcafe/dispatch-queue.working")
#define LPLOG QString("/var/log/lpreserver/lpreserver.log")
#define LPERRLOG QString("/var/log/lpreserver/error.log")
#define LPREPLOGDIR QString("/var/log/lpreserver/")

class EventWatcher : public QObject{
	Q_OBJECT
public:
	//Add more event types here as needed
	enum EVENT_TYPE{ BADEVENT, DISPATCHER, LIFEPRESERVER, SYSSTATE};
	
	EventWatcher();
	~EventWatcher();
	
	//Convert between strings and type flags
	static EVENT_TYPE typeFromString(QString);
	static QString typeToString(EventWatcher::EVENT_TYPE);

	//Retrieve the most recent event message for a particular type of event
	QJsonValue lastEvent(EVENT_TYPE type);
	
private:
	QFileSystemWatcher *watcher;
	QHash<unsigned int, QJsonValue> HASH;
	QTimer *filechecktimer;
	QTimer *syschecktimer;
	bool starting;
	//HASH Note: Fields 1-99 reserved for EVENT_TYPE enum (last message of that type)
	//	Fields 100-199 reserved for Life Preserver logs (all types)
	
	//Life Preserver Event variables/functions
	QString tmpLPRepFile;

	void sendLPEvent(QString system, int priority, QString msg);

	//General purpose functions
	QString readFile(QString path);
	double displayToDoubleK(QString);

	// For health monitoring
	QString oldhostname;

public slots:
	void start();

	//Slots for the global Dispatcher to connect to
	void DispatchStarting(QString);
	void DispatchEvent(QJsonObject);

private slots:
	//File watcher signals
	void WatcherUpdate(const QString&);
	void CheckLogFiles(); //catch/load any new log files into the watcher
	void CheckSystemState(); // Periodic check to monitor health of system

	//LP File changed signals/slots
	void ReadLPLogFile();
	void ReadLPErrFile();
	void ReadLPRepFile();
signals:
	void NewEvent(EventWatcher::EVENT_TYPE, QJsonValue); //type/message
};
#endif
