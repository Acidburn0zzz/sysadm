//===========================================
//  PC-BSD source code
//  Copyright (c) 2015, PC-BSD Software/iXsystems
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef __PCBSD_LIB_UTILS_SYSMGMT_H
#define __PCBSD_LIB_UTILS_SYSMGMT_H

#include <QJsonObject>
#include "sysadm-global.h"


namespace sysadm{

class SysMgmt{
public:
	static QJsonObject batteryInfo();
	static QJsonObject cpuPercentage();
	static QJsonObject cpuTemps();
	static QJsonObject externalDevicePaths();
	static QJsonObject killProc(QJsonObject);
	static QJsonObject memoryStats();
	static QJsonObject procInfo();

	//sysctl management
	static QJsonObject getSysctl(QJsonObject);
	static QJsonObject setSysctl(QJsonObject);
	static QJsonObject sysctlList();
	
	static QJsonObject systemInfo();
	static QJsonObject systemReboot();
	static QJsonObject systemHalt();

	static QJsonObject systemDevices();
	static QJsonObject fetchPortsTree(QString altDir = ""); //QStringList &cmds, QStringList &dirs);
	//static QJsonObject fetchSourceTree(QString branch, QStringList &cmds, QStringList &dirs); // This is not ready yet
};

} //end of namespace

#endif
